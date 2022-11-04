#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <cctype> //tolower(c)
#include <algorithm>
#include "funcs.h"

using std::vector;

//old

char shiftChar(char c, int rshift){
    if (isupper(c)){
        c += rshift;
        while (ispunct(c) || islower(c)){
            c-=26;
        }
    }
    else if (islower(c)){
        c += rshift;
        while (c > 122 || c < 97){
            c-=26;
        }
    }
    return c; 
}

std::string encryptCaesar(std::string plaintext, int rshift){
    std::string result;
    for (int i = 0; i < plaintext.length(); i++){
        result += shiftChar(plaintext[i], rshift); 
    }
    result += "\n";
    return result;
}

//add functions here   //also add gcovr    //distance formula try = sqrt(pow(x2 - x1)+pow(y2-y1))

bool alphabetically_order(std::string a, std::string b){
    return a < b;
}

vector<float> english(){   //based on the cornell tech aphlabet frequencies study results [in alphabetically order]
    vector<float> corn {0.082, 0.015, 0.028, 0.043, 0.13, 0.022, 0.02, 0.061, 0.07, 0.0015, 0.0077, 0.04, 0.024, 0.067, 0.075, 0.019, 0.00095, 0.06, 0.063, 0.091, 0.028, 0.0098, 0.024, 0.015, 0.02, 0.00074};
    return corn;
}

// std::vector<char> alphabetical(){
//     std::vector<char> order;  char c ='a';
//     for (int i = 0; i < 26; i++){   // sets the vector ~order~ with a-z alphabetically
//         order.insert(order.begin() +i,c);
//         c+=1;           //alphabet rotation
//         //std::cout << order.at(i); //outputs alphabet in order
//     }
//     return order;
// }

std::string every(std::string cipher){
    std::string out; static int shift = 0; 
    shift += 1;
    // for (int i = 0; i < cipher.length(); i++){
    //     out += cipher[i] + shift;
    // }
    return encryptCaesar(cipher, shift);
}

vector<float> count(std::string letter){   //counts the frequency of the ciphered characters
    std::vector<float> frq(26,0); 
    // int counter = 0;
    // frq.assign(27,0);  //assigns 27 sections within ~frq~ to 0 initially
    // for ( int y = 0; y < letter.length(); y++ ){    //looks through all of the letters in the sentence
    //     for ( int x = 0; x < letter.length(); x++){     
    //         if (letter[y] == letter[x]){        //sees how many one letter appears in the sentence
    //             counter += 1;                   //keeps count of them^
    //         }
    //     }
    //     for ( int o = 0; o < frq.size()-1; o++){    
    //         if (order.at(o) == letter[y]){      //finds where the alphabet letters matches the string letters
    //             frq.insert(frq.begin()+o,counter/letter.length());  //sets it to the frequency that corresponds with
    //             frq.erase(frq.begin()+o);
    //         }
    //         counter = 0;        //resets the counter for the next letter
    //     }
    // }
    // std::cout << letter << "\n";
    int size = letter.size();
    for(int i = 0; i < size; ++i){
        frq[letter[i]-'a']++;
    }
    for(auto &i : frq){
        i/=size;
        // std::cout << i << " ";
    }
    //std::cout << "\n";
    
    
    
    return frq;     //when done, returns the vector with frequencies in them including 0's.
}

int compare(std::vector<float> frq, std::vector<float> corn){    //compares the cipher string frq and english frq
    static double winner_winner_chicken_dinner = 100; double process = 0 ; double challenger; static int count = 1; static int solution = -1;
    //std::cout << frq.size() << ' ' << corn.size() << '\n';
    for (int i = 0; i < frq.size()-1; i++){        // looking through cipher
        //std::cout << frq.at(i) << ' ' << corn.at(i) << '\n';
        process += pow((frq.at(i)) - corn.at(i), 2);   //distance formula
    }
    challenger = sqrt(process);
    //std::cout << challenger << " " << count  << "\n";
    if (challenger < winner_winner_chicken_dinner){
        winner_winner_chicken_dinner = challenger;      //figuring out the smallest distance out of all the outcomes
        solution = count;               //should get the solution [but it doesnt T-T]
        //std::cout << "\n\n -----------> " << solution << "\n\n";
    }
    count+=1;
    return solution;        //returns the soultion
}

std::string solve(std::string encrypted_string){
    std::string clean = ""; std::string result = "";
    for (int i = 0; i < encrypted_string.length(); i++){    //cleans the encrypted string of periods and spaces
        if (isalpha(encrypted_string[i])){
            clean += tolower(encrypted_string[i]);
        }
    }

    std::string rotate; std::vector<float> frequencies; double shift;
    for ( int k = 0; k < 26; k++){          //calls the functions 25 times (b/c 26 would be itself again)
        rotate = every(clean);
        // std::cout << rotate << "\n";//each rotation
        frequencies = count(rotate);    //creates a vector of the frequencies of that rotation
        shift = compare(frequencies, english());    //compares the rotation 
    }
    //std::cout << "\n\n----------->" << shift << " SHIFT IS HEREEEE\n";

    std::string old;
    clean = encryptCaesar(encrypted_string, shift);     //decrypts it so it should show english version
    //std::cout << clean;
    
    result += clean;
    result += "Rotation Solution: " + std::to_string(int(shift)) + '\n';
    
    // std::cout << '\n' << shift << '\n';
    // std::cout << '\n' << encrypted_string << '\n';
    // std::cout << '\n' << clean << '\n';


    // for (int x = 0; x < encrypted_string.length(); x++){    //cleans the outcome back into an actual sentence
    //     if (isupper(encrypted_string[x])){
    //         result += toupper(clean[x]);
    //     }
    //     else if (isspace(encrypted_string[x])){
    //         result += ' ';
    //     }
    //     else if (ispunct(encrypted_string[x])){
    //         result += encrypted_string[x];
    //     }
    //     else{
    //         result += clean[x];
    //     }
    // }

    return result;
}

//temp main for testing

// int main(){
//     std::cout << solve(encryptCaesar("The opportunity of a lifetime passed before him as he tried to decide between a cone or a cup. Weather is not trivial - it's especially important when you're standing in it. With a single flip of the coin, his life changed forever. He had unknowingly taken up sleepwalking as a nighttime hobby She advised him to come back at once.", 1)) << std::endl;   //solution should be 10

//     return 0;
// }