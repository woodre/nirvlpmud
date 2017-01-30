#include "/players/francesco/univ/ansi.h"
inherit "obj/monster";

reset(arg){
  object kale;
  ::reset();
  if(arg) return;
   set_name("city-dweller");
   set_race("human");
   set_alias("city-dweller");
   set_gender("male");
     set_short(HIC+"A city-dweller"+NORM+"");
     set_long("The city-dweller is wearing an elegant suit.  His tie, his shoes\n"+
              "a pin on his jacket, they are all very fashioned items.  He wanders\n"+
              "around smiling and chats amiably with others.\n");
   set_level(5);
   set_hp(100);
   set_wc(7);
   set_ac(12);
   set_chat_chance(1);
   load_chat("The city-dweller whispers to his companion: Fantasy and I met during the first year of college.\n");
   load_chat("The city-dweller smiles, perhaps remembering the adventures he and Fantasy did together.\n");
   kale = clone_object("/players/francesco/wedding/invite.c");
   move_object(kale,this_object());
}

id(str) {return str=="city-dweller" ;}

