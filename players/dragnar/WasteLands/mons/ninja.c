/*
	Changelog:
	Bal 1996-03-15:
	+ moved inherit to top of file
*/

inherit "obj/monster";

short () { return 0; }

reset(arg){
    ::reset(arg);
    if (arg) return;
    set_name("Ninja");
    set_race("ninja");
    set_alias("ninja");
    set_short("An ultimate Ninja warrior");
    set_long(
	"This is a Ninja warrior, master of deception.  He is trained to\n" +
	"kill others with the skills of the ancients.  He is the perfect assassin.\n");
    set_level(20);
    set_hp(random(200)+400);
    set_al(-1000);
    set_wc(30);
    set_ac(17);
    set_chance(20);
    set_spell_dam(10);
    set_spell_mess1("Ninja disappears in a puff of smoke.\n");
    set_spell_mess2("Ninja strikes at your heart with a throwing star.\n");
    set_a_chat_chance(20);
    set_chat_chance(1);
    load_chat("You see something move in the shadows.\n");
    load_a_chat("Ninja whispers: You have chosen your fate, now you will die.\n");
    add_money(2000+random(6000));
   /* added by mizan- people linger without FEAR in the castle and rack exps */
/* Changed from 1/7 to 1/3 -Snow */
   if(1 == random(3)) set_aggressive(1);
}
