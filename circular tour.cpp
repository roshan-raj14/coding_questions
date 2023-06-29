// gfg - circular tour, leetcode - gas station

/* The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
}; */

class Solution{
public:
int tour(petrolPump p[],int n)
    {
       //Your code here
       int balance = 0;
       int deficit = 0;
       int start = 0;
       
       for(int i=0; i<n; i++)
       {
           balance += p[i].petrol - p[i].distance;
           
           if(balance < 0)
           {
               deficit += abs(balance);
               balance = 0;
               start = i+1;
           }
       }
       
       if(balance >= deficit)
       return start;
       else
       return -1;
    }
};
