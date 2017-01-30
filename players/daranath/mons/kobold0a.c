inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
move_object(clone_object("/players/daranath/closed/stuff/kat/nurse_dress.c"),this_object());
move_object(clone_object("/players/daranath/closed/stuff/kat/nurse_hat.c"),this_object());
move_object(clone_object("/players/daranath/closed/stuff/kat/nurse_shoe.c"),this_object());
move_object(clone_object("/players/daranath/closed/stuff/kat/nurse_stock.c"),this_object());
   if (!arg) {

     set_name("Kobold Nurse");
     set_short("Kobold Nurse");
     set_alias("kobold");
     set_alt_name("nurse");
     set_race("humanoid");
     set_gender("female");
     set_long("The kobold nurse is wearing an outfit taken from a human nurse during\n"+
              "one of the many kobold raids. The nurse takes care of the wounded\n"+
              "warriors within the tribe.\n");

     init_command("wear shoes");
     init_command("wear stockings");
     init_command("wear uniform");
     init_command("wear hat");

     set_level(5);
     set_ac(5);
     set_wc(7 + random(4));
     set_hp(60 + random(30));
     set_al(-450);
     set_aggressive(0);

   }
}
