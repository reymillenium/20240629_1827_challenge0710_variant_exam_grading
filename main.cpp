/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                         *
 *   Name: Exam Grading (Chapter 7 Challenge 10 Variant; Improved Version)                 *
 *                                                                                         *
 *   Purpose:                                                                              *
 *   Receives 20 answers to the driver license exam & stores them into a vector of chars.  *
 *   Then grades those answers by comparing them with the correct ones, and finally        *
 *   displays the results, including: the total number of correctly answered questions,    *
 *   the total number of incorrectly answered questions, and a list showing all the        *
 *   answers, detailing which ones are right and which ones are wrong. Its an improved     *
 *   and refactored version, removing all the unnecessary fat, while adding extra          *
 *   useful information in the results displayed to the user.                              *
 *                                                                                         *
 *   More Details:                                                                         *
 *   https://github.com/reymillenium/20240629_1827_challenge0710_variant_exam_grading      *
 *                                                                                         *
 *   Required Statement:                                                                   *
 *   "I did not use chatGPT or any outside source to assist me with the code."             *
 *                                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/


#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>
#include <regex>


using std::cout;
using std::endl;
using std::cin;
using std::fixed;
using std::setprecision;
using std::setw;
using std::setfill;
using std::string;
using std::to_string;
using std::vector;
using std::isalpha;
using std::inner_product;


// UTILITY FUNCTIONS PROTOTYPES


// Determines if a given string is a single valid char
bool containsSingleChar(const string &);

// Receives and validates a char from the console
char getAlphaChar(const string &, const string & = "Invalid input. Please try again.");

// Returns the string gramatic representation of an ordinal number, from a given int number
string ordinalFromNumber(long long int);


// CUSTOM FUNCTIONS PROTOTYPES


// Returns all the proper answers for the driver license exam
vector<char> loadCorrect();

// Validates and returns if the given answer is among the allowed or not
bool validateAnswer(char);

// Gets all the answers from the driver
vector<char> getDriverAnswers(int);

// Counts the correct answers. Grades the user's answers comparing them with the correct ones
int gradeExam(const vector<char> &, const vector<char> &);

// Displays all the results, including the: General Score, if the user passed or not, and the Detailed Results Table
void displayResults(const vector<char> &, const vector<char> &);

// Prints a useful & detailed table, containing every answer and comparing it with the correct one.
void printDetailedResultsTable(const vector<char> &, const vector<char> &, int);


// Main Function
int main() {
    constexpr int QUESTIONS_AMOUNT = 20;
    vector<char> vCorrectAnswers(QUESTIONS_AMOUNT);
    vector<char> vDriverAnswers(QUESTIONS_AMOUNT);

    vCorrectAnswers = loadCorrect(); // Gets all the correct answers
    vDriverAnswers = getDriverAnswers(QUESTIONS_AMOUNT); // Gets the user's answers

    // Displays the Improved Results:
    displayResults(vCorrectAnswers, vDriverAnswers);

    return 0;
}


// UTILITY FUNCTIONS DEFINITIONS


bool containsSingleChar(const string &input) {
    if (input.empty() || input.length() > 1) return false;
    return true;
}

char getAlphaChar(const string &message, const string &errorMessage) {
    string characterAsString; // Value typed by the user, that can be a char or not
    char character = 'A'; // Char convertion (if possible) of the value typed by the user
    bool isNotAlphaCharacter = true; // If the character is alphabetic

    do {
        cout << message << ": ";
        getline(cin, characterAsString);

        if (!containsSingleChar(characterAsString)) {
            cout << "That's not a single character. Try again." << endl;
            continue; // There is no point in keep validating any further, as it's not even a valid single char (still as a string at this point)
        }

        // const char *characterPointer = characterAsString.data(); // Only valid on C++ 17 or newer
        const char *characterPointer = characterAsString.c_str();
        character = characterPointer[0];

        isNotAlphaCharacter = !isalpha(character);
        if (isNotAlphaCharacter) cout << errorMessage << endl;
    } while (isNotAlphaCharacter);

    return character;
}

