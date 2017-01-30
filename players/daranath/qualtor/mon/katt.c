inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob;

move_object(clone_object("/players/daranath/qualtor/wep/ironwood.c"),this_object());
ob = clone_object("obj/money");
ob->set_money(random(1000)+500);
move_object(ob,this_object());

     set_name("Katt the halfling");
     set_short("Katt sits on the lip of the fountain");
     set_alias("katt");
     set_alt_name("Katt");
     set_race("halfling");
     set_gender("female");
     set_long("A small halfling female with long, brown curls that fall about\n"+
              "her shoulders, Katt spends most of her time here within the\n"+
              "garden of heroes. Staring into the water within the\n"+
              "fountain, a person can learn a lot about themselves.\n");
     set_level(15);

     init_command("wield staff");

     set_ac(15);
     set_wc(24 + random(4));
     set_hp(350 + random(60));
     set_al(1000);
     set_aggressive(0);
     set_chat_chance(12);
     set_a_chat_chance(10);
     load_chat("Katt stares into the fountain and sighs deeply.\n");
     load_chat("Katt gives a friendly little wave in your direction.\n");
     load_chat("Katt says: Isn't the Garden beautiful?\n");
     load_a_chat("Katt says: Why are you doing this?\n");

   }
}
