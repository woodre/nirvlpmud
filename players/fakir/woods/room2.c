#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Whispering Woods";
long_desc =
"Dark green moss covers the moist ground like a thick carpet of lamb's wool.\n"+
"Soft and forgiving, it swallows your feet almost to the ankles.  A giant\n"+
"tree with hanging branches stands tall in the sun.  The branches almost\n"+
"brush the ground.  You may need to 'push' them back if they get too much\n"+
"in your way.  Ahead, the Whispering Woods stretch out before you in small\n"+
"groves of trees mixed with large bushes and flowering plants of many sizes,\n"+
"shapes, and colors.\n";

items = ({
"moss",   "Creeping out in fingers of such vibrant green, it almost glows in the sunlight",
"ground", "Showing only in a few bare places, it is a rich dark forest loam", 
"feet",   "You cant see your feet.  Your belly is far to large",
"tree",   "It is a giant tree growing up through the canopy of the woods",
"branches","They are covered in silver leaves that once were green. 'Push' them if you dare",
"hollow", "A depression at the base of the tree where the roots once drank from the earth",
"roots",  "A ball of twisting feelers vainly reaching for moisture. There is some movement\n"+
          "amongst the roots.  Maybe if you 'searched'",
"images", "Can these actually be real fairy folk like those you heard of as a child?",
"shadowshapes", "No more than fleeting movements amongst the roots",
"groves", "Small groups of trees and bushes",
"trees",  "Tall ones, short ones, skinny ones, fat ones. Trees of all shapes and sizes and colors",
"bushes", "Mostly short and round, some are covered in flowers, while others have leaves of green",
"plants", "Growing under the bushes and trees wherever a bit of sun shines through",
"shapes", "They look like Sprites, and Pixies...Imps and Fairies...with a Minion or two thrown in",
"sun",    "You cannot see the sun from here. It is blocked by all the trees",   
});
if(!present("minion",this_object()))
 move_object(clone_object("/players/fakir/woods/NPC/minion.c"),this_object());
if(!present("imp",this_object()))
 move_object(clone_object("/players/fakir/woods/NPC/imp.c"),this_object());
dest_dir = ({
   "/players/fakir/woods/room3.c", "east",
   "/players/fakir/woods/room1.c", "south",
   
});
}

init()  {
  ::init();
    add_action("push_branches","push");
}
push_branches(str)  {
if(str && str != "branches") {
notify_fail("You find nothing when you push there.\n");
return 0; 
}
if(found) { write("You find nothing.\n"); 
return 1; }
write("You push the tree branches and find someone hiding in them!\n");
move_object(clone_object("/players/fakir/woods/NPC/pixie.c"),this_object());
 found = 1; return 1; 

}

