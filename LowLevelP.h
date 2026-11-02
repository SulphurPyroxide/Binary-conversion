#include <bitset>
///------------------------------------------------------------------------------------------------------------------
/// Returns data in various types converted to a binary string through ascii conversion in decimal format.
///
/// Supported datatypes
///------------------------------------------------------------------------------------------------------------------
///     > int
///     > string
///     > char
std::string getBinStr(std::string str){
    std::string toBin;
    for (char c : str){
        toBin += std::bitset<8> (c).to_string();
    }

    return toBin;
}

std::string getBinStr(int x){

    if (x == 0){
        return "00000000";
    }

    std::string toBin;

    while (x > 0){
        if (x % 2 == 1){
            toBin += '1';
        }
        else{
            toBin += '0';
        }

        x /= 2;
    }

    while (toBin.length() % 8 != 0){ ///keeping it to an 8 bit format for compatibility reasons.
        toBin += '0';
    }
    std::reverse(toBin.begin(),toBin.end());
    return toBin;
}

std::string getBinStr(char c){
    std::string toBin = std::bitset<8> (c).to_string();
    return toBin;
}

/// Converts a given binary string into a string
std::string convBin_str(std::string binStr){
    std::reverse(binStr.begin(),binStr.end());
    std::string convStr;
    int binMult = 1;
    int AsciiChar = 0;
    for (int i = 0; i < binStr.length() ; i++){
        if (binStr[i] == '1'){
            AsciiChar += (1 * binMult);
        }

        binMult *= 2;

        if ((i + 1) % 8 == 0){
            convStr += (char)AsciiChar;
            AsciiChar = 0;
            binMult = 1;
        }
    }
    std::reverse(convStr.begin(),convStr.end());
    return convStr;
}

/// Converts a given binary string into integer
int convBin_int(std::string binStr){
    std::reverse(binStr.begin(), binStr.end());

    int convInt = 0;
    int binMult = 1;

    for (int i = 0; i < binStr.length(); i++){
        if (binStr[i] == '1'){
            convInt += (1 * binMult);
        }

        binMult *= 2;
    }

    return convInt;
}