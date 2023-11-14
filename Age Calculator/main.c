//age calculator
#include <stdio.h>


struct age {
    int day;
    int month;
    int year;
};

void citireDate(struct age* date) {
    printf("Ziua: ");
    scanf("%d", &date->day);
    printf("Luna: ");
    scanf("%d", &date->month);
    printf("Anul: ");
    scanf("%d", &date->year);
}

void afisareDate(struct age date) {
    printf("Ziua: %d\n", date.day);
    printf("Luna: %d\n", date.month);
    printf("Anul: %d\n", date.year);
}

int verificareAn(struct age birth, struct age today) {
    if(birth.year <= today.year) {
        printf("Ani au fost verificati cu succes!\n");
        return 0;
    }
    else {
        return 1;
    }
}

int verifiareLuna(struct age birth, struct age today) {
    if(birth.month <= 12 && today.month <= 12) {
        printf("Lunile au fost verificate cu succes!\n");
        return 0;
    }
    else {
        return 1;
    }
}

int leapYears(struct age leap) {
    return (leap.year % 4 == 0 && leap.year % 100 != 0) || (leap.year % 400 == 0);
}

int verificareZi(struct age birth, struct age today) {
        if(
            (birth.month == 1 && birth.day >= 1 && birth.day <= 31) ||
            (today.month == 1 && today.day >= 1 && today.day <= 31) ||
            //January
            (birth.month == 2 && birth.day >= 1 && (birth.day <= 29 && leapYears(birth) || birth.day <= 28)) ||
            (today.month == 2 && today.day >= 1 && (today.day <= 29 && leapYears(today) || today.day <= 28)) ||
            // February
            (birth.month == 3 && birth.day >= 1 && birth.day <= 31) ||
            (today.month == 3 && today.day >= 1 && today.day <= 31) ||
            //March
            (birth.month == 4 && birth.day >= 1 && birth.day <= 30) ||
            (today.month == 4 && today.day >= 1 && today.day <= 30) ||
            //April
            (birth.month == 5 && birth.day >= 1 && birth.day <= 31) ||
            (today.month == 5 && today.day >= 1 && today.day <= 31) ||
            //May
            (birth.month == 6 && birth.day >= 1 && birth.day <= 30) ||
            (today.month == 6 && today.day >= 1 && today.day <= 30) ||
            // June
            (birth.month == 7 && birth.day >= 1 && birth.day <= 31) ||
            (today.month == 7 && today.day >= 1 && today.day <= 31) ||
            // July
            (birth.month == 8 && birth.day >= 1 && birth.day <= 31) ||
            (today.month == 8 && today.day >= 1 && today.day <= 31) || 
            // August
            (birth.month == 9 && birth.day >= 1 && birth.day <= 30) ||
            (today.month == 9 && today.day >= 1 && today.day <= 30) ||
            // September
            (birth.month == 10 && birth.day >= 1 && birth.day <= 31) ||
            (today.month == 10 && today.day >= 1 && today.day <= 31) || 
            // October
            (birth.month == 11 && birth.day >= 1 && birth.day <= 30) ||
            (today.month == 11 && today.day >= 1 && today.day <= 30) ||
            // November
            (birth.month == 12 && birth.day >= 1 && birth.day <= 31) ||
            (today.month == 12 && today.day >= 1 && today.day <= 31)
            // December
        ) {
            printf("Zilele au fost verificate cu succes!\n");
            return 0;
        }
        else {
            return 1;
        }
}

int daysLastMonth(struct age today) {
    int lastMonth = today.month - 1;
    if (lastMonth == 0) {
        lastMonth = 12;
        today.year--;
    }

    int daysLastMonth;
    switch (lastMonth) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysLastMonth = 31;
            break;
        case 4: case 6: case 9: case 11:
            daysLastMonth = 30;
            break;
        case 2:
            if ((today.year % 4 == 0 && today.year % 100 != 0) || (today.year % 400 == 0))
                daysLastMonth = 29;
            else
                daysLastMonth = 28;
            break;
    }

    return daysLastMonth;
}

void calculareVarsta(struct age birth, struct age today) {
    int ageYears= today.year - birth.year;
    int ageMonths= today.month - birth.month;
    int ageDays= today.day - birth.day;
        
    if(ageDays < 0) {
        ageMonths--;
        int daysInLastMonth= daysLastMonth(today);
        ageDays += daysInLastMonth;
    }
        
    if (ageMonths < 0) {
        ageYears--;
        ageMonths += 12;
    }

    printf("Ai %d ani, %d luni si %d zile!\n", ageYears, ageMonths, ageDays);
}


void main() {
    struct age birth;
    struct age today;
    
    printf("Introduceti data nasterii:\n");
    citireDate(&birth);
    
    printf("Introduceti data de astazi:\n");
    citireDate(&today);
    
    printf("Data nasterii: \n");
    afisareDate(birth);
    printf("Data de astazi: \n");
    afisareDate(today);
    
    printf("Urmeaza sa fie verficate datele introduse:\n");
    int check1= verificareAn(birth, today);
    int check2= verifiareLuna(birth, today);
    int check3= verificareZi(birth, today);
    
    //printf("%d\n", check1);
    //printf("%d\n", check2);
    //printf("%d\n", check3);
    
    if(check1 == 0 && check2 == 0 && check3 == 0) {
        calculareVarsta(birth, today);  
    }
    else {
        printf("Va rog sa introduceti date valide");
    }
}
