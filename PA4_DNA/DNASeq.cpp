/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA4: Genetic Palindromes
*/
#include "DNASeq.h"

//Default constructor
DNASeq::DNASeq(){
}

//Destructor
DNASeq::~DNASeq(){
}

//Constructor that takes a string as a parameter and if each character in the string is valid
//Then it adds it to the m_data linked list. Then it prints the list.
DNASeq::DNASeq(string data){
    DNASeq();
    m_data = new DblList<char>();
    for(char c : data){
        if(c == 'A' || c == 'C' || c == 'G' || c == 'T'){
            m_data->addBack(c);
        }
        else{
            cout << "Invalid character in DNA sequence" << endl;
            break;
        }
    }
    m_data->printList();
}

//Constructor that takes a DblList<char>* as a parameter and sets m_data to that list
DNASeq::DNASeq(DblList<char>* data) {
    DNASeq();
    m_data = data;
}

//Returns a DNASeq object that is the compliment of the DNASeq object that called it
//Loops through the m_data list and adds the compliment of each character to a new list called complimentData
DNASeq DNASeq::compliment(){
    DblList<char>* complimentData = new DblList<char>();
    for (int i = 0; i < m_data->getSize(); ++i){
        if(m_data->get(i) == 'A'){
            complimentData->addBack('T');
        }
        else if(m_data->get(i) == 'T'){
            complimentData->addBack('A');
        }
        else if(m_data->get(i) == 'C'){
            complimentData->addBack('G');
        }
        else if(m_data->get(i) == 'G'){
            complimentData->addBack('C');
        }
    }
    return (*new DNASeq(complimentData));
}

//Returns a DNASeq object that is a substring of the DNASeq object that called it
//Loops through the m_data list and adds each character to a new list called substringData
//The size depends on the integer parameters s and e
DNASeq DNASeq::substring(int s, int e){
    DblList<char>* substringData = new DblList<char>();
    for (int i = s; i < e; ++i){
        substringData->addBack(m_data->get(i));
    }
    return (*new DNASeq(substringData));
}

//Returns true if the DNASeq is a genetic palindrome
//Takes the original sequence and takes the compliment.
//It loops through the whole sequence. If the starting character of original string is the 
//same as the last character in compliment, and so on through the whole sequence, 
//then it is a genetic palindrome.
bool DNASeq::isGeneticPalindrome(DNASeq* dnaSeq){
    int s = dnaSeq->m_data->getSize()-1;
    DNASeq compliment = dnaSeq->compliment();

    for (int i = 0; i < dnaSeq->m_data->getSize(); ++i){
        if(dnaSeq->m_data->get(i) != compliment.m_data->get(s-i)){
            return false;
        }
    }
    return true;
}

//Finds all the substrings in the original sequence that are genetic palindromes
void DNASeq::findSubs(){
    int seqLength = m_data->getSize();
    
    for (int length = 5; length <= seqLength; ++length) { // Check for substrings of length 5 and greater
        for (int start = 0; start < seqLength - length; ++start) {
            DNASeq* subsequence = new DNASeq(substring(start, start + length));
            //If the subsequence is a palindrome, it prints it
            if (subsequence->isGeneticPalindrome(subsequence)) {
                cout << "Substring ";
                subsequence->m_data->printList();
                cout << " is a genetic palindrome!" << endl;
            }
            //realocating memory
            delete subsequence;
        }
    }
}