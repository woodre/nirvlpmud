inherit "/obj/monster";
int lvl,wcc;

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob2, ob3, gold;
 gold = clone_object("obj/money");
gold->set_money((4000));
  move_object(gold,this_object());
  ob2 = clone_object("/players/emerson/armor/toupee.c");
move_object(ob2,this_object());
     set_name("fredo");
set_short("Fredo Corleone");
     set_race( "human");
     set_alias("hutboss");
     set_long("Fredo is the wuss of the family. He eats his pizza in the\n"+
     "corner without saying much.  Something about him makes you think\n"+
     "he is weaker than he looks.\n");
     set_level(20);
     set_ac(17);
     set_wc(30);
     set_hp(500);
     set_al(-500);
     set_aggressive(0);
     set_whimpy();
     set_chat_chance(20);
     set_a_chat_chance(20);
     load_chat("Fredo quivers in the corner.\n");
     load_a_chat("Fredo says: You fool!  You can't be this stupid!\n");
     load_a_chat("Fredo slaps you across the face.\n");
     load_a_chat("Fredo punches you in the stomach.\n");
     load_a_chat("Fredo says: Surrender and I shall let you live...\n");
   }
}
