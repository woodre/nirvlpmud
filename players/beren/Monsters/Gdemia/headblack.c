inherit "/obj/monster";
object ob, gold;
reset (arg) {
:: reset (arg);
gold = clone_object ("obj/money");
gold -> set_money (500);
move_object (gold, this_object ());
ob = clone_object ("players/beren/Objects/Weapons/Gdemia/ghammer.c");
move_object (ob, this_object ());
command ("wield hammer", this_object ());
if (!arg) {
        set_name ("gdemia");
	set_alias ("blacksmith");
        set_short ("Gdemia Head Blacksmith");
        set_race ("gdemia");
        set_long ("You see Gdemia head blacksmith. He is busy working.\n");
        set_level (17);
        set_ac (10);
        set_wc (18);
        set_hp (600);
        set_al (0);
        set_aggressive (0);
        set_chat_chance (20);
        set_a_chat_chance (20);
        load_chat ("Gdemia says: You aren't Gdemia! Be gone!\n");
       load_a_chat ("Gdemia cries: Our leaders will kill you for this!\n");
}
}