// Returns the string gramatic representation of an ordinal number, from a given int number
string ordinalFromNumber(const long long int number) {
    const long long int lastDigit = number % 10;
    string additive;

    switch (number) {
        case 11:
        case 12:
            additive = "th";
            break;
        default:
            switch (lastDigit) {
                case 1:
                    additive = "st";
                    break;
                case 2:
                    additive = "nd";
                    break;
                case 3:
                    additive = "rd";
                    break;
                default:
                    additive = "th";
                    break;
            }
            break;
    }

    return to_string(number) + additive;
}


// CUSTOM FUNCTIONS DEFINITION


// Returns all the proper answers for the driver license exam
vector<char> loadCorrect() {
    return {
        'A', 'D', 'B', 'B', 'C',
        'B', 'A', 'B', 'C', 'D',
        'A', 'C', 'D', 'B', 'D',
        'C', 'C', 'A', 'D', 'B'
    };
}

// Validates and returns if the given answer is among the allowed or not
bool validateAnswer(const char input) {
    vector<char> allowedAnswers {'A', 'B', 'C', 'D'};
    return count(allowedAnswers.begin(), allowedAnswers.end(), input) > 0;
}

// Gets all the answers from the driver
vector<char> getDriverAnswers(const int vectorLength) {
    vector<char> vector(vectorLength);

    cout << endl;
    cout << "Welcome to Exam Grader Pro." << endl;
    cout << endl;

    for (int i = 0; i < vectorLength; i++) {
        bool isInvalidAnswer;
        do {
            vector[i] = toupper(getAlphaChar("Please type the answer for the " + ordinalFromNumber(i + 1) + " question (A, B, C, or D)"));
            isInvalidAnswer = !validateAnswer(vector[i]);
            if (isInvalidAnswer) cout << "The only allowed answers are: A, B, C or D. Try again." << endl;
        } while (isInvalidAnswer);
    }

    return vector;
}

// Counts the correct answers. Grades the user's answers comparing them with the correct ones
int gradeExam(const vector<char> &vCorrectAnswers, const vector<char> &vDriverAnswers) {
    // Compututing the cumulative inner equality of the range in those two same size vectors (when items are equal, then equal_to() returns 1, and then it's accumulated via plus<>() )
    return std::inner_product(
        vCorrectAnswers.begin(), vCorrectAnswers.end(), vDriverAnswers.begin(), 0, std::plus<>(), std::equal_to<>()
    );
}

// Displays all the results, including the: General Score, if the user passed or not, and the Detailed Results Table
void displayResults(const vector<char> &vCorrectAnswers, const vector<char> &vDriverAnswers) {
    int numCorrect = 0; // Number or correct answers
    numCorrect = gradeExam(vCorrectAnswers, vDriverAnswers); // Grades the user's answers comparing them with the correct ones
    const bool passedtheTest = numCorrect >= 15; // If the user passed the test

    cout << endl;
    cout << "Driver License Exam Official Results" << endl;
    cout << "Final Score: " << numCorrect << "/20 points." << endl;
    cout << "As a result: " << (passedtheTest ? "Congratulations! You passed " : "I'm sorry! You failed ") << "the Driver License Exam." << endl;
    cout << endl;
    cout << "Detailed Results: " << endl;
    printDetailedResultsTable(vCorrectAnswers, vDriverAnswers, numCorrect);
    cout << "Thank you for using our services. Goodbye!" << endl;
};


// Prints a useful & detailed table, containing every answer and comparing it with the correct one.
void printDetailedResultsTable(const vector<char> &vCorrectAnswers, const vector<char> &vDriverAnswers, const int correctAnswersAmount) {
    cout << "-----------------------------------------------------" << endl;
    cout << "| Question # | Your answer | Correct Answer | Score |" << endl;
    cout << "-----------------------------------------------------" << endl;

    const size_t length = vCorrectAnswers.size();
    for (int i = 0; i < length; i++) {
        const char userAnswer = vDriverAnswers[i];
        const char properAnswer = vCorrectAnswers[i];

        cout << "|     " << setfill(' ') << setw(2) << (i + 1) << "     |      " << userAnswer << "      |        " << properAnswer << "       |   " << (userAnswer == properAnswer) << "   |" << endl;
        cout << "-----------------------------------------------------" << endl;
    }

    cout << "| Final Amount of Points:                   | " << setfill(' ') << setw(3) << correctAnswersAmount << "   |" << endl;
    cout << "-----------------------------------------------------" << endl;
}
