/* 
  Function: grep
  Creator: Wizardchild, of course
  Purpose: scan files for text string
  Extras:  Accepts wildcards
           uses call_out to avoid driver time limit
           expands large files into pre-arrays
*/
#include "../lib/lib.h"
 
#pragma strict_types
#pragma save_types
 
#define Print_usage() \
 write("Usage: grep <'string'> <location>  or  grep -n <'string'> <location>\n")
 
#define Tell_string(str) \
 (log_file ? (void) write_file(log_file, str) : tell_object(tp, str))
 
void grep_file(mixed *data);
void notify_end(object tp);
int downsize(string source, string *out);
int my_strlen(string source);
 
int grep(string str) {
  string match, where, path, root;
  string *dir, log_file, tmp, tmp_file,*tarr; 
  int i,num_files,x,n;
  status print_lines;
  object tp;
  dir = ({ });
  tp = this_player();
  if(!str || str == "") {
    Print_usage();
    return 1;
  }
  if(sscanf(str, "-n %s %s", match, where) < 2 &&
     sscanf(str, "-n '%s' %s", match, where) < 2) {
    if(sscanf(str, "%s %s", match, where) < 2 &&
       sscanf(str, "'%s' %s", match, where) < 2) {
      Print_usage();
      return 1;
    }
  } else
    print_lines = 1;
  if(sscanf(where, "%s > %s", tmp, log_file) == 2 ||
     sscanf(where, "%s >%s", tmp, log_file) == 2) 
    where = tmp;
  path = (string) fix_path(where);
  if(log_file && log_file[0] != '/')
    log_file = this_player()->get_path() + log_file;
  dir = get_dir(path);
  root = (string) get_root(path);
  i = sizeof(dir);
  write("Searching for \""+match+"\" in \""+path+"\".\n");
  write((print_lines ? "Printing":"Not printing")+" line numbers.\n");
  if(log_file) {
    write("Logging to file: "+log_file+"\n");
    write_file(log_file, "---==="+match+" in "+path+"===---\n");
  }
  i--;
  num_files = 0;
  tmp_file  = 0;
  tarr = ({ }); /* allocate memory */
  while(i >= 0) {
    if(dir[i] != "." && dir[i] != ".." && file_size(root+dir[i]) != -2) {
      tmp_file = read_file(root+dir[i]);
	if( !tmp_file ) continue;
      if(x = downsize(tmp_file, tarr)) {
        write("x="+x+",so(tarr)="+sizeof(tarr)+"\n");
        for(n = 0; n < x; n++) 
          if(tarr[n] && tarr[n] != "")
          call_out("grep_file", 0, ({ "continued", match, tp, print_lines,
                                      tarr[n], log_file }));
      } else   
        call_out("grep_file", 0, ({ root+dir[i], match, tp, print_lines, 
                                    tmp_file, log_file }));
      if(i == 0)
        call_out("notify_end", 1, tp);
      num_files++;
    }
    i--;
  }
  write(num_files+" files found for searching.\n");
  write("Call_outs completed.\n");
  return 1;
}
/* ({ file, string_to_match, this_player(), line_printing, all_file, log }) */
void grep_file(mixed *data) {
  string file, match, log_file;
  object tp;
  status pln;
  string rf, *exp, tmp, foo;
  int ln,so;
  file  = (string) data[0];
  match = (string) data[1];
  tp    = (object) data[2];
  pln   = (status) data[3];
  rf    = (string) data[4];
  log_file = (string) data[5];
  Tell_string("--= "+file+" =--\n");
  exp = explode(rf, "\n");
  if(!(so = sizeof(exp))) {
    Tell_string("Error! Unable to explode file.\n");
    return ;
  }
  for(ln = 0; ln < so; ln++) {
    if(sscanf(exp[ln], "%s"+match+"%s", tmp, foo) > 0) { 
      if(pln)
        Tell_string("  "+(ln)+": "+exp[ln]+"\n");
      else
        Tell_string("  "+exp[ln]+"\n");
    }
  }
}
void notify_end(object tp) {
  tell_object(tp, "Completed.\n");
}
int downsize(string source, string *out) {
  string *t,tmp,foo,foo2;
  int ch, avg, start, top, total;  
  t = allocate(5);
  if(sscanf(source, "%s\n%s\n%s\n%s\n%s\n%s",t[0],t[1],t[2],t[3],t[4],foo) < 6) 
    return 0;
  foo = 0;
  avg = strlen(t[0])+strlen(t[1])+strlen(t[2])+strlen(t[3])+strlen(t[4]);
  avg = avg/5;
  ch  = 800*avg; 
  start = 0;
  total = 0;
  while(1) {
    top = start + ch;
    if(source == 0 || source == "")
      break;
    if(top >= strlen(source)) 
      top = strlen(source)-1;
    tmp = extract(source, start, top);  
    source = extract(source, ch+1, strlen(source)-1);
    if(sscanf(source, "%s\n%s", foo, foo2) < 2)
      foo = source;
    ch     += strlen(foo);
    tmp    += foo;
    source  = foo2;
    out    += ({ tmp });
    start   = top;
    top    += ch;
    foo  = 0;
    foo2 = 0;
    total++;
  }
  if(total == 1)
    return 0;
  out += ({ });
  return total;
}

int my_strlen(string source) {
  int i;
  if(!source) return -1;
  for( i = 0; source[i]; i++ );
  return i;
}
