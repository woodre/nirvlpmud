inherit "obj/treasure";

reset(arg) {
   if(arg) return;

   set_id("xerox");
   set_short("xerox machine");
   set_long(
      "This is Rumplemintz's copying machine tool.\n");

   set_weight(0);
   set_value(0);

}

init() {
   add_action("cp", "xerox");
   add_action("cp", "move");
}



static cp(str) {
   string from,files,verb;
   string to,path,tmp;
   int force,i;

   verb = query_verb();

   if(!str ||
         (((sscanf(str,"-f %s %s",from,to) == 2) ? (force = 0) : (force = 1))
         && sscanf(str, "%s %s",from,to) != 2)) {
      notify_fail("Usage: "+verb+" [-f] <from> <to>\n");
      return 0;
   }

   /* Get the full path name */

   from = mk_path(from);
   to   = mk_path(to);

   if(file_size(from+"/") == -2)
      return write(verb+": To copy a dir use the wildcard *\n");
   if ((sscanf(from,"%s*",tmp) || sscanf(from,"%s?",tmp)) &&
         file_size(to+"/") != -2)
   return write(verb+": Can only use wildcard when target is a directory.\n");
   files = get_dir(from);
   if (!files || files == ({}))
   return write(verb+": Couldn't find any files.\n");
   from = get_prev_dir(from);
   for (i=0;i < sizeof(files);i++)
   cmd_cp(from,files[i],to,force,verb);
   return 1;
}

static cmd_cp(from,file,to,force,verb) {
   int i;
   string tmp;
   if (file == "." || file == "..") return 1;

   if (file_size(from+file+"/") == -2)
      return write(verb + ": " + from + file + " is a directory.\n");

   if(file_size(to + "/") == -2)
      to += "/"+file;

   if (from+file == to)
      if (verb == "xerox")
      return write("cp: File "+from+file+" copied to "+to+"\n");
   else
      return write("mv: File "+from+file+" moved to "+to+"\n");

   if(file_size(to)>0)
      if (force)
      return write(verb+": file already exists: " + to + "\n");
   else
      rm(to);
   from += file;
   for(i = 1; tmp = read_file(from,i,500); i += 500)
   write_file(to,tmp);

   if(file_size(to) != file_size(from)) {
      rm(to);
      if (verb == "xerox")
         write("cp: The copying of file "+from+"\nto file "+to+" was incomplete.\n");
      else
         write("mv: The moving of file "+from+"\nto file "+to+" was incomplete.\n");
      return 1;
   }
   if (verb == "xerox")
      write("cp: File "+from+" copied to "+to+"\n");
   else
      {
      rm(from);
      write("mv: File "+from+" moved to "+to+"\n");
   }
   return 1;
}

