
displace(str){
     object target;
     target=find_living(str);
    if(!target){ write("You can't displace what isn't alive.\n"); return 1;}
    tell_object(target,"You have been moved.\n");
    move_object(target,"room/church");
    command("look",target);
    write("Displaced\n");
return 1;
}
