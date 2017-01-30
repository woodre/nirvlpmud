inherit "/players/dune/closed/guild/rooms/room";
#include "../DEFS.h"
#include DEFS_COLORPAD

#define EMOTE_MASTER_NAME   "emoteMaster"
#define STD_EMOTE_NAME      "stdEmote"
#define STD_EMOTE           LIB_EMOTES+STD_EMOTE_NAME+".c"
#define EMOTE_LIST_FILE     LIB_EMOTES+"emotes.txt"


string emoteName, myMsgU, myMsgD, roomMsgU, roomMsgD, tellMsg, farMsg, owner;


init()
{
  add_action("register",      "register");
add_action("rules",      "rules");
  add_action("new_emote",     "emote_new");
  add_action("load_emote",    "emote_load");
  add_action("view_emote",    "emote_view");
  add_action("list_emote",    "emote_list");
  add_action("msg_help",      "msg_help");
  add_action("emote_help",    "i_am_lost");
  add_action("set_my_msgU",   "set_my_msg_undir");
  add_action("set_my_msgD",   "set_my_msg_dir");
  add_action("set_room_msgU", "set_room_msg_undir");
  add_action("set_room_msgD", "set_room_msg_dir");
  add_action("set_tell_msg",  "set_tell_msg");
  add_action("set_far_msg",   "set_far_msg");
  add_action("save_emote",    "emote_save");
  add_action("close_emote",   "emote_close");

  if (IPTP && call_other(OFFICED, "checkStone", TP, "diamond"))
    add_action("erase_emote",   "emote_erase");

  ::init();
}


reset(arg)
{
  if (!arg)
  {
    set_light(1);
    short_desc=FUNKYNAME+" Emoteon";
    long_desc=
"     The Emoteon is small cockpit mounted atop thick metal frame\n"+
"supports. It is almost completely obscured from view by the myriad\n"+
"of wires and flat-panel monitor displays surrounding it.\n"+
"Here you may create new emotes, or view those others have made.\n"+
"Please type 'register' to list the services available to you.\n";

    items=({
"monitors", "The monitors display holo-enactments of various emotes",
"displays", "The displays show holo-enactments of various emotes",
"cockpit",  "The Emoteon cockpit sits high atop the pile of wires",
"supports", "The thick tithaneum supports envelop the cockpit",
"wires",    "Glowing wires of all shapes and sizes mesh around the cockpit"
    });

    dest_dir=({
ROOMDIR+"/archives.c", "up",
    });
  }
}


status register()
{
  string msg;
  if (!TP || !environment(TP)) return 1;
  msg = 
"Services available:\n" +
"\n" +
"rules.....................Guidelines for creating emotes.\n"+
"emote_new <emoteName>.....Sets up a new emote for you to work on.\n"+
"emote_load <emoteName>....Loads a pre-existing emote to modify.\n"+
"emote_list................Views all guild emotes.\n"+
"emote_view................Views all emote message settings.\n"+
"msg_help..................Shows you how to set up an emote msg.\n"+
"i_am_lost.................Shows an example for the confused.\n"+
"set_my_msg_undir <msg>....Sets the message directed to you.\n"+
"                          (for a general non-directed emote)\n"+
"set_my_msg_dir <msg>......Sets the message directed to you.\n"+
"                          (for an emote directed at a player)\n"+
"set_room_msg_undir <msg>..Sets the message directed to the room.\n"+
"                          (for a general non-directed emote)\n"+
"set_room_msg_dir <msg>....Sets the message directed to the room.\n"+
"                          (for an emote directed at a player)\n"+
"set_tell_msg <msg>........Sets the message your emote target sees.\n"+
"set_far_msg <msg>.........Sets the message your emote target sees.\n"+
"                          (allows you to use a custom far emote msg,\n"+
"                           set_tell_msg is far emote msg by default)\n"+
"emote_save................Saves currently loaded or created emote.\n"+
"emote_close...............Closes currently loaded or created emote.\n"+
"                          (if you close before saving, bye bye emote)\n";

  if (IPTP && call_other(OFFICED, "checkStone", TP, "diamond"))
  {
    msg += 
"emote_erase...............Permanently erases an emote.\n";
  }

  write(msg +"\n");
  return 1;
}


