#include "/players/mythos/closed/ansi.h"
#define tp this_player()
#define tpn tp->query_real_name()
#define TPN capitalize(tpn)
#define TO tell_object(tp
#define TR tell_room(environment(tp)
#define NOT TO,"A high pitch giggling sounds and you hear the words: WRONG!\n")

id(str) {return str == "still"; }

drop() {return 1;}
init() {
#ifndef __LDMUD__
  add_action("quiet");add_xverb("");
#else
 add_action("quiet", "", 3);
#endif
}

quiet(str) { 
string price;
if(str == "quit") { 
destruct(present("darm",tp)); tp->quit(); destruct(this_object()); return 1;}
  if(!sscanf(str,"grant %s",price)) {
      write("What?\n"); 
  return 1;}
  else {
  if(price == "blood") {
    TO,"You hear giggling and suddenly you feel the blood in you drain away!\n");
    TR,TPN+" screams with a sound of purest agony!\n");
    tp->add_hit_point(-(tp->query_hp() *10 /11));
    NOT;
  return 1;}
  if(price == "food") {
    TO,"The childish voice laughs at you....\n");
    tp->lower_attrib();
    tp->save_me();
    tp->reset(1);
    NOT;
  return 1;}
   if(price == "self" || price == "myself") {
  TO,"CHEATER!\n");
  tp->zap_object(tp);
NOT;
return 1; }
  if(price == "level") {
    TO,"You suddenly feel terrible.\n");
    comand("puke",tp);
    tp->add_exp(-5000 - random(10000));
    tp->reset(1);
    tp->save_me();
    NOT;
  return 1;}
  if(price == "soul") {
    TO,"Something giggles....\n");
    NOT;
    tp->zap_object(tp);
    destruct(present("darm",tp));
    destruct(this_object());
  return 1;}
  if(price == "life" || price == "one" || price == "oneself") {
    TO,"The voice is silent.....\n\tYou feel uneasy....\n\t\tThen....\n\n\n"+BOLD+
       "                           PAIN\n\n\n"+NORM+
       "Something sharp enters your soul and something is torn from you!\n");
    tp->add_exp(-30000-random(10000));
    tp->save_me();
    tp->reset(1);
    present("darm",tp)->doner();
    destruct(this_object());
  return 1;}
return 1;}
return 1;}
