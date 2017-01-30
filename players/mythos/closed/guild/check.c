id(str) { return str == "messenger";}
drop() { return 0;}
get() { return 1;}

query_shatter_proof() { return 1;} 

reset(arg) {
  if(arg) return;
  call_out("ff",8);
}

ff() { destruct(this_object()); return 1;}
