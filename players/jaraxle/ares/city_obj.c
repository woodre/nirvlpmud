#include "/players/jaraxle/ansi.h"

#define DAEMON "/players/jaraxle/templar/gdaemon.c"

id(str){ return str == "sign" || str == "city" || str == "ares" || str == "new ares"; }



short(){ return RED+"The Port-City of New Ares ("+HIW+gates()+NORM+RED+")"+NORM+".\n"+

                    "a small sign";

       }



gates(){ 

if(DAEMON->gate1_condition() && DAEMON->gate1() == 2){

   return "Closed";

   }

else return "Open";

}



long(str){

if(str == "sign"){  

    write("A small sign that reads...\n"+

          "City of New Ares, home of the Knights Templar. If\n"+

          "you are evil or a Criminal, leave at once.  If you\n"+  

          "are a friend, welcome and accept our protection.\n");

    return 1;

    }

else{ 

    write(

"You stand before the huge city of New Ares.  It is a busy port city that\n"+

"is home to thousands of civilians and the protectors of the realm - the\n"+

"Knights Templar. Fortress Stone can be seen far to the rear of the city.\n"+

"If you are a friend, you may '"+HIW+"enter city"+NORM+"'.\n"); 

    return 1;

    }

}

        

get(){ return 0; } 

query_weight(){ return 100000; }

query_value(){ return 0; }



init(){

   add_action("enter","enter");

   }



enter(str){

  this_player()->move_player("into the city#players/jaraxle/ares/rooms/city1.c");

  return 1;

  }



