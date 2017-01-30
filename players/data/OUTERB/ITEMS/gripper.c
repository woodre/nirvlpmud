inherit "/open/new/monster";
#include <ansi.h>
object shell;
reset(arg) {
if(arg) return ;  ::reset(arg);

set_name("gripper");
set_short(HIK+"A gripper"+NORM);
set_alias("clicker");
set_long("A small creature that has hook-like feet used to grip\n"+
         "its prey and has a mouth that looks like a suction cup.\n"+
         "It doesn't look like it is vunerable to much, but it is\n"+
         "slower than anything else.\n");

set_level(6);
set_wc(10);
set_ac(5);
set_hp(90);
 
monster_died() {
   object shell;
   shell = clone_object("/players/data/OUTERB/ITEMS/shell.c");
   move_object(shell,environment());
   return 0; 
   }



}

