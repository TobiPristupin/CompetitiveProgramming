/*
ID: tobiasp1
TASK: namenum
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream dict ("dict.txt");
    ifstream fin ("namenum.in");
    ofstream fout ("namenum.out");
    string keymap = "ABCDEFGHIJKLMNOPRSTUVWXY", code, name;
    bool found = false;
    fin >> code;
    
    while (dict >> name){
        string out = "";
        for (int c = 0; c < name.length(); c++){
            if (keymap.find(name.substr(c, 1)) == string::npos){
                continue;
            }
            out += to_string((keymap.find(name.substr(c, 1)) / 3) + 2);
        }

        if (out == code){
            fout << name << "\n";
            found = true;
        }
    }

    if (!found){
        fout << "NONE" << endl;
    }
        
    return 0;
}