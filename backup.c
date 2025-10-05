//#include <stdio.h>
//#include <stdlib.h>
//
////INPUT
//char pointTypeInput();
//double pointAmmountInput();
//void loop(double ZT, double AT, double UE, double GP);
//
////OUTPUT
//double totalPossiblePoints(int ztAmmount, int atDone);
//int grade(double points, double possiblePoints);
//double validPoints(double zt, double at, double ue, double possiblePoints);
//
//int main()
//{
//    //Zwischentest
//    double ZTPoints = 0;
//    int ZTDone = 0;
//
//    //Abschlusstest
//    double ATPoints = 0;
//    int ATDone = 0;
//
//    //Übungen
//    double UEPoints = 0;
//
//    //user input
//    char type = '1';
//    double currentPoints = 0;
//
//    //Output
//    double possiblePoints = 0.0;
//    double achievedPoints = 0.0;
//    double percentage = 0.0;
//    int finalGrade = 0.0;
//
//    while(type != '=')
//    {
//        //print stats, type
//        loop(ZTPoints, ATPoints, UEPoints, totalPossiblePoints(ZTDone, ATDone));
//        type = pointTypeInput();
//
//        //quit, print out final result
//        switch(type)
//        {
//        case('z'):
//        {
//            currentPoints = pointAmmountInput();
//            if(currentPoints < 0.0 || currentPoints > 10.0)
//            {
//                printf("\nungueltiger Bereich: min 0.00, max 10.00");
//                continue;
//            }
//            else
//            {
//                ZTPoints += currentPoints;
//                ZTDone++;
//            }
//            continue;
//        }
//        case('a'):
//        {
//            currentPoints = pointAmmountInput();
//            if(currentPoints < 0.0 || currentPoints > 70.0)
//            {
//                printf("\nungueltiger Bereich: min 0.00, max 70.00");
//                continue;
//            }
//            else
//            {
//                ATPoints = currentPoints;
//                ATDone = 1;
//            }
//            continue;
//        }
//        case('u'):
//        {
//            currentPoints = pointAmmountInput();
//            if(currentPoints < 0.0 || currentPoints > 0.5)
//            {
//                printf("\nungueltiger Bereich: min 0.00, max 0.50");
//                continue;
//            }
//            else
//            {
//                UEPoints += currentPoints;
//                if(UEPoints >= 10)
//                {
//                    UEPoints = 10;
//                }
//            }
//            continue;
//        }
//        case('='):
//        {
//            possiblePoints = totalPossiblePoints(ZTDone, ATDone);
//            if(possiblePoints == 0)
//            {
//                achievedPoints = 0;
//                percentage = 0;
//                finalGrade = 0;
//            }
//            else
//            {
//                achievedPoints = validPoints(ZTPoints, ATPoints, UEPoints, possiblePoints);
//                finalGrade = grade(achievedPoints, possiblePoints);
//                percentage = (achievedPoints / possiblePoints) * 100;
//
//            }
//            continue;
//
//        }
//        default:
//        {
//            printf("Kein gueltiges Zeichen, geben Sie (z/a/u/=) ein");
//            continue;
//        }
//        }
//    }
//
//    //output final result
//    printf("\nGesamtpunkte absolut: %.2lf", achievedPoints);
//    printf("\nGesamtpunkte %%: %.2lf %%", percentage);
//    printf("\nNote: %d", finalGrade);
//    return 0;
//}
//
//double validPoints(double zt, double at, double ue, double possiblePoints)
//{
//    //if student hasn't taken any tests
//    if(possiblePoints == 0)
//    {
//        return 0;
//    }
//
//    double gottenPoints = zt + at;
//
//    //check if zw and at are enough to pass
//    if(gottenPoints <= possiblePoints * 0.5)
//    {
//        return gottenPoints;
//    }
//    //if yes, add ue points
//    else
//    {
//        return gottenPoints + ue;
//    }
//}
//
//int grade(double points, double possiblePoints)
//{
//    //if student hasn't taken any tests
//    if(possiblePoints == 0)
//    {
//        return 0;
//    }
//
//    //check if zw and at are enough to pass
//    //return grade based on % achieved
//    if(points >= possiblePoints * 0.88)
//    {
//        return 1;
//    }
//    else if(points >= possiblePoints * 0.75)
//    {
//        return 2;
//    }
//    else if(points >= possiblePoints * 0.63)
//    {
//        return 3;
//    }
//    else if(points > possiblePoints * 0.5)
//    {
//        return 4;
//    }
//    else if(points <= possiblePoints * 0.5)
//    {
//        return 5;
//    }
//    else
//    {
//        printf("ERROR, something went horribly wrong in grade()");
//        return -1;
//    }
//}
//
//double totalPossiblePoints(int ztAmmount, int atDone)
//{
//    return (10 * ztAmmount) + (70 * atDone);
//}
//
////UI
//char pointTypeInput()
//{
//    char type = '1';
//    printf("\nTyp: ");
//    scanf(" %c", &type);
//    return type;
//}
//
//double pointAmmountInput()
//{
//    double points = 0;
//    printf("\nPunkte: ");
//    scanf(" %lf", &points);
//    return points;
//}
//
//void loop(double ZT, double AT, double UE, double GP)
//{
//    printf("\nZT Punkte: %.2lf", ZT);
//    printf("\nAT Punkte: %.2lf", AT);
//    printf("\nUE Punkte: %.2lf", UE);
//    printf("\nErreichbare Gesamtpunkte: %.2lf", GP);
//}
