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

short_desc = "Whispering Woods";
long_desc =
"Scattered groups of maple, alder and ash trees grow all about you.  A\n"+
"massive oak, its trunk scarred as if by lightning, stands alone a short\n"+
"distance off.  A large log lies across a narrow but deep chasm. It might\n"+
"be possible to traverse the log if you have good balance.  A few gourds\n"+
"are growing on a vine beside the fallen log.  Flowers, ferns and bushes\n"+
"also grow here in abundance.\n";

items = ({
"vine",    "A long stalk growing from beneath the fallen log.  It has some gourds attached",
"oak",     "A huge oak tree.  Its bark is burned away in places as if by lightning",
"gourds",  "These might be edible.  Maybe you could pick one",
"flowers", "Blue iris mixed with gold, pink delphinium, and some flowering kale",
"maple",   "The maple trees are rather pear shaped and symetrical three fingered leaves",
"alder",   "The alder trees look very much like the maple, but not as broad at the top",
"ash",     "The ash trees are oval in shape, and have small delicate leaves of silver and green",
"trees",   "Mostly maple, alder, and ash",
"bushes",  "Gooseberry, prickle grape and thistle",
"log",     "The trunk of an old alder tree, worn and weathered.  The bark has\n"+
           "been worn away on the top",
"chasm",   "It is too deep and its sides are too steep to climb.  The log is the only\n"+
           "means by which to cross it",
"ferns",   "Delicate, green and scattered among the flowers, its hard to tell one from another",

});
if(!present("imp",this_object()))
 move_object(clone_object("/players/fakir/woods/NPC/imp.c"),this_object());
dest_dir = ({
   "/players/fakir/woods/room13.c", "traverse",
   "/players/fakir/woods/room29.c", "south",
   
});
}
init()  {
  ::init();
    add_action("pick_gourd","pick");
}
pick_gourd(arg)  {
if(!arg || arg != "gourd") {
notify_fail("You cannot possibly pick that here.\n");
return 0; 
}
if(found==0) { write("All the gourds within reach have been picked.\n"); 
return 1;
}
write("You reach down and pick a gourd from the vine!\n");
move_object(clone_object("/players/fakir/woods/OBJ/gourd.c"),this_player());
found=found-1;
return 1; 
}



