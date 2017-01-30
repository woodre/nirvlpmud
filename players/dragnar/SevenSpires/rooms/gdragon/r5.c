#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include <ansi.h>


reset(arg) {
if(!present("cont_dragon", this_object())){
move_object(clone_object("/players/dragnar/SevenSpires/mons/gdragon/rdragon1"), this_object());
}
  if(arg) return;
set_light(1);

short_desc = "The Caves of the "+HIG+"Green "+NORM+GRN+"Dragon Clan"+NORM;
long_desc =
"  The tunnel here spreads outward into a vast area. The walls\n"+
"are smooth and warm to the touch, small amounts of steam rising\n"+
"out from cracks in them.  A large hole stands in the center of\n"+
"the room, a gush of hot air flowing from it. To the west is a\n"+
"long tunnel with a deep glow coming from it. To the south is\n"+
"a side chamber filled with darkness.\n";

items = ({
"walls",
"Smooth black walls that have a warmth flowing from it. Small\n"+
"cracks have formed along them with steam rising from each",
"steam",
"A small mist of hot steam",
"cracks",
"Deep cracks that have formed in the black stone walls",
"hole",
"A large hole that fills the center of the room. Steam rises\n"+
"from it in great gushes",
"air",
"A hot spray of air that fills the room",
"tunnel",
"A long glowing tunnel that leads deeper into the volcanic\n"+
"mountain",
});

dest_dir = ({
  "/players/dragnar/SevenSpires/rooms/gdragon/r7.c","south",
  "/players/dragnar/SevenSpires/rooms/gdragon/r2.c","east",
  "/players/dragnar/SevenSpires/rooms/gdragon/r6.c","west",
});

}

/* Thanks Feldegast for providing an easy template for messages */

int peeps;

void init() {
  ::init();
  peeps++;
  add_action("no_go", "west", 1);
  if(find_call_out("flames") == -1)
   call_out("flames", random(10) + 3);
  }

no_go(){
  if(present("cont_dragon", this_object())){
   write("The dragon slides in front of you and blocks entrance!\n");
   return 1;
   }
  return;
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
    case 0: msg= "Steam gushes out of a small crack with a *hiss*.\n"; break;
    case 1: msg= "*HISSSS* *SHHHHHH*\n"; break;
    case 2: msg= "Small rocks fall as the steam jets from a nearby crack.\n"; break;
    case 3: msg= "Steam rushes from the large hole, filling the room temporarily.\n"; break;
    }
  tell_room(this_object(),msg);
  call_out("flames", random(10) + 3); 
  }

