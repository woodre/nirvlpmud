#include "/players/forbin/define.h"

inherit "obj/armor";

reset(arg) {
  set_name("padded leather armor");
  set_alias("leather");
  set_short(YEL+"Padded Leather Armor"+NORM);
  set_long(
    "A well made, but well worn piece of padded leather armor.  It is\n"+
    "very thick, yet extremely light for its bulk.  The dark brown\n"+
    "leather is stained with dark splotches and streaks in several\n"+
    "places but appears in good enough condition to adequately protect\n"+
    "its wearer from harm.\n");
  set_ac(4);
  set_type("main");  
  set_weight(1);
  set_value(2222);
}

int do_special(object owner) 
{
  if(!random(6)) 
  {
    tell_object(owner,
      "There is a "+HIW+"LOUD THUD"+NORM+
      " as your attacker's blow glances off the "+
      YEL+"Padded Leather Armor"+NORM+"!\n");
    tell_room(owner,
      "There is a "+HIW+"LOUD THUD"+NORM+
      " as "+(string)owner->query_name()+ 
      "'s attacker's blow glances off"+
      (string)owner->query_possessive()+YEL+" Padded Leather Armor"+NORM+"!\n", ({ owner}) );
    return 0;
  }
}
