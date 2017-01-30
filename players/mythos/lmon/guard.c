inherit "obj/monster";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("guard");
  set_race("human");
  set_short("A Guard");
  set_long("A Buff Guard- he keeps the peace!\n");
  set_hp(1000);
  set_level(30);
  set_al(0);
  set_wc(50);
  set_ac(10);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_chat_chance(1);
  load_chat("The Guard slowly glances over the room.\n");
  load_chat("People pass by looking for information.\n");
  load_chat("People pass by looking for information.\n");
  load_chat("Someone quietly passes by...\n");
  call_out("check",3);
}

check() {
  if(this_object()->query_attack()) {
    tell_room(environment(this_object()),"\nThe Guard growls and tosses you away!\n\n");
    move_object((this_object()->query_attack()),"/players/mythos/lroom/pun.c");
    call_out("check",3);
    return 1;}
  call_out("check",3);
return 1;}
