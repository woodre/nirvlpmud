inherit"obj/food";
reset(arg) {
::reset(arg);
if(!arg) {
	set_name("spam");
	set_short("A can of Spam");
	set_long("This is a can of Spam. What else could it be?\n");
	set_eater_mess("You gobble down the meat-like substance in a flash!\n");
	set_eating_mess(" open up a can of Spam and gulps it down.\n");
	set_strength(30);
	set_value(700);
	}
}
