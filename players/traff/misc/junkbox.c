#define tp this_player()->qury_name()
#include "/players/traff/closed/ansi.h"
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("junkbox");
   set_alias("box");
   set_short("A junkbox");
   set_long(
    "A box full of JUNK commands!\n\n"+
    "afk = Away From Keyboard\n"+
    "brb = Be Right Back\n"+
    "(If you have suggestions for other commands, please mail Traff)\n");
   set_weight(0);
   set_value(1);
}

init()  {
  ::init();
  add_action("afk","afk");
  add_action("brb","brb");
  add_action("beano","beano");
  add_action("pe","pe");
  add_action("room","room");
        }

afk() {
  emit_channel("junk","(Junk) "+HIG+(this_player()->query_name())+HIR+" is AFK"+NORM+"!\n");
  return 1;
        }
brb() {
  emit_channel("junk","(Junk) "+HIG+(this_player()->query_name())+HIY+" will BRB"+NORM+"!\n");
  return 1;
        }
beano(str) {
  if(!str)  {
    emit_channel("junk",HIC+"A giant "+BLINK+HIY+"BEANO"+NORM+HIC+
"rolls into the room.\n");
    emit_channel("junk",HIC+"Beano shouts SALSA!\n");
    emit_channel("junk",HIC+"Beano leaves etherial!"+NORM+"\n");
  return 1;  }
  emit_channel("junk",HIY+"Beano Junks: "+HIC+str+NORM+"\n");
  return 1;
        }
pe(str) {
  if(!str) {return 0;}
  emit_channel("junk",HIG+str+NORM+"\n");
  return 1;
  }

room() {
  write("Room: "+(this_player()->query_room())+"\n");
  write("Env:  "+(this_player()->query_environment())+"\n");
  return 1; }
