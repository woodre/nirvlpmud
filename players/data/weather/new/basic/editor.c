/* ----- A basic editor-object, to be cloned for writing mails or notes ---- 
  Without patching the mail_reader, this editor is able to write notes only.
 Flash for Tubmud, January 5th, 1994                                       
 Wizards are able to configure their prompts, a '.editor_cfg' is written in  
 the wizards home-directory.
*/
#define MAXLINES 20
#define CMD_FORMAT "[%d]? "
#define INS_FORMAT "%d>>"
#define TOBEDELETED "(/tobedeleted/)"
#include "wizlevels.h"

void insert_block(mixed *buf,int lineno);
void edit_new();

string fname;
mixed *lines;
mixed *insert_buffer;
int line;
int insert_line;
int modified;
int new_file;
object writer,receiver;
string head;
string cmd_format,ins_format;
closure callback_fun; /* added by Ugh to have more flexibility 23-Jul-1994 */

int bad_format(string format){
  return (sprintf(format,15)=="ERROR: (s)printf(): Error in format string.\n");
}

void save_formats(){
  if(!ins_format || ins_format=="default") ins_format=INS_FORMAT;
  if(!cmd_format || cmd_format=="default") cmd_format=CMD_FORMAT;
  fname="/players/"+(writer->query_real_name())+"/.editor_cfg";
  rm(fname);
  if(!write_file(fname,ins_format+"#"+cmd_format)){
    write("Error writing configfile\n");
  }
}

void read_formats(){
string t;
  fname="/players/"+(writer->query_real_name())+"/.editor_cfg";
  if(file_size(fname)<0) return;
  if(!(t=read_file(fname)) ){
    write("Error reading configfile\n");
    return;
  }
  if(sscanf(t,"%s#%s",ins_format,cmd_format)!=2){
    write("Damaged config-file!\n");
  }
}

string ins_prompt(int s){
  if(ins_format && ins_format!="default")
    return sprintf(ins_format,s+1);
  return sprintf(INS_FORMAT,s+1);
}

string cmd_prompt(){
  if(cmd_format && cmd_format!="default")
    return sprintf(cmd_format,line);
  return sprintf(CMD_FORMAT,line);
}

void reset(int arg){
  if(arg) return;
  insert_buffer=({});
  lines=({""});
  insert_line=1;
  line=1;
}

void readfile(string fname){
string contents;
  contents=read_file(fname);
  if(!stringp(contents)){
    write("Error reading file "+fname+"\n");
    return;
  }
  insert_buffer=explode(contents,"\n");
  insert_block(insert_buffer,sizeof(lines));
  insert_buffer=({});
  line=sizeof(lines);
  write("File "+fname+" read and inserted.\n");
}

string adjust(int i){
  if(i<10) return "[  "+i+"] ";
  if(i<100) return "[ "+i+"] ";
  if(i<1000) return "["+i+"] ";
}

void insert_block(mixed *buf,int lineno){
int i,o;
  o=sizeof(lines)-lineno;
  for(i=0;i<sizeof(buf);i++) lines+=({ "" });
  for(i=0;i<o+1;i++) lines[sizeof(lines)-1-i]=lines[sizeof(lines)-sizeof(buf)-i-1];
  for(i=0;i<sizeof(buf);i++) lines[i+lineno-1]=buf[i];  
}

void display(int l){
int i;
int offset;
string a;
  if(l>sizeof(lines)) l=sizeof(lines)-MAXLINES;
  if(l<0) l=1;
  offset=MAXLINES;
  if(l+offset>sizeof(lines)) offset=sizeof(lines)-l;
  line=l;
  l--;
  for(i=0;i<offset;i++){
     if(lines[i+l]=="")
       write(adjust(line+i)+" <empty>\n");
     else {
       a=adjust(line+i)+lines[i+l]+"\n";
       write(a);
     }
  }
}

void enter(object who,string str){ /* entry point for board-notes */
  head=str;
  receiver=previous_object();
  writer=who;
  ins_format=INS_FORMAT;
  cmd_format=CMD_FORMAT;
  read_formats();
  edit_new();
}

void edit_new(){
  insert_buffer=({});
  lines=({""});
  insert_line=1;
  write("Entered Insertmode, end it with '.' ('**' ends and quits), cancel with '~q'\n");
  write(ins_prompt(0));
  modified=1;
  input_to("insert_mode");
  return;
}

