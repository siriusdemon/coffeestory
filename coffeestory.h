#pragma once


#include <string>
#include <vector>
#include <map>


struct Rule {
    int hit;
    std::vector<std::string> key;
};

using RuleMap = std::map<std::string, std::vector<Rule>>;

RuleMap Rules = {
    // cd hat
    {"cd1", {{1, {"cd"}}}},
    {"cd2", {{2, {"cd"}}}},
    {"cd3", {{3, {"cd"}}}},
    {"lukcd2", {{2, {"luk", "cd"}}}},
    {"strcd2", {{2, {"str", "cd"}}}},
    {"intcd2", { {2, {"int", "cd"}} }},
    { "dexcd2", {{2, {"dex", "cd"}}} },
    { "allcd2", {{2, {"all", "cd"}}} },
    { "hpcd2", {{2, {"hp", "cd"}}} },
    { "lukcd3", {{3, {"luk", "cd"}}} },
    { "strcd3", {{3, {"str", "cd"}}} },
    { "intcd3", {{3, {"int", "cd"}}} },
    { "dexcd3", {{3, {"dex", "cd"}}} },
    { "allcd3", {{3, {"all", "cd"}}} },
    { "hpcd3", {{3, {"hp", "cd"}}} },
    // glove
    { "crtdmg1", {{1, {"crtdmg"}}} },
    { "crtdmg2", {{2, {"crtdmg"}}} },
    { "crtdmg3", {{3, {"crtdmg"}}} },
    { "lukcrtdmg2", {{2, {"luk", "crtdmg", "all"}}} },
    { "strcrtdmg2", {{2, {"str", "crtdmg", "all"}}} },
    { "intcrtdmg2", {{2, {"int", "crtdmg", "all"}}} },
    { "dexcrtdmg2", {{2, {"dex", "crtdmg", "all"}}} },
    { "allcrtdmg2", {{2, {"crtdmg", "all"}}} },
    { "hpcrtdmg2", {{2, {"crtdmg", "hp"}}} },
    { "lukcrtdmg3", {{3, {"luk", "crtdmg", "all"}}} },
    { "strcrtdmg3", {{3, {"str", "crtdmg", "all"}}} },
    { "intcrtdmg3", {{3, {"int", "crtdmg", "all"}}} },
    { "dexcrtdmg3", {{3, {"dex", "crtdmg", "all"}}} },
    { "allcrtdmg3", {{3, {"crtdmg", "all"}}} },
    { "hpcrtdmg3", {{3, {"crtdmg", "hp"}}} },
    // weapon
    { "att3", {{3, {"att"}}} },
    { "matt3", {{3, {"matt"}}} },
    { "attb", {{3, {"att", "boss"}}} },
    { "mattb", {{3, {"matt", "boss"}}} },
    { "arm2", {{2, {"att", "boss", "dmg", "ignore"}}}},
    { "arm3", {{3, {"att", "boss", "dmg", "ignore"}}}},
    { "marm2", {{2, {"matt", "boss", "dmg", "ignore"}}}},
    { "marm3", {{3, {"matt", "boss", "dmg", "ignore"}}}},
    // normal armor
    { "int3", {{3, {"int", "all"}}} },
    { "str3", {{3, {"str", "all"}}} },
    { "luk3", {{3, {"luk", "all"}}} },
    { "dex3", {{3, {"dex", "all"}}} },
    { "all3", {{3, {"all"}}} },
    { "hp3", {{3, {"hp"}}} },
    // accessory
    { "md1", {{1, {"drop", "meso"}}} },
    { "md2", {{2, {"drop", "meso"}}} },
    { "md3", {{3, {"drop", "meso"}}} },
    { "d1", {{1, {"drop"}}} },
    { "d2", {{2, {"drop"}}} },
    { "d3", {{3, {"drop"}}} },
    { "lukmd2", {{2, {"luk", "all", "meso", "drop"}}} },
    { "intmd2", {{2, {"int", "all", "meso", "drop"}}} },
    { "dexmd2", {{2, {"dex", "all", "meso", "drop"}}} },
    { "strmd2", {{2, {"str", "all", "meso", "drop"}}} },
    { "allmd2", {{2, {"all", "meso", "drop"}}} },
    { "hpmd2", {{2, {"hp", "meso", "drop"}}} },
    { "hpmd3", {{3, {"hp", "meso", "drop"}}, {2, {"meso", "drop"}}} },
    { "allmd3", {{3, {"all", "meso", "drop"}}, {2, {"meso", "drop"}}} },
    { "lukmd3", {{3, {"luk", "all", "meso", "drop"}}, {2, {"meso", "drop"}}} },
    { "intmd3", {{3, {"int", "all", "meso", "drop"}}, {2, {"meso", "drop"}}} },
    { "dexmd3", {{3, {"dex", "all", "meso", "drop"}}, {2, {"meso", "drop"}}} },
    { "strmd3", {{3, {"str", "all", "meso", "drop"}}, {2, {"meso", "drop"}}} }
};

