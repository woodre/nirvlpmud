inherit "obj/monster";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("mythos");
  set_race("human");
  set_short("Mythos");
  set_long("This is Mythos the wiz.\n");
  set_hp(1000);
  set_level(60);
  set_al(-1000);
  set_wc(30);
  set_ac(20);
  set_aggressive(0);
}
is_player() { return 1;}
query_npc() { return 0;}
query_interactive() { return 1;}
query_real_name() { return "mythos"; }
