cmd_bow(string str){
  object who;
  if(TP->query_ghost()) return 0;
  if(!str){
   write("You cross your arm at your waist and bow low.\n");
say(this_player()->query_name()+" crosses "+this_player()->query_possessive()+" arm at"+
    " "+this_player()->query_possessive()+" waist and bows low.\n");
    return 1;
  }
who = present(str, environment(TP));
if(who && living(who)) {
    if(who == this_player())
      return 0;
write("You cross your arm at your waist and bow low to "+capitalize(str)+".\n");
tell_room(environment(TP), 
    this_player()->query_name()+" crosses "+this_player()->query_possessive()+" arm at"+
    " "+this_player()->query_possessive()+" waist and bows low to "+capitalize(str)+".\n",
    ({ TP, who }));
tell_object(who, 
    this_player()->query_name()+" crosses "+this_player()->query_possessive()+" arm at"+
    " "+this_player()->query_possessive()+" waist and bows low to you.\n");
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
write("You bow low to "+capitalize(str)+" from afar.\n");
tell_object(who, this_player()->query_name()+" bows low to you from afar.\n");
    return 1;  
    }
return 1;
}
