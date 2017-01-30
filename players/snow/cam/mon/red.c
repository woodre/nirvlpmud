/* Red Knight
 * Low ac, high hps, high healing
 */

inherit "/obj/monster";
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object ob, ob2, ob3;
 
  ob = clone_object("obj/weapon");
  ob->set_class(16);
  ob->set_name("Steel Longsword");
  ob->set_type("sword");
  ob->set_long("A well-forged and reliable weapon with fine\n"+
               "balance and a keen edge.\n");
  ob->set_alias("longsword");
  ob->set_alt_name("steel longsword");
  ob->set_value(500);
  ob->set_weight(1);
move_object(ob,this_object());

  ob2 = clone_object("obj/armor");
  ob2->set_name("steel boots");
  ob2->set_alias("boots");
  ob2->set_short("Steel Boots");
  ob2->set_long("A pair of exceedingly strong boots made of banded steel.\n");
  ob2->set_ac(2);
  ob2->set_type("boots");
  ob2->set_weight(2);
  ob2->set_value(1000);
move_object(ob2, this_object());
 
     set_name("red knight");
     set_short("Red Knight");
     set_race("human");
     set_alias("knight");
     set_long("A shining example of knighthood, the Red Knight\n"+
              "is a friend to the weak and foe to the wicked. He\n"+
              "wields his longsword with a mighty grace. His body\n"+
              "shows the scars of many battles.\n");
     set_level(19);
init_command("wear boots");
     set_ac(10);
init_command("wield longsword");
     set_wc(26);
     set_hp(700);
     set_heal(3,10);
     set_al(1000);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
 
     load_chat("The Red Knight bows his head piously.\n");
     load_chat("The Red Knight looks at you with forgiveness and love.\n");
     load_a_chat("The Red Knight says: Why cannot we be brothers?\n");
     load_a_chat("The Red Knights says: Let us make peace, not war...\n");
set_chance(15);
set_spell_mess1("The Red Knight attacks his foe in a mighty rage!\n");
set_spell_mess2("The Red Knight attacks you in a mighty rage!\n");
set_spell_dam(15);
  money = random(300)+200;
   }
}
 
crime_to_attack() { return 1; }
