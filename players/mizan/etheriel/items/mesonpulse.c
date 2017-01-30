inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("cannon");
		set_class(19);
		set_value(13500);
		set_weight(5);
                set_alias("cannon");
	set_short("Mesonpulse cannon");
set_long("	You hold the cannon, a sleek, sinister weapon crafted of an\n"+
"  ultralight alloy not familiar to you. You know that the language of\n"+
"  death and violence can be communicated very well with this slender weapon.\n"+
"  There are some numbers written on it that you cannot quite understand:\n"+
"\n"+
"Power index= 13.5l\n"+
"KDY Corporation (limited)\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
if(random(100) < 30)  {
	write("You cheer with delight as the cannon rips sub-atomic hell upon your foe!\n");
	say((this_player()->query_name())+" rains death on the enemy in the form of vicious little atoms!\n");
	return 6;
	}
}
query_save_flag() { return 1; }
