string file, chunk;
int current_line, next_line, max;
id(str) { return str == "printer"; }
short() { 
   if(this_player()&&this_player()->query_level() < 21) 
      destruct(this_object());
   return "A file printer";
}
long() { 
   write("A file printer. Type 'print <filename>'.\n");
}
query_value() { destruct(this_object());
}
get() { return 1; }
drop() { return 0; }

reset(arg) {
   if(arg) return;

   file = "0";
   current_line = 1;
   next_line = 1;
   chunk = "0";

}

init() {
   add_action("print_file","print");
   add_action("kill_print","stop");
}

print_file(str) {
   if(!str) {
      write("Its really easy....'print <filename>'.\n");
      return 1;
   }
   if(!read_file(str,1,1)) {
      write("Cannot locate or access denied.\n");
      return 1;
   }
   current_line = 1;
   next_line = 100;
   file = str;
   max = sizeof(explode(read_file(str), "\n"));
   set_heart_beat(1);
}

heart_beat() {
   print_chunk();
}

print_chunk() {
   if(next_line >= max) {
      next_line = max;
      set_heart_beat(0);
   }
   chunk = read_file(file, current_line, next_line);
   tell_object(environment(this_object()), chunk);
   current_line = next_line;
   next_line += 100;
   return 1;
}

