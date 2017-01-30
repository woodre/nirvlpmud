   /*                   bin_catch.c                */
   /*    To connect a players commands to files    */


mapping * commands;
goto /room/pub2
l
people
pwho
shw
int num_paths = 0;

int id(string test) { return test == "binob" ||
                             test == "bin"   ||
                             test == "bin object";
}

string short() {
   return "A Bin Object";
}

void long() {
   write("This is a wizards been tool.\n");
   write("Type 'help bin' to see how to use it.\n");
}

void reset(int arg) {

   if(!arg) {

   paths = ({});

   }
}

int new_path(string path) {
   string temp1, temp2;
   int size;
   if(!paths && !pointerp(paths)) {
      paths[0] = path;
      write("Bin path added: ");
      write(path +"\n");
      return 1;
   }
   paths[num_paths] = path;
   num_paths +=1;
   write("Bin path added: "+paths[size]+"\n");
   return 1;
}

int print_paths() {
   int size, n;
   n = 0;
   if(pointerp(paths)) {
      size = sizeof(paths);
      while(n < size) {
         write(paths[n]+"\n");
         n+=1;
      }
   }
   if(paths) {
      write(paths+"\n");
      return 1;
   }
  write("No paths.\n");
   return 1;
}

void init() {
   if(this_player()&&this_player()->query_level() < 21)
      destruct(this_object());
 
   add_action("print_paths","ppaths");
   add_action("new_path","apath");

}

int update_comm() {
   int n;
   string current_file;
   string * dir;
   while(n < 10) {
      if(paths[n]) {
         dir = get_dir(paths[n]+"/");
         while(flnum < sizeof(dir)) {
            if(sscanf(dir[flnum], "_%s.c", command) == 1) {
