/*****************************************************/
/*                                                   */
/*        Approved by Snow on 8.19.99                */
/*                                                   */
/*****************************************************/
inherit "obj/armor";
#include "/players/zeus/closed/all.h"

reset(arg){
   ::reset(arg);
   if(arg) return;

   set_name("onyx platemail");
   set_alias("platemail");
   set_short(BOLD+BLK+"Legendary Onyx Platemail"+NORM);
   set_long(
"The onyx platemail is a legendary piece of armor.  It glows with a dark\n"+
"aura of power.  It is incredibly durable, well built, and does not hinder\n"+
"the wearers movement.  This armor is fit for the mightiest of warriors.\n");
   set_type("armor");
   set_ac(5);
   set_weight(5);
   set_value(1120);
}

/*
query_save_flag(){    return 1; }
query_dest_flag() { return 1; }
2005.02.19 Forbin */

do_special(owner) {
  object att;
  if(!owner || !owner->query_attack()) return 1;
  if(!owner->is_player()) return 1;
  att = owner->query_attack();
  if(att->query_wc() > 20 && owner->query_alignment() < -200 &&
	  owner->query_attrib("mag") > random(60)){
  tell_object(owner, BOLD+BLK+
  "Your platemail radiates an aura of power!\n"+NORM);
  owner->add_spell_point(3); return 1; }
  return 0; }
