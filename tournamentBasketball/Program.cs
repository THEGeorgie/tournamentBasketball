using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Data.Entity.Infrastructure;
using System.Data.SQLite;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace SQLiteDemo {
    struct Team
    {
        public string name;
        public int manager;
        public int wins;
        public int losts;
        public float overAll;
    }
    class Program
    {

        static void Main(string[] args)
        {
            char input = ' ';
            Console.WriteLine("---------------------------------");
            Console.WriteLine("--MINI  BASCKETBALL  TOURNAMENT--");
            Console.WriteLine("---------------------------------");
            SQLiteConnection sqlConn;
            sqlConn = CreateConnection();

            Console.Write("Select team, make team, edit Team (a,b: ");
            try
            {
                input = Convert.ToChar(Console.ReadLine());
            }
            catch (Exception e)
            {
                Console.WriteLine("Please input only a,b or c");
            }

                switch (input) {
                    case 'a':
                            Console.Clear();
                            Database.ReadInput(sqlConn, "show all TEAM");
                            SQLiteConnection sqlite;
                            sqlite = CreateConnection();
                            string inputLocal = Console.ReadLine();
                            if (inputLocal == "exit") {
                                break;
                            }
                            else
                            {
                                Database.ReadInput(sqlite,inputLocal);
                            }
                        break;
                    case 'b':
                        break;
                    default:
                        break;
                }
            static SQLiteConnection CreateConnection()
            {

                SQLiteConnection sqlite_conn;
                // Create a new database connection:
                sqlite_conn = new SQLiteConnection("Data Source= database.db; Version = 3; New = True; Compress = True; ");
                // Open the connection:
                try
                {
                    sqlite_conn.Open();
                }
                catch (Exception ex)
                {

                }
                return sqlite_conn;
            }

        }
        
        

        
    }
    class Database {
        public static void ReadInput(SQLiteConnection conn, string expre) {
            string[] words = expre.Split();
            if (words.Length > 1) {
                string prep = "\"" + words[1] + "\"";
                switch (words[0])
                {
                    case "select":
                        SaveData(conn, "TEAM", string.Concat("name = ", prep));
                        break;
                    case "show":
                        if (words[1] == "all") {
                            ReadData(conn, "TEAM");
                        }
                        else {
                            ReadData(conn, "TEAM", string.Concat("name = ", prep));
                        }
                       
                        break;
                    default:
                        Console.WriteLine("Unknown Command");
                        break;

                }
            }
            else
            {
                Console.WriteLine("Not enough arguments!!");
            }


        }
        static void InsertData(SQLiteConnection conn)
        {
            SQLiteCommand sqlite_cmd;
            sqlite_cmd = conn.CreateCommand();
            sqlite_cmd.CommandText = "INSERT INTO SampleTable (Col1, Col2) VALUES('Test Text ', 1); ";
            sqlite_cmd.ExecuteNonQuery();
            sqlite_cmd.CommandText = "INSERT INTO SampleTable (Col1, Col2) VALUES('Test1 Text1 ', 2); ";
            sqlite_cmd.ExecuteNonQuery();
            sqlite_cmd.CommandText = "INSERT INTO SampleTable (Col1, Col2) VALUES('Test2 Text2 ', 3); ";
            sqlite_cmd.ExecuteNonQuery();


            sqlite_cmd.CommandText = "INSERT INTO SampleTable1 (Col1, Col2) VALUES('Test3 Text3 ', 3); ";
            sqlite_cmd.ExecuteNonQuery();

        }

        static void ReadData(SQLiteConnection conn, string coll)
        {
            SQLiteDataReader sqlite_datareader;
            SQLiteCommand sqlite_cmd;
            sqlite_cmd = conn.CreateCommand();

            sqlite_cmd.CommandText = string.Concat("SELECT name FROM ", coll) + ";";
            sqlite_datareader = sqlite_cmd.ExecuteReader();
            while (sqlite_datareader.Read())
            {
                Console.WriteLine(sqlite_datareader.GetString(0));
            }

            conn.Close();
        }
        static void ReadData(SQLiteConnection conn, string coll, string expression)
        {
            SQLiteDataReader sqlite_datareader;
            SQLiteDataReader sqlite_datareader1;
            SQLiteCommand sqlite_cmd;
            SQLiteCommand sqlite_cmd1;
            sqlite_cmd = conn.CreateCommand();
            sqlite_cmd.CommandText = string.Concat("SELECT * FROM ", coll) + " WHERE " + expression + ";";
            sqlite_datareader = sqlite_cmd.ExecuteReader();
            while (sqlite_datareader.Read())
            {
                string name = sqlite_datareader.GetString(1);
                int manager = sqlite_datareader.GetInt32(2);
                int wins = sqlite_datareader.GetInt32(3);
                int losts = sqlite_datareader.GetInt32(4);
                float overAll = sqlite_datareader.GetFloat(5);
                sqlite_cmd1 = conn.CreateCommand();
                sqlite_cmd1.CommandText = $"SELECT name FROM MANAGER WHERE m_id = {manager}";
                sqlite_datareader1 = sqlite_cmd1.ExecuteReader();
                while (sqlite_datareader1.Read())
                {
                    Console.WriteLine($"NAME: {name}, MANAGER: {sqlite_datareader1.GetString(0)}, WINS: {wins}, LOSTS: {losts}, OVERALL: {overAll}");
                }

            }

            conn.Close();
        }
        static void SaveData(SQLiteConnection conn, string coll, string expression)
        {
            SQLiteDataReader sqlite_datareader;
            SQLiteCommand sqlite_cmd;
            sqlite_cmd = conn.CreateCommand();
            sqlite_cmd.CommandText = string.Concat("SELECT * FROM ", coll) + " WHERE " + expression + ";";
            sqlite_datareader = sqlite_cmd.ExecuteReader();
            Team team1 = new Team();
            while (sqlite_datareader.Read())
            {
                team1.name = sqlite_datareader.GetString(1);
                team1.manager = sqlite_datareader.GetInt32(2);
                team1.wins = sqlite_datareader.GetInt32(3);
                team1.losts = sqlite_datareader.GetInt32(4);
                team1.overAll = sqlite_datareader.GetFloat(5);
            }

            Console.WriteLine("Succsefuly saved team!!");

            conn.Close();
        }
    }
    class Game {
        
        struct tournamentMap{
            int leftWing[];
        }
    }
}
