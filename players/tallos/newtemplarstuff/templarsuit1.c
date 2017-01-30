#include "/players/tallos/ansi.h"
#include "/players/jaraxle/define.h"
inherit "obj/armor";
#define tp owner->query_name()
reset(arg){
   ::reset(arg);
   set_name("Shinning Adamantine Fullplate");
   set_short(""+HIG+"["+HIB+"High Templar"+HIG+"]"+NORM+""+CYN+" Shinning Adamantine Fullplate "+NORM);
   set_alias("fullplate");
   set_long(""+HIY+""+BLK+"                            \n"+
      "       *"+NORM+""+CYN+"##"+HIY+""+BLK+"***     ***"+NORM+""+CYN+"##"+HIY+""+BLK+"*                           \n"+
      "      **"+NORM+""+CYN+"###"+HIY+""+BLK+"***   ***"+NORM+""+CYN+"###"+HIY+""+BLK+"**                                 \n"+
      "     ****"+NORM+""+CYN+"####"+HIY+""+BLK+"*"+NORM+""+CYN+"###"+HIY+""+BLK+"*"+NORM+""+CYN+"####"+HIY+""+BLK+"****                            \n"+
      "     ****"+NORM+""+CYN+"#############"+HIY+""+BLK+"****                                 \n"+
      "     *** "+NORM+""+CYN+"#############"+HIY+""+BLK+" ***                                 \n"+
      "     ***"+NORM+""+CYN+" ############# "+HIY+""+BLK+"***                                 \n"+
      "     "+NORM+""+CYN+"WWW ############# WWW                                 \n"+
      "         #############                                 \n"+
      "         "+HIY+""+BLK+"*"+NORM+""+CYN+"###########"+HIY+""+BLK+"*                                \n"+
      "         "+HIY+""+BLK+"*****"+NORM+""+CYN+"###"+HIY+""+BLK+"*****                                 \n"+
      "         ****     ****                                 \n"+
      "         ****     ****                                 \n"+
      "         "+NORM+""+CYN+"####     ####                                \n"+
      "         "+HIY+""+BLK+"****     ****                                 \n"+
      "         ****     ****                                 \n"+
      "         ****     ****                                 \n"+
      "                           "+NORM+"      \n");
   set_ac(5);
   set_params("other|evil",0,35,"evil_emote");
   set_params("other|dark",0,35,"evil_emote");
   set_params("magical",2);
   set_weight(6);
   set_type("armor");
   set_value(35000);
   set_light(1);
}
short(){
	if(worn){
	return ""+MAG+""+worn_by->query_name()+"'s "+HIG+"["+HIB+"High Templar"+HIG+"]"+NORM+""+CYN+" Shinning Adamantine Fullplate "+NORM;
        }
	else{
 	return ""+HIG+"["+HIB+"High Templar"+HIG+"]"+NORM+""+CYN+" Shinning Adamantine Fullplate "+NORM;
        }
       }
evil_emote() {
  if(environment()) tell_object(environment(),""+HIB+"The armor "+HIY+"shines true "+HIB+"as it absorbs the "+HIR+"evil "+HIB+"attack!"+NORM+"\n");
}
do_special(owner){
   if(!owner || !owner->query_attack()) return 1;
   if(!owner->is_player()) return 1;
   if(!owner->query_alignment() > 45) return 1;
   if(random(owner->query_attrib("pie")) > 5 + random(100)) {
      tell_object(owner," \n"+ 
            ""+HIW+"Your fullplate "+HIY+"shines BRIGHTLY "+HIW+"and you are "+HIC+"HEALED!!!\n"+
            " \n"+NORM);
      tell_room(environment(owner),""+HIB+""+tp+"'s "+HIW+"fullplate glows "+HIY+"BRIGHTLY "+HIW+"and they are "+HIC+"HEALED!\n"+NORM);
      owner->add_hit_point(random(15));
      return 1; 
      }
  }