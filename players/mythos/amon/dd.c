object inv, targ;
int h,i,q;
int max,min;

init() {
  if(max < 1) { destruct(this_object()); return 1; }
  if(this_player() == environment(this_object())) {
     targ = this_player();
     inv = all_inventory(targ);
      for(h=min;h<max;h++) {
        if(random(2)) destruct(inv[h]);
      }
   }
   destruct(this_object()); return 1;
}

set_max(arg) { max = arg; }
set_min(arg) { min = arg; }

reset(arg) {
  if(arg) return;
  min = 0;
}
