
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(!present("weapon")) {
    get_weapon();
    get_weapon();
  }
  if(arg) return;
  set_name("Quadrian Warrior");
  set_alt_name("warrior");
  set_alias("quad");
  set_short("Quadrian Warrior");
  set_long(
"This warrior is of a species of four-armed savages that live in\n"+
"these mountains.  The quadrians are a proud race of warriors and\n"+
"metalworkers who scavenge off of their prosperous neighbors.\n"+
"This quadrian wears furs across its muscular body and wields\n"+
"numerous deadly weapons.\n"
);
  if(!random(2)) set_gender("male"); else set_gender("female");
  set_race("quadrian");
  set_level(20);
  set_wc(20);
  set_ac(18);
  set_hp(450);
  set_al(-200);
  add_money(2500+random(1000));
  set_a_chat_chance(5);
  load_a_chat(
"The Quadrian Warrior weaves its weapons in a complicated pattern\n"+
"designed to mesmerize its foe.\n");
  set_chance(15);
  set_spell_mess1(
"The Quadrian Warrior catches its foe in a many-limbed bearhug.\n");
  set_spell_mess2(
"The Quadrian Warrior crushes your ribs in a many-limbed bearhug.\n"
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
get_weapon() {
  object wep;
  switch(random(3)) {
    case 0: wep=clone_object("/players/feldegast/wep/battleaxe");
            break;
    case 1: wep=clone_object("/players/feldegast/wep/scimitar");
            break;
    default: wep=clone_object("/players/feldegast/wep/hammer");
             break;
  }
  move_object(wep,this_object());
}
