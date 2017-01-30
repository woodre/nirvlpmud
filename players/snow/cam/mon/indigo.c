/* Indigo Knight
 * As the description attests, he has high ac but
 * low hps. The objects cannot be saved.
 */

inherit "/obj/monster";
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object ob, ob2, ob3;
 
  ob = clone_object("obj/weapon");
  ob->set_class(15);
  ob->set_name("Steel Longsword");
  ob->set_type("sword");
  ob->set_long("A well-forged and reliable weapon with fine\n"+
               "balance and a keen edge.\n");
  ob->set_alias("longsword");
  ob->set_alt_name("steel longsword");
  ob->set_value(400);
  ob->set_weight(1);
move_object(ob,this_object());

ob2 = clone_object("/players/snow/cam/stuff/plate.c");
move_object(ob2, this_object());
 
     set_name("indigo knight");
     set_short("Indigo Knight");
     set_race("human");
     set_alias("knight");
     set_long("A shining example of knighthood, the Indigo Knight\n"+
              "is a friend to the weak and foe to the wicked. He\n"+
              "wields his longsword with a mighty grace. His suit of\n"+
              "plate armor makes him nearly invulnerable to attacks.\n");
     set_level(20);
init_command("wear armor");
     set_ac(30);
init_command("wield longsword");
     set_wc(26);
     set_hp(2000);
     set_heal(1,10);
     set_al(1000);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
 
     load_chat("The Indigo Knight bows his head piously.\n");
     load_chat("The Indigo Knight looks at you with forgiveness and love.\n");
     load_a_chat("The Indigo Knight says: Why cannot we be brothers?\n");
     load_a_chat("The Indigo Knights says: Let us make peace, not war...\n");
set_chance(15);
set_spell_mess1("The Indigo Knight attacks his foe in a mighty rage!\n");
set_spell_mess2("The Indigo Knight attacks you in a mighty rage!\n");
set_spell_dam(15);
  money = random(300)+200;
   }
}
 
crime_to_attack() { return 1; }
