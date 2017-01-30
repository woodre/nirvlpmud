inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2, ob3, ob4;
     ob = clone_object("obj/money");
     ob->set_money(random(100) + 50);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/qualtor/wep/jitte.c");
     move_object(ob2, this_object());
     ob3 = clone_object("/players/daranath/qualtor/obj/crimson_uni.c");
     move_object(ob3, this_object());
     ob4 = clone_object("/players/daranath/qualtor/wep/tetsubo.c");
     move_object(ob4, this_object());

     set_name("Crimson Guardsman");
     set_short("A Guard stands by nervously");
     set_alt_name("guard");
     set_race("human");
     set_gender("male");
     set_long("The Crimson Guard serves as bodyguard for the Warlord who is\n"+
              "sieging this mountain. The guard member seems to be\n"+
              "enjoying himself a bit too much to be working right now.\n");

     init_command("wield tets");
     init_command("wear uni");

     set_level(17);
     set_ac(15);
     set_wc(25);
     set_hp(400 + random(50));
     set_al(-900);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(25);
     load_chat("The Guard says: Hurry up guys, lets get outa here.\n");
     load_chat("The Guard turns to you and says: You want a turn?\n"+
               "                                 It'll be 100 coins.\n");
     load_a_chat("The Guard screams at you in a language you don't understand.\n");
     load_a_chat("The Guard growls: This is what you get for ruining my fun!!!\n");
     load_a_chat("Crimson Guard hits you with a crushing blow.\n");
     load_a_chat("The Guard spits in your face.\n");

   }
}
