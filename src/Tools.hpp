#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <regex>
#include <sstream>
#include <fstream>
#include "nlohmann/json.hpp"
//#include "../lib/ibpp/ibpp.hpp"
//#include "../lib/ibpp/ibpp.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
//#include "date.h"
#include <iostream>
#include <stdint.h>
#include "oatpp/web/protocol/http/Http.hpp"

using json = nlohmann::json;

class Tools
{
private:
    static  bool BothAreSpaces(char lhs, char rhs);
  typedef oatpp::web::protocol::http::Status Status;

public:
    static std::string getTimeNow();
    static std::string getDateNow();
    static std::string removeMultipleSpace(std::string in);
    static std::string replaceSubstring(std::string find, std::string replace, std::string var);
    static std::string replaceInvalidAscii(std::string text);
    static oatpp::data::mapping::type::Void printDTO(const oatpp::data::mapping::type::Void &variant);
    static std::string dtoToString(const oatpp::data::mapping::type::Void &variant);
    static std::vector<std::string> explode(std::string const s, char delim);
    static std::string ltrim(std::string s);
    static std::string rtrim(std::string s);
    static std::string trim(std::string s);
    static std::string string_to_upper(std::string string);
    static std::string string_to_lower(std::string string);
    static json eliminarRepetidosOrdenadosPorAtributo(json array, std::string atributo_1, std::string atributo_2);
    // static IBPP::Date stringToDate(oatpp::String string);
    // static IBPP::Timestamp stringToTimestamp(oatpp::String string);
    // static IBPP::Date intToDate(int64_t myInt);
    // static IBPP::Timestamp intToTimestamp(int64_t myInt);
    static std::string intToDateString(int64_t myInt);
    static std::string fillNumber(double n, int precision, int with);
    static std::string fillString(std::string cadena, unsigned int length, char caracterParaCompletar, bool fillLeft = true);
    static bool fileExists(const std::string &name);
    static std::string stripUnicode(std::string str);
    static bool invalidChar (char c);
};

#endif // TOOLS_HPP
