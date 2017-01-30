#define tp this_player()
#define eo environment(this_object())
#define tpn tp->query_real_name()
#define tl tp->query_level()
#define eeo environment(eo)
#define etp environment(tp)
#include "/players/mythos/closed/ansi.h"

inherit "obj/weapon";
int prev;
object attprev;
int setting;

query_save_flag() { return 0; } /* SAVEABLE */

reset(arg) {
::reset(arg);
  if(arg) return;
  set_name("defender");
  set_short(RED+"Defender"+NORM);
  set_alias("blade");
  set_alt_name("sword");
  set_long("A \n");
  set_read(":: mode :::: defence :: enforce ::\n");
  set_value(10000);
  set_weight(2);
  set_class(18);
  prev = 0;
  attprev = 0;
  setting = 0;
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  if((tp->query_stat("pie") + tp->query_stat("int")) > random(110)) {
    if(attprev != attacker) {  attprev = attacker; prev = 0; }
    if(!prev) {
      prev = 5 + random(4);
      if(!setting) {
      attacker->set_wc(attacker->query_wc() - prev);
      tp->set_ac(tp->query_ac() + prev); }
      else { attacker->set_ac(attacker->query_ac() - prev); } 
    } else {
      if(!setting) {
      attacker->set_wc(attacker->query_wc() + prev);
      tp->set_ac(tp->query_ac() - prev); }
      else { attacker->set_ac(attacker->query_ac() + prev); }
      prev = 0; 
    }
  return 5; }
}

init() { 
  ::init();
  add_action("mode","mode");
}

mode(str) { 
  if(!str) return 0;
  if(str == "defense") {
    write("The blade is now in defensive mode.\n");
    set_short(RED+"Defender"+NORM);
    set_name("defender");
  }
  if(str == "enforce") {
    write("The blade is now in enforce mode.\n");
    set_short(BOLD+"Enforcer"+NORM);
    set_name("enforcer");
  }
return 1; }