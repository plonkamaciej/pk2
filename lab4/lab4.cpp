
#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;




class walidator {

public:

    string dane;
    virtual bool walidacja() {
        return true;
    }
};

class telefonkom : walidator {
public:
   
    bool is_valid_number(const std::string& dane)
    {
        static const std::string AllowedChars = "0123456789";
        for (auto numberChar = dane.begin();
            numberChar != dane.end(); ++numberChar)

            if (AllowedChars.end() == std::find(
                AllowedChars.begin(), AllowedChars.end(), *numberChar))
            {
                return false;
            }

        return true;
    }

    bool walidacja() {
        return is_valid_number(dane) && dane.size() == 9;
    }

telefonkom(string mnumer) {
    dane = mnumer;
}
};

class kwota : walidator {
public:
    bool walidacja() {
        if (stoi(dane) > 0) {
            return true;
        }
        else return false;
    }

    kwota(string mnumer) {
        dane = mnumer;
    };
};

class email : walidator {
public:

    bool walidacja()
    {
        
        const regex pattern
        ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

        return regex_match(dane, pattern);
    }
    email(string mnumer) {
        dane = mnumer;
    };

    email(string mnumer) {
        dane = mnumer;
    };
};

class telefonstat : walidator {
public:
    bool is_valid_number(const std::string& dane)
    {
        static const std::string AllowedChars = "0123456789";
        for (auto numberChar = dane.begin();
            numberChar != dane.end(); ++numberChar)

            if (AllowedChars.end() == std::find(
                AllowedChars.begin(), AllowedChars.end(), *numberChar))
            {
                return false;
            }

        return true;
    }

    bool walidacja() {
        return is_valid_number(dane) && dane.size() == 11;
    }
};

class liczba_rzymska: walidator {
public:
    bool is_valid_number(const std::string& dane)
    {
        static const std::string AllowedChars = "IVXCMD";
        for (auto numberChar = dane.begin();
            numberChar != dane.end(); ++numberChar)

            if (AllowedChars.end() == std::find(
                AllowedChars.begin(), AllowedChars.end(), *numberChar))
            {
                return false;
            }

        return true;
    }

    bool walidacja() {
        return is_valid_number(dane);
    }
};

int main()
{
    
    telefonkom n1("000111222");
    if (n1.walidacja()) cout << "numer poprawny" << endl;
    email email1("siema@siema.com");
    if (email1.walidacja()) cout << "email poprawny" << endl;

}

