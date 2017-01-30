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
"A small outcrop of rock looks out over a shallow chasm to the northwest.\n"+
"Far in the distance you can see the north road winding its way to the\n"+
"small township of the Two Rivers.  This sudden view of such grandeur is\n"+
"unexpected. A rest from the long journey might be in order here.  A small\n"+
"clump of grass is only a step or two away and would make a fine resting\n"+
"place. You better search for critters first or who knows what you might\n"+
"sit down on.\n";

items = ({
"outcrop",   "A small group of large stones rising from the ground and projecting\n"+
             "over a small sort of cliff which boarders the woods on the northwest",
"rock",      "Just plain old grey rock like you see every day",
"chasm",     "More of a shallow plain, but the drop is quite steep at first",
"road",      "The main road leading from town to town and round about the realm",
"grass",     "It must have found purchase in a bit of soil somehow and grows green and\n"+
             "lush.  You better search the grass before you sit there",
});

dest_dir = ({
   "/players/fakir/woods/room4.c", "southeast",
   "/players/fakir/woods/room6.c", "east",
   
});
}

init()  {
  ::init();
    add_action("search_grass","search");
}
search_grass(str)  {
if(str && str != "grass") {
notify_fail("You find nothing when you search there.\n");
return 0; 
}
if(found) { write("You find nothing.\n"); 
return 1; }
write("You search the grass and wake a sleeping fairy!\n");
move_object(clone_object("/players/fakir/woods/NPC/fairy.c"),this_object());
 found = 1; return 1; 

}

