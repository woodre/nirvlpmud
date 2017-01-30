#include "../defs.h"

cmd(string str){
string file,func;
string before,after;
string data;
string stuff1,stuff2,stuff3;
  if(!str){
    notify_fail("What file would you like to funcgrep?\nUsage: funcgrep <file> <function>\n");
    return 0;
  }
  if(sscanf(str,"%s %s",file,func) != 2){
    notify_fail("What function would you like to funcgrep?\nUsage: funcgrep <file> <function>\n");
    return 0;
  }
  data =read_file(file);
  if(sscanf(data,"%s"+func+"%s",before,after) == 2){
    write("Function found.\n");
  sscanf(after,"%s{%s}%s",stuff1,stuff2,stuff3);
    write(func+stuff1+stuff2);
    return 1;
  }
  write("didn't work.\n");
  return 1;
}