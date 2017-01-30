inherit "/obj/monster";

reset(arg) {
  object gold;
   ::reset(arg);
   if (!arg) {
move_object(clone_object("/players/daranath/qualtor/swamp/grolm_spear.c"),this_object());

     set_name("Grolm");
     set_short("A Grolm stands guard");
     set_alias("grolm");
     set_alt_name("critter");
     set_race("goblin");
     set_gender("creature");
     set_long("The Grolm has features very similiar to those of the goblins that\n"+
           "also wander the swamp. A short, crude spear is held in one hand\n"+
           "while he searches the swamp.\n");

     init_command("wield spear");

     set_level(6);
     set_ac(5);
     set_wc(10 + random(5));
     set_hp(75 + random(20));
     set_al(-800);
     set_aggressive(0);
     set_chat_chance(5);
     load_chat("The Grolm threatens you with the crude spear.\n");

     gold = clone_object("obj/money");
     gold->set_money(random(200)+175);
     move_object(gold,this_object());
   }
  }

