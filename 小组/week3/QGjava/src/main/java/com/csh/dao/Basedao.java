package com.csh.dao;

import com.csh.utils.JdbcUtils;

import java.lang.reflect.Field;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.util.ArrayList;
import java.util.List;

public class Basedao {
    public int executeUpdate(String sql,Object... params) throws Exception {
        //直接调封装好的方法获取连接
        Connection connection = JdbcUtils.getConnection();
        PreparedStatement preparedStatement=connection.prepareStatement(sql);
        //占位符号赋值
        if(params!=null&&params.length!=0) {
            for (int i = 1; i <= params.length; i++) {
                preparedStatement.setObject(i, params[i - 1]);
            }
        }
        int n=preparedStatement.executeUpdate();
        preparedStatement.close();
        //是否回收连接,要考虑是不是事务
        if(connection.getAutoCommit()){
            //不是事务,正常回收
            JdbcUtils.freeConnection();
        }
        return n;
    }



    public <T> List<T> executeQuery(Class<T> tClass, String sql, Object... params) throws Exception {
        //直接调封装好的方法获取连接
        Connection connection = JdbcUtils.getConnection();
        PreparedStatement preparedStatement = connection.prepareStatement(sql);
        //占位符号赋值
        if (params != null && params.length != 0) {
            for (int i = 1; i <= params.length; i++) {
                preparedStatement.setObject(i, params[i - 1]);
            }
        }
        ResultSet resultSet = preparedStatement.executeQuery();
        List<T> list = new ArrayList<>();

        //获取列的信息
        ResultSetMetaData metaData = resultSet.getMetaData();
        int columnCount = metaData.getColumnCount();
        while (resultSet.next()) {
            //调用类的无参构造函数实例化对象
            T t = tClass.newInstance();
            for (int i = 1; i <= columnCount; i++) {
                //对象的属性值
                Object value = resultSet.getObject(i);
                String propertyName = metaData.getColumnName(i);
                //反射,给对象的属性值赋值
                Field field = tClass.getDeclaredField(propertyName);
                //设置属性,打破私有限制
                field.setAccessible(true);
                field.set(t, value);
            }
            list.add(t);
        }
        //关闭
        resultSet.close();
        preparedStatement.close();
        if(connection.getAutoCommit()){
            //不是事务,正常回收
            JdbcUtils.freeConnection();
        }
        return list;
    }
}
