tell(str) {
  object who;
  string foo, foo2;
  if(!str || sscanf(str, "%s %s", foo, foo2) != 2) return 0;
  if(!(who = find_player(foo))) {
    write("Player not found.\n");
    return 1;
  }
  if(who->query_invis() > 99) { write("Player not found.\n"); return 1; }
  if(in_editor(who)) write(capitalize(foo)+" is editing.\n");
  if(!who->query_interactive()) write(capitalize(foo)+" is disconnected.\n");
  else if(query_idle(who) > 120) write(capitalize(foo)+" is idle.\n");
  if(who->query_level() < 20 && this_player()->query_invis()) 
{
who->add_tellhistory("Someone tells you: "+foo2);
tell_object(who,format("Someone tells you: "+foo2,70));
} else {
who->add_tellhistory("Wizardchild tells you: "+foo2);
tell_object(who,format("Wizardchild tells you: "+foo2,70));
write(format("You tell "+capitalize(foo)+": "+foo2,70));
}
  return 1;
}
