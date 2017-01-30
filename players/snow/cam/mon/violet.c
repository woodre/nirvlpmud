/* Violet Knight
 * Extremely high wc, high spell damage
 * Low ac and hps, does heal however
 */

inherit "/obj/monster";
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object ob, ob2, ob3;
 
  ob = clone_object("/players/snow/cam/stuff/sword.c");
move_object(ob,this_object());

  ob2 = clone_object("obj/bag");
move_object(ob2, this_object());

  ob3 = clone_object("obj/money");
  ob3->set_money(1000);
  move_object(ob3, ob2);
 
     set_name("violet knight");
     set_short("Violet Knight");
     set_race("human");
     set_alias("knight");
     set_long("A shining example of knighthood, the Violet Knight\n"+
              "is a friend to the weak and foe to the wicked. He\n"+
              "wields his longsword with a deadly skill matched only by\n"+
              "his disregard for his own well-being.\n");
     set_level(20);
     set_ac(5);
init_command("wield longsword");
     set_wc(50);
     set_hp(1000);
     set_heal(1,10);
     set_al(1000);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
 
     load_chat("The Violet Knight bows his head piously.\n");
     load_chat("The Violet Knight looks at you with forgiveness and love.\n");
     load_a_chat("The Violet Knight says: Why cannot we be brothers?\n");
     load_a_chat("The Violet Knights says: Let us make peace, not war...\n");
set_chance(30);
set_spell_mess1("The Violet Knight attacks his foe in a mighty rage!\n");
set_spell_mess2("The Violet Knight attacks you in a mighty rage!\n");
set_spell_dam(30);
  money = random(300)+200;
   }
}
 
crime_to_attack() { return 1; }
