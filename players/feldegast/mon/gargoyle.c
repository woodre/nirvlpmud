
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("gargoyle");
  set_alt_name("guardian");
  set_short("Gargoyle");
  set_long(
"This gruesomely demonic creature appears to have been shaped by some\n"+
"demented sculptor, then set to guard this place from intruders.  Long\n"+
"stone wings sprout from its back, sharp fangs protrude from its mouth\n"+
"and its tail is shaped like a morningstar.  Spikes protrude from its\n"+
"granite hide.\n"
);
  set_race("gargoyle");
  set_level(18);
  set_wc(26);
  set_ac(17);
  set_hp(450);
  set_al(-800);
  set_chat_chance(1);
  load_chat("The Gargoyle watches you in utter silence.\n");
  set_a_chat_chance(5);
  load_a_chat("The Gargoyle smashes you with its huge granite fists.\n");
  set_chance(15);
  set_spell_mess1(
"The Gargoyle whips its spiked tail across its opponents flesh.\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"\nThe Gargoyle's spiked tail whips through the air, smashing you\n"+
"with massive force and sharp spikes.\n\n"
  ); /* 1ST PERSON */
  set_spell_dam(15);
  set_dead_ob(this_object());
}
monster_died(ob) {
  tell_room(environment(),
"\nThe Gargoyle falls to the ground and shatters, revealing\n"+
"a ruby gem in its center.\n");
  move_object(clone_object("/players/feldegast/obj/gruby"), this_object());
}
