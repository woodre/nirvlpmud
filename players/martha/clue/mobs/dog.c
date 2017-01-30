#include <ansi.h>

inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) return;
      
      set_name("dog");
      set_race("canine");
      set_short(HIB+"A Dog"+NORM);
      set_long(
	"   This is a doberman pinscher.  He is black with brown markings.\n"+
"He looks really pissed that you have disturbed his sleep during this\n"+
"scary thunderstorm.  His ears are perked up and he is barking like mad.\n"+
"When he opens his mouth to snarl at you, his sharp pointy teeth gleam\n"+
"in the lightning.  Luckily he has a chain hooked to his collar that\n"+
"will slow down the rate at which he can attack someone.\n");
        set_level(10);
        set_ac(8);
        set_wc(14);
        set_hp(150);
        set_al(-500);
        set_chat_chance(10);
        set_a_chat_chance(10);
        
        load_chat("The dog bears its teeth.\n");
        load_chat("'Grrrrr'\n");
        load_chat("'Woof! Woof! Arf! Arf!'\n");
        load_a_chat("The dog jumps up and"+GRN+" B I T E S"+NORM+" your arm!\n");
  /*move_object(clone_object("/players/martha/clue/heals/bone.c"), this_object());
	move_object(clone_object("/players/martha/clue/weps/collar.c"), this_object());
	init_command("wear collar"); */

}

