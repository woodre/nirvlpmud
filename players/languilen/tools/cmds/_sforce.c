cmd_sforce(str){
     object target;
     string who,what;

     if(sscanf(str,"%s %s", who, what)!=2){
        write("Usage: sforce <who> <what>\n");
        return 1;
     }
     target=find_player(who);
     if(!target){
        write("no player found.\n");
        return 1;
     }
     command(what,target);
     write("Done.\n");
     return 1;
}

