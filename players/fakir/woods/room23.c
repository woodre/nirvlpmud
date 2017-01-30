#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
found = 1+random(4);
set_light(1);

short_desc = "Whispering Woods";
long_desc =
"Green leafy trees and a few maple and alder grow together in this\n"+
"sparsely-populated area of the woods.  Many tall bushes and colorful\n"+
"flowers grow in select clumps all about, and block the view of what\n"+
"must lie beyond. Some mounds of dirt are clustered about the flowers.\n";

items = ({
"trees",   "Tall and slender and of a slightly different sort than in the other parts\n"+
           "of the wood.  These have bright red and yellow leaves, and purple branches",
"woods",   "The Whispering Woods",
"flowers", "Bright colored blossoms with tall green stems and leaves.  They are thick\n"+
           "and plentiful",
"maple",   "The maple trees are rather pear shaped and have symmetrical three fingered leaves",
"alder",   "The alder trees look very much like the maple, but not as broad at the top",
"bushes",  "Some have prickly leaves like holly, with little gold berries at the top",
"flowers", "Oleander, nightshade, laurel and other blooming varieties",
"mounds",  "The dirt pushed up from below by small creatures called\n"+
           "'Brown Diggers', or just 'Diggers' for short.  Maybe you\n"+
           "could 'dig' up a few diggers if you tried",

 
});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc1.c"),this_object());

dest_dir = ({
   "/players/fakir/woods/room6.c", "west",
   "/players/fakir/woods/room24.c", "north",
   "/players/fakir/woods/room22.c", "south",
   "/players/fakir/woods/room26.c", "east",
});
}
init()  {
  ::init();
    add_action("dig_digger","dig");
}
dig_digger(arg)  {
if(!arg || arg != "digger") {
notify_fail("You might be digging for the wrong animal.\n");
return 0; 
}
if(found==0) { write("All the diggers are hiding too deep in the ground now.\n"); 
return 1; }
if(present("digger",this_object())) {
write("You must kill this one before you dig another.\n");
return 1;
}
write("You dig deep into the brown mound of dirt and come up with a Digger!\n");
move_object(clone_object("/players/fakir/woods/NPC/digger.c"),this_object());
found=found-1; 
return 1; 

}



