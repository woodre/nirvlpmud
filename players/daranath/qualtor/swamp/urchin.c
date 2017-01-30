inherit "/obj/monster";

reset(arg) {
  object gold;
   ::reset(arg);
   if (!arg) {

     set_name("Swamp Urchin");
     set_short("A small goblin child wanders the swamp");
     set_alias("child");
     set_alt_name("critter");
     set_race("goblin");
     set_gender("creature");
     set_long("The small goblin child has been abandoned by his clan and left\n"+
              "to aimlessly wander the swamp forever. Its green skin seems\n"+
              "to blend in with the surrounding area.\n");
     set_level(4);
     set_ac(4);
     set_wc(8 + random(5));
     set_hp(75 + random(20));
     set_al(-350);
     set_aggressive(0);
     set_chat_chance(5);
     load_chat("The goblin child moves through the swamp with ease.\n");

     gold = clone_object("obj/money");
     gold->set_money(random(100)+75);
     move_object(gold,this_object());
   }
  }

