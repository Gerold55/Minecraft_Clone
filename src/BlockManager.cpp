#include "BlockManager.h"
#include <sol/sol.hpp>
#include <iostream>

BlockManager::BlockManager(const std::string& luaScriptPath) {
    lua.open_libraries(sol::lib::base);

    // Load and execute the Lua script
    if (!lua.script_file(luaScriptPath)) {
        std::cerr << "Failed to load Lua script: " << luaScriptPath << std::endl;
        return;
    }

    // Access the blocks table from Lua
    auto blocks = lua["blocks"];
    for (auto& [key, value] : blocks.as<sol::table>()) {
        std::string name = value["name"];
        std::string texture = value["texture"];
        bool mineable = value["mineable"];

        blockData[key] = {name, texture, mineable};
    }
}

const BlockManager::BlockInfo& BlockManager::getBlockInfo(const std::string& id) const {
    auto it = blockData.find(id);
    if (it != blockData.end()) {
        return it->second;
    } else {
        throw std::runtime_error("Block ID not found");
    }
}
