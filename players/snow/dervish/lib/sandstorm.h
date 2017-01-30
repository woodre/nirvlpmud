#include "/players/snow/dervish/def.h"

dervish_sandstorm(){
  object me, myob, sandstorm;
  int x;
  me = this_player();
  myob = present(GID, me);
    if(me->query_ghost()) {
      write("You lack substance.\n"); return 1; }
    if(me->query_attrib("pie") < 30){
      write("You lack devotion.\n"); return 1; }
    if(myob->query_spell_delay()) {
      write("You cannot cast a spell again so soon.\n"); return 1; }
    if(environment(me)->query_no_fight()) {
      write("You can not cast this spell here.\n"); return 1; }
    x=65+random(20);
    if(me->query_sp() < x)
    {
       write("You do not have enough energy.\n"); return 1;}
    if(me->query_level() < 19 || (me->query_extra_level() < 15)) {
       write("You are not high enough level to summon a sandstorm yet.\n"); return 1; } 
    if(present(SANDSTORM, environment(me))){
       write("There is already a sandstorm in the room.\n"); return 1; }
   write(BOLD+RED+"\tYou scream wildly as a Sandstorm sweeps into the room.\n"+OFF);
   say(BOLD+RED+me->query_name()+" screams wildly as a Sandstorm sweeps into the room.\n"+OFF);
   sandstorm = clone_object("players/snow/dervish/objects/sandstorm.c");
   sandstorm->set_time((TP->query_level()/2) + (TP->query_extra_level()/2)+
                      (TP->query_attrib("int")/2) +
                      (TP->query_attrib("wil")/2)); 
                      
   move_object(sandstorm, environment(me));
   me->add_spell_point(-x);
   myob->add_spell_delay(200 - ((TP->query_level()*4) + (TP->query_extra_level()/2) +
                                (TP->query_attrib("pie")/2) +
                                (TP->query_attrib("wil")/2) +
                                (TP->query_attrib("int")/2) +
                                (TP->query_attrib("dex")/2)));
  return 1; }

    
