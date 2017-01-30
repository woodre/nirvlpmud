#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
#define PED "/players/wocket/turtleville/NPC/ped.c"
inherit "/players/wocket/std/tvroom.c";

reset(arg) {

if(!present("bartender",this_object()))
  move_object(clone_object(PATH+"/NPC/bartender.c"),this_object());
if(!present("maid",this_object()))
  move_object(clone_object(PATH+"/NPC/maid.c"),this_object());
if(random(2)==1){
if(!present("ped",this_object()))
  move_object(clone_object(PED),this_object());
 if(random(2)==1){
  move_object(clone_object(PED),this_object());
 }
}
      if (arg) return;
  short_desc = HIG+"The Turtleville Pub"+NORM;  
  long_desc = ""+
  "   There is a little bar off to the back of the small pub.  Bottles\n"+
  "of different concoctions line the back wall.  Small tables built from\n"+
  "giant turtle shells inhabit the main room with four chairs at each one.\n"+
  "The dark hardwood floors and the soft cushions on the seats, along with\n"+
  "the gentle light that filters in, gives this small pub a comfy atmosphere.\n"+
  "There is a menu behind the bar.\n";
  items = ({
    "bar","It is a dark polished black with small seats next to it",
    "seats","They have nice soft cushions on them and look sturdy",
    "cushions","They are soft and red",
    "floors","They are a deep heartwood and shine in the light",
    "bottles","They are all different shapes and sizes, many with green glass",
    "light","It filters in the doorway",
    "tables","They seem to be build from turtle shells.  They seat four comfortably",
    "chairs","They are all wood, but have been molded to give a nice feel",
    "menu","+--------------------------------+\n"+
           "|"+HIB+" ITEM:                 COST:"+NORM+"    |\n"+
           "|   ale                   10     |\n"+
           "|   turtle blood          300    |\n"+
           "|   turtillian shot       500    |\n"+
           "|                                |\n"+
           "|   turtle soup           250    |\n"+
           "|   water                 100    |\n"+
           "+--------------------------------+\n",

});

  smells = ({
     "default","It smells of alcohol",
   });
  listens = ({
     "default","It is very quiet in the bar",
    });

dest_dir = ({
    PATH+"/tnpath2.c","west",
  });
  set_light( 1);
}

init(){
  ::init();
  add_action("read","read");
}

read(string str){
  if(!str || str != "menu"){
  notify_fail("What would you like to read?\n");
  return 0;
}
write("+--------------------------------+\n"+
      "|"+HIB+" ITEM:                 COST:"+NORM+"    |\n"+
      "|   ale                   10     |\n"+
      "|   turtle blood          300    |\n"+
      "|   turtillian shot       500    |\n"+
      "|                                |\n"+
      "|   turtle soup           250    |\n"+
      "|   water                 100    |\n"+
      "+--------------------------------+\n");
return 1;
}



