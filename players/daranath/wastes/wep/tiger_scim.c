#include <ansi.h>
#define tp this_player()->query_name()
#define TARG attacker->query_name()
 inherit "obj/weapon.c";

int a;

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("tiger scimitar");
set_alias("scimitar");
set_short("Scimitar of the "+HIY+"T"+BOLD+BLK+"i"+HIY+"g"+BOLD+BLK+"e"+HIY+"r"+NORM);
set_long("A relic from the time when Gundar was thriving, the Clan of the Tiger\n"+
         "used these blades as thier primary weapon. A prowling tiger adorns the\n"+
         "hilt of the weapon, making sought after by collectors everywhere.\n");
set_class(18);
set_weight(2);
set_value(3500);
set_hit_func(this_object());
}

weapon_hit(attacker){
  if(call_other(this_player(), "query_attrib", "str") > random (50)) {
a = random(3);
 if(a == 0) {
write("You slash the "+TARG+" deeply with the "+YEL+"Tiger "+NORM+"Scimitar.\n");
say(tp +" slashes the "+TARG+" with the "+YEL+"Tiger"+NORM+" Scimitar.\n"); }
 if(a == 1) {
write("You spin the "+YEL+"Tiger"+NORM+" Scimitar around in your hand and\n"+
      "stab the "+TARG+" deeply with it.\n");
say(tp +" stabs the "+TARG+" deeply with the "+YEL+"Tiger"+NORM+" Scimitar.\n"); }
return 5;
}
return;
}

