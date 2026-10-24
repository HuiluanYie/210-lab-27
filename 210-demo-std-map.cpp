// COMSC-210 | Lab 27 | Huiluan Yie

#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

// function prototype
int display_menu();
void output(const map<string, tuple<int, string, string>>&);
void inc_f(map<string, tuple<int, string, string>>&);
void dec_f(map<string, tuple<int, string, string>>&);
void search(const map<string, tuple<int, string, string>>&, string);


int main() {
    // declarations
    // The key is the villager's name.
    // The tuple stores friendship level, species, and catchphrase.
    map<string, tuple<int, string, string>> villagers;

    // insert elements into the map
    // note how the right-hand side of the assignment are the tuples
    villagers["Audie"] = make_tuple(8, "Wolf", "foxtrot");
    villagers["Raymond"] = make_tuple(10, "Cat", "crisp");
    villagers.insert({"Marshal", make_tuple(7, "Squirrel", "sulky")});
    
    string v;
    int in;
    output(villagers);
    do
    {
        in = display_menu();
        switch (in)
        {
            case 1:
                inc_f(villagers);
                break;
            case 2:
                dec_f(villagers);
                break;
            case 3:
                cout << "Please enter the name of the villager you want to search for: ";
                cin >> v;
                search(villagers, v);
                break;
            case 4:
                break;
            default:
                cout << "Wrong input! Please choose a number from the menu.\n";
                break;
        }
        output(villagers);
    } while (in != 4);

    return 0;
}

// function definition
int display_menu()
{
    // display_menu() displays the menu
    // arguments: none
    // returns: the user's choice
    int choice;
    cout << "1. Increase Friendship\n"
         << "2. Decrease Friendship\n"
         << "3. Search for Villager\n"
         << "4. Exit\n"
         << "Enter choice: ";
    cin >> choice;
    return choice;
}

void output(const map<string, tuple<int, string, string>>& villagers)
{
    // output() displays the contents of villager data
    // arguments: the map of villagers
    // returns: none
    cout << "\n\nVillager details:" << endl;
    for (const auto& v : villagers) {
        cout << v.first << " [" 
             << get<0>(v.second)
             << ", " << get<1>(v.second) 
             << ", " << get<2>(v.second) << "]\n";
    }
}

void inc_f(map<string, tuple<int, string, string>>& villagers)
{
    // inc_f() increase friendship of a villager
    // arguments: the map of villagers
    // returns: none
    string v;
    cout << "Please enter the name of the villager you want to increase friendship: ";
    cin >> v;
    auto the_v = villagers.find(v);
    if (the_v == villagers.end())
    {
        cout << "villager not found\n";
    }
    else if (get<0>(the_v->second) >= 10)
    {
        cout << "villager friendship max";
    }
    else
    {
        get<0>(the_v->second)++;
    }
}

void dec_f(map<string, tuple<int, string, string>>& villagers)
{
    // dec_f() decrease friendship of a villager
    // arguments: the map of villagers
    // returns: none
    string v;
    cout << "Please enter the name of the villager you want to decrease friendship: ";
    cin >> v;
    auto the_v = villagers.find(v);
    if (the_v == villagers.end())
    {
        cout << "villager not found\n";
    }
    else if (get<0>(the_v->second) <= 0)
    {
        cout << "villager friendship min";
    }
    else
    {
        get<0>(the_v->second)--;
    }
}

void search(const map<string, tuple<int, string, string>>& villagers, string search_key)
{
    auto it = villagers.find(search_key);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << search_key << "'s details: ";
        cout << get<0>(it->second) << ", ";
        cout << get<1>(it->second) << ", ";
        cout << get<2>(it->second);
        cout << endl;
    } else
        cout << endl << search_key << " not found." << endl;
}