//
// Created by taylu on 9/9/2024.
//
#ifndef FIGHTER_H
#define FIGHTER_H

#include <cmath>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//define class and private variables
class Fighter {
private:
    string name;
    //using floats for all numerical variables
    float wins, losses, draws, sigStrAcc, sigStrDef, tdAcc, tdDef, height, weight, sigStrPerMin,
    sigStrAbsPerMin, tdLandedPer15, avgSubAttemptsPer15;

public:
    // Constructors
    Fighter();
    Fighter(string name, float wins, float losses, float draws, float sigStrAcc, float sigStrDef, float tdAcc,
            float tdDef, float height, float weight, float sigStrPerMin, float sigStrAbsPerMin,
            float tdLandedPer15, float avgSubAttemptsPer15);

    // Getters
    string getName() const ;
    // get fighter wins
    int getWins() const ;
    // get fighter losses
    int getLosses() const ;
    // get fighter draws
    int getDraws() const ;
    // get fighter significant strike accuracy percentage
    int getSigStrAcc() const ;
    // get fighter significant strikes defended percentage
    int getSigStrDef() const ;
    // get fighter takedown accuracy percentage
    int getTdAcc() const ;
    //get fighter take down defence percentage
    int getTdDef() const ;
    // get fighter height in cm
    float getHeight() const ;
    // get fighter weight in kg
    float getWeight() const ;
    // get fighter significant strikes landed per minute
    float getSigStrPerMin() const ;
    // get fighter sinigicant strikes absorbed per minute
    float getSigStrAbsPerMin() const ;
    // get fighter avg takedowns landed per 15 minutes
    float getTdLandedPer15() const ;
    // get fighter avg submissions attempted every 15 minutes
    float getAvgSubAttemptsPer15() const ;


    //setters
    // set fighter name
    void setName(string name) ;
    // set fighter wins
    void setWins(int wins) ;
    // set fighter losses
    void setLosses(int losses) ;
    // set fighter draws
    void setDraws(int draws) ;
    // set fighter significant strike accuracy percentage
    void setSigStrAcc(int sigStrAcc) ;
    // set fighter significant strikes defended percentage
    void setSigStrDef(int sigStrDef) ;
    // set fighter takedown accuracy percentage
    void setTdAcc(int tdAcc) ;
    // set fighter takedown defense percentage
    void setTdDef(int tdDef) ;
    // set fighter weight
    void setHeight(float height) ;
    // set fighter height
    void setWeight(float weight) ;
    // set fighter significant strikes landed per min
    void setSigStrPerMin(float sigStrPerMin) ;
    // set fighter significant strikes absorbed per minute
    void setSigStrAbsPerMin(float sigStrAbsPerMin) ;
    // set fighter takedowns landed every 15 mins
    void setTdLandedPer15(float tdLandedPer15) ;
    // set fighter submission attempts every 15 minutes
    void setAvgSubAttemptsPer15(float avgSubAttemptsPer15) ;

    // overloading << operator
    friend ostream& operator << (ostream& outs, const Fighter& obj);

    //overloading < operator
    bool operator < (const Fighter& obj) const;
    //overloading > operator
    bool operator > (const Fighter& obj) const;
    //overloading <= operator
    bool operator <= (const Fighter& obj) const;
    //overloading >= operator
    bool operator >= (const Fighter& obj) const;
    //overloading == operator
    bool operator == (const Fighter& obj) const;
    //overloading != operator
    bool operator != (const Fighter& obj) const;

};


/**
 * gets data from file and stores it in a vector of fighter objects
 * @param fighters a vector of fighter objects
 * @return bool true if data read successfully, false if not
 */
bool getDataFromFile(vector<Fighter>& fighters);

/**
 * avgWins finds the average number of wins across all fighters in the dataset
 * @param fighters vector of Fighter objects
 * @return float avg wins - the average wins across all fighters
 */
float avgWins(const vector<Fighter>& fighters);

/**
 * method findFighter takes a vector of fighters, asks the user which fighter they are looking for, if fighter in data
 * returns the index of the fighter, otherwise returns -1 (unused index)
 * @param fighters vector of Fighter objects
 * @return int i the index of the searched fighted
 */
int findFighter(vector<Fighter>& fighters);

/**
 * wlRatio finds the win to loss ratio of a specified fighter
 * @param fighters vector of Fighter objects
 * @return float ratio, the ratio of wins to losses a fighter has, if the fighter is undefeated it just returns wins
 */
float wlRatio(vector<Fighter>& fighters);

/**
 * get averages calculates the average value for every field in the data, and pushes it to the vector
 * @param fighters a vector of fighter objects
 * @return bool - weather or not pushing averages was successful
 */
bool getAverages(vector<Fighter>& fighters);
#endif //FIGHTER_H