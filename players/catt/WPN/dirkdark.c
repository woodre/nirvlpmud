inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("dirk");
set_alias("dirk of darkness");
set_short("dirk of darkness");
set_long(
"This is the dirk used by all supporters of the dark realm of demons.\n"
+ "Use it in good health(yea right). It is black down the slender hilt\n"
+ "and grey with streaks of silver down the blade... it hums with power.\n");
/* Value changed from 3000 to 500 -Snow */
set_value(500);
set_weight(3);
set_class(15);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(100) < 30) {
write(attacker->query_name()+" staggers as the dirk steals some of its lifeforce.\n");
say(attacker->query_name()+" staggers as the dirk strikes out... draining some of "+attacker->query_name()+"'s lifeforce.\n");
/* Changed from 12 to 6  -Snow */
return 6;
   }
return 0;
 }
