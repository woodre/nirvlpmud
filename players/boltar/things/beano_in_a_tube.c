#include "/obj/clean.c"
#include "/players/boltar/things/esc.h"
int used;

short() {
   if(used == 0) 
     return "A large tube of something";
   if(used == 1)
   return "A large squeezed out metal tube";
}

query_value() {
    if(!used)
        return 150;
    return 0;
}

query_weight() { return 1; }

long() {
   write("A huge squeeze tube of what appears to be RTV.\n"+
         "The label reads: BEANO IN A TUBE.\n"+
         "The instructions read: squeeze tube\n");
}

init() {
     add_action("squeeze","squeeze");
     add_action("eat","eat");
}

id(str) {
    return str == "tube" || str == "metal tube";
}



eat(str) {
    if (str && !id(str)) return 0;
   if(used != 0) {
   write("The tube is empty.\n");
   return 1;
   }
   write("You squeeze out some beano and taste it.\n");
   say(call_other(this_player(), "query_name") + 
       " squeezes a little goop out of a tube and tastes it. \n");
   write("ICK!!!!!!!\n");
   command("puke",this_player());
   return 1;
} 

squeeze(str) {
    if (str && !id(str)) return 0;
   if(used != 0) {
   write("The tube is empty.\n");
   return 1;
   }
 write("You remove the top of the tube and squeeze.\n");
 write("An orange goop spews out of the tube and piles up in the\n"+
       "form of a beano at your feet.\n");
 if (this_player()) {
say(call_other(this_player(), "query_name") +
  " squeezes goop out of a tube. \n"+
  "A beano forms from the goop. \n");
  }
  used = 1;
  move_object(clone_object("/players/mizan/mball/beasties/beano"),environment(this_player()));
  return 1;
}

get() {
   return 1;
}


