import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * 没有连接tomcat  而是通过ServerSocket监听localhost作为服务端 当有客户端连接时，会启动一个新线程处理客户端请求。
 *
 * 这里我只写了一种请求方法 get
 */


public class SimpleServer {
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(8080);//定义监听
            System.out.println("服务器启动， 开始监听8080...");

            while (true) {//当监听到客户端发送的请求时，进入新的线程
                Socket clientSocket = serverSocket.accept();
                Thread clientThread = new Thread(new ClientHandler(clientSocket));
                clientThread.start();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class ClientHandler implements Runnable {
        private Socket clientSocket;

        public ClientHandler(Socket socket) {
            this.clientSocket = socket;
        }

        @Override
        public void run() {
            try {//使用缓冲流接收字符流
                BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                OutputStream out = clientSocket.getOutputStream();

                String request = in.readLine();
                System.out.println("Received request: " + request);

                // 模拟处理不同请求的情况  定义sendResponse来返回状态码
                if (request.contains("/success")) {
                    sendResponse(out, "200 OK", "Success response");
                } else if (request.contains("/redirect")) {
                    sendResponse(out, "302 Found", "Redirecting to another page");
                } else if (request.contains("/notfound")) {
                    sendResponse(out, "404 Not Found", "The requested resource was not found");
                } else {
                    sendResponse(out, "400 Bad Request", "Bad request received");
                }

                in.close();
                out.close();
                clientSocket.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        private void sendResponse(OutputStream out, String status, String body) throws IOException {//
            PrintWriter printer = new PrintWriter(out);
            printer.println("HTTP/1.1 " + status);
            printer.println("Content-Type: text/plain");
            printer.println("Access-Control-Allow-Origin: *"); // 允许所有来源的跨域请求
            printer.println();
            printer.println(body);
            printer.flush();
        }

    }
    }
