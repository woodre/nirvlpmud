string dir;

void make_sure(string str) {
   int x;
   string *files;
   
   if(str != "y" && str != "Y" && str != "yes" && str != "Yes") {
      write("Aborted.\n"); return; }
   files = get_dir(dir);
   for(x = 0; x < sizeof(files); x++)
   if(file_size(dir+files[x]) != -2) rm(dir+files[x]);
   write("Done.\n");
   return; }

main(string str) {
   dir = str;
   if(!dir) dir = (string)this_player()->get_path();
   if(extract(dir,0,0) == "~") dir = "/players/"+extract(dir,1)+"/";
   if(extract(dir,0,0) != "/") dir = this_player()->get_path()+dir+"/";
   if(file_size(dir) != -2) { write("Not a directory!\n"); return 1; }
   input_to("make_sure");
   write("Delete all files in "+dir+".\n"+
      "Are you sure? (y/n) > ");
   return 1; }
