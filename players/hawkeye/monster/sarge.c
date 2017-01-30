inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "sergeant" );
     set_alias("sergeant");
     set_short("A Sergeant");
       set_long("This is a sergeant in the army..watch out.\n");
     set_level(11);
     set_ac(9);
     set_wc(15);
     set_hp(165);
     set_al(-50);
     set_aggressive(0);
     set_chat_chance(1);
     set_a_chat_chance(20);
    load_chat("One of the Sergeants says 'Go away..we're busy.\n");
       load_chat("The sergeants beat the hell outta privates.\n");
    load_chat("One of the Sergeants says: Drop and give me twenty punk!.\n");
    load_chat("The sergeant says, 'You're a putz'\n");
    load_a_chat("Sergeant says 'Hey Buddy!'\n");
    load_a_chat("The Sergeant taunts you.\n");
    load_a_chat("A Sergeant pokes you in the ribs..\n");
    load_a_chat("A sergeant points at you and laughs!\n");
/* changed money from 550 to below in order to conform to regs and add
  a little variety in the returns from multiple monsters. -Snow */
     money = (random(200)+300);
   }
}

