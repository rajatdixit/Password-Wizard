//This file defines all IR Remote related functions used in our project
///-----------------------Declarations------------------------///
#define Forward   16736925
#define Back      16754775
#define Right     16761405
#define Left      16720605
#define OK        16712445
#define HASHTAG   16732845
#define STAR      16728765

#define ZERO  16730805
#define ONE   16738455
#define TWO   16750695
#define THREE 16756815
#define FOUR  16724175
#define FIVE  16718055
#define SIX   16743045
#define SEVEN 16716015
#define EIGHT 16726215
#define NINE  16734885
///-----------------------Functions Declarations------------------------///
void initializeRemote();
void waitForInput();
long unsigned int inputReceived();
void resumeRemote();