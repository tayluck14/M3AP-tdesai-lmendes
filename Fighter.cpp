//
// Created by taylu on 9/9/2024.
//
#include "Fighter.h"

using namespace std;


Fighter::Fighter() : name("Dana White"), wins(-1.f), losses(-1.f), draws(-1.f), sigStrAcc(-1.f),
                    sigStrDef(-1.f), tdAcc(-1.f), tdDef(-1.f), height(-1.f), weight(-1.f),
                    sigStrPerMin(-1.f), sigStrAbsPerMin(-1.f), tdLandedPer15(-1.f), avgSubAttemptsPer15(-1.f) {}

Fighter::Fighter(string name, float wins, float losses, float draws, float sigStrAcc,
                float sigStrDef, float tdAcc, float tdDef, float height, float weight,
                float sigStrPerMin, float sigStrAbsPerMin, float tdLandedPer15, float avgSubAttemptsPer15)
: name(name), wins(wins), losses(losses), draws(draws), sigStrAcc(sigStrAcc), sigStrDef(sigStrDef),
    tdAcc(tdAcc), tdDef(tdDef), height(height), weight(weight), sigStrPerMin(sigStrPerMin),
    sigStrAbsPerMin(sigStrAbsPerMin), tdLandedPer15(tdLandedPer15), avgSubAttemptsPer15(avgSubAttemptsPer15) {}

// getters
string Fighter::getName() const { return name; }
int Fighter::getWins() const { return wins; }
int Fighter::getLosses() const { return losses; }
int Fighter::getDraws() const { return draws; }
int Fighter::getSigStrAcc() const { return sigStrAcc; }
int Fighter::getSigStrDef() const { return sigStrDef; }
int Fighter::getTdAcc() const { return tdAcc; }
int Fighter::getTdDef() const { return tdDef; }
float Fighter::getHeight() const { return height; }
float Fighter::getWeight() const { return weight; }
float Fighter::getSigStrPerMin() const { return sigStrPerMin; }
float Fighter::getSigStrAbsPerMin() const { return sigStrAbsPerMin; }
float Fighter::getTdLandedPer15() const { return tdLandedPer15; }
float Fighter::getAvgSubAttemptsPer15() const { return avgSubAttemptsPer15; }

//setters
// set fighter name
void Fighter::setName(string name) { this->name = name; }
void Fighter::setWins(int wins) { this->wins = wins; }
void Fighter::setLosses(int losses) { this->losses = losses; }
void Fighter::setDraws(int draws) { this->draws = draws; }
void Fighter::setSigStrAcc(int sigStrAcc) { this->sigStrAcc = sigStrAcc; }
void Fighter::setSigStrDef(int sigStrDef) { this->sigStrDef = sigStrDef; }
void Fighter::setTdAcc(int tdAcc) { this->tdAcc = tdAcc; }
void Fighter::setTdDef(int tdDef) { this->tdDef = tdDef; }
void Fighter::setHeight(float height) { this->height = height; }
void Fighter::setWeight(float weight) { this->weight = weight; }
void Fighter::setSigStrPerMin(float sigStrPerMin) { this->sigStrPerMin = sigStrPerMin; }
void Fighter::setSigStrAbsPerMin(float sigStrAbsPerMin) { this->sigStrAbsPerMin = sigStrAbsPerMin; }
void Fighter::setTdLandedPer15(float tdLandedPer15) { this->tdLandedPer15 = tdLandedPer15; }
void Fighter::setAvgSubAttemptsPer15(float avgSubAttemptsPer15) { this->avgSubAttemptsPer15 = avgSubAttemptsPer15; }

ostream& operator << (ostream& outs, const Fighter& obj) {
    //set appropriate widths and precision of for average row
        
    return outs;
}

