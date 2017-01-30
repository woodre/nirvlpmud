inherit "/obj/monster";

int DEATH;

reset(arg) {
   ::reset(arg);
   DEATH = 4;
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(101) + 550);
  move_object(gold,this_object());

     set_name("nightmare");
     set_short("A horrible nightmare");
     set_race( "spirit");
     set_alias("ghost");
     set_long("Your mind can not comprehend the sheer horror of the nightmare.\n");
     set_level(13);
     set_ac(9 + random(3));
     set_wc(16 + random(3));
     set_hp(1000);
     set_al(-900);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The nightmare SCREAMS!\n");
     load_chat("The nightmare creeps towards you.\n");
     load_a_chat("The nightmare stares into your eyes.\n");
     load_a_chat("The nightmare SCREAMS!\n");
     load_a_chat("The nightmare extends is razor sharp claws.\n");
   }
}

query_death()   { return DEATH; }
set_death(str)  { DEATH = str;  }
