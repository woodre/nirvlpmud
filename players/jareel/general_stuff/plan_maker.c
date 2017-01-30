#include "/players/jareel/ansi.h"
#define PLAN "/open/pub_plans/jareel.plan"

void reset(status arg) {
  if (arg) { destruct(this_object()); return; }

  write_file(PLAN, HIB+"OoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO\n"+NORM);
  write_file(PLAN, HIB+"OoO                   "+HIK+"Jareel's World"+HIB+"                    OoO\n"+NORM);
  write_file(PLAN, HIB+"OoO                                                     OoO\n"+NORM);
  write_file(PLAN, HIB+"OoO    "+HIK+"In Game        In the Works      Future Plan     "+HIB+"OoO\n"+NORM);
  write_file(PLAN, HIB+"OoO  "+HIG+"Hendrikville     "+HIK+"Dark Tunnels     "+NORM+BOLD+"Hero Questing    "+HIB+"OoO\n"+NORM);
  write_file(PLAN, HIB+"OoO   "+NORM+GRN+"Chaos Wood      "+NORM+BOLD+"Legend Mobs     "+NORM+RED+"The Luner Empire"+HIB+"  OoO\n"+NORM);
  write_file(PLAN, HIB+"OoO  "+NORM+BOLD+"Legends Area"+HIB+"                                       OoO\n"+NORM);
  write_file(PLAN, HIB+"OoO                                                     OoO\n"+NORM);
  write_file(PLAN, HIB+"OoO                   "+HIK+"Guild Plan"+HIB+"                        OoO\n"+NORM);
  write_file(PLAN, HIB+"OoO    "+NORM+BOLD+"A base guild that changes the fundamental"+HIB+"        OoO\n"+NORM);
  write_file(PLAN, HIB+"OoO        "+NORM+BOLD+"rules of nirvana as you know it"+HIB+"              OoO\n"+NORM);
  write_file(PLAN, HIB+"OoO             "+HIK+"Guild Gods/Demi-Gods"+HIB+"                    OoO\n"+NORM);
  write_file(PLAN, HIB+"OoO     "+NORM+BLU+"Orlanth--------- The god of the Storm "+HIB+"          OoO\n"+NORM);
  write_file(PLAN, HIB+"OoO     "+HIK+"Humakt---------- The God of Death"+HIB+"               OoO\n"+NORM);
  write_file(PLAN, HIB+"OoO     "+HIY+"Yelmalio-------- The Sun Dome God"+HIB+"               OoO\n"+NORM);
  write_file(PLAN, HIB+"OoO     "+HIR+"The Crimson Bat- Demi-God of the Red-Goddess"+HIB+"    OoO\n"+NORM);
  write_file(PLAN, HIB+"OoO     "+HIK+"Zorak Zoran----- Undead Troll Death God"+HIB+"         OoO\n"+NORM);
  write_file(PLAN, HIB+"OoO                                                     OoO\n"+NORM);
  write_file(PLAN, HIB+"OoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO\n"+NORM);
  write_file(PLAN, NORM+"\n"+NORM);
  destruct(this_object());
}


