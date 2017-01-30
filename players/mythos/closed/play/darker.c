#include "/players/mythos/closed/ansi.h"
#define user environment(this_object())

query_auto_load() {
    return "/players/mythos/closed/play/darker.c:"; }
id(str) {return str == "dark"; }
drop() {return 1;}
init() {
  call_out("hb",3);
}

hb() {
    call_other(user,"add_spell_point",-2);
    call_other(user,"add_hit_point",-2);
    tell_object(user,"You feel the "+BOLD+"DARKNESS"+NORM+
                 " tug at your soul...\n");
    tell_object(user,"You think you may have lost 1 or 2 hp"+
                       " and sp from your soul....\n");
    call_out("hb",3);
return 1;
}

