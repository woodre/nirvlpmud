cmd_carry(str){
     object target;
     target=find_player(str);
     if(!target){
        write("no player found.\n");
        return 1;
     }
     target->recalc_carry();
     write("done..\n");
     return 1;
}

