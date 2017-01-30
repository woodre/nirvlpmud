/*
  leave the vampire guild - with penalties
*/

#include "/players/eurale/defs.h"

/* --------------- Leave the guild --------------- */
leave_guild(str) {
  string str1, str2;
  object stuff;
  int i,exp,minus;

if(str != "vamps") return 0;

  /* take them off the member's list */
call_other(MEMBER, "???", 0);
call_other(MEMBER, "delete_player", TPRN);

  /* add them to the traitor's list & indicate that they Quit*/
call_other(TRAITOR, "???", 0);
call_other(TRAITOR, "add_player", TPRN, "Q");

  /* get rid of any guild stuff around */
if(PFANGS->query_littlebat_obj()) destruct(PFANGS->query_littlebat_obj());

  /* destruct their coffin & everything in it */
call_other(COFFIN_ROOM, "???", 0);
stuff = first_inventory(COFFIN_ROOM);
while (stuff) {
  if(stuff->query_coffin_owner_name() == TPRN) {
    destruct(stuff);
    break; }
    stuff = next_inventory(stuff);
  }

  /* dismiss wolf, if there is one */
if(PFANGS->query_wolf_obj()) destruct(PFANGS->query_wolf_obj());

  /* now drop any vampire equipment they have */
if(present("vampire dagger", TP)) command("drop dagger", TP);
if(present("vampire tuxedo", TP)) command("drop tuxedo", TP);

  /* fix their title */
TP->set_title("-->Quitter from the Vampire Guild");

  /* now throw them out if they're in a guild_room */
str1 = file_name(ROOM);
sscanf(str1, "%s.c", str2);
if (!str2) str2 = str1;
if(
  str2 == "/players/eurale/Vamp/RMS/vguild_hall.c" ||
  str2 == "/players/eurale/Vamp/RMS/boardroom.c" ||
  str2 == "/players/eurale/Vamp/RMS/titles.c" ||
  str2 == "/players/eurale/Vamp/RMS/equip.c" ||
  str2 == "/players/eurale/Vamp/RMS/mirrors.c" ||
  str2 == "/players/eurale/Vamp/RMS/shop.c" ||
  str2 == "/players/eurale/Vamp/RMS/wolf_path.c" ||
  str2 == "/players/eurale/Vamp/RMS/wolf_summon.c" ||
  str2 == "/players/eurale/Vamp/RMS/wing_room.c" ||
  str2 == "/players/eurale/Vamp/RMS/cafe.c" ||
  str2 == "/players/eurale/Vamp/RMS/init_room.c" ||
  str2 == "/players/nooneelse/black/guild_history_hall.c" ||
  str2 == "/players/nooneelse/black/guild_prohibit.c" ||
  str2 == "/players/nooneelse/black/guild_junk_room.c" ||
  str2 == MEMBER ||
  str2 == COFFIN_ROOM ||
  str2 == COFFIN) {
    write(HIR+
     "A flaming demon appears and tosses you out saying,"+
     " 'VAMPIRE MEMBERS ONLY!'"+NORM+"\n");
    FANGS->tell_my_room(HIR+
        "A flamming demon appears, beats "+capitalize(TPRN)+
        " up and tosses "+TP->query_objective()+
        " out, saying:\n     Members only!");

TP->move_player("into the mist#room/church.c");
}

i = TPGEXP;
TP->add_guild_exp(-i);
exp = TP->query_exp();
minus = exp / 4;
TP->add_exp(-minus);
TP->set_guild_name(0);
TP->set_guild_file(0);
TP->set_home("/room/church.c");

TP->raise_strength(-5);
  if(TP->query_attrib("str") < 0) TP->set_attrib("str") == 0;
TP->raise_magic_aptitude(-5);
if(TP->query_attrib("mag")<0)TP->set_attrib("mag")==0;
TP->raise_stamina(-5);
  if(TP->query_attrib("sta") < 0) TP->set_attrib("sta") == 0;
TP->raise_will_power(-5);
  if(TP->query_attrib("wil") < 0) TP->set_attrib("wil") == 0;
TP->raise_stealth(-4);
  if(TP->query_attrib("ste") < 0) TP->set_attrib("ste") == 0;
TP->raise_luck(-3);
  if(TP->query_attrib("luc") < 0) TP->set_attrib("luc") == 0;
TP->raise_intelligence(-3);
  if(TP->query_attrib("int") < 0) TP->set_attrib("int") == 0;
TP->raise_piety(-2);
  if(TP->query_attrib("pie") < 0) TP->set_attrib("pie") == 0;
telepathy("I'M A QUITTER FROM THE VAMPIRE GUILD!");
rm("/"+VMEMBER+TP->query_real_name()+".o");
TP->save_me();
destruct(PFANGS);
return 1;
}
