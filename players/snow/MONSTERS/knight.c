inherit "/obj/monster";
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object ob, ob2, ob3;
 
  ob = clone_object("obj/weapon");
  ob->set_class(18);
  ob->set_name("Steel Longsword");
  ob->set_long("A well-forged and reliable weapon with fine\n"+
               "balance and a keen edge.\n");
  ob->set_alias("longsword");
  ob->set_alt_name("steel longsword");
  ob->set_value(1000);
move_object(ob,this_object());

  ob2 = clone_object("obj/armor");
  ob2->set_name("steel shield");
  ob2->set_alias("shield");
  ob2->set_short("Steel Shield");
  ob2->set_long("An exceedingly strong shield made of banded steel.\n");
  ob2->set_ac(2);
  ob2->set_type("shield");
  ob2->set_weight(2);
  ob2->set_value(500);
move_object(ob2, this_object());
 
     set_name("white knight");
     set_short("White Knight");
     set_race("human");
     set_alias("knight");
     set_long("A shining example of knighthood, the White Knight\n"+
              "is a friend to the weak and foe to the wicked. He\n"+
              "wields his longsword with a mighty grace and ignores\n"+
              "all but the most powerful blows.\n");
     set_level(20);
init_command("wear shield");
     set_ac(22);
init_command("wield longsword");
     set_wc(26);
     set_hp(500);
     set_heal(1,10);
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
  money = random(300)+200;
   }
}
 
