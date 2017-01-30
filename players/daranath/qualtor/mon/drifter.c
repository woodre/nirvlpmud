inherit "/obj/monster";

reset(arg) {
  object gold;
   ::reset(arg);
   if (!arg) {

     set_name("Drifter");
     set_short("A spirit drifts about the area");
     set_alias("spirit");
     set_alt_name("drifter");
     set_race("undead");
     set_gender("creature");
     set_long("A wandering spirit who has failed the task of becoming a mourning\n"+
              "coil drifts about the area, bringing a child breeze wherever it\n"+
              "goes. Spirits such as this one were nicknamed 'drifters' by the\n"+
              "former residents of Qual'tor, and the name stuck.\n");
     set_level(20);
     set_ac(17);
     set_wc(36 + random(4));
     set_hp(500 + random(200));
set_al(-(250+random(350)));
     set_aggressive(0);
     set_a_chat_chance(15);
     load_a_chat("The Drifter tears into your throat, drawing blood.\n");
     load_a_chat("The Drifter tries to make you one of the dead.\n");

     set_spell_mess2("The Drifter howls loudly, drawing blood.\n");
     set_spell_mess1("The Drifter casts an arcane spell, howling gleefully.\n");
     set_chance(10);
     set_spell_dam(60);

     gold = clone_object("obj/money");
     gold->set_money(random(5000)+2000);
/* average coins of 4500 is less then the 5000 allowed per monster guide */
     move_object(gold,this_object());
   }
  }

