#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

 
object ob;
int shield;
 
extra_init() {
	string invaden;
	object invadobj;

	if(call_other(this_player(),"query_real_name") == "mistress") {
   		add_action("stat"); add_verb("shield");
	}
	invadobj = this_player();
	invaden = call_other(this_player(),"query_real_name");

        if(invaden != "mistress" && invaden != "orlith" && shield == 1) {
		write("\n\nIt is not nice to barge in unannounced.!\n");
                say("Oops! " + this_player()->query_real_name()+" tried to enter!\n");
		write("Be off with you!  I know how to deal with trespassers!\n");
		write("See if you can find your way now!  Next time knock.\n");
                transfer(invadobj,"room/mount_top2");
	}
	
}
 
stat(str) {
   if(str == "on")
	 shield = 1;
   if(str == "off")
      shield = 0;
   if (shield == 1)
      write("Shield on.\n");
   else 
      write("Shields off.\n");
   return 1;
}

/*
        The Love_Nest of Mistress...  (sorry...had to say it)
*/


FOUR_EXIT("room/vill_shore2", "out",
          "players/mistress/lobby/desk","desk",
           "room/post","post",
           "room/church","church",
         "Mistress's workroom",
         "This is a small, dark, musty room with old, leather bound books \n" +
         "scattered everywhere.  The floor, tables, chairs, and every other \n" + 
	    "horizontal surface is piled high with priceless treasures, ranging \n" +
         "from original transcrips of Aristotle to the history of Claudius \n" +
         "hand lettered on ancient scrolls.  The dust, musty smell, and clutter \n" + 
	    "cannot hide the loving attention given these great works... \n", 1)

