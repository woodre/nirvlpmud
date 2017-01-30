#include "/players/jaraxle/ansi.h"
inherit "/obj/monster";
string lastv;
int lastvisit;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("katarin");
  set_alt_name("innkeeper");
  set_race("human");
  set_gender("female");
  set_level(12);
  set_ac(9);
  set_wc(16);
  set_al(1000);
  set_aggressive(0);
  set_chat_chance(5);
  set_a_chat_chance(5);
  load_chat("Katarin says: Have you seen "+GRN+"Khrell"+NORM+" lately?\n");
  load_chat("Katarin thumbs through the book, humming softly to herself.\n");
  set_short("Katarin, the Templar Innkeeper");
  set_long(
    "Katarin is the Innkeeper for the Templar Castle. She has dark brown\n"+
      "hair pulled back into a braid that hangs halfway down her delicate\n"+
      "back. She has a warm smile with deeply blushed cheeks that contrast\n"+
      "the paleness of her soft skin. She wears a long gown, brown in color\n"+
      "and embroidered in gold thread. You may "+GRN+"ask her about"+NORM+" the "+GRN+"commands"+NORM+" \n"+
      "for the rooms or about the "+GRN+"rooms"+NORM+" in general.\n"+
    "  \n");
}

init() {
  ::init(); /* verte */
  add_action("read","read");
  add_action("ask","ask");
}

  ask(str) {
string what;
  if(!str) { notify_fail("Ask whom about what?\n"); return 0; }
  if(sscanf(str,"katarin about %s",what)!=1) { notify_fail("Ask whom about what?\n"); return 0; }
  switch(what) {
      case "katarin": case "innkeeper":
      write(
    "Katarin looks up at you, giving you a warm smile in greeting.\n"+
    "Katarin says: I can tell you about our private"+GRN+" rooms"+NORM+" or the "+GRN+"commands"+NORM+".\n"+
    "She waits patiently for your response.\n");
  return 1;
      case "rooms":
      write("Katarin says: Rooms cost 18,000 gold coins. You'll find some items\n"+
     "are unable to store in your room. You will be notified which items do\n"+
     "save and which do not.\n");
  return 1;
      case "commands":
      write("Katarin shows you a piece of parchment with the current commands:\n");
      write("  \n"+
      HIW+" LOBBY COMMANDS:"+NORM+" \n"+
      GRN+" register"+NORM+"                   Register for a room\n"+
      GRN+" checkout"+NORM+"                   Check out from your room\n"+
      "  \n"+
      HIW+" ROOM COMMANDS:"+NORM+" \n"+
      GRN+" invite "+NORM+"<"+GRN+"name"+NORM+">              Invite someone into your room\n"+
      GRN+" store"+NORM+"                      Store items (on floor)\n"+
      GRN+" restore"+NORM+"                    Restore items stored\n"+
      GRN+" clear"+NORM+"                      Clear room description\n"+
      GRN+" @"+NORM+" <"+GRN+"line"+NORM+">                   Add a line to the room description\n"+
      GRN+" list"+NORM+"                       Lists items stored\n"+
      GRN+" replace"+NORM+"                    Replace faulty items with a cookie\n"+
      GRN+" lock"+NORM+"                       Locks out other players\n"+
      GRN+" unlock"+NORM+"                     Unlock your door\n"+
      "   \n");
  return 1;
      case "khrell":
      write("Katarin's cheeks blush deeply and she giggles softly.\n");
  return 1;
  default:
     write("Katarin smiles at you and says: I don't know about that.\n");
  return 1;
  }
}
/*
get() {
      write("The book is too heavy and is attached to the table.\n");
    return 0;
}
*/
read(str){
   if(str!="book" && str!="output")
     return 0;
    if(str!="output")
   call_other("players/boltar/templar/private", "list_guests",0);
   if(str == "output")
    call_other("players/boltar/templar/private", "list_guests", 1);
   return 1;
}
