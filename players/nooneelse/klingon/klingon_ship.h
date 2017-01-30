/*
 klingon_ship.h - an include file with all the ship's room names
*/

#define KLINGON_BRIDGE "players/nooneelse/klingon/klingon_bridge"
#define KLINGON_CORRIDOR1 "players/nooneelse/klingon/klingon_corridor1"
#define KLINGON_CORRIDOR2 "players/nooneelse/klingon/klingon_corridor2"
#define KLINGON_CORRIDOR3 "players/nooneelse/klingon/klingon_corridor3"
#define KLINGON_CORRIDOR4 "players/nooneelse/klingon/klingon_corridor4"
#define KLINGON_CORRIDOR5 "players/nooneelse/klingon/klingon_corridor5"
#define KLINGON_CORRIDOR6 "players/nooneelse/klingon/klingon_corridor6"
#define KLINGON_SCIENCE "players/nooneelse/klingon/klingon_science"
#define KLINGON_MEDICAL "players/nooneelse/klingon/klingon_medical"
#define KLINGON_SECURITY "players/nooneelse/klingon/klingon_security"
#define KLINGON_WEAPON_LOCKER "players/nooneelse/klingon/klingon_weapon_locker"
#define KLINGON_CREW1 "players/nooneelse/klingon/klingon_crew1"
#define KLINGON_CREW2 "players/nooneelse/klingon/klingon_crew2"
#define KLINGON_CREW3 "players/nooneelse/klingon/klingon_crew3"
#define KLINGON_CREW4 "players/nooneelse/klingon/klingon_crew4"
#define KLINGON_ENGINEERING "players/nooneelse/klingon/klingon_engineering"
#define KLINGON_TRANSPORTER "players/nooneelse/klingon/klingon_transporter"
#define KLINGON_PHASER "players/nooneelse/klingon/klingon_phaser"
#define KLINGON_TORPEDO "players/nooneelse/klingon/klingon_torpedo"
#define KLINGON_AUX_BRIDGE "players/nooneelse/klingon/klingon_aux_bridge"
#define KLINGON_OFFICERS "players/nooneelse/klingon/klingon_officers"
#define KLINGON_FIRST_OFFICER "players/nooneelse/klingon/klingon_first_officer"
#define KLINGON_CAPTAIN "players/nooneelse/klingon/klingon_captain"

#define TELL_SHIP(str) \
  tell_room(KLINGON_BRIDGE, str); \
  tell_room(KLINGON_CORRIDOR1, str); \
  tell_room(KLINGON_CORRIDOR2, str); \
  tell_room(KLINGON_CORRIDOR3, str); \
  tell_room(KLINGON_CORRIDOR4, str); \
  tell_room(KLINGON_CORRIDOR5, str); \
  tell_room(KLINGON_CORRIDOR6, str); \
  tell_room(KLINGON_SCIENCE, str); \
  tell_room(KLINGON_MEDICAL, str); \
  tell_room(KLINGON_SECURITY, str); \
  tell_room(KLINGON_WEAPON_LOCKER, str); \
  tell_room(KLINGON_CREW1, str); \
  tell_room(KLINGON_CREW2, str); \
  tell_room(KLINGON_CREW3, str); \
  tell_room(KLINGON_CREW4, str); \
  tell_room(KLINGON_ENGINEERING, str); \
  tell_room(KLINGON_TRANSPORTER, str); \
  tell_room(KLINGON_PHASER, str); \
  tell_room(KLINGON_TORPEDO, str); \
  tell_room(KLINGON_AUX_BRIDGE, str); \
  tell_room(KLINGON_OFFICERS, str); \
  tell_room(KLINGON_FIRST_OFFICER, str); \
  tell_room(KLINGON_CAPTAIN, str);
