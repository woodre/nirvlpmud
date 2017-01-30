inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("sword");
		set_class(17);
		set_value(8000);
		set_weight(4);
                set_alias("sword");
	set_short("The Funk Sword");
set_long(
"  This is the Funk Sword. It is a beautifully crafted weapon, and when used\n"+
"  in combat, something interesting happens...\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
write("["+(this_player()->query_hp())+"] hp ["+(this_player()->query_sp())+"] sp\n");
if(random(100) < 30) {
write("You blast your enemy with pure funk!\n");
say(capitalize(this_player()->query_name())+" blasts something with raw funk!\n");
return 4;
}
}
query_save_flag() { return 1; }
