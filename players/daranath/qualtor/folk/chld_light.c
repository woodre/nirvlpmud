inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
     ob = clone_object("obj/money");
     ob->set_money(random(100) + 50);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/arms/halo.c");
     move_object(ob2, this_object());

     set_name("Child of Light");
     set_short("Children of the Crystal (light)");
     set_alias("children");
     set_alt_name("child");
     set_race("human");
     set_gender("male");
     set_long("The children of the crystal have taken residence here\n"+
              "waiting for the time when the Angels come back to take\n"+
              "Qual'tor back to its former glory.\n");
     set_level(7);

     init_command("wear armor");
     init_command("wield weapon");

     set_ac(8);
     set_wc(10 + random(4));
     set_hp(90 + random(30));
     set_al(random(350));
     set_aggressive(0);
     set_chat_chance(2);
     set_a_chat_chance(10);
     load_chat("The child of light cries for the destruction of Qual'tor.\n");
     load_chat("The child of light prays to Tarkos.\n");
     load_chat("The child of light wants to be an angel.\n");
     load_a_chat("The child of light prays to Tarkos for your forgiveness.\n");

   }
}
