inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("sword");
set_short("Sword");
set_long(
"A small sword that has seen better days.\n");
set_value(500);
set_weight(1);
set_class(10);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(100) < 20) {
write("You hit "+attacker->query_name()+" leaving an ugly cut.\n");
say(this_player()->query_name()+" hits "+attacker->query_name()+" with is sword making and ugly cut.\n");
return 3;
   }
return 0;
 }
