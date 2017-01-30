/*
 * This file is a daemon for each wizard. It defines the normal wizard
 * commands.
 */

#include <kernel.h>
#include <prop/player.h>
#include <describe.h>
#include <server.h>
#include <jobs.h>
#include <wizlevels.h>
#include <describe.h>
#include <grammar.h>
#include <mail.h>
#include <libs.h>
#include <message.h>
#include <regexps.h>
#include <rtlimits.h>
#include <is_wizard.h>
#include <files.h>     // Coogan, 07-Jun-2001
#include <fingerd.h>
#include <history.h>
#include <time_units.h>
#include <ctime.h>

inherit "basic/path";
inherit "basic/create";
inherit "basic/daemon";
inherit "bin/sub/less";
static functions inherit "basic/parser";

void create() {
  set_privilege(1);
  if (clonep()) {
    // Carador, Mar-1996
    add_rule("at "G_AMBIG_LIVINGS" "G_TEXT, "at");
    add_rule("with "G_AMBIG_LIVINGS" "G_TEXT, "with");
    add_error_message("at", "Usage: at <person> <command>.\n");
    add_error_message("with", "Usage: with <person> <command>.\n");

    add_rule("destruct "G_OBJECT, "destruct");
    add_rule("destruct "G_ALL, "destruct_all");
    add_error_message("destruct", "Destruct what?\n");

    add_rule("persistence "G_OBJECT, "persistence");   // Carador, Nov-1996

    add_rule("shutdown terminate", "shutdown_off");
    add_rule("shutdown now <text>", "shutdown");
    add_rule("shutdown <number> <text>", "shutdown");
    add_error_message("shutdown",
                      ("Use 'shutdown' only if you're aware of the"
                       " consequences of that command.\n"
                       "The game will be terminated and rebooted, all items"
                       " of the players will be gone.\n"
                       "Usage: shutdown now <very_good_reason>\n"
                       "          This command shuts down the game"
                       " immediately.\n"
                       "       shutdown <minutes> <reason_for_the_reboot>\n"
                       "          You start Armageddon by doing so. He will"
                       " reboot the game in\n"
                       "          <minutes> minutes. The"
                       " <reason_for_the_reboot> can be queried\n"
                       "          by anybody if he asks Armageddon 'why do"
                       " you reboot'.\n"
                       "       shutdown terminate\n"
                       "          Terminate a running Armageddon and do NOT"
                       " shut down the game.\n"));
    add_rule("clone "G_ANY_MONEY,"clonemoney");
    add_rule("clone "G_TEXT,"clone");
    add_rule("echo "G_TEXT, "echo");
    add_error_message("echo", "Echo what?\n");
    add_rule("echoto "G_ANY_LIVING" "G_TEXT, "echoto");
    add_error_message("echoto", "Echoto whom what?\n");
    add_rule("echoall "G_TEXT, "echoall");
    add_error_message("echoall", "Echoall what?\n");
    // autoload handling added by Coogan, 25-Jan-1999
    // enhanced autoload rules, Chameloid, 23-Mar-1999
    add_rule("autoload list","autoload_list");
    add_rule("autoload list "G_WORD,"autoload_list");
    add_rule("autoload remove "G_NUMBER,"autoload_remove");
    add_rule("autoload remove "G_NUMBER" "G_WORD,"autoload_remove");
    add_error_message("autoload","Usage: autoload list [<player>]\n"
                                 "       autoload remove <nr> [<player>]\n");
    // 'changelog' command by Coogan, 10++-Dec-2001
    add_rule("changelog add "G_WORD,    "changelog_add");
    add_rule("changelog remove "G_WORD, "changelog_remove");
    add_rule("changelog show",          "changelog_show");
    add_rule("changelog read "G_WORD,   "changelog_read");
    add_error_message("changelog",
      "Usage: changelog add <domain | wizard | global>\n"
      "       changelog remove <domain | wizard | global>\n"
      "       changelog read global | domains | wizards | <domain> | <wizard>\n"
      "       changelog show\n"
      "See 'man changelog' for further details.\n"); 
    // 'reportlog' command by Coogan, 16-Nov-2006
    add_rule("reportlog add "G_WORD,    "reportlog_add");
    add_rule("reportlog remove "G_WORD, "reportlog_remove");
    add_rule("reportlog read "G_WORD,   "reportlog_read");
    add_rule("reportlog read",          "reportlog_read");
    add_rule("reportlog show",          "reportlog_show");
    add_error_message("reportlog",
      "Usage: reportlog add <domain> | <wizard> | <syslog>\n"
      "       reportlog remove <domain> | <wizard> | <syslog>\n"
      "       reportlog read [<domain> | <wizard> | <syslog>]\n"
      "       reportlog show\n"
      "See 'man reportlog' for further details.\n"); 
  }
  set_auto_clone();
  add_command("parse_cmd", "shutdown");
  add_command("parse_cmd", "persistence");      // Carador, Nov-1996
  add_command("parse_cmd", "at");               // Carador, Mar-1996
  add_command("parse_cmd", "with");             // Alfe 1996-Oct-09
  add_command("parse_cmd", "clone");            // Alfe 1997-Nov-23
  add_command("parse_cmd", "echo");             // Coogan, 23-Apr-1998
  add_command("parse_cmd", "echoto");           // Coogan, 23-Apr-1998
  add_command("parse_cmd", "echoall");          // Coogan, 23-Apr-1998
  add_command("parse_cmd", "autoload");         // Coogan, 25-Jan-1999
  add_command("parse_cmd", "changelog_add");    // Coogan, 10-Dec-2001
  add_command("parse_cmd", "changelog_remove"); // Coogan, 10-Dec-2001
  add_command("parse_cmd", "changelog_show");   // Coogan, 10-Dec-2001
  add_command("parse_cmd", "changelog");        // Coogan, 10-Dec-2001
  add_command("parse_cmd", "reportlog_add");    // Coogan, 30-Oct-2006
  add_command("parse_cmd", "reportlog_remove"); // Coogan, 30-Oct-2006
  add_command("parse_cmd", "reportlog_read");   // Coogan, 30-Oct-2006
  add_command("parse_cmd", "reportlog_show");   // Coogan, 30-Oct-2006
  add_command("parse_cmd", "reportlog");        // Coogan, 30-Oct-2006
  add_command("parse_destruct", "destruct");
  add_command("shell","ls");
  add_command("shell","ll");
  add_command("shell","mv");
  add_command("shell","rm");
  add_command("shell","ed");
  add_command("shell","cat");
  add_command("shell","head");
  add_command("shell","tail");
  add_command("shell","mkdir");
  add_command("shell","rmdir");
  add_command("shell","cd");
  add_command("shell","pwd");
  add_command("shell","load");
  add_command("shell","update");
  add_command("shell","goto");
  add_command("shell","trans");
  add_command("shell","home");
  add_command("shell","people");
  add_command("shell","more");
  add_command("shell","localcmd");
#if 0  // Alfe 1998-Jul-31
  add_command("shell","prompt");
#endif
  add_command("shell","grep");
  add_command("shell","job");
  add_command("shell","view");
  add_command("shell","writefile");
  add_command("shell","in");
// those three are the substitution for an autoloading mailbox
  add_command("shell","read");
  add_command("shell","mail");
  add_command("shell","from");
// info-facility of the quest-server
  add_command("shell","qserv");
  add_command("shell","man");
  add_command("shell","apropos");
  add_command("shell","howto");
  add_command("shell","how");
// the board utility commands, Carador, Mar-1996
  add_command("shell","board");
// explore the history of a player, Alfe 2006-Mar-31
  add_command("shell","research");
}

static status parse_cmd(string arg, string verb) {
  return parse_sentence(arg ? verb + " " + arg : verb);
}

