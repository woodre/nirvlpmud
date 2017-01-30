inherit "/obj/monster";
int lvl,wcc;

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob2, ob3, gold;
 gold = clone_object("obj/money");
  gold->set_money(random(100));
  move_object(gold,this_object());
  ob2 = clone_object("/players/saber/weapons/rapier.c");
move_object(ob2,this_object());
 ob3 = clone_object("/players/saber/armor/stdleather.c");
move_object(ob3,this_object());
     set_name("frederick");
     set_short("Frederick the Bandit");
     set_race( "human");
     set_gender("male");
     set_long("A tall, blond haired man with a killer smile and wicked blue eyes.\n");
     set_level(6);
     set_ac(5);
     set_wc(13);
     set_hp(90);
     set_al(-180);
     set_aggressive(0);
     set_chat_chance(30);
     set_a_chat_chance(35);
    load_chat("Frederick grins evilly at you.\n");
     load_chat("Frederick slaps you across the face.\n");
     load_chat("Frederick says: We have you now!\n");
     load_chat("Frederick says: Surrender and we will let you live...\n");
     load_a_chat("Frederick says: You fool!  You can't be this stupid!\n");
     load_a_chat("Frederick slaps you across the face.\n");
     load_a_chat("Frederick punches you in the stomach.\n");
     load_a_chat("Frederick says: Surrender and I shall let you live...\n");
   }
}
