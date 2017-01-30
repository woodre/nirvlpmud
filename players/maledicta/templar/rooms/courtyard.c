#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Courtyard "+HIW+"["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc = 
"  This is a very large courtyard.  In the center is a massive\n"+
"fountain with a statue of a man sitting upon a horse over it.\n"+
"High walls surround the grounds, lending a fair amount of\n"+
"protection.  To the south is a gatehouse leading out into the\n"+
"wilds. To the west is the armorer, and to the east is the\n"+
"weaponsmith. A large stone building stands to the north, a\n"+
"set of double doors leading into it.  A large building houses\n"+
"the stables to the southwest.\n";

items = ({
"stables",
"The Templar stables. There, if you are a knight, you can get a horse",
"fountain",
"A huge fountain made of marble. A large statue stands over it\n"+
"like a guardian. You notice a small plaque at its base",
"statue",
"A large bronze statue of a man in full armor sitting upon the\n"+
"largest most majestic horse you have ever seen",
"walls",
"Stone walls that tower high over the courtyard",
"building",
"A well fortified building made of stone and covered with arrow-slits\n"+
"and decorative stone works",
"plaque",
"You look closely and see that the plaque has ancient words upon its\n"+
"surface, but you cannot make them out",
"doors",
"Heavy steel doors that protect the inner sanctum of the knights",
});

dest_dir = ({
  "/players/maledicta/templar/rooms/gatehouse.c","south",
  "/players/maledicta/templar/rooms/main.c","north",
  "/players/maledicta/templar/rooms/armory.c","west",
  "/players/maledicta/templar/rooms/weaponry.c","east",
  "/players/vertebraker/misc/s1.c", "southwest",
});

}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

