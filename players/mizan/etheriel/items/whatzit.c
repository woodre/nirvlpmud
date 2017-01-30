inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
		set_name("whatzit");
		set_class(15);
		set_value(1000);
		set_weight(1);
		set_alias("whatzit");
	set_short("A whatzit");
set_long(
"This is a whatzit. After some figuring, you conclude that it can be 'wielded'.\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
if(random(10) < 2)  {
	write("The whatzit tells you: You have ["+(this_player()->query_sp())+"] spellpoints.\n");
	say((this_player()->query_name())+"'s whatzit glows and hums with blind fury!\n");
	return 4;
}
}
