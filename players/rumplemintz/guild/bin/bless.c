/* Bless
* Druid Spell to increase class of weapon
*/
#include <ansi.h>
#include "/players/rumplemintz/guild/bin/SPELL_COST"

int bless(string str){
   int class, newclass;
   object weapon;
   if(!str){
      notify_fail(GRN+"The Trees tell you:"+NORM+" What would you like to bless?\n");
      return 0;
   }
   if(this_player()->query_guild_rank() < 6){
      notify_fail(GRN+"The Trees tell you:"+NORM+" You are not high enough level to use that ability.\n");
      return 0;
   }
   if(this_player()->query_alignment() < -100
         || this_player()->query_alignment() > 100){
      notify_fail(GRN+"The Trees tell you:"+NORM+" You have strayed too far from neutrality.\n");
      return 0;
   }
   if(this_player()->query_sp() < COST6){
      notify_fail(GRN+"The Trees tell you:"+NORM+" You do not have enough spell points.\n");
      return 0;
   }
   if(this_player()->query_attack()){
      notify_fail(GRN+"The Trees tell you:"+NORM+" You cannot use this ability while in combat.\n");
      return 0;
   }
   if(this_player()->query_attrib("int") < random(30)){
      notify_fail(GRN+"The Trees tell you:"+NORM+" Your spell has failed.\n");
      return 0;
   }
   weapon = present(str, this_player());
   if(!weapon){
      notify_fail(GRN+"The Trees tell you:"+NORM+" You have no "+str+".\n");
      return 0;
   }
   if(!weapon->weapon_class()){
      notify_fail(GRN+"The Trees tell you:"+NORM+" That is not a weapon.\n");
      return 0;
   }
   class = (int)weapon->query_class();
   switch(class){
      case 16..19: newclass = 20; break;
      case 1..15:  newclass = class+4; break;
      default: newclass = 20; break;
   }
   if(weapon->query_info("blessed")){
      notify_fail(GRN+"The Trees tell you:"+NORM+" "+capitalize(str)+" is already blessed.\n");
      return 0;
   }
   if(class > 19){
      notify_fail(GRN+"The Trees tell you:"+NORM+" "+capitalize(str)+" cannot be blessed anymore.\n");
      return 0;
   }
   weapon->set_class(newclass);
   weapon->set_info("blessed");
   this_player()->restore_spell_points(-COST6);
   write(GRN+"You call upon nature to bless a weapon"+NORM+".\n");
   say(GRN+this_player()->query_name()+" calls upon nature to bless a weapon"+NORM+".\n");
   return 1;
}
