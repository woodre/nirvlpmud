#include "/players/boltar/things/esc.h"
reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="sign") return 1;
        return 0;
}

long() {
write( "\n           *========================================================*\n");
write( "           |                     *UNDEAD GUILD*                     |\n");
write( "           |--------------------------------------------------------|\n");
 write( "           |    JOIN    | *Enter the Undead Guild                   |\n");
write( "           |   ADVANCE  | *Raise your guild level when you have     |\n");
write( "	   |            |  enough experience to spare above your    |\n");
write( "	   |            |  general level.                           |\n");
write( "	   |    COST    | *Look at the list of experience needed    |\n");
write( "	   |            |  for each guild level.                    |\n");
write( "           *========================================================*\n");
}

short()
  { return "An "+esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40mUNDEAD "+esc+"[0msign"; }
init()
{
  add_action( "cost","cost");
}
cost()
{ 
write( "\n           *========================================================*\n");
write( "           |                     *UNDEAD GUILD*                     |\n");
write( "           |--------------------------------------------------------|\n");
write( "           |          1st Level         |              0 Exp Pts.   |\n");
write( "           |          2nd Level         |           5000 Exp Pts.   |\n");
write( "	   |          3rd Level         |   2nd +  10000 Exp Pts.   |\n");
write( "	   |          4th Level         |   3rd +  20000 Exp Pts.   |\n");
write( "	   |          5th Level         |   4th +  40000 Exp Pts.   |\n");
write( "	   |          6th Level         |   5th +  80000 Exp Pts.   |\n");
write( "	   |          7th Level         |   6th + 160000 Exp Pts.   |\n");
write( "           |          8th Level         |   7th + 320000 Exp Pts.   |\n");
write( "           *========================================================*\n");
return 1;
}

get() {
        return 0;
}
drop() {
        return 0;
}
