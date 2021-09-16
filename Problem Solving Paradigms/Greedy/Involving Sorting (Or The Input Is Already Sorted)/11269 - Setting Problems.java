import java.util.*;
import java.io.*;

public class Main {
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private final DataInputStream din;
        private final byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(
                    new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[64];
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    } else {
                        continue;
                    }
                }
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0,
                    BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            din.close();
        }
    }

    static class Pair {
        int a;
        int b;

        Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    public static void main(String[] args) throws IOException {
        Reader input = new Reader();
        String line;
        while ((line = input.readLine()) != null && !line.isEmpty()) {
            int n = Integer.parseInt(line);
            List<Pair> arr = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int a = input.nextInt();
                arr.add(new Pair(a, 0));
            }
            for (int i = 0; i < n; i++) {
                arr.get(i).b = input.nextInt();
            }
            arr.sort((o1, o2) -> {
                if (o1.a < o1.b && o2.a < o2.b) {
                    return o1.a - o2.a;
                } else if (o1.a >= o1.b && o2.a >= o2.b) {
                    return o2.b - o1.b;
                } else if (o1.a < o1.b) {
                    return -1;
                } else {
                    return 1;
                }
            });
            int Sultan = arr.get(0).a, Baba = Sultan + arr.get(0).b;
            for (int i = 1; i < n; i++) {
                Sultan += arr.get(i).a;
                if (Sultan < Baba) {
                    Baba += arr.get(i).b;
                } else {
                    Baba = Sultan + arr.get(i).b;
                }
            }
            System.out.println(Baba);
        }
    }
}