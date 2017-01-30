#include <regexp.h>

#define DEBUG 1

string *exit_rooms;

status cmd_ss_make_area(string str) {
   string map, hold, char, default_dir, start_file, end_file;
   string *line, *tmp, *exits, *tmp2, *tmp3;
   int x, y, a, xt, yt;
   
   if(str)
      {
      if(sscanf(str,"%s %s %d %d",map, default_dir, xt,yt) != 4)
         map = str;
   }
   
   if(default_dir && extract(default_dir,strlen(default_dir) - 1) != "/") default_dir += "/";

   if(!default_dir) default_dir = (string)this_player()->get_path();

  // Get the exit_rooms
  if( !restore_object( default_dir + "map_key") )
    return notify_fail("Bad Key: "+default_dir+"map_key"+".\n");

  map = read_file(this_player()->get_path()+map);

  // Read the file
  if( strlen( map ) < 1 )
    return notify_fail("Bad Map\n");

   map = regreplace( map, "[ "+implode(exit_rooms, "")+"]", 
     function string( string str ) { 
       if( member( exit_rooms, str ) >= 0 )
         return "*";
       else
         if( str == " " )
	   return "";
         else
	   return ".";
       return str;
     }
     , RE_GLOBAL );
   tmp = ({ });
   
   if(!map) {
      write("No map to read.\n");
      return 1; 
   }
#if DEBUG
   write(map);
#endif
   
   if(!(start_file = read_file(this_player()->get_path()+"rstart")))
      start_file = read_file("/players/dragnar/wiztool/rstart");
   if(!(end_file = read_file(this_player()->get_path()+"rend")))
      end_file = read_file("/players/dragnar/wiztool/rend");  
   line = explode(map,"\n");
   for(x = 0; x < sizeof(line); x++) {
      hold = "";
      for(y = 0; y < strlen(line[x]); y++) {
         char = extract(line[x],y,y);
         if( char == "*" ) { char = this_player()->get_path()+"r"+x+"c"+y; }
         hold += char+","; 
      }
      line[x] = hold; 
   }
   
#if DEBUG
  write("Line Size: " + sizeof(line)+".\n");
#endif
   for(x = xt; x < sizeof(line); x++) {
      tmp = explode(line[x],",");
#if DEBUG
      write("["+x+"]"+line[x]+"\n");
#endif
      for(y = 0; y < sizeof(tmp); y++) {
         if(yt) { y = yt; yt = 0; }
         char = tmp[y];
         if(strlen(char) > 3) {
            exits = ({ char });
            
            /** Ensure this happens only on lines > 0 **/
            if(x) {
               tmp2 = explode(line[(x-1)],",");
               if(y < sizeof(tmp2) && strlen(tmp2[y]) > 3 ) {
                  tmp2 = explode(line[(x-1)],",");
                  exits += ({ "north-"+tmp2[y] }); } }
            
            if((x+1) < sizeof(line)) {
               tmp2 = explode(line[(x+1)],",");
               if(y < sizeof(tmp2) && strlen(tmp2[y]) && strlen(tmp2[y]) > 3 ) {
                  tmp2 = explode(line[(x+1)],",");
                  exits += ({ "south-"+tmp2[y] }); } }
            
            if(y) {
               hold = tmp[(y-1)];
               if( strlen(hold) > 3 ) {
                  exits += ({ "west-"+tmp[(y-1)] }); } }
            
            if((y+1) < sizeof(tmp)) {
               hold = tmp[(y+1)];
               if( strlen(hold) > 3 ) {
                  exits += ({ "east-"+tmp[(y+1)] }); 
	       }  
	    }
            map = exits[0];
            if(file_size(exits[0]) > 1) write("Already exists: "+exits[0]+" ("+x+","+y+")\n");
            if(file_size(exits[0]) < 2) {
               write("Writing file: "+map+".c ("+x+","+y+")\n");
               write_file(map+".c",start_file);
               write_file(map+".c","room_name = \"r"+x+"c"+y+"\";\n");
               write_file(map+".c","set_long(MAPDM->get_map( basename( this_object() )));\n" );
               if(sizeof(exits) > 1) {
                  write_file(map+".c", "dest_dir=({\n");
                  for(a = 1; a < sizeof(exits); a++) {
                     tmp2 = explode(exits[a],"-");
                     tmp3 = explode(tmp2[1],"/");
                     write_file(map+".c","\t \""+default_dir+tmp3[sizeof(tmp3) - 1]+"\",\""+tmp2[0]+"\",\n"); 
                  }
                  write_file(map+".c", "}); \n");
               }
               write_file(map+".c",end_file); }
          } } }
   write("\nArea Complete.\n");
   return 1; }
