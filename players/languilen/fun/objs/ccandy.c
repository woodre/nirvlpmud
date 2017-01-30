/* food heal, 5 charges @ +18 (hp only) for 960 coins tox(8) */

#define TPN this_player()->query_name()  /* player name  */
#include "/players/languilen/closed/ansi.h"

int number;

id(str) { return str == "candy" || str == "cotton" || str == "cotton candy"; }
short() { return "A ball of "+HIM+"cotton candy"+NORM; }
is_heal() { return "stuff"; }
query_potence() { return 18; }
query_save_flag() { return 1; }
query_value() { return (number * 192); }
long() {
	write("A huge ball of "+HIM+"cotton candy"+NORM+" all swirled around and around.\n"+
	      "It looks delicious!");
        if(number == 1){
           write("You may 'eat' only 1 more bite.\n");
        } else {
           write("You may 'eat' another "+number+" bites.\n");
        }
}
reset(arg) {
     if(arg) return;
     number = 5;
}

init() {
     add_action("eat_candy","eat"); }

eat_candy(str) {
     if(str == "candy" || str == "cotton candy") {
        if(!call_other(this_player(),"eat_food", 8)) return 1;
        write("You take a bite of cotton "+HIM+"candy"+NORM+" and it melts in your mouth.\n");
        say(TPN+" takes a bite of cotton "+HIM+"candy"+NORM+".\n");
        number--;
        call_other(this_player(),"add_hit_point",18);
        call_other(this_player(),"recalc_carry");
        write("You can feel the sugar rush through your body. "+HIM+"["+NORM+" Hp "+this_player()->query_hp() +HIM+" ]"+NORM+"\n");
        if(!number) {
           write("You finish off the "+HIM+"cotton candy"+NORM+".  Boy was that good!\n");
           destruct(this_object());
        }
        return 1;
     }
     return 0;
}

get() { return 1; }

query_weight() {
     if(number > 2) return(number/2);
     return 1;
}
