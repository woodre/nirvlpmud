inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

     set_name("Female kobold");
     set_short("Kobold Female");
     set_alias("kobold");
     set_alt_name("female");
     set_race("humanoid");
     set_gender("female");
     set_long("The female kobold runs about tending to the needs of the\n"+
              "males in the tribe. Her dark red skin matches that of the\n"+
               "rest of the kobolds, but no tattoos are evident.\n");
     set_level(5);
     set_ac(5);
     set_wc(7 + random(4));
     set_hp(60 + random(30));
     set_al(-450);
     set_aggressive(0);

   }
}
