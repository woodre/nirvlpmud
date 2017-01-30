/*
This weapon found on the Violet Knight. Return of 4, storable
*/
 
#include "/players/snow/closed/cyber/color.h"
 
#define TP this_player()
#define TPN TP->query_name()
#define OP TP->query_attack()
#define OPN OP->query_name()
#define PIE call_other(this_player(),"query_attrib","pie")
#define ALN TP->query_alignment()
#define OPALN OP->query_alignment()
#define SWORD BLUE+BOLD+"Blessed Longsword"+OFF+OFF
 
inherit "obj/weapon.c";
 
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("blessed longsword");
    set_alias("longsword");
    set_short(SWORD);
    set_type("sword");
    set_long(
"The Blessed Longsword blazes with a pure blue flame. Its might\n"+
"will never fade, nor will fear betray its owner.\n");
    set_class(18);
    set_weight(2);
    set_light(2);
    set_value(3000);
    set_hit_func(this_object());
}
 
weapon_hit(object ob) {
  object mon;
  mon = ob;
  if(!ob) return;
  if(ALN > 500 && PIE > random(40) && OPALN < 0)  {
    say(TPN+"'s "+SWORD+" burns into "+ob->query_name()+"!\n");
    write("Your "+SWORD+" burns into "+ob->query_name()+"!\n");
  return 4;
  }
       return;
}
