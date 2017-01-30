inherit "obj/armor";
#include "/open/ansi.h"
#define UWEB BOLD+WHT+"Ung"+BLK+"wel"+WHT+"ian"+BLK+"te's "+WHT+"web"+NORM


reset(arg){
   ::reset(arg);
   set_short(UWEB);
   set_long(BOLD+WHT+"\n                      UNGWELIANTE'S WEB!\n"+
            WHT+"                              |\n"+
            BLK+"                            _ "+WHT+"|"+BLK+"_\n"+
            BLK+"                           /  "+WHT+"|"+BLK+" \\\n"+
            BLK+"                       /  /  **  \\  \\ \n"+
            BLK+"                       \\  \\ @@@@ /  /\n"+
            BLK+"                        \\__******__/\n"+   
            BLK+"                           @@@@@@\n"+
            BLK+"                        \\ / **** \\ /\n"+  
            BLK+"                         v /("+YEL+"@@"+BLK+")\\ v\n"+ 
            BLK+"                           \\ `' /\n"+
            WHT+"This is the web spun by Ungweliante, the "+BLK+"Darkness Weaver"+WHT+".  It\n"+
            WHT+"is very light and extremely sticky.  It looks like one could\n"+
            WHT+"'wear' it as an armor of sorts.\n"+NORM);
   /* -Forbin 2005.04.29 
   //  changed ac to 4, and added a do_special()
   //  the mob is hard enough to justify the tweak  
   */
   set_ac(4);
/*
   set_weight(0);
     I DONT THINK SO - mythos <9-9-96> */
   set_weight(1); /* -Snow  (check out ungwe.c now) */
/* fine.... keep the weight 1 but the ac is now 3 not 4
   the changes to the monster does not justify a weight 1 ac 4
   savable armor - mythos <7-20-1998> */
   set_value(2000);
   set_alias("spider web");
   set_name("web");
   set_type("armor");
}

do_special(object owner) {
	object att;
	int aluc;
	if(!owner || !owner->query_attack()) return 0;
  if(!owner->is_player()) return 0;
  att = owner->query_attack();
  if(att->query_npc())
    aluc = 25;
  else 
    aluc = (int)att->query_attrib("luc");
  if(random(owner->query_attrib("luc")) > random(aluc)) {  
    if(!random(8)) {
      tell_object(owner,
        (string)att->query_name()+"'s attack glances off of your "+BOLD+WHT+"web"+NORM+" armor.\n");
      tell_object(att,
        "Your attack glances off of "+(string)owner->query_name()+"'s "+BOLD+WHT+"web"+NORM+" armor.\n");
	    tell_room(environment(owner),
  	    (string)att->query_name()+"'s attack glances off of "+
  	    (string)owner->query_name()+"'s "+BOLD+WHT+"web"+NORM+" armor.\n", ({ owner, att }));
	    return 1;
	  }
    if(!random(16)) {
      tell_object(att,
        "As you attack, you become tangled in "+UWEB+".\n");
      tell_room(environment(owner),
        "As "+(string)att->query_pronoun()+
        " attacks, "+(string)att->query_name()+" becomes tangled in "+UWEB+".\n", ({ att }));
	    return 2;
	  }	  
	}
}