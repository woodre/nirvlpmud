#define TPGO present("TRAV_OB",this_player())
#define MOD TPGO->query_mod()
cmd_rem_door(str){
     if(!str){
        write("You must specify a name of an exit.\n");
        return 1;
     }
     if( member_array(str, MOD->query_dest_dir()) < 0 ){
        write("You must specify a name of an exit.\n");
        return 1;
     }
     MOD->remove_mod_exit(str);
     TPGO->remove_extra_exit(str);
     write("Exit removed...\n");
     return 1;
}

