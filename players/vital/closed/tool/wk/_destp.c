#include <ansi.h>

main(str) {
  string who, what;
  object w, ob;
  if(!str || sscanf(str, "%s %s", who, what) != 2) {
    write("Usage: destp <who> <what>\n");
    return 1;
  }
  if(!(w = find_player(who))) {
    write("Player not found.\n");
    return 1;
  }
  /* please don't use as a standard - it's pretty hefty */
  /* this is just here for extreme cases */
  if(what[0] == 'F')
    return complex_dest(w, what);
  if(!(ob = present(what, w))) {
    write("Object not present.\n");
    return 1;
  }
  write("Destructing "+file_name(ob)+" from "+capitalize(who)+"'s inventory.\n")
;
  tell_object(w, "Something is missing...\n");
  destruct(ob);
  return 1;
}
complex_dest(w, what) {
  string blah;
  object ob;
  sscanf(what, "F%s", what);
  if(!what) return 0; /* handle 1 char string */
  if(what[0] != '/') what = this_player()->get_path()+what;
  sscanf(what, "/%s", what);
  ob = first_inventory(w);
  while(ob) {
    if(sscanf(file_name(ob), what+"%s", blah)) {
      write("Destructing "+what+" from "+w->query_name()+"'s inventory.\n");
      tell_object(w, "Something is missing...\n");
      destruct(ob);
      return 1;
    } else
      ob = next_inventory(ob);
  }
  write("Object not present.\n");
  return 1;
}

get_help()
{
  string help;
  help = "Syntax: [F]destp <who> <object>";
  return help;
}