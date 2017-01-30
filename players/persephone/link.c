inherit "obj/monster";

object tre, ob;

init() {
	add_action("give", "give");
	::init();
}

reset(arg) {
if (arg) return;
::reset(arg);

set_name("link");
set_short("Link, an old man");
set_alias("old man");
set_race("man");
set_long(
"This old man looks so calm and peaceful, but there are worries in his\n" +
"eyes. Perhaps you might be able to help him.\n");
set_level(20);
set_hp(1000);
set_wc(5);
set_ac(30);
set_chat_chance(50);
load_chat("Link says: I wish I still have my sword.\n");
load_chat("Link says: In return of my sword, I'll give you an orb.\n");
load_chat("Link says: Have you met Su? He is my old friend.\n");

}

give(str) {
    if (str != "heaven sword to link" && str != "sword to link") {
	write("Thank you. But I can't accept that.\n");
	return 1;
	}
    	ob = present("heaven sword", this_player());
	if (!ob) {
	    write("You don't have the Heaven Sword!\n");
	    return 1;
	}
	destruct(ob);
	tre = clone_object("players/lupin/item/orb_evil");
	write("Link gives you an orb.\n");
	transfer(tre, this_player());
	return 1;
}
