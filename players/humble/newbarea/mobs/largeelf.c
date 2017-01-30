inherit "/obj/monster.c";

#include "../defs.h"
reset(arg) {
   ::reset(arg);
   if(arg) return;
    move_object(clone_object("/players/humble/newbarea/items/elvendagger.c"));
    move_object(clone_object("/players/humble/newbarea/items/elvenboots.c"));
    move_object(clone_object("/players/humble/newbarea/items/elvenshield.c"));
    init_command("wear boots");
    init_command("wear shield");
    init_command("wield dagger");
    set_name(GRN+"An Adult Elf"+NORM);
    set_short(GRN+"An Adult Elf"+NORM);
    set_alias("elf");
    set_alt_name("elf");
   set_long(
    "This is an adult elf with a lean, muscular build. He walks standing\n"+
    "straight up with pride. You are a stranger in his land and if I was\n"+
    "you I'd be very weary.\n");
    set_gender("male");
    set_race("elf");
    set_level(13);
    set_hp(185+random(15));
    set_wc(17);
    set_ac(10);
    add_money(300+random(150));
    set_chat_chance(5);
    set_a_chat_chance(4);
     load_chat(GRN+"Large Elf says:"+NORM+" My ancestors have lived here all their life.\n");
     load_a_chat(GRN+"Large Elf says:"+NORM+" I will do whatever it takes to protect my people.\n");
}
