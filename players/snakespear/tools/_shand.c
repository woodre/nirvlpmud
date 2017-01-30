cmd_shand(str){
     object target,pkg;
     string who,what;

     if(sscanf(str,"%s %s", who, what)!=2){
        write("Usage: shand <who> <path>\n");
        return 1;
     }
     target=find_player(who);
     if(!target){
        write("no player found.\n");
        return 1;
     }
     pkg=clone_object(what);
     if(!pkg){
        write("Failure to clone file...\n");
        return 1;
     }
     move_object(pkg, target );
     write("Item sent...\n");
     return 1;
}

