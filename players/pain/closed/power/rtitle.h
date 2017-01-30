rtitle(str){
  if (this_player()->query_level()<wizard_level) return;
  if (!str || sscanf(str, "%s %s",who,msg) != 2){
    write("Use: ptitle <player> <title>\n");
    return 1;
  }
  it = lower_case(who);
  obj = find_living(it);
  if (!obj) {
    write("No player with that name.\n");
    return 1;
  }
  call_other(obj,"set_title",msg);
  write("Ok.\n");
  return 1;
}
