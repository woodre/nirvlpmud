id(str) { return str == "test"; }
short() { return "A test object"; }
get() { return 1; }
drop() { return 0; }

init() {
   add_action("copy_file","pcopy");
   add_action("test_clone","make");
   add_action("test_read","read");
}

test_clone(str) {
   object ob;
   if(file_size(str) < 0) write("FIle size < 0.\n");
   ob = clone_object(str);
   if(!ob) write("Clone failed.\n");
   move_object(ob, this_player());
   return 1;
}

test_read(file) {
   int size, current_line, next_line;
   string chunk;
   if(file_size(file) < 0) {
      write("No such file.\n");
      return 1;
   }
    size = sizeof(explode(read_file(file), "\n"));
   if(size < 1) {
      write("No such file.\n");
      return 1;
   }
   current_line = 1;
   next_line = 50;
   while(next_line < size) {
       chunk = read_file(file, current_line, next_line);
      write(chunk);
      current_line = next_line;
      next_line += 50;
   }
    chunk = read_file(file, current_line, size);
   write(chunk);
   write("\n\nDone.\n\n");
   return 1;
}

copy_file(file) {
   int size, current_line, next_line;
   string chunk, copy_name;
   size = sizeof(explode(read_file(file), "\n"));
   current_line = 1;
   next_line = 50;
   copy_name = "copy_test";
   write(copy_name+"\n");
   while(next_line < size) {
      chunk = read_file(file, current_line, next_line);
      write(chunk);
       write_file(copy_name, chunk);
      current_line = next_line;
      next_line += 50;
   }
   chunk = read_file(file, current_line, size);
   write_file(copy_name, chunk);
   write("Copy complete.\n");
   return 1;
}
