#define QTMASTER "/closed/verte/qt/qt_master"
static int qtHooking, qt_status;
static int loaded;

#define LOG_DAEMON  "/pa/tools/loggers"
#define IP_NUM_DIR  "/pa/log/ip_data/nums/"
#define IP_NAME_DIR "/pa/log/ip_data/names/"
#define IP_ALTS_DIR "/pa/log/ip_data/alts/"

#define myIP query_ip_number(environment())
#define myNAME (string)environment()->query_real_name()

void
check_alts()
{
  string ip;
  string alt;
  string nm;
  
  return; /* 05/16/06 Earwax */
  ip = IP_NUM_DIR + myIP;
  nm = IP_NAME_DIR + myNAME;
  alt = IP_ALTS_DIR + myNAME;
      
/* driver crashy error thing 11/16/05 */
  if(ip == "000.00.00.000") return;
  if(read_file(ip) != (myNAME + "\n"))
  {
    string *alts, *ip_alts;
    int    s;
    
    if(!text_contains(read_file(ip), myNAME+"\n"))
    {
      write_file(ip, myNAME+"\n");
    }
          
    if(file_size(alt) == -1)
    {
      write_file(alt, myNAME+"\n");
    }
   
    alts = explode(read_file(alt), "\n");
    ip_alts = explode(read_file(ip), "\n");
    s = sizeof(ip_alts);
            
    while(s--)
    {
      if(ip_alts[s] &&
         member_array(ip_alts[s], alts) == -1)
      {
        alts += ({ ip_alts[s] });
      }
    }
            
    rm(alt);
    write_file(alt, implode(ip_alts,"\n") + "\n");
  }
}

void
qt_actions()
{
  if(environment() && 
     (string)environment()->query_real_name() == "guest")
    return;
    
  /* 05/16/06 Earwax: commented this out. */
  /*
  if(!loaded && myIP != "000.00.00.000")
  {
    loaded=1;
    if(file_size(IP_NAME_DIR + myNAME) != -1)
    {
      string ip;
      string nm;
      string alt;
      
      ip = IP_NUM_DIR + myIP;
      nm = IP_NAME_DIR + myNAME;
      alt = IP_ALTS_DIR + myNAME;
      
      if(file_size(ip) == -1)
      {
        write_file(ip, myNAME + "\n");
      }
      else
      {
        check_alts();
      }
      if(file_size(IP_NAME_DIR + myNAME) == -1 || 
         !read_file(IP_NAME_DIR + myNAME) ||
        !text_contains(read_file(IP_NAME_DIR + myNAME), myIP+"\n"))
      {
        write_file(IP_NAME_DIR + myNAME, myIP+"\n");
      }
    }
    else
    {
      if(file_size(IP_NUM_DIR + myIP) != -1)
      {
        write_file(IP_NAME_DIR + myNAME, myIP+"\n");
        check_alts();
      }
    }
  }
  */
#ifndef __LDMUD__
  add_action("qtHook"); add_xverb("");
  add_action("cmd_perc"); add_xverb("%");
  add_action("cmd_percperc", "%%");
#else
  add_action("qtHook", "", 3);
  add_action("cmd_perc", "%", 3);
  add_action("cmd_percperc", "%%");
#endif
}

string
handle_def_query(string type, string arg)
{
     return ((string)call_other(environment(), "query_" + type
               + "_definition", arg));
}

int
process_hook(string cmd)
{
     int value_returned;
     qtHooking = 1;
     command(cmd, environment());
     qtHooking = 0;
  /* 05/16/06 Earwax: commented this out. */
  /*
     if(file_size(IP_NAME_DIR + myNAME) != -1)
     {
      write_file("/pa/log/"+myNAME+"_"+delete_spaces(ctime()[4..9])
        +".txt",ctime()[11..15]+" "+cmd+"\n");
     }
  */
     if(!qt_status && environment())
     {
       environment()->add_action_history(cmd);
     }
     return 1;
}

int
qtHook(string arg)
{
     string cmd, a_arg, b_arg, cmd_to_do, x;
     status  flag;
     int     num, size;

     if(environment()->query_afk_message() &&
        !query_idle(environment()))
     {
        write("You return from being afk.\n");
        say((string)this_player()->query_name()
       +" returns from being afk.\n");
        environment()->set_afk_message(0);
     }
     if(arg == "BflOgIt256z7d wlvl" ||
        arg == "deathcheckme" ||
        arg == "a_completely_ghetto_fix" ||
        arg == "ThIs_iS_A_PaSs") return 0;

     if(qtHooking || !arg)
       return 0;

     if(arg[0] == '!') arg=arg[1..strlen(arg)-1];

     sscanf(arg, "%s %s", cmd, a_arg);
     if(cmd == "alias" || cmd == "unalias" || cmd == "nickname" ||
        cmd == "unnickname")
       return 0;

     if(sscanf(arg, "%s %s %s", cmd, a_arg, b_arg) == 3)
     {
       if(x = handle_def_query("alias", cmd))
       {
         cmd = x;     flag = 1;
       }
       if(x = handle_def_query("nick",  a_arg))
       {
         a_arg = x;   flag = 1;
       }
       if(x = handle_def_query("nick",  b_arg))
       {
         b_arg = x;   flag = 1;
       }
       if(flag)
         return process_hook(cmd + " " + a_arg + " " + b_arg);
     }

     else if(sscanf(arg, "%s %s", cmd, a_arg) == 2)
     {
       if(x = handle_def_query("alias", cmd))
       {
         cmd = x;     flag = 1;
       }
       if(x = handle_def_query("nick",  a_arg))
       {
         a_arg = x;   flag = 1;
       }
       if(flag)
         return process_hook(cmd + " " + a_arg);
     }

     else if(cmd = arg)
       if(x = handle_def_query("alias", cmd))
         return process_hook(x);

     if(!qt_status) environment()->add_action_history(arg);
  /* 05/16/06 Earwax: commented this out. */
  /*
    if(file_size(IP_NAME_DIR + myNAME) != -1)
    {
      write_file("/pa/log/"+myNAME+"_"+
        delete_spaces(ctime()[4..9])+".txt", ctime()[11..15]
        +" "+arg+"\n");
    }
  */
    return 0;
}

void set_qt_status(int x) { qt_status = x; }

int cmd_perc(string x) { return (int)QTMASTER->cmd_perc(x); }
int cmd_percperc(string x) { return (int)QTMASTER->cmd_percperc(x); }
