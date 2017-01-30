inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
	set_name("rifle");
	set_class(10);
	set_value(350);
	set_weight(4);
	set_alias("22");
	set_short(".22 rifle");
set_long(
"  This is an ordinary-looking .22 caliber rifle.\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
if(random(100) < 10)  {
	write("You deftly shoot your enemy where the sun does'nt shine!\n");
	say((this_player()->query_name())+" cracks off a bulls-eye!\n");
	return 2;
	}
}
