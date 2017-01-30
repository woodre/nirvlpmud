#include "/players/feldegast/defines.h"

inherit "/players/feldegast/std/monster2.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("djinn");
  set_alt_name("");
  set_short("A fearsome "+HIY+"Djinn"+NORM);
  set_long(
"This djinn takes the form of an eight foot tall, muscular man with\n"+
"green skin and four arms.  His body is completely hairless, and\n"+
"his face appears alien and cold.  The eyes appear fierce, intelligent,\n"+
"and completely insane.\n"
  );
  set_gender("male");
  set_race("demon");
  set_level(20);
  set_wc(31);
  set_ac(16);
  set_hp(550);
  set_al(-450);
  load_spell(10,35,0,
    HIR+"\nThe djinn spits flames from his mouth!\n\n"+NORM,
    HIR+"\nThe djinn spits flames at %NAME%!\n\n"+NORM);
 load_spell(10,20,"other|fire",
    HIY+"\nThe djinn backhands you with his flaming fist!\n\n"+NORM,
    HIY+"\nThe djinn backhands %NAME% with his flaming fist!\n\n"+NORM);
  add_special("hb_aggro", ({ 50, 2 }));
  add_special("area_attack",
    ({
      10,25,
      GRN+"You choke on the green mist!\n"+NORM,
     GRN+"\nThe djinn summons a green mist!\n"+NORM,
      "other|poison", 2,
    }));
  add_special("spell_drain",
    ({
      15, 10, "The djinn drains a piece of your soul!\n",
      "The djinn drains a piece of %NAME%'s soul!\n"
    })
  );
}
