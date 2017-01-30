int num;

id(str) {return str == "duplicator";}

get() { return 0;}
drop() { return 1;}

query_save_flag() { return 1;}

reset(arg) {
  if(arg) return;
  num = 0;
}

set_num(n) { num = n; }
query_num() { return num; }