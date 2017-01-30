#define ROOT "/players/daranath/outside/"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object ob;
 ob = clone_object("obj/money");
 ob->set_money(random(200)+650);
   /* Average coins of 750 per monster guide */
 move_object(ob, this_object());

     set_name("Rock hound");
     set_short("Rock hound");
     set_race("hound");
     set_gender("creature");
     set_long("This monstrosity strands about seven or eight feet tall, and\n"+
        "is hideously ugly.  Its shape is barely recognizable as humaniod.\n");
     set_level(14);
     set_ac(10 + random(3));
     set_wc(16 + random(4));
     set_hp(200 + random(50));
     set_al(-750);
     set_aggressive(1);
     set_chat_chance(4);
     set_a_chat_chance(10);
     load_chat("Rock hound growls at you\n");
     load_a_chat("Rock hound snaps at you with its jaws\n");

   }
}
