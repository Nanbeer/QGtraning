package com.atguigu.api.statemeny;


/*

 */


import java.lang.reflect.Field;
import java.sql.*;
import java.util.*;

public abstract class JdbcUntils_高级应用封装 {//非DQL语句

    /**
     * 封装非DQL语句
     * @param sql 带占位符的SQL语句
     * @param params 占位符的值
     * @return  执行影响的行数
     */
    public int executeUpdate(String sql, Object... params) throws Exception {
        Connection connection = JdbcUntilsv2.getConnection(); // 获取连接
        PreparedStatement preparedStatement = connection.prepareStatement(sql);
        for (int i = 0; i < params.length; i++) { // 注意循环条件从0开始
            preparedStatement.setObject(i+1 , params[i]); // 设置参数值
        }
        int i = preparedStatement.executeUpdate(); // 执行更新操作
        preparedStatement.close(); // 关闭Statement
        if(connection.getAutoCommit()){
            JdbcUntilsv2.freeConnection(); // 自动提交时释放连接
        }
        return i; // 返回执行影响的行数
    }


    /**
     *
     * 非DQL语句封装方法-》返回值固定为int
     *
     * DQL语句封装-》返回值？  List<T>
     *
     *     并不是List<Map>Map key和value自定义！ 无需先设定
     *                  map没有数据校检机制
     *                  map不支持反射操作
     *
     *     表中一行-》java类的一个对象  -》多行-》List<Java实体类>list;
     *     DQL->List<Map>->一行->map->List<Map>
     *
     *     <T>声明一个泛型，不确定类型
     *          1.确定泛型 User.class T=User
     *          2.要使用反射技术属性赋值
     *     public <T> List<T> executeQuery(Class<T> clazz,String sql,Object... params);
     *
     *
     */

    /**
     * 将查询结果封装到一个实体类集合
     * @param clazz 要接的值的实体类集合的模板对象
     * @param sql 查询语句，要求列名或别名等于实体类的属性名
     * @param params 占为符的值，要和？位置对象传递
     * @return 查询的实体类集合
     * @param <T> 声明的结果的类型
     * @throws Exception
     */

    public <T> List<T> executeQuery(Class<T> clazz, String sql, Object... params) throws Exception {

        //获取连接
        Connection connection = JdbcUntilsv2.getConnection();
        PreparedStatement preparedStatement = connection.prepareStatement(sql);

        //占位符赋值
        if(params==null&&params.length!=0){
            for (int i = 1; i <= params.length; i++) {
                preparedStatement.setObject(i,params[i-1]);
            }
        }

        //发送sql语句
        ResultSet resultSet = preparedStatement.executeQuery();
        //结果解析
        /*
        解析全部结果：使用集合存放
         */
        List<T> list=new ArrayList<>();

        //获取当前信息集对象
        ResultSetMetaData metaData = resultSet.getMetaData();
        //获取列数
        int columnCount = metaData.getColumnCount();

        while (resultSet.next()){
            T t=clazz.getDeclaredConstructor().newInstance();//调用类的无参构造函数实例化对象
            for (int i = 1; i <=columnCount ; i++) {
                Object value = resultSet.getObject(i);//获取该列对象并接收
                String propertyName=metaData.getColumnLabel(i);//获取列名
                //反射，给对象属性赋值
                Field field=clazz.getDeclaredField(propertyName);
                field.setAccessible(true);//属性可设置
                /**
                 *参数1：要赋值的对象
                 * 参数2：具体的属性值
                 */
                field.set(t,value);
            }
            //将map放到list中
            list.add(t);
        }

        //关闭资源
        resultSet.close();
        preparedStatement.close();

        if(connection.getAutoCommit()){
            JdbcUntilsv2.freeConnection();
        }

        return list;
    }
}
