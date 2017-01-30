/*
// 2005.08.10 Forbin
//   -added fire protection (seemed thematic)
*/

inherit "obj/armor";
#include "/players/feldegast/defines.h"

reset(arg) {
  set_name("armor");
  set_short(RED+"Wyvernskin armor"+NORM);
  set_long(
"This suit of armor is formed from the treated hide of a wyvern,\n"+
"a distant cousin of the common dragon.  It is simultaneously\n"+
"extremely flexible and extremely tough, making it an exceptional\n"+
"armor for those lucky enough to obtain it.  The thick hide will\n"+
"somewhat protect the wearer from fire damage.\n"
  );
  /* added color to short and changed AC to 5 - 2004.11.01 Forbin */
  set_ac(5);
  set_params("other|fire", 0, 20, "fire_special");
  set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(4);
  set_value(2000);
}

int fire_special(object user)
{
  if(!random(8))
  {
    tell_object(user,
      HIR+"Flames"+NORM+" lick at your "+RED+"Wyvernskin armor"+NORM+".\n"+  
      "The flames protect you from the fire.\n"+NORM);
    tell_room(environment(user),
      (string)user->query_name()+"'s armor protects "+
      (string)user->query_objective()+" from fire.\n", ({ user }) );
    return 2005; /* additional 20% resistance, 5 AC Protection */
  }
  return 0;
}