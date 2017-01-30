#include "/players/pestilence/define.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("dna pill");
  set_alias("pill");
  set_short("DNA Enhancement");
set_long(
"A pill much like steroids.\n");
  set_value(500);
  set_weight(2);
}


init () {
   ::init() ;
     add_action ("enrage","enrage");
     }

    enrage(str){
    int dam,bug,myob;
    object ob, ob2, att, ob3;
    dam = 1;
    if(environment() != this_player()) return;  
    if (present("enrage")) {
         write("Your already enraged.\n");
         return 1; }
/*
    if (!str && !USER->query_attack()){
        write("You can be only enraged when fighting.\n");
        return 1;
    }
        else if(!str && USER->query_attack()){
                att = USER->query_attack();
        }

    else{ 
                att = present(str, environment(USER)); 
        }
    if (present("enrage")) {
         write("Your already enraged.\n");
         return 1; }
    if(USER->query_sp() < 35){
        write("You do not have the spell points available for this spell.\n");
        return 1; 
    }
*/
if (!(present("enrage"))) {
  ob3 = clone_object("/players/pestilence/test/enrage.c");
  move_object(ob3,USER);
}



    write("You become "+HIR+"ENRAGED"+NORM+" with hate.\n");
    say(USER->query_name() +" becomes "+HIR+"ENRAGED"+NORM+" with hate.\n");
      destruct(this_object());
     return 1;
}


