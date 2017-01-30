#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/turtleville"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
if(!present("smith",this_object()))
  move_object(clone_object("/players/wocket/turtleville/NPC/smith.c"),this_object());
  if(arg) return;

short_desc = HIG+"The Turtleville Shell Smith"+NORM;
long_desc = "   Bright light filters through the hot steamy smithshop.  The furnace,\n"+
            "covered with stone and steel, burns bright in the corner.  Large hammers\n"+
            "rest upon the walls along with tongs and other shellworking tools.\n"+
            "An anvil lays in the center of the room beaten from use.\n";

items = ({
  "light","It filters through the smoke and dust",
  "furnace","Covered with stone and steal, this small furnace burns\nwhite hot in the corner of the room",
  "stone","Nicks and cracks litter the stones that entrap the fire",
  "steel","A dark grey and very hot",
  "hammers","They have long wooden handles and their heads have been\nbeaten and chiped",
  "tongs","Metal tongs bent from holding molten shells",
  "anvil","This steel anvil is the centerpiece of the smithshop",
  "walls","They are dark from the steam and heat and hold hammers and tongs",
  "corner","A furnace rests there",
  "tools","Many different tools like files, clamps, pokers, all used\nfor shellworking",
});  
smells = ({
  "default","Steam and heat knock you back",
});
listens = ({
  "default","You hear the fire crackle",
  "fire","It crackles and hisses",
});

dest_dir = ({
    PATH+"/tnpath2.c","east",
  });
set_light(1);
}
