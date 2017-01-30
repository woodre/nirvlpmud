/* White Knight
 * High ac, very high heal rate
 * Many coins
 */

inherit "/obj/monster";
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object ob, ob2, ob3;
 
  ob = clone_object("obj/weapon");
  ob->set_class(17);
  ob->set_name("Steel Longsword");
  ob->set_type("sword");
  ob->set_long("A well-forged and reliable weapon with fine\n"+
               "balance and a keen edge.\n");
  ob->set_alias("longsword");
  ob->set_alt_name("steel longsword");
  ob->set_value(750);
  ob->set_weight(1);
move_object(ob,this_object());

  ob2 = clone_object("/players/snow/cam/stuff/shield.c");
move_object(ob2, this_object());
 
     set_name("white knight");
     set_short("White Knight");
     set_race("human");
     set_alias("knight");
     set_long("A shining example of knighthood, the White Knight\n"+
              "is a friend to the weak and foe to the wicked. He\n"+
              "wields his longsword with a mighty grace and ignores\n"+
              "all but the most powerful blows. He exudes the aura\n"+
              "of one blessed by a higher power.\n");
     set_level(20);
init_command("wear shield");
     set_ac(22);
init_command("wield longsword");
     set_wc(35);
     set_hp(1500);
     set_heal(5,10);
     set_al(1000);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
 
     load_chat("The White Knight bows his head piously.\n");
     load_chat("The White Knight looks at you with forgiveness and love.\n");
     load_a_chat("The White Knight says: Why cannot we be brothers?\n");
     load_a_chat("The White Knights says: Let us make peace, not war...\n");
set_chance(15);
set_spell_mess1("The White Knight attacks his foe in a mighty rage!\n");
set_spell_mess2("The White Knight attacks you in a mighty rage!\n");
set_spell_dam(15);
  money = random(2000)+1000;
   }
}
 
crime_to_attack() { return 1; }
