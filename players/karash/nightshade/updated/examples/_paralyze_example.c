/* A spell to paralyze a player with fear */

#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

int count;

reset(arg)  
{
   if(arg) return;
   count = 1+random(4);
   set_weight(0);
   set_heart_beat(1);
}

id(str)  {  return str == "freeze_me";  }

long(){ return 0; }

short() { return 0; }


init() 
{
#ifndef __LDMUD__
  add_action("iced"); add_xverb("");
#else
  add_action("iced", "", 3);
#endif
}

init_arg(str)  {  sscanf(str, "%d", count);  }

iced()  
{
   if(count > 0){
      write(HIC+"You're paralyzed with fear!\n"+NORM);
/*
      write(count+"\n");
*/
      return 1;  }
   else  {
      say(this_player()->query_name()+" is paralyzed with fear.\n");
      write("You're paralyzed with fear!\n");
      destruct(this_object());
      return 1;
      /* This cannot happen or heartbeat error if command is called from heartbeat - like wimpy
         return 0;
      */
   }
}

drop()  { return 1; }
get()   { return 1;  }

heart_beat() 
{
   count--;
   if(count <= 0)
      destruct(this_object());
}

