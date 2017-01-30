#include "../DEFS.h"

status main(string str) {
  object ob;
  int honor;

  if(!IPTP->guild_manager()) return 0;
  if(!str || !find_player(str) || 
     !present(GUILD_ID, find_player(str))) {
    write("Usage: view_honor <ninja>\n");
    return 1; }
  ob = find_player(str);
  honor = (int)IPOB->query_honor();
  write(OPN+"'s honor statistics...\n"+
        "Rank:         "+
        (string)call_other(HLEVELD, "honorTitle", honor)+"\n"+
        "Honor points: "+
        honor+"\n");
  return 1;
}
