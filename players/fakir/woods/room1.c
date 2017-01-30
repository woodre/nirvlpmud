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
"Soft and forgiving, it swallows your feet almost to the ankles.  A fallen\n"+
"tree with dying branches has left a large hollow in the ground.  The once-\n"+
"buried roots now reach for the sky in a grotesque plea for nourishment,\n"+
"creating twisted images and shadowshapes of fairy folk from long distant\n"+
"childhood bedtime stories.  The Whispering Woods stretch out before you in\n"+
"scattered groves of trees mixed with large bushes and flowering plants of\n"+
"many sizes, shapes, and colors.  Surely the images you see in the roots of\n"+
"the fallen tree are only imaginary...\n";

items = ({
"moss",   "Creeping out in fingers of such vibrant green, it almost glows in the sunlight",
"ground", "Showing only in a few bare places, it is a rich dark forest loam", 
"feet",   "You cannot see your feet.  Your belly is far too large",
"tree",   "Blown down by a great wind perhaps...or maybe pushed over by a very large beast",
"branches","They are covered in silver leaves that once were green",
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
   
});
if(!present("brownie",this_object()))
 move_object(clone_object("/players/fakir/woods/NPC/brownie.c"),this_object());
if(!present("sprite",this_object()))
 move_object(clone_object("/players/fakir/woods/NPC/sprite.c"),this_object());
dest_dir = ({
   "/players/fakir/woods/room2.c", "north",
   "/room/eastroad5.c",            "wheel",
   
});
}

init()  {
  ::init();
    add_action("search_roots","search");
}
search_roots(arg)  {
if(!arg || arg != "roots") {
notify_fail("You search in the wrong place.\n");
return 0; 
}
if(found) { write("You find nothing.\n"); 
return 1; }
write("You search the tree roots and find someone hiding behind them!\n");
move_object(clone_object("/players/fakir/woods/NPC/pixie.c"),this_object());
 found = 1; return 1; 

}


