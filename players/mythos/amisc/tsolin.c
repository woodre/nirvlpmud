#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
#define user environment(this_object())
#define att user->query_attack()
#define attname att->query_name()

query_auto_load() { return "/players/mythos/amisc/tsolin.c:"; }
id(str) {return str == "brand"; }
short() {
    return "A Brand in the shape of Om"; }
long() {
    write("A brand in the palm of the hand.\n"+"Power seems to eminate from it.\n"+
    "\tThe name is "+HIR+"TSOLIN"+NORM+"\n"+"The brand may be'erase'ed.\n");
}
drop() {return 1;}

reset(arg) {
if(arg) return;
return;
}

init() {
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("call_tsolin"); add_verb("tsolin");
    add_action("erase_brand"); add_verb("erase");
#else
  add_action("call_tsolin", "tsolin");
  add_action("erase_brand", "erase");
#endif
  call_out("hb",3);
}

hb() {
/* 03/20/06 Earwax: this doesn't need to always be running */
  while(remove_call_out("hb") != -1);
if(user) {
    if(user->query_interactive() && !(user->query_ghost()) &&
    !present("mailread",user)) {
    call_other(user,"heal_self",-1); 
    if(random(7) == 1) tell_object(user,"Tsolin feeds....\n");} }
    call_out("hb",5+ random(4));
return 1;
}

call_tsolin() {
if(!att) { write("You must be in combat!\n"); return 1;}
  if(!att->query_soul()) {
    if(this_player()->query_sp() > 22) {
    say(tp+ "calls out a word of command!\n");
    say("\t\t T  S  O  L  I  N  !!!!\n");
    say("\n");
    say(HIR+"\tSSSSSSSSSSSSSSSSSSS\n");
    say(NORM+"\nYou see something invisible shoot through "+attname+"'s body!\n");
    write("You call out the name of the creauture:  TSOLIN!\n");
    write(HIR+"\n\tSSSSSSSSSSSSSSSSSSS\n\n"+NORM);
    write("You see something invisible shoot through "+attname+"'s body!\n");
    att->heal_self(-(random(23) + 15));
    call_other(user,"add_spell_point",-23);
    call_other(user,"add_hit_point",-7);
      write("You feel Tsolin suck some of your essence to live...\n");
  return 1; }
    else {
      write("You have no power left!\n");
      user->heal_self(-20);
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
