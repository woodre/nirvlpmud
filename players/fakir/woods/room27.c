#define TP this_player()
#define TPN this_player()->query_name()
#include "/players/fakir/color.h"
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Whispering Woods";
long_desc =
"Maple, alder, and ash trees grow thickly here, their trunks so close\n"+
"together it is almost impossible to find a way through.  The air is\n"+
"cool and slightly damp.  Clumps of ferns and bushes grow in such\n"+
"abundance they create a barrier in almost every direction.  A strangler\n"+
"fig has taken root in a rather large maple tree.  Its roots nearly reach\n"+
"the ground.\n";

items = ({
"fig",     "A bird dropped a strangler fig seed on a tree branch.  The seed sprouted.\n"+
           "It sent long roots down toward the ground.  The strangler fig's roots\n"+
           "wound around the tree's trunk, making their way to the ground.  Eventually,\n"+
           "the fig will kill the tree on which it grows",
"roots",   "Long rope-like roots from the strangler fig.  You could probably use them\n"+
           "to help you climb",
"ferns",   "Deep green and bushy, they grow in abundance around the trunks of the trees",
"trees",   "The trees all blend in together, but you can tell they are maple, alder, and ash",
"earth",   "Rich dark loam like that found in most wooded areas",
"maple",   "The maple trees are rather pear shaped and symetrical three fingered leaves",
"alder",   "The alder trees look very much like the maple, but not as broad at the top",
"ash",     "The ash trees are oval in shape, and have small delicate leaves of silver and green",
"trunks",  "They are so close together it is hard to tell one from another",
"bushes",  "Gooseberry, rhododendrons in full bloom, wild grape and a few vine maple.\n"+
           "You might be able to 'push' your way through them to the west",
"bank",    "Mostly damp forest earth, with a few partially exposed round, grey rocks",
"tree",    "Host to the strangler fig, the maple tree will not live long",

});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({
   "/players/fakir/woods/room13.c", "south",
     
});
}
init()  {
  ::init();
    add_action("push_bushes","push");
    add_action("climb_roots","climb");
}
push_bushes(str)  {
if(str != "bushes") {
notify_fail("You cannot do that.\n");
return 0; 
}
tell_room("players/fakir/woods/room25.c", this_player()->query_name()+" arrives.\n");
move_object(this_player(),"/players/fakir/woods/room25.c");
command("look",this_player());
return 1;
}
climb_roots(str)  {
if(str !="roots") {
notify_fail("You cannot climb that!\n");
return 0;
}
tell_room("players/fakir/woods/room31.c", this_player()->query_name()+" arrives.\n");
move_object(this_player(),"/players/fakir/woods/room31.c");
command("look",this_player());
return 1;
}

