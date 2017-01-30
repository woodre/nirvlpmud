inherit "/players/vital/closed/std/monster.c";
reset(arg) {
  if(arg) return 0;
  ::reset(arg);
  set_name("dummy");
  set_alias("test dummy");
  set_short("A combat test dummy");
  set_long("Commands:  new_level  new_ac  reset_hp\n");
  set_wc(15);
  set_ac(10);
  set_hp(100);
  set_ep(5000);
  set_level(20);
}
id(str) {
  return str == "dummy" || str == "test dummy" || str == "combat test dummy";
}
init() {
  add_action("new_level", "new_level");
  add_action("new_ac", "new_ac");
  add_action("reset_hp", "reset_hp");
  ::init();
}
heart_beat() {
if(query_attack()) tell_object(query_attack(),"[Dummy: "+(100*query_hp()/query_mhp())+"%]\n");
  attack();
  ::heart_beat();
}
new_level(str) {
  int x;
  if(!str || !sscanf(str, "%d", x)) 
    write("Incorrect arguments.\n");
  else
    set_level(x);
  return 1;
}
new_ac(str) {
  int x;
  if(!str || !sscanf(str, "%d", x)) 
    write("Incorrect arguments.\n");
  else
    set_ac(x);
  return 1;
}
reset_hp() {
  set_hp(100);
  return 1;
}
