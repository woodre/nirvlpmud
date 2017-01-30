/* Quick function to setup equipment for Paven (my Test dood)
 */

#define BAG "/players/rumplemintz/obj/illegal_bag"
#define MISC "/players/khrell/armors/skaven/acowl"
#define SCARF "/players/angel/area/school/obj/flow_scarf_01"
#define ORB "/players/jaraxle/3rd/alt/items/nature_orb"
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
#define BOOTS "/players/jenny/bundy/items/shoelights"
#define RING "/players/angel/area/school/obj/mason_ring_01"
#define GRAVSTONE "/players/padrone/obj/gravstone"
#define CLOAK "/players/zeus/museum/OBJ/cloak"
#define SHIELD "/players/jareel/armor/chaos/tin_shield"
#define AMULET "/players/feldegast/equip/wandereye"
#define CHEST "/players/maledicta/cont/armor/guard_of_health"
#define HEAL "/players/rumplemintz/obj/heal"

status rpav() {
  object pav;
  int i, gravs;

  pav = find_player("paven");
  gravs = 12;
  if (!pav) {
    write("Paven isn't playing at the moment!\nAborting!!\n");
    return 1;
  }
  write("Equipping test-character Paven for duty!\n");
  move_object(clone_object(BAG), pav);
  move_object(clone_object(MISC), pav);
  move_object(clone_object(SCARF), pav);
  move_object(clone_object(ORB), pav);
  move_object(clone_object(MASK), pav);
  move_object(clone_object(UNDERWEAR), pav);
  move_object(clone_object(EARRING), pav);
  move_object(clone_object(GLOVES), pav);
  move_object(clone_object(BELT), pav);
  move_object(clone_object(PANTS), pav);
  move_object(clone_object(ARMOR), pav);
  move_object(clone_object(WEAP), pav);
  move_object(clone_object(BRACELET), pav);
  move_object(clone_object(NECKLACE), pav);
  move_object(clone_object(HELMET), pav);
  move_object(clone_object(BOOTS), pav);
  move_object(clone_object(RING), pav);
  move_object(clone_object(CLOAK), pav);
  move_object(clone_object(SHIELD), pav);
  move_object(clone_object(AMULET), pav);
  move_object(clone_object(CHEST), pav);
  move_object(clone_object(HEAL), pav);
  for (i = 0; i < gravs; i++)
    move_object(clone_object(GRAVSTONE), pav);
  write("Equipment moved into Paven!\n");
  command("ready", pav);
  command("wear mask", pav);
  command("activate orb", pav);
  return 1;
}
