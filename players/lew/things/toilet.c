inherit "obj/treasure";

reset(arg){
     if(!arg){
     set_id("toilet");
     set_short("A large porcelin toilet");
     set_long("Use this toilet to flush people or things.\n");
     set_weight(500);
     set_value(0);
}}

init(){
     ::init();

     add_action("flush","flush");
}

flush(str){
     object target;
     target = find_player(str);
     if(!target){ write("Player not on."); return 1;}
     if(target->query_level() >19){ write("That would not be a good "+
       "idea\n"); return 1;}
     if(environment(this_player()) != environment(target)){
          write("Player not in this room.\n"); return 1;}
     command("look",target);
     write("SPLUSH!!\n");
     say(capitalize(this_player()->query_real_name())+" flushes "+
          capitalize(target->query_real_name())+" down the toilet.\n");
     return 1;
}
