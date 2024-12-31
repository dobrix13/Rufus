#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <unordered_set>
#include <string>

class Inventory {
public:
    std::unordered_set<std::string> items;

    void addItem(const std::string &item) {
        items.insert(item);
    }

    bool hasItem(const std::string &item) const {
        return items.find(item) != items.end();
    }
};

#endif // INVENTORY_HPP