void leave(status flag){  // void added, Coogan, 28-May-1998
   if (!flag){
    write("Aborted.\n");
   } else {
     write("Bye.\n");
     if (callback_fun)
       funcall (callback_fun, 
		writer->query_real_name (), 
		implode(lines, "\n"));
     else
       receiver->finish_note(writer,head,implode(lines,"\n"));  /* for boards */
   }
#if 0
   destruct(this_object());
// removed by Carador, 27-Mar-1994. DON'T use destruct in inheritable classes.
#endif
}
/*
 * The next function should be called with a text (at least "") and
 * a closure which at the finishing of the note will be called 
 * with the name of the writer as first and the written text as second
 * argument (to be conform with /etc/editor).
 */
void edit_note (string text, closure callback) {
  writer = this_player ();
  callback_fun = callback;
  ins_format=INS_FORMAT;
  cmd_format=CMD_FORMAT;
  read_formats();
  insert_buffer = ({});
  lines = explode (text || "", "\n");  // Coogan, added "", 13-Nov-1998
  insert_line = 1;
  write ("Entered Insertmode, end it with '.' ('**' ends and quits), cancel with '~q'\n");
  write (ins_prompt(0));
  modified=1;
  input_to ("insert_mode");
  return;
}

void help(string b){
     switch (b){
       case "commands": 
        write("line <number>                   list from line <number> on\n"+
        "help [commands]                 get help on commands\n"+
        "quit                            quits normally\n"+
        "~q, abort                       quits without 'saving'\n"+
	"~e, ed				 starts the Ed with the current text\n"+
        "top, bottom                     goto top or bottom of file\n"+
        "del <line>                      delete line <line>\n"+
        "del <line1>-<line2>             delete block from <line1> to <line2>\n"+
        "bmov <l1>-<l2> <l3>             move block to line <l3>\n"+
        "ins <line>                      enter insertmode on line <line>\n"+
        "format all                      format all lines\n"+
        "format <from>-<to>              format block <from> <to>\n"+
        "change '<str1>' into '<str2>'   change (parts of) strings on act. line.\n"+
        "page                            display next page of file\n");
        if(writer->query_level()>=WL_WIZARD){
           write("read <filename>                 read contents of file.\n");
           write("set cmd_prompt <format>         set commandprompt\n");
           write("set ins_prompt <format>         set insertprompt\n");
           write(" <format> is used in sprintf(<cformat>,actual_line)\n");
           write(" Use <format>=='default' to get the default one.\n");
        }
             break;
       case "top": 
         write("top: Display contents from the beginning.\n");
         break;
       case "bottom": 
         write("bottom: Go to last line of file.\n");
         break;
       case "quit": 
         write("quit: Quit the editor.\n");
         break;
       case "line": 
         write("line: Syntax 'line <number>' Goto line <number>\n"); 
         break;
       case "del": 
         write("del: Syntax 'del <line>':    Delete line number <line>\n"); 
         write("         or 'del <l1>-<l2>': Delete lines from <l1> to <l2>\n"); 
         break;
       case "bmov":
         write("bmov: Syntax 'bmov <l1>-<l2> <l3>' Move Block <l1>-<l2> to line <l3>\n");
         break;
       case "page":
         write("page: Display next page.\n"); 
         break;
       case "read":
         if(writer->query_level()>=WL_WIZARD)
           write("read <filename>: Read contents of file <filename>\n");
         break;
       case "change":
         write("change: Syntax 'change '<string1>' into '<string2>'' \n");
         write("               tries to substitute string1 with string2.\n");
         write("               NOTE: ' is needed at beginning and end of string\n");
         break;
       case "format":
         write("format: Syntax 'format [ all | <l1>-<l2> ]' tries to format the lines\n");
         break;
       default: write("No such help available\n"); break;
     }
}

void delete_line(int number){
int i;
  if(number<1 || number>sizeof(lines)){
    write("There is no such linenumber!\n");
    return;
  }
  for(i=number-1;i<sizeof(lines)-1;i++) lines[i]=lines[i+1];
  lines[sizeof(lines)-1]=TOBEDELETED;;
}

