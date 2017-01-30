inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("paddle");
		set_class(12);
		set_value(2500);
		set_weight(1);
                set_alias("paddle");
	set_short("A ping-pong paddle");
set_long(
"This is an ordinary looking ping-pong paddle, but it has plenty \n"+
"of bloodstains on it. It looks like it can be wielded.\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
{
if(random(100) < 50) {
write("Pwok! Ping! Poof! You slap some poor creature viciously with the paddle!\n");
say(capitalize(this_player()->query_name())+" rudely slaps something with a ping-pong paddle!\n");
return 6;
}
}
query_save_flag() { return 1; }
