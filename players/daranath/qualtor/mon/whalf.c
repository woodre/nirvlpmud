inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

move_object(clone_object("/players/daranath/qualtor/wep/sh_sword.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/obj/rat_on_stick.c"),this_object());

     set_name("Wild halfling");
     set_short("A halfling chews on a rat");
     set_alias("wild");
     set_race("halfling");
     set_gender("female");
     set_long("A dirty and sparsly dressed female halfling lives in this corner\n"+
              "of the Field of Triumph, living off of rats and other small\n"+
              "creatures she can catch. Wild red hair falls in tangles\n"+
              "about her shoulders and a series of dark tattoos run\n"+
              "across her arms and shoulders.\n");
     set_level(15);

     init_command("wield sword");

     set_ac(15);
     set_wc(24 + random(4));
     set_hp(350 + random(60));
     set_al(750);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(10);
     load_chat("The female halfling chews on a piece of rat.\n");
     load_a_chat("Wild Halfling slashes at you with her short sword.\n");

   }
}
