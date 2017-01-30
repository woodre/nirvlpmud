#include <kernel.h>
#include <server.h>
#include <fingerd.h>
#include <is_wizard.h>
#include <prop/player.h>
#include <erq.h>

inherit ACCESS;
inherit "basic/daemon";
inherit "basic/create";
inherit "basic/path";
inherit "basic/name";
inherit "basic/confirm";

void create() {
  add_command("rehash","rehash");
  add_command("access","access");
  add_command("domain","domain");
  add_command("banish","banish");
  add_command("unbanish","unbanish");
  add_command("shell", "shell");  // Coogan, 25-Jan-2002
  set_privilege(1);
}

private nosave object erq_user;

private void erq_execute_callback(mixed *data, mixed size) {
  string fn;
  if (!pointerp(data) || !sizeof(data)) {
    erq_user &&
      tell_object(erq_user, "Something went wrong with the erq while "
                            "executing the command.\n");
    erq_user = 0;
    return;
  }
  if (!erq_user)
    return;
  switch (data[0]) {
  case ERQ_OK:
    tell_object(erq_user, "Erq command executed and returned an exit "
                          "value of " + data[1] + ".\n");
    break;
  case ERQ_E_ARGLENGTH:
    tell_object(erq_user, "Command too long.\n");
    break;
  case ERQ_E_ARGFORMAT:
    tell_object(erq_user, "Illegal argument given (contains '\', "
                          "'..' or starts with '/'.\n");
    break;
  case ERQ_E_ARGNUMBER:
    tell_object(erq_user, "Too much arguments (>= 96).\n");
    break;
  case ERQ_E_ILLEGAL:
    tell_object(erq_user, "Command from outside ERQ_DIR requested.\n");
    break;
  case ERQ_E_PATHLEN:
    tell_object(erq_user, "Commandpath too long.\n");
    break;
  case ERQ_E_FORKFAIL:
    tell_object(erq_user, "Command could not be forked, errno " +
                          data[1] + ".\n");
    break;
  case ERQ_SIGNALED:
    tell_object(erq_user, "Command terminated the signal " + data[1] + ".\n");
    break;
  case ERQ_E_NOTFOUND:
    tell_object(erq_user, "No process found to wait() for.\n");
    break;
  case ERQ_E_UNKNOWN:
    tell_object(erq_user, "Unknown exit condition from wait().\n");
    break;
  }
  fn = "/open/tmp/"+erq_user->query_real_name()+".erq";
  if (file_size(fn) > 0)
    tell_object(erq_user,
                "Please have a look at " + fn + ".\n");
  erq_user = 0;
}

