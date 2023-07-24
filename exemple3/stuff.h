#ifndef STUFF_H
#define STUFF_H

#endif // STUFF_H

/**
 * @brief Portée des variables, page 36
 */
void porteeVariable()
{
        int i=1;
        printf ("La valeur de i est %d\n",i);
        {int i=2;
        printf ("La valeur de i est %d\n",i);
            {int i=3;
            printf ("La valeur de i est %d\n",i);
            }
        printf ("La valeur de i est %d\n",i);
        }
        printf ("La valeur de i est %d\n",i);
}

/**
 * @brief Valeur maximalle pour les entiers, page 43
 */
void valeurMax()
{
    printf("Un octet se compose de %d bits.\n", CHAR_BIT);
    printf("signed char : min = %d ; max = %d.\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char : min = 0 ; max = %u.\n", UCHAR_MAX);
    printf("short : min = %d ; max = %d.\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short : min = 0 ; max = %u.\n", USHRT_MAX);
    printf("int : min = %d ; max = %d.\n", INT_MIN, INT_MAX);
    printf("unsigned int : min = 0 ; max = %u.\n", UINT_MAX);
    printf("long : min = %ld ; max = %ld.\n", LONG_MIN, LONG_MAX);
    printf("unsigned long : min = 0 ; max = %lu.\n", ULONG_MAX);
    printf("long long : min = %lld ; max = %lld.\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long : min = 0 ; max = %llu.\n", ULLONG_MAX);

    printf("float : min = %e ; max = %e.\n", FLT_MIN, FLT_MAX);
    printf("double : min = %e ; max = %e.\n", DBL_MIN, DBL_MAX);
    printf("long double : min = %Le ; max = %Le.\n", LDBL_MIN, LDBL_MAX);
}

/**
 * @brief operateur arithmétique, page 55
 */
void operateur(){
    float a=3/2;
    float b=3/2.;

    printf("3/2 = %f\n", a);
    printf("3/2. = %f\n", b);

    double c=3/2;
    double d=3/2.;
    printf("double c 3/2. = %lf\n", c);
    printf("double d 3/2. = %lf\n", d);
}

/**
 * @brief conversions numériques implicites, page 56
 */
void conversion(){
    char car='A' ;
    car=car+1 ;
    printf("car = %c\n", car);

    float val=2.97;
    int i = val;
    printf("val = %i\n", i);
}

/**
 * @brief Teste de l'erreur if ( a = b)
 */
void ifAegalB(){
    // essayer l'erreur if ( a=b) à la place de a==b
    // si il n'y pas le double égal, on affecte b à a (a = 3 ici)

    int a = 2;
    int b = 3;

    if ( a = b )
        printf("yes. a = %d\n", a);
    else
        printf("no. a = %i\n", a);
}

/**
 * @brief incrementation, page 62
 */
void incrementation(){
//        int a = 0b1010;
//        int b = 0b1000;
//        int c;
//        c = a & b;
//        printf("a = %d\n", a);
//        printf("c = %d\n", c);

//        int a = 8;
//        int b = 5;
//        bool a = true;
//        bool b = false;
//        if ( a & b )
//            printf("true \na = %d \nb = %d\n", a, b);
//        else
//            printf("false \na = %d \nb = %d\n", a, b);

//        int a = 3, b;
//        a++;
//        printf("a = %d\n", a);
//        --a;
//        printf("a = %d\n", a);

        int a = 3, b ,c ,d;
        d = 3;
        b = a++;
        d = ++c;
        printf("a = %d\n", a);
        printf("b = %d\n", b);
        printf("d = %d\n", d);
}

/**
 * @brief opTernaire, valeur absolue, page 66
 */
void opTernaire(){
    int x;
    x = 1;
    x = x >= 0 ? x : -x;
//    if ( x >= 0) x=x; else x=-x;
    printf("x = %d\n", x);
}

/**
 * @brief cast
 */
void cast(){
    int i = 5, j = 2;
//    printf("%f \n",(float)i/j);
    printf("%d\n", i/j);
}

/**
 * @brief tailleMemoire, page 70
 */
void tailleMemoire(){
    long int i=18 ;
    int j = 3;
    unsigned long k = 2;
    int s1=sizeof(i);
    int s2=sizeof(j);
    int s3=sizeof(&j);
    int s4=sizeof(k);

    printf("long int = %d\n", s1);
    printf("int = %d\n", s2);
    printf("adresse sur int =  %d\n", s3);
    printf("unsigned long = %d\n", s4);
}

/**
 * @brief breakBoucleImbriquee
 */
void breakBoucleImbriquee(){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
                printf("i j = %d %d\n",i,j);
                if (j == 2)
                break;
        }
    }
    return 0;
}

void affichageAaZ(){
        char a='a' ;
        char z='z' ;
        char A='A' ;
        char Z='Z' ;

        for (int i = a; i <= z; ++i) {
            printf("%c = %d \n", i, i);
        }

        for (int i = A; i <= z; ++i) {
            printf("%c = %d \n", i, i);
        }
}

void nombredOr(){
    int i,n,nor;
    n = 0;
    i=0;
    srand(time(NULL));
    nor = rand() % 100;

//    printf("rand = %d\n",nor);

    while (n !=nor) {
        i++;
        printf("entrez un nombre entre 0 et 100\n");
        scanf("%d",&n);

        if ( n > nor){
            printf("Le nombre d'or est plus petit.\n");
        }
        else if (n < nor) {
            printf("Le nombre d'or est plus grand.\n");
        }
        else {
            printf("Bien joué ! Le nombre d'or est : %d\n", nor);
            printf("Vous avez trouvez en %d essais\n", i);
        }
    }
}
