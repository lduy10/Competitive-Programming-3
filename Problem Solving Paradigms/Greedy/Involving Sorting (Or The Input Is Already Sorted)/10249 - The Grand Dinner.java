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
            byte[] buf = new byte[64]; // line length
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

    static class Team {
        int number;
        int members;

        Team(int number, int members) {
            this.number = number;
            this.members = members;
        }
    }

    static class Table {
        int number;
        int capacity;

        Table(int number, int capacity) {
            this.number = number;
            this.capacity = capacity;
        }
    }

    static class TeamCompare implements Comparator<Team> {
        @Override
        public int compare(Team o1, Team o2) {
            if (o2.members != o1.members) {
                return o2.members - o1.members;
            }
            return o1.number - o2.number;
        }
    }

    static class TableCompare implements Comparator<Table> {
        @Override
        public int compare(Table o1, Table o2) {
            if (o1.capacity != o2.capacity) {
                return o2.capacity - o1.capacity;
            }
            return o1.number - o2.number;
        }
    }

    public static void main(String[] args) throws IOException {
        Reader input = new Reader();
        while (true) {
            int m = input.nextInt(), n = input.nextInt();
            if (m == 0 && n == 0) {
                break;
            }
            PriorityQueue<Team> teams = new PriorityQueue<>(new TeamCompare());
            int totalMembers = 0;
            boolean ok = true;
            for (int i = 1; i <= m; i++) {
                int members = input.nextInt();
                if (members > n) ok = false;
                totalMembers += members;
                teams.add(new Team(i, members));
            }
            List<Table> tables = new ArrayList<>();
            int totalCapacities = 0;
            for (int i = 1; i <= n; i++) {
                int capacity = Math.min(input.nextInt(), m);
                totalCapacities += capacity;
                tables.add(new Table(i, capacity));
            }
            if (totalCapacities < totalMembers) {
                ok = false;
            }
            if (!ok) {
                System.out.println(0);
                continue;
            }
            List<List<Integer>> ans = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                ans.add(new ArrayList<>());
            }
            tables.sort(new TableCompare());
            for (int i = 0; i < n; i++) {
                int num = tables.get(i).number, c = tables.get(i).capacity;
                List<Team> tmp = new ArrayList<>();
                for (int j = 0; j < c; j++) {
                    Team head = teams.peek();
                    if (head.members == 0) continue;
                    int idx = head.number - 1;
                    head.members--;
                    ans.get(idx).add(num);
                    totalMembers--;
                    teams.remove();
                    tmp.add(head);
                }
                teams.addAll(tmp);
            }
            if (totalMembers == 0) {
                System.out.println(1);
                for (List<Integer> i : ans) {
                    for (int j = 0; j < i.size(); j++) {
                        System.out.print(i.get(j));
                        if (j < i.size() - 1) {
                            System.out.print(" ");
                        } else {
                            System.out.println();
                        }
                    }
                }
            } else {
                System.out.println(0);
            }
        }
    }
}