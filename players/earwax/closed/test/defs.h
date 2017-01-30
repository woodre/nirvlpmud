#include "../defs.h"

/* Daemons */
#define TESTD "/players/earwax/closed/test/testd.c"

/* Paths */
#define TESTDIR "/players/earwax/closed/test/"
#define TESTROOM "/players/earwax/closed/test/testroom"
#define TESTSHADOW "/players/earwax/closed/test/tshadow"
#define TESTMON "/players/earwax/closed/test/testmon"
#define DATA "/players/earwax/closed/test/data/"

/* Specific Files */
#define CONTROLROOM "/players/earwax/closed/test/control"
#define TESTROOM "/players/earwax/closed/test/testroom"

/* Stuff */
#define PLAYER 1
#define MOB 0
#define DTYPES ({ \
"dark", "fire", "ice", "evil",\
"light", "wind", "electric", "good",\
"water", "earth", "laser", "poison" })
#define ATTEMPTED 0
#define ACTUAL 1
#define MAX 2
#define AVERAGE 3
