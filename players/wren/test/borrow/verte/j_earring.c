
#include "../define.h"
inherit ARMOUR;

reset(arg) {
   if(arg) return;
   ::reset();
   set_id("earring");
   set_short("A "+YEL+"golden"+NORM+" earring");
   set_alias("golden earring");
   set_weight(1);
   set_ac(0);
   set_type("misc");
   set_value(300+random(100)); 
}

wear(string str) {
   while(remove_call_out("regen_sp") != -1);
   if(!id(str) || environment() != this_player() || worn) return 0;
   ::wear(str);
   if(worn) call_out("regen_sp", 5 + random(2));
   return 1; }

remove(string str) {
   if(!id(str) || environment() != this_player() || !worn) return 0;
   ::remove(str);
   while(remove_call_out("regen_sp") != -1);
   return 1; }

long() {
   write("A small, polished golden earring with a small point on the end\n"
      +"to penetrate one's earlobe.  It is usually used for style, but this\n"
      +"one has some sort of magical rune inscribed on the side.\n");
}

regen_sp() {
   string msg;
    if(!worn_by) return 0; /* if nobody wearing it, kill call-out*/
                           /*Make sure they need healing -Bp*/
    if(USER && USER->is_player() && worn_by->query_hurt())
    {
      switch(random(3)) {
         case 0: msg = "The earring glows softly.\nYour mental powers seem to recover...\n";
         break;
         case 1: msg = "You hear a faint 'hummmmmmmm' in your ear...\n";
         break;
         case 2: msg = "You feel more relaxed with the world.\n";
         break; }
      if(!random(20)) tell_object(USER,msg);
      if(!random(100000)) {
         tell_object(USER,"Suddenly, your ear burns hot!\n");
         tell_object(USER,RED+"Your flesh is scorched!\n"+NORM);
         USER->hit_player(50 + random(50), "other|fire");
         while(remove_call_out("regen_sp") != -1);
         call_out("regen_sp", 5 + random(2));
         return 1; }
      USER->add_spell_point(3+random(2));
    }
      while(remove_call_out("regen_sp") != -1);
      call_out("regen_sp",5+random(2));
}

query_save_flag() { return 1; }

drop()
{
   while(remove_call_out("regen_sp") != -1);
   ::drop();
}
