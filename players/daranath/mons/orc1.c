inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
     ob = clone_object("obj/money");
     ob->set_money(random(100) + 100);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/weps/sh_sword.c");
     move_object(ob2, this_object());

     set_name("orc");
     set_short("An angry Orc");
     set_race( "humanoid");
     set_gender("male");
     set_long("Standing just over 6 feet tall and wearing dirty clothes,\n"+
              "the orc looks as if he was a cross between a pig and a human.\n"+
              "He steps closer to you, branishing a short sword in your\n"+
              "face.\n");
     set_level(8);

     init_command("wear armor");
     init_command("wield weapon");

     set_ac(7);
     set_wc(11 + random(4));
     set_hp(110 + random(30));
     set_al(-250);
     set_aggressive(1);
     set_a_chat_chance(10);
     load_a_chat("Orc grunts at you.\n");
     load_a_chat("The Orc swings the sword at your head.\n");

   }
}
