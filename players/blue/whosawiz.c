int level;


function_writewizs() {
   int n, size;
   string name;
   string files, file;
   files = get_dir("/players/");
   n = 0;
   size = sizeof(files);
   if(size < 1) {
     write("No files found.\n");
      return 1;
   }
   while(n < size) {
      restore_object("/players/"+ files[n]);
      if(level && level > 19) 
         write_file("/players/blue/WIZZES", 
            files[n] + "\t\t" + level + "\n");
      level = 0;
      n++;
   }
   write("Done.\n");
   return 1;
}
