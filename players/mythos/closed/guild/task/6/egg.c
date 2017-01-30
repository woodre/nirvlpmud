#include "/players/mythos/closed/guild/def.h"
object targ;
int kj, jh, qu;
inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("egg");
  set_short("A large black egg.");
  set_long("An egg that shines with a strange light.\n");
  set_weight(10000);
  set_value(1);
  kj = jh = qu = 0;
}

get() { return 0; }
drop() { return 1;}

nn() { environment(this_object())->set_n(); return 1;}

init() {
  ::init();
  add_action("essence","smear");
  add_action("llook","look");
  add_action("llook","exa");
  add_action("Aanswer","answer");
}

llook() {
  if(kj) {
  write("You can not see anything but the shining aura of NIGHT.\n");
  return 1;}
}

essence(str) {
  if(!str) return 0;
  if(str != "blood on egg") return 0;
  if(!jh) {
  jh = 1;
  targ = tp;
  write("You cut yourself and smear blood onto the egg.c\n");
  tp->add_hit_point(-10-random(10));
  call_out("blood",15); 
  return 1;}
return 1;}

blood() {
  tell_object(targ,"Smoke begins to rise from the egg.....\n");
call_out("blood2",15);
return 1;}

blood2() {
  tell_object(targ,"The smoke fills the room...\n");
call_out("blood3",10);
return 1;}

blood3() {
  tell_object(targ,"Suddenly you see a Dark Angel appear before you!\n"+
                   "Wings of Raven Black and skin of ivory white-\n"+
                   "Night stands before you!\n");
  kj = 1;
  call_out("blood4",3);
return 1;}

blood4() {
  tell_object(targ,"Night looks you over and smiles- a smile so\n"+
                   "beautiful and mysterious.\n"+
                   "She speaks:\n"+
                   "           Thank you for giving me life.\n"+
                   "           And in return I am in your debt.\n"+
                   "           Call upon me and I shall come.\n");
  call_out("blood5",10);
return 1;}

blood5() {
  tell_object(targ,"She pauses and looks deep into your eyes.\n"+
                   "Eyes of deepest violet pierce your soul.\n"+
                   "She speaks:\n"+
                   "           Ahhh... Seems you have come here to\n"+
                   "           gain power.  Very well. \n"+
                   "           Answer me this:\n"+
                   "           What was told to all to do with I?\n"+
                   "<type 'answer <whatever>'\n");
call_out("question",100);
return 1;}

question() {
  if(!qu) {  tell_object(targ,"She frowns and disappears......\n");
  destruct(this_object());
  return 1;}
return 1;}

Aanswer(str) {
  if(!str) return 0;
  if(str == "balberith" || str == "Balberith") {
write("CHEATER!\n"); tp->zap_object(tp);  destruct(this_object());
  return 1; }
  if(str == "not sleep" || str == "not sleep with" || str == "not sleep in") {
    qu = 1;
    tell_object(tp,"Night smiles and suddenly you feel invigorated!\n");
    tp->heal_self(1000);
    pp->set_dark_level(6);
    pp->add_sacrifice(1000);
    pp->save_dark();
    pp->update_me();
    write("Night vanishes!\n");
    destruct(this_object());
 return 1;}
return 0; }
