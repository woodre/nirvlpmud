/* Setup room for ChAoS realm */

#include "std.h"
#include "/players/snow/chaos/defs.h"

string short_desc, long_desc, items;

set_short(sh) { short_desc = sh; }
set_long(lo) { long_desc = lo; }

short() { return short_desc; }
id(str) {
  int i;
  if(!items) return;
  while(i < sizeof(items)) {
    if (items[i] == str) RE;
    i += 2;
  }
  return 0;
}
long(str) {
  int i;
  if(!str) write(long_desc);
  if(!items) return;
  i = 0;
  while(i < sizeof(items)) {
    if(items[i] == str) {
      write(items[i+1] + ".\n");
      return;
    }
  i += 2;
  }
}

realm() { return "NT"; }
query_chaos() { return "devour"; }

reset(arg) {
  if(arg) return;
}

init() {
  if(this_player()->is_player()) this_player()->set_fight_area();
  set_light(1);
  add_action("chaos_cmds","chaos");
  add_action("chaos_voice","voice");
  add_action("chaos_move","north");
  add_action("chaos_move","south");
  add_action("chaos_move","east");
  add_action("chaos_move","west");
  add_action("chaos_move","northeast");
  add_action("chaos_move","northwest");
  add_action("chaos_move","southeast");
  add_action("chaos_move","southwest");
  add_action("chaos_move","up");
  add_action("chaos_move","down");
  add_action("jump_out","jumpout");
  if(this_player()->is_player()) call_out("wandering", 1);
}

exit() { if(this_player()) if(this_player()->is_player()) this_player()->clear_fight_area(); }
 
chaos_cmds(str) { BASE->chaos_cmds(str); RE; }
chaos_voice(str) { BASE->chaos_voice(str); RE; }
jump_out() { BASE->jump_out(); RE; }
chaos_move() { BASE->chaos_move(); RE; }
random_creation(str) { return BASE->random_creation(str); }
 
wandering() {
  object chc, monst;
chc = present("chaoscreature");
 if(!chc && random(100) < APPEAR) {
    TR(TO,"The ChAoS gives birth to another monster!\n");
    MO(clone_object(random_creation("monster")),TO);
   return 1;
 }
return 1;
}
