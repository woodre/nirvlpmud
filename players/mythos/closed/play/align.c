id(str) { return str == "al"; }

init() { 
  add_action("al","al");
}

al(str) {
int h;
  sscanf(str,"%d",h);
   this_player()->add_alignment(h);
return 1; }
