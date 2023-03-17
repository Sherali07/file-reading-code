#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    int noc=0, now=0, nol=0, nop=0, ndw=0,nod=0;
    char fname[20], ch;
    string punctuations = ",.?!";
    string word = "";
    string words[10000]; // array to store words
    int word_count[10000] = {0}; // array to store word count
    int i, j, k;
    
    cout << "\n Enter Source File Name : ";
    cin.getline(fname, 20);
   
    ifstream file(fname);
    if (!file.is_open())
    {
        cout << "\n Invalid File Name. \n No such File or Directory ";
        exit(0);
    }

    clock_t start_time = clock(); 

    i = 0;
    while (file.get(ch))
    {
        noc++;

        if (ch == ' ')
        {
            now++;
            words[i] = word; // add word to array
            word = "";
            i++;
        }
        else
        {
            word += ch;
        }

        if (ch == '\n')
        {
            nol++;
            now++;
            words[i] = word; // add word to array
            word = "";
            i++;
        }

        if (ch=='.'||ch==','||ch=='!'||ch=='?'||ch==';'||ch==':')
        {
            nop++;
            words[i] = word; // add word to array
            word = "";
            i++;
        }
    }

    // check for last word
    if (!word.empty())
    {
        now++;
        words[i] = word; // add word to array
    }
    if (isdigit(ch))
    {
    	nod++;
	}

   

    // count number of duplicate words
    for (j = 0; j < i; j++)
    {
        if (word_count[j] == -1) // word already counted as duplicate
            continue;

        for (k = j + 1; k < i; k++)
        {
            if (word_count[k] == -1) // word already counted as duplicate
                continue;

            if (words[j] == words[k])
            {
                ndw++;
                word_count[j] = -1; // mark word as counted
                word_count[k] = -1; // mark word as counted
            }
        }
    }
     file.close();

    clock_t end_time = clock(); 

    double execution_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << " -------------------------------------";
    cout << "\n Total No. of Characters  : " << noc;
    cout << "\n Total No. of Words       : " << now;
    cout << "\n Total No. of Lines       : " << nol;
    cout << "\n Total No. of Punctuations: " << nop;
    cout << "\n Total No. of digits: "<<nod;
    cout << "\n Total No. of Duplicate Words: " << ndw;
    
    cout << "\n Execution Time           : " << execution_time << " seconds";

    return 0;
}

