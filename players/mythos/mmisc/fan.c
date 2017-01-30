#define tp this_player()
#include "/players/mythos/closed/ansi.h"
inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("fan");
    set_short("A fancy looking fan.");
    set_long("A fancy hannd-fan.  There is something written on it.\n");
    set_read("Juliana's Tokyo's Original Fan.\n"+
             "Use it to cool oneself and come \n"+
             "back to Juliana's Tokyo <juliana_tokyo>\n");
    set_weight(1);
    set_value(2000);
}

query_save_flag() { return 0;}

init() { 
  ::init();
  add_action("juliana_tokyo","juliana_tokyo");
}

juliana_tokyo() {
  if(environment(tp)->realm() == "NT") {
  write("You can not get to Juliana's from here.\n"); return 1;}
  if(tp->query_sp() < 55+random(5)) { write("You do not have enough power!\n"); return 1;}
  tell_room(environment(tp),"A small man pops up from nowhere and bows.\n"+
            "He snaps his fingers......\n\n"+CYN+
            "               >>  >     >  FLASH  <     <  <<\n\n"+NORM+
            "A small limo pulls up.\n"+
            "The man opens the door and "+capitalize(tp->query_real_name())+
            " climbs into the car.\nThe limo drives off.\n\n");
  move_object(tp,"/players/mythos/mroom/juliana.c");
  command("look",tp);
  tell_room(environment(tp),"\n"+
  "A small limo pulls up and "+capitalize(tp->query_real_name())+" steps out.\n"+
  "The car drives off.\n");
tp->add_spell_point(-55-random(5));
destruct(this_object());
return 1;}
