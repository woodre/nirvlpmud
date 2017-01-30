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
"A short willow tree grows from the moist earth and its branches encircle\n"+
"you, hanging like a curtain blocking out all else.  Greenish leaves rustle\n"+
"slightly as a soft wind blows through, causing the long, thin limbs to sway\n"+
"as if alive.  The trunk is solid and healthy, though only eight feet in\n"+
"height before the limbs begin to branch out.  The bark of the willow is\n"+
"white with dark brown highlights in short vertical blotches.  Something\n"+
"about the bark catches your eye and causes you to take a closer look.\n";

items = ({
"tree",     "A common black willow tree, with long droopy branches reaching almost to the ground",
"earth",    "Dark and rich from centuries of falling leaves.  It is moist from a spring nearby",
"branches", "Thin and spindly, they entwine each other and sway with the wind",
"curtain",  "The branches seem to create a type of curtain which surrounds you like a blanket",
"leaves",   "Long and thin, shaped like the blade of a small throwing knife or\n"+
            "dagger.  They rustle slightly as if someone were hiding there",
"limbs",    "Thin and spindly, they entwine each other and sway with the wind",
"trunk",    "About eight feet in height and three feet in diameter",
"bark",     "The smooth white and brown bark has been blemished by the blade of a knife.\n"+
            "There are some 'letters' carved into the trunk of the tree from long ago",
"letters",  "The letters read thus:\n\n\n"+
            "Defeat, my Defeat, my shining sword and shield,\n\n"+
            "In your eyes I have read\n\n"+
            "That to be enthroned is to be enslaved,\n\n"+
            "And to be understood is to be leveled down,\n\n"+
            "And to be grasped is but to reach one's fullness\n\n"+
            "And like a ripe fruit to fall and be consumed\n\n\n",
});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc5.c"),this_object());

dest_dir = ({
   "/players/fakir/woods/room6.c", "south",
   "/players/fakir/woods/room8.c", "northeast",
   
});
}

init()  {
  ::init();
    add_action("search_leaves","search");
}
search_leaves(str)  {
if(str && str != "leaves") {
notify_fail("You find nothing when you search there.\n");
return 0; 
}
if(found) { write("You find nothing.\n"); 
return 1; }
write("You search the leaves and find some fairy folk playing hide and seek!\n");
move_object(clone_object("/players/fakir/woods/NPC/sprite.c"),this_object());
move_object(clone_object("/players/fakir/woods/NPC/brownie.c"),this_object());
move_object(clone_object("/players/fakir/woods/NPC/sprite.c"),this_object());
 found = 1; return 1; 

}

