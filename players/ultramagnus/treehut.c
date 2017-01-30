#include "std.h"
object elf, dwarf, berries, gem, sign, hut;
#undef EXTRA_INIT
#define EXTRA_INIT\
       add_action("enter","enter");
#undef EXTRA_RESET
#define EXTRA_RESET\
extra_reset();
extra_reset()
{
int i;
i=0;
       if(!elf || !living(elf)){
              while(i<3){
              i += 1;
              elf=clone_object("obj/monster.c");
              call_other(elf, "set_name", "elf");
              call_other(elf, "set_alias", "blue elf");
              call_other(elf,"set_level",1);
              call_other(elf, "set_short", "An Elf Dressed in Blue");
              call_other(elf, "set_long",
                     "An Elf Dressed in Blue.  He is waiting in line for something.\n");
              call_other(elf,"set_wc",5);
              call_other(elf,"set_ac",3);
              call_other(elf, "set_hp", 45);
              call_other(elf, "set_al", 100);
              call_other(elf, "set_aggressive", 0);
              move_object(elf, this_object());
              }
       }
       i=0;
              if(!dwarf || !living(dwarf)){
              while(i<3){
              i += 1;
              dwarf=clone_object("obj/monster.c");
              call_other(dwarf, "set_name", "dwarf");
              call_other(dwarf, "set_alias", "blue dwarf");
              call_other(dwarf, "set_short", "An Dwarf Dressed in Blue");
              call_other(dwarf, "set_long",
                     "A Dwarf Dressed in Blue.  He is waiting in a line.\n");
              call_other(dwarf,"set_level",1);
              call_other(dwarf,"set_wc",5);
              call_other(dwarf,"set_ac",3);
              call_other(dwarf, "set_hp", 45);
              call_other(dwarf, "set_al", 100);
              call_other(dwarf, "set_aggressive", 0);
              move_object(dwarf, this_object());
              }
       }
       i=0;
       if(!present("berries")){
       while(i<2){
              i += 1;
              berries=clone_object("players/ultramagnus/berries.c");
              move_object(berries, this_object());
       }
       }
       if(!present("sign")){
       sign=clone_object("players/ultramagnus/boffice_sign.c");
       move_object(sign, this_object());
       }
       if(!present("hut")){
       hut=clone_object("players/ultramagnus/boffice.c");
       move_object(hut, this_object());
       }
}
ONE_EXIT("players/ultramagnus/bluetree.c", "east",
        "Blue Hut",
        "Standing on a limb you see a small Blue Hut.  There are several\n" +
        "glittering stones lying about in the leaves.  They may have some\n" +
        "value.  Looking at the other trees in the Blue forest you see\n" +
       "the same activity as in the tree that you are in.  There is\n" +
       "a Sign by the door of the Hut.\n", 1)
enter(){
       if(present("elf")){
       write("Elf says: Excuse me!  I was ahead of you.\n");
       return 1;
       }
       if(present("dwarf")){
       write("Dwarf says: Excuse me! I was ahead of you in line.\n");
       return 1;
       }
     call_other(this_player(), "move_player", "in#players/ultramagnus/blueoffice.c");
       return 1;
}
