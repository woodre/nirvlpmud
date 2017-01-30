inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
		set_name("bat");
		set_class(18);
		set_value(13000);
		set_weight(1);
		set_alias("bat");
	set_short("A yellow wiffle bat");
set_long(
"  This is an ordinary looking wiffle bat. It feels light and strong *swish*\n"+
"  as you swing it.\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
if(random(100) < 7) {
say(capitalize(this_player()->query_name())+" viciously pounds the hell out of some poor soul with the bat.\n");
write("You hear your opponent scream as the bat connects!\n");
return 2;
}
}