status emote_help()
{
  string msg;
  msg = 
"Emoton: So you are completely lost? Well, creating an emote is simple.\n"+
"        First, you need to either create or load an emote into the\n"+
"        pattern buffer. This allows you to work on it. You cannot set\n"+
"        emote messages if there is no emote to set them on. Once you\n"+
"        are finished setting the messages, you need to save your emote.\n"+
"        Close your emote if you wish to clean up after yourself, or\n"+
"        if you wish to work on another emote. Follow this procedure:\n"+
"\n"+
"1) emote_new gotcha   Sets up a new emote called 'gotcha' to work on.\n"+
"                      (New emotes will not be created until saved.)\n"+
"\n"+
"2) emote_view         Shows the message settings for the emote.\n"+
"                      (We just created 'gotcha' so everything is 0\n"+
"\n"+
"3) (now use the set message commands to fill in the 'gotcha' emote)\n"+
"   (type 'msg_help' for a guide on how to create an emote message)\n"+
"\n"+
"4) emote_save         Saves the filled-in 'gotcha' emote.\n"+
"                      (Because this is a new emote, the emote will be\n"+
"                      created upon saving. So, if you close 'gotcha'\n"+
"                      without saving it, bye bye emote.\n";
  write(msg);
  return 1;
}


status msg_help()
{
  string msg;
  msg = 
"An emote message consists of ordinary text and any optional keywords.\n"+
"Keywords let you insert your name and/or your target's name into your\n"+
"emote message. They also allow you to add color. The following is a\n"+
"list of all keywords you may use in your message. See example below.\n"+
"\nCOLORING KEYWORDS\n"+
color_help()+
"\nNAMING KEYWORDS\n"+
"%SRC%      your name\n"+
"%TRG%      target's name\n"+
"%SRCPOS%   you possessive    (its/his/her)\n"+
"%TRGPOS%   target possessive (its/his/her)\n"+
"%SRCOBJ%   you objective     (it/him/her)\n"+
"%TRGOBJ%   target objective  (it/him/her)\n"+
"\n......example: %SRC% punches %TRG% right in the $HR$kisser!\n";
  write(msg);
  return 1;
}

status rules()
{
string msg;
msg =
"Emoteon Rules:\n"+
"\n"+
"Do not create an emote that has the same name as a current game emote.\n"+
"Use ckiss, cyberkiss, ninjakiss, etc...\n";
write(msg);
return 1;
}


status validFileName(string str)
{
  string *strArray;
  if (!str) return 0;
  strArray = explode(str, "/");
  if (sizeof(strArray) > 1      ||
      extract(str, 0, 0) == "/" ||
      extract(str, strlen(str)-1) == "/")
  {
    return 0;
  }
  strArray = explode(str, " ");
  if (sizeof(strArray) > 1      ||
      extract(str, 0, 0) == " " ||
      extract(str, strlen(str)-1) == " ")
  {
    return 0;
  }
  return 1;
}


status new_emote(string str)
{
  if (emoteName)
  {
    write("Emotron: You must first close emote "+emoteName+".\n");
    return 1;
  }
  if (!validFileName(str))
  {
    write("Emotron: You must specify a valid emote name.\n"+
          "         The name must be only one-word long,\n"+
          "         and cannot contain slashes '/'.\n");
    return 1;
  }
  if (file_size(LIB_EMOTES+str+".c") >= 0)
  {
    write("A guild emote of that name already exists.\n");
    return 1;
  }
  emoteName = str;
  write("Emoton: Now creating emote "+str+".\n"+
        "        Remember to save your emote when finished.\n");
  return 1;
}


