new_Fibonacci<-function(a,b,A,B,n)   # Conditional Fibonacci Function 
    {
    if(n==0)
        return(a)
    if(n==1)
        return(b)
    return(A*new_Fibonacci(a,b,A,B,n-1)+B*new_Fibonacci(a,b,A,B,n-2))  #recursion call 
    }
 
Function_Writer_into_CSV<-function(n,k=5,a=2,b=3,A=10,B=2)  #Here k bydefault is 6 and it will store K(n) to k fibonacci numeber into CSV file
    {
    new_data<-c()  #new_data is list for storing the K(n) to K(k)
    for(i in k:n)
        {
        K=new_Fibonacci(a,b,A,B,i)    # invoke the new_Fibonacci for generating the conditional Fibonacci number
                                               # also passing the defauld value of a,b,Alfa,Beta
        new_data<-c(new_data,K)
        }
    filename<-toString(Sys.Date())   # take system date and convert into string 
    write.csv(new_data,filename)  #for writing data in CSV file 
    newdata <- read.csv(filename)   #just for show data that are written in CSV file
     print(newdata)               #remove comment to check the activity in CSV file 
    }
Function_Writer_into_CSV(10)
    
      
