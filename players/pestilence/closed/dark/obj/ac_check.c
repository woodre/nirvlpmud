int ac_times;

id(str) { return str == "ac_check"; }

drop() { return 1; }
get() { return 0; }

reset(arg) {
  if(arg) return;
  ac_times = 0;
}

add_ac_times(arg) { ac_times = ac_times + arg; }
query_ac_times() { return ac_times; }

no_exp_effect() { return 1; }
