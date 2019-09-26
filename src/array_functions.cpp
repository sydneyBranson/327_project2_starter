/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author:SydBranson
 */

//============================================================================
//	TODO add necessary includes here
//============================================================================
#include <string>
#include <iostream>
#include <sstream>
#include <array>
#include <string.h>
#include <fstream>
#include <algorithm>
#include "constants.h"
#include "utilities.h"
#include "array_functions.h"
using namespace constants;
using namespace std;
//============================================================================
//	stuff you will need
//============================================================================
int nextWord=0;
struct entry{
	string word;
	int number_occurances;
};

entry myArray[MAX_WORDS];//check if this needs to be here now


int CompareTo(entry word1, entry word2){
return word1.word.compare(word2.word);
}

void clearArray(){
int nextWord=0;
}
//how many unique words are in array
int getArraySize(){
return nextWord;
}
//get data at a particular location
std::string getArrayWordAt(int i){
	return myArray[i].word;
}

int getArrayWord_NumbOccur_At(int i){
	return myArray[i].number_occurances;
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::fstream &myfstream){
	if(myfstream.is_open()){
		std::string hold;//holds woreds in string
		while(getline(myfstream, hold)){
			processLine(hold);
		}
		return true;
	}
	else{
		return false;
	}
}

/*take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
void processLine(std::string &myString){
	std::stringstream stringstream(myString);
	std::string hold;
	while(getline(stringstream, hold, ' ')){
		processToken(hold);
	}
	}


/*Keep track of how many times each token seen*/
void processToken(std::string &token){
	strip_unwanted_chars(token);

	for(int i=0; i<getArraySize();i++){
		string stringA= token;
		string stringB=myArray[i].word;
		toUpper(stringA);
		toUpper(stringB);

		if(stringA==stringB){
			myArray[i].number_occurances+=1;
			return;
		}

	}
	if(token.length()!=0){
		myArray[nextWord]=entry();
		myArray[nextWord].word=token;
		myArray[nextWord].number_occurances=1;
		nextWord+=1;
	}
	}


/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(std::fstream& myfile, const std::string& myFileName, std::ios_base::openmode mode){
	myfile.open(myFileName.c_str(), mode);
		return  myfile.is_open();
}

/*if myfile is open then close it*/
void closeFile(std::fstream& myfile){
	if(myfile.is_open()){
		myfile.close();
		}
	}

/* serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writeArraytoFile(const std::string &outputfilename){
	ofstream out;
	out.open(outputfilename.c_str());//might be problem

		if(!out.is_open()){
			return constants::FAIL_FILE_DID_NOT_OPEN;
		}
		if(nextWord==0){
			return constants::FAIL_NO_ARRAY_DATA;
		}
		else
		for(int i = 0;i<nextWord;i++){
			out << myArray[i].word + " " + intToString(myArray[i].number_occurances) + "\n";//might be the intToString, jsut be myArray...

		}
		out.close();
				return constants::SUCCESS;
}

/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so){

switch(so){
 case constants::ASCENDING://this should work now
 		//sort(myArray,(myArray+nextWordspot), CompareTo);

 		for(int i=0;i<nextWord;i++){
 				for(int j=i+1;j<nextWord;j++){
 					string a = myArray[i].word;
 					string b = myArray[j].word;

 					toUpper(a);
 					toUpper(b);

 					if(a > b){

 						entry temp =myArray[i];
 						myArray[i]=myArray[j];
 						myArray[j]=temp;
 					}
 				}

 		}
 		break;
 	case constants::NONE:
 		break;
 	case constants::DESCENDING:
 		break;
 	case constants::NUMBER_OCCURRENCES:
 		break;
	}
 }



