du(dir) {
   string files;
   int size, n, temp;
   n = 0;
   files = get_dir(dir);
   size = sizeof(files);
   if(size < 1) {
      write("Couldn't read/empty directory: "+dir+"\n");
      return 1;
   }
   while(n < size) {
       temp = file_size(files[n]);
       if(temp == -2) du(files[n]);
         else {
            write(files[n]);
             if(strlen(files[n]) < 8) write("\t");
            write(temp +"\n");
         }
      n++;
   }
   write("Done.\n");
   return 1;
}
