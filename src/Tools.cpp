
#include "Tools.hpp"

std::string Tools::getDateNow()
{
  std::time_t rawtime;
  std::tm *timeinfo;
  char buffer[20];

  std::time(&rawtime);
  timeinfo = std::localtime(&rawtime);

  std::strftime(buffer, 20, "%d/%m/%Y", timeinfo);
  return buffer;
}

std::string Tools::getTimeNow()
{
  std::time_t rawtime;
  std::tm *timeinfo;
  char buffer[20];

  std::time(&rawtime);
  timeinfo = std::localtime(&rawtime);

  std::strftime(buffer, 20, "%I:%M %p", timeinfo);
  return buffer;
}

bool Tools::invalidChar(char c)
{
  return !(c >= 0 && c < 128);
}
std::string Tools::stripUnicode(std::string str)
{
  str.erase(remove_if(str.begin(), str.end(), invalidChar), str.end());
  return str;
}

std::string Tools::fillNumber(double n, int precision, int with)
{
  double temp;
  std::stringstream stream;
  if (modf(n, &temp) != 0 && precision == 0)
  {
    stream << std::setw(with) << std::fixed << std::setprecision(2) << n;
  }
  else
  {
    stream << std::setw(with) << std::fixed << std::setprecision(precision) << n;
  }
  std::string s = stream.str();
  std::replace(s.begin(), s.end(), '.', ',');
  return s;
}

bool Tools::fileExists(const std::string &name)
{
  std::ifstream f(name.c_str());
  return f.good();
}

std::string Tools::fillString(std::string cadena, unsigned int length, char caracterParaCompletar, bool fillLeft)
{
  std::string respuesta;
  if (cadena.length() > length)
  {
    respuesta = cadena;
  }
  else
  {
    respuesta = fillLeft ? std::string(length - cadena.size(), caracterParaCompletar) + cadena : cadena + std::string(length - cadena.size(), caracterParaCompletar);
  }
  return respuesta;
}

bool Tools::BothAreSpaces(char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); }
std::string Tools::removeMultipleSpace(std::string str)
{

  std::string::iterator new_end = std::unique(str.begin(), str.end(), BothAreSpaces);
  str.erase(new_end, str.end());

  return str;
}

std::string Tools::replaceSubstring(std::string find, std::string replace, std::string var)
{
  std::string res = var;
  res = std::regex_replace(res, std::regex(find), replace);
  return res;
}

std::string Tools::replaceInvalidAscii(std::string text)
{
  std::string result = "";
  for (size_t i = 0; i < text.size(); i++)
  {
    if ((text[i] >= 0 && text[i] <= 128))
    {
      result += text[i];
    }
  }

  return result;
}

oatpp::data::mapping::type::Void Tools::printDTO(const oatpp::data::mapping::type::Void &variant)
{
  auto serializeConfig = oatpp::parser::json::mapping::Serializer::Config::createShared();
  auto deserializeConfig = oatpp::parser::json::mapping::Deserializer::Config::createShared();

  /* enable beautifier */
  serializeConfig->useBeautifier = true;

  /* create json object mapper with serializer config */
  auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared(serializeConfig, deserializeConfig);
  oatpp::String json = jsonObjectMapper->writeToString(variant);
  OATPP_LOGD("", "%s", json.getValue("").c_str());
  return variant;
}

std::string Tools::dtoToString(const oatpp::data::mapping::type::Void &variant)
{
  auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
  oatpp::String json = jsonObjectMapper->writeToString(variant);
  return json;
}

std::vector<std::string> Tools::explode(std::string const s, char delim)
{
  std::vector<std::string> result;
  std::istringstream iss(s);

  for (std::string token; std::getline(iss, token, delim);)
  {
    result.push_back(std::move(token));
  }

  return result;
}

std::string Tools::ltrim(std::string s)
{
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
                                  { return !std::isspace(ch); }));
  return s;
}

std::string Tools::rtrim(std::string s)
{
  s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                       { return !std::isspace(ch); })
              .base(),
          s.end());
  return s;
}

