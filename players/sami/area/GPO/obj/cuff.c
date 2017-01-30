#include <ansi.h>
#include <ansi.h>
#define tp this_player()
#define tpn tp->query_name()
inherit "obj/treasure";

reset(arg)  
{
        if(arg) return;

        set_name("handcuff");
        set_alias("cuffs");
        set_short("A slick pair of "+HIG+"H"+HIK+"and"+HIG+"c"+HIK+"uffs"+NORM+"	");
        set_long("Sami is such a feak, who would have thought?\n");
        set_weight();
        set_value(10);
}

init() {
  ::init();
  add_action("emotes","cuff");
  add_action("emotes","slip");

  }
  

  emotes() {
string msg,msg2;
msg = msg2 = 0;
  if(query_verb() == "cuff") { 
    msg = "You walk up to "+tp->query_possessive()+" and roughly cuff there hands.";
    msg2 = tpn+" Roughly cuffs "+tp->query_possessive()+"'s hands behind their back.";
  }
  if(query_verb() == "slip") {
    msg = "You slip behind "+tp->query_possessive()+" and bend them over holding the cuffs .";
    msg2 = tpn+" bends "+tp->query_possessive()+" over grabbing firmly onto the cuffs.";
  }
  
  
  write(msg+"\n");
  say(msg2+"\n");
return 1; }