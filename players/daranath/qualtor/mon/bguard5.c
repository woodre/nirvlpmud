inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2, ob3, ob4;
     ob = clone_object("obj/money");
     ob->set_money(random(200) + 50);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/qualtor/obj/crimson_gau.c");
     move_object(ob2, this_object());
     ob3 = clone_object("/players/daranath/qualtor/obj/crimson_uni.c");
     move_object(ob3, this_object());
     ob4 = clone_object("/players/daranath/qualtor/wep/naginata.c");
     move_object(ob4, this_object());

     set_name("Crimson Guardsman");
     set_short("A member of the Crimson Guard");
     set_alt_name("guard");
     set_race("human");
     set_gender("male");
     set_long("The Crimson Guard serves as bodyguard for the Warlord who is\n"+
              "sieging this mountain. The guard member seems to be\n"+
              "standing watch over the quiet streets of Qual'tor.\n");

     init_command("wield nagi");
     init_command("wear uni");
     init_command("wear gauntlets");

     set_level(18);
     set_ac(16);
     set_wc(25 + random(4));
     set_hp(400 + random(100));
     set_al(-1000);
     set_aggressive(0);
     set_a_chat_chance(25);
     load_a_chat("Crimson Guard yells at you for interupting his duties.\n");
     load_a_chat("The Guard screams at you in a language you don't understand.\n");
     load_a_chat("Crimson Guard hits you with a crushing blow.\n");

   }
}
