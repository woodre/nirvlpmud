id(str) { return (str == "more_verte_object"); }
drop() { return 1; }
get() { return 1; }
string more_file;
string last_search;
int more_line;
int CHUNK;
init() { add_action("more", "x123321123321"); }
#include "/players/fred/ansi.h"

void show_pos();

more(str)
{
   string tmore;
   string pwd;
   object myself;
   string tilda,blah;
   myself=this_player();
   CHUNK=20;
   if(this_player()) pwd=this_player()->get_path();
   if(!pwd) pwd="";
   
   if (!str)
      return (destruct(this_object()), 0);
   
   tmore = str;
   blah = pwd; /*
   if(extract(blah,0,0)!="/") blah = "/"+blah;
   if(extract(tmore,0,0)=="~") {
      tilda=extract(tmore,1,strlen(tmore));
      tmore = "/players/"+myself->query_real_name()+tilda;
   }
   if(extract(tmore,0,0)!="/") tmore = blah+tmore;
   */
   if((string)this_player()->query_guild_name() == "bloodfist") {
   tmore=resolv_path(blah,str);
   write("More: "+tmore+"\n");
}
   if(file_size(tmore) < 1) {
      write("That file does not exist.\n");
      destruct(this_object());
      return 1;
   }
   more_file = str;
   more_line = 1;
   if (cat(more_file, more_line, CHUNK) == 0) {
      write("No such file\n");
      destruct(this_object());
      return 1;
   }
   show_pos();
   input_to("even_more");
   return 1;
}

int search_file(int more_line,string search) {
  string cur_line;
  string tmp1,tmp2;
  string *words;
  int cur_line_number;
  if(last_search==search) /*Skip one page if searching for the same thing*/
    cur_line_number=more_line+CHUNK;
  last_search=search;
  while(cur_line=read_file(more_file,cur_line_number,CHUNK)) {
    if(sscanf(cur_line,"%s"+search+"%s",tmp1,tmp2)) {
      write(implode(explode(NORM+cur_line+NORM,search),BOLD+search+NORM));
      return cur_line_number;
    }
    cur_line_number += CHUNK;
  }
  write(search+" not found.\n");
  return -1;
}
  

static even_more(str) {
   string search;
   int select_num;
   if(str=="?" || str == "h") {
     write("/<string> - search for <string> in the remaining file\n");
     write("positive number - jump to that line number\n");
     write("negative number - scroll back that number of lines\n");
     write("u               - scroll back 1 page\n");
     write("d or <return>   - scroll forward 1 page\n");
     write("page <number>   - change the page size (20-49)\n");
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
        BOLD+"-"+NORM + (more_line + CHUNK -1) +BOLD+ ") "+NORM);
}
