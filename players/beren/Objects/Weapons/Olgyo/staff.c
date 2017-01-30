inherit "obj/weapon.c";

reset (arg) {
::reset (arg);
if (arg) return;

set_name ("staff");
set_alias ("Pedane staff");
set_short ("Pedane staff");
set_long ("It's a magic staff of Pedane.\n");
set_class (19);
set_weight (2);
set_value (1000);
set_hit_func(this_object ());
}

weapon_hit(attacker)
{
  if(!random(3)) {
 write("Your staff lights brightly and casts a lightning on your opponent.\n");
 say ("You see "+this_player()->query_name()+"'s staff lights and the foe falls down screaming.\n");
 return random(4)+4;
}
}
