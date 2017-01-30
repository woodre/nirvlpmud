/* This sword is found on Goro in Mortal Kombat. The only way to get it is to go
   through the entire mortal kombat arena monsters, as well as the MK Quest */

#include <ansi.h>
inherit "obj/weapon";
#define user environment()

void
reset(int arg) {
    ::reset(arg);
    if (arg) return;
    set_name("sword");
    set_short("Sword of Angels");
    set_long(
"This is the sword you recieved for fighting the warriors on the\n" +
"island of darkness.  With your victory you gained great power with\n" +
"the angels.  They will protect your soul now.\n");
    set_class(18);
    set_weight(3);
    set_value(3000);
    set_save_flag(1);
    set_hit_func(this_object());
    set_wield_func(this_object());
}

mixed
weapon_hit(object attacker) {
  int x;
  x=random(100);
  if(!attacker || !user) return;
  switch(x) 
  {
  case 89..99:
    tell_object(user,
      "\nA circle of 13 angels decend from the heavens.  Each one turns and\n" +
      "touches your sword.  As they ascend back into the sky your wounds\n" +
      "are surrounded by a "+BOLD+"white light"+NORM+" and you feel stronger.\n\n");
    user->heal_self(random(12)+1);
	return(random(6));
    break;
  case 69..88:
    tell_object(user,
	  BOLD+"You strike out with the speed of the Gods."+NORM+"\n");
	attacker->hit_player(random(x/4));
	break;
  case 49..68:
    tell_object(user,
	  "An angel appears and "+HIY+"unleashes holy wrath"+NORM+" upon "+attacker->query_name()+".\n");
	attacker->heal_self(x/6);
	break;
  case 30..48:
    write("The angels sing as you slice " + attacker->query_name() + ".\n");
    say("Angels sing as " + this_player()->query_name() + " uses the power of"+
      " "+user->query_possessive()+" sword.\n");
    return(3 + random(6));
	break;
  default:
    return 0;
	break;
  }
}

mixed wield(mixed x)
{
    if (objectp(x)) {
	write("You feel the power of the angels watching over you.\n");
	return 1;
    }
    else return ::wield(x);
}
