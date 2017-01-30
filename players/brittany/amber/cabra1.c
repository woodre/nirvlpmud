#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;

reset(arg) {

if(!present("joplin", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/brittany/amber/joplin.c"),
      this_object());
    }
  }
   if(arg) return;
   set_light(0);
   
   short_desc = GRY+"Lighthouse"+NORM;
   long_desc =
   "     You are inside the lighthouse, it is high, wide, heavy, and\n"+
   "watertight made of concrete.  You are standing in the small living\n"+
   "room.  A eat-in kitchen is straight ahead of you, with the kitchen\n"+
   "off to the right of that.  A room is to the left of you.\n";
   
   items = ({
         "room","A room with a medium size bed inside.",
         "kitchen","A small eat-in area with a table and four chairs.  The kitchen\n"+
         "have a countertop with small cabinets above, a stove and a refrigerator",
         });

   dest_dir = ({
         "players/brittany/amber/cabra.c","out",
          });
   }

   
init(){
::init();
add_action("out","out");
add_action("search","search");
}

out(str){
  tp->move_player("out#/players/brittany/amber/cabra.c");
  return 1; }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}