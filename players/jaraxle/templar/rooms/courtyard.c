#include "/players/jaraxle/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIW+"Castle Courtyard ["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc = 
"  The courtyard is paved in cobblestones, circular in shape, and has\n"+
"a few benches set out for minglers. A granite statue depicting a war\n"+
"horse with no rider rearing up on his back legs stands at the center\n"+
"of a beautiful fountain. A golden plaque is at the base of the foun-\n"+
"tain, surrounded by flower pots with a variety of blooming flowers. A\n"+
"stable is visible to the southeast, while the gates to the fortress\n"+
"lie directly to the south. A manicured garden is to the west, and the\n"+
"local pub is to the east.\n";

items = ({
"image",
"A shimmering distorts the view to the southeast, it appears to be a\n"+
"magical link to elsewhere.",
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
"The plaque reads:\n"+
" \n"+
" In honor of our brothers and sisters whom we have lost. May your\n"+
"   swords strike true, and your heart lead you home once more",
"doors",
"Heavy steel doors that protect the inner sanctum of the knights",
});

move_object(clone_object("/players/jaraxle/closed/castle_lock.c"), this_object());
dest_dir = ({
  "/players/jaraxle/templar/rooms/main.c","north",
  "/players/jaraxle/templar/rooms/garden.c","west",
  "/players/jaraxle/closed/templar/squires/feast_hall.c","east",
  "/players/jaraxle/templar/rooms/s2.c","southeast",
  "/players/jaraxle/templar/rooms/library.c","northeast",
  "/players/jaraxle/templar/rooms/gatehouse.c","south",
});

}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

