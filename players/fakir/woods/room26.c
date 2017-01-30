#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
found = 1+random(3);
set_light(1);

short_desc = "Whispering Woods";
long_desc =
"Green leafy trees and a few maple and alder grow together in this\n"+
"sparsely populated area of the woods.  Tall bushes and colorful\n"+
"flowers grow in select clumps all about, and block the view of what\n"+
"must lie beyond.  There are a few mounds of fresh dirt over by the\n"+
"flowers.\n";

items = ({
"trees",   "Tall and slender and of a slightly different sort than in the other parts\n"+
           "of the wood.  These have bright red and yellow leaves, and purple branches",
"woods",   "The Whispering Woods",
"flowers", "Bright colored blossoms with tall green stems and leaves.  They are so thick\n"+
           "and plentiful",
"maple",   "The maple trees are rather pear shaped and have symmetrical three fingered leaves",
"alder",   "The alder trees look very much like the maple, but not as broad at the top",
"bushes",  "Some have prickly leaves like holly, with little gold berries at the top",
"flowers", "Oleander, nightshade, laurel and other blooming varieties",
"mounds",  "The dirt pushed up from below by small creatures called\n"+
           "'Brown Diggers', or just 'Diggers' for short.  Maybe you\n"+
           "could 'dig' up a few diggers if you tried",

 
});

dest_dir = ({
   "/players/fakir/woods/room23.c", "west",
   "/players/fakir/woods/room19.c", "south",
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



