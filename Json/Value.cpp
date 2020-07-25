#include "Value.h"

#include <exception>
#include <sstream>
#include <cstring>
#include <fstream>
#include <algorithm>

namespace Json
{

  Value::Value(Type i_type) : d_type(i_type)
  { 
    std::memset(&d_data, 0, sizeof(d_data));
  }

  Value::Value(int value)
  {
    *this = value;
  }
  Value::Value(float value)
  {
    *this = value;
  }
  Value::Value(const std::string& value)
  {
    *this = value;
  }
  Value::Value(const Value& value) 
  {
    *this = value;
  }
  
  Value::~Value() 
  {
    clearArray();
    clearObj();
  }

  Value& Value::operator=(const Value& value) 
  {
    d_type = value.d_type;
    clearObj();
    d_sData = std::string();

    switch(d_type)
    {
      case Type::UNDEFINED : break;
      case Type::INT : 
        d_data.iValue = value.d_data.iValue; 
        break;
      case Type::FLOAT :
        d_data.fValue = value.d_data.fValue; 
        break;
      case Type::STRING :
        d_sData = value.d_sData; 
        break;
      case Type::VALUE :
        for(const auto& [key, val] : value.d_objData)
        {
          ValuePtr copyValue = std::make_unique<Value>();
          *copyValue = *val;
          d_objData.emplace(key, std::move(copyValue));
        }
        break;
      case Type::ARRAY :
        for(const auto& val : value.d_arrData) 
        {
          ValuePtr copyValue = std::make_unique<Value>();
          *copyValue = *val;
          d_arrData.push_back(std::move(copyValue));
        }
        break;
      default:
        break;
    }

    return *this;
  }

  Value& Value::operator=(int value) 
  {
    d_type = Type::INT;
    clearObj();
    d_sData = std::string();
    d_data.iValue = value;

    return *this;
  }


  Value& Value::operator=(float value) 
  {
    d_type = Type::FLOAT;
    clearObj();
    d_sData = std::string();
    d_data.fValue = value;

    return *this;
  }

  Value& Value::operator=(const std::string& value) 
  {
    d_type = Type::STRING;
    clearObj();
    d_sData = value;

    return *this;
  }



  Value& Value::append(const Value& value)
  {
    if(!isNull())
    {
      d_arrData.push_back(std::move(std::make_unique<Value>(*this)));
      d_objData = ObjectMapContainer();
    }
    d_type = Type::ARRAY;
    ValuePtr copyValue = std::make_unique<Value>();
    *copyValue = value;
    d_arrData.push_back(std::move(copyValue));
    return *this;
  }
  Value& Value::append(int value)
  {
    return append(Value(value));
  }
  Value& Value::append(float value)
  {
    return append(Value(value));
  }
  Value& Value::append(const std::string& value)
  {
    return append(Value(value));
  }



  int Value::toInt() const
  {
    switch (d_type)
    {
    case Type::INT :
      return d_data.iValue;
      break;
    case Type::FLOAT :
      return static_cast<int>(d_data.fValue);
      break;
    case Type::STRING : 
      return std::atoi(d_sData.c_str());
      break;
    default:
      throw std::runtime_error("can not be converted to Int");
      break;
    }
  }

  float Value::toFloat() const
  {
    switch (d_type)
    {
    case Type::INT :
      return static_cast<float>(d_data.iValue);
      break;
    case Type::FLOAT :
      return d_data.fValue;
      break;
    case Type::STRING : 
      return std::atof(d_sData.c_str());
      break;
    default:
      throw std::runtime_error("can not be converted to Float");
      break;
    }
  }

  std::string Value::toString() const
  {
    switch (d_type)
    {
    case Type::INT :
      return std::to_string(d_data.iValue);
      break;
    case Type::FLOAT :
      return std::to_string(d_data.fValue);
      break;
    case Type::STRING : 
      return d_sData;
      break;
    case Type::VALUE :
      {
        std::stringstream ss;
        ss << *this;
        return ss.str();
      }
    default:
      throw std::runtime_error("can not be converted to Float");
      break;
    }
  }


  Value& Value::operator[](const std::string& key)
  {
    d_type = Type::VALUE;
    clearArray();
    if(!contains(key))
    {
      d_objData[key] = std::make_unique<Value>(Type::UNDEFINED);
    }
    return *d_objData[key];
  }

  const Value& Value::operator[](const std::string& key) const
  {
    if(!contains(key))
    {
      throw std::runtime_error("const Json::Value object has no any value with key \"" + key + "\"");
    }
    return *d_objData.at(key);
  }

