inherit "/obj/monster";

reset(arg) {
  object gold;
   ::reset(arg);
   if (!arg) {
move_object(clone_object("/players/daranath/qualtor/swamp/grolm_hammer.c"),this_object());

     set_name("Grolm");
     set_short("A Grolm watches the area");
     set_alias("grolm");
     set_alt_name("big grolm");
     set_race("goblin");
     set_gender("creature");
     set_long("The Grolm has features very similiar to those of the goblins that\n"+
          "also wander through the swamp. A large metal hammer is wielded\n"+
           "buy this one grolm, and he looks like he can use it.\n");

     init_command("wield hammer");

     set_level(10);
     set_ac(9);
     set_wc(14 + random(5));
     set_hp(145 + random(35));
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(5);
     load_chat("The grolm watches over the swamp protectivly.\n");

     gold = clone_object("obj/money");
     gold->set_money(random(250)+300);
     move_object(gold,this_object());
   }
  }

