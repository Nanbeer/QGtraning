package com.atguigu.api.statemeny;

import org.junit.Test;

import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class PSCURDPart_new extends JdbcUntils_高级应用封装{

    private String account;
    private long money;


    @Override
    public String toString() {
        return " " +
                "account='" + account + '\'' +
                ", money=" + money +
                ' ';
    }

    //插入
    @Test
    public void testInsert() throws Exception {
        String sql="insert into bank (account,money) values(?,?);";
        int i = executeUpdate(sql, "test3", "6645");
        System.out.println("i="+i);
    }

    //更新
    @Test
    public void testUpdate() throws Exception {
        String sql="update bank set money=? where id=?";
        int i=executeUpdate(sql,"15600","6");
        System.out.println("i="+i);
    }

    //删除
    @Test
    public void testDelete() throws Exception {

        String sql="delete from bank where id=?";
        int i=executeUpdate(sql,"5");
        System.out.println("i="+i);
    }

    //查询
    @Test
    public void testSelect() throws Exception{
        String sql="select account,money from bank;";
        List<PSCURDPart_new>list=executeQuery(PSCURDPart_new.class,sql);
        System.out.println("list="+list);
    }
}
