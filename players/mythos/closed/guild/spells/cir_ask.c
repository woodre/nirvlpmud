#include "/players/mythos/closed/guild/def.h"
string caster,p;
id(str) {return str == "cir_ask"; }

drop() {return 1; }

query_weight() {return 0;}
query_value() {return 0; }

set_caster(str) { caster = str; }

init() {
  if(!(ep->query_npc())) {
    tell_object(ep,capitalize(caster)+" wishes to create a grand circle with you.\n"+
          "Will you allow it? <y/n>  ");
    input_to("aanswer");
    }
}

aanswer(p) {
int co;
  if(p == "y") {
  tell_object(find_player(caster),epn+" accepts the circle.\n");
  tell_object(ep, "You have become a member of the circle!\n"); 
  co = present("count",find_player(caster))->query_count();
  present("count",find_player(caster))->set_count(1 + co);
  }
  else {
  tell_object(find_player(caster),epn+" refuses the circle.\n");
  tell_object(ep,"You turn down the circle...\n"); 
  destruct(this_object()); }
return 1;}
