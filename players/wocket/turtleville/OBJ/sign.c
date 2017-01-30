#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
set_id("sign");
set_alias("turtlesign");
set_short("A sign to "+HIG+"Turtleville"+NORM);
set_long("\n\n  Southwest \n"+
             "        to\n"+
         HIG+"      Turtleville \n"+NORM+
             "               North\n"+
             "          to the\n"+
         HIR+"     Mushroom Grove\n\n\n"+NORM); 
}

get(){ return 0; }
