package com.csh.servlet;



import com.alibaba.fastjson.JSONObject;
import com.csh.entity.User;
import com.csh.servise.Loginservise;


import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


import java.io.IOException;


import java.io.PrintWriter;
import java.util.List;

@WebServlet("/login")
public class Loginservlet extends HttpServlet {
    private final Loginservise loginservise=new Loginservise();
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws  IOException {
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        List<User> list = loginservise.check(username);
        // 创建用于返回的JSON响应对象
        JSONObject responseJson = new JSONObject();

        if (list.isEmpty()) {
            responseJson.put("status", "error");
            responseJson.put("message", "用户名或密码错误");
        } else {
            if (list.get(0).getPassword().equals(password)) {
                responseJson.put("status", "success");
                responseJson.put("message", "登录成功");
            } else {
                responseJson.put("status", "error");
                responseJson.put("message", "用户名或密码错误");
            }
        }

        // 设置响应类型为JSON
        resp.setContentType("application/json;charset=UTF-8");

        // 输出JSON响应内容
        PrintWriter out = resp.getWriter();
        out.write(responseJson.toString());
        out.flush();
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
      this.doGet(req,resp);
    }
}
