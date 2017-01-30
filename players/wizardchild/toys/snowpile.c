#define SNOW "/players/wizardchild/toys/snowball.c"
id(str) {
  return str == "snow" || str == "pile" || str == "pile of snow"; 
}
short() { return "A pile of snow"; }
get() { return 0; } drop() { return 0; }
long() { 
  write("A pile of snow. You could probably collect enough of it to make\n");
  write("a decent snowball.\n");
}
reset(arg) { if(!arg) call_out("self_dest",240); }
self_dest() { move_object(clone_object("/players/wizardchild/toys/puddle"), environment()); destruct(this_object()); }
init() {
  add_action("collect","collect");
}
collect(str) {
  object s;
  if(!id(str)) return 0;
  write("You compact the snow into a small sphere.\n");
  write("You can't help but grin at what comes next.\n");
  s = clone_object(SNOW);
  move_object(s, this_player());
  this_player()->remote_say(this_player()->query_name()+" makes a snowball.\n");
  this_player()->remote_say(this_player()->query_name()+" grins mischieviously.\n");
  destruct(this_object());
  return 1;
}
