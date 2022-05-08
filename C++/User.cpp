#pragma once
#include <iostream>
using namespace std;

class User
{
private:
    string role;
    
public:
    
    void setRole(string role)
    {
        this->role = role;
    }
    
    string getRole()
    {
        return role;
    }
    
    virtual void options()
    {
        
    }
    
};

