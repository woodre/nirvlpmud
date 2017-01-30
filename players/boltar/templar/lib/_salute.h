cmd_salute(string str){
  object who;
  if(TP->query_ghost()) return 0;
  if(!str){
   write("You cover your heart with your fist and nod in a formal salute.\n");
say(this_player()->query_name()+" covers "+this_player()->query_possessive()+" heart with"+
    " "+this_player()->query_possessive()+" fist and nods in a formal salute.\n");
    return 1;
  }
who = present(str, environment(TP));
if(who && living(who)) {
    if(who == this_player())
      return 0;
write("You cover your heart with your fist and nod to "+capitalize(str)+" in a formal salute.\n");
tell_room(environment(TP),
    this_player()->query_name()+" covers "+this_player()->query_possessive()+" heart with"+
    " "+this_player()->query_possessive()+" fist and nods to "+capitalize(str)+" in a formal salute.\n",
    ({ TP, who }));
tell_object(who, this_player()->query_name()+" covers "+this_player()->query_possessive()+" "+
           "heart with "+this_player()->query_possessive()+" fist and nods in a formal salute.\n");
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
write("You salute "+capitalize(str)+" from afar.\n");
tell_object(who, this_player()->query_name()+" salutes you from afar.\n");
    return 1;  
    }
return 1;
}
