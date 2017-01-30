inherit "/obj/monster";
int lvl,wcc;

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob2, ob3, gold;
 gold = clone_object("obj/money");
 gold->set_money(random(500));
  move_object(gold,this_object());
  ob2 = clone_object("/players/emerson/heal/spizza.c");
move_object(ob2,this_object());
     set_name("donald");
     set_alias("hutboss");
	set_short("Donald Trump");
     set_race( "human");
	set_long("Donald is enjoying Pizza Hut's new stuffed crust pizza.\n"+
	"He looks like he's eating it the wrong way! Crust first!\n");
     set_level(20);
     set_ac(17);
     set_wc(30);
     set_hp(500);
     set_al(-1000);
     set_aggressive(0);
     set_whimpy();
     set_chat_chance(20);
     set_a_chat_chance(20);
	load_chat("Donald eats his pizza the wrong way...crust first..\n");
	load_chat("Donald says: Where did Ivana go?\n");
     load_a_chat("Donald says: You fool!  You can't be this stupid!\n");
     load_a_chat("Donald slaps you across the face.\n");
     load_a_chat("Donald punches you in the stomach.\n");
	load_a_chat("Donald says: Tell Ivana I still love her...\n");
   }
}
