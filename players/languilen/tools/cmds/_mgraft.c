cmd_mgraft(str){
     int amt;
     object target, mobster;
     if(sscanf(str, "%s %d", str, amt)!=2){
        write("Usage: mgraft <player> <amt>\n");
        return 1;
     }
     target=find_player(str);
     if(!target){
        write("no player found.\n");
        return 1;
     }
     mobster=present("mob_ob", target);
     if(!mobster){
        write(target->query_name()+" is not a mobster!\n");
        return 1;
     }
     mobster->add_graft(amt);
     write("Done..\n");
     return 1;
}

