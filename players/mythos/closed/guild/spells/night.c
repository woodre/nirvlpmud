#include "/players/mythos/closed/ansi.h"
inherit "players/mythos/closed/guild/spells/monster2";
int figh, timer;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("night");
  set_race("special");
  set_short(BOLD+"Night"+NORM);
  set_long("A naked beautiful woman with great "+HIB+"RAVEN"+NORM+" wings\n"+
           "standing out from her back- a "+BOLD+"DARK ANGEL"+NORM+".\n");
  set_hp(250);
  set_level(30);
  move_object(clone_object("/players/mythos/closed/guild/spells/yamato.c"),this_object());
  init_command("wield yamato");
  set_al(-500);
  set_wc(20);
  set_ac(2);
  set_heal(3,13);
  set_can_kill(1);
  set_aggressive(0);
  set_a_chat_chance(2);
  load_a_chat("Night smiles....you shiver in fear....\n");   

  set_mult(2);
  set_mult_chance(20);
  set_mult_dam1(5);
  set_mult_dam2(5);
  figh = 0;
  timer = 0;  
  call_out("check",3);
}

check() {
   if(!environment(this_object())) return 1;
if(!present(owner,environment(this_object()))) {
tell_room(environment(this_object()),"With a fluttering of wings...\n"+BOLD+"\tNIGHT LEAVES\n"+NORM);
move_object(this_object(),environment(find_player(owner)));
tell_room(environment(this_object()),"With a fluttering of wings...\n"+BOLD+"\tNIGHT ENTERS\n"+NORM);
}
if(this_object()->query_hp() < 80) {
tell_object(find_player(owner),
"Night tells you: I must leave, for the battle has wounded me\n"+
"                 almost to the point of no return.\n"+
"                 Fare ye well......\n");
tell_room(environment(this_object()),"With a fluttering of wings...\n"+BOLD+"\tNIGHT VANISHES\n"+NORM);
destruct(present("yamato",this_object()));
destruct(this_object());
return 1;}
if(timer > 180) {
tell_object(find_player(owner),
"Night tells you: I must leave, for the my time here is up.\n"+
"                 Fare ye well......\n");
tell_room(environment(this_object()),"With a fluttering of wings...\n"+BOLD+"\tNIGHT VANISHES\n"+NORM);
destruct(present("yamato",this_object()));
destruct(this_object());
return 1;}
if(present(owner,environment(this_object()))->query_attack() && figh == 0) {
this_object()->attack_object(present(owner,environment(this_object()))->query_attack());
(present(owner,environment(this_object()))->query_attack())->attack_object(this_object());
figh = 1;}
else { figh = 0;}
timer = timer + 1;
call_out("check",3);
return 1;}
