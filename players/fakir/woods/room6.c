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
"The green leafy trees enfold you like a mother holds a child.  It is\n"+
"peaceful and quiet inside the woods.  Flowers grow here in abundance,\n"+
"perhaps due in part to the small spring bubbling up from the earth.\n"+
"The flowers are lovely. You might wish to 'pick' one.\n";

items = ({
"trees",   "Tall and slender and of a slightly different sort than in the other parts\n"+
           "of the wood.  These have bright red and yellow leaves, and purple branches",
"woods",   "The Whispering Woods",
"flowers", "Bright colored blossoms with tall green stems and leaves.  They are so thick\n"+
           "and plentiful",
"spring",  "A clear forest spring bubbling up from the ground creating a small pool",

 
});
if(!present("trolloc",this_object()))
 move_object(clone_object("/players/fakir/woods/TEMP/trolloc2.c"),this_object());
if(!present("imp",this_object()))
 move_object(clone_object("/players/fakir/woods/NPC/imp.c"),this_object());
dest_dir = ({
   "/players/fakir/woods/room5.c", "west",
   "/players/fakir/woods/room7.c", "north",
   "/players/fakir/woods/room23.c", "east",
});
}

init()  {
  ::init();
    add_action("pick_flower","pick");
}
pick_flower(str)  {
if(str && str != "flower") {
notify_fail("You cannot pick that.\n");
return 0; 
}
if(found) { write("You already picked a flower.  Dont be greedy.\n"); 
return 1; }
write("You pick a flower but it turns out to be...a pixie of all things!\n");
move_object(clone_object("/players/fakir/woods/NPC/pixie.c"),this_object());
 found = 1; return 1; 

}

