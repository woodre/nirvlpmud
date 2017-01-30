inherit "obj/monster";
#include "/players/catt/AREAS/base_defines.c"
reset(arg) {
   object obj1;
   object obj2;
   object obj3;
   object obj4;
   object obj5;
   ::reset(arg);
   if(arg) return;
   set_name();
   set_alias();
   set_short();
   set_long();
   set_level();
   set_race();
   set_hp();
   set_al(); \* +1000 -- (-)1000 *\
   set_wc();
   set_ac();
   set_aggressive();
   enable_commands();
   set_random_pick();
   set_chat_chance(5);
   load_chat("smile/n");
   load_chat("frown/n");
   obj1 = clone_object();
   if(obj1) {
      move_object(obj1, this_object());
      command("wear "+obj1->query_name());
      }
   obj2 = clone_object();
   if(obj2) {
      move_object(obj2, this_object());
      command("wield "+weapon->query_name());
      }
}
