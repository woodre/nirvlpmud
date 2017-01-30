inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("bowie");
		set_class(18);
		set_value(3300);
		set_weight(2);
                set_alias("bowie");
	set_short("The Big Bad Black Bowie of Bunupuradah");
set_long(
"  This is indeed the big, bad, black bowie of Bunupuradah.. It's a vicious\n"+
"  looking thing, and you cackle with glee as you imagine it plunged into\n"+
"  someone's gut, and how silly that someone would look and feel.\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
if(random(100) < 25)  {
	write("You giggle inanely as you plunge the blade into something's gut.\n");
	say((this_player()->query_name())+" dances and cheers merrily as the bowie tastes blood!\n");
	return 5;
	}
}
