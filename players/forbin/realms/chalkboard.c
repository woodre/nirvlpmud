/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2004 Forbin
//                  All Rights Reserved.
//  Function:     Bulletin Board
//  Create Date:  2004.07.23
//  Last Edit:    2004.07.23 -Forbin
//  Notes:        Adapted heavily from bulletin board by Groo
//                  Original Copyright (c) Groo 1990
//  Notable Changes:
*/
#include "/players/forbin/define.h"
#include "/players/forbin/logging.h"
#include "/players/forbin/closed/pc.h"

#define ERROR_LOG "/players/forbin/logs/cb_error"
#define BOARD_NAME "players/forbin/logs/cb"

string NewHead, NewText, TempHead, TempText;
int MsgNum;

static string  Messages, Headers;
static int Line, LookedAt;
static object CurrentWriter;

id(str) { return (str == "board" || str == "chalk board" || 
                  str == "post" || str == "chalkboard"); }

short() { return HIK+"A large chalkboard"+NORM+(!MsgNum ? "" : (MsgNum == 1 ? HIK+" ("+HIW+MsgNum+" message"+HIK+")"+NORM : HIK+" ("+HIW+MsgNum+" messages"+HIK+")"+NORM)); }

long() {
  int index;
  write(
    "This is a large, rectangular chalkboard that has been nailed to\n"+
    "a short post.  A small ledge mounted beneath the board holds a few\n"+
    "pieces of white chalk.  "+(!MsgNum ? "There is nothing written on the board." : (MsgNum == 1 ? "There is "+convert_num(MsgNum)+" note scribbled on the board." : "There are "+convert_num(MsgNum)+" notes scribbled on the board."))+"\n");
  write(
    "You may 'scribble <topic>', 'read <number>', or 'remove <number>'.\n");
  if(query_pc(this_player()->query_real_name())) {
    write("You may also 'store <message>' to save the message to a file.\n");
  }    
  index = 0;
  while (index < MsgNum) {
    write(colour_pad("  "+HIW+(index+1)+":"+NORM, -5));
    write("  "+Headers[index]+"\n");
    index++;
  }
}

get() {
  write("The chalkboard is secured firmly to the post.\n");
  return 0;
}

init() {
  add_action("cmd_scribble", "scribble");
  add_action("cmd_read", "read");
  add_action("cmd_remove", "remove");
  add_action("cmd_store", "store");
  if(!LookedAt) {
    int i;
    string arr;
    Messages = allocate(200);
    Headers = allocate(200);
    LookedAt = 1;
    if(!restore_object(BOARD_NAME)) return;
    arr = explode(TempHead, "\n**\n");
    i = 0;
    while(i < sizeof(arr)) {
      Headers[i] = arr[i];
      i++;
    }
    arr = explode(TempText, "\n**\n");
    i = 0;
    while(i < sizeof(arr)) {
      Messages[i] = arr[i];
      i++;
    }
    TempText = "";
    TempHead = "";
  }
}

reset(arg) {
  if(arg) return;
}

cmd_scribble(string topic) {
  Line = 1;
  if(!topic) return 0;
  if(CurrentWriter && environment(CurrentWriter) == environment(this_object())) {
    write(this_player()->query_name()+" is busy writing with the chalk.\n");
    return 1;
  }
  if(MsgNum == 50) {
    write("An old message must be removed first.\n");
    return 1;
  }
  if(strlen(topic) > 50) {
    write("That topic is too long.  Try again with a shorter one.\n");
    return 1;
  }
  CurrentWriter = this_player();
  say(CurrentWriter->query_name()+" starts scribbling on the chalkboard.\n");
  NewHead = topic;
  NewText = "";
  input_to("get_msg");
  write("Enter message text.  End with '**', abort with '~q'.\n");
  write("["+pad("1",-3)+"]");
  return 1;
}

get_msg(string str) {
  if(str == "~q") {
    say(CurrentWriter->query_name()+" stops what "+CurrentWriter->query_pronoun()+" is writing and erases it.\n");
    write("Message aborted.\n");
    CurrentWriter = 0;
    NewHead = "";
    NewText = "";
    return;
  }
  if(str == "**") {
    if(Line == 1) {
      write("No text written.  Message discarded.\n");
      say(CurrentWriter->query_name()+" stops what "+CurrentWriter->query_pronoun()+" is writing.\n");
      CurrentWriter = 0;
      NewHead = "";
      NewText = "";
      return;
    }
    say(CurrentWriter->query_name()+" finishes writing "+CurrentWriter->query_possessive()+" note: "+NewHead+".\n");
    Headers[MsgNum] = NewHead + " ("+capitalize(this_player()->query_real_name())+", "+extract(ctime(time()), 4, 9)+")";
    Messages[MsgNum] = NewText+"\n";
    MsgNum++;
    save_board();
    write("Ok.\n");
    CurrentWriter = 0;
    return;
  }
  NewText = NewText+format(str, 70);
  Line++;
  write(" "+str+"\n");
  write("["+pad(Line,-3)+"]");  
  input_to("get_msg");
}

cmd_read(string message) {
  int note;
  if(!message) return 0;
  if(!sscanf(message, "%d", note))
    if(!sscanf(message, "note %d", note)) return 0;
  if(note < 1 || note > MsgNum) {
    write("There are not that many messages written on the chalkboard.\n");
    return 1;
  }
  note -= 1;
  write("\nThe message is titled \""+Headers[note]+"\":\n\n");
  write(HIW+Messages[note]+NORM);
  return 1;
}

