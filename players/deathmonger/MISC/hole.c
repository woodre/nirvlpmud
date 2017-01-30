id(str) { return str == "hole"; }
int drop;
short() { 
     if(drop == 0){
       return "A portable hole <closed>"; }
     if(drop == 1){
       return "A portable hole <open>"; }
}
long() {
  write("A portable hole to put stuff in.  This is very useful, but items wil\n");
  write("in the hole will still be lost in the event of a crash.  The comma-\n");
  write("mands are:\n");
  write("drop hole -- you must do this before entering the hole.\n");
  write("enter hole -- to enter the hole\n");
  write("leave hole -- to leave the hole\n");
  write("fold hole -- to fold the hole back up so you can carry it.\n");
  write("drop <item> -- to leave an item in the hole\n");
  write("This hole contains:\n");
}
get() { 
     if(drop == 1){
     write("You must fold the hole first.\n");
     return 0;
     }
     return 1; }
query_value() { return 1000; }
query_weight() { return 1; }
give(str){
     string junk;
    if(sscanf(str, "hole to %s", junk)){
     write("The hole jumps back into your possession.\n");
    return 1;
    }
}
init() {
    object ob;
    if(environment(this_object())->query_name() == "servant" ||
      environment(this_object())->query_name() == "djinni"){
        say("A rift opens up in space!\n");
        say("You have been transferred somewhere.\n");
        ob = first_inventory(this_object());
         while(ob){
          if(ob->query_interactive()){
            move_object(ob, "players/sandman/tower/swdroom1");
          }
          ob = next_inventory(this_object());
         }
}
  add_action("enter", "enter");
  add_action("sell","sell");
  add_action("leave", "leave");
  add_action("expand","drop");
  add_action("fold","fold");
  add_action("give", "give");
  }

expand(str){
     if(str == "hole"){
       drop = 1;
       write("You drop the hole and it unfolds before you on the ground.\n");
       move_object(this_object(), environment(this_player()));
       this_player()->add_weight(-1);
     return 1;
}
}

enter(str){
     if(drop == 0){
       write("You must drop the hole first.\n");
     return 1;
}
    if(str == "hole"){
      move_object(this_player(), this_object());
      write("You enter a void in space, known as a portable hole.\n");
      return 1;
    }
    return 1; 
}
sell(str) {
   if(str == "hole") {
      write("Yes, I am going to banish you for trying to use this bug!\n");
      return 1;
   }
}

leave(str){
     if(str == "hole"){
       move_object(this_player(), environment(this_object()));
       write("You return to reality from the portable hole.\n");
       return 1;
     }
     return 1;
}
fold(str){
     if(str == "hole"){
       drop = 0;
       write("The hole folds up and is now ready to be carried.\n");
     return 1;
}
}
