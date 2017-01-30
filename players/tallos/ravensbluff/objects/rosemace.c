#include "/players/tallos/ansi.h"
#define tp this_player()->query_name()
int a;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("morningstar");
    set_alias("mace");
    set_alt_name("rosemace");
    set_short(""+HIG+"==,=='={"+HIR+"@"+NORM+"");
    set_long("                 "+HIY+"Morning"+NORM+"star"+HIG+" of "+HIR+"R"+HIM+"o"+NORM+""+MAG+"s"+NORM+"e"+HIY+"s"+NORM+"\n"+
    		 "This is the "+HIY+"morning"+NORM+"star of the high cleric of "+HIM+"S"+NORM+""+MAG+"u"+HIM+"n"+NORM+""+MAG+"e"+NORM+", the\n"+
             ""+HIM+"goddess of love"+NORM+".  It is shaped like a large "+HIR+"rose"+NORM+" but is\n"+
             "made of hard "+NORM+""+YEL+"ironwood"+NORM+" and "+NORM+""+CYN+"steel"+NORM+".   It is quite a deadly\n"+
             "weapon in the hands of one with great "+HIM+"be"+HIR+"au"+HIY+"ty"+NORM+".\n");
    set_class(19);
    set_weight(4);
    set_value(50000);
    set_type("mace");
    set_params("other|earth",0,"rosehit");
}
rosehit(attacker){
 if(this_player())
if(call_other(this_player(),"query_attrib","cha") >= 20)
 {
  int a;
  a=random(10);
  if(a >= 8) {
    write("Your target is struck by a shower of:\n"+
          "  "+HIG+"--'-{"+HIR+"@"+NORM+"    "+HIG+"--'-{"+HIR+"@"+NORM+"   "+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@  "+HIG+"--'-{"+HIR+"@"+NORM+"\n"+
          "  "+HIG+"--'-{"+HIR+"@"+NORM+"    "+HIG+"--'-{"+HIR+"@"+NORM+"   "+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@  "+HIG+"--'-{"+HIR+"@"+NORM+"\n"+            
          "  "+HIG+"--'-{"+HIR+"@"+NORM+"    "+HIG+"--'-{"+HIR+"@"+NORM+"   "+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@  "+HIG+"--'-{"+HIR+"@"+NORM+"\n"+
          "  "+HIG+"--'-{"+HIR+"@"+NORM+"    "+HIG+"--'-{"+HIR+"@"+NORM+"   "+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@  "+HIG+"--'-{"+HIR+"@"+NORM+"\n");
    say(""+wielded_by->query_name()+"'s "+HIY+"morning"+NORM+"star produces a shower of:\n"+
        ""+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@    "+HIR+"R"+HIM+"o"+NORM+""+MAG+"s"+NORM+"e"+HIY+"s"+NORM+"   "+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@"+NORM+"\n"+
        " \n");

    this_player()->add_hit_point(random(6));
    return random(6);
    }
    return 1;
}
}
