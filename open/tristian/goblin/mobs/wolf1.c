inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/tristian/lib/goblin_define.h"
int pelt;

reset(arg){

 ::reset(arg);
  if(arg) return;

  set_name("Wolf");
  set_race("wolf");
  set_alias("wolf");
  set_short("A maurding wolf");
  set_long("A beautiful silver grey wolf.\n");
  set_level(5);
  set_ac(5);
  set_wc(9);
  set_hp(65);
  set_al(-100);
  set_aggressive(1);
  set_a_chat_chance(15);
      load_a_chat("The wolf snarles.\n");
      load_a_chat("\nThe wolf raises its muzzle to the sky.\n"+
                  "\nHooooooooooooowwwwwlllllll\n\n");
  set_dead_ob(this_object());



}

  monster_died(){
      tell_room(environment(this_object()),
          "You quickly skin the wolf after it falls to the ground.\n");
  pelt=clone_object("/players/tristian/realms/goblin/obj/wolfpelt.c");
      move_object(pelt,this_object());

      return 0;
    }