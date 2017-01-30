do_cmd(str) {
  object ob;
  ob=first_inventory(environment(this_player()));
  while(ob) {
    if(ob->is_npc())
      ob->set_chat_chance(0);
    ob=next_inventory(ob);
  }
  write("You gesture for silence.\n");
  say(this_player()->query_name()+" gestures for silence.\n");
  return 1;
}
