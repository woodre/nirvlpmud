cmd_coshelp(str){
     string file;

     file = "/players/cosmo/guild/mob/docs/help/index";
     if(file_size(file)<1){
        write("no file\n");
        return 1;
     }
     cat(file);
     return 1;
}
