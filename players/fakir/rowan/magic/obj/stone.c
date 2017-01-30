
/*
 * (1/24/94)
 * stone object for use with the sleep spell in sc_mu_3.c
 */

string short_desc;
object target;

reset(arg) {
   if(arg)
     return;
}

set_short(s) { short_desc = s; }

short() { return short_desc+" (turned to stone)"; }

long() {
   write(short_desc+"\n");
}

get() { return 0; }

set_target(t) { target = t; }

id(str) { return str == target->query_name() || str == "stoned_object"; }

set_duration(d) { 
   call_out("awaken", d);
}

awaken() {
   tell_room(environment(this_object()), capitalize(target->query_name())+
       " returns to flesh form.\n");
   if(target)
     move_object(target, environment(this_object()));
   destruct(this_object());
   return 1;
}

