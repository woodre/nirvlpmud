inherit "obj/monster";

reset(arg) {
  if(arg) return;
  set_name("mythos");
  set_alias("shut");
  set_short("Mythos");
  set_long("Nothing much");
  set_level(1000);
  set_wc(69);
  set_ac(69);
}

   init() { add_action("shuts","shuts");
}
shuts() {
  call_other("/obj/shut.c","shut",1);
return 1; }

sch() { init_command("shuts",this_object()); return 1; }

heart_beat() {
  sch();
  ::heart_beat();
}
