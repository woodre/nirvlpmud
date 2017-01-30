inherit "/obj/monster";
int lvl,wcc;

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob2, ob3, gold;
 gold = clone_object("obj/money");
gold->set_money((4000));
  move_object(gold,this_object());
  ob2 = clone_object("/players/emerson/obj/political.c");
move_object(ob2,this_object());
   ob3 = clone_object("/players/emerson/obj/instructions.c");
   move_object(ob3,this_object());
     set_name("vito");
set_short("Vito Corleone");
     set_race( "human");
set_long("The Godfather has been coming to Pizza Huts way too often lately.\n"+
"he has grown tremendous in his later years. His weight is only \n"+
"paled by his ravenous appetite.\n");
     set_level(20);
     set_ac(20);
     set_wc(33);
     set_hp(1000);
     set_al(-1000);
     set_chance(40);
     set_spell_dam(20);
     set_aggressive(0);
     set_chat_chance(20);
     set_a_chat_chance(20);
  load_chat("The Godfather says: Ill make him an offer he cant refuse.\n");
  load_chat("The Godfather shouts: Stellaaaaaa! Stellaaaaa! More wine!\n");
  load_chat("The Godfather stuffs another slice down his throat.\n");
     load_a_chat("The Godfather says: You fool!  You can't be this stupid!\n");
     load_a_chat("The Godfather slaps you across the face.\n");
     load_a_chat("The Godfather punches you in the stomach.\n");
     load_a_chat("The Godfather says: Surrender and I shall let you live...\n");
   }
}
