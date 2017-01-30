inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("lag wand");
set_alias("wand");
set_short("lag wand");
set_long(
"a long slender white wand that creates lag across the mud\n");
set_value(20);
set_weight(1);
set_class(1);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(100) < 70) {
write("YOU cause lag to increase across the mud!!!!!!\n");
say(attacker->query_name()+" shrieks as LAG increases for a min... causing mud CRASH!\n");
return 1;
   }
return 0;
 }
