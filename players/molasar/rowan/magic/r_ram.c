
/*
 * RING OF THE RAM (3/19/94)
 * Let's you punch your opponent DAM = random(strength/2);
 * AC 0     TYPE ring
 */

#define TELL(x) tell_room(environment(this_player()), x)
#define DAM random(this_player()->query_attrib("str")/2)

inherit "obj/armor";

reset(arg) {
   if(arg)
     return;
   set_name("ring");
   set_value(550);
   set_ac(0);
   set_type("ring");
  set_short("Ring of the Ram");
  set_long("An incription reads:\n"+
           "  Punch thy foe into submission.\n");
}

init() {
   add_action("punch","punch");
   ::init();
}

punch() {
   object target;

   if(!worn) {
     write("You must wear the ring first.\n");
     return 1;
   }
   target = this_player()->query_attack();
   if(!target) {
     write("You must be fighting someone before you can punch.\n");
     return 1;
   }
   if(!target->query_npc()) {
     write("You may not punch players!\n");
     return 1;
   }
   TELL(this_player()->query_name()+" punches "+target->short()+".\n"); 
   target->hit_player(DAM);
   return 1;
}