std::string Tools::trim(std::string s)
{
  return ltrim(rtrim(s));
}

std::string Tools::string_to_upper(std::string string)
{
  for (auto &c : string)
    c = toupper(c);

  return string;
}

std::string Tools::string_to_lower(std::string string)
{
  for (auto &c : string)
    c = tolower(c);

  return string;
}

// IBPP::Date Tools::stringToDate(oatpp::String string)
// {
//   // OATPP_LOGI("servicio Tools", "Entrando a stringToDate %s", string->c_str());

//   auto day = string.getValue("01").substr(0, 2);
//   auto month = string.getValue("01").substr(3, 2);
//   auto year = string.getValue("1900").substr(6, 4);
//   // OATPP_LOGI("servicio Tools", "Dia: %s", day.c_str());
//   // OATPP_LOGI("servicio Tools", "Mes: %s", month.c_str());
//   // OATPP_LOGI("servicio Tools", "Año: %s", year.c_str());
//   int iDay = std::stoi(day);
//   int iMonth = std::stoi(month);
//   int iYear = std::stoi(year);
//   IBPP::Date datestring(iYear, iMonth, iDay);
//   // OATPP_LOGI("servicio Tools", "Saliendo de stringToDate");
//   return datestring;
// }
// IBPP::Timestamp Tools::stringToTimestamp(oatpp::String string)
// {
//   // OATPP_LOGI("servicio Tools", "Entrando a stringToDate %s", string->c_str());

//   auto day = string.getValue("01").substr(0, 2);
//   auto month = string.getValue("01").substr(3, 2);
//   auto year = string.getValue("1900").substr(6, 4);
//   auto hour = string.getValue("00").substr(11, 2);
//   auto min = string.getValue("00").substr(14, 2);
//   auto sec = string.getValue("00").substr(17, 2);
//   OATPP_LOGI("servicio Tools", "Dia: %s -  Mes: %s -  Año: %s -  Hora: %s -  Min: %s -  Sec: %s", day.c_str(), month.c_str(), year.c_str(), hour.c_str(), min.c_str(), sec.c_str());

//   int iDay = std::stoi(day);
//   int iMonth = std::stoi(month);
//   int iYear = std::stoi(year);
//   int iHour = std::stoi(hour);
//   int iMin = std::stoi(min);
//   int iSec = std::stoi(sec);
//   IBPP::Timestamp datestring(iYear, iMonth, iDay, iHour, iMin, iSec);
//   // OATPP_LOGI("servicio Tools", "Saliendo de stringToDate");
//   return datestring;
// }

// IBPP::Timestamp Tools::intToTimestamp(int64_t myInt)
// {
//   // OATPP_LOGI("servicio Tools", "Entrando a intToDate %f", myInt);
//   std::string stringDate = intToDateString(myInt);
//   auto newDate = stringToTimestamp(stringDate);
//   // OATPP_LOGI("servicio Tools", "Saliendo de intToDate");
//   return newDate;
// }

// IBPP::Date Tools::intToDate(int64_t myInt)
// {
//   // OATPP_LOGI("servicio Tools", "Entrando a intToDate %f", myInt);
//   std::string stringDate = intToDateString(myInt);
//   auto newDate = stringToDate(stringDate);
//   // OATPP_LOGI("servicio Tools", "Saliendo de intToDate");
//   return newDate;
// }

std::string Tools::intToDateString(int64_t myInt)
{
  // OATPP_LOGI("servicio Tools", "Entrando a intToDateString %f", myInt);

  std::int64_t time_date_stamp = (myInt / 1000);
  std::time_t temp = time_date_stamp;
  std::tm *t = std::gmtime(&temp);
  std::stringstream ss; // or if you're going to print, just input directly into the output stream
  ss << std::put_time(t, "%d.%m.%Y %H:%M:%S");
  std::string stringDate = ss.str();

  // OATPP_LOGI("servicio Tools", "Saliendo de intToDateString");
  return stringDate;
}
