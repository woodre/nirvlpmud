#include "/players/snow/dervish/def.h"

dervish_whirlwind(){
  int amt, num;
  object me, myob, whirlwind;
  me = this_player();
  myob = present("dknight_ob", me);
  num = me->query_level();
    if(me->query_ghost()) {
      write("You lack substance.\n"); return 1; }
    if(me->query_attrib("pie") < 15){
      write("You lack devotion.\n"); return 1; }
    if(present(WHIRLWIND,me)){
      write("You already have a whirlwind surrounding you.\n"); return 1; }
    if(num > 9 && num < 69){
      switch(num){
        case 0.. 4:    amt = 30; break;
        case 5..10:    amt = 35; break; 
        case 11..14:    amt = 40; break;
        case 15..19:    amt = 50; break;
        case 20..69:    amt = 50; break;
        }
       if(me->query_sp() < amt) {
         write("You do not have enough energy.\n"); return 1;}
     whirlwind = clone_object("/players/pestilence/closed/newguild/whirlwind.c");
     whirlwind->set_time(TP->query_level());
     move_object(whirlwind, TP);
     write(BOLD+RED+"\tYou scream and spin around summoning a giant Whirlwind of sand around you!\n"+OFF+OFF);
     say(BOLD+RED+me->query_name()+" screams and spins around summoning a giant Whirlwind of sand around "+me->query_objective()+"\n"+OFF+OFF);  
     TP->add_spell_point(-amt);
     return 1; }
    else {
      switch(num){
        case 0..2:    amt = 10; break;
        case 3..5:    amt = 15; break;
        case 6..7:    amt = 20; break;
        case 8..10:    amt = 25; break;
        }
       if(me->query_sp() < amt) {
         write("You do not have enough energy.\n"); return 1;}
      whirlwind = clone_object("/players/snow/dervish/objects/whirlwind1.c");
      whirlwind->set_time(TP->query_level());
      move_object(whirlwind, TP);
      write(BOLD+RED+"\tYou scream and spin around summoning a Whirlwind of sand around you!\n"+OFF+OFF);
      say(BOLD+RED+me->query_name()+" screams and spins around summoning a Whirlwind of sand around "+me->query_objective()+"\n"+OFF+OFF);  
      me->add_spell_point(-amt);
      return 1; }      
    }
