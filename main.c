#include <stdio.h>

int main() {

    //Aktuell erfolgt die Approximation der Exponentialreihe fuer eine hardkodierte Anzahl von Summanden.
    //Passen Sie Ihr Programm an, sodass die Approximation endet, wenn der naechste Summand in Betrag kleiner ist als ein vorgegebener Schwellenwert (bspw. 0.00000001).
    //Zaehlen Sie die Anzahl der verwendeten Summanden und geben diese Anzahl mit aus.

    double x;
    double exp_x = 1; // Der erste Summand der Exponentialreihe ist 1.
    int continue_program = 1;
    double collector [10] [2]; //10 rows 2 columns
    int num_runs = 0; //anzahl der durchlaeufe der do schleife

    double treshold = 0.00000001;
    int summand;

    do {
        x = 0; //reset wenn eine erneute eingabe gemacht wird
        exp_x = 1; //reset wenn eine erneute eingabe gemacht wird

        printf("Geben Sie die Kommazahl x (zwischen -10 und 10) ein.\n");
        scanf("%lf", &x);

        while ((x > 10) || (x < -10)) {
            printf("Geben Sie eine gueltige Kommazahl zwischen -10 und 10 ein.\n");
            scanf("%lf", &x);
        }

        collector[num_runs] [0] = x; //array-wert fuer den durchlauf setzen

        double term = 1;  // Der erste Term der Partialsumme.
        double factorial = 1;

        for (int n=1; term > treshold; n++) {
            //factorial *= n;
            //term =  pow(x, n) / factorial;
            term *= x / n;
            exp_x += term;
            summand++;
        }

        collector[num_runs] [1] = exp_x; //array-wert fuer den durchlauf setzen

        printf("exp(x) = %.15lf\n", exp_x);
        printf("Summanden: %.15d\n", summand-1);

        num_runs++;
        //printf("Debug: Num of runs %d\n", num_runs);

        if (num_runs == 10) {
            break;
        }

        printf("Moechten Sie noch eine Approximation durchfuehren? 1 = ja, 0 = nein.\n");
        scanf("%d", &continue_program);
        while ((continue_program !=1) && (continue_program != 0)) {
            printf("Geben Sie eine gueltige Antwort ein! 1 = weiter, 0 = beenden:\n");
            scanf("%d", &continue_program);
        }

    } while (continue_program==1);

    printf("\nErgebnisse:\n");
    for (int i = 0; i < 10; i++) {
        printf("x: %.2lf, exp(x): %.15lf\n", collector[i][0], collector[i][1]);
    }

    return 0;
}