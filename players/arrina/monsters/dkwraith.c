 inherit "/obj/monster";
  reset(arg) {
   ::reset(arg);
   if (!arg) {
  object gold;
       set_name("wraith");
     set_short("A Dark Wraith");
     set_race( "spirit");
     set_long("A barely visible wraith.  You get the feeling that\n"
 +      "he used to be much like you, until he arrived here.\n");
     set_level(11);
     set_ac(9);
     set_wc(15);
     set_hp(165);
     set_al(-750);
     set_aggressive(0);
     set_chat_chance(20);
       gold=clone_object("obj/money");
     gold->set_money(random(76)+425);
     move_object(gold,this_object());
      load_chat("Wraith says: The evil here has overcome us.\n");
     load_chat("Wraith says: They feed on your fear here.\n");
      }
 }
