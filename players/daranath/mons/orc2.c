inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2, ob3;
     ob = clone_object("obj/money");
     ob->set_money(random(100) + 25);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/weps/halberd.c");
     move_object(ob2, this_object());
     ob3 = clone_object("/players/daranath/arms/stud_leath.c");
     move_object(ob3, this_object());

     set_name("orc");
     set_short("An Orc Guard");
     set_race( "humanoid");
     set_gender("male");
     set_long("The orc guard stands near the entrance to the stronghold,\n"+
              "watching over the wild tunnels in the UnderDark. The orc\n"+
              "is wearing a suit of leather and carries a Halberd.\n");
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
     load_a_chat("The Orc swings the halberd down at you.\n");

   }
}
