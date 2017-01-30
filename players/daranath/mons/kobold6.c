inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
     ob = clone_object("obj/money");
     ob->set_money(random(100) + 50);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/arms/kobold_shield.c");
     move_object(ob2, this_object());

     set_name("Kobold captain");
     set_short("Kobold Captain");
     set_alias("kobold");
     set_alt_name("captain");
     set_race( "humanoid");
     set_gender("male");
     set_long("The kobold captain has the same redish scaly skin as the\n"+
              "rest of the kobolds, but he carries a shield decorated with\n"+
              "the blueish markings the others wear. He seems to direct the\n"+
              "others in their daily tasks.\n");
     set_level(9);

     init_command("wear shield");
     init_command("wield weapon");

     set_ac(7);
     set_wc(12 + random(4));
     set_hp(125 + random(30));
     set_al(-400);
     set_aggressive(0);
     set_a_chat_chance(10);
     load_a_chat("The captain swings at you with the shield.\n");
     load_a_chat("The kobold captain barks orders for the others to help him.\n");
     load_a_chat("The captain sneers at your pitiful attacks.\n");

   }
}
