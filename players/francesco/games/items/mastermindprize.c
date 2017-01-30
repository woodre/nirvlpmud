#include "/players/francesco/univ/ansi.h"
#define tpn this_player()->query_name()
inherit "obj/treasure.c";

reset(arg)
{
    if(arg) return;
}

drop() { return 1;}

/* short() { return "Mastermind prize"; } */

long(str) {
    write("      "+HIC+environment(this_object())->query_name()+NORM+HIW+"\nSolved Mastermind quest"+NORM+"\n");
	return;
    }
    

init() {}

id(str) { return str == "large pin" || str == "pin"; }

query_weight() { return 0; }

query_auto_load(){return "players/francesco/games/items/mastermindprize.c:";}

extra_look() {
   string pronoun;
    if(environment(this_object())->query_gender() == "male") pronoun = "his";
     else pronoun = "her";
   write(environment(this_object())->query_name()+" has a large "+HIC+"pin "+NORM
        +"attached to "+pronoun+" clothes.\n");
}


/*
{
    write("\n        February 4th\n"+
          "   Happy B-Day, Francesco!\n\n");
    return 1;
}
*/
