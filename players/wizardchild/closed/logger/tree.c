/* tree.c: tree to chop down for logger spell */
inherit "/obj/monster";
object attacker;
reset(arg) {
  if(arg) return 0;
  ::reset(arg);
  set_name("tree");
  set_alias("mooga");
  set_short("A large and weighty tree");
  set_long("An enourmous tree. By the looks of it, only a very powerful player could\n"
          +"chop it down.\n");
  set_wc(1);
  set_ac(10);
  set_hp(80);
  set_ep(1);
  set_level(5);
  set_dead_ob(this_object());
}
id(str) { return str == "tree" || str == "mooga"; }
heart_beat() {  
  if(this_object()->query_attack())
    attacker = this_object()->query_attack();
  else
    destruct(this_object());
  if(!present("logger pack", attacker)) 
    destruct(this_object());
  attack();
  ::heart_beat();
}
monster_died() {
  tell_object(attacker, "Monster_dead called\n");
  tell_object(attacker, "atk->query_name - "+attacker->query_name()+"\n");
  present("logger pack", attacker)->finish_tree(attacker);
  return 1;
}
