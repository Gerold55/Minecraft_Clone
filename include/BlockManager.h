#ifndef BLOCKMANAGER_H
#define BLOCKMANAGER_H

#include <sol/sol.hpp>
#include <string>
#include <unordered_map>

class BlockManager {
public:
    BlockManager(const std::string& luaScriptPath);

    struct BlockInfo {
        std::string name;
        std::string texture;
        bool mineable;
    };

    const BlockInfo& getBlockInfo(const std::string& id) const;

private:
    sol::state lua;
    std::unordered_map<std::string, BlockInfo> blockData;
};

#endif // BLOCKMANAGER_H
