inherit "obj/monster";

object gold,sax;

reset(arg) {
	::reset(arg);
	if (arg) return;

	set_name("Lisa");
	set_alias("lisa");
	set_short("Lisa Simpson");
	set_long(format("Lisa Simpson.  She is relatively quiet, except "+ 
			"for her music.  She plays the saxophone very we"+
			"ll.  Bart is the family troublemaker and Lisa is"+
			" the scholar.\n",75));
	set_level(10);
	set_hp(175);
	set_wc(12);
	set_ac(3);
	set_al(60);
	set_chat_chance(1);
	load_chat("Lisa plays the blues.\n");
	sax = clone_object("players/gowron/room/obj/saxophone");
	move_object(sax, this_object());	
}
