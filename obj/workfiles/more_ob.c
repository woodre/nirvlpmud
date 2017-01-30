id(str) { return (str == "more_verte_object"); }
drop() { return 1; }
get() { return 1; }
string more_file;
string last_search;
int more_line;
int CHUNK;
init() { add_action("more", "x123321123321"); }
#define ESC ""
#define NORM ESC+"[2;37;0m"
#define BOLD ESC+"[1m" 
#define SEARCH_CHUNK 300

void show_pos();

more(str)
{
   string tmore;
   string pwd;

   object me;
   
   if(!str)
      return (destruct(this_object()), 0);
   me=this_player();
   if(me && me->query_level() > 19 ) {
     pwd=this_player()->get_path();
     if(!pwd) pwd="/";
     tmore=resolv_path(pwd,str);
     write("More: "+tmore+"\n");
   } else {
     tmore=str;
   }
   if(file_size(tmore) < 1) {
      write("That file does not exist.\n");
      destruct(this_object());
      return 1;
   }
   more_file = tmore;
   more_line = 1;
   CHUNK=20;
   if (cat(more_file, more_line, CHUNK) == 0) {
      write("No such file.\n");
      destruct(this_object());
      return 1;
   }
   show_pos();
   input_to("even_more");
   return 1;
}

int search_file(int start_line,string search) {
  string cur_line;
  string *lines,*matches;
  int x;
  int cur_line_number;
  cur_line_number=start_line+1;
  last_search=search;
  while(cur_line=read_file(more_file,cur_line_number,SEARCH_CHUNK)) {
    lines=explode(cur_line,"\n");
    matches=regexp(lines,search);
    if(sizeof(matches)) {
      cur_line_number+=member_array(matches[0],lines);
      x=0;
      while(cur_line[x..x++]=="\n") /* corrects an issue with explode */
        cur_line_number++;
      cat(more_file,cur_line_number,CHUNK);
      return cur_line_number;
    }
    cur_line_number += SEARCH_CHUNK;
  }
  write(search+" not found.\n");
  return -1;
}
  

static even_more(str) {
   string search;
   int select_num;
   if(str=="?" || str == "h") {
     write("/<string>       - search for <string> in the remaining file\n");
     if((int)this_player()->query_level()>19)
       write("        See /doc/Driver/doc/efun/regexp for patterns for searching.\n");
     write("positive number - jump to that line number\n");
     write("-number         - scroll back that number of lines\n");
     write("+number         - jump forward that number of lines\n");
     write("u               - scroll back 1 page\n");
     write("d or <return>   - scroll forward 1 page\n");
     write("page <number>   - change the page size (20-49)\n");
     write("h or ?          - show this page\n");
     show_pos();
     input_to("even_more");
     return;

   } else if(sscanf(str,"/%s",search)) {
     int result_line;
     result_line=search_file(more_line,search);
     if(result_line!=-1) {
       more_line=result_line;
     }
     show_pos();
     input_to("even_more");
     return;
   } else if(sscanf(str,"+%d",select_num)) {
     if(select_num<0)
       select_num=0;
     more_line+=select_num;
   } else if(sscanf(str,"%d",select_num)) {
     if(select_num>0)
       more_line=select_num;
     else {
       more_line+=select_num;
       if(more_line<0)
       more_line=1;
     }
   } else if(sscanf(str,"page %d",select_num)) {
     if(select_num<20) select_num=20;
     if(select_num>49) select_num=49;
     more_line+= CHUNK-select_num;
     if(more_line<1) more_line=1;
     CHUNK=select_num;
     write("Page length set to "+CHUNK+"\n");
     show_pos();
     input_to("even_more");
     return;
   } else if (str == "" || str == "d")
      more_line += CHUNK;
   else if (str == "q") {
      write("Ok.\n");
      destruct(this_object());
      return;
   } else if (str == "u") {
      more_line -= CHUNK;
      if (more_line < 1)
         more_line = 1;
   }
   if(cat(more_file, more_line, CHUNK) == 0) {
      more_file = 0;
      write("EOF\n");
      destruct(this_object());
   } else {
     show_pos();
     input_to("even_more");
   }
}

void show_pos() {
  write(BOLD+"More: (lines "+NORM+more_line + 
        BOLD+"-"+NORM + (more_line + CHUNK -1) +BOLD+ ") "+NORM+"[? for help]");
}
