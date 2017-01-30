#pragma strong_types            // Coogan, 18-Oct-2010

#include <kernel.h>
#include <etc.h>                // finger.h to etc.h, Coogan, 18-Oct-2010

inherit ACCESS;
inherit "basic/name";

private static string initial;
private        mapping banished;
private static mapping cache;

string banish(string name, string by) {
  if (!SECURITY->query_is_wizard(by))
    return by+" is not a wizard";
  if (!valid_name(name))
    return name+" is not a valid character name";
  name = to_real_name(name);
  if (ETC_FINGERD->load_player(name))
    if (!SECURITY->query_is_admin(by))
      return name+" is already used by a player";
    else {
      write("Warning: "+name+" is used by a player!\n");
      log_file("BANISH",ctime(time())+": "+name+" banished by "+by+"\n");
    }
  if (!check_previous_privilege(by))
    return "insufficient privilege";
  if (initial != name[0..0]) {
    initial = 0;
    banished = 0;
    restore_object("/save/banish/"+name[0..0]);
    initial = name[0..0];
  }
  if (!banished)
    banished = ([ ]);
  if (banished[name])
    return name+" already banished by "+banished[name];
  banished[name] = by;
  unguarded(1,#'save_object,"/save/banish/"+initial);
  return 0;
}

string query_banished(string name) {
  if (!valid_name(name))
    return 0;
  name = to_real_name(name);
  if (name[0..0]!=initial) {
    initial = 0;
    banished = 0;
    restore_object("/save/banish/"+name[0..0]);
    initial = name[0..0];
  }
  if (!banished)
    banished = ([ ]);
  return banished[name];
}

string unbanish(string name) {
  string banisher;
  banisher = query_banished(&name);
  if (!banisher)
    return name+" is not banished";
  if (!check_previous_privilege(banisher))
    return "insufficient privilege";
  if ("etc/fingerd"->load_player(name))
    log_file("BANISH",ctime(time())+": "+name+" unbanished by "+
             (this_player() ? this_player()->query_real_name() : 
              object_name(previous_object()))+"\n");
  m_delete(banished,name);
  unguarded(1,#'save_object,"/save/banish/"+initial);
  return 0;  // Coogan, 26-Mar-2011
}

