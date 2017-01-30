inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("wooden elven sword");
set_alias("sword");
set_short("a wooden elven sword");
set_long(
"A wooden elven sword??? How the heck do you fight with a wooden sword?\n"
+ "Aah...but remember, it's elven.\n");
set_value(3000);
set_weight(3);
set_class(16);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(100) < 30) {
write("Your sword radiates fiercely and chops at "+attacker->query_name()+"'s internals!\n");
say(this_player()->query_name()+"'s sword radiates fiercely and chops at "+attacker->query_name()+"'s internals!\n");
return 2;
   }
return 0;
 }
