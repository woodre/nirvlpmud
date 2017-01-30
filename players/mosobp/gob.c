#include "/open/ansi.h"
#define TP this_player()
inherit "/obj/treasure.c";
   object who;
string target;
int mode,prefix;
reset(int arg) {
  if(arg) return;
  set_id("wand");
set_short(GRN+"A Warder's Cloak"+NORM);
}

init() {
    ::init();
      add_action("hero","hero");
      add_action("test","test");
      add_action("spark","spark");
     add_action("sparkle","sparkle");
     add_action("warder","warder");
      add_action("send","lt");
add_action("tell","tell");
    }
hero() {
TP->set_pretitle("Hero of "+BLU+"Earth"+NORM);
TP->set_title(HIY+"The Super Saiyan"+NORM);
  TP->set_guild_name("Saiyan");
  return 1;}

spark() {
TP->set_pretitle(BOLD+BLU+"Lord"+RED+" Captain "+YEL+"Commander"+NORM);
TP->set_title(BOLD+CYN+"The Defender of Light"+NORM+"(Defender of Rightousness)"+NORM);
  TP->set_guild_name("WhiteCloak");
  return 1;}

test() {
TP->set_pretitle(BOLD+RED+"Aielman"+NORM);
TP->set_title(BOLD+YEL+"Clan Chief"+NORM+"of the "+YEL+"Sharaad Sept"+NORM);
TP->set_guild_name("Aiel");
  return 1;}

sparkle() {
TP->set_pretitle(BOLD+MAG+"The Amirlyn "+BLUE+"Seat "+NORM);
TP->set_title(BOLD+CYN+"is The keeper "+GRN+"of the "+RED+"Seals"+NORM);
TP->set_guild_name("Aes Sedai");
return 1;  }

warder()  {
TP->set_pretitle(BOLD+YEL+"Graceful yet dangerous"+NORM);
TP->set_title(GRN+"is the Warder to an Aes Sedai"+NORM);
TP->set_guild_name("Warder");
return 1; }

drop() {
  write(""+YEL+"The wand breaks as it hits the ground."+NORM+"\n");
  destruct(this_object());
  return 1; }

give() {
  write(""+YEL+"Do you really think anyone would want this?"+NORM+"\n");
  return 1; }

send(str) {
   string history; /* added by verte */
   object list;
   object AURA;
   int i;
   string myname;
   if (!str) { write("Send what?\n"); return 1; }
   list = users();
  return 1;
  }
tell(arg) 
{
call_other("/players/mosobp/examples/teller.c","main",arg);
return 1;
}

