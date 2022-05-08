#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "User.cpp"

using namespace std;

struct info
{
    string role;
    string username;
    string password;
    string helmetID;
};

class Authorize
{
private:
    vector<info> file_info;
    
public:
    Authorize(string path)
    {
        import(path);
    }
    
    // import info from file to vector
    void import(string path)
    {
        ifstream file(path);
        
        string line = "";
        string word = "";
        info temp_info;
        
        while (getline(file, line)) // copy line by line from file
        {
            replace(line.begin(), line.end(), ',', ' ');    // replace commas with spaces
            stringstream iss(line);
            
            // assign word by word to info vector
            iss >> word;
            temp_info.username = word;
            
            iss >> word;
            temp_info.password = word;
            
            iss >> word;
            temp_info.helmetID = word;
            
            iss >> word;
            temp_info.role = word;
            
        
            file_info.push_back(temp_info);     // add new entry to vector
        }
        
        file.close();
    }
    
    // return index if username and password match
    int find(string user, string pass)
    {
        for (int index = 0; index < file_info.size(); index++)
        {
            if ( (file_info[index].username == user) && (file_info[index].password == pass) )
                return index;
        }
        
        return -1;
    }
    
    // return bool whether they match or not
    bool check(string user, string pass)
    {
        if (find(user, pass) != -1)
        {
            return true;
        }
        else return false;
    }
    
    string getUsername(int index)
    {
        return file_info[index].username;
    }
    
    string getPassword(int index)
    {
        return file_info[index].password;
    }
    
    string getHelmetID(int index)
    {
        return file_info[index].helmetID;
    }
    
    string getRole(int index)
    {
        return file_info[index].role;
    }
    
    void print()
    {
        for(int i=0; i<file_info.size(); i++)
        {
            cout << file_info[i].username << endl;
            cout << file_info[i].password << endl;
            cout << file_info[i].helmetID << endl;
            cout << file_info[i].role << endl;
        }
    }
    
    // login process
    bool login(User &user)
    {
        string username, password;
        cout << "Please enter username.\n";
        cin >> username;
        
        cout << "Please enter password.\n";
        cin >> password;
        
        int attempts = 1;
        while ( (check(username, password) == false) && (attempts < 3) )
        {
            cout << "Username and password do not match. Please try again. \n";
            cout << "Remaining attemps = " << 3-attempts << endl << endl;
            cout << "Please enter username.\n";
            cin >> username;
            cout << "Please enter password.\n";
            cin >> password;
            attempts++;
            
            // if 3 wrong inputs
            if ( (check(username, password) == false) && (attempts == 3) )
            {
                cout << endl << "Number of login attempts exceeded. \n";
                return false;
            }
            
        }
        
        // if correct login
        if (check(username, password) == true)
        {
            int index = find(username, password);
            cout << endl << "Hello, " << getUsername(index) << endl;
            cout << "Helmet ID = " << getHelmetID(index) << endl;
            
            if (getRole(index) == "admin")
            {
                user.setRole("admin");
            }
            else if (getRole(index) == "worker")
            {
                user.setRole("worker");
            }
            
            return true;
        }
        
        return false;
    }
    
};
