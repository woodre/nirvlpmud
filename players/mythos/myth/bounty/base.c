#include "/players/mythos/myth/bounty/def.h"
inherit "players/mythos/myth/base";
int dm;

id(str) { return str == "cloak" || str == "bounty_hunter" ||
                 str == "bgo" || str == "MYTHOSSYSOBJ"; }

query_auto_load() { return "/players/mythos/bounty/cloak.c:"; }

short() { return RED+"Hunter's Cloak"+NORM; }

long() {
   write("\n");
   write("myth_help will bring up the help files\n");
}

reset(arg) {
::reset(arg);
  if(arg) return;
  dm = 0;
  whatob = "bounty";
}

init() {
::init();
  if(tp == ep) {
    
    if(dm) { 
    clone_object("/players/mythos/closed/guild/tlight.c")->start_see_shadow(tp);
    } else if(level > (MAX)*1/2) level = (MAX)*1/2; 
    add_action("enhance","benhance");
    add_action("tele_officer","grounding");
    add_action("ration","ration");
    add_action("grenade","grenade");
    add_action("note","check_note");
  }
}       

help() {
  cat("/players/mythos/myth/bounty/HELP");
  write("\n");
}

/* POWER material */

note() { POWER->note(); return 1; }
enhance(str) { POWER->enhance(str); return 1; }
tele_officer() { POWER->tele_officer(); return 1; }
ration(str) { POWER->ration(str); return 1; }
grenade(n) { POWER->grenade(n); return 1; }

