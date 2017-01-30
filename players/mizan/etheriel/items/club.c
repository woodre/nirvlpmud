inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
		set_name("club");
		set_class(16);
		set_value(1000);
		set_weight(3);
		set_alias("club");
	set_short("A nasty looking club");
set_long(
" This is a really nasty looking club. You could really pound something to \n"+
" tiny little pieces with it.\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
if(random(100) < 10) {
write("You cackle gleefully as you pound your opponent where the sun dont shine!\n");
say(capitalize(this_player()->query_name())+" beats someone so hard it hurts just to see it!\n");
return 5;
}
}
