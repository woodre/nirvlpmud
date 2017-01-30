inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("malac's warhammer");
set_alias("hammer");
SetMultipleIds(({"warhammer"}));
set_short("warhammer of MIGHTY destruction");
set_long("You notice some runes marking this weapon as the mighty\n" +
         "warhammer of malac, The Giant Hunter. This mighty weapon\n" +
         "may only be wielded by the mightiest of warriors.\n");
/* Value changed from 15000 to 1500 - Snow */
set_value(1500);
set_weight(6);
set_class(15);
set_hit_func(this_object());
}
weapon_hit(attacker) {
object ob;
int i;
ob = users();
if(random(100) < 10) {
write("The earth rumbles as you SMASH your enemy!!\n");
say("The earth splits as Malac's Warhammer strikes!\n");
return 5;
}
if(random(100) < 5) {
write("A BLAST FROM HELL BLOWS YOUR ENEMY INTO THE GROUND!\n");
say("A HELLACIOUS BLAST CAUSES THE GROUND TO QUAKE!\n");
for(i=0; i<sizeof(ob); i++) {
   if(ob[i]->on_channel("junk") && ob[i]->query_level() < 20) {
   tell_object(ob[i], "You feel a mighty tremor erupt throughout"+
      " the land.\n");
   }}
return 7;
     }
 return 0; }
