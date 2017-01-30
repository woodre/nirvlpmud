inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
     ob = clone_object("obj/money");
     ob->set_money(random(100) + 50);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/weps/kobold_axe.c");
     move_object(ob2, this_object());

     set_name("Kobold berzerker");
     set_short("Kobold Berzerker");
     set_alias("kobold");
     set_alt_name("berzerker");
     set_race( "humanoid");
     set_gender("male");
     set_long("Snarling and howling wildly, the berzerker is the most\n"+
              "unpredictable of the kobold tribes. Tattoos that are evident\n"+
              "on the arms of the others run across the whole of the crazed\n"+
              "berzerking humanoid. A gleaming double handed axe is held\n"+
              "by the kobold savage.\n");
     set_level(9);

     init_command("wield axe");

     set_ac(7);
     set_wc(12 + random(4));
     set_hp(125 + random(30));
     set_al(-800);
     set_aggressive(1);
     set_a_chat_chance(25);
     load_a_chat("The savage steps back and howls at the sky.\n");
     load_a_chat("The berzerker swings the axe with a madness born of rage.\n");
     load_a_chat("The berzerker barks wildly during the fighting.\n");
     load_a_chat("The kobold drinks the blood from the blade of his axe.\n");

   }
}
