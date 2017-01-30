#include "/players/mokri/define.h"
#define CHUNK 16
static string more_file;
static int more_line;


main(string str) {
   string *tmp;
   int pages;
   if (!str) return 0;
   more_file = str;
   more_line = 1;
str = "/players/mokri/cmds/funcs/modify_path"->modify_path(str);
   if(file_size(str) < 1) {
      write("No such file.\n");
      return 1; }
   tmp = explode(read_file(str),"\n");
   pages = (sizeof(tmp)/16);
   if((sizeof(tmp)%16)) pages += 1;
   if (cat(more_file, more_line, CHUNK) == 0) {
      write("No such file\n");
      return 1; }
   if(sizeof(tmp) < 17) return 1;
   input_to("even_more");
   write(HIY+"[Page 1 of "+pages+"] [q,x,#,b]: "+NORM);
   return 1; }
static even_more(str) {
   string *tmp;
   int x, pages;
   tmp = explode(read_file(more_file),"\n");
   pages = (sizeof(tmp)/16);
   if((sizeof(tmp)%16)) pages += 1;
   if(sscanf(str,"%d",x));
   if(x > 0 && x < (pages+2)) more_line = (x*16)-16;
   if(str == "q" || str == "x") {
      write(HIY+"[Exiting file: "+more_file+"]\n"+NORM);
      command("new_this",TP);
      return; }
   if (str == "b" || str == "-") {
      more_line -= CHUNK;
      if (more_line < 1)
         more_line = 1; }
   if(!str || str == "") more_line += CHUNK;
   cat(more_file, more_line, CHUNK);
   if((more_line+CHUNK) > sizeof(tmp)) {
      write(HIY+"[Exiting file: "+more_file+"]\n"+NORM);
      command("new_this",TP);
      more_file = 0;}
   
   if((more_line+CHUNK) <= sizeof(tmp)) {
      write(HIY+"[Page "+((more_line/16)+1)+" of "+pages+"] [q,x,#,b,-]: "+NORM);
      input_to("even_more"); 
   } 
}
