/* DarK ArenA prototype */

inherit "room/room.c";
#include "defs.h"
 
reset(arg){
 
if(!present("cave bear"))  {
move_object(clone_object("/players/snow/MONSTERS/cave_bear.c"),this_object());                                    }
 
 if(!arg){

 short_desc="ProtoDark";
 long_desc=
 "This is a prototype of the \n\
  Dark Arena.\n";
 
items=({
 "item1", "a desc of item1",
});
 
  dest_dir=({
  "/players/snow/workroom.c","work"});
  }   }
 
init()  {
 ::init();
  add_action("dark_cmds","dark");
  add_action("dark_voice","dvoice");
  TP->set_fight_area();
         }
 
dark_cmds(str) { BASE->dark_cmds(str); RE; }
dark_voice(str) { BASE->dark_voice(str); RE; }
random_creation(str) { return BASE->random_creation(str); }
realm() { return "NT"; }
query_darena() { return "boo"; }
