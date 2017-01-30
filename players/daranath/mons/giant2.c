inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
     ob = clone_object("obj/money");
     ob->set_money(random(100) + 950);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/weps/spik_club.c");
     move_object(ob2, this_object());
     set_name("fomorian");
     set_short("An ugly Fomorian");
     set_race( "giant");
     set_gender("creature");
     set_long("This monstrosity strands about seven or eight feet tall, and\n"+
        "is hideously ugly.  Its shape is barely recognizable as humaniod.\n");
     set_level(16);
     set_ac(13 + random(3));
     set_wc(20 + random(4));
     set_hp(380 + random(40));
     set_al(-500);
     set_aggressive(0);
     set_chat_chance(4);
     set_a_chat_chance(10);
     load_chat("Fomorian drools on itself.\n");
     load_chat("Fomorian slaps his club down against the ground in a threatening manner.\n");
     load_chat("Fomorian growls at you in its own disfigured way.\n");
     load_a_chat("Fomorian tries to attack but confuses itself too much.\n");
     load_a_chat("Fomorian roars and charges.\n");

   }
}
