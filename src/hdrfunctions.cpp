#include "hdrfunctions.h"
#include <iostream>
#include <vector>

#include <ctype.h>
#include <stdlib.h>
#include <assert.h>


#ifdef NDEBUG
#define Assert(expr) ((void)0)
#else
#define Assert(expr) \
    ((expr) ? (void)0 : \
        printf("Assertion \"%s\" failed in %s, line %d", \
               #expr, __FILE__, __LINE__))
#endif // NDEBUG

void openhdr(std::string fname)
{
	
	std::vector<float> *values = new std::vector<float>();

	FILE *f = fopen(fname.c_str(), "r");
    if (!f) 
	{
        std::cout << "Unable to open file";
        return;
	}

    int c;
    bool inNumber = false;
    char curNumber[32];
    int curNumberPos = 0;
    int lineNumber = 1;
    while ((c = getc(f)) != EOF) 
	{
		if (c == '\n') ++lineNumber;
        if (inNumber) 
		{
            if (isdigit(c) || c == '.' || c == 'e' || c == '-' || c == '+')
                curNumber[curNumberPos++] = c;
            else 
			{
                curNumber[curNumberPos++] = '\0';
                values->push_back(atof(curNumber));
                Assert(curNumberPos < (int)sizeof(curNumber));
                inNumber = false;
                curNumberPos = 0;
            }
        }
        else 
		{
            if (isdigit(c) || c == '.' || c == '-' || c == '+') 
			{
                inNumber = true;
                curNumber[curNumberPos++] = c;
            }
            else if (c == '#') 
			{
                while ((c = getc(f)) != '\n' && c != EOF)
                    ;
                ++lineNumber;
            }
            else if (!isspace(c)) 
			{
                printf("Unexpected text found at line %d of float file \"%s\"\n",
                        lineNumber, fname);
            }
        }
    }
    fclose(f);
    return;
}
