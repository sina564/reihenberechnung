#include <stdio.h>

int main() {

    double x;
    double exp_x = 1; // Der erste Summand der Exponentialreihe ist 1.
    int continue_program = 1;
    double collector [10] [2]; //10 rows 2 columns
    int num_runs = 0; //anzahl der durchlaeufe der do schleife

    do {
        x = 0; //reset wenn eine erneute eingabe gemacht wird
        exp_x = 1; //reset wenn eine erneute eingabe gemacht wird

        printf("Geben Sie die Kommazahl x (zwischen -10 und 10) ein.\n");
        scanf("%lf", &x);

        //Passen Sie das Programm so an, sodass die Aufforderung zur Eingabe der Zahl wiederholt wird, bis die Eingabe in dem vorgegebenen Wertebereich liegt.
        while ((x > 10) || (x < -10)) {
            printf("Geben Sie eine gueltige Kommazahl zwischen -10 und 10 ein.\n");
            scanf("%lf", &x);
        }

        collector[num_runs] [0] = x; //array-wert fuer den durchlauf setzen

        //Ihr Programm soll nun fuer den eingegebenen Wert die Exponentialfunktion exp(x) approximieren, in dem die Partialsumme der Exponentialreihe fuer die ersten 100 Summanden berechnet wird.
        double term = 1;  // Der erste Term der Partialsumme.
        double factorial = 1;

        for (int n=1; n<=100; n++) {
            //factorial *= n;
            //term =  pow(x, n) / factorial;
            term *= x / n;
            exp_x += term;
        }

        collector[num_runs] [1] = exp_x; //array-wert fuer den durchlauf setzen

        // Geben Sie das Ergebnis von exp(x) mit 15 Nachkommastellen aus.
        printf("exp(x) = %.15lf\n", exp_x);

        num_runs++;
        //printf("Debug: Num of runs %d\n", num_runs);

        if (num_runs == 10) {
            break;
        }

        //Das Programm soll den Nutzer abschließend fragen, ob er eine weitere Zahl eingeben will und ggf. das Programm wieder bei der Eingabe der Zahl starten und die Approximation fuer die neue Eingabe ausgeben lassen.
        printf("Moechten Sie noch eine Approximation durchfuehren? 1 = ja, 0 = nein.\n");
        scanf("%d", &continue_program);
        while ((continue_program !=1) && (continue_program != 0)) {
            printf("Geben Sie eine gueltige Antwort ein! 1 = weiter, 0 = beenden:\n");
            scanf("%d", &continue_program);
        }

    } while (continue_program==1);

    //Speichern Sie fuer jede korrekte Eingabe des Nutzers den Wert von x und den entsprechenden approximierten Wert von exp(x) in einer geeigneten Datenstruktur.
    //Nachdem der Nutzer das zehnte Mal erfolgreich einen Wert berechnet hat, soll das Programm alle gespeicherten Paare von x und exp(x) ausgeben und dann beendet werden. Ueberlegen Sie sich hierfuer eine geeignete Datenstruktur.
    printf("\nErgebnisse:\n");
    for (int i = 0; i < 10; i++) {
        printf("x: %.2lf, exp(x): %.15lf\n", collector[i][0], collector[i][1]);
    }

    return 0;
}