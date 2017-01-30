#include "/players/mythos/closed/guild/def.h"
object tasker;
int h;

id(str) { return str == "scribe"; }

long() { write("A small elf.  His body is shrouded in a dark\n"+
                "cloak.  He seems to resent your intrusion.  You\n"+
                "had best do what you came to do and let him go\n"+
                "back to his work.\n"); }

reset(arg) { 
  if(arg) {  return; }
  h = 0; }

drop() { return 1;}
get() { return 0;}

init() {
  add_action("taskA","ask");
  add_action("magicA","The");
}

taskA(str) {
 if(!str) return 0;
  if(str && str == "scribe" && present(fear,tp) && tgl == 2 && tl > 6 &&
   h == 0) {
  tasker = tp;
  h = 1;
  tell_object(tasker,"The scribe looks up at you with a resentful glint\n"+
                     "in his eye.\n");
  call_out("task1",6);
  return 1;
  }
return 0; }

task1() {
  tell_object(tasker,"The scribe grunts and sighs.  He wipes his brow\n"+
                     "and closes the book he was reading.\n");
  call_out("task2",6);
return 1;}

task2() {
  tell_object(tasker,"The scribe speaks in a grouchy voice:\n"+
                     "    'So, you want to learn about magic....\n"+
                     "    'Well then... come back and tell me where\n"+
                     "    'it is...  Till then dont bother me....\n"+
                     "He turns back to his book.....\n");
  call_out("task3",21);
return 1;}

task3() {
if(present(tasker->query_real_name(),environment(this_object()))) {
  tell_object(tasker,"The scribe turns to you and says:\n"+
                     "    'Oh, sorry.  I forgot.  When you do\n"+
                     "    'have the answer come to me and \n"+
                     "    '<The answer>  <lies where you think it does>\n"+
                     "He turns back to the book.\n");
  }
  h = 0;
return 1;}

magicA(str) {
if(!str) return 0;
if(str && present(fear,tp) && tgl == 2 && tl > 6) {
  if(str == "magic is the base element, represented as fae,"+
            " that is a conduit between the infinite and energy.") { 
  write("The scribe glares at you. He cries out: CHEATER!!!\n");
  tp->zap_object(tp);
  return 1; }
 if(str != "answer lies within the ideas the Gods have placed within this universe.  Material, energy, and Infinity.  Those three cover all that there is in this universe and their boundaries are rather strict and concrete.") {
  write("The scribe laughs at you !\n");
  return 1;}
    write("The scribe grins at you and he points at you.\nYou feel strange....\n");
    present(fear,tp)->set_dark_level(3);
    present(fear,tp)->add_sacrifice(1000);
    present(fear,tp)->save_dark();
    present(fear,tp)->update_me();
  return 1;}
return 0;}
