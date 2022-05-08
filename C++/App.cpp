#include <iostream>
#include <unistd.h>
#include <term.h>
#include "Authorize.cpp"
#include "Worker.cpp"
#include "Admin.cpp"
using namespace std;

class App
{
public:
    
    App()
    {
        startup();
        Authorize a("/Users/hazemwalidf/Desktop/Helmet/data.txt");
        User user;
        if (a.login(user) == true)
        {
            while (true)
            {
                cout << endl;
                
                if (user.getRole() == "worker")
                {
                    Worker worker;
                    worker.options();
                }
                
                if (user.getRole() == "admin")
                {
                    Admin admin;
                    admin.options();
                }
                
                
            }
        }
    }
    
    void startup()
    {
        char enter;
        cout << "Welcome, to the Smart Helmet App \n";
        cout << "Press Any Key to Login \n";
        cin >> enter;
    }
    
    
    
    
};
