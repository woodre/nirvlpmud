#define TP this_player()
#define TPN this_player()->query_name()
#include "/players/fakir/color.h"
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
found = 1+random(3);
set_light(1);

short_desc = "Clearing in Whispering Woods";
long_desc =
"Far in the north a rock cliff rises some distance into the skyline.  Short\n"+
"grass and a few small bushes blend into the treeline west...but the lodgepole\n"+
"pine and spruce grow so close together east and south as to make passage that\n"+
"way impossible.  Small mounds of brown earth, some very freshly dug, spot the\n"+
"clearing.  Tiny footprints can be seen on the path leading west into the woods\n"+
"and north toward the cliff.\n";
items = ({
"spruce",  "Shaped like an upside down snow cone, they grow close together",
"pine",    "Thin trunked and tall, they grow so close together passage\n"+
           "through them is impossible but for the smallest of creatures",
"mounds",  "The dirt pushed up from below by small creatures called\n"+
           "'Brown Diggers', or just 'Diggers' for short.  Maybe you\n"+
           "could 'dig' up a few diggers if you tried",
"footprints","So small and faint you can barely make them out, but they must\n"+
             "belong to very delicate feet",
"grass",   "Broadleaf meadow grass, very course and rather rough",
"clearing","Mostly grass and scattered wild flowers, it is surrounded by the\n"+
           "woods on all sides, except here where it meets the lakeshore",
"cliff",   "It boarders the horizon to the north",
"treeline","To the west they look like maple, alder, and ash mixed together.  Those\n"+
           "to the east are lodgepole pine.  South are spoty groups of spuce and pine",
"path",    "A dirt path that wanders through the short grass and bushes of the clearing",
"bushes",  "Gooseberry, Ticklebush, and a few Vine Maple",


});

dest_dir = ({
   "/players/fakir/woods/room12.c", "north",
   "/players/fakir/woods/room13.c", "west",
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


