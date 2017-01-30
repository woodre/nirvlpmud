
int do_infuse(string str) {
  object target;
  if(!str) {
    write("Usage: infuse <person>\n");
    return 1;
  }
  target=present(str,environment(TP));
  if(!target) {
    write("That person is not here.\n");
    return 1;
  }
  if(!living(target)) {
    write("You cannot infuse life into a non-living thing.\n");
    return 1;
  }
  if(TP->query_hp() < 40) {
    write("You cannot give away life that you do not have.\n");
    return 1;
  }
  TP->add_hit_point(-40);
  call_out("infuse",random(2),target);
  write("You infuse life and order into "+target->query_name()+".\n");
  say(TPN+" infuses life and order into "+target->query_name()+".\n");
  return 1;
}
void infuse(object target) {
  target->add_hit_point(40);
  tell_object(target,"You begin to feel better.\n");
}
