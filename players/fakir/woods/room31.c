#define TP this_player()
#define TPN this_player()->query_name()
#include "/players/fakir/color.h"
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
found = 1+random(4);
set_light(1);

short_desc = "Top of a Tree";
long_desc =
"You find yourself surrounded by dozens of small slender fig saplings, all\n"+
"reaching in height for the same blue sky.  It is almost like being in a\n"+
"jail cell, as your movements are limited in every direction but down.\n";

items = ({
"saplings",  "Long slender shoots from the strangler fig that has taken\n"+
             "root here in the crotch of the host tree.  Some have small\n"+
             "figs growing on them.  You should 'pick' a few",
"sky",       "Clear blue with just a few puffy clouds",


});

dest_dir = ({
   "/players/fakir/woods/room27.c", "down",
     
});
}
init()  {
  ::init();
    add_action("pick_fig","pick");
}
pick_fig(arg)  {
if(!arg || arg != "fig") {
notify_fail("You cannot possibly pick that here.\n");
return 0; 
}
if(found==0) { write("All the figs within reach have been picked.\n"); 
return 1;
}
write("You reach way out and pick a nice juicy fig!\n");
move_object(clone_object("/players/fakir/woods/OBJ/fig.c"),this_player());
found=found-1;
return 1; 
}


