inherit "/obj/monster";
object ob, ob2, gold;

reset(arg) {
   ::reset(arg);
gold = clone_object("obj/money");
gold->set_money(50);
move_object(gold,this_object());
  ob = clone_object("/players/saber/weapons/sclub.c");
move_object(ob,this_object());
 ob2 = clone_object("/players/saber/armor/wshield.c");
move_object(ob2,this_object());
   if (!arg){
     set_name( "goblin" );
    set_gender("male");
      set_short("An ugly goblin");
     set_race( "orc");
     set_long("A small humanoid with a flat face, broad nose, pointed ears, a\n"+
 "wide mouth and small, sharp fangs.  It has dull black skin and\n"+
 "oily black hair, and is wearing tattered bits of leather armor.\n");
     set_level(6);
     set_ac(5);
     set_wc(10);
     set_hp(90);
     set_al(-200);
     set_chat_chance(10);
     set_a_chat_chance(15);
     load_chat("Goblin cowers.\n");
     load_chat("The crowd cheers.\n");
    load_a_chat("Goblin punches you.\n");
     load_a_chat("Goblin kicks you.\n");
     load_a_chat("Goblin burps loudly.\n");
     load_a_chat("Goblin bleeds.\n");
     load_a_chat("The crowd cheers.\n");
   }
}
