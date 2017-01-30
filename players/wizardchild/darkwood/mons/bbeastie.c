/* bbeastie.c: larger thing */
/* working on new driver */
#define ROOT_DIR "players/wizardchild/darkwood/"
inherit "players/wizardchild/closed/monster2.c";
reset(arg) {
  ::reset(arg);
  if(arg)
    return ;
  set_name("beast");
  set_alias("big beast");
  set_short("A big beast from the underworld");
  set_long("Noticeably larger than the others, this creature is evidentally an elder\n"
          +"among these beasts' ranks. His immense size is unlike anything you have\n"
          +"ever seen on Nirvana before.\n");
  set_level(21);
  set_hp(350+random(150));
  set_wc(20+random(5));
  set_ac(14+random(3));
  set_al(-900);
  set_nuke_wc(1);
  set_steal_arm(1);
  set_steal_weap(1);
  set_mirror(1);
  set_money(3000+random(3000));
  move_object(clone_object(ROOT_DIR+"obj/bones"), this_object());
}
id(str) { return str == "beast" || str == "big beast" || str == "big beast from underworld"; }
