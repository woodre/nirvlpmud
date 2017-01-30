#define TP this_player()
merge_dir(str) {
   string files, junk, out, dir;
   int n, size;
   if(!str) return;
   if(sscanf(str, "%s %s", dir, out) != 2)  
      write("'usage: merge <directory> <output filename>'n");
   dir = explode(dir, "");
   if(dir[0] != "/") {
      write("Pathnames must be absolute.n");
      return 1;
   }
   if(dir[sizeof(dir) - 1] != "/") {
      dir = implode(dir, "");
      dir = dir + "/";
       write("Using "+dir+"\n");
   } else {
      dir = implode(dir, "");
   }
   files = get_dir(dir);
   if(!files) {
       write("Couldn't read directory.\n");
      return 0;
   }
   size = sizeof(files);
   n = 0;
   write("Writing to "+ out + ".\n");
   while(n < size) {
   write("Trying to read "+files[n]+"\n");
      junk = read_file(dir + files[n]);
      if(junk) {
          write_file(out, "\n\n"+files[n] + "\n\n" + junk);
          write("Read "+files[n]+".\n");
      }
      n += 1;
   }
      write("Merge complete.\nRemove the file after downloading.\n");
   return 1;
}       
