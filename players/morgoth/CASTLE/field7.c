#include "std.h"

object cyclops, money, mace;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
if (!cyclops || !living(cyclops)) {
    money = clone_object("obj/money");
    money->set_money(random(3000));
    cyclops = clone_object("obj/monster.talk");
    call_other(cyclops, "set_name", "cyclops");
    call_other(cyclops, "set_level", 20);
    call_other(cyclops, "set_hp", 600);
    call_other(cyclops, "set_short", "A Cyclops");
    call_other(cyclops, "set_long", "A fierce looking cyclops stands\n"
              +"before you.  You are not sure what sex it is with all\n"
              +"that hair hanging from it.  The cyclops doesn't look\n"
              +"happy that you have entered it's domain.  You can see\n"
              +"bits of flesh and blood in it's beard and hair... You\n"
              +"decide to scream !!!\n");
    call_other(cyclops, "set_ac", 17);
    call_other(cyclops, "set_wc", 30);
    call_other(cyclops, "set_chat_chance", 50);
    call_other(cyclops, "load_chat", "SNIFF SNIFF...\n");
    call_other(cyclops, "load_chat", "Oh good, another adventurer to pulverize !!\n");
    call_other(cyclops, "load_chat", "AAARHHHHGGG !!!\n");
    mace = clone_object("players/morgoth/WEAPONS/mace");
    move_object(money, cyclops);
    move_object(mace, cyclops);
    move_object(cyclops, this_object());
   }
  }

ONE_EXIT("players/morgoth/CASTLE/Efield14", "east",
   "The Cyclops realm",
   "You find yourself standing before a huge hair covered\n"
  +"cyclops.  As you look around you see the rotting corpses\n"
  +"and skeletons of the poor adventurers foolish enough to\n"
  +"confront 'it'..  Your face winces at the awful stench\n"
  +"this creature exudes..  It is then you notice with terror\n"
  +"the huge blood covered mace it is carrying...\n", 1)


query_temp() { return 2; }
