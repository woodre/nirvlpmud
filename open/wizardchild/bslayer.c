/* bslayer.c: slayer boy from forest */
/* working on new driver */
#define ROOT_DIR "players/wizardchild/darkwood/"
inherit "players/wizardchild/closed/monster2.c";
reset(arg) {
  ::reset(arg);
  if(arg)
    return ;
  set_name("slayer");
  set_alias("beast");
  set_short("A beast slayer");
  set_long("This unGodly creature is assigned the task of \"pruning\" the weak beasts\n"
          +"from their society. By his immense size, even larger than the big beasts,\n"
          +"you can tell that anything would have serious trouble fighting him.\n");
  set_level(24);
  set_hp(420+random(130));
  set_wc(24+random(3));
  set_ac(18);
  set_al(-800-random(200));
  randomized_load();
  set_can_kill(1); /* ensure they kill */
  set_money(3000+random(option_exp_values()*3));
  move_object(clone_object(ROOT_DIR+"obj/bones"), this_object());
}
id(str) { return str == "beast" || str == "slayer" || str == "beast slayer"; }
