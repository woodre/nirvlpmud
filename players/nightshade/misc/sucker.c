inherit "obj/treasure";
reset(arg) {
if (arg) return;
set_short("Topaz");
set_long
("A rather large topaz gem Hephastus has plundered.\n");
set_weight(1);
set_alias("gem");
set_value(500);
}
init()
{
::init();
add_action("do_suck", "suck");
}
do_suck(str)
{
ob=present(str, environment(this_player()));

