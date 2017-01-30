
id(str) { return str == "walkie talkie" || str == "walkie" || str == "talkie";}

get() { return 1; }

query_value() { return 100; }

short() { return "A walkie talkie"; }

long() {
   write("A device for talking to people far away.  They must have a walkie\n"+
         "talkie to hear you.  Just 'wt <player> <msg>' to talk.\n");
}

init() { 
   add_action("wt","wt");
}

wt(str) {
   string who, mess;

   if(!str || sscanf(str, "%s %s", who, mess) != 2) {
     write("Useage: wt <player> <msg>\n");
     return 1;
   }
   if(!find_player(who)) {
     write(capitalize(who)+" is not on.\n");
     return 1;
   }
   if(!present(id(str), find_player(who))) {
     write(capitalize(who)+" does not have a walkie talkie.\n");
     return 1;
   }
   tell_object(find_player(who), mess+"\n");
   write("You walkie talkie to "+capitalize(who)+": "+mess+"\n");
   return 1;
}

