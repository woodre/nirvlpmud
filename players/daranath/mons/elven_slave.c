inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
     ob = clone_object("obj/money");
     ob->set_money(random(75) + 5);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/weps/work_sickle.c");
     move_object(ob2, this_object());
     set_name("worker");
     set_short("An elven slave worker");
     set_race( "elf");
     set_alias("slave");
     set_gender("male");
     set_long("The elf stands here tending to the fungal farm within the\n"+
              "UnderDark. Tattered clothing hugs his gaunt frame, and he\n"+
              "carries a rusted sickle, which you cannot imagine gives him\n"+
              "much protection within the wilds of the tunnels.\n");
     set_level(10);

     init_command("wield weapon");

     set_ac(8);
     set_wc(12 + random(4));
     set_hp(150 + random(40));
     set_al(100);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(30);
     load_chat("The elven worker tends to the lands.\n");
     load_chat("The elven worker watches over the farms.\n");
     load_chat("The elven slave looks up at you, trying to gauge you.\n");
     load_a_chat("The elf swiped at you with the sickle.\n");
     load_a_chat("The elven slave screams and tries to get away.\n");
     load_a_chat("The elven slave tries to fend you off with the sickle.\n");

   }
}
