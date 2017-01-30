inherit "/obj/monster";
int lvl,wcc;

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob2, ob3, gold;
 gold = clone_object("obj/money");
gold->set_money((4000));
  move_object(gold,this_object());
  ob2 = clone_object("/players/emerson/obj/straw.c");
move_object(ob2,this_object());
     set_name("michael");
     set_alias("hutboss");
set_short("Michael Corleone");
     set_race( "human");
     set_long("Michael eats his pizza through a straw on account of his broken jaw.\n"+
     "He is sitting calmly, knowing full well that the vast Corleone crime\n"+
     "empire will one day be his.  He has a spagetti stain on his forehead.\n");
     set_level(20);
     set_ac(17);
     set_wc(30);
     set_hp(500);
     set_al(-1000);
     set_aggressive(0);
     set_whimpy();
     set_chat_chance(20);
     set_a_chat_chance(20);
     load_chat("Michael stares at you and over acts.\n");
     load_chat("Michael says: Do they have Pizza Huts in Cuba?\n");
     load_a_chat("Michael says: You fool!  You can't be this stupid!\n");
     load_a_chat("Michael slaps you across the face.\n");
     load_a_chat("Michael punches you in the stomach.\n");
     load_a_chat("Michael says: Surrender and I shall let you live...\n");
   }
}