int shell(string arg) {
  string fn;
  if (!check_privilege(1))
    return notify_fail("Only members of the technical admin can use this"
                       " command.\n"), 0;
  if (!arg)
    return
      notify_fail("Usage: shell <command>\n"
                  "The command <command> will be evaluated in a shell.\n"
                  "All used paths must either be absolute or relative to "
                  "the erqdir of the driver.\n"), 0;
  write("Executing: " + arg + "\n");
  erq_user = this_player();
  fn = "/home/tubmud/mudlib/open/tmp/" + this_player()->query_real_name() +
       ".erq";
  rm(fn[19..]);
  send_erq(ERQ_EXECUTE,
           "execute_shell_command " + fn + " " + arg,
           #'erq_execute_callback);
  return 1;
}

void write_error(string error) {
  if (!error)
    write("Ok.\n");
  else
    write("Error: " + error +".\n");
}

void write_access_tree(mapping tree,string path);

#define REHASHER "etc/rehash"

int rehash(string arg) {
  object rehasher,current_owner;

  // added following check   Alfe 1997-Feb-08
  if (!is_wizard(this_player(),IW_TOOLUSER))
    raise_error("Illegal daemon added for player\n");

  if (arg)
    return notify_fail("Usage: rehash\n"), 0;
  if (!check_privilege(1))
    return notify_fail("Only members of the technical admin can use this"
                       " command.\n"), 0;
  if (rehasher=find_object(REHASHER)) {  // rehasher already loaded?
    if ((current_owner=environment(rehasher)) &&
        interactive(current_owner) &&
        current_owner != this_player())  // does an interactive one carry it?
      if (query_input_pending(current_owner)==rehasher)  // is current_owner
                                                         // using the rehasher?
        return notify_fail("Sorry, "+current_owner->query_vis_name()+
                           " is currently rehashing.\n"), 0;
      else  // current_owner does not use the rehashing-command right now.
        tell_object(current_owner,"The rehash command is leaving you.\n");
  }
  else  // not yet loaded.
    rehasher = load_object(REHASHER);
  move_object(rehasher,this_player());
  return rehasher->rehash_man_pages(0);
}

int banish(string arg) {
  mixed h;

  // added following check   Alfe 1997-Feb-08
  if (!is_wizard(this_player(),IW_TOOLUSER))
    raise_error("Illegal daemon added for player\n");

  if (!arg)
    return notify_fail("Usage: banish <name_to_banish>\n"), 0;
  if (!valid_name(arg))
    return notify_fail("No player could use this name anyway.\n"), 0;
  arg = to_real_name(arg);
  if (h=SE_BANISH->query_banished(arg))
    return notify_fail("This name is already banished by "+to_vis_name(h)+".\n"
                       "Use 'unbanish "+arg+"' to remove the banishment.\n"
                       "(This will only work if your privilege is"
                       " sufficient!)\n"), 0;
  if (h=FINGERD->load_player(arg))  // player exists!
    if (get_privilege(this_player()) == 1) {  // admin is acting
      write("Warning!\n"+
            h->query_vis_name()+" is an existing player. Do you really want"
            " to banish "+h->query_objective()+"?\n"
            "Banish (y/n)? ");
      confirm(lambda(0,({ (#'write_error),
                          ({ (#'call_other),
                             SE_BANISH,
                             "banish",
                             arg,
                             this_player()->query_real_name() }) })),
              "Not banished.\n");
    }
    else  // non-admin is acting
      return notify_fail("Sorry, this name is already used by a player.\n"), 0;
  else  // player does not exist
    write_error(SE_BANISH->banish(arg,this_player()->query_real_name()));
  return 1;
}

int unbanish(string arg) {

  // added following check   Alfe 1997-Feb-08
  if (!is_wizard(this_player(),IW_TOOLUSER))
    raise_error("Illegal daemon added for player\n");

  if (!arg)
    return notify_fail("Usage: unbanish <banished_name>\n"), 0;
  write_error(SE_BANISH->unbanish(arg));
  return 1;
}

static int access(string arg) {
  mixed *args;
  mixed error;
  int i;

  // added following check   Alfe 1997-Feb-08
  if (!is_wizard(this_player(),IW_TOOLUSER))
    raise_error("Illegal daemon added for player\n");

  if (!arg)
    return notify_fail("Usage: access define <new_priv>\n"
                       "       access undefine <priv>\n"
                       "       access open <priv1> for <priv2>\n"
                       "       access close <priv1> for <priv2>\n"
                       "       access +wiz <wizard>\n"
                       "       access -wiz <wizard>\n"
                       "       access +admin { <wizard> }\n"
                       "       access -admin { <wizard> }\n"
                       "       access link [-read] <priv> to <dir>\n"
                       "       access unlink [-read] <dir>\n"
                       "       access show <priv>\n"
                       "       access list [-read] <dir>\n"
                       "       access history\n"), 0;
  args = explode(arg," ")-({""});
  arg = args && args[0];
  args = args[1..];
  switch (arg) {
  case "define":
    if (sizeof(args) != 1)
      return notify_fail("Usage: access define <priv>\n"), 0;
    write_error(SECURITY->define_privilege(args[0]));
    return 1;
  case "undefine":
    if (sizeof(args) != 1)
      return notify_fail("Usage: access undefine <priv>\n"), 0;
    write_error(SECURITY->undefine_privilege(args[0]));
    return 1;
  case "open":
    if (sizeof(args)!=3 || args[1]!="for")
      return notify_fail("Usage: access open <priv1> for <priv2>\n"), 0;
    write_error(SECURITY->extend_access(args[0],args[2]));
    return 1;
  case "close":
    if (sizeof(args)!=3 || args[1]!="for")
      notify_fail("Usage: access close <priv1> for <priv2>\n"), 0;
    write_error(SECURITY->restrict_access(args[0],args[2]));
    return 1;
  case "makewiz":
  case "+wiz":
    if (sizeof(args) != 1)
      return notify_fail("Usage: access +wiz <wiz>\n"), 0;
    args[0] = to_real_name(args[0]);
    error = SECURITY->create_wizard(args[0]);
    if (error) {
      write_error(error);
      return 1;
    }
    unguarded(1,#'mkdir,"/players/"+args[0]);
    SECURITY->set_protection("/players/"+args[0],1,args[0]+":");
    return 1;
  case "zapwiz":
  case "-wiz":
    if (sizeof(args) != 1)
      return notify_fail("Usage: access -wiz <wiz>\n"), 0;
    args[0] = to_real_name(args[0]);
    if (!SECURITY->query_is_wizard(args[0])) {
      write("No such wizard.\n");
      return 1;
    }
    error = SECURITY->set_protection("/players/"+args[0],1,-1);
    if (error) {
      write_error(error);
      return 1;
    }
    error = SECURITY->delete_wizard(args[0]);
    return 1;
  case "addadmin":
  case "+admin":
    for (i=0; i<sizeof(args); i++) {
      error = SECURITY->create_admin(to_real_name(args[i]));
      if (error)
        write_error(error);
    }
    return 1;
  case "deladmin":
  case "-admin":
    for (i=0; i<sizeof(args); i++) {
      error = SECURITY->delete_admin(to_real_name(args[i]));
      if (error)
        write_error(error);
    }
    return 1;
  case "link":
    if (sizeof(args)==3 && args[1]=="to") {
      args[2] = normalize_path(args[2],this_player());
      switch (args[0]) {
      case "0":
        args[0] = 0;
        break;
      case "1":
        args[0] = 1;
        break;
      }
      write_error(SECURITY->set_protection(args[2],1,args[0]));
      return 1;
    }
    if (sizeof(args)==4 && args[2]=="to" && args[0]=="-read") {
      args[3] = normalize_path(args[3],this_player());
      switch (args[1]) {
      case "0":
        args[1] = 0;
        break;
      case "1":
        args[1] = 1;
        break;
      }
      write_error(SECURITY->set_protection(args[3],0,args[1]));
      return 1;
    }
    return notify_fail("Usage: access link <priv> to <dir>\n"
                       "       access link -read <priv> to <dir>\n"), 0;
  case "unlink":
    if (sizeof(args) == 1) {
      args[0] = normalize_path(args[0],this_player());
      write_error(SECURITY->set_protection(args[0],1,-1));
      return 1;
    }
    if (sizeof(args)==2 && args[0]=="-read") {
      args[1] = normalize_path(args[1],this_player());
      write_error(SECURITY->set_protection(args[1],0,-1));
      return 1;
    }
    return notify_fail("Usage: access unlink <dir>\n"
                       "       access unlink -read <dir>\n"), 0;
  case "show":
    if (sizeof(args) == 1) {
      int n;
      mapping p;
      string *s;
      n = member(args[0], ':');
      if (n < 0) {
        p = SECURITY->query_privilege_list(args[0]);
        if (!p) {
          write("There is no such privilege.\n");
          return 1;
        }
        s = sort_array(m_indices(p),#'>);
        for (i=0; i<sizeof(s); i++) {
          if (sizeof(p[s[i]]))
            write("["+s[i]+"] -> "+implode(p[s[i]],", ")+"\n");
          else
            write("["+s[i]+"]\n");
        }
        return 1;
      }
      else {
        p = SECURITY->query_privilege_list(args[0][0..n-1]);
        if (!p || !member(p,args[0])) {
          write("There is no such privilege.\n");
          return 1;
        }
        if (sizeof(p[args[0]]))
          write("["+args[0]+"] -> "+implode(p[args[0]],", ")+"\n");
        else
          write("["+args[0]+"]\n");
        return 1;
      }
    }
    return notify_fail("Usage: access show <priv>\n"), 0;
  case "list":
    if (sizeof(args)==1 || (sizeof(args)==2 && args[0]=="-read")) {
      mapping tree;
      int rw;
      rw = 1;
      if (sizeof(args) == 2) {
        args[0] = args[1];
        rw = 0;
      }
      args[0] = normalize_path(args[0],this_player());
      if (args[0] == "/")
        args[0] = "";
      tree = SECURITY->query_access_tree(args[0],rw);
      write_access_tree(tree,args[0]);
      return 1;
    }
    return notify_fail("Usage: access list <dir>\n"
                       "       access list -read <dir>\n"), 0;
  case "history":
    if (!sizeof(args)) {
      int j;
      string *history;
      mixed *output;
      history = SECURITY->query_access_history();
      output = ({ ({ "USER" }),
                  ({ "CALLER" }),
                  ({ "OFFENDING OBJECT" }),
                  ({ "PRIVILEGE" }) });
      for (j=0; j<sizeof(history); j+=4) {
        output[0] += ({ history[j] });
        output[1] += ({ history[j+1] });
        output[2] += ({ history[j+2] });
        output[3] += ({ history[j+3] });
      }
      printf("%-78.4#s\n",
             implode(output[0]+output[1]+output[2]+output[3],"\n")+"\n");
      return 1;
    }
    return notify_fail("Usage: access history\n"), 0;
  default:
    return notify_fail("Error.\n"), 0;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 27-Mar-2011
}

string *access_list;
int access_write_pos;

void write_access_subtree(mapping tree,string path) {
  string *keys;
  int i;
  keys = m_indices(tree);
  for (i=0; i<sizeof(keys); i++) {
    mixed priv;
    mapping subtree;
    m_contains(&priv,&subtree,tree,keys[i]);
    if (priv != -1) {
      if (access_write_pos >= sizeof(access_list))
        access_list += allocate(sizeof(access_list));
      access_list[access_write_pos++] = path + "/" + keys[i] + "  " + priv;
    }
    if (subtree)
      write_access_subtree(subtree,path + "/" + keys[i]);
  }
}

void write_access_tree(mapping tree,string path) {
  int i;
  path = implode(explode(path,"/")[0..<2],"/");
  access_list = allocate(10);
  access_write_pos = 0;
  write_access_subtree(tree,path);
  access_list = sort_array(access_list[0..access_write_pos-1],#'>);
  for (i=0; i<sizeof(access_list); i++) {
#if 0  // Alfe 1998-Oct-26
    write
#else
      this_player()->tell_more
#endif
      (access_list[i] + "\n");
  }
}

static int domain(string arg) {
  string *args;
  mixed temp, temp2;
  int i;
  string err;

  // added following check   Alfe 1997-Feb-08
  if (!is_wizard(this_player(),IW_TOOLUSER))
    raise_error("Illegal daemon added for player\n");

  if (!arg)
    return notify_fail("Usage: domain show <domain>\n"
                       "       domain list [<wizard>]\n"
                       "       domain create <new_domain>\n"
                       "       domain delete <domain>\n"
                       "       domain add [-lord] <wizard> to <domain>\n"
                       "       domain remove <wizard> from <domain>\n"), 0;
  args = explode(arg," ")-({""});
  arg = args && args[0];
  args = args[1..];
  switch (arg) {
  case "create":
    if (sizeof(args) != 1)
      return notify_fail("Usage: domain create <new_domain>\n"), 0;
    args[0] = lower_case(args[0]);
    if (temp=SE_BANISH->query_banished(args[0])) {
      message("This name is already banished by " + to_vis_name(temp) + "."
              " Please choose a different name.\n");
      return 1;
    }
    if (FINGERD->file_time_of(args[0])) {
      message("This name is already used by a player. Please choose a"
              " different name.\n");
      return 1;
    }
    err = (SE_BANISH->banish(args[0],this_player()->query_real_name()) ||
           SECURITY->create_domain(args[0]));
    if (err) {
      write_error(err);
      return 1;
    }
    write("Domain created.\n");
    mkdir("/domains/"+args[0]);
    write("Created /domains/"+args[0]+"\n"
          "Setting protection level of /domains/"+args[0]+"\n");
    err = SECURITY->set_protection("/domains/"+args[0],1,
                                   capitalize(args[0]+":"));
    if (err) {
      write_error(err);
      return 1;
    }
    temp = "/domains/"+args[0]+"/castle.c";
    if (file_size(temp)<0) {
      // Carador, Feb-1995.
      temp2 = implode(explode(read_file("/room/def_castle.c"),"Newwiz"),
                      capitalize(args[0]));
      temp2 = implode(explode(temp2, "new wizard"), "new domain");
      write_file(temp, temp2);
#if 0
// no longer automatically do this. an elder++ shall do it
// later when it is really needed
// Carador, 20-Nov-1997
      write_file("/room/init_file",temp+"\n");
#endif
      write("Created "+temp+"\n");
      call_other(temp, "???"); /* Hal praises Macbeth loading a castle */
    }
    return 1;
  case "delete":
    if (sizeof(args) != 1)
      return notify_fail("Usage: domain delete <domain>\n"), 0;
    SECURITY->set_protection("/domains/"+args[0],1,-1);
    err = SECURITY->delete_domain(args[0]);
    if (err) {
      write_error(err);
      return 1;
    }
    write("Domain deleted.\n"
          "Please remove files and possible entries in /room/init_file"
          " manually.\n");
    return 1;
  case "add":
    if (sizeof(args)<3 || args[<2]!="to")
      return notify_fail("Usage: domain add [-lord] <wizard> to <domain>\n"),0;
    temp = args[<1];
    args = args[0..<3];
    for (i=0; i<sizeof(args); i++) {
      if (args[i]=="-lord" && i+1 <sizeof(args)) {
        temp2 = args[++i];
        err = SECURITY->add_domain_member(temp,temp2,1);
        if (!err)
          write("Added lord "+temp2+" to "+temp+".\n");
      }
      else {
        temp2 = args[i];
        err = SECURITY->add_domain_member(temp,temp2,0);
        if (!err)
          write("Added "+temp2+" to "+temp+".\n");
      }
      if (err)
        write_error(err);
    }
    return 1;
  case "remove":
    if (sizeof(args)<3 || args[<2]!="from")
      return notify_fail("Usage: domain remove <wizard> from <domain>\n"), 0;
    temp = args[<1];
    args = args[0..<3];
    for (i=0; i<sizeof(args); i++) {
      err = SECURITY->remove_domain_member(temp,args[i]);
      if (err)
        write_error(err);
      else
        write("Removed "+args[i]+" from "+temp+".\n");
    }
    return 1;
  case "list":
    if (!sizeof(args)) {
      temp = SECURITY->query_domains();
      temp = sort_array(temp,#'>);
      if (!sizeof(temp))
        write("There are no domains.\n");
      else
        printf("The following domains exist:\n"
               "%-#*s\n",this_player()->query_property(P_DISPLAY_WIDTH),
               implode(temp,"\n")+"\n");
      return 1;
    }
    for (i=0; i<sizeof(args); i++) {
      temp = sort_array(SECURITY->query_domains(args[i])||({ }),#'>);
      if (!sizeof(temp))
        write("Wizard "+args[i]+" doesn't belong to any domain.\n");
      else
        write("Wizard "+args[i]+" belongs to "+implode(temp,", ")+".\n");
    }
    return 1;
  case "show":
    if (!sizeof(args))
      return notify_fail("Usage: domain show <domain>\n"), 0;
    for (i=0; i<sizeof(args); i++) {
      temp = SECURITY->query_domain_members(args[i]);
      if (!temp)
        write("There is no domain "+args[i]+".\n");
      else {
        temp2 = SECURITY->query_domain_lords(args[i]) || ({ });
        temp -= temp2;
        write("Domain "+args[i]+":\n");
        switch (sizeof(temp2)) {
        case 0:
          write("Lords: (none)\n");
          break;
        case 1:
          write("Lord: "+temp2[0]+"\n");
          break;
        default:
          write("Lords: "+implode(temp2,", ")+"\n");
        }
        switch (sizeof(temp)) {
        case 0:
          write("Members: (none)\n");
          break;
        case 1:
          write("Member: "+temp[0]+"\n");
          break;
        default:
          write("Members: "+implode(temp,", ")+"\n");
        }
        // Logged on... added by Carador, Apr-1996
        temp = filter(temp2 + temp,
                            lambda(({ 'x }),
                                   ({ (#'&&),
                                      ({ (#'=),
                                         'x,
                                         ({ (#'find_player), 'x }) }),
                                      ({ (#'interactive), 'x }) })));
        if (sizeof(temp)) write("Logged on: " + implode(temp, ", ") + "\n");
      }
    }
    return 1;
  }
  return 0;  // Coogan, 26-Mar-2011
}
