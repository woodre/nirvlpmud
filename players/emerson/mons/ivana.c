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
     set_name("ivana");
     set_alias("hutboss");
     multipleIds = ({"trump"});
	set_short("Ivana Trump");
     set_race( "human");
	set_long("Ivana is enjoying Pizza Hut's new stuffed crust pizza.\n"+
	"She looks like she's eating it the wrong way! Crust first!\n");
     set_level(20);
     set_ac(17);
     set_wc(30);
     set_hp(500);
     set_al(-1000);
     set_aggressive(0);
     set_whimpy();
     set_chat_chance(20);
     set_a_chat_chance(20);
	load_chat("Ivana eats her pizza the wrong way...crust first..\n");
	load_chat("Ivana says: Where did Donald go?\n");
     load_a_chat("Ivana says: You fool!  You can't be this stupid!\n");
     load_a_chat("Ivana slaps you across the face.\n");
     load_a_chat("Ivana punches you in the stomach.\n");
	load_a_chat("Ivana says: Tell Donald I still love him...\n");
   }
}
