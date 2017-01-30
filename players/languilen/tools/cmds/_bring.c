cmd_bring(str){
     object target;
     target=find_player(str);
     if(!target){
        write("no player found.\n");
        return 1;
     }
     move_object(target, environment(this_player()) );
     write("done..\n");
     return 1;
}

