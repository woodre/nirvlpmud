/*
Name: starfire.c
Author: Feldegast
Date: 12/21/01
Description:
  A unique weapon, awarded to Bone after he won a contest to
kill a level 19 player. (It was Pepino)
*/

#include "/players/feldegast/defines.h"

inherit "/obj/weapon.c";

void reset(int arg)
{
  if(arg) return;
  set_class(19);
  set_name("starfire sword");
  set_type("sword");
  set_short(BBLK+HIW+"Star"+HIR+"Fire"+NORM+BBLK+" Sword"+NORM);
  set_long(
"The StarFire Sword is a meter long length of metal, forged by\n"+
"the master swordsmith Aryn Starforge from the remains of a\n"+
"strange rock that fell to earth, destroying a small town.  The\n"+
"sword is exceptionally light and sharp, and glows softly with\n"+
"a strange, alien magic.\n"
  );
  set_weight(2);
  set_value(1200);
  set_hit_func(this_object());
}

int query_save_flag()
{
  if(!broke)
    return 0;
  else
    return 1;
}

int weapon_hit(object attacker)
{
  if(broke)
  {
    tell_object(TP, "The "+short_desc+"'s blade moves like quicksilver metal, repairing the break!\n"+NORM);
    broke = 0;
    command("unwield");
    command("wield starfire sword");
    return 0;
  }

  if(random((int)TP->query_attrib("int")) > 17)
  {
    tell_room(environment(TP),
TP->query_name()+"'s "+short_desc+" burns with a flash of light that hurtles at "+attacker->query_name()+"!\n");
    tell_room(environment(TP),
BBLK+HIR+"\n         *"+HIW+"    |    "+HIR+"*\n"+
"          *"+HIW+"   |   "+HIR+"*\n"+
"           *"+HIW+"  |  "+HIR+"*\n"+
"            *"+HIW+" | "+HIR+"*\n"+
HIW+"  - - - - - -("+HIY+"o"+HIW+")- - - - - - - \n");
    tell_room(environment(TP),
HIR+"            "+HIR+"*"+HIW+" | "+HIR+"*\n"+
"           *"+HIW+"  |  "+HIR+"*\n"+
"          *"+HIW+"   |   "+HIR+"*\n"+
"         *"+HIW+"    |    "+HIR+"*\n\n"+NORM
     );
     return 8;
  }
  if(random((int)TP->query_attrib("luc")) > 17)
  {
    write(BBLK+HIW+"Your sword glows brightly, bathing you in starlight.\n"+NORM);
    say(BBLK+HIW+TPN+"'s sword glows brightly, bathing "+objective(TP)+" in starlight.\n"+NORM);
    TP->heal_self(random(10)+1);
    return random(6);
  }
}
