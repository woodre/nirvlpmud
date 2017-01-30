inherit "/obj/monster";
int lvl,wcc;

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob2, ob3, gold;
   ob3 = clone_object("/players/emerson/heal/lpizza.c");
   move_object(ob3,this_object());
 gold = clone_object("obj/money");
gold->set_money(random(2000));
  move_object(gold,this_object());
set_short("Pizza The Hut");
set_name("pizza the hut");
set_alias("hut");
     set_race( "human");
set_long("This is the legendary Pizza The Hut, he is a slimey creature\n"+
"which is about 15 feet long,and at present he looks like a pizza on steroids!.\n"+
"Looking at him makes the hair on the back of you neck stick up in fear!\n");
     set_level(20);
     set_ac(20);
     set_wc(32);
     set_hp(1000);
     set_al(-1000);
     set_aggressive(1);
 /* fixed spell attack (there was no message) 2004.09.21 Forbin
set_chance(40);
set_spell_dam(20);
 */
add_spell("pepperoni",
          "Pizza the Hut tosses a few pieces of $R$pepperoni$N$ at you.\n",
          "Pizza the Hut tosses a few pieces of $R$peppweoni$N$ at #CTN#.\n",
          30,20);
     set_a_chat_chance(35);
load_a_chat("Pizza The Hut rolls over you!\n");
load_a_chat("You are crushed under Pizza The Hut's weight!\n");
   }
}
