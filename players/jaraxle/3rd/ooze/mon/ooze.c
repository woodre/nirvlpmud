#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

int x;
reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name(HIM+"Living ooze"+NORM);
   set_alias("ooze");
   set_alt_name("living ooze");
   set_race("ooze");
   
   set_level(15);
   set_hp(275);
   set_al(0);
   set_ac(24);
   set_aggressive(0);
   switch(random(5)){
      case 0..3:
      set_wc(10);
      break;
      case 4:
      set_wc(20);
      break;
   }
   set_dead_ob(this_object());
   
   set_chat_chance(3);
   load_chat(HIM+"The ooze bubbles.\n"+NORM);
   load_chat(HIM+"The ooze flows between your feet.\n"+NORM);
   load_chat(HIM+"The ooze suddenly seems to lash out at you!\n... missing you by inches.\n"+NORM);
   gold = clone_object("obj/money");
   gold->set_money(100+random(201));
   move_object(gold,this_object());
}

monster_died() {
   x = present("corpse",environment(this_object()));
   destruct(x);
   tell_room(environment(this_object()),
      ""+HIM+"Living ooze slinks back into itself, defeated.\n"+NORM);
   MOCO("/players/jaraxle/3rd/ooze/mon/slab.c"),environment());
   return 0; }

long(){ write(HIM+"Purple ooze seemingly out of nowhere.  The ooze might be sticky to the touch.\nIt smells rotten and repugnant.\n"+NORM); }
short(){ return 0; }

init(){
   ::init();
   add_action("touch","touch");
}

touch(arg){
   if(!arg) return (notify_fail("Touch what?\n"), 0);
   if(id(arg)) {
      write("\
         As you try and touch the ooze, it quickly moves out of the way\n\
         as if it was alive!\n");
      return 1; }
   else return (notify_fail("You can touch the ooze.\n"), 0);
}
