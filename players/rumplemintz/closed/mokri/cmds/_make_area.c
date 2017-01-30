status main(string str) {
   string map, hold, char, default_dir, start_file, end_file;
   string *line, *tmp, *exits, *tmp2, *tmp3;
   int x, y, rnum, a, xt, yt;
   
   if(str)
      {
      if(sscanf(str,"%s %d %d",default_dir, xt,yt) != 3)
         default_dir = str;
   }
   
   if(default_dir && extract(default_dir,strlen(default_dir) - 1) != "/") default_dir += "/";
   map = read_file(this_player()->get_path()+"map");
   tmp = ({ });
   rnum = 1;
   if(!map) {
      write("No map to read.\n");
      return 1; }
   
   if(!(start_file = read_file(this_player()->get_path()+"rstart")))
      start_file = read_file("/open/mokri/rstart");
   if(!(end_file = read_file(this_player()->get_path()+"rend")))
      end_file = read_file("/open/mokri/rend");  
   line = explode(map,"\n");
   for(x = 0; x < sizeof(line); x++) {
      hold = "";
      for(y = 0; y < strlen(line[x]); y++) {
         char = extract(line[x],y,y);
         if(char == "*") { char = this_player()->get_path()+"r"+rnum; rnum += 1; }
         hold += char+","; }
      line[x] = hold; }
   
   for(x = xt; x < sizeof(line); x+=2) {
      tmp = explode(line[x],",");
      for(y = 0; y < sizeof(tmp); y++) {
         if(yt) { y = yt; yt = 0; }
         char = tmp[y];
         if(strlen(char) > 3) {
            exits = ({ char });
            
            if(x) {
               tmp2 = explode(line[(x-1)],",");
               if(y < sizeof(tmp2) && tmp2[y] == "|") {
                  tmp2 = explode(line[(x-2)],",");
                  exits += ({ "north-"+tmp2[y] }); } }
            
            if((x+2) < sizeof(line)) {
               tmp2 = explode(line[(x+1)],",");
               if(y < sizeof(tmp2) && tmp2[y] == "|") {
                  tmp2 = explode(line[(x+2)],",");
                  exits += ({ "south-"+tmp2[y] }); } }
            
            if(y) {
               hold = tmp[(y-1)];
               if(hold == "-") {
                  exits += ({ "west-"+tmp[(y-2)] }); } }
            
            if((y+1) < sizeof(tmp)) {
               hold = tmp[(y+1)];
               if(hold == "-") {
                  exits += ({ "east-"+tmp[(y+2)] }); } }
            map = exits[0];
            if(file_size(exits[0]) > 1) write("Already exists: "+exits[0]+" ("+x+","+y+")\n");
            if(file_size(exits[0]) < 2) {
               write("Writing file: "+map+".c ("+x+","+y+")\n");
               write_file(map+".c",start_file);
               if(sizeof(exits) > 1) {
                  if(!default_dir) default_dir = (string)this_player()->get_path();
                  for(a = 1; a < sizeof(exits); a++) {
                     tmp2 = explode(exits[a],"-");
                     tmp3 = explode(tmp2[1],"/");
                     write_file(map+".c","add_exit(\""+default_dir+tmp3[sizeof(tmp3) - 1]+"\",\""+tmp2[0]+"\");\n"); } }
               write_file(map+".c",end_file); }
          } } }
   write("\nArea Complete.\n");
   return 1; }
