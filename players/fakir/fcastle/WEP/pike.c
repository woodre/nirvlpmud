#include <ansi.h>

inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("pike");
  set_alias("spear");
  set_type("spear");
  set_short("Longpike");
  set_long("The chosen weapon of the Children of Light, the pike is two spans\n"+
           "in length and tipped with a hooked steel spearhead.\n");
  set_class(16);
  set_weight(1);
  set_value(1000);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(20);
if(W>14)  {
  say("\nThe pike's hook gashes and slashes soft flesh.\n\n"+
    "    "+YELLOW+"~~~~~~~~~"+OFF+" "+RED+"G A S H"+OFF+" "+YELLOW+"~~~~~~~~"+OFF+" "+RED+"S L A S H"+OFF+" "+YELLOW+"~~~~~~~~~"+OFF+"\n\n"+
    "You see bloody flesh fly everywhere.\n");
  write("\nThe mighty hooked pike gashes and slashes soft flesh.\n\n"+
    "     "+YELLOW+"~~~~~~~~"+OFF+" "+RED+"G A S H"+OFF+" "+YELLOW+"~~~~~~~~"+OFF+" "+RED+"S L A S H"+OFF+" "+YELLOW+"~~~~~~~~"+OFF+"\n\n"+
    "Bloody flesh flies everywhere.\n");
return 4;

   }
   return;
}
