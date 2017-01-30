/* 
 * Forbin
 * Created:   2003.09.03
 * Last edit: 2003.09.03 -forbin
 * Change log:
 */

id(str) { return (str == "waterfall_wet_object"); }

init() {
  if(this_player()) call_out("dripfreeze", 5+random(25));
  if(this_player()) call_out("dryoff", 1+random(400));
}

extra_look() {
  if(environment() == this_player()) write("You are soaking wet.\n");
  else tell_object(this_player(), environment()->query_name()+" is soaking wet.\n");
}

drop() { return 1; }

dripfreeze() {
  while(remove_call_out("dripfreeze")!= -1);
  switch(random(3)) {
    case 0: tell_object(environment(this_object()), "You shiver from the cold.\n");
    case 1: tell_object(environment(this_object()), "Water drips from your damp clothes.\n");
    case 2: tell_object(environment(this_object()), "The wind chills your wet body.\n");
  }
  call_out("dripfreeze",20+random(20));
}

dryoff() { 
  destruct(this_object());
}
