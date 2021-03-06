#include "../DEFS.h"
#define LEVEL  5

status main(string str) {
  int b, level, pk, xlev;
  string gname, room;
  object * ob;

  if(!gotrank(TP, LEVEL)) return 0;
  write("\n");
  write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
        "~~~~~~~~~~~~~\n");
  write(BOLD+YELLOW);
  write("Player          Level    Guild         Location\n");
  write(OFF);
  write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
        "~~~~~~~~~~~~~\n");

  ob = users();
  for(b=0;b<sizeof(ob);b+=1)  {
    if(!(ob[b]->query_invis() > this_player()->query_level())) {
      if(ob[b]->query_invis() && ob[b]->query_level() >= this_player()->query_level()) continue;
      level = (int)ob[b]->query_level();
      xlev  = (int)ob[b]->query_extra_level();
      gname = (string)ob[b]->query_guild_name();
      pk    = (status)ob[b]->query_pl_k();
      if(environment(ob[b]))
        room = (string)environment(ob[b])->short();
      if(!room) room = "unknown";
      if(level >= 12 && level < 20) {
        if(pk) 
          write(RED+pad(capitalize((string)ob[b]->query_name()),15)+OFF);
        else 
          write(pad(capitalize((string)ob[b]->query_name()),15));
        write(" ");
        if(!xlev) write(pad(level,6));
        else write(pad(level+"+"+xlev,6));
        write(" ");
        if(gname) {
          if(gname == GUILDNAME)
            write(BOLD+pad(capitalize(GUILDNAME),15)+OFF);
          else write(pad(gname, 15)); 
        }
        else write(pad("none", 15));
      write(" ");
      if(environment(ob[b])) {
      if((string)ob[b]->query_fight_area() == 
      file_name(environment(ob[b])))
        write(RED+"->"+OFF+room);
      else write(room);
      }
      else write(room);
      write("\n");
      }
    }
  }
  write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"+
        "~~~~~~~~~~~~~~~\n\n");
  return 1;
}
