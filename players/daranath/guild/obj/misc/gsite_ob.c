string name;
int burial_check;

id(str) {
return str == "gsite_ob" || str == "gravesite" || str == "marker";
}

short() {return "A Gravesite Marker"; }
long() {
write("A dark grey pillar of stone that is cool to the touch, the marker\n"+
      "stands here to let Nirvana know that you stand upon a\n"+
      "consecrated graveyard.\n");
}

reset(arg) { 
  burial_check = 1;
  if(arg) return;
}
get() { return 1; }
query_weight() {return 400; }
query_burial_check() { return burial_check; }

set_burial_check(arg) {
  burial_check = arg;
  return 1;
}

