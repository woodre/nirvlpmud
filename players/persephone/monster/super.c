inherit "obj/monster";
#include "/players/persephone/rooms.h"
object whip;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      whip = clone_object("players/persephone/weapon/whi");
      move_object(whip, TOB);
      init_command("wield whip");
      set_name("supervisor");
      set_alias("foreman");
      set_alias("man");
      set_alias("boss");
      set_short("A Workgang Supervisor");
      set_long("Possibly one of the cruelest bosses you hsve\n"+
               "ever seen he is shouting out orders to the workers.\n");
      set_level (16);
      set_wc (22);
      set_ac (13);
      set_hp(400);
      set_al(-50);
      set_aggressive(0);
      set_gender ("male");
      set_chat_chance(20);
      load_chat("Supervisor shouts: Come on sluggards move it\n".);
      load_chat("Supervisor scowls: Not like that show some muscle\n");
      load_chat("Supervisor shouts: I can find other workers\n");
      load_chat("Supervisor says: What are you doing standing around work!!\n");
}

