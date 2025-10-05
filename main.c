#include <stdio.h>
#include <stdlib.h>

//INPUT / UI
char pointTypeInput();
double pointAmmountInput(char type);
void loop(double ZT, double AT, double UE, double GP);

//CALCULATIONS
double totalPossiblePoints(int ztAmmount, int atDone);
double validPoints(double zt, double at, double ue, double possiblePoints);
int grade(double points, double possiblePoints);

//OUTPUT
void finalResult(double ZTPoints, double ZTDone, double ATPoints, double ATDone, double UEPoints);

int main(){
    double ZTPoints = 0; //points in ZT achieved
    double ATPoints = 0; //points in AT achieved
    double UEPoints = 0; //points in UE achieved

    int ZTDone = 0; //# of ZT taken
    int ATDone = 0; //bool has taken AT?

    char type = '1';          //type of points in current loop, '1' Placeholder
    double currentPoints = 0; //points in current loop

    while(type != '='){
        //print stats get type
        loop(ZTPoints, ATPoints, UEPoints, totalPossiblePoints(ZTDone, ATDone));
        type = pointTypeInput();

        if (type == '='){
            finalResult(ZTPoints, ZTDone, ATPoints, ATDone, UEPoints);
            continue;
        }

        //get & check points
        currentPoints = pointAmmountInput(type);
        if(currentPoints == -1) continue;

        switch(type){
            case('z'): //Zwischentest
                ZTPoints += currentPoints;
                ZTDone++;
                continue;

            case('a'): //Abschlusstest
                ATPoints = currentPoints;
                ATDone = 1;
                continue;

            case('u'): //Uebung
                UEPoints += currentPoints;
                if(UEPoints > 10) UEPoints = 10;
                continue;
        }
    }
    return 0;
}

//INPUT / UI
//gets the type user input
char pointTypeInput(){
    char type = '1';
    printf("\nTyp: ");
    scanf(" %c", &type);
    return type;
}

//gets and returns user input points
//checks if point ammount is valid for type
double pointAmmountInput(char type){
    double points = 0;
    printf("\nPunkte: ");
    scanf(" %lf", &points);

    double limit = type == 'z' ? 10.0
                   : type == 'a' ? 70.0
                   : type == 'u' ? 0.50
                   : 0.0;

    if(points < 0 || points > limit){
        printf("\nungueltiger Bereich: min 0.00, max %.2lf", limit);
        return -1;
    }
    return points;
}

//prints loop statistics
void loop(double ZT, double AT, double UE, double GP){
    printf("\nZT Punkte: %.2lf", ZT);
    printf("\nAT Punkte: %.2lf", AT);
    printf("\nUE Punkte: %.2lf", UE);
    printf("\nErreichbare Gesamtpunkte: %.2lf", GP);
}

//CALCULATIONS
//returns possible Points based on tests taken
double totalPossiblePoints(int ztAmmount, int atDone){
    return (10 * ztAmmount) + (70 * atDone);
}

//returns the points valid for grading
//if student hasn't taken tests return 0
double validPoints(double zt, double at, double ue, double possiblePoints){
    if(possiblePoints == 0) return 0;

    double gottenPoints = zt + at;
    if(gottenPoints < possiblePoints * 0.5) return gottenPoints;

    else return gottenPoints + ue;
}

//calculates final grade
//if no ZT and AT return 0
int grade(double points, double possiblePoints){
    //if student hasn't taken any tests
    if(possiblePoints == 0) return 0;

    //check if zw and at are enough to pass
    //return grade based on % achieved
    if(points >= possiblePoints * 0.88) return 1;
    else if(points >= possiblePoints * 0.75) return 2;
    else if(points >= possiblePoints * 0.63) return 3;
    else if(points >= possiblePoints * 0.5) return 4;
    else if(points < possiblePoints * 0.5) return 5;
    else return -1; //ERROR
}

//OUTPUT
//takes all data, calculates and ouputs resluts
void finalResult(double ZTPoints, double ZTDone, double ATPoints, double ATDone, double UEPoints)
{
    double possiblePoints  = totalPossiblePoints(ZTDone, ATDone);
    double achievedPoints;
    double percentage;
    int finalGrade;

    if(possiblePoints == 0){
        achievedPoints = 0;
        percentage = 0;
        finalGrade = 0;
    }else{
        achievedPoints = validPoints(ZTPoints, ATPoints, UEPoints, possiblePoints);
        finalGrade = grade(achievedPoints, possiblePoints);
        percentage = (achievedPoints / possiblePoints) * 100;
    }
    printf("\nGesamtpunkte absolut: %.2lf", achievedPoints);
    printf("\nGesamtpunkte %%: %.2lf %%", percentage);
    printf("\nNote: %d", finalGrade);
}