//overloading < operator
bool Fighter::operator<(const Fighter& obj) const { return name < obj.name; }
bool Fighter::operator>(const Fighter& obj) const { return name > obj.name; }
bool Fighter::operator<=(const Fighter& obj) const { return name <= obj.name; }
bool Fighter::operator>=(const Fighter& obj) const { return name >= obj.name; }
bool Fighter::operator==(const Fighter& obj) const { return name == obj.name; }
bool Fighter::operator!=(const Fighter& obj) const { return name != obj.name; }

/**
    * gets data from file and stores it in a vector of fighter objects
    * @param fighters a vector of fighter objects
    * @return bool true if data read successfully, false if not
    */
bool getDataFromFile(vector<Fighter>& fighters) {
    ifstream fileIn;
    fileIn.open("../fighters.csv");

    if (fileIn) {
        cout << "File opened successfully." << endl;
        string header;
        getline(fileIn, header);
        cout << header << endl;
        // declare default variables to read in
        string name = "Dana White", newline;
        int wins = -1, losses = -1, draws = -1, sigStrAcc = -1, sigStrDef = -1, tdAcc = -1, tdDef = -1;
        float height = -1, weight = -1, sigStrPerMin = -1, sigStrAbsPerMin = -1, tdLandedPer15 = -1, avgSubAttemptsPer15 = -1;
        char comma;

        while (fileIn) {
            //read in name
            getline(fileIn, name, ',');
            //read in wins
            fileIn >> wins;
            if (!fileIn) {
                // set wins to default since there is no data
                wins = -1;
                fileIn.clear();
            }
            fileIn >> comma;
            // read in losses
            fileIn >> losses;
            if (!fileIn) {
                //set losses to default since there is no data
                losses = -1;
                fileIn.clear();
            }
            fileIn >> comma;
            // read in draws
            fileIn >> draws;
            if (!fileIn) {
                draws = -1;
                fileIn.clear();
            }
            fileIn >> comma;
            // read in sig strike accuracy
            fileIn >> sigStrAcc;
            if (!fileIn) {
                sigStrAcc = -1;
                fileIn.clear();
            }
            fileIn >> comma;
            // read in sig strike defence percentage
            fileIn >> sigStrDef;
            if (!fileIn) {
                sigStrDef = -1;
                fileIn.clear();
            }
            fileIn >> comma;
            // read in td acc percentage
            fileIn >> tdAcc;
            if (!fileIn) {
                tdAcc = -1;
                fileIn.clear();
            }
            fileIn >> comma;
            // read in td def percentage
            fileIn >> tdDef;
            if (!fileIn) {
                tdDef = -1;
                fileIn.clear();
            }
            fileIn >> comma;
            // read in height
            fileIn >> height;
            if (!fileIn) {
                height = -1;
                fileIn.clear();
            }
            fileIn >> comma;
            // read in weight
            fileIn >> weight;
            if (!fileIn) {
                weight = -1;
                fileIn.clear();
            }
            fileIn >> comma;
            // read in sig strike landed per min
            fileIn >> sigStrPerMin;
            if (!fileIn) {
                sigStrPerMin = -1;
                fileIn.clear();
            }
            fileIn >> comma;
            // read in sig strikes absorbed per minute
            fileIn >> sigStrAbsPerMin;
            if (!fileIn) {
                sigStrAbsPerMin = -1;
                fileIn.clear();
            }
            fileIn >> comma;
            // read in takedowns landed every 15min
            fileIn >> tdLandedPer15;
            if (!fileIn) {
                tdLandedPer15 = -1;
                fileIn.clear();
            }
            fileIn >> comma;
            // read in average submissions attempted every 15 mins
            // check for eof or end of record
            if(fileIn.peek()=='\n' || fileIn.peek()=='\r' || fileIn.peek() == EOF) {
                //no data
                avgSubAttemptsPer15 = -1;
            } else {
                //there is data
                fileIn>>avgSubAttemptsPer15;
            }
            //remove end of line character
            getline(fileIn, newline);
            //push to vector
            fighters.push_back(Fighter(name, wins, losses, draws, sigStrAcc, sigStrDef, tdAcc, tdDef, height,
                                            weight, sigStrPerMin, sigStrAbsPerMin, tdLandedPer15, avgSubAttemptsPer15));
        }

    } else {
        // if file is not opened
        cout << "File could not be opened." << endl;
        return false;
    }
    //close file and reteurn true to indicate that data was read in succesfully
    fileIn.close();
    return true;
};

