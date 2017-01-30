inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("blade");
set_alias("sword");
set_short("Trix's blade");
set_long(
"This is the blade of Trix.\n");
set_value(500);
set_weight(1);
set_class(25);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(100) < 50) {
write(attacker->query_name()+" is slammed by your blade.\n");
say(this_player()->query_name()+" swings the blade upon "+attacker->query_name()+"'s head.\n");
return 5;
   }
return 0;
 }
