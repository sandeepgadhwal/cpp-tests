
#include <iostream>
// #include <vector>
#include <cmath>
#include <unordered_map>


using namespace std;

string tolowercase(string input){
    for (int i=0; i<input.size(); i++){
        input[i] = tolower(input[i]);
    }
    return input;
}

string toCamelCase(string input){
    if (input.size() > 0){
        input[0] = toupper(input[0]);
    }
    return input;
}

string get_city_name(){
    string cityname;
    getline(cin, cityname);
    return cityname;
}

unordered_map<string, int> build_city_database (){
    unordered_map<string, int> store;
    string cityname;
    int counter = 0;
    while (true) {
        cout << "Enter a new city name and to register or press enter to skip: ";
        cityname = get_city_name();
        if (cityname == ""){
            break;
        } else if ( store.find(tolowercase(cityname)) != store.end() ){
            cout << "City: " << toCamelCase(cityname) << " already registered in system with ID: " << store[cityname] << " !\n";
            continue;
        }
        counter+=1;
        store[tolowercase(cityname)] = counter;
        cout << "Saved entered city: " << toCamelCase(cityname) << " with ID: " << counter << "\n";
    }
    return store;
}

void list_all_cities(unordered_map<string, int> database){
    int ncities = database.size();
    if (ncities==0) {
        cout << "Found 0 cities in database"; 
        return;
    }
    cout << "Priting details of " << ncities  << " cities\n";
    cout << "City Name | City ID\n";
    for (auto& [cityname, citycode]: database){
        cout << toCamelCase(cityname) << " | " << citycode << "\n";
    }
}

void seach_cities(unordered_map<string, int> database){
    string cityname;
    while (true){
        cout << "Search by city name or enter all to list all or enter exit to terminate program: ";
        cityname = tolowercase(get_city_name());
        if (cityname=="exit") {
            return;
        }
        else if (cityname=="all") {
            list_all_cities(database);
        }
        else if (database.find(cityname) == database.end()) {
            cout << "City: " << cityname << " not found\n";
        } else {
            int citycode = database[cityname];
            cout << "Found city " << toCamelCase(cityname) << " by ID: " << citycode << "\n";
        }
    }
}

int main() 
{
    cout << "Hello from Sandeep";
    cout << endl;

    unordered_map<string, int> database = build_city_database();
    seach_cities(database);


    cout << "\n";
    return 0;
}