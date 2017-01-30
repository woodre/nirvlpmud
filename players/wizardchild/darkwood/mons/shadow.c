/* shadow.c: monster in shadows */
#define ROOT_DIR "players/wizardchild/darkwood/"
inherit "obj/monster";
reset(arg) {
  if(arg)
    return ;
  ::reset(arg);
  set_name("shadow");
  set_alias("something");
  set_short(0);
  set_long("Hiding discretely behind the trees, this \"thing\" seems to be eyeing you.\n"
          +"Though you can see no more than his eyes, you can tell that he would be a\n"
          +"formidable opponent.\n");
  load_chat("Something lurks in the shadows...\n");
  set_chat_chance(10);
/* Changed level from 21 to 14 until monster can be fixed by WC - Snow */
  set_level(14);
  set_hp(440+random(161));
  set_wc(20);
  set_ac(25); /* armor is high because he is hard to see */
  set_al(-100-(random(81)));
  move_object(clone_object(ROOT_DIR+"obj/nighteye"), this_object());
  move_object(clone_object(ROOT_DIR+"obj/darksuit"), this_object());
}
id(str) { return str == "shadow" || str == "something"; }
