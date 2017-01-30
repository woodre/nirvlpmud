int my_cost;
string my_tat;
id(str) { return str=="tatoo"; }
long() { write("A tatoo of "+my_tat+"\n"); return 1; }
extra_look() { long(); }
get() { return; }
drop() { return 1; }
set_my_cost(x) { my_cost=x; }
set_my_tat(str) { my_tat=str; }
query_my_cost() { return my_cost; }
query_my_tat() { return my_tat; }
query_auto_load() {
  return "/players/grimm/closed/mall/tatoo:"+my_tat+"#"+my_cost; }
init_arg(str) { sscanf(str,"%s#%d",my_tat,my_cost); }
