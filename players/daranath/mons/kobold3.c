inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
     ob = clone_object("obj/money");
     ob->set_money(random(100) + 50);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/weps/kobold_spear.c");
     move_object(ob2, this_object());

     set_name("Kobold guard");
     set_short("Kobold Guard");
     set_alias("kobold");
     set_alt_name("guard");
     set_race( "humanoid");
     set_gender("male");
     set_long("A short, dog-faced humanoid, the kobold stands barely three\n"+
              "tall. Blue tattoos run across the kobolds arms and face. A\n"+
              "short leather jerkin is worn across his torso and the kobold\n"+
              "brandishes a short sword at your face.\n");
     set_level(7);

     init_command("wear armor");
     init_command("wield weapon");

     set_ac(7);
     set_wc(10 + random(4));
     set_hp(100 + random(30));
     set_al(-190);
     set_aggressive(0);
     set_a_chat_chance(10);
     load_a_chat("Kobold strikes at you with the spear.\n");
     load_a_chat("The Kobold lunges at you with the spear.\n");
     load_a_chat("Kobold barks and charges at you with the spear.\n");

   }
}
