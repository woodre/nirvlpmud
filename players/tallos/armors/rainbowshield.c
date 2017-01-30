
inherit "obj/armor";
#include "/players/wocket/closed/ansi.h"
#define tp this_player()->query_name()
int n;
reset(arg){
   ::reset(arg);
   if(arg) return;

   set_name("rainbow shield");
   set_alias("shield");
   set_short(""+HIR+"R"+HIY+"a"+HIG+"i"+HIB+"n"+HIM+"b"+HIR+"o"+HIY+"w "+HIG+"S"+HIB+"h"+HIM+"i"+HIR+"e"+HIY+"l"+HIG+"d"+NORM+"");
   set_long(
            "    "+HIR+" @@@@@@               \n"+   
            "   "+HIR+"@"+HIY+"@@@@@@@"+HIY+"@"+HIR+"@           \n"+
            "  "+HIR+"@"+HIY+"@"+HIG+"@@@@@@@"+HIG+"@"+HIY+"@"+HIR+"@          \n"+
            " "+HIR+"@"+HIY+"@"+HIG+"@"+HIB+"@@@@@@@"+HIB+"@"+HIG+"@"+HIY+"@"+HIR+"@         \n"+
            ""+HIR+"@"+HIY+"@"+HIG+"@"+HIB+"@"+HIM+"@@@@@@@"+HIM+"@"+HIB+"@"+HIG+"@"+HIY+"@"+HIR+"@        \n"+
            ""+HIR+"@"+HIY+"@"+HIG+"@"+HIB+"@"+HIM+"@@@@@@@"+HIM+"@"+HIB+"@"+HIG+"@"+HIY+"@"+HIR+"@        \n"+
            " "+HIR+"@"+HIY+"@"+HIG+"@"+HIB+"@@@@@@@"+HIB+"@"+HIG+"@"+HIY+"@"+HIR+"@         \n"+
            "  "+HIR+"@"+HIY+"@"+HIG+"@@@@@@@"+HIG+"@"+HIY+"@"+HIR+"@          \n"+
            "   "+HIR+"@"+HIY+"@@@@@@@@"+HIR+"@           \n"+
            "     "+HIR+"@@@@@@    "+NORM+"   \n");
   set_type("shield");
   set_ac(2);
   set_weight(2);
   set_value(20000);
   set_params("other|fire",0,10,0);
   set_params("other|ice",0,10,0); 
   set_params("other|water",0,10,0); 
   set_params("other|earth",0,10,0);
   set_params("other|wind",0,10,0);
   set_params("other|eletric",0,10,0);      

}
do_special(owner){
   n = random(100);
   if(n > 85){
    tell_object(owner,
    "  "+NORM+""+MAG+"The "+HIR+"s"+HIY+"h"+HIG+"i"+HIB+"e"+HIM+"l"+HIR+"d"+NORM+""+NORM+""+MAG+" produces a beautiful..."+NORM+"\n"+
    "               "+HIR+"="+HIY+" ="+HIG+" ="+HIB+" ="+HIM+" =\n"+
    "              "+HIR+"="+HIY+" ="+HIG+" ="+HIB+" ="+HIM+" =\n"+
    "             "+HIR+"="+HIY+" ="+HIG+" ="+HIB+" ="+HIM+" =\n"+
    "            "+HIR+"="+HIY+" ="+HIG+" ="+HIB+" ="+HIM+" =\n"+
    "           "+HIR+"="+HIY+" ="+HIG+" ="+HIB+" ="+HIM+" =\n"+
    "          "+HIR+"="+HIY+" ="+HIG+" ="+HIB+" ="+HIM+" =\n"+
    "         "+HIR+"="+HIY+" ="+HIG+" ="+HIB+" ="+HIM+" ="+NORM+"\n"+
    "     "+NORM+""+MAG+"and you are "+HIC+"healed!"+NORM+"\n");
    owner->add_hit_point(4);
   return 1; 
  }
}
