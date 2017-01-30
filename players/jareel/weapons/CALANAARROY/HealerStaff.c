inherit "/obj/weapon.c";

/* Original code looped out so needed to re think this weapon from scratch
   Basic concept was much longer Dragnar condensed it into an array and made
   it super lean*/

#include "/players/jareel/define.h"
#define ME TP->query_possessive()
#define MEE TP->query_objective()

reset(arg){
  if(arg) return;
    ::reset(arg);
    
  set_alt_name("staff");
  set_alias("healing staff");
  set_name(YEL+"Revive, "+HIB+"Healing Staff of Virtue"+NORM);
  set_long(
    "Revive is a simple wooded staff engraved with simple ornate runes of healing.\n"+
    "It has helped many a clever healer recover in combat and it has made the foolish\n"+
    "suffer for not understanding the simple power that lies within.\n");
  set_read("staff\n");
  set_class(1);
  set_type("staff");
  set_weight(3);
  set_value(10000);
  set_hit_func(this_object());
}

init() {
   ::init();
}

status filter_armor( object ob ) {
  return (status) ob->query_worn();
}

weapon_hit(attacker) { 
  int a, b, i, siz;
  object *arm;
 
  a = 0;
  b = 0;

#ifndef __LDMUD__
  arm = filter_array( all_inventory(this_player()), "filter_armor", this_object() );
#else
  arm = filter( all_inventory(this_player()), "filter_armor", this_object() );
#endif
  siz = sizeof(arm);
  
  if(!attacker || !siz) 
    return;
    
  for( i=0; i < siz; i++ ) {
    arm[i]->do_special( this_player() );
  }  
  
}