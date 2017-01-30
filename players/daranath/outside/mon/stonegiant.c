#define ROOT "/players/daranath/outside/"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob, ob2;
 ob = clone_object("obj/money");
 ob->set_money(random(100)+950);
 move_object(ob, this_object());
 ob2 = clone_object(ROOT+"wep/stone_club.c");
 move_object(ob2, this_object());

     set_name("Stone Giant");
     set_short("Stone giant");
     set_race( "giant");
     set_gender("creature");
     set_long("This monstrosity strands about seven or eight feet tall, and\n"+
        "is hideously ugly.  Its shape is barely recognizable as humaniod.\n");
     set_level(19);
     set_ac(15 + random(3));
     set_wc(26 + random(8));
     set_hp(420 + random(75));
     set_al(-950);
     set_aggressive(0);
     set_chat_chance(4);
     set_a_chat_chance(10);
     load_chat("Stone giant tightens his grip on his club in anticipation of a fight\n");
     load_a_chat("stone giant swings his club at your head\n");

   }
}
