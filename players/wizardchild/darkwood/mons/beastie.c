/* beastie.c: thing from forest */
/* working on new driver */
#define ROOT_DIR "players/wizardchild/darkwood/"
inherit "players/wizardchild/closed/monster2.c";
reset(arg) {
  ::reset(arg); /* must be called first */
  if(arg)
    return ;
  set_name("beast");
  set_alias("beast from underworld");
  set_short("A beast from the underworld");
  set_long("This dispicable creature is from the inner depths of Nirvana. How he\n"
          +"escaped to here, you may never know. But now, he is your problem.\n"
          +"In comparison to the other creatures here, this seems to be a juevenile.\n");
  set_level(19);
  set_hp(300+random(150));
  set_wc(20);
  set_ac(12);
  set_al(-800);
  set_drain_sp(1);
  set_nuke_ac(1);
  set_aggressive(random(2));
  set_money(2500+random(2500)); /* invisible to player this way */
  move_object(clone_object(ROOT_DIR+"obj/bones"), this_object());
}
id(str) { return str == "beast" || str == "beast from underworld"; }
