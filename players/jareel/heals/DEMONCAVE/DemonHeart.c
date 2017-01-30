/* 
 Second nirvana demon lore item...Hearts from Zeus
 great non-toxing heal, also makes player more evil */

inherit "obj/treasure.c";
#include "/players/jareel/define.h"
#include "/players/jareel/ansi.h"
#define TQL  (int)this_player()->query_level()
#define TQA  (int)this_player()->query_alignment()

int bites;

reset(arg) {
  if(arg) return;

  no_clean = 1;
  bites = 3;

  set_short(RED+"A demons heart"+NORM);
}
id(str){ return str == "heart" || str == "demons heart";  }

long(){    write(
  "This is a bloody demons heart.  It is the center of evil which brought\n"+
  "a demon into this world.  It beats with a disgusting sound that haunts\n"+
  "your ears endlessly.  You could 'eat' the heart to harness its powers.\n"+
  "The demons heart is a rare item and can also be 'barter'ed for money.\n");
  if(bites < 3)
    write("There are a few bites missing from the demons heart.\n");
}

  query_save_flag(){      return 1;       }
  query_value(){          return 150; }
  get(){                  return 1;       }
  query_weight(){         return 1;       }

  void init(){ ::init(); add_action("eat_cmd", "eat");  }
  query_bites(){          return bites; }

  status eat_cmd(string str){
    if(!str) return 0;
    if(environment(this_object()) != this_player()) return 0;
    if(str != "heart" && str != "demons heart") return 0;
      write("You take a bite out of the demons heart...\n"+
        "The blood of the demon races through your veins...\n");
          bites -= 1;
    if(TQL != 30)
      this_player()->add_alignment((TQA * 2 / (30 - TQL) - (TQL * 6)));
      this_player()->heal_self(85+random(25));
    if(!bites){
      write(RED+"You eat the last of the demons heart.\n"+NORM);
        local_weight = 0;
      this_player()->recalc_carry();
        destruct(this_object());
    }
    return 1;
}

  is_heal(){ return 1; }
  query_charges() { return bites; }