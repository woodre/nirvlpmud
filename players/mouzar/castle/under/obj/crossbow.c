inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("crossbow");
set_alias("bow");
set_short("Drow Crossbow");
set_long(
"This is a drow crossbow.  It is small but more than effective.  It's darts\n"
+ "are coated with deady drow poison.\n");
set_value(1500);
set_weight(1);
set_class(16);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(100) < 33) {
write("You strike "+attacker->query_name()+" with one of the deadly darts.\n");
say(this_player()->query_name()+" hits "+attacker->query_name()+" with one of the deady drow darts.\n");
return 9;
   }
return 0;
 }
query_save_flag() { return 1; }
