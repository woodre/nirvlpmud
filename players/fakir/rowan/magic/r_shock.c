
/*
 * RING OF SHOCKING (3/19/94)
 * AC 0  CHARGES 5 + random(5)   
 * DAMAGE = [3 * (mag+wil)/5] - [targets lvl/2]
 */

int charges;

inherit "obj/armor";

reset(arg) {
   if(arg) {
     charges += 1 + random(2);
     return;
   }
   set_name("ring");
   set_short("A ring of shocking");
   set_long("Type 'target <monster>' to inflict damage.\n");
   set_value(700);
   set_ac(0);
   set_type("ring");
   charges = 5 + random(5);
}

init() {
   add_action("target","target");
   ::init();
}

target(str) {
   object target, dest;
   int mag, wil, dam, lvl;
   
   if(!worn) {
     write("You must wear the ring to use its powers.\n");
     return 1;
   }
   if(charges == 0) {
     write("The ring is currently out of charges!\n");
     return 1;
   }
   dest = environment(this_player());
   target = present(str, dest);
   if(!target || !living(target)) {
     write(capitalize(str)+" is not here.\n");
     return 1;
   }
   if(!target->query_npc()) {
     write("You cannot use the ring against players.\n");
     return 1;
   }
   mag = this_player()->query_attrib("mag");
   wil = this_player()->query_attrib("wil");
   lvl = target->query_level();
   dam = (3*((mag+wil)/5) - (lvl/2));
   target->attack_object(this_player());
   target->hit_player(dam);
   write("You summon the ring's power against "+capitalize(str)+".\n");
   tell_room(dest, "A stream of blue light issues forth from the ring "+
       "on "+capitalize(this_player()->query_name())+"'s finger.\n");
   charges -= 1;
   return 1;
}

