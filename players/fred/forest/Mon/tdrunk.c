#include "/players/fred/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("drunk");
set_alias("man");
set_race("human");
set_short("Village Drunk");
set_long(
  "  The village drunk is a dirty little man in his mid\n"+ 
  "thirties.  He is wearing old tattered clothes with\n"+
  "holes and stains all over them.  He stumbles around\n"+
  "town yelling meaningless phrases in between drinks.\n"); 
 
add_money(375); 
set_level(15);
set_hp(225);
set_al(600);
set_ac(12);
set_wc(20);
set_aggressive(0);
set_chat_chance(10);
  load_chat("The Drunk yells: The asparagus is tickling my toes!\n");
  load_chat("The town drunk hiccups.\n");
  load_chat("The Drunk yells: I just ate a handful of honey bees!\n");
  load_chat("The town drunk asks: hey buddy you got any spare change?\n");
  load_chat("The Drunk yells: Fred is a PUTZ!\n");
  load_chat("The Drunk yells: Did you see the size of that pigeon?\n");
  load_chat("The Drunk yells: My hair tastes like bananas!\n");
  load_chat("The Drunk yells: What are you looking at?\n");
  load_chat("The Drunk yells: Paint my bird bath!\n");
  load_chat("The Drunk yells: Buy my sea monkeys!\n");
  load_chat("The Drunk asks: Did you bring me back a monkey?\n");   
} 

  status random_move() {
  int n;
  string msg;
  if(!environment(this_object())) return 1;
  if(!query_attack()) {
  n = random(4);
switch(n) {
  case 0 : init_command("north");
           break;
  case 1 : init_command("east");
           break;
  case 2 : init_command("south");
           break;
  case 3 : init_command("west");
           break;
}
}
  call_out("random_move",10);
  return 1;
}


