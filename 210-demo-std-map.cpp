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
auto search(map<string, tuple<int, string, string>>&);


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
    
    int in;
    do
    {
        in = display_menu();
        switch (in)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            break;
        default:
            cout << "Wrong input! Please choose a number from the menu.\n";
            break;
        }
    } while (in != 4);
    

    // access the map using a range-based for loop
    cout << "Villagers and details(range-based for loop):" << endl;
    for (const auto& t : villagers) {
        cout << t.first << ": \n";
        cout << "Friendship level: " << get<0>(t.second) << '\n';
        cout << "Species: " << get<1>(t.second) << '\n';
        cout << "Catchphrase: " << get<2>(t.second) << '\n';
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and details(iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagers.begin(); 
                                               it != villagers.end(); ++it) {
        cout << it->first << ": ";
        cout << get<0>(it->second) << ", ";
        cout << get<1>(it->second) << ", ";
        cout << get<2>(it->second);
        cout << endl;
    }

    // delete an element
    villagers.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s details: ";
        cout << get<0>(it->second) << ", ";
        cout << get<1>(it->second) << ", ";
        cout << get<2>(it->second);
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    return 0;
}

// function definition
