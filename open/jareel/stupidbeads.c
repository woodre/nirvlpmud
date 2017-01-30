  string last;
     string msg;

     short() { 
       return "A lump of coal for -Max-";
     }

     id(str) { 
       return str == "beads" || str == "plastic" || str == "plastic beads";
     }

     get() { return 1; }
       long() {
         write("A string of beads to toss to people who flash you.\n");
         write(" Type \"beads <player>\" to toss them to someone.\n");
       if(msg) 
         write(msg+"\n");    
         write("Type \"message <str>\" to set a new message line.\n");
         return 1;
       }

     init() {
       if(environment(this_object()) == this_player()) {
         add_action("toss_beads", "beads");
         add_action("new_msg", "message");
           }else destruct(this_object());
       }

     toss_beads(str) {
       object who;
         if(!str) {
           write("Missing something?\n");
             return 1;
       }
  
       who = find_player(str);
         if(!who || who->query_invis() > this_player()->query_level()) {
           write("That player is not logged in.\n");
             return 1;
       }
  
       if(str != "sparkle") /* added by me */
         if(who->query_level() > 20 && this_player()->query_level() < 21) {
           write("Your respect for Wizards prevents you from throwing this at one.\n");
             return 1;
       }

       write("You wrap the beads in a ball and toss them..\n");
       write("The beads fly off towards "+who->query_name()+".\n");
       say(this_player()->query_name()+" throws cheesy plastic beads off to "+who->query_name()+".\n");
       last = this_player()->query_name();
       move_object(this_object(), who);
       tell_object(who, "Beads comes flying in out of nowhere and lands gently in your hands.\n");
       tell_room(environment(who), who->query_name()+" catches a string of beads.\n");
       return 1;
       }

       new_msg(str) {
         if(!str) {
           write("Missing something?\n");
             return 1;
       }

       msg = str;
         write("Beads message: "+msg+"\n");
           return 1;
       }
