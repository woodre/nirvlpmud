/* Let's equip someone!
 * Args: who - who to equip
 *       heals - equip heals only
 */

#define BAG "/players/forbin/realms/misc/OBJ/saddlebag"
#define MISC "/players/khrell/armors/skaven/acowl"
#define SCARF "/players/angel/area/school/obj/flow_scarf_01"
#define ORB "/players/jaraxle/3rd/alt/items/healing_orb"
#define MASK "/players/jaraxle/closed/phoenix/mask"
#define UNDERWEAR "/players/vertebraker/swamp/OBJ/denim_shorts"
#define EARRING "/players/vertebraker/swamp/OBJ/j_earring"
#define GLOVES "/players/jenny/wings/items/sblocker"
#define BELT "/players/valen/area/catacombs/armors/d_belt"
#define PANTS "/players/tallos/7tigers/objects/dragon_legs"
#define ARMOR "/players/arrina/armor/sveil"
#define WEAP "/players/jareel/weapons/orlanth/fiona_sword"
#define BRACELET "/players/maledicta/cont/rdragon/sbracers"
#define NECKLACE "/players/khrell/armors/skaven/foulpendant"
#define HELMET "/players/vertebraker/misc/cj/cj_face"
#define BOOTS "/players/fred/closed/bloodfist/eq/combat_boots"
#define RING "/players/eurale/Chess/OBJ/ring"
#define GRAVSTONE "/players/padrone/obj/gravstone"
#define CLOAK "/players/zeus/museum/OBJ/cloak"
#define SHIELD "/players/jareel/armor/chaos/tin_shield"
#define AMULET "/players/feldegast/equip/wandereye"
#define CHEST "/players/maledicta/cont/armor/guard_of_health"
#define HEAL "/players/pestilence/amity/obj/lvshake"
#define HEAL2 "/players/fred/closed/bloodfist/obj/water"

status requip(string str) {
  object plyr;
  string who, arg;
  int i, gravs, heals;

  if (sscanf(str, "%s %s", who, arg) != 2) return 0;
  plyr = find_player(who);
  gravs = 12;
  heals = 12;
  if (!plyr) {
    write(capitalize(who)+ " isn't playing at the moment!\nAborting!!\n");
    return 1;
  }
  if (arg != "heals") {
    write("Equipping " + plyr->query_name() +" for duty!\n");
    move_object(clone_object(BAG),       plyr);
    move_object(clone_object(MISC),      plyr);
    move_object(clone_object(SCARF),     plyr);
    move_object(clone_object(ORB),       plyr);
    move_object(clone_object(MASK),      plyr);
    move_object(clone_object(UNDERWEAR), plyr);
    move_object(clone_object(EARRING),   plyr);
    move_object(clone_object(GLOVES),    plyr);
    move_object(clone_object(BELT),      plyr);
    move_object(clone_object(PANTS),     plyr);
    move_object(clone_object(ARMOR),     plyr);
    move_object(clone_object(WEAP),      plyr);
    move_object(clone_object(BRACELET),  plyr);
    move_object(clone_object(NECKLACE),  plyr);
    move_object(clone_object(HELMET),    plyr);
    move_object(clone_object(BOOTS),     plyr);
    move_object(clone_object(RING),      plyr);
    move_object(clone_object(CLOAK),     plyr);
    move_object(clone_object(SHIELD),    plyr);
    move_object(clone_object(AMULET),    plyr);
    move_object(clone_object(CHEST),     plyr);
    for (i = 0; i < gravs; i++)
      move_object(clone_object(GRAVSTONE), plyr);
    for (i=0; i<heals; i++) {
      move_object(clone_object(HEAL),  present("saddlebag", plyr));
      move_object(clone_object(HEAL2), present("saddlebag", plyr));
    }
    write("Equipment moved into " + plyr->query_name()+"!\n");
    command("ready",          plyr);
    command("wear mask",      plyr);
    command("wear saddlebag", plyr);
    command("activate orb",   plyr);
    return 1;
  }
  else if (arg == "heals") {
    for (i=0; i<heals; i++) {
      move_object(clone_object(HEAL),  present("saddlebag", plyr));
      move_object(clone_object(HEAL2), present("saddlebag", plyr));
    }
    write("Heals replenished!\n");
    return 1;
  }
  notify_fail("Usage requip <who> <heals?>\n");
  return 0;
}
