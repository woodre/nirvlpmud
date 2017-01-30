inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2, ob3, ob4;
     ob = clone_object("obj/money");
     ob->set_money(random(2100) + 500);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/qualtor/obj/kimono2.c");
     move_object(ob2, this_object());
     ob3 = clone_object("/players/daranath/qualtor/obj/hairpins.c");
     move_object(ob3, this_object());
     ob4 = clone_object("/players/daranath/qualtor/obj/sandles.c");
     move_object(ob4, this_object());

     set_name("Shou Lung's Mistress");
     set_short("A young woman lounges upon the furs");
     set_alt_name("woman");
     set_race("human");
     set_gender("female");
     set_long("The young woman lounging upon the furs is wearing a dark red\n"+
           "robe that has been left wide open. She smiles as you look upon her\n"+
             "and almost seems to invite you to lie on the furs with her.\n"+
             "Shou Lung's Mistress is always in a playful mood.\n");

     init_command("wear sandles");
     init_command("wear kimono");
     init_command("wear hairpins");

     set_level(19);
     set_ac(20);
     set_wc(30 + random(4));
     set_hp(500 + random(100));
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(25);
     load_chat("The younger woman mocks the older one silently.\n");
     load_chat("The young woman lounges sexily upon the furs.\n");
     load_chat("The young woman shifts slightly, exposing herself to you.\n");
     load_a_chat("Shou Lung's Mistress moves with amazing speed and agility.\n");
     load_a_chat("Shou Lung's Mistress avoids your pathetic attack.\n");
     load_a_chat("Shou Lung's Mistress steps around your attack.\n");

   }
}
