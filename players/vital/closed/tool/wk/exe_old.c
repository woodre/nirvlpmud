/* exe.c: executes code-based functions */
/* usage: exe [options] <command>
/* options are:
 *  -f<file>     execute a pre-made file
 *  -d           don't rm on completion
 *  -nd          make file 'nice' w/ no deletion
 */
#include <ansi.h>
#define exe_dir "/players/wizardchild/exe/"
#define tmp_file exe_dir+"tmp"
#define is_flag(s) (s == "-f" || s == "-d" || s == "-nd")
 
short() { return "Your own personal jesus"; }
id(str) { return str == "jesus" || str == "personal jesus" || str == "exe"; }
get()   { return 1; }
drop()  { destruct(this_object()); }
long()  { 
  write("Usage: exe [-f<file>] [-d] [-nd] <command>\n");
  write("Where:\n");
  write(" -f<file>       execute a pre-made file (not deleted)\n");
  write(" -d             don't rm on completion\n");
  write(" -nd            make file 'nice' w/ no deletion\n");
  return 1;
}
init()  {
  if(this_player()->query_real_name() == "wizardchild")
    add_action("exe", "exe");
  else
    destruct(this_object());
}
exe(str) {
  string *args,file,foo,cmd;
  int i,so;
  status nodel, nice;
  if(!str) return long();
  file = tmp_file;
  args = explode(str, " ");
  if(!(so = sizeof(args))) args = ({str});
  for(i = 0; i < so; i++) {
    foo = args[i];
    if(foo[0] == '-' && i < 2) {
      if(is_flag(extract(foo,0,1)) || is_flag(extract(foo,0,2))) {
        if(foo[1] == 'd') nodel = 1;
        else if(foo[1] == 'f') {
          if(strlen(foo) == 2) {
            write("Error: no file specified.\n");
            return long();
          }
          sscanf(foo, "-f%s", file);
          if(file[0] != '/') file = exe_dir+file;
          nodel = 1;
        } else {  /* -nd */
          nice = 1;
          nodel = 1;
        }
      } else {
        write("Illegal flag: "+foo+".\n");
        return long();
      }
    } else {
      if(!cmd || cmd == "") cmd = foo;
      else cmd += " "+foo;
    }
  }    
  if(!nodel && file_size(file) > 0) rm(file);
  if(file && !sscanf(file, "%s.c", foo)) file += ".c";
  if(cmd) {
    if(nice == 1) cmd = nicen_str(cmd);
    write_file(file, "exe_cmd() { "+cmd+" }\n");
    write("Command: "+cmd+".\n");
  } else {
    if(file_size(file) < 1) {
      write("Fatal error: no such file: "+file+"\n");
      return long();
    }
  }
  write("Returns: "+file->exe_cmd()+"\n");
  if(!nodel) rm(file);
  if(find_object(file)) destruct(find_object(file));
  return 1;
}  
 
nicen_str(str) {
  string out, *arr;
  int i,so;
  arr = explode(str, ";");
  so = sizeof(arr);
  if(!so) return str;
  for(i = 0; i < so; i++) {
    if(!out || out == "") out = arr[i]+";\n";
    else out += arr[i]+";\n";
  }
  return "\n"+out;
}