void compress_array(int c){
int i;
  for(i=0;i<c;i++) lines-=({TOBEDELETED});
}

void delete_block(int from,int to){
  int i;
  if(to<from){
    write("Blockdelete: Parameter error!\n");
    return;
  }
  for(i=0;i<sizeof(lines)-to;i++) lines[from-1+i]=lines[to+i];
  for(i=0;i<to-from+1;i++) lines[sizeof(lines)-1-i]=TOBEDELETED;
  compress_array(to-from+1);
}

void move_block(int from1,int from2,int to){ /* not nice, but working */
mixed *buffer,*mbuf;
int last,i,o;
   if( from2<from1 || to > sizeof(lines) || to<=0 ){
     write("Blockmover: Parameter error!\n");
     return;
   }
   if(to>=from1 && to<=from2){
     write("Blockmover: Parameter error!\n");
     return;
   }
   o=from2-from1+1;
   buffer=allocate(o);
   for(i=0;i<o;i++) buffer[i]=lines[from1-1+i];
   if(to>from2){
      for(i=0;i<to-from2;i++) lines[from1-1+i]=lines[from2+i];
      for(i=0;i<o;i++) lines[to-i-1]=buffer[sizeof(buffer)-i-1];
   } else {
      mbuf=allocate(from1-to+1);
      for(i=0;i<(from1-to+1);i++) mbuf[i]=lines[to-1+i];
      for(i=0;i<o;i++) lines[to-1+i]=buffer[i];
      for(i=0;i<from1-to+1;i++) lines[to+o-1+i]=mbuf[i];
   }
}

void format_lines(int a,int b){
string *buf;
int i;
  if(a>=b){ write("Error on parameters!\n"); return; }
  if(b>sizeof(lines)) b=sizeof(lines)-1;
  if(a<=0) a=1;
  buf=({});
for(i=a;i<=b;i++) buf+=({ lines[i-1] });
  buf=explode(break_string( implode(buf," "),75,0)+"\n","\n");
  buf-=({""});
  buf-=({"\n"});
  buf[sizeof(buf)-1]=buf[sizeof(buf)-1]+"\n";
  delete_block(a,b);
  insert_block(buf,a);
  line=1;
  write("Okay, formatting of lines "+a+" to "+b+" ready.\n");
}

void change_me(string a,string b,int l){
string first,last,f;
int i;
  f="%s"+a+"%s";
  if((i=sscanf(lines[l-1],f,first,last))==2){
    lines[l-1]=first+b+last;
    write("Okay.\n");
    return;
  }
  write("Change from "+a+" to "+b+" didn't work.\n");
}

