inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("sphere");
		set_class(18);
		set_value(12000);
		set_weight(3);
                set_alias("sphere");
	set_short("The Shock Sphere");
set_long(
"  This is a really nasty looking thing, glowing with the power of many, many\n"+
"  volts. Be careful with the way you wield that thing... you could really\n"+
"  toast someone's eyeballs!\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
if(random(100) < 24)  {
write("You toast your opponent with a zap of (something like) 200,000 volts!!\n");
say((this_player()->query_name())+" toasts someone's eyeballs!\n");
	return 3; }
}
