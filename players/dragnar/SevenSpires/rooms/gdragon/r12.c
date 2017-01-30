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
"  Here the tunnel slopes upward at a steep angle. A horrendous\n"+
"heat sweeps down from above on a strong current. The tunnel\n"+
"continues up to the west, or to a chamber to the east.\n";

items = ({
"walls",
"Smooth black volcanic rock walls. They are covered in several\n"+
"cracks that glow",
"cracks",
"Large cracks that have formed in the rock walls. Looking closer\n"+
"you see that lava flows from within, lending light and heat to\n"+
"the area",
"light",
"A glowing red light that is emitted from the cracks in the walls",
});

dest_dir = ({
  "/players/dragnar/SevenSpires/rooms/gdragon/r13.c","west",
  "/players/dragnar/SevenSpires/rooms/gdragon/r11.c","east",

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
    case 0: msg= "A rushing gust of super heated wind fills the tunnel!\n"; break;
    case 1: msg= "The howling of heated wind roars up ahead.\n"; break;
    case 2: msg= "There is a light hiss as steam slips from a crack.\n"; break;
    case 3: msg= "The light flickers slightly as molten rock flows.\n"; break;
    }
  tell_room(this_object(),msg);
  call_out("flames", random(10) + 3); 
  }
