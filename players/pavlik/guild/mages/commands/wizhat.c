#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("wizhat");
  set_name("Wizard's Hat");
  set_color_name(HIC+"Wizard's Hat"+NORM);
  set_rank(6);
  set_descrip(
	"The Wizard's Hat is a powerful that can help Mages move " +
	"around more quickly.  The Wizhat is the guild's powerful " +
	"'speedster' tool.\n"
  );
}


cmd()
{
  object obj;

  if(tp->query_guild_rank() < query_rank())
	return 0;

  if(present("wiz_hat", tp))
  {
    notify_fail("You already have a hat!\n");
    return 0;
  }

  obj = clone_object(OBJ_DIR + "wiz_hat");
  move_object(obj, tp);

  write(
   "You pull an old beat up hat from your robes.\n"+
   "You dust off the shapeless cloth and place it on your head.\n"+
   "You smile.\n");
  say(
   ME+" pulls an old beat up hat from "+PO+" robes.\n"+
   ME+" places the shapeless mass on "+PO+" head.\n"+
   ME+" smiles.\n");

  return 1;
}


