#include "room.h"
object gem,elf,dwarf;
object sack, berries;
#undef EXTRA_RESET
#define EXTRA_RESET\
extra_reset();
extra_reset()
{
int i;
i=0;
       if(!elf || !living(elf)){
         while(i<2){
              i +=1;
              elf=clone_object("obj/monster");
              call_other(elf, "set_name", "elf");
              call_other(elf, "set_alias", "blue elf");
              call_other(elf, "set_level", 7);
             call_other(elf, "set_short", "An Elf Dressed in Blue");
              call_other(elf, "set_long",
                     "An elf dressed in Blue. He seems quite happy.\n"+
                     "He is busy picking Blue Berries. There seems to be\n"+
                     "something very shiny in his pocket.\n");
              call_other(elf, "set_wc", 3);
              call_other(elf, "set_ac", 2);
              call_other(elf, "set_hp", 100);
              call_other(elf, "set_al", 200);
              call_other(elf, "set_aggressive", 0);
              move_object(elf, this_object());
              gem=clone_object("players/ultramagnus/bdiamond.c");
              move_object(gem, elf);
            }
       }
       i=0;
       if(!dwarf || !living(dwarf)){
              while(i<2){
              i +=1;
              dwarf=clone_object("obj/monster");
              call_other(dwarf, "set_name", "dwarf");
              call_other(dwarf, "set_alias", "blue dwarf");
              call_other(dwarf, "set_level", 7);
              call_other(dwarf, "set_short", "A Dwarf Dressed in Blue");
              call_other(dwarf, "set_long",
                     "A dwarf dressed in blue. He is busy picking Blue Berries.\n");
              call_other(dwarf, "set_wc", 3);
              call_other(dwarf, "set_ac", 2);
              call_other(dwarf, "set_hp", 100);
              call_other(dwarf, "set_al", 200);
              call_other(dwarf, "set_aggressive", 0);
              move_object(dwarf, this_object());
              gem=clone_object("players/ultramagnus/bdiamond.c");
              move_object(gem, dwarf);
            berries=clone_object("players/ultramagnus/berries.c");
            move_object(berries, this_object());
            sack=clone_object("players/ultramagnus/bsack.c");
            move_object(sack, dwarf);
              }
       }
}
TWO_EXIT("players/ultramagnus/bforest1.c", "down",
         "players/ultramagnus/treehut.c", "west",
         "Blue Tree",
         "You have climbed into the Blue Tree.  Elves and Dwarves tailored\n" +
         "in little blue outfits are working about like humming birds picking\n" +
         "Blue Plumbs to sell in the Blue City.  With the greatest of ease\n" +
         "they spring from limb to limb gathering fruit.  It is a good thing\n" +
         "that the tree is sturdy or you would have fallen to the ground.\n" +
         "To the west you see a small hut with some ot these tiny wokers\n" +
         "standing in a line.\n", 1)
