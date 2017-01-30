status main(string arg) {
  object ob, there, here;

  if (!arg) {
    notify_fail("Trans who?\n");
    return 0;
  }

  if (!(ob = find_living(arg)) )
    return 0;

  here = environment(this_player());
  there = environment(ob);

  if (here == there) {
    write("Already here, dumbass.\n");
    return 1;
  }

  move_object(ob, environment(this_player()));
  tell_room(there, "Earwax yanks "+(string)ob->query_name()+" out of the room by the short and curlies!\n");
  write("You transed "+capitalize((string)ob->query_real_name())+" to you.\n");
  tell_object(ob, "Earwax reaches out, grabs you by the short and curlies, and yanks HARD!\nWhen you blink the tears from your eyes you find yourself standing before him.\n");
  tell_room(here, "Earwax reaches his arm waaaayyyyyyy out...\nand yanks "+(string)ob->query_name()+" into the room by "+((string)ob->query_gender() == "male" ? "his" : "her")+" short and curlies!\n", ({ this_player(), ob }) );
  return 1;
}
