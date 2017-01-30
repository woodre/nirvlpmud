
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("kruarg");
  set_alt_name("demon-lord");
  set_alias("demon");
  set_short("Kruarg, the Demon Lord");
  set_long(
"Kruarg is a giant humanoid demon, with bat-like wings folded behind his\n"+
"back and a pair of long horns curving out of his head.  Two long fangs,\n"+
"touched by dark red blood protrude out of the mouth of a surprisingly\n"+
"handsome faith.  His huge muscular body gleams an unusual shade of crimson\n"+
"and a touch of fear writhes its way into your heart at the sound of his\n"+
"voice.\n"
);
  set_gender("male");
  set_race("demon");
  set_level(30);
  set_wc(45);
  set_ac(35);
  set_hp(1000);
  set_al(-1500);
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
