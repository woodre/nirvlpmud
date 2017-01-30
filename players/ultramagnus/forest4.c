#include "room.h"
object elf1,elf2,cap;
#undef EXTRA_RESET
#define EXTRA_RESET\
extra_reset();
extra_reset() {
        if(!elf1 || !living(elf1)){
	  elf1 = clone_object("obj/monster");
          call_other(elf1, "set_name", "elf");
          call_other(elf1, "set_alias", "blue elf");
          call_other(elf1, "set_level", 10);
          call_other(elf1, "set_short", "A Blue Elf Pointing West");
          call_other(elf1, "set_wc", 10);
          call_other(elf1, "set_ac", 4);
          call_other(elf1, "set_hp", 150);
          call_other(elf1, "set_al", 300);
          call_other(elf1, "set_aggressive", 0);
        call_other(elf1, "set_chat_chance", 25);
       call_other(elf1, "load_chat", "Blue Elf says: There are Terrors in the West!!\n");
       call_other(elf1, "load_chat", "The Blue Elf frowns and Begins to weep...\n");
       call_other(elf1, "set_a_chat_chance", 50);
       call_other(elf1, "load_a_chat", "Blue Elf says: A Demon such as yourself Belongs in the West!\n");
       call_other(elf1, "load_a_chat", "Blue Elf says: Go Away!!!\n");
move_object(elf1, this_object());
       cap=clone_object("players/ultramagnus/cap.c");
       move_object(cap, elf1);
        }
         if(!elf2 || !living(elf2)){
           elf2 = clone_object("obj/monster");
           call_other(elf2, "set_name", "elf");
           call_other(elf2, "set_alias", "red elf");
           call_other(elf2, "set_level", 10);
           call_other(elf2, "set_short", "A Red Elf Pointing East");
           call_other(elf2, "set_wc", 5);
           call_other(elf2, "set_ac", 2);
           call_other(elf2, "set_hp", 100);
           call_other(elf2, "set_al", 300);
           call_other(elf2, "set_aggressive", 0);
         call_other(elf2, "set_chat_chance", 25);
       call_other(elf2, "load_chat", "Red Elf says: All Those seeking Refuge from The Dark Forces go East!!\n");
       call_other(elf2, "load_chat", "Red Elf says: For If a Man seeks Safety, Let him Find Hope in Minus Tirith!!!\n");
        call_other(elf2, "set_a_chat_chance", 50);
        call_other(elf2, "load_a_chat", "Red Elf says: Filth of the Mud!...I cannot let YOU go to Minus Tirith!\n");
        call_other(elf2, "load_a_chat", "Red Elf says: If I cannot stop you...Others there WILL!!\n");
move_object(elf2, this_object());
       cap=clone_object("players/ultramagnus/cap.c");
       move_object(cap, elf2);
         }
}
FOUR_EXIT("players/ultramagnus/forest3.c", "north",
           "players/ultramagnus/pathdown.c", "south",
           "players/ultramagnus/redforest.c", "east",
           "players/ultramagnus/blueforest.c", "west",
             "Split Path",
       "As you wanderer along the path, you come to a point where\n" +
       "it splits into several different directions. To the East\n" +
       "is a path that leads into the Red section of the forest.\n" +
       "To the West is a path that leads into the Blue section of\n" +
       "the forest. Looking to the south you notice that the \n" +
       "forest seems to lighten up a bit. The vivid Red and Blue\n" +
       "colors brightens the forest creating a nice purple line\n" +
       "in the middle of the path as you look north.\n" +
       "Even the grass and flowers begin to take on shades of Blue\n" +
       "and Red. There is certainly magic in the air here.\n", 1)