  std::ostream& operator<<(std::ostream& os, const Value& value) 
  {
    switch (value.d_type)
    {
    case Type::UNDEFINED :
      return os << "none";
      break;
    case Type::INT :
      return os << value.d_data.iValue;
      break;
    case Type::FLOAT :
      return os << value.d_data.fValue;
      break;
    case Type::STRING :
      return os << value.d_sData;
      break;
    case Type::VALUE :
      {
        os << "{";
        int count = value.d_objData.size();
        for(const auto& [key, val] : value.d_objData)
        {
          os << "\"" << key << "\" : ";
          if(val->d_type == Type::STRING)
            os << "\"" << *val << "\"";
          else 
            os << *val;
          
          if(count-- > 1)
            os << ", ";
        }
        return os << "}";
      }
      break;
    case Type::ARRAY :
      {
        os << "[";
        int count = value.d_arrData.size();
        for(const auto& val : value.d_arrData)
        {
          if(val->d_type == Type::STRING)
            os << "\"" << *val << "\"";
          else 
            os << *val;
          
          if(count-- > 1)
            os << ", ";
        }
        return os << "]";
      }
      break;
    }
    return os;
  }


  std::string load(const std::string& file)
  {
    std::ifstream fs(file);
    if(!fs.is_open())
      throw std::runtime_error("file : \"" + file + "\" not found");
    std::stringstream ss;
    ss << fs.rdbuf();
    if(fs.bad() || fs.fail() || ss.bad() || ss.fail())
      throw std::runtime_error("something bad has happened while reading file \"" + file + "\"");

    std::string buff;
    buff = ss.str();
    buff.erase(std::remove_if(buff.begin(), buff.end(), [](auto c)
      {
        return c == '\n' || c == '\t';
      }), buff.end());
    
    return buff;
  }




  Value makeValue(std::istream& is)
  {
    Value result;
    char c;
    while((c = is.get()) == ' ');
    
    switch (c)
    {
    case '{':
      {
        do
        {
          while((c = is.get()) != '"');
          std::string key;
          while((c = is.get()) != '"')
            key.push_back(c);
          while((c = is.get()) != ':');
          result[key] = makeValue(is);
          do{
            c = is.get();
          }while(c != '}' && c != ',' );
        }while(c != '}');   
      }
      break;
    case '[' :
      {
        do {
          result.append(makeValue(is));
          c = is.get();
        }while(c != ']');
      }
      break;

    default:
      {
        std::string strValue;
        if(c != '"')
          strValue.push_back(c);
        do
        {
          if(!is.eof())
            c = is.get();
          else break;
          if(c == ',' || c == ']'  || c == '}' || c == '"')
            break;
          strValue.push_back(c);
        } while (true);
       
        if(c == ',' || c == ']'  || c == '}')
          is.putback(c);

        bool isNumber = true;
        int pointsCounter = 0;

        for(const char c : strValue)
        {
          if((c < '0' || c > '9') && c != '.')
          {
            isNumber =false;
            break;
          }
          if(c == '.')
            ++pointsCounter;
        }

        if(isNumber && pointsCounter == 1)
          result = (float)std::atof(strValue.c_str());
        else if(isNumber && pointsCounter == 0)
          result = std::atoi(strValue.c_str());
        else result = strValue;
      }  
      break;
    }

    return result;
  }

  


  std::optional<Value> readFromFile(const std::string& file) 
  {
    std::stringstream ss;
    try {
      ss << load(file);
    }
    catch(std::exception& e)
    {
      std::cerr << e.what() << std::endl;
      return std::nullopt;
    }



    if(!validate(ss.str()))
    {
      std::cerr << "file contains not valide json format" << std::endl;
      return std::nullopt;
    }

    return makeValue(ss);
       
  }


  bool validate(const std::string& str)
  {
    std::string stack;
    int bracesCounter = 0;
    int quotesCounter = 0;
    bool inQuotes = false;

    for(auto c : str)
    {
      if(c == '"')
      {
        inQuotes = !inQuotes;
        ++quotesCounter;
      }

      if(!inQuotes && (c == '{' || c == '['))
        ++bracesCounter;

      if(!inQuotes && (c == '}' || c == ']'))
        --bracesCounter;

      if(inQuotes && (c == '{' || c == '[' || c == '}' || c == ']'))
        return false;
    }
    
    return !inQuotes && (bracesCounter == 0) && (quotesCounter%2 == 0);
  }
}