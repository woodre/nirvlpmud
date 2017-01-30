inherit "obj/weapon.c";
reset(arg) {
set_alias("breasts");
set_class(2);
   set_weight(0);
set_hit_func(this_object());
}
string extra_look () {
return environment()->query_name()+" has huge 42 DDD breasts";
 }
string query_auto_load () {
return "players/boltar/test/we";
}
weapon_hit(attacker) {
int hurt;
hurt=random(10);
if(hurt < 5) {
tell_object(attacker, environment()->query_name()+" smacks you with her 42 DDD breasts\n");
write("You thwap "+attacker->query_name()+" with your breasts.\n");
say(environment()->query_name()+" smacks "+attacker->query_name()+" with her 42 DDD breasts.\n");
 }
}
