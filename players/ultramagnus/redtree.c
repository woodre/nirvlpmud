#include "room.h"
object gem,elf, dwarf;
object sack,apple;
#undef EXTRA_RESET
#define EXTRA_RESET\
extra_reset();
extra_reset()
{
int i;
i = 0;
       if(!elf || !living(elf)){
        while(i<2){
        i += 1;
         elf=clone_object("obj/monster");
         call_other(elf, "set_name", "elf");
         call_other(elf, "set_alias", "red elf");
         call_other(elf, "set_level", 4);
         call_other(elf, "set_short", "An Elf dressed in Red");
        call_other(elf, "set_long",
              "A small elf dressed in Red picking apples.\n"+
              "He looks quite happy doing his work.\n");
         call_other(elf, "set_wc", 3);
         call_other(elf, "set_ac", 2);
         call_other(elf, "set_hp", 60);
         call_other(elf, "set_al", 200);
         call_other(elf, "set_aggressive", 0);
         call_other(elf, "set_chat_chance", 25);
         call_other(elf, "load_chat",
                     "elf says: Hello! Care for an Apple?\n");
         call_other(elf, "load_chat",
                     "elf says: It is best if you pick the apples here.\n");
         call_other(elf, "load_chat",
                     "elf says: One takes a Risk by going higher to work!\n");
        call_other(elf, "set_a_chat_chance", 50);
        call_other(elf, "load_a_chat", "elf says: Please Stop! ... Be Peaceful in the Red Forest!\n");
        call_other(elf, "elf says: I only wish to pick apples...!!!...\n");
         move_object(elf, this_object());
       gem=clone_object("players/ultramagnus/rdiamond.c");
       move_object(gem, elf);
       apple=clone_object("players/ultramagnus/apple.c");
       sack=clone_object("players/ultramagnus/rsack.c");
        move_object(apple, this_object());
       move_object(sack, elf);
      }
       }
      i = 0;
       if(!dwarf || !living(dwarf)){
       while(i<2){
        i += 1;
         dwarf=clone_object("obj/monster.talk");
         call_other(dwarf, "set_name", "dwarf");
         call_other(dwarf, "set_alias", "red dwarf");
         call_other(dwarf, "set_level", 4);
         call_other(dwarf, "set_short", "A Dwarf dressed in Red");
       call_other(dwarf, "set_long",
              "A small dwarf dressed in red.\n"+
              "He seems to work while keeping an eye\n"+
              "on the branches above.\n");
         call_other(dwarf, "set_wc", 3);
         call_other(dwarf, "set_ac", 2);
         call_other(dwarf, "set_hp", 60);
         call_other(dwarf, "set_al", 200);
         call_other(dwarf, "set_aggressive",0);
        call_other(dwarf, "set_chat_chance", 25);
        call_other(dwarf, "load_chat", "dwarf says: Take an apple...\n");
        call_other(dwarf, "load_chat", "dwarf says: Eat one now or save it for later.\n");
        call_other(dwarf, "load_chat", "dwarf says: Be Very careful if you go above!\n");
         call_other(dwarf, "set_a_chat_chance", 50);
        call_other(dwarf, "load_a_chat", "dwarf says; Why do you do this to me...??!!\n");
        call_other(dwarf, "load_a_chat", "dwarf says; I meant You No Harm...!!!\n");
         move_object(dwarf, this_object());
       gem=clone_object("players/ultramagnus/rdiamond.c");
       move_object(gem, dwarf);
       }
       }
}
TWO_EXIT("players/ultramagnus/rforest1.c", "down",
         "players/ultramagnus/redweb.c", "up",
        "Red Tree",
        "You are climbing a red tree.  There are Plump, and Juicy\n" +
        "Apples here...Begging to be eaten.  Many elves and dwarves often come\n" +
        "here and pick them so that they may sell them in the Red City.\n" +
        "There seems to be some rather LARGE Webbing hanging from the\n" +
        "tree limbs up above.  It may be sticky like that of a spiders web.\n", 1)
