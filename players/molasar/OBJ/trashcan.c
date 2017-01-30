
id(str) { return str == "can" || str == "trashcan"; }

get() { 
     if(this_player()->query_level() < 21)
       return 0;
     return 1;
}

short() { return "A trashcan"; }

long() {
     write("A large metal trashcan for disposing of any trash.\n");
     write("To use:  trash <item>\n");
}

init() {
     add_action("trash", "trash");
}

trash(str) {
     string item, me;
     object itemob;
     me = this_player()->query_name();

     if(this_player()->query_level() >= 20) {
       write("The trash can is for players only.\n");
       return 1;
     }
     if(str == "soul" || str == "seal" || call_other(itemob,"query_short") == 0) {
        write("You can't throw that away.\n");
        return 1;
     }
     if(!str || sscanf(str, "%s", item) != 1) {
       write("Trash what?\n");
       return 1;
     }
     itemob = present(item, this_player());
     if(!itemob) {
       write("You do not have the "+item+".\n");
       return 1;
     }
     write("You throw away "+call_other(itemob,"short")+".\n");
     say(capitalize(me)+" throws away "+call_other(itemob,"short")+".\n");
     destruct(itemob);
     return 1;
}

