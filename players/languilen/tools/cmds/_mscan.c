cmd_mscan(str){
     int i;
     string s;
     object target, mobster;
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
     i=target->query_guild_rank();
     s=mobster->query_title();
     write("  Mob Level: "+i+"       Mob Title: "+s+"\n");
     i=mobster->query_graft();
     s=mobster->query_family();
     write("  Family: "+s+"          Graft: "+i+"\n");
     write("\n");
     return 1;
}

