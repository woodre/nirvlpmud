/* elof.c - Smith for the blademasters.  Handles part 2 of joining and
            weapon upgrades.

            To join, a player needs level 5 and no guilds, plus 10,000
            coins and a wc 18+ weapon to sacrifice.

            To upgrade a weapon, the player's average attack skills
            (extra,enhanced, and crit) must average at least 10 times
            the value above 10 that the weapon would be upgraded to.
            (10 for wc 11, 50 for wc 15, and 100 for wc 20)

            Upgrading a weapon costs 8k*the amount the wc will be above
            10.  (8k for wc 11 up to 80k for wc 20)

            Wc 20 is the max
*/

#include "/players/illarion/guild/def.h"

#define P_COST 1000

inherit "obj/monster.c";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("elof");
  set_race("human");
  set_alias("smith");

  set_short("Elof, the smith");
  set_long(
"Elof is a tall, dark-haired man with the muscles and forearm scars of\n"+
"an accomplished smith.  His dark eyes burn with an inner fire which makes\n"+
"it impossible to meet his gaze for long.\n"+
"No one is really sure where Elof came from, or why he forges blades for\n"+
"Lan's students, but there's no denying the quality of the weapons he\n"+
"forges, though he's picky about who he will forge them for.\n\n"+
"You can ask him to "+BLD("forge")+" a weapon for you, or try to "+BLD("buy")+
"a weapon maintainence pouch from him.\n");
  set_level(20);
  set_hp(4000);
  set_wc(50);
  set_ac(30);
}

void init() {
  ::init();

  add_action("cmd_forge","forge");
  add_action("cmd_buy","buy");
}

status monster_respond(string what) {
  object padawan;
  object room;
  string name;
  padawan=this_player();
  room=environment();
  name=(string)this_object()->query_name();
  if(padawan && room && name && present(padawan,room)) {
    tell_object(padawan,format(name+" says, to you, \""+what+"\""));
    tell_room(room,format(name+" says, to "+padawan->query_name()+", \""+what+"\""),({padawan,this_object()}));
    return 1;
  }
  return 0;
}

status cmd_buy(string arg) {
  object gob;
  object p;
  object kit;
  if(!arg || arg!="pouch")
    return monster_respond("I only sell weapon maintainence pouches.");
  p=TP;
  gob=present(OB_NAME,p);
  if(!gob)
    return monster_respond("I only sell kits to blademasters and students.  "+
                           "It wouldn't do you any good anyway.");
  if((int)p->query_money() < P_COST)
    return monster_respond("Weapon maintainence pouches cost 1000 coins.  "+
    "The oils used aren't cheap, and making the honing stones isn't easy either.");
  kit=clone_object(GDIR+"obj/misc/skit");
  if(transfer(kit,p)) {
    destruct(kit);
    return monster_respond("You'll need to lighten your load a bit first.");
  }
  p->add_money(-P_COST);
  monster_respond("There you are.  One maintainence kit, in a convenient pouch.");
  write("You pay "+P_COST+" coins and recieve a pouch.\n");
}
