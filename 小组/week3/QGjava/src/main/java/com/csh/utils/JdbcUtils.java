package com.csh.utils;

import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.Properties;

public class JdbcUtils {
    private static DataSource dataSource=null;
    //本地变量
    private static final ThreadLocal<Connection> tl=new ThreadLocal<>();
    //封装
    static {
        Properties properties=new Properties();
        InputStream ips = com.alibaba.druid.util.JdbcUtils.class.getClassLoader()
                .getResourceAsStream("druid.properties");
        try {
            properties.load(ips);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        try {
            dataSource= DruidDataSourceFactory.createDataSource(properties);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
    //对外提供连接方法
    public static Connection getConnection() throws SQLException {
        //查看线程本地变量是否存在
        Connection connection= tl.get();
        if(connection==null){
            //不存在,就获取
            connection= dataSource.getConnection();
            tl.set(connection);
        }
        return connection;
    }
    public static void freeConnection() throws Exception {
        Connection connection= tl.get();
        if(connection!=null){
            //清空线程本地变量
            tl.remove();
            //事务状态回归
            connection.setAutoCommit(true);
            //回收
            connection.close();
        }

    }
}
