inherit "/players/mythos/amon/forest/monster1";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2, ob3, ob4;
     ob = clone_object("obj/money");
     ob->set_money(random(2100)+500);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/qualtor/obj/kimono1.c");
     move_object(ob2, this_object());
     ob3 = clone_object("/players/daranath/qualtor/obj/obi.c");
     move_object(ob3, this_object());
     ob4 = clone_object("/players/daranath/qualtor/wep/gunsen.c");
     move_object(ob4, this_object());

     set_name("Shou Lung's Wife");
     set_short("An oriental woman kneels by the altar");
     set_alias("wife");
     set_alt_name("woman");
     set_race("human");
     set_gender("female");
     set_long("The woman by the altar is praying quietly for Shou Lung\n"+
              "to be successful in his quest to become a god. She is an\n"+
              "older woman, dressed in a black and silver kimono.\n"+
              "Shou Lung's Wife does not like to be disturbed.\n");

     init_command("wield gunsen");
     init_command("wear kimono");
     init_command("wear sash");

     set_level(20);
     set_ac(22);
     set_wc(30 + random(4));
     set_hp(500 + random(100));
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(5);
     set_a_chat_chance(25);
     load_chat("The older woman prays silently.\n");
     load_a_chat("Shou Lung's Wife moves with amazing speed and agility.\n");
     load_a_chat("Shou Lung's Wife avoids your pathetic attack.\n");
     load_a_chat("Shou Lung's Wife steps around your attack.\n");

   }
}
