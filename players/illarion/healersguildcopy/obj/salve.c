#define tp this_player()
#define tpn tp->query_name()

int rate;
int uses;

id(str) { return str == "salve" || str == "healing"; }

short() { return "Salve of Healing"; }

long() { write("A light green ointment sits in the small tin.\n"+
               "You may 'dab' it on someone, which may have some healing effects.\n"+
               "Uses left: "+uses+"\n"); }
 
set_heal(a) { rate = a; }
set_uses(a) { uses = a; }

query_weight() { return 2; }

reset(arg) { if(arg) return; rate = 1; uses = 1;}

drop() { return 0; }
get() { return 1; } 
 
init() {
  if(tp == environment(this_object())) 
  add_action("drink","dab");
}

drink(str) { 
object what;
  if(!str) { write("Dab ointment on who?\n"); return 1; }
  if(!(what=present(str,environment(tp)))) { write("Dab on who?\n"); return 1; } 
  if(!living(what)) { write("You may only dab the salve on living beings.\n"); return 1; }
     write("You dab the ointment on "+what->query_name()+"'s wounds.\n");
     uses = uses - 1;
     say(tpn+" dabs some light green ointment on "+what->query_name()+"'s wounds.\n");
    what->heal_self(rate/2+random(rate/3));
     
     if(uses < 1) { tp->add_weight(-2); 
                   write("The tin disappears.\n");
                   destruct(this_object()); }
return 1; }

