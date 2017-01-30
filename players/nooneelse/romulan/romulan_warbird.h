/*
 romulan_warbird.h - an include file with all the warbird's room names
*/

#define ROMULAN_BRIDGE "players/nooneelse/romulan/romulan_bridge"
#define ROMULAN_CORRIDOR1 "players/nooneelse/romulan/romulan_corridor1"
#define ROMULAN_CORRIDOR2 "players/nooneelse/romulan/romulan_corridor2"
#define ROMULAN_CREW1 "players/nooneelse/romulan/romulan_crew1"
#define ROMULAN_CREW2 "players/nooneelse/romulan/romulan_crew2"
#define ROMULAN_ENGINEERING "players/nooneelse/romulan/romulan_engineering"
#define ROMULAN_TRANSPORTER "players/nooneelse/romulan/romulan_transporter"
#define ROMULAN_PHASER "players/nooneelse/romulan/romulan_phaser"
#define ROMULAN_TORPEDO "players/nooneelse/romulan/romulan_torpedo"
#define ROMULAN_FIRST_OFFICER "players/nooneelse/romulan/romulan_first_officer"
#define ROMULAN_CAPTAIN "players/nooneelse/romulan/romulan_captain"

#define TELL_SHIP(str) \
  tell_room(ROMULAN_BRIDGE, str); \
  tell_room(ROMULAN_CORRIDOR1, str); \
  tell_room(ROMULAN_CORRIDOR2, str); \
  tell_room(ROMULAN_CREW1, str); \
  tell_room(ROMULAN_CREW2, str); \
  tell_room(ROMULAN_ENGINEERING, str); \
  tell_room(ROMULAN_TRANSPORTER, str); \
  tell_room(ROMULAN_PHASER, str); \
  tell_room(ROMULAN_TORPEDO, str); \
  tell_room(ROMULAN_FIRST_OFFICER, str); \
  tell_room(ROMULAN_CAPTAIN, str);
