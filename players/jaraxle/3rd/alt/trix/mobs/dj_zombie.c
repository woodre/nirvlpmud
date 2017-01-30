#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
   object fucked,record;
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("zombie");
   set_race("zombie");
   set_alias("dj");
   set_short("The DJ"+RED+"("+BLK+BOLD+"zombie"+NORM+RED+")"+NORM);
   set_long("An eccentric dj , a creature of the night , he's in his environment , he's HUGE.\n");
   set_level(20);
   set_hp(500);
   set_al(1000);
   set_wc(30);
   set_ac(17);
   set_aggressive(0);
   set_chat_chance (14);
   load_chat("DJ says: techno techno techno techno.\n");
   load_chat("DJ says: boom boom boom.\n");
   load_chat("DJ looks at the crowd dancing and grins.\n");
   set_chance(7);
   set_spell_dam(random(5)+2);
   set_spell_mess1("DJ pushes you.");
   set_spell_mess2("DJ throws a record to you.");
   record=clone_object("players/trix/castle/dismonst/record.c");
   move_object(record,this_object());
}

init(){
   ::init();
   if (this_player()->is_player()) fucked = this_player();
}

heart_beat(){
   object here, there;
   here = environment(this_object());
   there = environment(fucked);
   ::heart_beat();
   if(here != there){
      move_object(this_object(), environment(fucked)); 
      say("A zombie DJ rushes in to the room!\n");
   }
   
}
