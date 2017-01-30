inherit "obj/monster";
   object gold;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Ninja");
   set_race("ninja");
   set_alias("ninja");
	set_short("");
	set_long("This is a Ninja of the lower order.  He is in training to become\n" +
	"a master of the ancient skills of Ninjitsu.  He would fair well\n" +
	"killing you.\n");
   set_level(13);
   set_hp(195);
   set_al(-1000);
   set_wc(17);
   set_ac(10);
   set_chance(20);
   set_spell_dam(5);
	set_spell_mess1("The Ninja strikes out with his claws.\n");
	set_spell_mess2("Ninja cuts you with his claws!\n");
	set_a_chat_chance(20);
   set_chat_chance(5);
	load_chat("Ninja whispers: Only a Ninja can kill a Ninja.\n");
	load_a_chat("Ninja says: You are a foolish adventurer for attacking me.\n");
    gold = clone_object("obj/money");
	gold->set_money(random(1000)+500);
   move_object(gold,this_object());
}
