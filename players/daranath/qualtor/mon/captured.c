inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

move_object(clone_object("/players/daranath/qualtor/obj/tat_cloak.c"),this_object());

     set_name("Kidnapped Female");
     set_short("A female cowers upon the bedding");
     set_alias("female");
     set_race("human");
     set_gender("female");
     set_long("A young human female lies about the furs and cloak set aside for\n"+
              "her bedding. She is wearing little more then a dirty and torn\n"+
              "cloak that barely covers half of her body. Large blackened\n"+
              "welts are spread over her small form, signs of severe\n"+
              "beatings at the hands of her tormentors.\n");
     set_level(10);

     init_command("wear cloak");

     set_ac(8);
     set_wc(13 + random(4));
     set_hp(150 + random(60));
     set_al(1000);
     set_aggressive(0);
     set_chat_chance(15);
     load_chat("The young female cries into her bedding.\n");
     load_chat("The young female begs to you for help.\n");

   }
}
