#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include <ansi.h>
int i;

reset(arg) {
if(!present("darkling", this_object())){
for(i = 0; i < 4; i++){
 move_object(clone_object("/players/dragnar/SevenSpires/mons/gdragon/darkling"), this_object());
 } 
}
  if(arg) return;
set_light(1);

short_desc = "The Caves of the "+HIG+"Green "+NORM+GRN+"Dragon Clan"+NORM;
long_desc =
"  Here the cave opens up into a larger cavern, the ceiling\n"+
"far overhead and lost in darkness. The walls here are warm\n"+
"to the touch, as if the heat of the earth is running behind\n"+
"them. To the west the caves tunnel continues, leading further\n"+
"into darkness. To the north is a smaller tunnel, and to the\n"+
"east is the mouth of the cave leading out.\n";

items = ({
  "ceiling",
  "A high rock ceiling. Most of it is lost in darkness",
  "rock",
  "A black stone that seems to be very porous and somewhat\n"+
  "brittle",
  "darkness",
  "An impenetrable darkness that seems to hover over the ceiling",
  "walls",
  "Formed from a black stone, they seem very warm to the touch",
});

dest_dir = ({
  "/players/dragnar/SevenSpires/rooms/gdragon/r3.c","north",
  "/players/dragnar/SevenSpires/rooms/gdragon/r1.c","east",
  "/players/dragnar/SevenSpires/rooms/gdragon/r5.c","west",
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
    case 0: msg= "Dark things flutter overhead in the darkness.\n"; break;
    case 1: msg= "Shadows flow, expand, and retract, as you watch.\n"; break;
    case 2: msg= "Something cold flows from the northern tunnel.\n"; break;
    case 3: msg= "A small creature flies within the shadows overhead.\n"; break;
    }
  tell_room(this_object(),msg);
  call_out("flames", random(10) + 3); 
  }

