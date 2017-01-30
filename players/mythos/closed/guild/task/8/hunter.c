#include "/players/mythos/closed/guild/def.h"
int g;
string target;
object targ;
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("lord");
  set_alias("tarrant");
  set_race("hunter");
  set_short("Lord of the Nexus- the "+RED+"HUNTER"+NORM);
  set_long("A man of regal stature.  He wears his brown hair down and long-\n"+
           "shoulder length.  He stands- 6' 5- and seems to tower over \n"+
           "everything, no matter how tall.  His eyes of opale silver, pierce\n"+
           "your soul and seem to prob the darkest secrets in your heart and \n"+
           "soul.  Darkness seems to obey him....\n");
  set_hp(2000);
  g = 1;
  set_level(30);
  set_heal(20,5);
  set_al(-1000);
  set_wc(100);
  set_ac(20);
  set_aggressive(0);
  set_chance(90);
  set_spell_dam(200);
  set_spell_mess1("A shadow envelopes everything!\n");
  set_spell_mess2("A shadow wraps itself around you....\n"); 
  set_mult(2);
  set_mult_dam1(50);
  set_mult_dam2(100);
  set_mult_chance(90);
}

heart_beat() {
  ::heart_beat();
  if(this_object()->query_attack()) {
    if(present(fear,this_object()->query_attack())) {
    tell_room(environment(this_object()),"The HUNTER snaps his fingers...\n");
      present(fear,this_object()->query_attack())->set_switch(0);
      tell_object(this_object()->query_attack(),"Your powers vanish!\n");
      g = 0;
      present(fear,this_object()->query_attack())->set_dark_level(1);
      (this_object()->query_attack())->add_exp(-1000000);
      (this_object()->query_attack())->save_me();
      (this_object()->query_attack())->reset(1);
      (this_object()->query_attack())->quit();
      }
    if((this_object()->query_attack())->query_npc()) {
      this_object()->zap_object(this_object()->query_attack());
    }
  }
}

set_target(str) { target = str; targ = present(str,environment(this_object())); }

start() {
  if(g) {
  call_out("task",15); }
return 1;}

task() {
  tell_object(targ,"The man looks you over slowly....\n"+
                   "The hair on your arms stand on end....\n");
  if(g) {
  call_out("task2",21); }
return 1;}

task2() {
  tell_object(targ,"The man laughs- a very cold laugh.\n");
  if(g) {
  call_out("task3",6); }
return 1;}

task3() {
  tell_object(targ,"The man speaks: "+
                   "      So it seems that Samial's little project\n"+
                   "      has grown and caught on a bit.\n");
  if(g) {
  call_out("task4",6); }
return 1;}

task4() {
  tell_object(targ,"     So have you learned anything, little one?\n"+
                   "     Do you understand what you are? Or what you\n"+
                   "     are missing?\n");
  if(g) {
  call_out("task5",10); }
return 1;}

task5() {
  tell_object(targ,"He laughs evilly.\n"+
                   "    You are pitiful.  You know nothing of what you\n"+
                   "    see.  You know nothing of what you are nor does it\n"+
                   "    seem that you care.  Let me show you something\n"+
                   "He gestures...\n");
  if(g) {
  call_out("task6",5); }
return 1;}

task6() {
  tell_object(targ,"Power fills you!  And for an instant you understand...\n"+
                   "You glance down at yourself and your vision multiplies\n"+
                   "ten fold, then a hundred, and then a thousand fold, till\n"+
                   "the mysteries of DNA is before your eyes.  You understand\n"+
                   "that the very substance of life and death, of energy and\n"+
                   "infinity is before you.\n");
  if(g) {
  call_out("task7",6); }
return 1;}

task7() {
  tell_object(targ,"He speaks:\n"+
                   "     What you have is the key to everything.  The\n"+
                   "     answers to the very structure of the universe.\n"+
                   "     Before you not even the GODS may contain you- for\n"+
                   "     the power of the GODS is in your hands.\n"+
                   "He gestures again.\n");
  if(g) {
  call_out("task8",3); }
return 1;}

task8() {
  tell_object(targ,"A DREAD appears before you.\n"+
                   "The man speaks:\n"+
                   "     Know the dread and then 'dest' him\n");
  move_object(clone_object("/players/mythos/closed/guild/task/8/dread.c"),
      environment(this_object()));
return 1;}

task9() {
  if(g) {
  call_out("task10",6); }
}

task10() {
  tell_object(targ,"The man nods...\n"+
                   "     The simple act of desting that the gods have\n"+
                   "     is in your hands.  But I doubt that you truly\n"+
                   "     comprehend.  You don't see as you should see.\n"+
                   "     Well leave me...  Search blindly as the rest\n"+
                   "     of them.\n");
  if(g) {
  call_out("task11",15); }
return 1;}

task11() {
  tell_object(targ,"He vanishes...\nAnd you feel empty....\n"+
                   "You feel power infuse you, but you wonder....\n"+
                   "           Are you really following what should be?\n");
  present(fear,targ)->set_dark_level(8);
  present(fear,targ)->save_dark();
   targ->add_exp(-500000);
  command("uu",targ);
  targ->reset(1);
   command("save",targ);
  move_object(targ,"/players/mythos/closed/guild/forest/rooms/castle6.c");
  call_out("wait",21);
return 1;}

wait() {
  destruct(environment(this_object()));
  destruct(this_object());
return 1;}
