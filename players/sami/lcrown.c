#include "/obj/ansi.h";
inherit "obj/treasure";
#include <ansi.h>
#define tp this_player()
#define tpn tp->query_name()

reset(arg)  
{
        if(arg) return;

        set_name("king_crown");
        set_alias("crown");
        set_short(""+HIY+"King James Golden Crown"+NORM+" (worn) ["+RED+"rubie encrusted"+NORM+"]"+NORM+"");
        set_long("Engraved on this majestic crown is the command '"+HIY+"cpowers"+NORM+"'.\n");
        set_weight(0);
        set_value(0);
}
init() {
  ::init();
  add_action("emotes","cnod");
  add_action("emotes","cwear");
  add_action("emotes","cspit");
  add_action("emotes","bang");
  add_action("crown_powers","cpowers");
  }
  crown_powers() {
  write("**********~~~~~~~~~Crown Powers~~~~~~~~~~~~~~~**********\n");
  write("EMOTES:\n"+
        "  cnod   cwear   cspit   bang\n");
  write("**********~~~~~~~~~Crown Powers~~~~~~~~~~~~~~~~**********\n");
return 1; }

  emotes() {
string msg,msg2;
msg = msg2 = 0;
  if(query_verb() == "cwear") { 
    msg = "You don the "+HIY+"King James Golden Crown"+NORM+" ["+RED+"rubie encrusted"+NORM+"]"+NORM+".";
    msg2 = tpn+" dons the "+HIY+"King James Golden Crown"+NORM+" ["+RED+"rubie encrusted"+NORM+"]"+NORM+".";
  }
  if(query_verb() == "cnod") {
    msg = "You nod in acknowledgement, the room is in awe as your"+RED+" rubie crown"+NORM+" sparkling.";
    msg2 = tpn+" nods in acknowledgement, "+RED+"Rubies"+NORM+" glisten from his crown.";
  }
  if(query_verb() == "cspit") {
    msg = "You spit "+RED+"rubies"+NORM+" about the room.";
    msg2 = tpn+" spits "+RED+"rubies"+NORM+" about the room as if it were vomit!";

  }
  if(query_verb() == "bang") {
    msg = "You scream :BANG BANG! BANG BANG! You run around the room like a nut.";
    msg2 = tpn+" screams: BANG BANG BANG BANG! as "+tp->query_objective()+" runs around the room.";
  }
  write(msg+"\n");
  say(msg2+"\n");
return 1; }