#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("Bob Ray");
  set_alt_name("ray");
  set_alt_name("mayor");
  set_race("Master Mason");
  set_alias("bob");
  set_short(""+HIY+"Bob Ray"+NORM+" Mayor of Gas City");
  set_long("\Before you is the Mayor of Gas City. He appears to be in his\n\
late 60's. The mayor is a General Contractor running his own business.\n\
Although he is an older man, Do not underestimate his ability to act\n\
fast and crush you! Master Mason Bob Ray has much power when he calls\n\
on his God for vengeance!\n");
  set_level(21);
  set_hp(699 + random (100));
  set_ac(20 + random (10));
  set_wc(38 + random (10));
  set_al(0);
  set_chat_chance(10);
  load_chat(query_name()+" says, \"Hello, How are you today?\"\n");
  load_chat("You stand in the Mayors office looking around and feel inspired by what you see!\n");
  gold=clone_object("obj/money");
  gold->set_money(4000);
  move_object(gold, this_object());
  add_spell("saber","#MN# slices his "+HIY+"M"+HIW+"asonic"+NORM+" "+HIY+"S"+HIW+"word"+NORM+" through you.\n",
                     "#MN# slices his "+HIY+"M"+HIW+"asonic"+NORM+" "+HIY+"S"+HIW+"word"+NORM+" through #TN#.\n",
                     50,60,"other|fire");
}

init() {
  ::init();
  add_action("ask","ask"); }

ask(str) {
string s1,s2;
  if(!str) { write("Who did you want to ask?\n"); return 1; }
  sscanf(str,"%s %s",s1,s2);
  if(s1 != "mayor") { write("Be a little more formal.\n");
        return 1; }
if( (s1 == "mayor") && (s2 == "ray") )
  {write("    An order of European Knights amassed a huge amount of\n\
priceless treasure. It was brought to the United States and\n\
hidden by the Founding Fathers after the Revolutionary War. The\n\
Masons hid the treasure in a secret location to keep it out of\n\
the hands of the British. To this day the treasure has not been\n\
found. If you seek out the treasure you must find Hiram's Key to\n\
start unlocking the clues. \n");
return 1;
}}