status load_emote(string str)
{
  string emoteData;
  if (emoteName)
  {
    write("Emotron: You must first close emote "+emoteName+".\n");
    return 1;
  }
  if (!str)
  {
    write("Emotron: No emote specified.\n");
    return 1;
  }
  if (file_size(LIB_EMOTES+str+".c") < 0)
  {
    write("Emotron: No such guild emote exists.\n");
    return 1;
  }
  emoteData = EMOTESAVEDIR +"/"+ str;
  if (!restore_object(emoteData))
  {
    write("Emotron: Emote load error.\n");
  }
  write("Emotron: Emote "+str+" loaded.\n");
  return 1;
}


status set_my_msgU(string str)
{
  string filteredStr;
  if (!emoteName)
  {
    write("Emotron: No emote has been loaded or created.\n");
    return 1;
  }
  if (!str)
  {
    write("Emotron: No message specified.\n");
    return 1;
  }
  myMsgU = str;
  filteredStr = (string)call_other(VERTE_COLOR, "filter_msg", str);
  write("Emotron: Personal emote message set (undirected).\n"+
        "( "+filteredStr+" )\n");
  return 1;
}


status set_my_msgD(string str)
{
  string filteredStr;
  if (!emoteName)
  {
    write("Emotron: No emote has been loaded or created.\n");
    return 1;
  }
  if (!str)
  {
    write("Emotron: No message specified.\n");
    return 1;
  }
  myMsgD = str;
  filteredStr = (string)call_other(VERTE_COLOR, "filter_msg", str);
  write("Emotron: Personal emote message set (directed).\n"+
        "( "+filteredStr+" )\n");
  return 1;
}


status set_room_msgU(string str)
{
  string filteredStr;
  if (!emoteName)
  {
    write("Emotron: No emote has been loaded or created.\n");
    return 1;
  }
  if (!str)
  {
    write("Emotron: No message specified.\n");
    return 1;
  }
  roomMsgU = str;
  filteredStr = (string)call_other(VERTE_COLOR, "filter_msg", str);
  write("Emotron: Room emote message set (undirected).\n"+
        "( "+filteredStr+" )\n");
  return 1;
}


status set_room_msgD(string str)
{
  string filteredStr;
  if (!emoteName)
  {
    write("Emotron: No emote has been loaded or created.\n");
    return 1;
  }
  if (!str)
  {
    write("Emotron: No message specified.\n");
    return 1;
  }
  roomMsgD = str;
  filteredStr = (string)call_other(VERTE_COLOR, "filter_msg", str);
  write("Emotron: Room emote message set (directed).\n"+
        "( "+filteredStr+" )\n");
  return 1;
}


status set_tell_msg(string str)
{
  string filteredStr;
  if (!emoteName)
  {
    write("Emotron: No emote has been loaded or created.\n");
    return 1;
  }
  if (!str)
  {
    write("Emotron: No message specified.\n");
    return 1;
  }
  tellMsg = str;
  filteredStr = (string)call_other(VERTE_COLOR, "filter_msg", str);
  write("Emotron: Tell emote message set.\n"+
        "( "+filteredStr+" )\n");
  return 1;
}


status set_far_msg(string str)
{
  string filteredStr;
  if (!emoteName)
  {
    write("Emotron: No emote has been loaded or created.\n");
    return 1;
  }
  if (!str)
  {
    write("Emotron: No message specified.\n");
    return 1;
  }
  farMsg = str;
  filteredStr = (string)call_other(VERTE_COLOR, "filter_msg", str);
  write("Emotron: Far tell emote message set.\n"+
        "( "+filteredStr+" )\n");
  return 1;
}


