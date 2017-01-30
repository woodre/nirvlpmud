#include "/players/mythos/closed/guild/def.h"
#define memcurse  "players/mythos/closed/guild/cursed/"
string feed, food;

id(str) { return str == "cursed" || str == "feeder"; }

/*
query_auto_load() { return "/players/mythos/closed/guild/curse.c:"; }
*/

get() { return 0; }
drop() { return 1;}

reset(arg) {
  if(arg) return;
  return;
}

/*
init_arg() { restore_object(memcurse+tpn); }

init() {
  restore_object(memcurse+tpn);
  call_out("cursed", 100);
}
*/

set_feeder(str) { feed = str; }
set_food(str) { food = str; }
savecurse() { save_object(memcurse+tpn); }

cursed() {
object dark;
int blood;
  if(feed)
  dark = find_player(feed);
  if(dark) {
    blood = 100 + random(100);
    ep->add_exp(-blood);
    dark->add_exp(blood);
    tell_object(ep,"You feel weaker, as if something \n"+
                   "was sapping your vitality.\n");
    tell_object(dark,"You feel good as you feed on "+capitalize(food)+".\n");
    }
  if ( environment() && living(environment(this_object())) )
     call_out("cursed",100+random(100));
return 1;}

exit() {
  if(this_player() == environment(this_object())) return 1;
  if(this_player() && this_player()->query_level() > 90) return 0;
    else return 1;
}
