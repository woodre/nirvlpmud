int ag;
id(str) {return str == "numbered";}

get() { return 0;}
drop() { return 1;}

set_ag(n) { ag = n;}
query_ag() { return ag;}

query_save_flag() { return 1;}

reset(arg) {
  if(arg) return;
  call_out("check",20);
  }

check() {
  destruct(this_object());
return 1;}
