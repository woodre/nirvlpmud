cmd_udir(){
     string *files;
     int i;

     files=get_dir(this_player()->get_path());
     if(!files){
        write("No files here!\n");
        return 1;
     }
     i=0;
     while(i++<sizeof(files)){
           if( files[i-1][strlen(files[i-1])-2..strlen(files[i-1])-1] == ".c" ){
              write("Updating "+files[i-1]+": ");
              command("update "+files[i-1], this_player());
           }
     }
     write("done..\n");
     return 1;
}

