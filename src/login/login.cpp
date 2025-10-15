#include <iostream>
#include <string>
#include <vector>
// Using MySQL++
#include <mysql++/mystring.h>
#include <mysql++/mysql++.h>

using Records = std::vector<std::string>;


class loginAndRegistion
{
    std::string username;
    std::string password;
    // MySQL++ connection and objects
    mysqlpp::Connection db;
    mysqlpp::Query query;
    mysqlpp::StoreQueryResult res;
    std::string sql;
    bool loged_in;

    public:
    // Explicit constructor to initialize db and query
    loginAndRegistion() : db(false), query(&db), loged_in(false) {}

    int open()
    {
        // Note: user must ensure a MySQL server is running and credentials are correct.
        // Adjust host, user, password, and db name as needed.
        try {
            db.connect("testdb", "localhost", "root", "");
        } catch (const mysqlpp::BadQuery &er) {
            std::cerr << "Query error: " << er.what() << std::endl;
            return 0;
        } catch (const mysqlpp::BadConversion &er) {
            std::cerr << "Conversion error: " << er.what() << std::endl;
            return 0;
        } catch (const mysqlpp::Exception &er) {
            std::cerr << "DB connection error: " << er.what() << std::endl;
            return 0;
        }
        return 0;
    }

    
    int close()
    {
        if (db.connected()) db.disconnect();
        return 0;
    }


    // MySQL++ does not use callbacks; we'll run queries directly.


    int createTable()
    {
        try {
            query = db.query("CREATE TABLE IF NOT EXISTS COMPANY("
                             "USERNAME VARCHAR(255) NOT NULL,"
                             "PASSWORD VARCHAR(255) NOT NULL);");
            query.execute();
        } catch (const mysqlpp::Exception &er) {
            std::cerr << "Create table error: " << er.what() << std::endl;
        }
        return 0;
    }


    int reg()
    {
        std::cout << "Please give a username: "; std::cin >> username;
        std::cout << "Please give a password: "; std::cin >> password;
        try {
            query = db.query();
            query << "INSERT INTO COMPANY (USERNAME, PASSWORD) VALUES(" <<
                     mysqlpp::quote << username << ", " << mysqlpp::quote << password << ")";
            query.execute();
        } catch (const mysqlpp::Exception &er) {
            std::cerr << "Insert error: " << er.what() << std::endl;
        }
        return 0;
    }


    int login()
    {
        try {
            query = db.query("SELECT USERNAME, PASSWORD FROM COMPANY");
            res = query.store();

            std::cout << "Please give a username: "; std::cin >> username;
            std::cout << "Please give a password: "; std::cin >> password;

            loged_in = false;
            for (size_t i = 0; i < res.num_rows(); ++i) {
                std::string u = res[i][0].c_str();
                std::string p = res[i][1].c_str();
                if (u == username && p == password) {
                    loged_in = true;
                    break;
                }
            }
        } catch (const mysqlpp::Exception &er) {
            std::cerr << "Select error: " << er.what() << std::endl;
        }
        return 0;
    } 


    int control()
    {
        int option;
        std::cout << "Do you wish to login or registor(1/2): "; std::cin >> option;
        switch(option){
            case 1: 
                login();
                break;
            case 2: 
                reg();
                break;
        }
        return 0;
    }
};

int main(int argc, char* argv[])
{
    loginAndRegistion data;
    data.open();   // Open the database first
    data.control();    //
    data.close();  // Close the database
    return 0;
}