/*
File: wgauntlet.c
Author: Feldegast @ nirvana.mudservices.com
Date: 2/13/01
Description
  Gauntlets of Wraithkind.  The special, based upon wil, drains
the attacker's hp, and heals the defender.  Found on the revenant
in Caladon.
*/
#include "defs.h"

inherit "/obj/armor.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("gauntlets");
  set_alias("gauntlet");
  set_short("Gauntlets of "+MAG+"Wraith"+BOLD+BLK+"kind"+NORM);
  set_long(
    "This is a pair of coal-black metal gauntlets with metal spikes\n"+
    "affixed to the knuckles and circling the wrist.\n"
  );
  set_ac(1);
  set_type("gloves");
  set_weight(2);
  set_value(2000);
}

int do_special(object owner) {
  int amt;
  if((int)owner->query_attrib("wil") > random(200)) {
    tell_object(owner, "You grasp "+(int)this_player()->query_name()+" with your "+short_desc+"!\n"+
                       HIM+"\t"+capitalize((string)this_player()->query_possessive())+" life becomes yours!\n"+NORM);
    write((string)owner->query_name()+" grasps you with "+short_desc+"!\n"+
          HIM+"\tYour life becomes "+(string)owner->query_possessive()+"!\n"+NORM);

    amt=1+random(2);

    if((int)this_player()->is_player())
       this_player()->add_hit_point(-amt);
    else
       this_player()->heal_self(-amt);

    if((int)owner->is_player()) {
      owner->add_hit_point(amt);
      owner->add_spell_point(-1);
    }
    else
      owner->heal_self(amt);
    return 0;
  }
}
