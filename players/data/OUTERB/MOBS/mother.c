inherit "/obj/monster.c";
#include <ansi.h>
reset(arg) {
if(arg) return ;  ::reset(arg);
set_name("mother");
set_short(GRN+"a Shadow of your Mother's Soul"+NORM);
set_alias("mother");
set_long("This is your mother, you feel compeled to go to her as she screams\n"+
         "your name, she looks just like you remember her. Although her features\n"+
         "aren't as strongly defined when she was alive you still feel you owe\n"+
         "her some sort of explanation, yet something in the back of your mind\n"+
         "warns you about some sort of danger.\n");
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
      "Your mother screams loudly as her task of killing you has failed.\n"+
      "Your mother's shape shimmers and the underworld creature's form fades.\n"+
      "You feel relieved that you didn't hurt your real mother's soul.\n");
   move_object(gold,environment());
   return 0; }

init(){
   ::init();
   call_out("mother_cry", 3, this_player());
}
mother_cry(object who){
   if(!present(who, environment())){
      return 1;
   }
switch(random(3)){
case 0:
      tell_object(who, "Your mother asks: Why wont you stay with me "+who->query_name()+"?\n");
break;
case 1:
   tell_object(who, "Your mother sighs: "+who->query_name()+", I can't stand you not being here.\n");
break;
case 2:
   tell_object(who, "Your mother cries: "+who->query_name()+", I gave birth to you in the living world and this is how I am repaid?!?\n");
break;
}
call_out("mother_cry", 12, who);

}


