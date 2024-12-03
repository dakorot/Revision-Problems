#include <cstdio>

void credit_payment_per_month(float loan, unsigned int months)
{
    float payment, percentage, total_payment = 0.0f, loan_left = loan;
    unsigned int current_month = 1;

    for(int i=0; i<months; i++)
    {

        loan_left -= loan/months;
        percentage = 0.2f*loan_left;
        payment = loan/months + percentage;

        printf("%d %.2f\n", current_month, payment);

        ++current_month;
        total_payment += payment;
    }
    printf("%.2f", total_payment);
}

int main()
{
    float X;
    unsigned int M;
    scanf("%f\n%u", &X, &M);
    credit_payment_per_month(X, M);

    return 0;
}