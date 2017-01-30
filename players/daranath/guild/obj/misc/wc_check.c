int wc_times;

id(str) { return str == "wc_check"; }

drop() { return 1; }
get() { return 0; }

reset(arg) {
  if(arg) return;
  wc_times = 0;
}

add_wc_times(arg) { wc_times = wc_times + arg; }
query_wc_times() { return wc_times; }

