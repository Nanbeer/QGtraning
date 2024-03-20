package com.atguigu.api.statemeny;

import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.Properties;

public class JdbcUntilsv2 {

    private static DataSource dataSource=null;//连接池对象

    private static ThreadLocal<Connection> tl=new ThreadLocal<>();//线程
    /*
    TODO:利用线程本地变量存储连接信息，确保一个线程的多个办法可以获取同一个connection
     */

    static {
        /*
        初始化连接池对象
         */

        Properties properties=new Properties();
        InputStream ips = JdbcUntils.class.getClassLoader().getResourceAsStream("druid.properties");
        try {
            properties.load(ips);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }


        try {
           dataSource = DruidDataSourceFactory.createDataSource(properties);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }


    }

    public static Connection getConnection() throws SQLException {

        //线程本地是否存在
        Connection connection = tl.get();
        //若没有
        if(connection==null){
            connection = dataSource.getConnection();
            tl.set(connection);
        }
        return connection;
    }

    public static void freeConnection() throws SQLException {
        Connection connection = tl.get();
        if(connection!=null){
            tl.remove();
            connection.setAutoCommit(true);
            connection.close();
        }
    }
}
