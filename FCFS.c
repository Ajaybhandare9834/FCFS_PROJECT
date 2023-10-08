#include <stdio.h>

int func1(char array[], float quantity)//func1 is printing the ----- job name
{
    printf("job name     = "); 
    for (int j = 1; j <= quantity; j++)
    {
        printf("   %c    ", array[j]);
    }
    return 0;
}

float func2(float array[], float quantity)//func2 is printing---- job arrival time
{
    printf("arrival time = ");
    for (int j = 1; j <= quantity; j++)
    {
        printf("  %0.2f  ", array[j]);
    }
    return 0;
}

float gantt_chart_box(float quantity ,char jobname[])//func is printing---- gantt chart
{
    for (int j = 1; j <= quantity; j++)
    {
        printf("|____%c___",jobname[j]);
    }
    return 0;
}

float func3(float array[], float quantity) //func2 is printing ---job PU time
{
    printf("job AU time  = ");
    for (int j = 1; j <= quantity; j++)
    {
        printf("  %0.2f  ", array[j]);
    }
    return 0;
}
float func4(float x[], float y[]) //func4 is addition in two numbers ---- Arrival time & PU time
{
    printf("Job PU Time Addition Value\n\n");
    return x[1] + y[1];
}

float func5(float x, float y[], float quantity) //addition is frist job entery time and all job PU time
{
    float sum = x;
    for (int j = 2; j <= quantity; j++)
    {
        sum += y[j];
        printf("    %0.2f", sum);
    }

    return 0;
}
float subfunc1(float jobautime[], float jobarvltime[])//subtract in 1st job arrival time & PU time 
{
    printf("    Exite Time     -    Entry Time    =   Turn Around Time\n");
    return jobautime[1] - jobarvltime[1];
}
float subfunc2(float x, float y[], float jobarvltime[], float sub, float quantity)//subtract in exite time into Entry time ====== subtract in started 2 job to end job 
{
    float sum = x;
    float integer = 0;
    float integernew = 0;
    float div = 0;
    for (int j = 2; j <= quantity; j++)
    {
        integer = (sum += y[j]);
        integernew = integer - jobarvltime[j];
        printf("       %0.2f       -       %0.2f       =   %0.2f\n", integer, jobarvltime[j], integernew);
        sub = (sub += integernew);//addition in Turn around time
        div = sub / quantity;//division in sum of Turn around time value into job quantity
    }
    printf("________________________________________________________\n\n");
    printf("\n");
    // printf(" %0.2f + ",anss);
    printf("                                        --------------\n");
    printf(" Turn Around Time Addition is         =   %0.2f / %0.2f = ", sub, quantity);
    printf("%0.2f\n", div);
    printf("                                        --------------\n");

    return 0;
}
float subfunc3(float x, float y[])//subtract in Turn around time into PU time
{
    float subtract = 0;
    printf("  Turn Around Time -      P.T.W.T     =   Waiting Time \n");
    // return sub-jobautime[1];
    subtract = x - y[1];//subtract in 1st job turn around time into PU time
    printf("       %0.2f        -       %0.2f       =   %0.2f\n", x, y[1], subtract);
    return 0;
}
float subfunc4(float x, float y[], float jobarvltime[], float sub, float jobautime[], float finalsub, float quantity)// T.A.T / P.U time = waiting time & waiting time addition and division into job quantity
{
    float sum = x;
    float integer = 0;
    float integersecond = 0;
    float subvalue = sub;
    float div = 0;
    float jobautimediv = 0;
    float integerthree = 0;
    float integerfour = 0;
    float waitimgtime = 0;
    float waitingtimedivquantity = 0;
    for (int j = 2; j <= quantity; j++)
    {
        integer = (sum += y[j]);
        integersecond = integer - jobarvltime[j];
        subvalue = (sub += integersecond);
        jobautimediv = integersecond - jobautime[j];
        integerfour = (integerthree += jobautimediv);
        waitimgtime = integerfour + finalsub;
        waitingtimedivquantity = waitimgtime / quantity;
        printf("       %0.2f       -       %0.2f       =   %0.2f\n", integersecond, jobautime[j], jobautimediv);
    }
    // printf("%0.2f\n",subbbb);
    printf("________________________________________________________\n\n");
    printf("\n");
    printf("                                        --------------\n");
    printf("Avrage Waiting Time is                 = %0.2f / %0.2f   = %0.2f\n", waitimgtime, quantity, waitingtimedivquantity);
    printf("                                        --------------\n\n");

    return 0;
}

int main()
{
    float quantity;
    char jobname[50];
    float jobarvltime[50];
    float jobautime[50];
    printf("-------------------------------\n");
    printf("Enter job quantity\n");
    scanf("%f", &quantity);
    printf("-------------------------------\n");
    for (int i = 1; i <= quantity; i++)
    {
        printf("________________________________________________________\n");
        printf("enter %d job name\n", i); 
        scanf("%s", &jobname[i]); //input---job name
        printf("enter %d job arrival time\n", i);
        scanf("%f", &jobarvltime[i]);//input---job arrival time
        printf("enter %d job au time\n", i);
        scanf("%f", &jobautime[i]);//input---job PU time
        printf("________________________________________________________\n");
    }
    printf("\n");
    printf("________________________________________________________\n\n");
    func1(jobname, quantity); //call in func1 and send 2 value function 
    printf("\n");
    func2(jobarvltime, quantity);//call in func2 and send 2 value function
    printf("\n");
    func3(jobautime, quantity);//call in func3 and send 2 value function
    printf("\n");
    printf("________________________________________________________\n\n");
    float add = func4(jobarvltime, jobautime); //call in func4 and send 2 value function
    // printf("___________________________________\n");
    // printf("|__A___|__B___|__C___|______|__Z___|\n");
    gantt_chart_box(quantity,jobname);
    printf("|");
    printf("\n");
    printf("%0.2f     %0.2f ", jobarvltime[1], add);
    func5(add, jobautime, quantity);
    printf("\n\n");
    printf("________________________________________________________\n\n");
    float sub = subfunc1(jobautime, jobarvltime);
    printf("       %0.2f        -       %0.2f       =   %0.2f\n", jobautime[1], jobarvltime[1], sub);
    subfunc2(add, jobautime, jobarvltime, sub, quantity);
    printf("\n\n");
    printf("________________________________________________________\n\n");
    float finalsub = subfunc3(sub, jobautime);
    // printf("%0.2f - %0.2f = %0.2f\n",sub,jobautime,sub1);
    subfunc4(add, jobautime, jobarvltime, sub, jobautime, finalsub, quantity);
    return 0;
}
