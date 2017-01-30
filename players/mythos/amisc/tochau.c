#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
#define user environment(this_object())
#define att user->query_attack()
#define attname att->query_name()

query_auto_load() {
    return "/players/mythos/amisc/tochau.c:"; }
id(str) {return str == "brand"; }
short() {
    return "A Brand in the shape of Om"; }
long() {
    write("A brand in the palm of the hand.\n"+
        "Power seems to eminate from it.\n"+"\tThe name is "+
        GRN+"TOCHAU"+NORM+"\n"+"The brand may be 'erase'ed.\n");
}
drop() {return 1;}

reset(arg) {
  if(arg) return;
  return;
}

init() {
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("call_tochau"); add_verb("tochau");
    add_action("erase_brand"); add_verb("erase");
#else
  add_action("call_tochau", "tochau");
  add_action("erase_brand", "erase");
#endif
  call_out("hb",3);
}

hb() {
  while(remove_call_out("hb") != -1); /* 03/20/06 Earwax */
if(user) {
    if(user->query_interactive() && !(user->query_ghost()) &&
       !present("mailread",user)) {
    call_other(user,"heal_self",-1 - random(2)); 
    if(random(7) == 1) tell_object(user,"Tochau feeds....\n"); } }
    call_out("hb",3 + random(7));
return 1;
}

call_tochau() {
if(!att) { write("You must be in combat!\n"); return 1;}
  if(!att->query_soul()) {
    if(this_player()->query_sp() > 29) {
    say(tp+ "calls out a word of command!\n");
    say("\t\t T  O  C  H  A  U  !!!!\n");
    say("\n");
    say(GRN+"\tS\tL\tA\tS\tH\n");
    say(NORM+"\nYou see something invisible rake across "+attname+"'s face!\n");
    write("You call out the name of the creauture:  TOCHAU!\n");
    write(GRN+"\n\tS\tL\tA\tS\tH\n\n"+NORM);
    write("You see something invisible rake across "+attname+"'s face!\n");
    att->heal_self(-(random(30) + 21));
    call_other(user,"add_spell_point",-30);
    call_other(user,"add_hit_point",-10);
      write("You feel Tochau suck some of your essence to live...\n");
  return 1; }
    else {
      write("You have no power left!\n");
      user->heal_self(-30);
      write("You feel the strain of using power too much....\n"+
        "You feel weak and you topple.....\n");
      say("You see "+tp+" topple over in weakness!\n");
    return 1; }
  return 1; }
  else {
    write("You may not call upon this power against another player!\n");
    call_other(user,"add_hit_point",-15);
  return 1; }
return 1;
}

erase_brand() {
   if(present("priest",environment(user))) {
    write("The Priest softly incants something.....\n"+
      "He then takes out a knife and cuts the brand out of you rhand!\n");
    say("The Priest intones softly....\n"+
      "He takes out a knife and cuts out the brand!");
    call_other(user,"add_hit_point",-10);
    call_other(user,"add_spell_point",-20);
    destruct(this_object());
return 1;}
  write("You need a Shinto Priest to do that!\n");
return 1;}
