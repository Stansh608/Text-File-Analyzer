
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

//declaring functions
void readFile();
void Count(string word,int &LCaseCount,int &UCaseCount,int &punctuationCount,int frequency[]);
void lettersFrequency(char chr,int frequency[]);
void dispResults(int UCaseCount,int LCaseCount,int spaceCount,int punctuationCount,int wordCount,int frequency[]);
int main() {
  
//function readFile call
readFile();  

return 0;
}
//non return-value function to read file
void readFile()
{
int UCaseCount=0,LCaseCount=0,punctuationCount=0,wordCount=0,spaceCount=0;
int frequency[26]={0};
string word;
//defining the input string 
ifstream inFile;

//opening the txt file from the computer to analyze it
inFile.open("myfile.txt");
while(inFile>>word)
{
   wordCount++;
   spaceCount++;
   Count(word,LCaseCount,UCaseCount,punctuationCount,frequency);
}
  
//Closing the file
inFile.close();
  
  //to display results
   dispResults(UCaseCount,LCaseCount,spaceCount-1,punctuationCount,wordCount,frequency);
}
//The function that counts the  number of uppre and lower case letters and punctuation marks
void Count(string word,int &LCaseCount,int &UCaseCount,int &punctuationCount,int frequency[])
{
   char ch;
   for(int a=0;a<word.length();a++)
   {
       ch=word.at(a);
      
        if(ch=='"')
       {
           punctuationCount++;
       }
       if(islower(ch))
       {
           UCaseCount++;
           lettersFrequency(ch,frequency);
       }
       if(isupper(ch))
       {
           lettersFrequency(ch+32,frequency);
           UCaseCount++;
       }
      
      
   }
}
void lettersFrequency(char ch,int frequency[])
{
   frequency[((int) (ch) - 97)]++;
}
//displaying the output to console
void dispResults(int UCaseCount,int LCaseCount,int spaceCount,int punctuationCount,int wordCount,int frequency[])
{
  
  
   cout<<endl;
   char ch=97;
   //Looping around the Characters : a/A to z/Z counting each occurrence.
   for(int i=0;i<26;i++)
   {
       cout<<ch<<"/"<<(char)(ch-32)<<":"<<frequency[i]<<endl;
       ch++;
   }
   //Listing down the totals
   cout<<"Total upper case letters :"<<UCaseCount<<endl;
   cout<<"Total lower case letters :"<<LCaseCount<<endl;
   cout<<"Total number of  spaces :"<<spaceCount<<endl;
   cout<<"Total number of punctuation marks :"<<punctuationCount<<endl;
   cout<<"Total number of words in text:"<<wordCount<<endl;
}