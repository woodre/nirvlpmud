#include "/players/mythos/myth/thief/def.h"
inherit "players/mythos/myth/base";

id(str) { return str == "tob" || str == "thieves_tools" ||
                 str == "tools" || str == "MYTHOSSYSOBJ"; }
                 
query_auto_load() { return "/players/mythos/myth/thief/base.c:"; }

short() { return "Thieves' Tools"; }

long() {
   write("\n");
   write("myth_help will bring up the help files\n");
}

reset(arg) {
::reset(arg);
  if(arg) return;
  whatob = "thief";
}

init() {
::init();
  if(tp == ep) {
  
    /* replacement or overlay of normal actions in game */
    
    add_action("wield","wield");
    add_action("wield","wear);
    
    call_out("block",5);
  }
}

block() {
  if(!ep) return 1;
  move_object(this_object(),ep);
  call_out("block",3);
return 1; }

wield(str) {
object dod;
  if(!str) return 0;
  dod = present(str,ep);
  if(!dod) { 
    write("You do not have that.\n");
  return 1; }
  if(dod->weapon_class() || dod->armor_class()) {
    if(dod->query_weight() > 1) {
      write("As a thief you may not use that.\n");
    return 1; }
  }
}

/* POWER material */
