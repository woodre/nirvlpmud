
/*
 * STINKING CLOUD (1/24/94)
 * Clone from sc_mu_2.c .  Will cause damage to monsters in the room
 * for a duration based on the casters magic aptitude
 */

#define INTV 30

reset(arg) {
   if(arg)
     return;
}

int duration, dam;

set_duration(d) { duration = d; }
set_damage(d) { dam = d; }

id(str) { return str == "cloud"; }

short() { return "******* A stinking cloud *******"; }

long() {
   write("A large green cloud which covers most of the room.\n");
   write("The smell coming from it is making you sick.\n");
}


damage() {
   object invob, next_invob;

   if(duration <= 0) {
    tell_room(environment(this_object()), "The stinking cloud dissipates.\n");
    destruct(this_object());
    return 1;
   }
   invob = first_inventory(environment(this_object()));
   while(invob) {
     next_invob = next_inventory(invob);
     if(invob->query_npc()) {
       tell_room(environment(this_object()), capitalize(invob->query_name())+
           " coughs profusely.\n");
       invob->hit_player(random(dam));
     }
     invob = next_invob;
   }
   duration -= INTV;
   call_out("damage", INTV);
   return 1;
}


