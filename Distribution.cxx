//
// Created by Oleksandr Deundiak on 9/26/17.
//

#include "Distribution.h"
#include "CyrillicCharacter.h"
#include "LatinCharacter.h"

template <>
Distribution<CyrillicCharacter>::Distribution() {
    std::map<std::string, double> id = {
        {"о", 0.1097},
        {"е", 0.0849},
        {"а", 0.0801},
        {"и", 0.0735},
        {"н", 0.0670},
        {"т", 0.0626},
        {"с", 0.0547},
        {"р", 0.0473},
        {"в", 0.0454},
        {"л", 0.0440},
        {"к", 0.0349},
        {"м", 0.0321},
        {"д", 0.0298},
        {"п", 0.0281},
        {"у", 0.0262},
        {"я", 0.0201},
        {"ы", 0.0190},
        {"ь", 0.0174},
        {"г", 0.0170},
        {"з", 0.0165},
        {"б", 0.0159},
        {"ч", 0.0144},
        {"й", 0.0121},
        {"х", 0.0097},
        {"ж", 0.0094},
        {"ш", 0.0073},
        {"ю", 0.0064},
        {"ц", 0.0048},
        {"щ", 0.0036},
        {"э", 0.0032},
        {"ф", 0.0026},
        {"ъ", 0.0004}
    };

    std::map<int, double> ideal;

    for (auto it = id.begin(); it != id.end(); it++) {
        ideal[CyrillicCharacter(it->first).getCharNum()] = it->second;
    }

    this->ideal = ideal;
}

template <>
Distribution<LatinCharacter>::Distribution() {
    std::map<std::string, double> id = {
            {"e", 0.12702},
            {"t", 0.09056},
            {"a", 0.08167},
            {"o", 0.07507},
            {"i", 0.06966},
            {"n", 0.06749},
            {"s", 0.06327},
            {"h", 0.06094},
            {"r", 0.05987},
            {"d", 0.04253},
            {"l", 0.04025},
            {"c", 0.02782},
            {"u", 0.02758},
            {"m", 0.02406},
            {"w", 0.02360},
            {"f", 0.02228},
            {"g", 0.02015},
            {"y", 0.01974},
            {"p", 0.01929},
            {"b", 0.01492},
            {"v", 0.00978},
            {"k", 0.00772},
            {"j", 0.00153},
            {"x", 0.00150},
            {"q", 0.00095},
            {"z", 0.00074}
    };

    std::map<int, double> ideal;

    for (auto it = id.begin(); it != id.end(); it++) {
        ideal[LatinCharacter(it->first).getCharNum()] = it->second;
    }

    this->ideal = ideal;
}