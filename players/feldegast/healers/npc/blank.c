
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("");
  set_alt_name("");
  set_alias("");
  set_short("");
  set_long(
);
  set_gender(""); /* "male","female" */
  set_race("");
  set_level(1);
  set_wc(1);
  set_ac(1);
  set_hp(1);
  set_al(0);
  set_chat_chance(5);
  load_chat("");
  set_a_chat_chance(0);
  load_a_chat("");
  set_chance(15);
  set_spell_mess1(
  ); /* 3RD PERSON */
  set_spell_mess2(
  ); /* 1ST PERSON */
  set_spell_dam(5);
}
