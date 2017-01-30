/* soak heal, 4 charge @ +20 (hp only) for 640 coins tox(12) */

#define TP this_player()
#define TPN TP->query_name()
#define WJUICE HIG+"w"+HIB+"i"+HIY+"l"+HIR+"d"+HIG+"e"+HIB+"r"+HIY+"b"+HIR+"e"+HIG+"r"+HIB+"r"+HIY+"y "+HIG+"j"+HIB+"u"+HIW+"i"+HIY+"c"+HIR+"e"+NORM
#include "/players/languilen/closed/ansi.h"

int number;

id(str) { return str == "juice" || str == "wilderberry juice" || str == "wild juice" || str == "bottle"; }
short() {
      return "A bottle of "+WJUICE;
}
is_heal() { return "soak"; }
query_potence() { return 20; }
query_save_flag() { return 1; }
query_value() { return (number * 160); }
long() {
     write("A bottle of "+WJUICE+".  The instructions look as if you\n\
are to 'slam' the 'juice'.  The bottle is bio-destructable so when\n\
you're done it'll just disappear!\n");
     if(number == 1){
        write("There is only 1 drink left.\n");
     } else {
        write("There are "+number+" drinks left.\n");
     }
}
reset(arg) {
  if(arg) return;
  number = 4;
}

init() {
  add_action("slam_juice","slam");
}

slam_juice(str) {
   if(str == "juice" || str == "bottle") {
      if(!call_other(this_player(),"drink_soft", 12)) return 1;
      write("You slam the bottle of "+WJUICE+".\n");
      say(TPN+" slams the bottle of "+WJUICE+".\n");
      number--;
      call_other(this_player(),"add_hit_point",20);
      call_other(this_player(),"recalc_carry");
      write("A "+HIG+"w"+HIB+"i"+HIY+"l"+HIR+"d"+NORM+" feeling runs through your body. "+HIG+"[ "+NORM+"Hp "+TP->query_hp() +HIG+" ]"+NORM+" \n");
      if(!number) {
         write("You drain the bottle of "+WJUICE+".\n");
         write("It crumbles into dust.\n");
         destruct(this_object());
      }
      return 1;
   }
   return 0;
}

get() { return 1; }

query_weight() {
  if(number > 2) return 2;
  return 1;
}

