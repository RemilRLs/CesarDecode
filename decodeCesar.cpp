#include <iostream>
#include <sstream>

bool userInputVerif(std::string userInput);
std::string askUserString(std::string userInput);
std::string stringDecodeCesar(std::string inputUserValidate, int shift);
int checkAnswerBruteForce(char inputUser);
void CesarBruteforce(std::string inputUserValidate);



std::string askUserString(std::string userInput){ // On demande à l'utilisateur un input.


    std::cout << "[*] - Please give a string : ";
    std::getline(std::cin, userInput); // On utilise getline car cela nous permet de prendre de grande phrase avec des espaces.

    bool verif = userInputVerif(userInput);

    if(!verif){
        std::cout << "[X] - Error coming from your string." << std::endl;
        return "NULL";
    }

    else{
        std::cout << "[*] - String Validate." << std::endl;
        int lenInputUser = userInput.size();
        for(int i = 0 ; i < lenInputUser ; i++){

            userInput[i] = toupper(userInput[i]); // On met tout en majuscule.

        }
        return userInput;
    }

}

bool userInputVerif(std::string userInputToVerif){ // On vérifie l'input de l'utilisateur.

    int lenInputUser = userInputToVerif.size();


    for(int i = 0 ; i < lenInputUser ; i++){


        //std::cout << userInputToVerif[i] << std::endl;

        if((int)userInputToVerif[i] >= 65 && (int)userInputToVerif[i] <= 90 || (int)userInputToVerif[i] >= 97 && (int)userInputToVerif[i] <= 122 || userInputToVerif[i] == ' '){
            

            if(i == lenInputUser - 1){ // On a parcouru toute la string.
                return 1; // On valide la string.
            }
        
        }

        else{
            return 0; // La string n'est pas valide.

        }
    }


    return 0;
}


int checkAnswerBruteForceAndExecute(char inputUser){
    
    if(inputUser == 'Y'){
        std::cout << "[*] - You choose BruteForce" << std::endl;
        return 1;
    }
    
    else if(inputUser == 'N'){
        std::cout << "[*] - Request in progress for the shift..." << std::endl;

        return 0; // On demande tout de même un shift.
    }
    
    else{
        std::cout << "[*] - Your input is not valid." << std::endl;

        return 0; // On demande tout de même un shift.
    }
}


void CesarBruteforce(std::string inputUserValidate){

    std::string outputString;
    int lenInputUser = inputUserValidate.size();
    const int shift = 25;



    for(int i = 1 ; i <= shift ; i++){
        for(int j = 0 ; j < lenInputUser  ; j++){

            if((int)inputUserValidate[j] - i < 65){


                if(inputUserValidate[j] == ' '){
                    outputString[j] = ' ';
                }

                else{
                    int offset = (int)inputUserValidate[j] - i;
                    offset = 65 - offset;

                    outputString[j] = 90 - offset + 1;
                }
            }

            else{
                outputString[j] = (int)inputUserValidate[j] - i;

                
            }

            std::cout << outputString[j];

        }
        std::cout << "\n";
    }

    std::cout << "[*] - Bruteforce done." << std::endl;
}

std::string stringDecodeCesar(std::string inputUserValidate, int shift){

    int lenInputUser = inputUserValidate.size();

    std::string outputString;

    for(int i = 0 ; i < lenInputUser ; i++){

        if((int)inputUserValidate[i] - shift < 65){ // On vérifie si on ne sort pas de l'alphabet.

            if(inputUserValidate[i] == ' '){ // On vérifie si cela est un espace.
                outputString[i] = ' ';
            }

            else{
                int offset = (int)inputUserValidate[i] - shift; // On vérifie le décalage que l'on a eu en dehors de l'alphabet (ASCII).
                offset = 65 - offset;

                outputString[i] = 90 - offset + 1; // On se remet au début du Z. La boucle est bouclée.

            }

        }
        else{

            outputString[i] = (int)inputUserValidate[i] - shift;
        }

        std::cout << outputString[i];
    }
}



int main(){

    std::string userInput;
    char bruteForce;
    int shift; 

    std::string userInputValidate = askUserString(userInput); // Something stupid.

    if(userInputValidate == "NULL"){
        std::cout << "[X] - Retry." << std::endl;
        // break;
    }
    else{
        std::cout << "[*] - Do you want to BruteForce the sentence ? (Y) - Yes / (N) - No" << std::endl;
        std::cin >> bruteForce;

        if(checkAnswerBruteForceAndExecute(bruteForce)){ // On vérifie si l'utilisateur a activé le bruteforce.
            CesarBruteforce(userInputValidate);
        } 

        else{
            std::cout << "[*] - How many shift do you want ? " << std::endl;
            std::cin >> shift;
        
            stringDecodeCesar(userInputValidate, shift); // Decode.
        }
        
       
        
    }


    return 0;
}