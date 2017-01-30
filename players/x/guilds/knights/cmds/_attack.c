int main(string str){
  string mode;
  if(str) return 0;
  mode = query_verb();
  if((string)previous_object()->query_combat_mode() == mode){
    write("You're already assuming a "+capitalize(mode)
      +"ing stance.\n");
    return 1;
  }
  else if(previous_object()->query_done()){
    write("You cannot change your combat stance this round.\n");
    return 1;
  }
  else {
    write("You quietly pop your knuckles.\n");
    say((string)this_player()->query_name()+" quietly "+
    "pops "+possessive(this_player())+" knuckles.\n");
    write("You assume "+a_or_an(mode)+" "+capitalize(mode)
         +"ing stance.\n");
    say((string)this_player()->query_name()+
    " assumes "+a_or_an(mode)+" "+capitalize(mode)+"ing"+
   " stance.\n");
   previous_object()->set_combat_mode(mode);
   return 1;
 }
}
