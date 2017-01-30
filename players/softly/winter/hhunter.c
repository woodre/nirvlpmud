#include "/players/softly/misc/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
move_object(clone_object("/players/softly/winter/hblade.c"),this_object());  

   set_name("hunter");
   set_alt_name("Hunter");   
   set_alias("hunter");
   set_long("A large thin man strides through the forest.  He has a long\n"+
            "hunting knife in his hand and is clearly hungry.\n");
  set_short("A hungry hunter");
   set_type("human");
   set_level(15);
   set_wc(20);
   set_ac(13);
   set_hp(250);
   set_al(0);
   set_aggressive(0);
   add_money(100+random(101));
   set_chat_chance(20);
   load_chat("The hunter warns: There is great danger near the cabin.\n");
   load_chat("The hunter says: The wolf near the cabin is unnatural somehow.\n");
   load_chat("The hunter whispers: Stay away from the cabin.\n");
}
