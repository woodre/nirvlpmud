#include "/players/mythos/closed/guild/def.h"
int quest1, quest2, quest3;

id(str) { return str == "sakura" || str == "tree" || str == "cherry blossoms"  ||
                 str == "blossoms"; }

query_weight() { return 10000;}

query_value() { return 0; }

get() { return 0;}

short() { return "A Sakura"; }

long() {  write("A large ancient Cherry Blossom- The Sakura.\n"+
                "It is huge, a tree of proportions that overwhelm\n"+
                "your senses.  There is something odd however....\n"+
                "most cherry blossoms have white or pink  petals/\n"+
                "leaves...this one's are "+HIR+"red"+NORM+".\n");
        }

reset(arg) {
  if(arg) return;
  quest1 = quest2 = quest3 = 0;
  call_out("effects",12);
}

set_quest1() { quest1 = 1; }
set_quest2() { quest2 = 1; }
set_quest3() { quest3 = 1; }

init() {
  add_action("dig","dig");
}

effects() {
string msg;
  if(!environment(this_object())) return 1;
if(random(2) == 0) {
  switch(random(4)) {
    case 0: 
    case 1: msg = "A "+HIR+"red"+NORM+" petal falls to the ground.\n"; break;
    case 2: msg = "The wind blows and you shiver.\n"; break;
    case 3: msg = "You sense that something is wrong.\n"; break;
  }
  tell_room(environment(this_object()),msg);
}
call_out("effects",12);
return 1;}

dig() {
int h;
h = 0;
  if(quest1) h = 5;
  if(quest2) h = h + 40;
  if(quest3) h = h + 40;
  if(random(100) < h) {
    write("You find a small piece of red coral.\n");
    move_object(clone_object("/players/mythos/closed/guild/task/5/coral.c"),tp);
    write("Cardiou nods and waves a hand.\n");
    move_object(tp,"/players/mythos/closed/guild/assembly.c");
    command("look",tp);
    environment(this_object())->over();
  return 1; }
  switch(random(5)) {
    case 0: tp->lower_attrib(); tp->reset(1); tp->save_me(); break;
    case 1: tp->heal_self(-50); break;
    case 2: tp->add_spell_point(-100); break;
    case 3: if(present("cardiou",environment(this_object()))) {
            present("cardiou",environment(this_object()))->attack_object(tp);
            }
            break;
    case 4: tp->add_exp(-1000); tp->reset(1); tp->save_me(); break;
    }
  write("You feel great pain as Cardiou strikes at you!\n");
return 1;}
    
