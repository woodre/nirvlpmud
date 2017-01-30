#include "/players/tallos/ansi.h"
#define USER environment(this_object())
#define ATT USER->query_attack()
#define LIVING USER->is_living()
#define tp this_player()->query_name()
#define tpt ATT->query_name()
#define TP this_player()
#define sx this_player()query_gender()
inherit "obj/armor";


reset(arg) {
 if(arg) return;
 ::reset(arg);
  set_name("corset");
  set_alias("outfit");
  set_short(BOLD+""+NORM+"A "+WHT+"Black "+MAG+"Dominatrix "+WHT+"Corset"+NORM);
  set_long(
    "     This is the corset of the dominatrix Melinda. It leaves\n"+
    "little to the imagination. To those with wondrous beauty, it\n"+
    "aids without question.  Just putting it on, you think, would\n"+
    "make you feel more feminine.\n");
  set_ac(4);
  set_type("armor");
  set_weight(2);
  set_value(10000);  
}


do_special(owner){
  if(random(100) < USER->query_attrib("cha") && ATT)
  {
    if(ATT->is_npc())
      ATT->heal_self(-(USER->query_attrib("cha") / 3));
    else ATT->add_hit_point(-(USER->query_attrib("cha") / 4));
      tell_object(USER,
        "Your corset has paid off. Your foe is distracted by your sexy dominatrix attire.\n"+
        "You are able to sneak in under their guard. \n"+
        " \n"+
        "You hit "+tpt+" Hard!\n");
    if(ATT->is_player()){
       tell_object(ATT,
        ""+tp+" distracts you with a sexy showing of their corset. You lose your concentration\n"+ 
        "and...\n"+
        ""+tp+" Hits you Hard!\n");
    }
    else {
       write(""+tp+" distracts their opponent with a sexy show of their corset and slips\n"+
             "under "+tpt+"'s guard.\n"+
             " \n"+
             ""+tp+" hits "+tpt+" Hard!\n");
         } 
    return 0;
  }
  return 0;
}	
	
