/*
Andrew Ingalls
ID: 2368574
Aingalls@chapman.edu
CPSC 350-01
PA1: Robber Language Translation
*/
#include "Translator.h"

//Default constructor
Translator::Translator(){
    m_model = new Model();
}

//Destructor
Translator::~Translator(){

}

/*Takes in a word as a string and iterates through the word and checks each character in the word.
the if statement checks to see if it is a vowel or if its punctuation, if so it adds the translated
character to a empty string which will then output our translated word. If not, it translates 
it as a consonant*/
string Translator::translateEnglishWord(string word){
    string translatedWord = "";
    for (int i = 0; i < word.length(); i++){
        if (m_model->isVowel(word[i]) || m_model->isPunctuation(word[i])){
            translatedWord += m_model->translateSingleVowel(word[i]);
        }
        else{
            translatedWord += m_model->translateSingleConsonant(word[i]);
        }
    }
    return translatedWord;
}

/*takes in a sentence as a string and iterates through the string. The word to translate is 
added to the word variable. If the string contains a space or a null character, we know it 
is at the end of the word so it translates the word and adds it to the translated sentence.
The word variable is then reset so it can take in a new word. The translated sentence is then returned*/
string Translator::translateEnglishSentence(string sentence){
    string translatedSentence = "";
    int startingIndex = 0;
    string word = "";
    for (int i = 0; i < sentence.length(); i++){
        word += sentence[i];
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            translatedSentence += this->translateEnglishWord(word);
            word = "";
        }
    }
    translatedSentence += this->translateEnglishWord(word);
    return translatedSentence;
}