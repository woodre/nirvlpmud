inherit "/obj/weapon.c";
#include "/players/zeus/closed/all.h"

reset(arg) {
   ::reset(arg);
   if (arg) return;

  set_name("sword");
  set_short("A broad sword");
  set_long(
"This is a battered old broad sword.  The edges are not terribly\n"+
"sharp anymore, and in numerous places there are small pieces\n"+
"that have broken off.  It was once a great weapon.\n");
  set_type("sword");
  set_value(700);
  set_weight(3);
  set_class(15);
  set_read("There is nothing to read on the sword.\n");
  add_wear(201);
  set_hit_func(TO);
}
int weapon_hit(object target){

  if(random(100)<=10) {
  write("You slash your enemy with the broad sword!\n");
  say(environment(TO)->QN+
          " slashes "+TP->POS+" enemy with "+TP->POS+" broad sword!\n");
return 6; }
}
