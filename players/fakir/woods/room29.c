#define TP this_player()
#define TPN this_player()->query_name()
#include "/players/fakir/color.h"
#define TPP this_player()->query_possessive()
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "An Oak";
long_desc =
"A large and mighty oak rises from the ground, its base a tangle of thick\n"+
"strong roots anchored firmly in the earth.  Its bark is scared black in\n"+
"places, as if attacked by lightning.  It's long branches spread out like\n"+
"open arms, and show no sign of burns nor marks as does the trunk.  Green\n"+
"leaves grow from every branch and twig, and rustle and sway with the wind,\n"+
"giving the oak an appearance of animation and true life.\n";

items = ({
"oak",    "A mighty oak tree, suitable for climbing if one wished to do so",
"ground", "You cannot see the ground.  Too many leaves litter its surface",
"base",   "The base of the oak, where it meets the earth",
"roots",  "Branching out from the base of the trunk, they extend a few\n"+
          "feet outward and then burrow deeply into the earth",
"bark",   "It is scarred black as if by fire or lightning in places.\n"+
          "There are some 'carvings' in the bark as well",
"carvings",  "The carvings say:\n\n"+
          "The Shadow shall rise across the world, and darken\n\n"+
          "every land, even to the smallest corner, and there\n\n"+
          "shall be neither Light nor safety.  And he who shall\n\n"+
          "be born of the Dawn, born of the Maiden, according to\n\n"+
          "Prophecy, he shall stretch forth his hands to catch\n\n"+
          "the Shadow, and the world shall scream in the pain of\n\n"+
          "salvation.  All Glory be to the Creator, and to the\n\n"+
          "Light, and to he who shall be born again.  May the\n\n"+
          "Light save us from him.\n\n",
"branches","Covered in leaves green with life",
"twig",    "Covered in leaves green with life",
"trunk",   "Covered in scared bark burned black, perhaps by lightning",
"leaves",  "Green and healthy, they grow on every branch and twig",



});
if(!present("weasel",this_object()))
 move_object(clone_object("/players/fakir/woods/NPC/weasel.c"),this_object());
dest_dir = ({
   "/players/fakir/woods/room14.c", "north",
   
});
}
init()  {
  ::init();
    add_action("climb_oak","climb");
}
climb_oak(str)  {
if(str != "oak") {
notify_fail("You cannot climb that.\n");
return 0; 
}
tell_room("players/fakir/woods/room30.c", this_player()->query_name()+" arrives.\n");
move_object(this_player(),"/players/fakir/woods/room30.c");
command("look",this_player());
return 1;
}


