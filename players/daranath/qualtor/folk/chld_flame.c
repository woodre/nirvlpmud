inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
     ob = clone_object("obj/money");
     ob->set_money(random(100) + 50);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/qualtor/newstuff/obj/flame_amulet.c");
     move_object(ob2, this_object());

     set_name("Child of Flame");
     set_short("Children of the Crystal (flame)");
     set_alias("children");
     set_alt_name("child");
     set_race("human");
     set_gender("male");
     set_long("The children of the crystal have taken residence here\n"+
              "waiting for the time when the Pyromancers come back to take\n"+
              "Qual'tor back to its former glory.\n");
     set_level(7);

     init_command("wear amulet");

     set_ac(8);
     set_wc(10 + random(4));
     set_hp(90 + random(30));
     set_al(random(0));
     set_aggressive(0);
     set_chat_chance(2);
     set_a_chat_chance(10);
     load_chat("The child of flame prays to Pyron.\n");
     load_chat("The child of flame wants to be an pyromancer.\n");
     load_a_chat("The child of flame tries to cast a spell, but fails.\n");

   }
}
