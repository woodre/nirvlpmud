#include "/players/wocket/closed/ansi.h"
inherit "obj/weapon";

reset(arg){
    set_id("bow");
    set_short("A finely carved bow");
    set_long("blah\n");
    set_weight(2);
}
drop(){return 1;}

init(){
     add_action("wield","wield");
    add_action("draw","draw");
    add_action("relax","relax");
    add_action("release","release");
    add_action("release","rb");
}


int draw(string str){
if (str == "bow"){
"/obj/weapon.c"->wield(str);
return 1;
}
notify_fail("What would you like to draw?\n");
return 0;
}

int release(){
object attacker;
attacker = (object) this_player()->query_attack();
if(!attacker){
  notify_fail("You must be in combat to fire your bow.\n");
  return 0;
}
write("You draw back your arrow with great force.\nThe arrow leaps from its string ripping the air around it.\nPain fills "+(attacker)->query_name()+" as the arrow smashes into "+(attacker)->query_name()+".\nBlood fills the wound.\n");
say(this_player()->query_name()+" draws back an arrow with great force.\nThe arrow leaps from its string ripping the air around it.\nPain fille "+(attacker)->query_name()+" as the arrow smashes into "+(attacker)->query_name()+".\nBlood fills the wound.\n");
(attacker)->heal_self(-1000);
(attacker)->hit_player(5);
this_player()->add_spell_point(-5);
return 1;
}
