inherit "/obj/monster";

reset(arg)
{
	::reset(arg);
	if (!arg) {
		set_name("faeries");
		set_short("A group of tiny faeries with gossamer wings");
		set_long("A horde of tiny nude faeries whith gossamer wings.\n" +
				 "They appear to ALL be watching you...\n");
		set_level(15);
		set_ac(20);
		set_wc(15);
		set_hp(300);
		set_al(400);
		set_aggressive(0);
		set_chat_chance(3);
		set_a_chat_chance(10);
		load_chat("The tiny faeries whisper to each other.\n");
		load_chat
			("The tiny faeries run their little fingers through your hair.\n");
		load_chat("The tiny faeries look at you and smile.\n");
		load_a_chat("A faerie falls to the ground.\n");
	}
}
