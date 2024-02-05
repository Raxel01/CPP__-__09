#include <iostream>
#include <map>

#include <iostream>
#include <string>
#include <sstream>

#include <iostream>
#include <string>
#include <sstream>

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> // for setiosflags

// int main() {
//     std::string str = "11392.1369999999999999";
//     double value;

//     // Create stringstream with fixed-point formatting
//     std::stringstream ss(str);
//     ss  >> value;  // Corrected: use std::setiosflags

//         std::cout << "Double value: " << std::fixed << std::setprecision(2) << value << std::endl;
//     if (ss.fail()) {
//         std::cerr << "Error: Invalid string format." << std::endl;
//     } else {
//     }

//     return 0;
// }


// int main() {
//     std::string str = "13554.14";
//     double value;

//     // Create stringstream with fixed-point formatting
//     std::stringstream ss(str);
//     ss >> std::fixed >> value;

//     if (ss.fail()) {
//         std::cerr << "Error: Invalid string format." << std::endl;
//     } else {
//         std::cout << "Double value: " << value << std::endl;
//     }

//     return 0;
// }


// int main() {
//     std::string str = "14437.423";
//     double value;

//     // Use stringstream for conversion:
//     std::stringstream ss(str);
//     ss >> value;

//     if (ss.fail()) {
//         std::cerr << "Error: Invalid string format." << std::endl;
//     } else {
//         std::cout << "Double value: " << value << std::endl;
//     }

//     return 0;
// }


// #include <iostream>
// #include <string>
// #include <stdlib.h> // for strtol

// int main() {
//     std::string str = "895.693";
//     char* endptr;

//     // Set custom radix to represent decimal with 5 decimal places
//     int radix = 100000;

//     // Convert string to long using strtol and custom radix
//     long long_value = strtol(str.c_str(), &endptr, radix);

//     // Check for conversion errors
//     if (endptr == str.c_str() || *endptr != '\0') {
//         std::cerr << "Error: Invalid string format." << std::endl;
//     } else {
//         // Convert long to double with appropriate division
//         double value = static_cast<double>(long_value) / radix;
//         std::cout << "Double value: " << value << std::endl;
//     }

//     return 0;
// }


int main ()
{
    
    std::map<std::string, int, std::greater<std::string>> myMap;

    myMap.insert(std::pair<std::string, int> ("Abdelali 7", 1));
    myMap.insert(std::pair<std::string, int> ("Abdelali 7", 1));
    myMap.insert(std::pair<std::string, int> ("Abdelali 5", 2));
    myMap.insert(std::pair<std::string, int> ("Abdelali 0", 3));
    myMap.insert(std::pair<std::string, int> ("Abdelali 2", 4));
    myMap.insert(std::pair<std::string, int> ("Abdelali 1", 5));

    std::map<std::string, int>::iterator it = myMap.begin();

    while (it != myMap.end()){
        std::cout << "Key : " << it->first << "| Value : " << it->second << std::endl;
        it++;
    }
    return 0;
}