void get_editor_command(string str){
string a,b,b1,b2;
int number,num2,num3;
   if(str=="quit" || str=="**"){ leave(1); return; }
   if(str=="~q" || str=="abort"){ leave(0); return; }
   if(sscanf(str,"change '%s' into '%s'",a,b)==2){
      change_me(a,b,line);
      write("\n"+cmd_prompt());
      input_to("get_editor_command");
      return;
   }
   if (str == "~e" || str == "ed")
   {
       "/etc/editor"->edit_temp (implode (lines, "\n"), callback_fun);
       write ("Type 'h' for help, '.' to get out of the insert mode, 'q' or "
	      "'Q' to abort\nand 'x' to quit and save.\n");
       return;
   }
   if(str=="top"){ 
      line=1; 
      display(line); 
      write("\n"+cmd_prompt());
      input_to("get_editor_command");
      return;
   }
   if(str=="display"){ 
      display(line); 
      write("\n"+cmd_prompt());
      input_to("get_editor_command");
      return;
   }
   if(str=="page"){ 
      line+=MAXLINES-1;
      display(line); 
      write("\n"+cmd_prompt());
      input_to("get_editor_command");
      return;
   }
   if(str=="bottom"){ 
      line=sizeof(lines)-MAXLINES; 
      display(line); 
      write("\n"+cmd_prompt());
      input_to("get_editor_command");
      return;
   }
   if(str=="help"){
     help("commands");
     write(cmd_prompt());
     input_to("get_editor_command");
     return;
   }
   if(sscanf(str,"%s %s",a,b)!=2){
     write("\nCommand not understood, try 'help commands'\n");
     write(cmd_prompt());
     input_to("get_editor_command");
     return;
   }
   if(a=="set"){
      if( (writer->query_level()<WL_WIZARD)
        || (sscanf(b,"%s %s",b1,b2)!=2) ){
           write("\nCommand not understood, try 'help commands'\n");
           write(cmd_prompt());
           input_to("get_editor_command");
           return;
      } 
      switch (b1){
        case "cmd_prompt":
             if(bad_format(b2)) write("Bad formatstring\n"); 
             else { cmd_format=b2; save_formats(); }
             break;
        case "ins_prompt":
             if(bad_format(b2)) write("Bad formatstring\n");
             else { ins_format=b2; save_formats(); }
             break;
        default:
           write("\nCommand not understood, try 'help commands'\n");
           break;
      }
      write(cmd_prompt());
      input_to("get_editor_command");
      return;
   }
   if(a=="read"){
     if(writer->query_level()<WL_WIZARD){
       write("Unsupported command.\n");
     } else 
       readfile(b);
     input_to("get_editor_command");
     return;
   }
   if(a=="help"){
     help(b);
     write(cmd_prompt());
     input_to("get_editor_command");
     return;
   }
   if(a=="line"){
     if(sscanf(b,"%d",number)!=1){
       write("linenumber required!\n");
     } else {
// Check for bad linenumer added by Carador, 06-Jun-1994
       if(number<=0 || number>sizeof(lines)){
          write("Bad linenumber!\n");
       }       
       else {
          write("Displaying file from line "+number+" on.\n");
          line=number;
          display(number);
       }
     }
   }
   if(a=="del"){
      if(sscanf(b,"%d-%d",number,num2)!=2){
        if(sscanf(b,"%d",number)!=1){
           write("Parameter error for 'del'\n");
        } else  {
         delete_line(number);
         modified=1;
         compress_array(1);
        }
      } else {
         delete_block(number,num2);
         modified=1;
      }
   }
   if(a=="ins"){
     if(sscanf(b,"%d",number)!=1){
        write("Insert needs linenumber!\n");
     } else {
       if(number<=0 || number>sizeof(lines)){
          write("Bad linenumber!\n");
       } else {
         insert_line=number;
         write("Entered Insertmode, end it with '.' ('**' ends and quits), cancel with '~q'\n");
         write(ins_prompt(0));
         modified=1;
         input_to("insert_mode");
         return;
       }
     }
   }
   if(a=="bmov"){
     if(sscanf(b,"%d-%d %d",number,num2,num3)!=3){
       write("linenumbers for block-moving required!\n");
     } else {
       move_block(number,num2,num3);
       modified=1;
     }
   }
   if(a=="format"){  
     if(b=="all"){
       lines=explode(break_string(implode(lines," "),75,0)+"\n","\n");
       line=1;
       write("Okay, formatting ready.\n");
     } else
     if(sscanf(b,"%d-%d",number,num2)!=2){
       write("Error! Use 'format all' or 'format <from>-<to>'\n");
     } else {
       format_lines(number,num2);
     }
     write("\n"+cmd_prompt());
     input_to("get_editor_command");
     return;
   }
   write("\n"+cmd_prompt());
   input_to("get_editor_command");
   return;
}

void insert_mode(string str){
string *buf;
int i;
string cmd;
   switch (str){
     case "~e":
       insert_block(insert_buffer, insert_line);
       insert_buffer = ({});
       get_editor_command ("~e");
       break;
     case "**":
       insert_block(insert_buffer,insert_line);
       insert_buffer=({});
       leave(1);
       break;
     case ".":
       insert_block(insert_buffer,insert_line);
       write("Left insertmode, entering command-mode.\n");
       write("\n"+cmd_prompt());
       insert_buffer=({});
       input_to("get_editor_command");
       break;
     case "~q":
     case "abort":
       write("Inserting aborted.\n");
       write("\n"+cmd_prompt());
       insert_buffer=({});
       input_to("get_editor_command");
       break;
     default:
       buf=({});
       buf=explode(break_string( str,76,0),"\n");
       for(i=0;i<sizeof(buf);i++)
         insert_buffer+=({buf[i]});
       write(ins_prompt(sizeof(insert_buffer)));
       input_to("insert_mode");
       break;
   }
   return;
}

