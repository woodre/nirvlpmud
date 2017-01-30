#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("master")) {
        object wea;
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","master");
       call_other(own,"set_short","Dungeon Master");
       call_other(own,"set_long","The Almighty Dungeon Master.\n");
       call_other(own,"set_alias","dungeon master");
       call_other(own,"set_hp",525);
       call_other(own,"set_ac",12);
       call_other(own,"set_wc",19);
       call_other(own,"set_level",17);
       call_other(own,"set_al",25);
       call_other(own,"set_chat_chance",23);
       call_other(own,"load_chat","Master says: my blade is VERY powerful in the  right place!!!\n");
       move_object(own,this_object());
        wea=clone_object("obj/weapon");
         call_other(wea,"set_name","blade");
         call_other(wea,"set_short","The Dungeon Master's Blade");
         call_other(wea,"set_class",15);
         call_other(wea,"set_value",1500);
         call_other(wea,"set_weight",4);
         call_other(wea,"set_hit_func",this_object());
         move_object(wea,own);
   }
 }
  ONE_EXIT("players/haji/king/dungeon/stair1.c", "east",

    "A dungeon",
      "This is a dungeon to the east is a stairway.\n",1)
  realm(){return "harem";}
weapon_hit() {
    if(call_other(environment(this_player()),"realm")=="harem") {
         write("You feel the blade power up and watch with\n");
         write("glee as the blade slams into its opponent!!!\n");
         return 5;
      }
 }
