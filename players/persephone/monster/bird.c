inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset (arg){
 ::reset(arg);
  if(!arg){
   object beak;
   beak = clone_object("players/persephone/obj/beak");
   move_object(beak, TOB);
   init_command("wield beak");
   set_name("woodpecker");
   set_short("A Peaceful Woodpecker");
   set_long("A Beautiful Woodpecker who is minding its own business\n" +
            "building a nest in one of the trees.\n\n");
   set_level (3);
   set_wc(6);
   set_ac(3);
   set_hp(40);
   set_al(0);
   set_aggressive(0);
   set_gender(0);
   set_chat_chance(35);
    load_chat("The Woodpecker starts pecking into one of the trees.\n");
    load_chat("Woodpecker knocks: Tap! Tap! Tap!\n");
    load_chat("The Woodpecker flies around looking for a good tree.\n");
  }
}
