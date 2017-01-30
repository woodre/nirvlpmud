inherit "obj/monster";
reset(arg)  {
  object armor;
  ::reset(arg);
  if(arg) return;
  set_name("woman");
  set_alias("food");
  set_race("human");
  set_short("A Terrified Woman");
  set_long("A terrified woman....  You smell her fear and you hunger....\n");
  set_hp(10);
  set_level(1);
  set_al(0);
  set_wc(13);
  set_ac(15);
  set_ep(0);
  set_wimpy();
  set_aggressive(0);
  set_chat_chance(20);
  set_frog();
  set_dead_ob(this_object());
  load_chat("You need to feed....\n");
  load_chat("The woman screams....\n");
  call_out("rmove",10);
}

rmove() {
switch(random(4)) {
  case 0 : command("north"); break;
  case 1 : command("east"); break;
  case 2 : command("south"); break;
  case 3 : command("west"); break;
}
call_out("rmove",10+random(10));
return 1;}

monster_died() {
object ob;
  ob = this_object()->query_attack();
  tell_object(ob,"You are transported else where.....\n");
  tell_object(ob,"Task complete....\n");
  move_object(ob,"/players/mythos/closed/guild/assembly.c");
return 0;}
