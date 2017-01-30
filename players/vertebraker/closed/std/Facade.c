string insideRoom;
string logFile;
string enterCmd;
string usrEntranceMsg;
string othEntranceMsg;
string insideEntranceMsg;

inherit "/obj/treasure";
inherit "/players/vertebraker/closed/std/CheckArgument.c";

status get() { return 0; }
int    query_prevent_shadow() { return 1; }
int    is_castle() { return 1; }

void init()
{
 ::init();
 if(enterCmd)
 {
  add_action("CmdEnter", enterCmd);
  add_action("CmdIn","in");
 }
}

int CmdEnter(string arg)
{
 if(!this_player()->is_player())
  return 0;

 if(CheckArgument(arg,0,0))
 {
  write(usrEntranceMsg);
  say((string)this_player()->query_name() + " " + othEntranceMsg);
  tell_room(insideRoom, 
   (string)this_player()->query_name() + " " + insideEntranceMsg);
  write_file(logFile, "[" + ctime()[4..15] + "] " + 
   capitalize((string)this_player()->query_real_name()) + 
   " entered " + short() + ".\n");
  move_object(this_player(), insideRoom);
  return 1;
 }
}

int CmdIn()
{
 return CmdEnter(name);
}

void SetInsideRoom(string path) { insideRoom = path; }
string QueryInsideRoom() { return insideRoom; }

void SetLogFile(string path) { logFile = path; }
string QueryLogFile() { return logFile; }

void SetEnterCmd(string cmd) { enterCmd = cmd; }
string QueryEnterCmd() { return enterCmd; }

void SetUsrEntranceMsg(string msg) { usrEntranceMsg = msg; }
string QueryUsrEntranceMsg() { return usrEntranceMsg; }

void SetOthEntranceMsg(string msg) { othEntranceMsg = msg; }
string QueryOthEntranceMsg() { return othEntranceMsg; }

void SetInsideEntranceMsg(string msg) { insideEntranceMsg = msg; }
string QueryInsideEntranceMsg() { return insideEntranceMsg; }
