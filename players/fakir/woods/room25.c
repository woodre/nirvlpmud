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
"Maple, alder, and ash trees grow thickly here, their trunks so close\n"+
"together it is almost impossible to find a way through.  The air is cool\n"+
"and slightly damp.  Clumps of ferns and bushes grow in such abundance\n"+
"they create a barrier in almost every direction. The ground is rich and\n"+
"damp here, perfect conditions for mushrooms to grow\n";

items = ({

"ferns",   "Deep green and bushy, they grow in abundance around the trunks of the trees",
"trees",   "The trees all blend in together, but you can tell they are maple, alder, and ash",
"ground",  "Rich dark loam like that found in most wooded areas",
"maple",   "The maple trees are rather pear shaped and symetrical three fingered leaves",
"alder",   "The alder trees look very much like the maple, but not as broad at the top",
"ash",     "The ash trees are oval in shape, and have small delicate leaves of silver and green",
"trunks",  "They are so close together it is hard to tell one from another",
"bushes",  "Gooseberry, rhododendrons in full bloom, wild grape and a few vine maple.\n"+
           "You might be able to 'push' your way through them to the east and southwest",
"bank",    "Mostly damp forest earth, with a few partially exposed round, grey rocks",
"mushrooms","Often found in moist earth such as this, perhaps if you were to try\n"+
            "to 'pick' a couple...",


});
if(!present("brownie",this_object()))
 move_object(clone_object("/players/fakir/woods/NPC/brownie.c"),this_object());
if(!present("imp2",this_object()))
 move_object(clone_object("/players/fakir/woods/NPC/imp2.c"),this_object());
dest_dir = ({
   "/players/fakir/woods/room24.c", "west",
     
});
}
init()  {
  ::init();
    add_action("pick_mushroom","pick");
}
pick_mushroom(arg)  {
if(!arg || arg != "mushroom") {
notify_fail("You cannot possibly pick that here.\n");
return 0; 
}
if(found==0) { write("All the mushrooms have been picked.  Come back later.\n"); 
return 1;
}
write("You reach down and pick a nice white mushroom!\n");
move_object(clone_object("/players/fakir/woods/OBJ/mushroom.c"),this_player());
found=found-1;
return 1; 
}


