#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct project
{
    string name;
    string description;
    bool completed;
};

class Projects
{
    vector<project> allProjects;
    
public:
    Projects()
    {
        import("/Users/hazemwalidf/Desktop/Helmet/projects.txt");
        
        cout << endl << "Projects Status \n";
        if (allProjects.size() == 0)
        {
            cout << "No projects are available. \n\n";
            cout << "Enter -1 to Return \n";
            int r;
            do{
                cin >> r;
                
                if (r == -1)
                {
                    return;
                }
                
            }while (r != -1);
        }
        else
        {
            cout << "1. In-Progress \n";
            cout << "2. Completed \n";
            int option;
            cin >> option;
            
            display(option);
        }
        
        
    }
    
    void display(int option)
    {
        if (option == 1)
        {
            for (int i=0; i<allProjects.size(); i++)
            {
                if (allProjects[i].completed == false)
                {
                    cout << endl << "Project " << allProjects[i].name << endl << endl;
                    cout << "Description \n" << allProjects[i].description << endl << endl;
                }
            }
        }
        else if (option == 2)
        {
            for (int i=0; i<allProjects.size(); i++)
            {
                if (allProjects[i].completed == true)
                {
                    cout << endl << "Project " << allProjects[i].name << endl << endl;
                    cout << "Description \n" << allProjects[i].description << endl << endl;
                }
            }
        }
        
        cout << "Enter -1 to Return \n";
        int r;
        do{
            cin >> r;
            
            if (r == -1)
            {
                return;
            }
            
        }while (r != -1);
    }
    
    void import(string path)
    {
        ifstream file(path);
        
        string line;
        getline(file, line);
        project temp_proj;
        
        vector<string> v;
        
        stringstream ss(line);
    
        while (ss.good())
        {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }
        
        int nameflag = 0;
        int descriptionflag = 1;
        int completeflag = 2;
        
        for (int i=0; i<v.size(); i++)
        {
            if (i == nameflag)
            {
                temp_proj.name = v[i];
                nameflag += 3;
            }
            
            if (i == descriptionflag)
            {
                temp_proj.description = v[i];
                descriptionflag += 3;
            }
            
            if (i == completeflag)
            {
                if (v[i] == "1")
                {
                    temp_proj.completed = true;
                }
                else if (v[i] == "0")
                {
                    temp_proj.completed = false;
                }
                
                allProjects.push_back(temp_proj);
                completeflag += 3;
            }
        }
        
        file.close();
    }
    
    
};
