sgoto(str){
     object target;
     target=find_player(str);
     if(!target){
        write("no player found.\n");
        return 1;
     }
     move_object(this_player(), environment(target) );
     command("look", this_player());
     return 1;
}

