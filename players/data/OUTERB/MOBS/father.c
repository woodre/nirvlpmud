inherit "/obj/monster.c";
#include <ansi.h>
reset(arg) {
if(arg) return ;  ::reset(arg);

set_name("father");
set_short(GRN+"a Shadow of your Father's Soul"+NORM);
set_alias("dad");
set_long("Somehow this shadow resembles your father, further more, it has his\n"+
         "voice. You can barely distinguish his features, but enough of him\n"+
         "remains intact enough to see that he is your father. He calls out to\n"+
         "you, beseaching your help. Yet something just doesn't seem quite right.\n");
set_level(17);
set_wc(24);
set_ac(14);
set_hp(350);
set_dead_ob(this_object());
   
   
   
}

monster_died() {
   object gold;
   gold = clone_object("obj/money");
   gold->set_money(1500+random(600));
   tell_room(environment(this_object()),
      "Your father screams loudly as his task of killing you has failed.\n"+
      "Your father's shape shimmers and the underworld creature's form fades.\n"+
      "You feel relieved that you didn't hurt your real father's soul.\n");
   move_object(gold,environment());
   return 0; }

init(){
   ::init();
   call_out("father_cry", 3, this_player());
}
father_cry(object who){
   if(!present(who, environment())){
      return 1;
   }
switch(random(3)){
case 0:
      tell_object(who, "Your father pleads: You will be safe here "+who->query_name()+", please believe me!\n");
break;
case 1:
   tell_object(who, "Your father cries: Please "+who->query_name()+", I need your help!\n");
break;
case 2:
   tell_object(who, "Your father gasps: "+who->query_name()+" I dont know how much longer I can hold on!\n");
break;
}
call_out("father_cry", 12, who);

}

