inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

move_object(clone_object("/players/daranath/qualtor/wep/rusty_dag.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/obj/tat_cloak.c"),this_object());

     set_name("Ratling");
     set_short("A large rat looks at you nervously");
     set_alias("rat");
     set_alt_name("ratling");
     set_race("rodent");
     set_gender("male");
     set_long("A large rat crawls about the floor, although not everything is normal\n"+
              "about this creature. He is wearing a tattered cloak and his extremly\n"+
              "humanoid hands wield a rusting dagger.\n");
     set_level(12);

     init_command("wield dagger");
     init_command("wear cloak");

     set_ac(9);
     set_wc(15 + random(4));
     set_hp(150 + random(60));
     set_al(-900);
     set_aggressive(0);

   }
}
