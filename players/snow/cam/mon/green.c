/* Green Knight
 * A standard sort of knight. objects cannot be saved
 */

inherit "/obj/monster";
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object ob, ob2, ob3;
 
  ob = clone_object("obj/weapon");
  ob->set_class(16);
  ob->set_name("Steel Longsword");
   ob->set_type("sword");  /* Added by Mal */
  ob->set_long("A well-forged and reliable weapon with fine\n"+
               "balance and a keen edge.\n");
  ob->set_alias("longsword");
  ob->set_alt_name("steel longsword");
  ob->set_value(500);
  ob->set_weight(1);
move_object(ob,this_object());

  ob2 = clone_object("obj/armor");
  ob2->set_name("steel helmet");
  ob2->set_alias("helmet");
  ob2->set_short("Steel Helmet");
  ob2->set_long("An exceedingly strong helmet made of banded steel.\n");
  ob2->set_ac(2);
  ob2->set_type("helmet");
  ob2->set_weight(2);
  ob2->set_value(1000);
move_object(ob2, this_object());
 
     set_name("green knight");
     set_short("Green Knight");
     set_race("human");
     set_alias("knight");
     set_long("A shining example of knighthood, the Green Knight\n"+
              "is a friend to the weak and foe to the wicked. He\n"+
              "wields his longsword with a mighty grace and ignores\n"+
              "all but the most powerful blows. In his eyes you\n"+
              "see a lifetime of sorrow.\n");
     set_level(19);
init_command("wear helmet");
     set_ac(19);
init_command("wield longsword");
     set_wc(26);
     set_hp(600);
     set_heal(1,10);
     set_al(1000);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
 
     load_chat("The Green Knight bows his head piously.\n");
     load_chat("The Green Knight looks at you with forgiveness and love.\n");
     load_a_chat("The Green Knight says: Why cannot we be brothers?\n");
     load_a_chat("The Green Knights says: Let us make peace, not war...\n");
set_chance(15);
set_spell_mess1("The Green Knight attacks his foe in a mighty rage!\n");
set_spell_mess2("The Green Knight attacks you in a mighty rage!\n");
set_spell_dam(15);
  money = random(300)+200;
   }
}
 
crime_to_attack() { return 1; }
