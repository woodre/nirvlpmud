#define FOG "/players/languilen/battle/objs/fog_ob.c"
#define WARFOG "/players/languilen/battle/mons/fogowar.c"
cmd_enfog(str){
     object target,thefog;
     if(!str){
        write("You must specify a target.\n");
        return 1;
     }
     if(!find_player(str)){
        write("bad target -no player found-\n");
        return 1;
     }
     target=find_player(str);
     move_object(clone_object(FOG),target);
     thefog=clone_object(WARFOG);
     move_object(thefog,environment(target));
     thefog->set_target(target);
     return 1;
}

