inherit "/obj/monster";
reset (arg) {
:: reset (arg);
if (!arg) {
        set_name ("gdemia");
	set_alias ("leader");
        set_short ("Gdemia Leader");
        set_race ("gdemia");
        set_long ("You see one of three Gdemia Leaders. They are small"+
                  " but very strong! Beware!\n");
        set_level (18);
        set_ac (15);
        set_wc (25);
        set_hp (600);
        set_al (0);
        set_aggressive (0);
	set_chat_chance (20);
	set_a_chat_chance (20);
	load_chat ("Leader says: Get out of a here, before we killed you!\n");
	load_a_chat ("Leader says: You aren't strong enough to kill me!\n");
/* Some coin return.. -Snow 3/00 */
money = random(200)+500;
}
}
