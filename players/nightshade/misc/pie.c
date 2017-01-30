inherit "obj/treasure";
reset(arg) {
if (arg) return;
set_short("Meat pie");
set_long
("A mincemeat pie. Looks good!\n");
set_weight(1);
set_alias("pie");
set_value(1);
}
init()
{
if(environment() == this_player()) add_action("do_eat", "eat");
}
do_eat(str)
{
if(!str) return 0;
if(str == "pie");
this_player()->heal_self(1);
write("You eat the meat pie and fell refreshed.\n");
destruct(this_object());
return 1;
}