status save_emote()
{
  int i;
  object *people;
  object ob;
  string emoteData, emoteCommand, myName;

  if (!emoteName)
  {
    write("Emotron: No emote has been loaded or created.\n");
    return 1;
  }

  emoteCommand = LIB_EMOTES+emoteName+".c";

  /* create emote command if it does not exist */
  if (file_size(emoteCommand) < 0)
  {
    /* we need to create the command file */
    write_file(emoteCommand, read_file(STD_EMOTE));
    call_other(ACTIOND, "rehash");
    people = users();
    for (i=0; i < sizeof(people); i++)
    {
      ob = people[i];
      if (IPOB) move_object(IPOB, ob);
    }
  }

  myName = (string)TP->query_real_name();

  /* save emote data */
  emoteData = EMOTESAVEDIR +"/"+ emoteName;
  call_other(emoteCommand, "set_emote_name",          emoteName);
  call_other(emoteCommand, "set_my_msg_undirected",   myMsgU);
  call_other(emoteCommand, "set_my_msg_directed",     myMsgD);
  call_other(emoteCommand, "set_room_msg_undirected", roomMsgU);
  call_other(emoteCommand, "set_room_msg_directed",   roomMsgD);
  call_other(emoteCommand, "set_tell_msg",            tellMsg);
  call_other(emoteCommand, "set_far_msg",             farMsg);
  call_other(emoteCommand, "set_owner",               myName);
  call_other(emoteCommand, "saveData",                emoteData);

  write("Emotron: Emote "+emoteName+" saved.\n");
  return 1;
}


status close_emote()
{
  if (!emoteName)
  {
    write("Emotron: No emote has been loaded or created.\n");
    return 1;
  }
  write("Emotron: Closing emote "+emoteName+".\n");
  emoteName = 0;
  myMsgU    = 0;
  myMsgD    = 0;
  roomMsgU  = 0;
  roomMsgD  = 0;
  tellMsg   = 0;
  farMsg    = 0;
  return 1;
}


status view_emote()
{
  string msg;
  if (!emoteName)
  {
    write("Emotron: No emote has been loaded or created.\n");
    return 1;
  }
  msg =  "Emotron: Emote "+emoteName+" message settings...\n";
  msg += "Name of last modifier: "+owner+"\n"+LINE+
"set_my_msg_undir      "+myMsgU+"\n"+
"set_my_msg_dir        "+myMsgD+"\n"+
"set_room_msg_undir    "+roomMsgU+"\n"+
"set_room_msg_dir      "+roomMsgD+"\n"+
"set_tell_msg          "+tellMsg+"\n"+
"set_far_msg           "+farMsg+"\n";
  msg += LINE;
  write(msg);
  return 1;
}


status list_emote()
{
  string emoteDir, ename, emoteList;
  string *files, *fileName;
  int i;
  emoteDir = LIB_EMOTES;
  emoteDir = extract(emoteDir, 0, strlen(emoteDir)-2);
  write("Emotron: Listing all guild emotes...\n");
  files = get_dir(emoteDir + "/*");

  emoteList = "";
  if (file_size(EMOTE_LIST_FILE) >= 0) rm(EMOTE_LIST_FILE);

  for (i=0; i < sizeof(files); i++)
  {
    if (files[i] != "." && files[i] != "..")
    {
      fileName=explode(files[i], ".");
      if (sizeof(fileName) == 2)
      {
        /* make sure we're dealing with .c files */
        if (fileName[1]=="c"                 &&
            fileName[0] != EMOTE_MASTER_NAME &&
            fileName[0] != STD_EMOTE_NAME)
        {
          ename = fileName[0];
          emoteList += ename+"\n";
        }
      }
    }
  }

  write_file(EMOTE_LIST_FILE, emoteList);
  call_other(MORED, "more_file", EMOTE_LIST_FILE);

  return 1;
}


status erase_emote(string str)
{
  if (!str)
  {
    write("Emotron: No emote specified.\n");
    return 1;
  }
  if (file_size(LIB_EMOTES+str+".c") < 0)
  {
    write("Emotron: No such guild emote exists.\n");
    return 1;
  }
  rm(LIB_EMOTES+str+".c");
  rm("/"+EMOTESAVEDIR+"/"+str+".o");
  write("Emotron: Emote "+str+" erased.\n");
  return 1;
}