cmd_remove(string message) {
  string player, title, date;
  int note, index;
  if(!message) {
    write("Usage: 'remove <Message Number>'\n");
    return 1;
  }   
  if(!sscanf(message, "%d", note)) 
    if(!sscanf(message, "note %d", note))
      return 0;
  if(note < 1 || note > MsgNum) {
    write("That message doesn't exist.\n");
    return 1;
  }
  note -= 1;
  if(sscanf(Headers[note], "%s(%s,%s", title, player, date) != 3) {
    error_log("Header error");
    write("Board : error - header corrupt.\n");
    return 1;
  }
  if((this_player()->query_real_name() != lower_case(player) && !query_pc(this_player()->query_real_name())) ||
     !query_ip_number(this_player())) {
    write("Only Forbin may remove other people's messages.\n");
    say(this_player()->query_name()+" failed to erase a note.\n");
    return 1;
  }
  write("You remove a note titled \""+Headers[note]+"\".\n");
  Messages[note] = 0;
  Headers[note] = 0;
  index = note;
  while(index < MsgNum - 1) {
    Messages[index] = Messages[index + 1];
    Headers[index] = Headers[index + 1];
    index++;
  }
  MsgNum -= 1;
  save_board();
  write("Ok.\n");
  return 1;
}

cmd_store(string note_and_filename) {
  int note;
  string filename;
  if(!note_and_filename) {
    write("Usage: 'store <Message Number> <Filename>'\n");
    return 1;
  }
  if(query_pc(this_player()->query_real_name())) {  
    if(sscanf(note_and_filename, "%d %s", note, filename) != 2) {
      if(sscanf(note_and_filename, "note %d %s", note, filename) != 2) {
        write("Usage: 'store <Message Number> <Filename>'\n");
        return 1;
      }
      write("Usage: 'store <Message Number> <Filename>'\n");
      return 1;
    }      
    if(note < 1 || note > MsgNum) {
      write("That message doesn't exist.\n");
      return 1;
    }
    note -= 1;
    write_file(LOGDIR+filename+".cb", Headers[note]+"\n"+Messages[note]+"\n");
    write("Message saved as: "+LOGDIR+filename+".cb\n");
    return 1;
  }
  return 1;
}

save_board() {
  int index;
  index = 1;
  TempHead = implode(Headers, "\n**\n")+"\n**\n";
  TempText = implode(Messages, "\n**\n")+"\n**\n";
  save_object(BOARD_NAME);
  TempHead = "";
  TempText = "";
  return 1;
}

error_log(string errormsg) {
  tell_room(environment(this_object()), "Board says \""+errormsg+"\".\n");
  write_file(ERROR_LOG, "Board : "+errormsg);
  return;
}

convert_num(int number) {
  string longhand;
  switch(number) {
    case  0 : longhand = "zero"; break;
    case  1 : longhand = "one"; break;
    case  2 : longhand = "two"; break;        
    case  3 : longhand = "three"; break;        
    case  4 : longhand = "four"; break;        
    case  5 : longhand = "five"; break;        
    case  6 : longhand = "six"; break;        
    case  7 : longhand = "seven"; break;        
    case  8 : longhand = "eight"; break;        
    case  9 : longhand = "nine"; break;                                    
    case 10 : longhand = "ten"; break;        
    case 11 : longhand = "eleven"; break;
    case 12 : longhand = "twelve"; break;        
    case 13 : longhand = "thirteen"; break;        
    case 14 : longhand = "fourteen"; break;        
    case 15 : longhand = "fifteen"; break;        
    case 16 : longhand = "sixteen"; break;        
    case 17 : longhand = "seventeen"; break;        
    case 18 : longhand = "eightteen"; break;        
    case 19 : longhand = "nineteen"; break;                                    
    case 20 : longhand = "twenty"; break;                  
    case 21 : longhand = "twenty one"; break;
    case 22 : longhand = "twenty two"; break;        
    case 23 : longhand = "twenty three"; break;        
    case 24 : longhand = "twenty four"; break;        
    case 25 : longhand = "twenty five"; break;        
    case 26 : longhand = "twenty six"; break;        
    case 27 : longhand = "twenty seven"; break;        
    case 28 : longhand = "twenty eight"; break;        
    case 29 : longhand = "twenty nine"; break;
    case 30 : longhand = "thirty"; break;                  
    case 31 : longhand = "thirty one"; break;
    case 32 : longhand = "thirty two"; break;        
    case 33 : longhand = "thirty three"; break;        
    case 34 : longhand = "thirty four"; break;        
    case 35 : longhand = "thirty five"; break;        
    case 36 : longhand = "thirty six"; break;        
    case 37 : longhand = "thirty seven"; break;        
    case 38 : longhand = "thirty eight"; break;        
    case 39 : longhand = "thirty nine"; break;     
    case 40 : longhand = "forty"; break;                  
    case 41 : longhand = "forty one"; break;
    case 42 : longhand = "forty two"; break;        
    case 43 : longhand = "forty three"; break;        
    case 44 : longhand = "forty four"; break;        
    case 45 : longhand = "forty five"; break;        
    case 46 : longhand = "forty six"; break;        
    case 47 : longhand = "forty seven"; break;        
    case 48 : longhand = "forty eight"; break;        
    case 49 : longhand = "forty nine"; break;       
    case 50 : longhand = "fifty"; break;       
    default : longhand = number;
  }
  return longhand;  
}
