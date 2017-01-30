main(string str) {
   string start_dir, target_dir, *files;
   int x;
   
   if(!str)
      {
      write("Move directory to where?\n");
      return 1;
   }
   
   if(sscanf(str,"%s %s",start_dir,target_dir) != 2)
      {
      start_dir = this_player()->get_path();
      target_dir = str;
   }
   
   if(extract(start_dir,0,0) == "~") start_dir = "/players/"+extract(start_dir,1)+"/";
   if(extract(start_dir,0,0) != "/") start_dir = this_player()->get_path()+start_dir+"/";
   if(extract(target_dir,0,0) == "~") target_dir = "/players/"+extract(target_dir,1)+"/";
   if(extract(target_dir,0,0) != "/") target_dir = this_player()->get_path()+target_dir+"/";
   if(extract(start_dir,strlen(start_dir) - 1) != "/") start_dir += "/";
   if(extract(target_dir,strlen(target_dir) - 1) != "/") target_dir += "/";
   if(file_size(start_dir) != -2) { write("Invalid source directory.\n"); return 1; }
   if(file_size(target_dir) != -2) { write("Invalid target directory.\n"); return 1; }
   files = get_dir(start_dir);
   for(x = 0; x < sizeof(files); x++)
   {
      if(file_size(start_dir+files[x]) != -2)
         "/bin/wiz/_mv"->cmd_mv(start_dir + files[x] + " " + target_dir + files[x]);  
   }
   
   write("\nComplete.\n");
   return 1; }
