inherit "obj/monster";

reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("Alchemist");
   set_race("child");
   set_alias("alchemist");
   set_short("A puking Alchemist");
   set_long("This basically an Alchemist who is feeling under the weather\n"+
      "They never could hold their liquor..maybe you should KILL him and put\n"+
      "him out of his misery.\n");
   set_level(6);
   set_hp(100);
   set_al(-1000);
   set_wc(12);
   set_ac(3);
   set_chance(20);
   set_spell_dam(10);
   set_spell_mess1("Alchemist begins puking again.");
   set_spell_mess2("Alchy pukes all over you.");
   set_chat_chance(20);
load_chat("Alchemist cries: One beer was too much\n");
load_chat("Alchemist yells: Please don't make me drink two this time!\n");
   gold=clone_object("obj/money");
   gold->set_money(random(100)+150);
   move_object(gold,this_object());
}