/**
    * avgWins finds the average number of wins across all fighters in the dataset
    * @param fighters vector of Fighter objects
    * @return float avg wins - the average wins across all fighters
    */
float avgWins(const vector<Fighter>& fighters) {
    //check for data
    if (fighters.size() != 0) {
        //define vars
        float avgWins = 0;
        float totalWins=0;
        for (int i = 0; i < fighters.size(); i++) {
            totalWins+=fighters[i].getWins();
        }
        avgWins = totalWins/fighters.size();
        return avgWins;
    }
    cout << "Vector is empty - unable to calculate average" << endl;
    return 0.0;
}

/**
    * method findFighter takes a vector of fighters, asks the user which fighter they are looking for, if fighter in data
    * returns the index of the fighter, otherwise returns -1 (unused index)
    * @param fighters vector of Fighter objects
    * @return int i the index of the searched fighted
    */
int findFighter(vector<Fighter>& fighters) {
    //prompt user
    cout << "Enter fighter name: ";
    //initialize name variable
    string name;
    // get input and store in variable, use getline to account for spaces
    getline(cin, name);
    // search vector
    for (int i = 0; i < fighters.size(); i++) {
        //return index if found
        if(fighters[i].getName().compare(name) == 0) {
            return i;
        }
    }
    // if not found return unused index
    cout << "Fighter index not found" << endl;
    return -1;
}

/**
    * wlRatio finds the win to loss ratio of a specified fighter
    * @param fighters vector of Fighter objects
    * @return float ratio, the ratio of wins to losses a fighter has, if the fighter is undefeated it just returns wins
    */
float wlRatio(vector<Fighter>& fighters) {
    // find specified fighter using findFighter method
    int i = findFighter(fighters);
    //handle for division by 0 if fighter has not lost
    if (fighters[i].getLosses()!=0) {
        // calculate and return w/l ratio
        float ratio = float(fighters[i].getWins())/float(fighters[i].getLosses());
        return ratio;
    }
    // special message indicating fighter is undefeated
    cout << fighters[i].getName() << " is undefeated" << endl;
    return fighters[i].getWins();
}

/**
    * get averages calculates the average value for every field in the data, and pushes it to the vector
    * @param fighters a vector of fighter objects
    * @return bool - weather or not pushing averages was successful
    */
