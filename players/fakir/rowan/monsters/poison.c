
/*
 * A POSION OBJECT (1/24/94)
 * Placed on player by monster/object.
 */

#define INTV 20  /* interval between damage */

int damage, tot_damage, max_damage;
string owner;

reset(arg) {
   if(arg)
     return;
   call_out("poison", 30);
}

id(str) { return str == "poison" || str == "sore" || str == "poison_sore"; }

short() { return "A sore caused by poisoning"; }

long() {
   write("A disgusting puss filled mass of flesh.\n");
   write("You feel sicker just looking at it.\n");
}

drop() {
   write("Better luck next time.\n");
   return 1;
}

set_damage(d) { damage = d; }

set_max_damage(md) { max_damage = md; }

set_owner(o) { owner = o; }

poison() {
   int dam;
   if(!owner || !find_player(owner) || 
             !present(this_object(), find_player(owner))) {
     destruct(this_object());
     return 1;
   }
   if(tot_damage >= max_damage) {
     tell_object(find_player(owner), "The swelling from the poison "+
         "disappears.\n");
     destruct(this_object());
     return 1;
   }
   tell_object(find_player(owner), "You feel sick from poisoning!\n");
   tell_room(environment(find_player(owner)), 
       capitalize(owner)+" doubles over and vomits.  YUCK!\n");
   dam = random(damage);
   find_player(owner)->add_hit_point(-dam);
   tot_damage += dam;
   call_out("poison", INTV);
   return 1;
}

