
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  if(!present("sword")) {
    object sword;
    sword=clone_object("/players/feldegast/wep/hslayer");
    move_object(sword,this_object());
    init_command("wield sword");
  }
  set_name("King Tetros");
  set_alt_name("king");
  set_alias("tetros");
  set_short("King Tetros");
  set_long(
"King Tetros of the quadrians won his position the usual\n"+
"way: through sheer strength of arms.  His four limbed\n"+
"torso ripples with steel-like muscles covered by a\n"+
"loose purple felt robe with a mink lining.\n"
);
  set_gender("male");
  set_race("quadrian");
  set_level(21);
  set_wc(26);
  set_ac(22);
  set_hp(500);
  set_al(-1000);
  set_chat_chance(5);
  load_chat("King Tetros asks: How dare you disturb me, crippled one?\n");
  load_chat("King Tetros says: You cripples will die out soon enough.\n");
  set_a_chat_chance(5);
  load_a_chat("King Tetros weaves his weapons in a complicated dance designed\n"+
              "to mesmerize his foe.\n");
  set_chance(15);
  set_spell_mess1(
"King Tetros flexes his rippling muscles as he picks up his foe and slams\n"+
"the intruder head-first into the cave wall.\n");
  set_spell_mess2(
"King Tetros flexes his rippling muscles as he picks you up and slams\n"+
"you head-first into the cave wall.\n");
  set_spell_dam(40);
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
query_attrib(str) {
  return 10;
}
id(str) {
  return str=="quadrian lord" || ::id(str);
}
