#include "/players/guilds/bards/def.h"

status main(string str) {
  object bpeep;
  object bobj;
  
  if (spell(-1000, 1, 0) == -1)
    return 0;
  if(!GOB->query_is_gc()) return 0;
  
  if(!str)
    FAIL("Toggle the freeze on who?\n");
  
  bpeep = find_living(str);
  
  if(!bpeep)
    FAIL("Target not found.\n");

  bobj = present("bard_obj", bpeep);

  if(!bobj)
    FAIL(NAME(bpeep)+" does not have an instrument.\n");
    
  if(bobj->query_locked()) {
    write(str+" is currently frozen by "+bobj->query_locked()+".\n");
    bobj->unlock();
    write("Unfrozen.\n");
  }  else {
    write("You freeze "+str+"'s powers.\n");
    bobj->set_locked(this_player()->query_real_name());
    write("Done.\n");
  }
  return 1;
}
