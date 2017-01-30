#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include <ansi.h>


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "The Caves of the "+HIG+"Green "+NORM+GRN+"Dragon Clan"+NORM;
long_desc =
"  You stand on a narrow path leading around the core of the\n"+
"volcano. Looking over the edge you see a huge lava pool far\n"+
"below. The path continues around west closer to the outcropping\n"+
"on the far side, or to the south and the entrance of the\n"+
"the core.\n"; 
items = ({
"core",
"The molten core of the center of the volcano. It is a huge\n"+
"bubbling mass of glowing red liquid rock",
"path",
"A narrow stone path that leads west and south around the\n"+
"volcanoes core",
"outcropping",
"A large stone outcropping that extends out and over the\n"+
"molten core of the volcano",
"molten rock",
"A bubbling mass of liquified stone",
"pool",
"A large pool of lave far below",
});

dest_dir = ({
  "/players/dragnar/SevenSpires/rooms/gdragon/r15.c","west",
  "/players/dragnar/SevenSpires/rooms/gdragon/r13.c","south",
});

}

/* Thanks Feldegast for providing an easy template for messages */

int peeps;

void init() {
  ::init();
  peeps++;
  if(find_call_out("flames") == -1)
   call_out("flames", random(10) + 3);
  }

void exit() {
  peeps--;
  if(peeps <= 0)
    while(remove_call_out("flames") != -1) ;
  }

void flames() {
  object ob,next;
  string msg;

  switch(random(4)) {
    case 0: msg= HIR+"Lava"+NORM+" burns brightly far below.\n"; break;
    case 1: msg= "The molten rock of the core flows about lazily.\n"; break;
    case 2: msg= "Red light, almost unbearable to see, reflects off of the walls.\n"; break;
    case 3: msg= "A heated gust of wind rises from the core and sweeps over you.\n"; break;
    }
  tell_room(this_object(),msg);
  call_out("flames", random(10) + 3); 
  }
