cmd_warn(string str){
  object who;
  if(TP->query_ghost()) return 0;
  if(!str){
    write("Warn who?\n");
    return 1;
    }
who = present(str, environment(TP));
if(who && living(who)) {
    if(who == this_player())
      return 0;
write("You warn "+capitalize(str)+" about the dangers of being evil.\n");
tell_room(environment(TP),
    this_player()->query_name()+" warns "+capitalize(str)+" about the dangers of being evil.\n",
    ({ TP, who }));
tell_object(who, this_player()->query_name()+" warns you about the dangers of being evil.\n");
    return 1;  
    } 
else {
    who = find_player(str);
    if(!who || who == this_player() || in_editor(who) || who->query_invis() >= this_player()->query_level())
      return 0;
    if(who->query_tellblock()) {
      write(capitalize(str)+" is blocking emotes.\n");
      return 1;
     }
write("You warn "+capitalize(str)+" about their evil deeds from afar.\n");
tell_object(who, this_player()->query_name()+" warns you about your evil deeds from afar.\n");
    return 1;  
    }
return 1;
}
