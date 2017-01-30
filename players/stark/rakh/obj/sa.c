/*
  Shielding Aura
*/
inherit "obj/armor";
#include "/players/stark/defs.h"
#define GOB present("rakh_guild",TP)
int shieldlvl;
int aclevel;


reset(arg) {
  ::reset(arg);
  if(arg) return;
  shieldlvl=GOB->query_aura2_lvl();
  aclevel=1;
  if(shieldlvl>4){aclevel=2;}
  if(shieldlvl==10){aclevel=3;}
  set_name("armor_aura");
  set_alias("aura");
  set_weight(0);
  set_value(0);
  set_ac(0);
  set_type("guild");  /* armor,helmet,boots,ring,amulet,shield,misc  */
}

do_special(owner) {
   tell_object(owner, "Your aura flashes brightly for a moment...\n");
return aclevel;
}

drop(){return 1;}
get(){return 1;}