static status parse_destruct(string arg, string verb) {
  return arg != "all" && parse_sentence(arg ? verb + " " + arg : verb);
}

private varargs string* get_changelog_filenames(string key, status domain) {
  switch (key) {
  case "lib"      : return ({ "/changelog/LIBCHANGE", "/changelog/LIBINTRO" });
  case "wiz"      : return ({ "/changelog/WIZCHANGE", "/changelog/WIZINTRO" });
  case "decision" : return ({ "/changelog/DECISION",  "" });
  default:
    if (domain)
      return ({ "/changelog/changed/domains/" + key,
                "/changelog/intro/domains/" + key });
    else
      return ({ "/changelog/changed/wizards/" + key,
                "/changelog/intro/wizards/" + key });
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

private varargs mapping generate_changelog_mapping_entry(string key,
                                         status domain, status read) {
  string *files;
  files = get_changelog_filenames(key, domain);
  return ([ key : file_size(files[0]); 
                  file_size(files[1]);
                  time();
                  read ]);
}

private mapping generate_reportlog_mapping_entry(string key) {
  string *files;
  if (key == upper_case(key))
    // this is a syslog logfile
    return ([ key : file_size("/syslog/" + key);
                    file_size("/syslog/" + key + ".old");
                    0;
                    time() ]);
  else
    return ([ key : file_size("/log/" + key + ".rep");
                    file_size("/log/" + key + ".idea");
                    file_size("/log/" + key + ".praise");
                    time() ]);
}

private void show_log_entries(string s, string kind) {
  if (s == "")
    message("No new " + kind + " found.\n");
  else {
    this_player()->view_text(s, "latest " + kind);
    this_player()->start_view();
  }
}

private varargs string get_changelog_entries(mapping m, mixed who, status dom) {
  string result;
  string key, *keys, *files;
  int i, size;

  result = "";
  if (who && stringp(who))
    keys = ({ who });                      // ({ coogan })
  else {
    keys = sort_array(m_indices(m), #'>);  // ({ decision, libchng, wizchng })
    if (who) {                             // here: filtered
      for (i = sizeof(keys); i-->0; ) {
        if (!m[keys[i],3])
          keys[i] = 0;
      }
      keys -= ({ 0 });
    }
  }

  foreach (key : keys) {
    files = get_changelog_filenames(key, dom);  // ({ lc-c, lc-i })
    for (i = 0; i < sizeof(files); i++) {
      m[key, 2] = time();   // we just did the latest check
      if ((size = file_size(files[i])) == m[key, i]) {  // nothing new
        continue;
      }
      if (size == FSIZE_NOFILE) {  // file has been removed
        m[key, i] = -1;            // remember new file size
        continue;
      }
      result += files[i] + ":\n";
      if (size < m[key, i])              // exception: file became shorter,
        result += read_bytes(files[i], 0, size);  // so read the whole file
      else                                        // else read only new stuff
        result += read_bytes(files[i], m[key, i], size-m[key, i]);
      result += "\n";
      m[key, i] = size;   // remember the current filesize
    }
  }
  return result;
}

private string* get_reportlog_filenames(string key) {
  if (key == upper_case(key))
    return ({ "/syslog/" + key });
  return map(({ "rep", "idea", "praise" }),
             (: "/log/" + (SECURITY->query_is_domain($2)
                  ? capitalize($2) : $2) + "." + $1 :), key);
}

private varargs string get_reportlog_entries(mapping m, string key) {
  string result;
  result = "";
  string *keys, *files;
  int i, size, sizeoldfile;
  keys = sort_array(m_indices(m), #'>);

  if (key)
    keys = ({ key });

  foreach (key : keys) {
    files = get_reportlog_filenames(key);
    for (i = 0; i < sizeof(files); i++) {
      m[key, 3] = time();
      size = file_size(files[i]);
      sizeoldfile = file_size(files[i] + ".old");
      if (size == m[key, i]) {
        continue;
      }
      if (size == FSIZE_NOFILE) {
        m[key, i] = -1;
        continue;
      }
      result += files[i] + ":\n";
      if (size < m[key, i]) {
        // logfile was rotated; check if old file still exists
        if (sizeoldfile >= 0) { 
          result += read_bytes(files[i]+".old",m[key,i],sizeoldfile-m[key,i]);
        }
        result += read_bytes(files[i], 0, size);
      }
      else {
        result += read_bytes(files[i], m[key,i],size-m[key,i]);
      }
      result += "\n";
      m[key, i] = size;   // remember the current filesize
    }
  }
  return result;
}

static status do_action(string verb, mapping args) {
  object other_room, my_room, pl;  // Chameloid, 23-Mar-1999
  int passone, passtwo;            // Chameloid, 18-Jan-1998
  int i, j, remove, syslog;        // Coogan, 25-Jan-1999
  mixed h, h2, msg, desc;
  string *ind, err, type, key, *keys;

  // added following check   Alfe 1997-Feb-08
  if (query_once_interactive(this_player()) && 
      !is_wizard(this_player(),IW_TOOLUSER))
    raise_error("Illegal daemon added for player\n");

  switch (verb) {
  case "reportlog_show":
    // extern data 'reportlog' is a mapping:
    // ([ <domain>|<wizard> : 
    //           filesize(bug); filesize(idea); filesize(praise);
    //           readtime,
    //    <SYSLOG> :
    //           filesize(syslog); filesize(syslog.old); 0;
    //           readtime,
    // ])

    msg = "";
    h = this_player()->query_extern_data("bin/shell", "reportlog");
    if (h) {
      msg = "Reports of           time of last read\n\n";
      ind = m_indices(h);
      keys = map(ind, (: sprintf("%-15s      %-s\n",$1,ctime($2[$1,3])) :), h);
      for (i = 0; i < sizeof(ind); i++) {
        if (upper_case(ind[i]) == ind[i])
          continue;
        if (is_wizard(ind[i]))
          continue;
        keys[i] = capitalize(keys[i]);
      }
      keys = sort_array(keys, #'>);
      for (i = 0; i < sizeof(ind); i++) {
        msg += keys[i];
      }
    }
    if (msg == "")
      message("You're not reading any report logs.\n");
    else
      message(msg);
    return 1;

  case "reportlog_remove":
    h = this_player()->query_extern_data("bin/shell", "reportlog");
    key = args[G_WORD,1];
    if (upper_case(key) == key)
      syslog = 1;
    else
      key = lower_case(key);
    if (!h) {
      write("You are not reading any reportlogs.\n");
      return 1;
    }
    if (!member(h, key)) {
      if (syslog)
        message("You don't read the " + (key) + " syslog.\n");
      else
        message("You don't read the report logs of " + capitalize(key) + ".\n");
      return 1;
    }
    if (syslog)
      message("You stop reading the " + (key) + " syslog.\n");
    else
      message("You stop reading the report logs of " + capitalize(key) + ".\n");
    m_delete(h, key);
    if (!sizeof(h))
      this_player()->remove_extern_data("bin/shell", "reportlog");
    else
      this_player()->set_extern_data("bin/shell", "reportlog", h);
    return 1;
                
  case "reportlog_add":
    h = this_player()->query_extern_data("bin/shell", "reportlog") || ([:4]);
    key = args[G_WORD,1];
    if (upper_case(key) == key)
      syslog = 1;
    else
      key = lower_case(key);
    if (member(h, key)) {
      if (syslog)
        message("You're already reading the " + (key) + " syslog.\n");
      else
        message("You're already reading the report logs of " +
                capitalize(key) + ".\n");
      return 1;
    }
    if (syslog) {
      h += generate_reportlog_mapping_entry(key);
      message("You're now reading the " + (key) + " syslog.\n");
    }
    else {
      if (SECURITY->query_is_domain(key) == 0 &&
          !is_wizard(key)) {
        message("'"+ capitalize(key) +"' is neither a wizard or a domain.\n");
        return 1;
      }
      h += generate_reportlog_mapping_entry(key);
      message("You're now reading the report logs of " +
              capitalize(key) + ".\n");
    }
    keys = get_reportlog_filenames(key);
    for (i = 0; i < sizeof(keys); i++) {
      h[key,i] = file_size(keys[i]);
    }
    h[key, 3] = time();
    this_player()->set_extern_data("bin/shell", "reportlog", h);
    return 1;

  case "reportlog_read":
    if (args[G_WORD] == "show"  ||
        args[G_WORD] == "add"   ||
        args[G_WORD] == "remove")  // show default error message
      return 0;
    h = this_player()->query_extern_data("bin/shell", "reportlog") || ([:4]);
    if (member(args, G_WORD))
      key = args[G_WORD,1];
    else
      key = 0;
    if (!key && !sizeof(h)) {
      write("You're not watching any report logs.\n");
      return 1;
    }
    if (key) {
      if (upper_case(key) == key)
        syslog = 1;
      else
        key = lower_case(key);
      if (!member(h, key)) {
        string path;
        if (syslog)
          path = "/syslog/";
        else
          path = "/log/";
        // if existing, ...
        if (file_size(path + key) == FSIZE_NOFILE) {
          write("There is no such log " + path + key + ".\n");
          return 1;
        }
        // adding key on-the-fly
        do_action("reportlog_add", ([ G_WORD : key ]));
        h = this_player()->query_extern_data("bin/shell", "reportlog");
        if (!member(h, key))
          // sth. was wrong, error message is already given
          return 1;
      }
    }
    show_log_entries(get_reportlog_entries(&h, key), "reports");
    this_player()->set_extern_data("bin/shell", "reportlog", h);
    return 1;

    // end of reportlog handling

  case "changelog_show":
    msg = "";
    foreach (type : ({ "global", "domains", "wizards" })) {
      h = this_player()->query_extern_data("bin/shell", type);
      if (h) {
        if (msg == "")
          msg = "Log            read by default     time of last read\n\n";
        if (type == "domains")
          msg += "Domains:\n";
        else if (type == "wizards")
          msg += "Wizards:\n";
        keys = sort_array(m_indices(h), #'>);
        foreach (key : keys)
          msg +=sprintf("%-14s %-19s %s\n",
                        key, (h[key,3] == 1 ? "yes" : "no"), ctime(h[key,2]));
        if (sizeof(keys))
          msg += "\n";
      }
    }
    if (msg == "")
      message("You're not reading any changelogs.\n");
    else
      message(msg);
    return 1;

  case "changelog_remove":
    remove = 1;  // fall through
  case "changelog_add":
    // ([ domain | wizard : filesize(changed); filesize(intro);
    //                      readtime(intro);
    //                      status read ])

    if (args[G_WORD] == "global") {
      h = this_player()->query_extern_data("bin/shell", "global");
      if (!remove && h && member(h, "lib") && h["lib",3]) {
        message("You're already reading the global changelogs.\n");
        return 1;
      }
      if (remove && (!h || !member(h, "lib"))) {
        message("You're not reading the global changelogs.\n");
        return 1;
      }

      if (h && member(h, "lib")) {
        if (remove && !h["lib",3]) {
          m_delete(h, "lib");
          m_delete(h, "wiz");
          m_delete(h, "decision");
          message("You're not reading the global changelogs anymore.\n");
        } else {
          h["lib", 3]      = !remove;
          h["wiz", 3]      = !remove;
          h["decision", 3] = !remove;
          if (remove)
            message("Reading the global changelogs is set "
                    "to 'inactive' now. Remove again for real removal.\n");
          else
            message("You're now reading the global changelogs, too.\n");
        }
      } else {
        h  = generate_changelog_mapping_entry("lib", 0, 1);
        h += generate_changelog_mapping_entry("wiz", 0, 1);
        h += generate_changelog_mapping_entry("decision",  0, 1);
        message("Initialising the reading of global changelogs.\n");
        message("You're now reading the global changelogs, too.\n");
      }
      this_player()->set_extern_data("bin/shell", "global", h);
      return 1;
    }

    i = 1;
    if (member(SECURITY->query_domains(), args[G_WORD]) > -1) { // valid domain
      i = 0;
      j = 1;  // is domain!
    }
    if (i && is_wizard(args[G_WORD])) {  // valid wizard
      i = 0;
    }
    if (i) {
      notify_fail("'" + args[G_WORD] + "' is neither a wizard or a domain.\n");
      return 0;
    }

    if (j)
      h = this_player()->query_extern_data("bin/shell", "domains");
    else
      h = this_player()->query_extern_data("bin/shell", "wizards");

    if (!remove && h && member(h, args[G_WORD]) && h[args[G_WORD],3]) {
      message("You're already reading the changelog of "+ args[G_WORD] +".\n");
      return 1;
    }
    if (remove && (!h || !member(h, args[G_WORD]))) {
      message("You're not reading the changelog of " + args[G_WORD] + ".\n");
      return 1;
    }
    if (remove) {
      if (h[args[G_WORD],3]) {
        h[args[G_WORD],3] = 0;
        message("Reading the changelog of " + args[G_WORD] + " is set "
                "to 'inactive' now. Remove again for real removal.\n");
      } else {
        // already inactive, delete it finally
        m_delete(h, args[G_WORD]);
        message("You're not reading the changelog of " + args[G_WORD] +
                " anymore.\n");
      }
    } else {
      if (h && member(h, args[G_WORD]))
        h[args[G_WORD],3] = 1;
      else {
        h2 = generate_changelog_mapping_entry(args[G_WORD], j, 1);
        message("Initialising the reading of changelog of "+args[G_WORD]+".\n");
        if (sizeof(h))
          h += h2;
        else
          h  = h2;
      }
      message("You're now reading the changelog of "+args[G_WORD]+", too.\n");
    }
    if (j)
      this_player()->set_extern_data("bin/shell", "domains", h);
    else
      this_player()->set_extern_data("bin/shell", "wizards", h);
    return 1;

  case "changelog_read":
    if (!args[G_WORD])  // show default error message
      return 0;

    switch (args[G_WORD]) {
    case "global":
      i = 1;
      h = this_player()->query_extern_data("bin/shell", "global");
      if (!h) {
        h  = generate_changelog_mapping_entry("lib");
        h += generate_changelog_mapping_entry("wiz");
        h += generate_changelog_mapping_entry("decision");
        message("Initialising the reading of global changelogs.\n");
        i = 0;
      }
      if (i)
        show_log_entries(get_changelog_entries(&h), "changes");
      this_player()->set_extern_data("bin/shell", "global", h);
      return 1;
     
    case "domains":
    case "wizards":
      h = this_player()->query_extern_data("bin/shell", args[G_WORD]);
      if (!h) {
        message("You're not reading any changelogs of "+ args[G_WORD] +".\n");
        return 1;
      }
      show_log_entries(
        get_changelog_entries(&h, 1, (args[G_WORD]=="domains")), "changes");
      this_player()->set_extern_data("bin/shell", args[G_WORD], h);
      return 1;

    default:  // a particular domain/wizard
      i = 0;
      if (SECURITY->query_is_domain(args[G_WORD])) {
        h = this_player()->query_extern_data("bin/shell", "domains");
        j = 1;  // is domain
        i = 1;
      } else if (is_wizard(args[G_WORD])) {
        h = this_player()->query_extern_data("bin/shell", "wizards");
        i = 1;
      }
      if (!i) {
        notify_fail("'"+ args[G_WORD] +"' is neither a wizard or a domain.\n");
        return 0;
      }
      if (!h) {
        h  = generate_changelog_mapping_entry(args[G_WORD], j);
        message("Initialising the reading of changelog of "+args[G_WORD]+".\n");
        i = 0;
      } else if (h && !member(h, args[G_WORD])) {
        h += generate_changelog_mapping_entry(args[G_WORD], j);
        message("Initialising the reading of changelog of "+args[G_WORD]+".\n");
        i = 0;
      }
      if (i)
        show_log_entries(get_changelog_entries(&h, args[G_WORD], j), "changes");
      if (j)
        this_player()->set_extern_data("bin/shell", "domains", h);
      else
        this_player()->set_extern_data("bin/shell", "wizards", h);
      return 1;
    }
    return 0;

  case "echo":
    log_file("ECHO", this_player()->query_vis_name() + " echo: " +
             args[G_TEXT] +"\n");
    say(args[G_TEXT] + "\n");
    write("You echo: " + args[G_TEXT] + "\n");
    return 1;
  case "echoto":
    log_file("ECHO", this_player()->query_vis_name() + " echoto " +
             args[G_ANY_LIVING]->query_vis_name()+": "+ args[G_TEXT]+"\n");
    tell_object(args[G_ANY_LIVING], args[G_TEXT] + "\n");
    write("You echo to " + args[G_ANY_LIVING]->query_vis_name() + ": " +
          args[G_TEXT] + "\n");
    return 1;
  case "echoall":
    log_file("ECHO", this_player()->query_real_name() + " echoall: " +
             args[G_TEXT] + "\n");
    filter(users(),
#if 0  // Coogan, 17-Dec-1998
                 #'tell_object,
#else
                 lambda(({ 'x, 'y }),
                        ({ #'?, ({ #'call_other, 'x, "query_login" }), 0,
                           ({ #'tell_object, 'x, 'y }) })),
#endif
                 args[G_TEXT]+"\n");
    write("You echo to all people: " + args[G_TEXT] + "\n");
    return 1;
  case "clonemoney":
    h = clone_object("obj/money");
    h->set_amount(args[G_ANY_MONEY,1]);
    send_message(({ M_PL_THE,M_PL_VERB,"make"," a complicated gesture and ",
                    h,M_VERB,"appear",h," in ",M_PL_POSSESSIVE," hand." }));
    move_object(h,this_player());
    return 1;
  case "clone":
    args[G_TEXT] = normalize_path(args[G_TEXT],this_player());

    // following check for non-existent or non-readable files and
    // directories added by Chameloid, 18-Jan-1998
    
    if (!find_object(args[G_TEXT])) { // blueprint not loaded?
      err = catch(passone = unguarded(1,#'file_size,args[G_TEXT]));
      if (err) { // illegal path for instance?
        write(err);
        return 1;
      }
      if (passone < 0) {
        err = catch(passtwo = unguarded(1,#'file_size,args[G_TEXT]+".c"));
        // we ignore 'err' since we built the filename
        if (!err && passtwo != -1) passone = passtwo;
      }
      switch (passone) {
      case -1:
        write("Error: file does not exist or cannot be read.\n");
        return 1;
      case -2:
        write("Error: cannot clone directories.\n");
        return 1;
      }
    }

    h = clone_object(args[G_TEXT]);
    move_object(h, environment(this_player()));  // move the thing near
                                                 // the player
    if (h && environment(h) && h->get() && h)  // thing takeable and all ok?
      move_object(h,this_player());            // then move into the player
    else if (h && !environment(h))             // else: something funny?
      destruct(h);                             // then destruct it.
    if (this_player()->short()) {
      msg=this_player()->query_property(P_MSGCLONE);
      if (!(stringp(msg) || pointerp(msg)))
        msg=({ M_PL_THE, M_PL_VERB, "fetch",
               " something from another dimension." });
      if (stringp(msg))
        send_message(({ M_SAY, M_PL_THE, " "+msg, M_WRITE, "Ok." }));
      else if (this_player()->query_property(P_ECHO))
        send_message(msg[0..],([ "cloned_object":h ]));
                     // ^^^^^ copying necessary due to message system
      else
        send_message(({ M_SAY }) + msg + ({ M_WRITE,"Ok." }),
                     ([ "cloned_object":h ]));
    }
    return 1;
  // Carador, Mar-1996
  case "at": // fall through
  case "with":
    h = ([]) + args[G_AMBIG_LIVINGS];
    ind = m_indices(h);
    if (sizeof(ind) > 1)
      return notify_fail(capitalize(verb)+
                         " only works with one person at the same time.\n",
                         -1), 0;
    if (!sizeof(ind))
      return notify_fail("No such person.\n",-1), 0;
    if (!h[ind[0]])
      return notify_fail(capitalize(verb) + " " + ind[0] +
                         "? Didn't find that person.\n",-1), 0;
    h = h[ind[0]];
    if (pointerp(h) && sizeof(h) > 1)
      return notify_fail("There are " + sizeof(h) +
                         " players beginning with '" + ind[0] + "': " +
                         make_list(map_objects(h,
                                               "query_vis_name")) + ".\n",
                         -1), 0;
    if (pointerp(h))
      h = h[0];
    if (!(other_room = environment(h)))
      return notify_fail(h->query_vis_name() + " has no environment.\n",-1), 0;
    my_room = environment(this_player());
    if (verb == "at")
      move_object(this_player(), other_room);
    else
      move_object(h, my_room);
    command(args[G_TEXT], this_player());
    if (verb == "at")
      if (!my_room)
        write("Hm, your old room is gone. Staying where you are.\n");
      else
        move_object(this_player(),my_room);
    else  // verb was "with"
      if (!other_room)
        send_message(({ M_TARGETS,({ this_player(),h }),"Oops, ",M_S,h,
                        " room is gone. Staying were ",M_PRONOUN,h,
                        M_VERB,"are",h,"." }));
      else
        move_object(h,other_room);
    return 1;
  case "shutdown_off":
    if (!(h = find_object("/etc/shut"))) {
      notify_fail("There's no shutdown in progress which to terminate.\n",-1);
      return 0;
    }
    write("Ok. Shutdown has been terminated.\n");
    destruct(h);
    return 1;
  case "shutdown":
    if (!args[G_NUMBER]) {     // shutdown now
      shout("Game is shut down by " + this_player()->query_vis_name() + ".\n");
      log_file("GAME_LOG",
         ctime(time())+": Game shutdown by "+
           this_player()->query_vis_name()+" ("+args[G_TEXT]+")\n");
      shutdown();
      return 1;
    }
    if (find_object("/etc/shut")) {
      notify_fail("There's already a shutdown in progress.\n",-1);
      return 0;
    }
    if (args[G_NUMBER] < 5) {
      notify_fail("That's too soon. At least five minutes, okay?\n",-1);
      return 0;
    }
    message("Armageddon started. Shutdown will be in " + args[G_NUMBER] +
            " minutes.\n"
            "Reason is: " + args[G_TEXT] + "\n");
    "/etc/shut"->start_armageddon(args[G_NUMBER], args[G_TEXT]);
    return 1;
  case "destruct":
    args[G_ALL] = ({ args[G_OBJECT] });
    args[G_ALL,1] = ({ args[G_OBJECT,1], 0 });
    // fall through
  case "destruct_all":
    if (args[G_ALL,1][1])
      args[G_ALL] = args[G_ALL][0..args[G_ALL,1][1]-1];
    if (!sizeof(args[G_ALL]))
      return 0;
#if 0 // Chameloid, 30-Jul-1997
    h=this_player()->query_property(P_MSGDESTRUCT) || "hurled into the void";
#else
    h=this_player()->query_property(P_MSGDESTRUCT);
    if (!(stringp(h) || pointerp(h)))
      h="hurled into the void";
#endif
    // added some M_THE in the next messages, Coogan, 10-Oct-2001
    if (this_player()->query_property(P_ECHO))
      send_message(stringp(h) ?
                   ({ M_SAY, M_THE, args[G_ALL], M_VERB, "are", args[G_ALL],
                      " "+h+" by ", M_PL_THE, ".",
                      M_WRITE, M_PL_THE, M_PL_VERB, "hurl", M_OBJECT, M_THE,
                      args[G_ALL], " into the void." }) :
                   h[0..],([ "destructed_objects": args[G_ALL] ]));
    else
      send_message(stringp(h) ?
                   ({ M_SAY, M_THE, args[G_ALL], M_VERB, "are", args[G_ALL],
                      " "+h+" by ", M_PL_THE, ".",
                      M_WRITE, "Ok." }) :
                   ({ M_SAY }) + h + ({ M_WRITE, "Ok." }),
                   ([ "destructed_objects": args[G_ALL] ]));
    map(args[G_ALL], #'destruct);
    break;
  case "persistence" :    // Carador, Nov-1996
    if (environment(args[G_OBJECT]) != this_player()) {
      message("Get it first.\n");
      return 1;
    }
    h = args[G_OBJECT]->get_state();
    desc = load_name(args[G_OBJECT]);

    if (!h ||     // missing persistence,
         h == -1) // wanted non-persistence, Chameloid, 25-Sep-1997
    {
      send_message(({ M_WRITE, args[G_OBJECT], M_VERB, "are", args[G_OBJECT],
        " not persistent." }));
      return 1;
    }
    if (intp(h)) {
      send_message(({ M_WRITE, args[G_OBJECT], M_VERB, "are", args[G_OBJECT],
        " persistent without variables. Destructing..." }));
      destruct(args[G_OBJECT]);
      move_object(my_room = clone_object(desc), this_player());
      send_message(({ M_WRITE, "Restored ", my_room, "." }));
      return 1;
    }
    if (mappingp(h)) {
      send_message(({ M_WRITE, args[G_OBJECT], M_VERB, "are", args[G_OBJECT],
        " persistent with variables " +
        make_list(m_indices(h)) + ". Destructing..." }));
      destruct(args[G_OBJECT]);
      my_room = clone_object(desc);
      my_room->set_state(h);
      move_object(my_room, this_player());
      send_message(({ M_WRITE, "Restored ", my_room, "." }));
      return 1;
    }
    break;
  case "autoload_list":
    // added possibility of looking at other people's autoloading items,
    // Chameloid, 23-Mar-1999
    if (args[G_WORD]) {
      if (!pl = find_player(args[G_WORD]))
        return notify_fail("No such player online.\n"), 0;
    } else {
      pl = this_player();
    }
    h = pl->query_autoloads();
    message("A list of "+
            ((this_player() == pl)? "your" : LIB_LANGUAGE->possessive_s(pl)) +
            " autoloading items:\n");
    for (i = 0; i < sizeof(h); i++)
      message(("   "+ i)[<3..<1] +": "+ object_name(h[i]) +"\n");
    j = i;
    h = pl->query_buggy_autoloads();
    if (sizeof(h))
      for (i = 0; i < sizeof(h); i++)
        message(("   "+ (i + j))[<3..<1] +": "+ h[i] +"  (buggy)\n");
    return 1;
  case "autoload_remove":
    // added possibility of removing other people's autoloading items,
    // Chameloid, 23-Mar-1999
    if (args[G_WORD]) {
      if (!pl = find_player(args[G_WORD]))
        return notify_fail("No such player online.\n"), 0;
    } else {
      pl = this_player();
    }
    h = pl->query_autoloads();
    ind = pl->query_buggy_autoloads();
    if ((args[G_NUMBER] < 0) || (args[G_NUMBER] >= (sizeof(h) + sizeof(ind))))
      return notify_fail("There are not so many autoloads.\n"), 0;
    if (args[G_NUMBER] < sizeof(h)) {  // destruct a normal autoload
      message("Ok, destructing "+ object_name(h[args[G_NUMBER]]) +".\n");
      destruct(h[args[G_NUMBER]]);
      return 1;
    } else {
      args[G_NUMBER] -= sizeof(h);
    }
    message("Ok, removing "+ ind[args[G_NUMBER]] +" from "+
            ((this_player() == pl)? "your" : LIB_LANGUAGE->possessive_s(pl)) +
            " autoload list.\n");
    pl->remove_single_buggy_autoload(ind[args[G_NUMBER]]);
    return 1;
  default:
    return 0;
  }
  return 1;
}

static void list_dir(string dir,mapping options) {
  string path;
  mixed *contents;
  status wildcards; // Chameloid, 18-Jan-1998
  string *list,err;
  int all,long;
  int i,j,s,t;
  int pass; // Chameloid, 18-Jan-1998
  string tpath;     // Coogan, 07-Jun-2001, for 'ls -f' extension by Dozy:
  string load_mark; // argument '-f' checks for loaded objects and marks
                    // them with a '*' in the output

  // improved following check for non-existent or non-readable
  // files and directories, Chameloid, 18-Jan-1998
  
  path = normalize_path(dir, this_player());
  wildcards = !!(member(path, '*') + member(path,'?') + 2);

  err = catch(pass = file_size(path));
  if (err) { // illegal path for instance?
    write(err);
    return;
  }

  // for the 'ls -f' extension
  if (file_size(path) != FSIZE_DIR)
    tpath = implode(explode(path, "/")[0..<2], "/");
  else
    tpath = path;
            
  if (!wildcards)
    switch (pass) {
    case FSIZE_NOFILE:
      printf("%s not found.\n",path);
      return;
    case FSIZE_DIR:
      if (!options["d"]) path += "/*";
      break;
    }
  
  if (err = catch(contents = get_dir(path,7))) {
    write(err);
    return;
  }

  if (!sizeof(contents)) {
    if (wildcards)
      write("ls: No match.\n");
    else
      printf("%s not readable.\n",path[0..<3]);
    return;
  }

  all = options["a"];
  long = options["l"];
  list = allocate(sizeof(contents)/3);
  s = 4;
  t = 4;
  if (long) {
    for (i=0; i<sizeof(contents); i+=3) {
      if ((j = strlen(contents[i])) > s)
        s = j;
      switch (contents[i+1]) {
        case -2:
          j = 6;
          break;
        case 0..9:
          j = 2;
          break;
        case 10..99:
          j = 3;
          break;
        case 100..999:
          j = 4;
          break;
        case 1000..9999:
          j = 5;
          break;
        case 10000..99999:
          j = 6;
          break;
        case 100000..999999:
          j = 7;
          break;
        case 1000000..9999999:
          j = 8;
          break;
        case 10000000..99999999:
          j = 9;
          break;
        default:
          j = strlen(contents[i]+1+"");
          break;
      }
      if (j>t)
        t = j;
    }
  }
  for (i=j=0; i<sizeof(list); i++, j+=3) {
    if (!all && contents[j][0]=='.')
      continue;
    all = 1;
    // And here is the -f option, Coogan for Dozy, 07-Jun-2001
    if (options["f"])
      load_mark = (find_object(tpath+"/"+contents[j]) ? "*" : "");
    else
      load_mark = "";
    if (long)
      // and added the last %s for -f
      list[i] = sprintf("%-*s%*s  %s %s\n",
                        s,contents[j],
                        t,contents[j+1]>=0?contents[j+1]+"":"<dir>",
                        ctime(contents[j+2]),
                        load_mark);
    else
      list[i] = contents[j+1]<0
                ? "  <d> "+contents[j]+"/\n"
                : sprintf("%5d %s%s\n", (contents[j+1]+1023)>>10,
                                        contents[j], load_mark);
  }
  list -= ({ 0 });
  if (long)
    this_player()->view_text(implode(list,""),
                             this_player()->query_commandline());
  else
    this_player()->view_text(sprintf("%-78#s\n",implode(list,"")),
                             this_player()->query_commandline());
  this_player()->start_view();
}

static void dogrep(string *args) {
  mapping job;
  string *files, *dir;
  int i, j;
  job = ([ J_HANDLER: "/global/server/grep",
           J_FUNCTION: "do_grep_job",
           J_OUTPUT: 1,
           J_SIGNATURE: "grep",
           GREP_EXPRESSION: args[0],
           GREP_FILES: ({}) ]);
  if (sizeof(args) > 3 && args[<2] == ">") {
    job[J_OUTPUT] = normalize_path(args[<1], this_player());
    files = map(args[1..<3], #'normalize_path, this_player());
  }
  else
    files = map(args[1..], #'normalize_path, this_player());
  for (i = 0; i < sizeof(files); i++) {
    for (j = strlen(files[i]); j-- && files[i][j]!='/';)
      ;
    if (!sizeof(dir = get_dir(files[i])))
      write("'"+files[i]+"' doesn't exist.\n");
    job[GREP_FILES] += map(dir - ({ ".", ".." }),
                                 lambda(({'x, 'y}), ({ #'+, 'y, 'x })),
                                 files[i][0..j]);
  }
  JOB_SERVER->add_job(job, get_privilege(this_player()));
}

static void read_whole_file(string arg) {
    mapping job;
    string *files, *dir;
    job = ([ J_HANDLER: load_name(this_object()),
             J_FUNCTION: "read_file_job",
             J_OUTPUT: 1 ]);
    switch (file_size(arg = normalize_path(arg, this_player())))
    {
    case -2: write(arg + " is a directory.\n"); return;
    case -1: write(arg + " doesn't exist.\n"); return;
    default: job += ([ J_SIGNATURE: arg ]);
    }
    JOB_SERVER->add_job(job, get_privilege(this_player()));
}

void read_file_job(mapping job) {
    string str;
    str = read_bytes(job[J_SIGNATURE], job["file_offset"], 50000);
    if (str && strlen(str) == 50000) 
        job["file_offset"] = job["file_offset"] + 50000;
    else job[J_FINISHED] = "New file to 'view': "+job[J_SIGNATURE]+"\n";
    if (!str) return;
    if (job[J_RESULT]) job[J_RESULT] += str;
    else job[J_RESULT] = str;
}

static void writefile_loop(string str, string file) {
  if (str == "**") {
    write("Ok, written to "+file+".\n");
    return;
  }
  write_file(file, str+"\n");
  write("]");
  input_to("writefile_loop", 0, file);
}

string age_to_string(int age) {
  age <<= 1;  // age is counted in doubleseconds
  if (!age)             return "?";
  if (age < ONE_MINUTE) return age            + " seconds";
  if (age < ONE_HOUR)   return age/ONE_MINUTE + " minutes";
  if (age < ONE_DAY)    return age/ONE_HOUR   + " hours";
  else                  return age/ONE_DAY    + " days";
}

string level_to_string(int level) {
  return "" + level;
}

string history_entry_to_string(mapping entry) {
  mixed h;
  string result;
  h = result = ctime(entry[HIST_DATE]);
  h = (h[CTIME_YEAR] + "-" + h[CTIME_MONTH] + "-" + h[CTIME_DAY] + " " +
       h[CTIME_TIME]);
  result = (h + ", age " + age_to_string(entry[HIST_AGE]) + ", level " +
            level_to_string(entry[HIST_LEVEL]));
  if      (h=entry[HIST_BIRTH])
    return result + ": character created";
  else if (h=entry[HIST_SPONSOR])
    return (result +
            ": inaugurated; sponsored by " + h);
  else if (h=entry[HIST_NEW_LEVEL])
    return (result +
            ": raised level to " + h);
  else if (h=entry[HIST_QUEST])
    return (result +
            ": solved quest " + h);
  else if (h=entry[HIST_SCENARIO])
    return (result +
            ": solved scenario " + h);
  else if (h=entry[HIST_KILLER])
    return (result +
            ": was killed by " + h);
  else if (h=entry[HIST_HOLIDAY])
    return (result +
            ": was on holiday for " + h/ONE_DAY + " days");
  else {
    return result + " (entry without topic)";
  }
}

int shell(string arg, string verb) {
  mixed h;
  string *args;
  int i, j, t;
  object ob;
  string out, file;
  mapping options;
  mixed temp, temp2;

  // added following check   Alfe 1997-Feb-08
  // check only done for once_interactives (as above)   Ugh Jun-02-1997
  if (query_once_interactive(this_player())
      && !is_wizard(this_player(),IW_TOOLUSER))
    raise_error("Illegal daemon added for player\n");

  if (!arg)
    args = ({ });
  else
    args = explode(arg," ")-({});
  switch (verb) {
  case "ll":
    args = ({ "-l" }) + args;
    // fall through
  case "ls":
    options = ([ ]);
    t = 0;
    for (i=0; i<sizeof(args);i++) {
      if (args[i][0]=='-') {
        j = 1;
        while(strlen(temp = args[i][j..j])) {
          ++j;
          options[temp] = 1;
        }
      }
      else {
        t = 1;
        list_dir(args[i],options);
      }
    }
    if (!t)
      list_dir(".",options);
    return 1;
  case "mv":
    if (sizeof(args)>2) {
      // added following unguarded() call, Chameloid, 27-Jan-1998
      if (unguarded(1,#'file_size,args[<1])!=-2) {
        notify_fail("mv: moving multiple files requires last argument to be "
                    "target directory\n",-1);
        return 0;
      }
      for (i=0; i<sizeof(args)-1; i++)
        write("mv "+args[i]+" "+args[<1]+
              // added following catch() call, Chameloid, 27-Jan-1998
              ((!catch(t=rename(args[i],args[<1])) && !t) ?
               ": OK.\n" : ": Failed.\n"));
      return 1;
    }
    else
      if (sizeof(args)==2 && // refined check, Chameloid, 27-Jan-1998
          !catch(t=rename(args[0],args[1])) && !t)
        write("Ok.\n");
      else
        write("Failed.\n");
    return 1;
  case "rm":
    if (!sizeof(args)) {
      notify_fail("rm what?\n",-1);
      return 0;
    }
    for (i=0; i<sizeof(args); i++)
      write("rm " + args[i] + (rm(args[i]) ? ": Ok.\n" : ": Failed.\n"));
    return 1;
  case "ed":
    if (sizeof(args)>1) {
      notify_fail("Too many arguments to ed.\n",-1);
      return 0;
    }
    if (!sizeof(args)) {
      temp = get_error_file(this_player()->query_real_name());
      if (temp) {
        write(temp[0]+" "+temp[1]+": "+temp[2]+"\n");
        args = temp[0..0];
      }
      else
        return write("Nothing to edit.\n"), 1;
    }
    if (file_size(args[0])>=204800) {
      notify_fail("This file is too large for online editing. Please"
                  " desist.\n",-1);
      return 0;
    }
    ed(args[0]);
    return 1;
  case "head":
  case "tail":
    if (!sizeof(args))
      return 0;
    temp = 10;
    if (sizeof(args)==2)
      if (sizeof(regexp(args[0..0],"-[0-9][0-9]*"))) {
        temp = -to_int(args[0]);
        args = args[1..];
      }
    if (sizeof(args)>1) {
      notify_fail("Too many arguments to \'"+verb+"\'.\n",-1);
      return 0;
    }
    if (verb=="head")
      cat(args[0],1,temp);
    else
      tail(args[0],temp);
    return 1;
  case "cat":
    if (!sizeof(args))
      return 0;
    if (sizeof(args)>1) {
      notify_fail("Too many arguments to \'cat\'.\n",-1);
      return 0;
    }
    cat(args[0]);
    return 1;
  case "mkdir":
    if (!sizeof(args)) {
      notify_fail("Usage: mkdir <directory>\n",-1);
      return 0;
    }
    for (i=0; i<sizeof(args); i++)
      write("mkdir "+args[i]+(mkdir(args[i]) ? ": Ok.\n" : ": Failed.\n"));
    return 1;
  case "rmdir":
    if (!sizeof(args)) {
      notify_fail("Usage: rmdir <directory>\n",-1);
      return 0;
    }
    for (i=0; i<sizeof(args); i++)
      write("rmdir "+args[i]+(rmdir(args[i]) ? ": Ok.\n" : ": Failed.\n"));
    return 1;
  case "cd":
    if (sizeof(args) > 1) {
      notify_fail("Usage: cd <directory>\n",-1);
      return 0;
    }
    // reinstalled the 'here' feature again, Coogan, 23-Nov-2001
    if (!sizeof(args))
      args = ({ "/players/"+this_player()->query_real_name() });
    else {
      if (args[0] == "here") {
        args += ({ implode(
                     explode("/"+load_name(environment(this_player()))+".c",
                             "/")[0..<2], "/") });
        if (!strlen(args[1]) || args[1][0] != '/')
          args[1] = "/" + args[1];
      }
      args[0] = normalize_path(args[0], this_player());
    }
    if (file_size(args[0]) != FSIZE_DIR) {   // first try failed.
      if (sizeof(args) == 2 && file_size(args[1]) == FSIZE_DIR) {
        args = ({ args[1] });  // success, do nothing now.
      } else
        return notify_fail(args[0]+" is not a valid path.\n",-1), 0;
    }
    this_player()->set_path(args[0][1..]);
    write("/" + this_player()->query_path() + "\n");
    return 1;
  case "pwd":
    write("/"+this_player()->query_path()+"\n");
    return 1;
  case "update":
    if (!sizeof(args)) {
      notify_fail("Usage: update <files>\n",-1);
      return 0;
    }
    args = map(args,#'normalize_path,this_player());
    for (i=0; i<sizeof(args);i++) {
      if (temp = find_object(args[i])) {
        write("Destructing "+args[i]+"\n");
        destruct(temp);
      }
      else
        write("Failed to find "+args[i]+"\n");
    }
    return 1;
  case "goto":        /*Fangorn 13-Oct-1993*/
    if (!arg) {
      notify_fail("Goto where?\n",-1);
      return 0;
    }
    ob = find_living(arg);
    if (ob) {
      ob = environment(ob);
      this_player()->move_living("X", ob);
      return 1;
    }
    arg=normalize_path(arg,this_player());
    if (file_size(arg) <= 0 && file_size(arg+".c") <= 0) {
      notify_fail("Invalid monster name or file name: " + arg + "\n",-1);
      return 0;
    }
    this_player()->move_living("X", arg);
    return 1;
  case "in":
    if (!arg || sizeof(args) < 2) {
      notify_fail("Usage: in <room> <command>\n",-1);
      return 0;
    }
    args[0] = normalize_path(args[0], this_player());
    if (args[0][<2..] == ".c")
      args[0] = args[0][0..<3];
    if (file_size(args[0]+".c") < 0) {
      notify_fail(args[0]+".c doesn\'t exist.\n",-1);
      return 0;
    }
    ob = environment(this_player());
    move_object(this_player(), args[0]);
    command(implode(args[1..], " "), this_player());
    if (ob)
      move_object(this_player(), ob);
    return 1;
  case "trans":
    if (!arg) {
      notify_fail("Trans whom?\n", -1);
      return 0;
    }
    ob = find_living(arg);
    if (!ob) {
      notify_fail("No such living thing.\n", -1);
      return 0;
    }
    tell_object(ob, "You are magically transferred somewhere.\n");
    send_message(({ M_WRITE, M_PL_THE, M_PL_VERB, "transfer", M_THE, M_OBJECT,
                    ob, " from ", environment(ob),
                    " (" + object_name(environment(ob)) + ") to ",
                    M_THE, environment(this_player()),
                    " (" + object_name(environment(this_player())) + ")." }));
    ob->move_living("X",environment(this_player()));
    return 1;
  case "home":
    this_player()->move_living("home", "players/" +
                               this_player()->query_real_name() + "/workroom");
    return 1; 
  case "load":
    args = map(args,#'normalize_path,this_player());
    if (!sizeof(args))
      return notify_fail("Usage: load <file1> <file2> ...\n"), 0;
    for (i=0; i<sizeof(args); i++) {
      if (find_object(args[i]))
        write(args[i]+" is already loaded.\n");
      else
        write("Loading "+args[i]+"\n");
      if (h=catch(load_object(args[i]))) {
        if (h == "*Failed to load file.\n")
          return notify_fail("Failed to load file: "+args[i]+"\n"), 0;
        // no notify_fail here
        else
        {
          message("Error loading object: "+h);
          return 1;
        }
      }
      else
        write("Ok.\n");
    }
    return 1;
  case "clone":
    if (sizeof(args)!=1) {
      notify_fail("Clone what?\n",-1);
      return 0;
    }
    args[0] = normalize_path(args[0],this_player());
    temp2 = this_player();
    temp = clone_object(args[0]);
    move_object(temp, environment(temp2));
    if (temp && environment(temp) && temp->get() && temp)
      move_object(temp, temp2);
    else
      if (temp && !environment(temp)) destruct(temp);
    /* changed the moving algorithm (Ugh 23-May-1994) */
    if (this_player()->short()) {
#if 0 // Chameloid, 30-Jul-1997
      h=this_player()->query_property(P_MSGCLONE) ||
        ({ M_PL,M_PL_VERB,"fetch"," something from another dimension." });
#else
      h=this_player()->query_property(P_MSGCLONE);
      if (!(stringp(h) || pointerp(h)))
        h=({ M_PL_THE,M_PL_VERB,"fetch"," something from another dimension." });
#endif
      if (stringp(h))
        send_message(({ M_SAY,M_PL_THE," ",h,M_WRITE,"Ok." }));
      else if (this_player()->query_property(P_ECHO))
        send_message(h[0..],([ "cloned_object":temp ]));
      else
        send_message(({ M_SAY })+h+({ M_WRITE,"Ok." }),
                     ([ "cloned_object":temp ]));
    }
    return 1;
  case "people":
    return "/bin/sub/people"->do_people(arg);
  case "more":
    if (sizeof(args)!=1) {
      notify_fail("Usage: more <file>\n",-1);
      return 0;
    }
    // added following switch, Chameloid, 27-Jan-1998
    switch (unguarded(1,#'file_size,args[0])) {
    case -1:
      return notify_fail("File does not exist.\n",-1), 0;
    case -2:
      return notify_fail("Cannot display directory.\n",-1), 0;
    }
    command_less(normalize_path(args[0],this_player()));
    return 1;
  case "localcmd":
    this_player()->tell_more(sprintf("%-78#s\n",
                                     implode(query_actions(this_player()),
                                             "\n")+"\n"));
    // changed write to tell_more()  Alfe 1995-Sep-13
    return 1;
#if 0  // Alfe 1998-Jul-31
  case "prompt":
    if (!sizeof(args))
      write("Prompt: \""+this_player()->change_prompt(0)+"\"\n");
    else {
      h=implode(args," ");
      if (h[0]=='\"' && h[<1]=='\"')
        h = h[1..<2];
      write("Old prompt: \""+this_player()->change_prompt(h)+"\"\n");
    }
    return 1;
#endif
  case "grep": 
    if (arg && arg[0] == '\"') {  // expression is enclosed in doublequotes?
      h = regexplode(arg,REGEXP_STRING);
      if (catch(args = (({ h[1][1..<2] }) +
                        (explode(implode(h[2..],"")," ") - ({ "" })))))
        return notify_fail("Parse error: String not terminated.\n",-1), 0;
    }
    if (sizeof(args) < 2)
      return notify_fail("Usage: grep <expr> { <filename> } [ >"
                         " <output-filename> ]\n"
                         "(<expr> can be quoted with doublequotes.)\n",-1), 0;
    dogrep(args);
    return 1;
  case "job":
    if (!sizeof(args)) {
      notify_fail("Usage: job list {[all|<player>]}\n"
                  "Usage: job remove {<number>}\n",-1);
      return 0;
    }
    // moved next declaration out of the switch(), Coogan, 09-Oct-09
    mapping jobs, *my_jobs;
    switch (args[0]) {
    case "list":
      args = map(args[1..], #'lower_case);
      jobs = JOB_SERVER->query_job_queue();
      if (sizeof(args) == 1 && args[0] == "all")
        args = m_indices(jobs);
      for (i = 0; i < sizeof(args); i++)
        if (this_player()->query_level() >= WL_ELDER)
          if (!(my_jobs = jobs[args[i]]))
            write(capitalize(args[i]) + 
                  " has no jobs running.\n");
          else {
            write("Jobs of " +
                  capitalize(args[i]) + ":\n");
            for (j = 0; j < sizeof(my_jobs); j++)
              write(my_jobs[j][J_NUMBER] + ": in <"+
                    to_string(my_jobs[j][J_HANDLER]) + 
                    "> call \"" +
                    my_jobs[j][J_FUNCTION] + "\" > " +
                    my_jobs[j][J_OUTPUT] + ".\n");
          }
        else
          write(capitalize(args[i]) + ": "+sizeof(jobs[args[i]])+" jobs.\n");
      if (!(my_jobs = jobs[this_player()->query_real_name()]))
        write("You have no jobs running.\n");
      else {
        write("Your jobs are:\n");
        for (i = 0; i < sizeof(my_jobs); i++)
          write(my_jobs[i][J_NUMBER] + ": in <" +
                to_string(my_jobs[i][J_HANDLER]) + 
                "> call \"" + 
                to_string(my_jobs[i][J_FUNCTION]) + 
                "\" > " + 
                my_jobs[i][J_OUTPUT] + "\n");
      }
      return 1;
      break;
    case "remove":
      if (!sizeof(args = map(args[1..], #'to_int))) {
        notify_fail("Usage: job remove {<number>}\n",-1);
        return 0;
      }
      if (this_player()->query_level() < WL_ELDER)
        JOB_SERVER->remove_jobs(args, this_player()->query_real_name());
      else
        JOB_SERVER->remove_jobs(args);
      write("Done.\n");
      return 1;
      break;
    default:
    }
  case "view": 
    if (!sizeof(args)) {
      this_player()->start_view();
      notify_fail("",-1);
      return 0;
    }
    for (i = 0; i < sizeof(args); i++)
      read_whole_file(args[i]);
    notify_fail("Please wait, reading files ... type \'view\' "
                "to read them!\n", -1);
    return 0;
  case "writefile":
    switch (sizeof(args)) {
    case 0:
      notify_fail("Usage: writefile <file> <text> (to append <text> to "+
                  "<file>)\n"+
                  "       writefile <file> (puts you into an insert-mode"+
                  " appending to the file)\n",-1);
      return 0;
    case 1:
      file = normalize_path(args[0], this_player());
      write("]");
      input_to("writefile_loop", 0, file);
      return 1;
    default:
      file = normalize_path(args[0], this_player());
      write_file(file, implode(args[1..], " ")+"\n");
      write("Ok, written to "+file+".\n");
    }
    return 1;
  case "read":
    return (POSTMASTER->
            get_clone_of(this_player()->query_real_name())->
            read_mail(implode(args," ")));
  case "mail":
    return (POSTMASTER->
            get_clone_of(this_player()->query_real_name())->
            mail(implode(args," ")));
  case "from":
    return (POSTMASTER->
            get_clone_of(this_player()->query_real_name())->
            show_headers(implode(args," ")));
    
  case "qserv":
    return SE_QUESTS->server_info(arg);
    
  case "apropos":
    if (!arg)  // Coogan, 28-Mar-2011
      return notify_fail("Syntax: apropos <pattern>\n",-1), 0;
    h=LIB_MANUAL->get_matching_manpages(arg);
    this_player()->view_text(h,"apropos "+arg);
    this_player()->start_view();
    return 1;

  case "man":
    if (!arg)
      return notify_fail("Syntax: man <pattern>\n",-1), 0;
    h=LIB_MANUAL->get_matching_manpages("^"+arg+"\\>");
    if (!sizeof(h)) {
      h=LIB_MANUAL->get_matching_manpages(arg);
      if (!sizeof(h))
        return notify_fail("Not found, sorry.\n",-1), 0;
      else if (sizeof(h)==1) {
        h=LIB_MANUAL->get_manpage(h[0]);
        this_player()->view_text(read_file(h),h);
        this_player()->make_search_string(arg);  // Alfe 1997-Jan-29
        this_player()->start_view();
      }
      else {
        this_player()->view_text("Not found, alternatives:\n"+
                                 implode(h,"\n")+"\n","man "+arg+
                                 ", alternatives");
        this_player()->make_search_string(arg);  // Alfe 1997-Jan-29
        this_player()->start_view();
      }
    }
    else {
      h=LIB_MANUAL->get_manpage(h);
#if 1  // Alfe 2002-Oct-16
      map(h, (: this_player()->view_text(limited(lambda(0,({#'read_file,$1})),
                                                 LIMIT_FILE, 100000), $1) :));
#else
      map(h,lambda(({ 'file }),
                         ({ symbol_function("view_text",this_player()),
                            ({ #'read_file,'file }),
                            'file })));
#endif
      this_player()->make_search_string(arg);  // Alfe 1997-Jan-29
      this_player()->start_view();
    }
    return 1;
      
  case "how":
  case "howto":
    if (!arg)
      return notify_fail("Syntax: howto <keyword> <keyword> ...\n",-1), 0;
    h=LIB_MANUAL->get_matching_howtos(arg);
    if (!sizeof(h)) {
      write(break_string("Nothing matches, sorry. If you want to formulate a"
                         " proper query, this will be logged. You would help"
                         " us by doing this.\n"
                         "If you do not want to, just type return.\n"
                         "Proper query: "));
      input_to("howto_query");
      return 1;
    }
    else {
      h=LIB_MANUAL->get_howto(h);
      map(h,lambda(({ 'file }),
                         ({ symbol_function("view_text",this_player()),
                            ({ #'read_file,'file }),
                            'file })));
      this_player()->start_view();
    }
    return 1;

  case "board" :
    return "/bin/sub/board_util"->board(arg);    // Carador, Mar-1996

  case "research":
    if (!arg)
      return notify_fail("Syntax: research <player>\n", -1), 0;
    h = FINGERD->load_player(arg);
    if (!h)
      return notify_fail("No such player found\n", -1), 0;
    h = h->query_history();
    if (!h) {
      write("Sorry, this player has no history yet.\n");
      return 1;
    }
    if (!pointerp(h)) {
      write("Internal error: history is no array\n");
      return 1;
    }
    h = implode(map(h, #'history_entry_to_string), "\n") + "\n";
    this_player()->view_text(h, "history of " + arg);
    this_player()->start_view();
    return 1;
  }
  return 0;   // default case
}

static void howto_query(string input) {
  if (input=="")
    return write("Ok, nothing logged.\n"), 0;
  log_file("HOW_TO",ctime()+": "+this_player()->query_vis_name()+": "+input+
           "\n");
  write("Thank you for your help.\n");
}

