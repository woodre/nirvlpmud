inherit "obj/treasure";
int last_use, charges;
reset(arg) {
if (arg) return;
last_use = 0;
charges=3;
set_short("Figurine of a black panther");
set_long
("This is small figurine of a gorgeous black panther. As you turn it\n"+
 "around in your hand you notice the fine details of the carving. The\n"+
"white, sharp teeth, the glossy sheen of the panthers pelt, and the\n"+
"incredible power behind the sleek hard muscles. You also notice on\n"+
"bottom of the figurine, the word 'Guenhwyvar'.\n");
set_weight(1);
set_alias("figurine");
set_value(500);
}
init()
{
::init();
if(environment() == this_player())
{
add_action("do_summon", "Guenhwyvar");
}
}
do_summon()
{
object panther, enemy;
if(!this_player()->query_attack())
{
write("You are not fighting anyone.\n");
return 1;
}
if(present("panther", environment(this_player())))
{
write("The panther is already here.\n");
return 1;
}
if(charges<1)
{
write("The figurine does not work anymore and dissolves into a green mist.\n");
destruct(this_object());
return 1;
}
if(time() < (last_use + 20))
{
write("The figurine has not regained its power yet.\n");
return 1;
}
write("You speak the word of power and watched amazed as a green\n"+
"mist envelops the statuette, coalescing into a sleek, black panther.\n");
say(this_player()->query_name()+" 's speaks an unfamiliar word and a green\n"+
"mist envelopes the statue and soon forms into a huge muscular panther.\n");
panther=clone_object("players/nightshade/mons/panther");
move_object(panther, environment(this_player()));
enemy = this_player()->query_attack();
charges -=1;
return 1;
}
