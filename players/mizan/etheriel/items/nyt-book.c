inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("telephone book");
set_alias("book");
set_short("A New York Telephone book");
set_long(
"It's heavy, it's rather unwieldy, but if you struck someone on the\n"
+ "head with this thing, damn... it would hurt!\n");
set_value(1500);
set_weight(4);
set_class(17);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(100) < 10) {
write("You pound a "+attacker->query_name()+" with a New York Telephone book! (ouch!)\n");
say(attacker->query_name()+" is struck with a telephone book!!\n");
return 5;
   }
return 0;
 }
