#include "/open/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

short_desc = ""+BLU+"Kitchen"+NORM+"";
long_desc =
  "    This is the kitchen of the house.  There is a long counter\n"+
  "running along the east wall.  There is a large sink in the middle\n"+
  "of the counter.  On the west wall sits a refrigerator.  The counter\n"+
  "from the east wall continues on the north wall where it ends at an\n"+
  "electric stove.  Next to the stove there is a dishwasher.\n";
set_light(1);

items = ({
"stove","A white gas stove, maybe you could put your head in it, but would you want to",
"counter","A long counter top that extends the length of the east wall",
"counter top","A long counter top that extends the length of the east wall",
"sink","A large ceramic sink in the middle of the counter",
"refrigerator","An average size white refrigerator with two doors", 
"dishwasher","A white dishwasher used to wash dishes",
});

dest_dir = ({
"/players/pestilence/amity/room/madhouse1.c","south",
});
}


 init () {
   ::init() ;
   add_action("stove", "put");
}

stove(arg) {
     if(!arg) { notify_fail("Put your head where?\n");
     return 0;
}
     if(arg == "head in the stove"){   
write("You put your head in the stove.\n"+
           "You feel the heat kill off some of your brain cells.\n"+
           "You remove your head quickly from the stove.\n");
     this_player()->heal_self(-30); 
     return 1;}
     if(arg == "my head in the stove"){   
write("You put your head in the stove.\n"+
           "You feel the heat kill off some of your brain cells.\n"+
           "You remove your head quickly from the stove.\n");
     this_player()->heal_self(-30); 
     return 1;}
     if(arg == "head in stove"){   
write("You put your head in the stove.\n"+
           "You feel the heat kill off some of your brain cells.\n"+
           "You remove your head quickly from the stove.\n");
     this_player()->heal_self(-30); 
     return 1;}
     if(arg == "my head in stove"){   
write("You put your head in the stove.\n"+
           "You feel the heat kill off some of your brain cells.\n"+
           "You remove your head quickly from the stove.\n");
     this_player()->heal_self(-30); 
     return 1;}
     if(arg == "head stove"){   
write("You put your head in the stove.\n"+
           "You feel the heat kill off some of your brain cells.\n"+
           "You remove your head quickly from the stove.\n");
     this_player()->heal_self(-30); 
     return 1;}
     else
     {
            notify_fail("You can only put your head in the stove.\n");
     return 0;
}
}
