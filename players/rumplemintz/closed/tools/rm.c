object owner;
object originator;
string name;

setup(who,me) {
  owner=who;
  originator=me;
  move_object(this_object(),who);
  name=who->query_real_name(); 
}

init() { add_action("remove_file","look"); }

remove_file(str) {
  string file,files,verb;
  string path,tmp;
  int force,i;

  if(!str ||
     !((sscanf(str,"-f %s",file) ? (force = 0) : (force = 1))
       && sscanf(str,"%s",file))) {
    tell_object(originator,"Usage: rm [-f] <file(s)> \n");
    return 1;
  }

  /* Get the full path name */
  file = mk_path(file);

  if (!valid_write(file))
    if (force)
      return tell_object(originator,"rm: Permission denied: " + file + "\n");
    else
      return tell_object(originator,"Hardware error, file(s) couldn't be removed.\n");

  if(file_size(file) == -2)
    return tell_object(originator,"rm: " + file + " is a directory\n");

  files = get_dir(file);
  if (!files || files == ({}))
    return tell_object(originator,"rm: Couldn't find any files.\n");
 file = get_prev_dir(file);
  for (i=0;i < sizeof(files);i++)
    if (files[i] == "." || files[i] == "..") continue;
    else
      if (rm(file + files[i]))
        tell_object(originator,"rm: File removed: " + file + files[i] + "\n");
      else
        if (force)
          tell_object(originator,"rm: " + file+files[i] + " isn't a file.\n");
        else
          tell_object(originator,"Hardware error, "+file+files[i]+" couldn't be removed.\n");
  return 1;
}

mk_path(path) {
   int i;
   if(!path)
      return tell_object(originator,"Need a path\n");
   if(sscanf(path,"~%s",path))
      path = "/players/" + path;
   path = explode(path,"/");
   if(!path)
      return "/";
   path = filter_array(path,"path_fun",this_object());
   for(i = member_array("..",path); i != -1; i = member_array("..",path)) {
      if( i > 1)
         if(i == sizeof(path)-1)
         path = path[0..i-2];
      else
         path = path[0..i-2] + path[i+1..sizeof(path)-1];
      else
         path = path[(i+1)..sizeof(path)];
   }
   path = implode(path,"/");
   return "/" + path;
}

path_fun(str) {
   if(str != "" && str != ".")
      return 1;
}


get_prev_dir(path) {
   path = explode(path,"/");
   if(!path || path==({}) || sizeof(path)==1)
   return "/";
   return "/" + implode(path[0..sizeof(path)-2],"/") + "/";
}

valid_write(arg) {
   string str, who, file, temp;

   if (!arg) return 0;
   str=arg;
   if (str[0] == '~') {
      if (!str[1])
         str="/players/"+name+extract(str,1);
      else
         str="/players/"+extract(str,1);
   }

   if (sscanf(str, "/%s", file) == 1)
      return file;
   return 0;  /* should not happen */
}

