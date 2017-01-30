
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Officer Husslebeck");
  set_alt_name("officer");
  set_alias("husslebeck");
  set_short("Officer Husslebeck");
  set_long(
"Officer Husslebeck is a young, awkward policeman who\n"+
"looks uncomfortable in his uniform.  Husselbeck is always\n"+
"eager to help his superiors and frequently winds up running\n"+
"unimportant errands for them.  You notice his shoelace is\n"+
"untied.\n"
);
  set_gender("male");
  set_race("human");
  set_level(10);
  set_wc(15);
  set_ac(7);
  set_hp(155);
  add_money(400+random(100));
  set_al(350);
  set_chat_chance(5);
  load_chat("Officer Husslebeck says: If anybody can catch the killer,\n"+
            "                         it's Inspector Bumstead.\n");
}
