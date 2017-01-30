/* torch.c: simple darkwood torch */
status cloned;
short() { return "A darkwood torch (always lit)"; }
long()  {
  write("A simplistic looking torch. For some strange reason, however, it works much better\n");
  write("here than any other torch. Unfortunately, it will only provide light for you.\n");
  write("It is always lit.\n");
  return 1;
}
query_weight() { return 1;  }
query_value()  { return 20; }
id(str) { return str == "torch" || str == "darkwood torch" || str == "darkwood_torch"; }
get()  { return 1; }
drop() {
  write("The torch disintegrates as it hits the ground.\n");
  destruct(this_object());
}
init() {
  if(cloned)
    destruct(this_object());
  cloned = 1;
  write("As you grab the torch, it lights itself.\n");
  say("The torch lights itself.\n");
  call_out("burnout", 1800); /* 30 minutes */
}
burnout() {
  tell_object(environment(this_object()), "The flame on your darkwood torch dwindles into nothing, and the torch\n"
                                         +"disintegrates.\n");
  destruct(this_object());
}
