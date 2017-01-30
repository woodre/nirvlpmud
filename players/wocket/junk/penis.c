#include "/players/wocket/closed/ansi.h"
inherit "/obj/armor";

reset(arg){
    ::reset();
    set_id("penis");
    set_short("A detachable penis");
    set_long("A detachable penis used for all those male things that women\ncant do without it.. :)\n");
    set_weight(7); /* well we have to give it some size.. :P */
    set_ac(1);
    set_value(-1);
    set_type("misc");
}

init(){
    add_action("pwear","wear");
    add_action("punwear","remove");
}

int punwear(string str){
if (str == "penis"){
    if(worn == 1){
    if(environment(this_object()) == this_player()){
    write("You disattach your penis.\nYour body rocks from a massive orgasm.\nThe woman in you has returned.\n");
    this_player()->set_gender("female");
    worn_by = 0;
    worn = 0;
    call_other(this_player(),"remove",this_object());
    return 1;
    }
  return 0;
}
  return 0;
}
return 0;
}
int pwear(string str){
if (str == "penis"){
    if((string) this_player()->query_gender() == "male"){
    write("You already have a penis.. you cant wear another..\n");
    return 1;
}
    write("You attach your penis.\nYou begin to feel MANLY..\n");
    call_other(this_player(),"wear",this_object());
    worn_by = this_player();
    worn = 1;
    this_player()->set_gender("male");
    return 1;
}
return 0;
}

