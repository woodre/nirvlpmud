inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2, ob3;
     ob = clone_object("obj/money");
     ob->set_money(random(100) + 50);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/weps/kobold_dag.c");
     move_object(ob2, this_object());
     ob3 = clone_object("/players/daranath/arms/kobold_jerkin.c");
     move_object(ob3, this_object());

     set_name("Kobold scout");
     set_short("Kobold Scout");
     set_alias("kobold");
     set_alt_name("scout");
     set_race( "humanoid");
     set_gender("male");
     set_long("A short, dog-faced humanoid, the kobold stands barely three\n"+
              "tall. Blue tattoos run across the kobolds arms and face. A\n"+
              "short leather jerkin is worn across his torso and the kobold\n"+
              "brandishes a rusty dagger at your face.\n");
     set_level(5);

     init_command("wear armor");
     init_command("wield weapon");

     set_ac(5);
     set_wc(8 + random(4));
     set_hp(60 + random(30));
     set_al(-700);
     set_aggressive(0);
     set_a_chat_chance(10);
     load_a_chat("Kobold slashes at you with the dagger.\n");
     load_a_chat("The Kobold swings the dagger at your head.\n");

   }
}
