inherit"obj/weapon";
int i,n;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("Balig the Goblin Slayer");
set_alias("balig");
set_short("Balig: The Goblin Slayer");
set_long(
"This is Balig the goblin slayer. It has been used in many a war\n" +
"against mass armies of goblins and orcs and was forged for that\n" +
"purpose. It is an ancient weapon and holds mystical powers within\n" +
"it's depths. It has a silvered blade worked with fine elven runes\n" +
"that glow a soft fiery red when spilling the black blood of it's\n" +
"intended pray.\n");
/* Value changed from 5000 to 500  -Snow */
set_value(500);
set_weight(3);
set_class(15);
set_int_init();
set_hit_func(this_object());
}
set_int_init() {
   i = 0;
   n = 1;
}
weapon_hit(attacker) {
if(call_other(attacker, "id", "goblin")) {
write("Balig's runes take on a soft fiery glow\n");
write("Balig hums as goblin's black blood wets the blade\n");
  attacker->heal_self(-(random(5) + 4));  return 8; }
if(call_other(attacker, "id", "orc")) {
  write("Balig glows a soft red\n");
  write("Orc says: NO!! NOT THE SLAYER!!\n");
  say("energy ripples down balig sending the orc writhing in pain\n");
   return 15; }
return 0;
 }
