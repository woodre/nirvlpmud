string file;
short() { return "A logging device"; }
id(str) { return str == "log" || str == "device" || str == "logging device"; }
get()   { return 1; }

long()  {
  write("Commands:\n");
  write("set_file <fname>   Set the logging file.\n");
  write("logmsg <str>       Log a message.\n");
  return 1;
}

reset(arg) {
  if(arg) return ;
  file = "/players/vital/log/notes.log";
}

init()  {
  add_action("set_file","set_file");
  add_action("logmsg", "logmsg");
}

set_file(str) {
  int i;
  if(!str) return 0;
  if(str[0] != '/')
    str = "/players/vital/log/"+str;
  for(i = 0; i < strlen(str); i++) 
    if(str[i] == '.') break;
  if(i == strlen(str))
    str += ".log";
  write("Log file set to "+str+".\n");
  file = str;
  return 1;
}

logmsg(str)  {
  if(!str || !file) return 0;
  write_file(file, "["+extract(ctime(time()),0,9)+"]-> "+str+"\n");
  write("Ok.\n");
  return 1;
}
