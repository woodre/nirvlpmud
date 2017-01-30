#include "/players/linus/def.h"
inherit "/obj/weapon.c";
int mon;
id(str) { return str=="sword" || str=="enchanted sword"; }
reset(arg) {
   ::reset(arg);
   if(arg) return;
 set_name("enchanted sword");
   set_long(
    "This sword was once a fine weapon used by the guards of the mighty\n"+
    "King Reuben.  Unfortunately, time and the elements have taken their\n"+
    "toll on this sword.  The hilt is barely held together, and the blade\n"+
    "is covered in rust.  Perhaps it is still functional, and may fetch a\n"+
    "decent price if sold to a collector or trader in artifacts.\n");
   set_type("sword");
   set_class(18);
   set_weight(2);
   set_value(5000);
   set_hit_func(this_object());
}
short() {
 if(wielded) { return HIM+"***["+NORM+MAG+"= Enchanted Sword =>"+NORM+" (wielded)"; }
else { return "Longsword"; }
}
wield(str) {
  if(!id(str)) return 0;
if(wielded) return 0;
 if(TP->query_level() < 19) { write("You are too small to wield such a big weapon.\n"); return 1; }
::wield(str);
write("As you wield the longsword, a strange glow takes over it.\n");
     return 1;
}
unwield(str) {
 if(!id(str)) return 0;
 if(!wielded) return 0;
::unwield(str);
 write("The enchantment fades away when you stop wielding the longsword.\n");
return 1;
}
weapon_hit(attacker) {
int blah;
blah = random(5);
if(blah>3) {
 say("The sword starts to glow\n    "+HIY+"* S * P * A * R * K * S *"+NORM+"  fly from the blade!\n");
write("The sword starts to glow\n    "+HIY+"* S * P * A * R * K * S *"+NORM+"  fly from the blade!\n");
return 1;
}
if(!blah) {
say(TPN+" gets a sinister look on their face as the sword slices through flesh!\n");
return 1;
}
}
