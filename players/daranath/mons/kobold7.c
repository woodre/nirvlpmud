inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
     ob = clone_object("obj/money");
     ob->set_money(random(100) + 50);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/weps/kobold_morn_star.c");
     move_object(ob2, this_object());

     set_name("elite guard");
     set_short("Kobold Elite Guard");
     set_alt_name("kobold");
     set_alias("guard");
     set_race( "humanoid");
     set_gender("male");
     set_long("Standing a bit taller then the average kobold, the elite\n"+
              "guard stands to protect the king from any harm.\n");
     set_level(10);

     init_command("wear armor");
     init_command("wield weapon");

     set_ac(8);
     set_wc(12 + random(4));
     set_hp(130 + random(30));
     set_al(-900);
     set_aggressive(0);
     set_chat_chance(15);
     set_a_chat_chance(10);
     load_chat("Elite Guard barks: The king is in danger!!!!\n");
     load_a_chat("Kobold swings at you with the morning star.\n");
     load_a_chat("Elite guard defends the king with his life.\n");
     load_a_chat("Kobold barks and challenges you with its tone.\n");

   }
}
