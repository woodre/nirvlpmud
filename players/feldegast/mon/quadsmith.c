
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(!present("weapon")) {
    move_object(clone_object("/players/feldegast/wep/hammer"),this_object());
    move_object(clone_object("/players/feldegast/wep/hammer"),this_object());
  }
  if(arg) return;
  set_name("Quadrian Blacksmith");
  set_alt_name("blacksmith");
  set_alias("smith");
  set_short("Quadrian Blacksmith");
  set_long(
"This stout and muscular quadrian stands with his chest bare and\n"+
"his numerous burn scars for all to see.  As a rite of initiation,\n"+
"quadrian blacksmiths scar their chests with red hot pokers to\n"+
"show their devotion to the flames.  They are fearsome opponents\n"+
"in battle due to their upper body strength and indifference to\n"+
"pain.\n"
);
  set_gender("male");
  set_race("quadrian");
  set_level(20);
  set_wc(21);
  set_ac(17);
  set_hp(475);
  set_al(-200);
  set_chat_chance(5);
  load_chat("The Quadrian Blacksmith hammers on a piece of metal.\n");
  set_a_chat_chance(5);
  load_a_chat("The Quadrian Blacksmith gets red in the face and bellows in rage.\n");
  set_chance(15);
  set_spell_mess1(
"\nThe Quadrian Blacksmith strikes its foe with its silver hammers.\n"
  );
  set_spell_mess2(
"\nThe Quadrian Blacksmith strikes you with its silver hammers.\n"
  ); /* 1ST PERSON */
  set_spell_dam(20);
}
heart_beat() {
  ::heart_beat();
  if(attacker_ob) {
    already_fight=0;
    attack();
    already_fight=0;
    attack();
    already_fight=0;
    attack();
  }
}
