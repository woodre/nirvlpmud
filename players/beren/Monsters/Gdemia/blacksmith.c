inherit "/obj/monster";
object ob;
reset (arg) {
:: reset (arg);
ob = clone_object ("players/beren/Objects/Weapons/Gdemia/ghammer.c");
move_object (ob, this_object ());
command ("wield hammer", this_object ());
if (!arg) {
        set_name ("gdemia");
	set_alias ("blacksmith");
        set_short ("A Gdemia blacksmith is working here");
        set_race ("gdemia");
        set_long ("You see an ordinary Gdemian blacksmith. He is working hard,\nusing his helpful hammer, you feel that it's not just a\ntool, but a part of him. He is real master, nothing to\nsay. Still he can be quite dangerous when attacked and\nhis hammer which was just brilliantly used may serve as\nweapon as well.\n"); 
	set_level (16);
        set_ac (10);
        set_wc (18);
/* Changed from 500. -Snow 3/00 */
        set_hp (random(250)+300);
        set_al (0);
        set_aggressive (0);
        set_chat_chance (20);
        set_a_chat_chance (20);
        load_chat ("Blacksmith is working just BRILLIANTLY.\n");
        load_a_chat ("Blacksmith shouts: You dare attack me!? I 'll smash you now!\n");
}
}

