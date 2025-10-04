#pragma once

#include "../../../../application/server/repository/DaysMealsRepository.hpp"

#include <Arduino.h>
#include <LittleFS.h>
#include <ArduinoJson.h>

class LittleFsFileSystem{
public:

};

class FileNameCreator{
public:
    static std::string createFileName(CommonDateTime date){
        return "/data/" + date.getDateString() + ".json";
    }
};

class DaysMealsToJsonStringMapper{
public:
    static std::string map(DaysMeals data){
        StaticJsonDocument<2048> doc;
        doc["date"] = data.getDay().getDateString();
        JsonArray mealsArray = doc.createNestedArray("meals");
        
        for (const auto& kv : data.getAll()) {
            MealEntity entity = kv.second;

            JsonObject entityObj = mealsArray.createNestedObject();
            entityObj["status"] = entity.getStatus();
            entityObj["type_str"] = MealTypeToString::map(entity.getType());
            entityObj["type"] = (int)entity.getType();
            entityObj["time"] = entity.getDateTime().getTimeString();
        }

        std::string res;
        serializeJson(doc, res);

        return res;
    }

    static DaysMeals map(std::string json){
        StaticJsonDocument<2048> doc;
        DeserializationError error = deserializeJson(doc, json);

        if (error) {
            return DaysMeals();
        }

        DaysMeals res;

        CommonDateTime day;
        day.deserializeDateFromString(doc["date"]);
        res.setDay(day);

        JsonArray mealsArray = doc["meals"].as<JsonArray>();
        for (JsonObject mealObj : mealsArray){
            CommonDateTime time;
            time.deserializeTimeFromString(mealObj["time"].as<std::string>());

            MealEntity meal(
                static_cast<MealType>(mealObj["type"].as<int>()),
                mealObj["status"].as<bool>(),
                time
            );

            res.append(meal);
        }

        return res;
    }
};

class DaysMealsRepositoryInMemoryImpl: public DaysMealsRepository{
public:
    int create(DaysMeals entity){
        std::string filePath = FileNameCreator::createFileName(entity.getDay());
        File file = LittleFS.open(filePath.c_str(), FILE_WRITE);
        if (!file){
            return -1;
        }

        std::string json = DaysMealsToJsonStringMapper::map(entity);
        if(!file.print(json.c_str())) {
            file.close();
            return -1;
        }
        file.close();

        return -1;
    }
    int getByDay(CommonDateTime day, DaysMeals* result){
        std::string filePath = FileNameCreator::createFileName(day);

        if (!LittleFS.exists(filePath.c_str())){
            return -1;
        }

        File file = LittleFS.open(filePath.c_str(), FILE_READ);
        if(!file) {
            return -1;
        }
        
        std::string json;
        while(file.available()) {
            json += file.read();
        }
        Serial.println(json.c_str());
        file.close();
        
        *result = DaysMealsToJsonStringMapper::map(json);

        return 0;
    }
    int update(DaysMeals entity){
        return -1;
    }
    int remove(DaysMeals entity){
        return -1;
    }
    int getListWithDates(std::list<DaysMeals>* result){
        return -1;
    }
};