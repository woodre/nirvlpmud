object listen_ob;
int case_is_unlocked, case_is_open;
object amulet;

reset(arg) {
    case_is_unlocked = 0;
    case_is_open = 0;
    if (!amulet || environment(amulet) != this_object()) {
        amulet=clone_object("/players/trix/castle/quest/monst/amulet"); 
        move_object(amulet, this_object());
    }
}

long(str) { 
    write("A heavy case made with wood, it is ");
    if(case_is_unlocked) {
    if(case_is_open) { write("open.\n"); }
    else { write("unlocked.\n"); } }
    else { write("locked.\n"); }
    return 1;
}

short() {
    if (case_is_open)
        return "A wooden case (open)";
    return "A wooden case";
}

init() {
   add_action("open", "open");
   add_action("unlock", "unlock");
}

unlock(str)
{ if (str!="case")
        return 0;
  if(case_is_unlocked) { write("The case is already ");
  if(case_is_open) { write("open.\n"); }
  else { write("unlocked.\n"); } 
  return 1;}
  if(!present("trixkey",this_player())) {write("You haven't got the key!\n"); return 1; }
  case_is_unlocked=1;
  write("Ok.\n");
  say(call_other(this_player(), "query_name") + " unlocks the case.\n");
  return 1;
} 


open(str) {
if (str!="case")
        return 0;
    if (!case_is_unlocked) {
        write("The case is locked.\n");
        return 1;
    }
    case_is_open = 1;
    write("Ok.\n");
    say(call_other(this_player(), "query_name") + " opens the case.\n");
    return 1;
}

id(str) {
 if(str=="case") return 1;
 return 0;
}


can_put_and_get() {
    return case_is_open;
}

add_weight() { return 1; }
