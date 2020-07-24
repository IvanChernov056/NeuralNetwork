#pragma once

#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <optional>

namespace Json
{

  /**@ Json::Value class

   * This is a container to work with json files.
   * StorageValue will contain a value as:
   *    string
   *    float
   *    int
   *    Value
  */

  
  enum class Type
  {
    UNDEFINED = -1, 
    INT,
    FLOAT,
    STRING,
    VALUE,
    ARRAY
  };


  class Value
  {

    using ValuePtr = std::unique_ptr<Value>;
    using ObjectMapContainer = std::unordered_map<std::string, ValuePtr>;
    using ArrayList = std::vector<ValuePtr>;
    
    public:
      
      explicit Value(Type i_type = Type::UNDEFINED);
      explicit Value(int value);
      explicit Value(float value);
      explicit Value(const std::string& value);
      Value(const Value& value);
      ~Value();

      Value& operator=(const Value& value);
      Value& operator=(int value);
      Value& operator=(float value);
      Value& operator=(const std::string& value);

      int toInt() const;
      float toFloat() const;
      std::string toString() const;

      Value& append(const Value& value);
      Value& append(int value);
      Value& append(float value);
      Value& append(const std::string& value);

      inline bool isInt() const
      {
        return d_type == Type::INT;
      }

      inline bool isFloat() const 
      {
        return d_type == Type::FLOAT;
      }

      inline bool isString() const
      {
        return d_type == Type::STRING;
      }

      inline bool isObject() const
      {
        return d_type == Type::VALUE;
      }

      inline bool isArray() const
      {
        return d_type == Type::ARRAY;
      }

      inline bool isNull() const
      {
        return d_arrData.empty() && d_objData.empty() || d_type == Type::UNDEFINED;
      }

      inline bool contains(const std::string& key) const
      {
        return !(d_objData.find(key) == d_objData.end() 
                  || d_objData.find(key) == d_objData.cend());
      }

      Value& operator[](const std::string& key);
      const Value& operator[](const std::string& key) const;

      friend std::ostream& operator<<(std::ostream& os, const Value& value);


    private:

      inline void clearArray()
      {
        d_arrData = ArrayList();
      }
      inline void clearObj()
      {
        d_objData = ObjectMapContainer();
      }

    private:

      Type d_type{Type::UNDEFINED};

      union StorageValue 
      {
        int iValue;
        float fValue;
      };
        
      StorageValue d_data;
      std::string d_sData;
      ArrayList d_arrData;
      ObjectMapContainer d_objData;
  };

  std::optional<Value> readFromFile(const std::string& file);
  bool validate(const std::string& str);
}