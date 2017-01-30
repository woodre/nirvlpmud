

 /****                            bin.h                          ****/
 /****                    A basic bin loading file               ****/
 
 /**                     format for a file: _<verb>.c              **/
 /**                  example: a 'missle' spell bin file           **/
 /**                       would be  _missle.c                     **/


load_bin(action, dir) {
   int n, size;                  /* should begin and end with "/"   */
   string files, file, path_ar, path_st;
   path_ar = explode(dir, "");
   if(path_ar[0] != "/") path_st = "/"+dir;
   if(path_ar[sizeof(path_ar) - 1] != "/") path_st = path_st +"/";
   files = get_dir(dir);
   size = sizeof(files);
   if(!size && this_player()) {
      write("Failed to load commands.\n");
       if(this_player()->query_level() > 19)
         write("Error: couldn't read path "+ dir +"\n");
      return 1;
   }
   n = 0;
   while(n < size) {
      file = strip_file(files[n]);    /* see if the file has the form */
      if(file != "0")                     /*         _<command>.c     */ 
         add_action(action, file);
      n+=1;
   }
}

strip_file(file) {
   string ret, tmp, tmp2;
   if(sscanf(file, "_%s.c", file) != 1) return "0";
write(file +"\n");
      return file;
}




   
