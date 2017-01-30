#include "/players/snakespear/closed/ansi.h"
inherit "obj/weapon.c";
  reset(arg) {
   ::reset(arg);
   if (arg) return;
set_name("axe");
set_alias("battleaxe" && "axe" && "tongue");
set_short("[("+MAG+"Velvet Tongue"+HIR+" the Battleaxe of the Gods"+NORM+")]");
set_long("  This is the prestigious axe once held by the great Elemental Lord.\n"+
         "Although it seems a little heavy, it's rough edges look keen enough\n"+
         "to cleave through any enemy.  The axe seems to feed on your mind.\n");
set_class(500);
set_weight(1);
set_value(1300);
set_hit_func(this_object());
}

init() {
   ::init();
   if(this_player()->query_real_name() != "snakespear") destruct(this_object());
}
weapon_hit(attacker){
int W;

W = random(16);
   if(W > 8) {
   say(BLINK+HIR+"A "+HIG+"b"+HIB+"l"+HIR+"a"+HIY+"s"+HIM+"t"+HIR+" of elemental power shoots from "+capitalize(this_player()->query_real_name())+"'s mind destroying "+(this_player()->query_attack())->query_name()+".\n"+NORM);
   write(BLINK+HIR+"A "+HIG+"b"+HIB+"l"+HIR+"a"+HIY+"s"+HIM+"t"+HIR+" of elemental power shoots from your mind destroying "+(this_player()->query_attack())->query_name()+".\n"+NORM);
   return 500;
 }
return;
 }
