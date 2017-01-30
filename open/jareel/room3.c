#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "A brush pile";
long_desc =
"The green moss grows thin and more leaves litter the ground.  A small brush\n"+
"pile is stacked here as if someone were planning a large fire of some kind.\n"+
"The blue sky is dotted with puffy white clouds and this small break in the\n"+
"woods is a welcome sight.  A very large tree is to the west.  Faint wagon\n"+
"tracks can be seen heading east through the leaves.\n";

items = ({
"moss",   "Creeping out in fingers of such vibrant green, it almost glows in the sunlight",
"leaves", "Mostly dead and fallen from the surrounding trees",
"ground", "Showing only in a few bare places, it is a rich dark forest loam", 
"tree",   "It is a giant tree growing up through the canopy of the woods",
"pile",   "A large pile of dead limbs and odd branches. You should 'search' it",
"sky",    "Clear blue but for some white clouds",
"clouds", "The puffy white kind that take on funny shapes and sometimes look like people",
"woods",  "Trees and bushes all around you now, far as you can see",
"tracks", "The ruts left by the wheels of a flatbed wagon used to haul logs",


});

dest_dir = ({
   "/players/fakir/woods/room21.c", "east",
   "/players/fakir/woods/room2.c", "west",
   "/players/fakir/woods/room4.c", "northeast",
});
}

init()  {
  ::init();
    add_action("search_pile","search");
}
search_pile(str)  {
if(str && str != "pile") {
notify_fail("You find nothing when you search there.\n");
return 0; 
}
if(found) { write("You find nothing.\n"); 
return 1; }
write("You search the brush pile and find someone hiding inside it!\n");
move_object(clone_object("/players/fakir/woods/NPC/brownie.c"),this_object());
 found = 1; return 1; 

}

