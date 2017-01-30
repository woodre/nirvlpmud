short () { return 0; }
inherit "obj/monster";
   object gold;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Ninja");
   set_race("ninja");
   set_alias("ninja");
   set_short("An ultimate Ninja warrior");
	set_long("This is a Ninja warrior, master of deception.  He is trained to\n" +
	"kill others with the skills of the ancients.  He is the perfect assassin.\n");
   set_level(20);
   set_hp(500);
   set_al(-1000);
   set_wc(30);
   set_ac(17);
   set_chance(20);
   set_spell_dam(10);
	set_spell_mess1("Ninja disappears in a puff of smoke.\n");
	set_spell_mess2("Ninja strikes at your heart with a throwing star.\n");
	set_a_chat_chance(20);
   set_chat_chance(5);
	load_chat("Ninja whispers: Only a Ninja can kill a Ninja.\n");
	load_chat("Ninja says: Only one will live, turn around and face your fate.\n");
	load_a_chat("Ninja whispers: You have chosen your fate, now you will die.\n");
    gold = clone_object("obj/money");
   gold->set_money(random(2500)+3500);
   move_object(gold,this_object());
}
