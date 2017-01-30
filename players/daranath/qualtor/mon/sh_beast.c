inherit "/obj/monster";

reset(arg) {
  object gold;
   ::reset(arg);
   if (!arg) {

     set_name("Shadow Beast");
     set_short("A dark hound");
     set_alias("hound");
     set_alt_name("shadow beast");
     set_race("beast");
     set_gender("creature");
     set_long("A large hound bays at your approach into his area, dark\n"+
              "shadows swirling about its shoulders and torso. Baring\n"+
              "large white teeth, the hound seems more then just a\n"+
              "minor threat.\n");
     set_level(18);
     set_ac(15);
     set_wc(25 + random(5));
     set_hp(425 + random(75));
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(5);
     load_chat("The Shadow Beast threatens you with its barking.\n");
     load_chat("Shadows swirl about the shoulders of the hound.\n");

     gold = clone_object("obj/money");
     gold->set_money(random(400)+900);
     move_object(gold,this_object());
   }
  }

