#include <iostream>
#include <map>
#include <vector>

int new_bus(std::map<std::string, std::vector<std::string>>& data);
bool stop_is_found(const std::vector<std::string> stops, const std::string stop);
int buses_for_stop(std::map<std::string, std::vector<std::string>> data, const std::string stop);
int stops_for_bus(std::map<std::string, std::vector<std::string>> data, const std::string bus);
int all_buses(std::map<std::string, std::vector<std::string>> data);

int main() {
    std::cout << "Enter amount of calls n: ";
    int n = 0;
    std::cin >> n;

    std::map<std::string, std::vector<std::string>> data = {};

    for (int i = 0; i < n; ++ i) {
        std::cout << "Enter command: ";
        std::string command = " ";
        std::cin >> command;

        if ((command == "NEW_BUS") || (command == "new_bus")) {
            new_bus(data);

        } else if ((command == "BUSES_FOR_STOP") || (command == "buses_for_stop")) {
            std::string stop = " ";
            std::cout << "Enter stop: ";
            std::cin >> stop;

            if (buses_for_stop(data, stop) == -1)
                std::cout << "No stop" << std::endl;

        } else if ((command == "STOPS_FOR_BUS") || (command == "stops_for_bus")) {
            std::string bus = " ";
            std::cout << "Enter bus: ";
            std::cin >> bus;

            stops_for_bus(data, bus);

        } else if ((command == "ALL_BUSES") || (command == "all_buses")) {
            all_buses(data);

        } else if ((command == "exit") || (command == "EXIT")) {
            return 0;

        } else {
            std::cout << "Wrong command try again" << std::endl;
            --n;
        }
    }

    return 0;
}

int new_bus(std::map<std::string, std::vector<std::string>>& data) { 
    std::cout << "Enter name of the bus: ";
    std::string bus = " ";
    std::cin >> bus;

    std::cout << "Enter amount of the stops: ";
    int n = 0;
    std::cin >> n;

    std::vector<std::string> stops(n);

    for (int stopIndex = 0; stopIndex < n; ++ stopIndex) {
        std::cout << "Enter name of stop " << stopIndex + 1 << ": ";
        std::string stop = " ";
        std::cin >> stop;

        stops[stopIndex] = stop;
    }

    data[bus] = stops;
    return 0;
}

int buses_for_stop(std::map<std::string, std::vector<std::string>> data, const std::string stop) {
    std::map<std::string, std::vector<std::string>>::iterator it = data.begin();
    bool stopExist = false;

    for (it; it != data.end(); ++it) {
        if (stop_is_found(it->second, stop)) {
            std::cout << it -> first << std::endl;
            stopExist = true;
        }
    }

    if (!stopExist) 
        return -1;

    return 0;
}

bool stop_is_found(const std::vector<std::string> stops, const std::string stop) {
    const int size = stops.size();
    for (int stopIndex = 0; stopIndex < size; ++stopIndex) {
        if (stop == stops[stopIndex])
            return true;
    }

    return false;
}

int stops_for_bus(std::map<std::string, std::vector<std::string>> data, const std::string bus) {
    if (data.find(bus) == data.end()) {
        std::cout << "No bus" << std::endl;
        return -1;
    }

    const int size = data[bus].size();

    std::map<std::string, std::vector<std::string>> copyData = data;
    copyData.erase(bus);
    for (int stopIndex = 0; stopIndex < size; ++stopIndex) {
        std::cout << data[bus][stopIndex] << ":" << std::endl;

        int result = buses_for_stop(copyData, data[bus][stopIndex]);
        if (result == -1) 
            std::cout << "No interchange" << std::endl;
        
        std::cout << std::endl;
    }

    return 0;
}

int all_buses(std::map<std::string, std::vector<std::string>> data) {
    if (data.begin() == data.end()) {
        std::cout << "No buses" << std::endl;
        return -1;
    }
    
    std::map<std::string, std::vector<std::string>>::iterator it = data.begin();
    for (it; it != data.end(); ++it) {
        std::cout << "Bus " << it -> first << ":" << std::endl;
        const int size = it -> second.size();
        for (int stopIndex = 0; stopIndex < size; ++stopIndex)
            std::cout << it -> second[stopIndex] << std::endl;

        std::cout << std::endl;
    }

    return 0;
}