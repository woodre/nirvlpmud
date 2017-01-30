/* ltstand.c: darkwood torch stand */
int num_torches;
short() { return "The darkwood torch stand"; }
long()  {
  write("A small wooden stand with a coin slot and a little tray - it looks something\n");
  write("like a shortened Pepsi machine. You could probably buy a torch, unless it is\n");
  write("out of torches already.\n");
  write("Darkwood torches cost 100 coins, and are only good in darkwood.\n");
  return 1;
}
id(str) { return str == "torch stand" || str == "stand" || str == "darkwood torch stand"; }
reset(arg) {
  if(arg)
    return ;
  num_torches = 10;
}
init() {
  add_action("buy_torch", "buy");
}
buy_torch(str) {
  object me, torch;
  if(str != "torch")
    return 0;
  me = this_player();
  if(!num_torches) {
    write("The machine is evidentally out of torches.\n");
    return 1;
  }
  if(me->query_money() < 100) {
    write("You do not have 100 coins.\n");
    return 1;
  }
  torch = clone_object("/players/wizardchild/darkwood/obj/torch");
  if(!me->add_weight(torch->query_weight())) {
    write("You cannot carry any more.\n");
    return 1;
  }
  me->add_money(-100);
  move_object(torch, me);
  write("You buy a darkwood torch.\n");
  say(me->query_name()+" buys a darkwood torch.\n");
  num_torches--;
  if(num_torches == 0)
    call_out("refill_stand", 600);
  return 1;
}
refill_stand() {
  tell_room(environment(this_object()), "A wily looking old man puts a few more torches into the stand.\n");
  num_torches = 10;
}
