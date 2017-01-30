/*
	Changelog:
	Bal 1996-03-15:
	+ moved inherit to top of file
*/

inherit "obj/monster";

short() { return 0; }

reset(arg) {
    object gold;
    ::reset(arg);
    if (arg) return;
    set_name("Ninja");
    set_race("ninja");
    set_alias("ninja");
    set_short("A well trained Ninja warrior");
    set_long(
	"This is a Ninja warrior, master of deception.  He is training\n" +
	"to master the skills he has learned.  He was trained by the\n"+
	"warriors of Mortal Kombat.\n");
    set_level(16);
    set_hp(350);
    set_al(-1000);
    set_wc(22);
    set_ac(13);
/* Now they are aggressive 50% -Snow */
    set_aggressive(random(2));
    set_chance(20);
    set_spell_dam(10);
    set_spell_mess1("Ninja stikes out with his Sai.\n");
    set_spell_mess2("Ninja cuts you open with his Sai.\n");
    set_a_chat_chance(5);
    set_chat_chance(5);
    load_chat("You see something move in the shadows.\n");
    load_a_chat("Ninja says: You are not worthy of this battle.\n");

    gold = clone_object("obj/money");
    gold->set_money(random(1500)+300);
    move_object(gold,this_object());
}
