inherit "obj/monster.c";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("dufus");
  set_short("Dufus the Practice Monster");
  set_long("He doesn't look very intelligent to you.\n");
  set_hp(1);
  set_wc(1);
  set_ac(1);
  set_level(1);
  set_dead_ob(this_object());
}
monster_died()
{
  object ob;
  ob=clone_object("/players/feldegast/junk/practice.c");
  move_object(ob,environment());
  destruct(present("corpse",environment()));
}
heart_beat()
{
  ::heart_beat();
  if(attacker_ob) attacker_ob->add_hit_point(100);
}
init() {
  add_action("cmd_cs","cs");
}
cmd_cs(arg)
{
  int l,hp,w,a;
  int al;
  notify_fail("Usage: <level> <hp> <wc> <ac> <al>\n");
  if(!arg) return 0;
  if(sscanf(arg,"%d %d %d %d %d",l,hp,w,a,al)!=5) return 0;
  set_level(l);
  set_hp(hp);
  set_wc(w);
  set_ac(a);
  set_al(al);
  write("Ok.\n");
  return 1;
}
