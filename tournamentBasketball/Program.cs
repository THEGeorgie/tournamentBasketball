using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Data.Entity.Infrastructure;
using System.Data.SQLite;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SQLiteDemo
{
    class Program
    {

        static void Main(string[] args)
        {
            char input = ' ';
            Console.WriteLine("---------------------------------");
            Console.WriteLine("--MINI  BASCKETBALL  TOURNAMENT--");
            Console.WriteLine("---------------------------------");

            Console.Write("Select team, make team, edit Team (a,b: ");
            try
            {
                input = Convert.ToChar(Console.ReadLine());
            }
            catch (Exception e)
            {
                Console.WriteLine("You fucked up somethin");
            }

            SQLiteConnection sqlite_conn;
            sqlite_conn = CreateConnection();

            switch (input)
            {
                case 'a':
                    Console.Clear();
                    ReadData(sqlite_conn, "TEAM", "");

                    String expre = Console.ReadLine();
                    string[] words = expre.Split();
                    if (words[0] == "select")
                    {
                        ReadData(sqlite_conn, "TEAM", string.Concat("name = ", words[1]));
                    }
                    break;
                case 'b':
                    break;
                default:
                    break;
            }

      


            Console.ReadKey();
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

        static void ReadData(SQLiteConnection conn, string coll, string expression)
        {
            SQLiteDataReader sqlite_datareader;
            SQLiteCommand sqlite_cmd;
            sqlite_cmd = conn.CreateCommand();
            if (expression == "") {
                sqlite_cmd.CommandText = string.Concat("SELECT name FROM ", coll) + ";";
            }
            else
            {
                sqlite_cmd.CommandText = string.Concat("SELECT * FROM", coll) + "WHERE " + expression + ";";
            }

            sqlite_datareader = sqlite_cmd.ExecuteReader();
            while (sqlite_datareader.Read())
            {
                Console.WriteLine(sqlite_datareader.GetString(0));
            }
            conn.Close();
        }
    }
}