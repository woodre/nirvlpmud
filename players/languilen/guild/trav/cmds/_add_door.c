#define TPGO present("TRAV_OB",this_player())
#define MOD TPGO->query_mod()
cmd_add_door(str){
     string here;
     if(!str){
        write("You must specify a name for the exit.\n");
        return 1;
     }
     if( sizeof(TPGO->query_extra_exits()) >= this_player()->query_guild_rank()+1 ){
        write("You have no spare doors to place!\n");
        return 1;
     }
     here = object_name(environment(this_player()));
     if( sizeof(explode(here,"#")) != 1){
        write("You can not place a doorway here.\n");
        return 1;
     }
     if(environment(this_player())->query_realm() == "NT"){
        write("You can not place a doorway here.\n");
        return 1;
     }
     here+=".c";
     MOD->add_mod_exit( here, str );       
     TPGO->add_extra_exit( here, str );
     return 1;
}

