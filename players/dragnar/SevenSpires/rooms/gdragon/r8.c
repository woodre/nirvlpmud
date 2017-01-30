#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include <ansi.h>


reset(arg) {
if(!present("cont_dragon", this_object())){
move_object(clone_object("/players/dragnar/SevenSpires/mons/gdragon/rdragon1"), this_object());
move_object(clone_object("/players/dragnar/SevenSpires/mons/gdragon/rdragon1"), this_object());
}
  if(arg) return;
set_light(1);

short_desc = "The Caves of the "+HIG+"Green "+NORM+GRN+"Dragon Clan"+NORM;
long_desc =
" The tunnel here begins to turn sharply around the west\n"+
"corner. The walls here are made of a black stone with\n"+
"several glowing cracks throughout. The tunnel also leads\n"+
"to the east, back to the main chambers.\n";

items = ({
"walls",
"Black stone walls that have numerous cracks in them",
"cracks",
"Small cracks that have formed all over the surrounding walls. A\n"+
"terrible heat and light leak from within",
"light",
"Light that is created from the lava that flows from behind the\n"+
"walls",
"lava",
"A super-heated rock that flows from behind the walls",
"stone",
"A smooth volcanic stone",
});

dest_dir = ({
  "/players/dragnar/SevenSpires/rooms/gdragon/r6.c","east",
  "/players/dragnar/SevenSpires/rooms/gdragon/r9.c","west",
});

}

/* Thanks Feldegast for providing an easy template for messages */

int peeps;

void init() {
  ::init();
  add_action("no_west", "west", 1);
  peeps++;
  if(find_call_out("flames") == -1)
   call_out("flames", random(10) + 3);
  }

no_west(){
if(present("cont_dragon", this_object())){
write("The Green Dragon steps in front of you, blocking your entrance into the chamber!\n");
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
    case 0: msg= HIR+"Lava"+NORM+" light flows throughout the room.\n"; break;
    case 1: msg= "Molten rock leaks from a nearby crack and oozes onto the floor.\n"; break;
    case 2: msg= "There is a light hiss as steam slips from a crack.\n"; break;
    case 3: msg= "The light flickers slightly as molten rock flows.\n"; break;
    }
  tell_room(this_object(),msg);
  call_out("flames", random(10) + 3); 
  }
