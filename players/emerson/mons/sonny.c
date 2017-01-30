inherit "/obj/monster";
int lvl,wcc;

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob2, ob3, gold;
 gold = clone_object("obj/money");
gold->set_money((5000));
  move_object(gold,this_object());
     set_name("sonny");
     set_alias("hutboss");
set_short("Sonny Corleone");
     set_race( "human");
  set_long("Sonny Corleone, hot head of the Corleone crime family, would have\n"+ 
   "inherited his fathers vast empire...but all he got was lead poisoning.\n");
     set_level(20);
     set_ac(17);
     set_wc(30);
     set_hp(500);
     set_al(-1000);
     set_aggressive(0);
     set_whimpy();
     set_chat_chance(20);
     set_a_chat_chance(20);
     load_chat("Sonny drinks some wine and it sprinkles out his bullet ridden body.\n");
     load_chat("Sonny says: Damn those toll booth prices are murder!\n");
     load_a_chat("Sonny says: You fool!  You can't be this stupid!\n");
     load_a_chat("Sonny slaps you across the face.\n");
     load_a_chat("Sonny punches you in the stomach.\n");
     load_a_chat("Sonny says: Surrender and I shall let you live...\n");
   }
}
