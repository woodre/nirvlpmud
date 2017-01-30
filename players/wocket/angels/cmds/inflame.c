#include "/players/wocket/closed/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
#define ATTACKER this_player()->query_attack()

int inflame(string str){
if(!this_player()->query_attack()){
  write("You must be in combat to cast inflame.\n");
  return 0;
}
if(this_player()->query_sp() < 35){
  notify_fail("You lack the harmony to cast inflame.\n");
  return 0;
}
this_player()->spell_object(ATTACKER,"inflame",13+random(26),35);
this_player()->add_hit_point(4+random(5));
}