bool getAverages(vector<Fighter>& fighters) {
    //declare vars
    float totalWins = 0, totalLosses = 0, totalDraws = 0, totalSigStrAcc = 0, totalSigStrDef = 0, totalTdAcc = 0,
    totalTdDef = 0, totalHeight = 0, totalWeight = 0, totalsigStrPerMin = 0, totalSigStrAbsPerMin = 0,
    totalTdLandedPer15 = 0, totalSubAttemptsPer15 = 0;

    // count valid data points for each variable
    int datapointWins = 0, datapointLosses = 0, datapointDraws = 0, datapointSigStrAcc = 0, datapointSigStrDef = 0, datapointTdAcc = 0,
    datapointTdDef = 0, datapointHeight = 0, datapointWeight = 0, datapointsigStrPerMin = 0, datapointSigStrAbsPerMin = 0,
    datapointTdLandedPer15 = 0, datapointSubAttemptsPer15 = 0;

    //declare average variables
    float avgWins = 0, avgLosses = 0, avgDraws = 0, avgSigStrAcc = 0, avgSigStrDef = 0, avgTdAcc = 0,
    avgTdDef = 0, avgHeight = 0, avgWeight = 0, avgSigStrPerMin = 0, avgSigStrAbsPerMin = 0,
    avgTdLandedPer15 = 0, avgSubAttemptsPer15 = 0;
    //if the vector has data
    if (fighters.size() != 0) {
        //loop through each record,
        //if the datapoint is valid - increment datapoint counter and
        //add the value of each field to its respective total variable
        //otherwise move on to the next field
        for (int i = 0; i < fighters.size(); i++) {
            if (fighters[i].getWins()!=-1) {
                totalWins+=fighters[i].getWins();
                datapointWins++;
            }
            if (fighters[i].getLosses()!=-1) {
                totalLosses+=fighters[i].getLosses();
                datapointLosses++;
            }
            if (fighters[i].getDraws()!=-1) {
                totalDraws+=fighters[i].getDraws();
                datapointDraws++;
            }
            if (fighters[i].getSigStrAcc()!=-1) {
                totalSigStrAcc+=fighters[i].getSigStrAcc();
                datapointSigStrAcc++;
            }
            if (fighters[i].getSigStrDef()!=-1) {
                totalSigStrDef+=fighters[i].getSigStrDef();
                datapointSigStrDef++;
            }
            if (fighters[i].getTdAcc()!=-1) {
                totalTdAcc+=fighters[i].getTdAcc();
                datapointTdAcc++;
            }
            if (fighters[i].getTdDef()!=-1) {
                totalTdDef+=fighters[i].getTdDef();
                datapointTdDef++;
            }
            if (fighters[i].getHeight()!=-1) {
                totalHeight+=fighters[i].getHeight();
                datapointHeight++;
            }
            if (fighters[i].getWeight()!=-1) {
                totalWeight+=fighters[i].getWeight();
                datapointWeight++;
            }
            if (fighters[i].getSigStrPerMin()!=-1) {
                totalsigStrPerMin+=fighters[i].getSigStrPerMin();
                datapointsigStrPerMin++;
            }
            if (fighters[i].getSigStrAbsPerMin()!=-1) {
                totalSigStrAbsPerMin+=fighters[i].getSigStrAbsPerMin();
                datapointSigStrAbsPerMin++;
            }
            if (fighters[i].getTdAcc()!=-1) {
                totalTdLandedPer15+=fighters[i].getTdLandedPer15();
                datapointTdLandedPer15++;
            }
            if (fighters[i].getTdDef()!=-1) {
                totalSubAttemptsPer15+=fighters[i].getAvgSubAttemptsPer15();
                datapointSubAttemptsPer15++;
            }
        }
        // calculate all averages and set name
        string name = "Average";
        avgWins = totalWins/datapointWins;
        avgLosses = totalLosses/datapointLosses;
        avgDraws = totalDraws/datapointDraws;
        avgSigStrAcc = totalSigStrAcc/datapointSigStrAcc;
        avgSigStrDef = totalSigStrDef/datapointSigStrDef;
        avgTdAcc = totalTdAcc/datapointTdAcc;
        avgTdDef = totalTdDef/datapointTdDef;
        avgHeight = totalHeight/datapointHeight;
        avgWeight = totalWeight/datapointWeight;
        avgSigStrPerMin = totalsigStrPerMin/datapointsigStrPerMin;
        avgSigStrAbsPerMin = totalSigStrAbsPerMin/datapointSigStrAbsPerMin;
        avgTdLandedPer15 = totalTdLandedPer15/datapointTdLandedPer15;
        avgSubAttemptsPer15 = totalSubAttemptsPer15/datapointSubAttemptsPer15;

        //push averages to the vector and return true to indicate success
        fighters.push_back(Fighter(name, avgWins, avgLosses, avgDraws, avgSigStrAcc, avgSigStrDef,
            avgTdAcc, avgTdDef, avgHeight, avgWeight, avgSigStrPerMin, avgSigStrAbsPerMin,
            avgTdLandedPer15, avgSubAttemptsPer15));
        return true;

    }
    cout << "Vector is empty - unable to calculate averages" << endl;
    return false;
}
