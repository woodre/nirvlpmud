#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include <ansi.h>

int peeps;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "The Caves of the "+HIG+"Green "+NORM+GRN+"Dragon Clan"+NORM;
long_desc =
" You stand on a huge outcropping of rock. Looking over the\n"+
"edge you see the molten core of the volcano. To the west is\n"+
"the path leading around the volcanoes edge.\n";

items = ({
"core",
"The molten core of the center of the volcano. It is a huge\n"+
"bubbling mass of glowing red liquid rock",
"path",
"A narrow stone path that leads around the volcanoes core",
"molten rock",
"A bubbling mass of liquified stone",
"edge",
"A short rocky edge that overlooks the molten rock below"
});

dest_dir = ({
  "/players/dragnar/SevenSpires/rooms/gdragon/r16.c","west",
});

}
/* Thanks Feldegast for providing an easy template for messages */
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
    case 0: msg= HIR+"Flames"+NORM+" swirl about the outcropping.\n"; break;
    case 1: msg= "The core seethes far below you.\n"; break;
    case 2: msg= "The terrible heat rises in waves all around you.\n"; break;
    case 3: msg= "Volcanic lava flows about the core far below.\n"; break;
    }
  tell_room(this_object(),msg);
  call_out("flames", random(10) + 3); 
  }
