/*** Acid object that lands on living for extra damage ***/

int i;
id(str) { return str == "acid"; }
short() { return "several drops of acid"; }
long() {
   write("Drops of acid, likely burning whatever it touches.\n");
   return 1;
}

drop() { return 1;} /*not to drop*/

reset(arg) {
  if(arg) return;
   dest_me();
           }
int dest_me(string arg) {
   object target;
   target = find_living(arg);
   if(!target)
      destruct(this_object());
   if(i<3) {
      target->do_damage(random(5)+5, "other|poison");
      tell_object(target, "Acid eats into you, causing great pain.\n");
      tell_room(target, "Acid eats into "+target->query_name()+"\n");
      i++;
      if(i<4) call_out("dest_me", 15);
      return 1;
   }
   tell_room(environment(this_object()), "A blob of acid disapates.\n");
   destruct(this_object());
}
