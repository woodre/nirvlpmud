GIVE(str) {
            string who,what;
            object who1,what1;
            
            if (!str) return;
            if(sscanf(str,"%s to %s",what,who) != 2) return write("Usage: GIVE <what> to <whom>.\n");
            who1 = find_player(who);
            what1 = present(what);
            if (!who1) {
             write(capitalize(who)+" is not logged on.\n");
             return; }
            if (!what) {
             write("You don't have a "+what+"!\n");
             return ; }
write(
"You GIVE to "+who1->query_name()+": "+what1->short()+"\n"
);
            move_object(what1,who1);
            return 1;
          }
