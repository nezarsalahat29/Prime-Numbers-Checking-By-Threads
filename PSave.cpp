//Nezar Al-Salahat 132827
//Raghad Ghalib 137144  
#include "bits/stdc++.h"
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <mutex>
using namespace std;




// Global Variables
int T;
int r0,r1;
int NumPrime = 0, TotalNum = 0;
vector <int> primeList;
mutex lock1;

//Check if prime
bool isPrime(int x){
    for(int i=2;i<x;i++)
    {
        if(x%i==0)return false;
    }
    return true;
}

struct th
{
int ID,r0,r1;
} ;

//Prime Threading Function
void *Prime(void* Input)
{
    th* n = (th*) Input;
    int s0,s1;
    s0=n->r0;
    s1=n->r1;
    lock1.lock();
    if(n->ID<(r1-r0))
    cout<<"ThreadID="<<n->ID<<", startNum="<<n->r0<<", endNum="<<n->r1<<endl;
    else
    cout<<"ThreadID="<<n->ID<<" No Need"<<endl;
    for (int i=s0;i<s1;i++){
        TotalNum++;

            if(isPrime(i)){
                NumPrime++;
                primeList.push_back(i);


    }
    }
    lock1.unlock();
    pthread_exit(NULL);

}



void write(string s) {
        fstream file;
        file.open("out.txt", ios_base::app);
        file << s << endl;
        file.close();
}

//Main Function
int main(int argc, char* argv[])
{



    fstream file;
    file.open("out.txt",ios::out);
    file.close();
    file.open("in.txt");


    //reading t from Argv (passed in the command line)
    if(argv[1] !=NULL)
            T= atoi(argv[1]) ;
        else T=1;
            cout<<T<<endl;

    if (!file)
            cout << "no file with this name" << endl;
        else
        {
            file >> r0 >>r1;
        }
        file.close();
    primeList.reserve(r1-r0);// for free space




    int stepSize = floor((r1 - r0)/T);
    int RSteps = ((r1 - r0) % T);
    int SR = r0;
    int ER = SR + stepSize;

    th tInput[T]; // for passing to thread

    pthread_t threads[T];    //allocating array of type pthread
    int ef; // for exit
    for (int i = 0; i < T; i++)        //a loop that executes t times
    {
        if(RSteps){
            ER++;
            RSteps--;
        }
        // create thread number i ;

        tInput[i].ID = i;
        tInput[i].r0 = SR;
        tInput[i].r1 = ER;
        //int rc = pthread_create(&threads[i], NULL,Worker,&tInput[i]);
        ef = pthread_create(&threads[i], NULL, Prime, &tInput[i]); //creating threads which execute the function "multi" and passing thread number (id) to the function
        if (ef)  //Errors Handling
        {
            printf("\n\n A problem has occured \n\n");
            exit(-1);
        }
        // make start and end for next thread
        SR = ER;
        ER = ER + stepSize;
    }
    for (int i = 0; i < T; i++)  //JOIN
    {
        pthread_join(threads[i], NULL);
    }





    cout<<"numOfPrime="<<NumPrime<<", totalNums="<<TotalNum<<endl;
    //fprintf(wfptr, "numOfEven= %d, numOfOdd=%d, totalCells=%d \n\n", Even, Odd, Total);

    for(auto i=primeList.begin();i!=primeList.end();i++){
        write(to_string(*i));
    }
    //fclose(tfptr);
  //to exit the main thread
    return 0;
}
