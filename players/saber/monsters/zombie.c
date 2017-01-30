inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(101) + 550);
  move_object(gold,this_object());

     set_name("zombie");
     set_short("A rotting zombie");
     set_race( "undead");
     set_gender("creature");
     set_long("The decaying corpse of a zombie.\n"+
       "It looks very old.\n");
     set_level(12);
     set_ac(8 + random(3));
     set_wc(15 + random(3));
     set_hp(160 + random(40));
     set_al(-500);
     set_aggressive(1);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("A bit of flesh falls from the zombie.\n");
     load_chat("The zombie stares at you with rotting eyes.\n");
     load_chat("The zombie moans.\n");
     load_a_chat("A bit of flesh falls from the zombie.\n");
     load_a_chat("The zombie flails wildly at you.\n");
   }
}

init()  {
  ::init();
  add_action("west","west");
        }

west()  {
  write("A zombie stumbles in front of you.\n");
  return 1;
        }
