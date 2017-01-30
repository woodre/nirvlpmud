/* Limited randomly cloned ryos to 10 per reset - ill 2011-6-18 */
/*******************************************
  The commented out area will eventually 
  be put in.  However, the eggs are not
  finished....  but they will be..:>
*******************************************/
#include "/players/mythos/closed/guild/def.h"

inherit "room/room";
int z;
int ryos;
reset(arg) {
  ryos = 0;
  if(!present("ryo")) {
    move_object(clone_object("/players/mythos/amon/forest/ryo2.c"),this_object()); }
  if(!arg) {
  set_light(0);
    short_desc = "Forest";
    long_desc =
    "The forest is dark- very dark...light has trouble entering...  \n"+
    "in fact it is as if you have entered night.  The 'trees' are creepy\n"+
    "and seem to move in the dim light. You feel as if something is watching \n"+
    "you.....\n";
  items = ({
    "trees","Something fliters by you see a ryo",
    "rice","You can return to the rice patties",
    "east","The forest streches far as one can see",
  });

  dest_dir = ({
    "/players/mythos/aroom/forest/forestr.c", "north",
    "/players/mythos/aroom/forest/forestr.c","east",
    "/players/mythos/aroom/forest/forestr.c","south",
    "/players/mythos/aroom/forest/forestr.c","west",
  });
} }

init() {
  ::init();
  add_action("north","north" || "east" || "south" || "west");
  add_action("north","east");
  add_action("north","south");
  add_action("north","west");
  if(this_player()->query_npc() != 1) {
  if(present("egg")) {destruct(present("egg")); }
  z=random(13);
/*  if(z==0) {
  move_object(clone_object("/players/mythos/amisc/egg3.c"),this_object());
  return 1;}
  if(z==1) {
    move_object(clone_object("/players/mythos/amisc/egg4.c"),this_object());
  return 1;}
  if(z==2) {
     move_object(clone_object("/players/mythos/amisc/egg5.c"),this_object());
  return 1;}
  if(z==3) {
    move_object(clone_object("/players/mythos/amisc/egg6.c"),this_object());
  return 1; }
if(z==4) {
   
move_object(clone_object("/players/mythos/amisc/egg7.c"),"/players/mythos/aroom/forest/forestr.c");
  return 1;}  */
if(!max_liv() && ryos < 10) {
  if(z == 4 || z > 11) {
    object ob2;
      ryos++;
    ob2=clone_object("/players/mythos/amon/forest/ryo4.c");
    ob2->set_aggressive(1);
    move_object(ob2,this_object());
    write("You have angered the spirits in the forest by venturing further into this forest!\n");
  }
  if(z>5) {
    object ob;
    ob=clone_object("/players/mythos/amon/forest/ryo2.c");
    ryos++;
    ob->set_aggressive(1);
    move_object(ob,this_object());
    write("You have angered the spirits in the forest by venturing further into this forest!\n");
  return 1;}
}
    }
}

max_liv() {
object liv;
int o,p;
liv = all_inventory(this_object());
o = 0;
p = 0;
while(o<sizeof(liv)) {
  if(liv[o]->id("ryo")) p = p + 1;
o++;
}
if(p > 6) return 1;
return 0;
}

north() {
  int n;
  n = random(21);
  if(pp) { 
    if(n < 3) { n = 9;}
  }
  
  switch(n) {
    case 0: call_other(tp,"move_player","north#players/mythos/aroom/forest/forest4.c"); break;
    case 1: call_other(tp,"move_player","north#players/mythos/aroom/forest/forest5.c"); break;
    case 2: call_other(tp,"move_player","north#players/mythos/aroom/forest/forest7.c"); break;
	case 3: call_other(tp,"move_player","north#players/mythos/aroom/forest/forest8.c"); break;
	case 4: call_other(tp,"move_player","north#players/mythos/aroom/forest/foresto.c"); break;
	case 6:
	case 7: call_other(tp,"move_player","north#players/mythos/aroom/forest/forestr2.c"); break;
	case 8:
	case 9:
	case 10:
	case 11:
/* Changing access to the entering room only.  There needs to be a clear way to back out
 * when players see the "extremely dangerous" message
	case 12: call_other(tp,"move_player","north#players/mythos/closed/guild/forest/rooms/hunter.c"); break;
	case 13: call_other(tp,"move_player","north#players/mythos/closed/guild/forest/rooms/hunter3.c"); break;
	case 14: call_other(tp,"move_player","north#players/mythos/closed/guild/forest/rooms/hunter6.c"); break;
	case 15: 
	case 16: call_other(tp,"move_player","north#players/mythos/closed/guild/forest/rooms/huntera.c"); break;
*/
      case 12: case 13: case 14: case 15: case 16:
      call_other(tp,"move_player","north#players/mythos/closed/guild/forest/rooms/hunter.c");
      break;
	case 17:
	case 18:
	case 19:
	case 20: call_other(tp,"move_player","north#players/mythos/aroom/forest/forestr.c"); break;
  }
return 1;
}
