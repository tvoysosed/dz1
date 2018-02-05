#include <iostream>
#include <cstring>

using namespace std;

int main(int argc,char*argv[]) 
{
char op[10];
int chisla[20], pozu[20], pozd[20], pozs[20], pozv[20];	
int j = 0, umn = 0, del = 0, slo = 0, vych = 0, res = 0, k = 0, l = 0, m = 0, n = 0, count1 = 0;
int countop = 0, countn = 0;
bool fl1 = false;
for(int i = 0; i < strlen(argv[1]); i++)
   {
   if((argv[1][i] == '+') || (argv[1][i] == '-') || (argv[1][i] == '*') || (argv[1][i] == '/'))
      {
      op[countop] = argv[1][i];
      countop++;
      if (argv[1][i] == '+')
         {
         slo++;
         }
      if (argv[1][i] == '-')
         {
         vych++;
         }
      if (argv[1][i] == '*')
         {
         umn++;
         }
      if (argv[1][i] == '-')
         {
         del++;
         }
      }
   }
for (int i = 0; i < strlen(argv[1]); i++)
   {
   if((argv[1][i] != '+') && (argv[1][i] != '-') && (argv[1][i] != '*') && (argv[1][i] != '/'))
      {
      if (fl1 == false)
         {
         chisla[countn] = argv[1][i] - 48;
         }
      else
         {
         chisla[countn] = chisla[countn] * 10 + argv[1][i] - 48;
         }
      if((argv[1][i + 1] == '+') || (argv[1][i + 1] == '-') || (argv[1][i + 1] == '*') || (argv[1][i + 1] == '/'))
         {
         countn++;
         fl1 = false;
         }
      else
         {
         fl1 = true;
         }
      }
   }
countn++;
for (int i = 0; i < strlen(op); i++)
   {
   if (op[i] == '*')
      {
      count1++;
      chisla[i] = chisla[i] * chisla[i + 1];
      for (int j = i + 1; j < countn - 1; j++)
         {
         chisla[j] = chisla[j + 1];
         }
      for (int j = countn - count1 ; j < countn; j++)
         {
         chisla[j] = 0;
         }
      for (int j = i; j < strlen(op) - count1; j++)
         {
         op[j] = op[j + 1];
         }
      op[strlen(op) - count1] = '0';
      }
   if (op[i] == '/')
      {
      count1++;
      chisla[i] = chisla[i] / chisla[i + 1];
      for (int j = i + 1; j < countn - 1; j++)
         {
         chisla[j] = chisla[j + 1];
         }
      for (int j = countn - count1 ; j < countn; j++)
         {
         chisla[j] = 0;
         }
      for (int j = i; j < strlen(op) - count1; j++)
         {
         op[j] = op[j + 1];
         }
      op[strlen(op) - count1] = '0';
      }
   }
for (int i = 0; i < strlen(op); i++)
   {
   if (op[i] == '+')
      {
      count1++;
      chisla[i] = chisla[i] + chisla[i + 1];
      for (int j = i + 1; j < countn - 1; j++)
         {
         chisla[j] = chisla[j + 1];
         }
      for (int j = countn - count1 ; j < countn; j++)
         {
         chisla[j] = 0;
         }
      for (int j = i; j < strlen(op) - count1; j++)
         {
         op[j] = op[j + 1];
         }
      op[strlen(op) - count1] = '0';
      }
   if (op[i] == '-')
      {
      count1++;
      chisla[i] = chisla[i] - chisla[i + 1];
      for (int j = i + 1; j < countn - 1; j++)
         {
         chisla[j] = chisla[j + 1];
         }
      for (int j = countn - count1 ; j < countn; j++)
         {
         chisla[j] = 0;
         }
      for (int j = i; j < strlen(op) - count1; j++)
         {
         op[j] = op[j + 1];
         }
      op[strlen(op) - count1] = '0';
      }
   }
for (int i = 0; i < countn; i++)
   {
   res += chisla[i];
   }
cout << endl;
cout << "Result: " << res << endl;
}
