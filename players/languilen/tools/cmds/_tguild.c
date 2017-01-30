cmd_tguild(str){
     object target;
     target=find_player(str);
     if(!target){
        write("no player found.\n");
        return 1;
     }
     move_object(clone_object("/players/languilen/guild/trav/gob.c"), target );
     write("done..\n");
     return 1;
}

