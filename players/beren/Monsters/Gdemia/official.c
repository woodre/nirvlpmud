inherit "/obj/monster";
object ob;
reset (arg) {
:: reset (arg);
ob = clone_object ("players/beren/Objects/Armors/Gdemia/garmor.c");
move_object (ob, this_object ());
command ("wear armor", this_object ());
if (!arg) {
        set_name ("gdemia");
	set_alias ("official");
        set_short ("Gdemia Official");
        set_race ("gdemia");
        set_long ("You see Gdemia official. He is busy working.\n");
        set_level (15);
        set_ac (13);
        set_wc (28);
        set_hp (250);
        set_al (0);
        set_aggressive (0);
        set_chat_chance (20);
        set_a_chat_chance (20);
        load_chat ("Gdemia says: You aren't Gdemia! Be gone!\n");
	load_a_chat ("Gdemia cries: Our leaders will kill you for this!\n");
}
}
