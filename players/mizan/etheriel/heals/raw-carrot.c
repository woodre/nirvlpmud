inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("carrot");
	set_short("A carrot");
	set_alias("carrot");
	set_long("An ordinary looking carrot.\n");
	set_eater_mess("You chomp down on a raw carrot.\n");
	set_eating_mess(" goes: Nyahhhh! What's up, doc?\n");
	set_strength(10);
	}
}
query_value()
{
return 1;
}
