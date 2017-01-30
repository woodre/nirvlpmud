inherit "/obj/monster";
reset (arg) {
:: reset (arg);
if (!arg) {
        set_name ("gdemia");
	set_alias ("guard");
        set_short ("A Gdemia guard is here on duty.");
        set_race ("gdemia");
        set_long ("A guard! Yes, yes, these 'people' have guards as well.\nHow did you know that he is a guard? Hm... He looks taller\nthen others, quite mean and his sight is like... If you\nhave seen a guard once in your life, you can easily recognize it.\n");
        set_level (14);
        set_ac (10);
        set_wc (18);
        set_hp (200);
        set_al (0);
        set_aggressive (0);
        set_chat_chance (20);
        set_a_chat_chance (20);
        load_chat ("A guard says: Get out, I am on duty here!\n");
       load_a_chat ("Guard shouts: Police! Police! Man-on-duty is being attacked!\n");
/* Some profit... -Snow 3/00 */
money = random(500)+250;
}
}
