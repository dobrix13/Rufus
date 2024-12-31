#ifndef SCENARIO_HPP
#define SCENARIO_HPP

#include <string>
#include <vector>

class Scenario {
public:
    std::string description;
    int id;
    std::vector<std::string> choices;
    std::vector<int> nextScenarios;
    bool isEndScenario;
    int taskDuration;
    std::string name;
    int travelDuration;

    Scenario()
        : description(""), id(0), choices({}), nextScenarios({}), isEndScenario(false), taskDuration(0), name(""), travelDuration(0) {}

    Scenario(std::string desc, int id, std::vector<std::string> opts, std::vector<int> next, bool end, int duration, std::string path, int travel)
        : description(desc), id(id), choices(opts), nextScenarios(next), isEndScenario(end), taskDuration(duration), name(path), travelDuration(travel) {}
};

#endif // SCENARIO_HPP