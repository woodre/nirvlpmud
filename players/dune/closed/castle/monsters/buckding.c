inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   if (!present("map"))
   {
      move_object(clone_object(CASTLEOBJECT+"/map.c"),
                  this_object());
   }

   ::reset(arg);
   if(arg) return;
   set_name("Billy");
   set_alias("billy");
   set_short("Billy Buckding");
   set_level(11);
   set_race("human");
   set_hp(random(20)+165);
   set_wc(16);
   set_ac(10);
   set_long(
"     Billy Buckding is a silly disheveled old man.\n"+
"He wears torn suspenders which his long hair mostly obscures.\n"+
"Billy looks a bit out of place in Lothlorien, perhaps he is a\n"+
"traveler just like you.\n");
   set_chat_chance(25);
   load_chat(
"Billy Buckding says: I had seven scrolls and I ate one.\n");
   load_chat(
"Billy Buckding says: Did'ya see them Sithi folk? I hate'm!\n");
   load_chat(
"Billy Buckding says: Doctor Morgenes is out to get me!\n");
   load_chat(
"Billy Buckding says: You can't have my map, it's mine, my precious!!!\n");
   load_chat(
"Billy Buckding says: Stop looking at me. Noooo! Stop it!\n");
   set_al(0);
   set_move_at_reset();
}
