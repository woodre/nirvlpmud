inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("rifle");
		set_class(19);
		set_value(13500);
		set_weight(3);
                set_alias("rifle");
	set_short("NX20 pulse rifle");
set_long("	You hold the NX20, a sleek, sinister weapon crafted of an\n"+
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
	write("Bwup! Bwup! Bwup! Bwup! Bwup! Bwup! Bwup! Skree! The rifle rains Death!!\n");
	say((this_player()->query_name())+" rains death on the enemy in the form of depleted uranium slugs!\n");
	return 6;
	}
}
query_save_flag() { return 1; }
