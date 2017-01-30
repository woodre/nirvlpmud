/* Code to include in heal objects to allow consolidation.
   Must have NAME and MAX defined - NAME must be unique, MAX is max charges
   Snow */


do_consolidate(str) {
  object ob;
  ob = clone_object("/players/snow/heals/consolidator.c");
  move_object(ob, this_player());
  ob->consolidate(str);
  write("Consolidating process for "+str+" complete.\n");
  return 1; }

query_charge() { return shots; }
add_charge(int num) {
  if(this_player() && environment() != this_player()) return;
  if(!num) return;
  if(num < 0) { shots += num; if(shots <= 0) destruct_sequence(); return 1; }
  shots += num; if(shots > MAX) shots = MAX; return 1; }
set_charge(int num) {
  if(this_player() && environment() != this_player()) return;
  if(!num || num < 0) destruct_sequence();
  shots = num; return 1; }
query_need() { return MAX-shots; }
query_NAME() { return NAME; }

destruct_sequence() {
  if(!environment()) { destruct(this_object()); return 1; }
  tell_object(environment(),"You discard an empty "+NAME+".\n");
  transfer(this_object(), environment(environment())); destruct(this_object()); return 1; }
