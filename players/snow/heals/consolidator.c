/* Code to consolidate heals. Note that this does not allow heals in any
   way different than regulations. It simply takes charges from like-type
   heals and 'fills' heal charges with slightly used heals. Thus a goop
   with 3 of 5 charges could combine with a goop with 1 of 5 charges to
   create a single goop with 4 of 5 charges. Might or might not be
   approved but it is an interesting exercise. -Snow */

consolidate ( type ) {
  object ob, ob2, ob3;
  int n, s;
  if(!type) { notify_fail("Consolidate what type of heal?\n"); return 0; }
  if(!environment()) return;
  if(!this_player()) return;
  if(environment() != this_player()) return;
  ob = present(type, this_player());
  if(ob->query_NAME() != type) {
    tell_object(this_player(), "Specify type more exactly, please.\n"); return 1; }
  s = ob->query_charge();
  if(!s) return;
  ob2 = first_inventory(environment());
  while(ob2 && s) {
   if(ob2->query_need() && ob2->query_NAME() == type) {
      n = ob2->query_need();
      if(s > n) { s -= n; n = 0; }
      if(n > s) { n -= s; s = 0; }
      if(s == n) { n = 0; s = 0; }
      if(!s) ob->destruct_sequence();
      if(!n) ob2->add_charge(ob2->query_need());
    }
    if(ob2) ob2 = next_inventory(ob2);
  }
  if(ob) ob->set_charge(s);
  destruct(this_object()); }
