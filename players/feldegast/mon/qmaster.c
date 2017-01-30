
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(!present("key")) move_object(clone_object("/players/feldegast/std/key"),this_object());
  if(!present("weapon")) {
    move_object(clone_object("/players/feldegast/wep/hammer"),this_object());
    move_object(clone_object("/players/feldegast/wep/hammer"),this_object());
  }
  if(arg) return;
  set_name("master");
  set_alt_name("blacksmith");
  set_alias("smith");
  set_short("Quadrian Master Blacksmith");
  set_long(
"This quadrian stands out as a giant among giants.  His muscular\n"+
"arms are as thick as barrels and his fierce expression warns all\n"+
"not to trifle with his fiery temper.  His long beard indicates\n"+
"his respected position in quadrian society and the scars on his\n"+
"chest indicate his many long years in devotion to the flames.\n"
);
  set_gender("male");
  set_race("quadrian");
  set_level(21);
  set_wc(24);
  set_ac(20);
  set_hp(500);
  set_al(-500);
  set_chance(15);
  set_spell_mess1(
"\nThe Quadrian Blacksmith strikes its foe with its silver hammers.\n"
  );
  set_spell_mess2(
"\nThe Quadrian Blacksmith strikes you with its silver hammers.\n"
  ); /* 1ST PERSON */
  set_spell_dam(40);
  add_money(5000);
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
