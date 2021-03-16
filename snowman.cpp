#include "snowman.hpp"
#include <string>
#include <exception>
#include <stdexcept>
#include <array>
using namespace std;


string ariel::snowman(int format){
    string topHat;
    string hat;
    string nose;
    string leftEye;
    string rightEye;
    string rightArm;
    string leftArm;
    string torso;
    string base;
    const size_t slots = 8;
    array<int, slots> props = {0,0,0,0,0,0,0,0};
    int tmp1 = format;
    int counter = 0;
    int digit = 0;
    const int hatDigit = 0;
    const int noteDigit = 1;
    const int leftEyeDigit = 2;
    const int rightEyeDigit = 3;
    const int leftArmDigit = 4;
    const int rightArmDigit = 5;
    const int torsoDigit = 6;
    const int legsDigit = 7;
    const int length = 8; 
    const int dividingBy = 10;
    const int lengthProps = 8;

    while(tmp1 > 0){
        digit = tmp1%dividingBy;
        tmp1 /= dividingBy;
        counter++;
        if(digit < 1){
            string strFormat = to_string(format);
            throw invalid_argument{"Invalid code " + strFormat};
        }

        if(digit > 4){
            string strFormat = to_string(format);
            throw invalid_argument{"Invalid code " + strFormat};
        }
    }

    if(counter != length){
        string strFormat = to_string(format);
        throw invalid_argument{"Invalid code " + strFormat};

    }
    

    for(int i = length-1; 0 <= i; i--){
        props.at(i) = format % dividingBy;
        format /= dividingBy; 
    }

    for(int j = 0; j < lengthProps ; j++){

        switch(j){
            case hatDigit:
                if(props[hatDigit] == 1){
                    hat += "\n_===_\n";
                } 

                else if(props[hatDigit] == 2){
                    topHat += "\n  ___\n";
                    hat += ".....\n";
                }

                else if(props[hatDigit] == 3){
                    topHat += "\n   _\n";
                    hat += " /_\\\n";
                }

                else if(props[hatDigit] == 4){
                    topHat += "\n ___\n";
                    hat += "(_*_)\n";
                }

                break; 

            case noteDigit:
                if(props[noteDigit] == 1){
                    nose = ",";
                } 

                else if(props[noteDigit] == 2){
                    nose = ".";
                }

                else if(props[noteDigit] == 3){
                    nose = "_";
                }

                else if(props[noteDigit] == 4){
                    nose = " ";
                    
                }
                
                break; 

            case leftEyeDigit:
                if(props[leftEyeDigit] == 1){
                    leftEye = ".";
                } 

                else if(props[leftEyeDigit] == 2){
                    leftEye = "o";
                }

                else if(props[leftEyeDigit] == 3){
                    leftEye = "O";
                }

                else if(props[leftEyeDigit] == 4){
                    leftEye = "-";
     
                }


                break;   

            case rightEyeDigit:
                if(props[rightEyeDigit] == 1){
                    rightEye = ".";
                } 

                else if(props[rightEyeDigit] == 2){
                    rightEye = "o";
                }

                else if(props[rightEyeDigit] == 3){
                    rightEye = "O";
                }

                else if(props[rightEyeDigit] == 4){
                    rightEye = "-";
                    
                }

            case leftArmDigit:
                if(props[leftArmDigit] == 1){
                    leftArm = "<";
                } 

                else if(props[leftArmDigit] == 2){
                    leftArm = "\\";
                }

                else if(props[leftArmDigit] == 3){
                    leftArm = "/";
                }

                else if(props[leftArmDigit] == 4){
                    leftArm = "";
                    
                } 

            case rightArmDigit:
                if(props[rightArmDigit] == 1){
                    rightArm = ">";
                } 

                else if(props[rightArmDigit] == 2){
                    rightArm = "/";
                }

                else if(props[rightArmDigit] == 3){
                    rightArm = "\\";
                }

                else if(props[rightArmDigit] == 4){
                    rightArm = "";
                    
                }

            case torsoDigit:
                if(props[torsoDigit] == 1){
                    torso = " : ";
                } 

                else if(props[torsoDigit] == 2){
                    torso = "] [";
                }

                else if(props[torsoDigit] == 3){
                    torso = "> <";
                }

                else if(props[torsoDigit] == 4){
                    torso = "   ";
                    
                }

            case legsDigit:
                if(props[legsDigit] == 1){
                    base = " : ";
                } 

                else if(props[legsDigit] == 2){
                    base = '"';
                }

                else if(props[legsDigit] == 3){
                    base = "___";
                }

                else if(props[legsDigit] == 4){
                    base = "   ";
                    
                }              
        }
    }

    string output;
    string secondLine;
    string thirdLine;
    string forthLine;

    if(props[leftArmDigit] == 2){
        secondLine += leftArm;
    }

    secondLine += "(" + leftEye + nose + rightEye;  
    secondLine += ")";

    if(props[rightArmDigit] == 2){
        secondLine += rightArm;
    }

    
    secondLine += "\n";
    


    if(props[leftArmDigit] != 2){
        thirdLine += leftArm;
    }

    thirdLine += "(" + torso;  
    thirdLine += ")"; 

    if(props[rightArmDigit] != 2){
        thirdLine += rightArm;
    }

    thirdLine += "\n";
    
    if(props[legsDigit] != 2){
        forthLine += "(" + base + ")\n";
    }

    else{
        forthLine += "(" + base + " " + base + ")\n";
    }

    if(props[leftArmDigit] != 4){
        topHat = "  " + topHat;
        hat = " " + hat;
        forthLine = " " + forthLine;
        
        if(props[leftArmDigit] == 2){
            thirdLine = " " + thirdLine;
        }
        if(props[leftArmDigit] != 2){
            secondLine = " " + secondLine;
        }    
    }

    output = topHat + hat + secondLine + thirdLine + forthLine +"\n"; 

    return output;    
}