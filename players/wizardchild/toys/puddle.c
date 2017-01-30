reset(arg) { if(!arg) call_out("self_dest",240); }
id(str) { 
  return str == "puddle" || str == "water" || str == "puddle of water"; 
}
short() { return "A puddle of water"; }
long() {
  write("Looks like a puddle of defrosted snow.\n");
}
self_dest() { destruct(this_object()); }
