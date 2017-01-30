inherit "/obj/monster";
int wcc;
object person;

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob2, ob3, gold;
 gold = clone_object("obj/money");
  gold->set_money(random(100));
  move_object(gold,this_object());
  ob2 = clone_object("/players/saber/closed/weapons/rapier.c");
move_object(ob2,this_object());
 ob3 = clone_object("/players/saber/closed/armor/stdleather.c");
move_object(ob3,this_object());
  person = this_object()->query_attack();
   wcc = (person->query_level()) + 4;
     set_name("fredrick");
     set_short("Fredrick the Bandit");
     set_race( "human");
     set_long("A tall, blond haired man with a killer and wicked blue eyes.\n");
     set_level(6);
     set_ac(5);
     set_wc(wcc);
     set_hp(90);
     set_al(-180);
     set_aggressive(0);
     set_chat_chance(30);
     set_a_chat_chance(35);
    load_chat("Fredrick grins evilly at you.\n");
     load_chat("Fredrick slaps you across the face.\n");
     load_chat("Fredrick says: We have you now!\n");
     load_chat("Fredrick says: Surrender and we will let you live...\n");
     load_a_chat("Fredrick says: You fool!  You can't be this stupid!\n");
     load_a_chat("Fredrick slaps you across the face.\n");
     load_a_chat("Fredrick punches you in the stomach.\n");
     load_a_chat("Fredrick says: Surrender and I shall let you live...\n");
   }
}
