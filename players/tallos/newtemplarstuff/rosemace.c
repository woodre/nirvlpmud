#include "/players/tallos/ansi.h"
#define tp this_player()->query_name()
int a;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("morningstar");
    set_alias("mace");
    set_alt_name("rose");
    set_short(""+HIG+"==,=='={"+HIR+"@"+NORM+"");
    set_long("                        "+HIY+"Morning"+HIW+"star"+HIG+" of "+HIR+"R"+HIM+"o"+NORM+""+MAG+"s"+HIW+"e"+HIY+"s"+NORM+"\n"+
    		 "     "+HIW+"This is the most coveted weapon of the "+HIB+"High Knights Templar"+HIW+".\n"+
             "It is made of hard "+HIY+""+BLK+"ironwood"+HIW+","+NORM+""+CYN+" steel"+HIW+", and is shapped like that of a\n"+
             "a large '"+HIR+"f"+HIY+"l"+HIW+"e"+HIM+"u"+HIG+"r"+HIR+"d"+HIY+"e"+HIW+"l"+HIM+"e"+HIW+"'.  In the hands of a person of great "+HIR+"be"+HIM+"au"+HIY+"ty"+HIW+" it \n"+
             "is a weapon to be feared!\n");
    set_class(19);
    set_weight(4);
    set_params("other|earth",0,"rose_hit");    
    set_value(50000);
    set_type("mace");
}
query_wear() {
   return 1;
}
weapon_breaks() {
   return 1;
}
rose_hit(attacker){
 if(this_player())
if(call_other(this_player(),"query_attrib","cha") > random(80))
  {
  int a;
  a=random(10);
  if(a >= 6) {
    write(""+HIW+"Your target is struck by a shower of:\n"+
          " \n"+
          "  "+HIG+"--'-{"+HIR+"@"+NORM+"    "+HIG+"--'-{"+HIR+"@"+NORM+"   "+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@  "+HIG+"--'-{"+HIR+"@"+NORM+"\n"+
          "  "+HIG+"--'-{"+HIR+"@"+NORM+"    "+HIG+"--'-{"+HIR+"@"+NORM+"   "+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@  "+HIG+"--'-{"+HIR+"@"+NORM+"\n"+            
          "  "+HIG+"--'-{"+HIR+"@"+NORM+"    "+HIG+"--'-{"+HIR+"@"+NORM+"   "+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@  "+HIG+"--'-{"+HIR+"@"+NORM+"\n"+
          "  "+HIG+"--'-{"+HIR+"@"+NORM+"    "+HIG+"--'-{"+HIR+"@"+NORM+"   "+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@  "+HIG+"--'-{"+HIR+"@"+NORM+"\n"+
          ""+HIW+"And you are "+HIC+"HEALED!!!"+NORM+"\n");
    say(""+wielded_by->query_name()+"'s "+HIY+"morning"+NORM+"star produces a shower of:\n"+
        ""+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@    "+HIR+"R"+HIM+"o"+NORM+""+MAG+"s"+NORM+"e"+HIY+"s"+NORM+"   "+HIG+"--'-{"+HIR+"@"+NORM+"  "+HIG+"--'-{"+HIR+"@"+NORM+"\n"+
        " \n");

    this_player()->add_hit_point(random(9));
    attacker->hit_player(random(9), "other|earth");
    return random(9);
             }
    return 0;
 }
 }
