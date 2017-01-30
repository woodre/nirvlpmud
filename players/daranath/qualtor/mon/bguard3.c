inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2, ob3, ob4;
     ob = clone_object("obj/money");
     ob->set_money(random(100) + 50);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/qualtor/obj/crimson_hak.c");
     move_object(ob2, this_object());
     ob3 = clone_object("/players/daranath/qualtor/obj/crimson_uni.c");
     move_object(ob3, this_object());
     ob4 = clone_object("/players/daranath/qualtor/wep/naginata.c");
     move_object(ob4, this_object());

     set_name("Crimson Guardsman");
     set_short("A Guard is pulling on his trousers");
     set_alt_name("guard");
     set_race("human");
     set_gender("male");
     set_long("The Crimson Guard serves as bodyguard for the Warlord who is\n"+
              "sieging this mountain. The guard member seems to be\n"+
              "enjoying himself a bit too much to be working right now.\n");

     init_command("wield nagi");
     init_command("wear uni");
     init_command("wear hakama");

     set_level(17);
     set_ac(15);
     set_wc(25);
     set_hp(400 + random(50));
     set_al(-900);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(25);
     load_chat("The Guard happily says: Whose next?\n");
     load_chat("The Guard winks at you suggestivly.\n");
     load_chat("The Guard ties off his trousers and grins at you.\n");
     load_a_chat("The Guard screams at you in a language you don't understand.\n");
     load_a_chat("The Guard growls: This is what you get for ruining my fun!!!\n");
     load_a_chat("Crimson Guard hits you with a crushing blow.\n");
     load_a_chat("The Guard spits in your face.\n");

   }
}
