/*
  defs.h - alchemist ALCHEMIST objects definitions
*/

#include "/players/nooneelse/ansi.h"

#define PAGESIZE  18
#define SHOP_DESTROY_VALUE 6000

#define LOGINMSG "enters the game and sends 'Ho fellow Alchemists!'"
#define LOGOUTMSG "has left the game after sending 'Bye fellow Alchemists'!"

#define  ALCHEMIST_MASTER          "Grand Master"
#define  ALCHEMIST_GUILD_MASTER    "nooneelse"

#define  POUCH                     "/players/nooneelse/Alchemist/pouch"
#define  POUCH_BASE                "/players/nooneelse/Alchemist/pouch_base"
#define  ALCHEMIST_NEWS            "/players/nooneelse/Alchemist/alchemist_news"
#define  ALCHEMIST_HELP            "/players/nooneelse/Alchemist/hlp/"
#define  ALCHEMIST_LIB             "/players/nooneelse/Alchemist/lib/"

/* Achemist rooms */
#define  MASTER_WORKROOM           "/players/nooneelse/workroom"

#define  ALCHEMIST_ENTRANCE        "/players/nooneelse/Alchemist/room/entrance"
#define  ALCHEMIST_LOBBY           "/players/nooneelse/Alchemist/room/lobby"
#define  ALCHEMIST_CENTRAL         "/players/nooneelse/Alchemist/room/central"
#define  ALCHEMIST_MEMBER          "/players/nooneelse/Alchemist/room/central"
#define  ALCHEMIST_DONATION        "/players/nooneelse/Alchemist/room/donation"
#define  ALCHEMIST_PUB             "/players/nooneelse/Alchemist/room/pub"
#define  ALCHEMIST_SHOP            "/players/nooneelse/Alchemist/room/shop"
#define  ALCHEMIST_STOREROOM       "/players/nooneelse/Alchemist/room/storeroom"
#define  ALCHEMIST_P_BOARD         "/players/nooneelse/Alchemist/room/player_board_room"
#define  ALCHEMIST_SHELF           "/players/nooneelse/Alchemist/room/shelf"
#define  ALCHEMIST_COMPONENT       "/players/nooneelse/Alchemist/room/component"
#define  ALCHEMIST_W_BOARD         "/players/nooneelse/Alchemist/room/wizard_board_room"
#define  ALCHEMIST_PROHIBIT        "/players/nooneelse/Alchemist/room/prohibit"
#define  ALCHEMIST_SANCTUARY       "/players/nooneelse/Alchemist/room/central"

/* Alchemist special directories */
#define  ALCHEMIST_COMPONENTS      "/players/nooneelse/Alchemist/member/components/"

/* Achemist cloned items */
#define  ALCHEMIST_PENANCE_MARK    "/players/nooneelse/Alchemist/obj/misc/alchemist_penance_mark"
#define  ALCHEMIST_RAVEN           "/players/nooneelse/Alchemist/mon/raven.c"
#define  ALCHEMIST_VAMPIRE         "/players/nooneelse/Alchemist/mon/vampire.c"
#define  AIR_ELEMENTAL             "/players/nooneelse/Alchemist/obj/misc/air_elemental"
#define  EARTH_ELEMENTAL           "/players/nooneelse/Alchemist/obj/misc/earth_elemental"
#define  FIRE_ELEMENTAL            "/players/nooneelse/Alchemist/obj/misc/fire_elemental"
#define  ALCHEMIST_POISON          "/players/nooneelse/Alchemist/obj/weapon/alchemist_poison"
#define  ALCHEMIST_SUMMONS         "/players/nooneelse/Alchemist/obj/misc/alchemist_summons"
#define  ALCHEMIST_HOLE            "/players/nooneelse/Alchemist/obj/misc/alchemist_hole.c"
#define  ALCHEMIST_STONE_SKIN      "/players/nooneelse/Alchemist/obj/armor/stone_skin.c"
#define  ALCHEMIST_RESERVE_MONSTER "/players/nooneelse/Alchemist/obj/misc/reserve_monster.c"

/* items from processed & sewn skins */
#define  ALCHEMIST_SKIN            "/players/nooneelse/Alchemist/obj/armor/skin"
#define  ALCHEMIST_WOVEN_SKIN      "/players/nooneelse/Alchemist/obj/armor/woven_skin"
#define  ALCHEMIST_LEATHER_ARMOR   "/players/nooneelse/Alchemist/obj/armor/leather_armor"
#define  ALCHEMIST_CLOAK           "/players/nooneelse/Alchemist/obj/armor/cloak"
#define  ALCHEMIST_SKULL_CAP       "/players/nooneelse/Alchemist/obj/armor/skull_cap"
#define  ALCHEMIST_BOOTS           "/players/nooneelse/Alchemist/obj/armor/boots"
#define  ALCHEMIST_LEATHER_GLOVES  "/players/nooneelse/Alchemist/obj/armor/leather_gloves"
#define  ALCHEMIST_AMULET          "/players/nooneelse/Alchemist/obj/armor/amulet"
#define  ALCHEMIST_RUBY_RING       "/players/nooneelse/Alchemist/obj/armor/ruby_ring"

/* ALCHEMIST definitions to check various stats in the player */
#define MY_POUCH           previous_object()
#define MY_PLAYER          environment(MY_POUCH)
#define MY_ROOM            environment(MY_PLAYER)
#define MY_ALCHEMIST_EXP   MY_PLAYER->query_guild_exp()
#define MY_ALCHEMIST_RANK  MY_PLAYER->query_guild_rank()
#define MY_LEVEL           MY_PLAYER->query_level()
#define MY_SPELL_POINTS    MY_PLAYER->query_spell_point()
#define MY_HIT_POINTS      MY_PLAYER->query_hp()
#define MY_INTOXICATION    MY_PLAYER->query_intoxination()
#define MY_STUFFED         MY_PLAYER->query_stuffed()
#define MY_ALIGNMENT       MY_PLAYER->query_alignment()
#define MY_AC              MY_PLAYER->query_ac()
#define MY_WC              MY_PLAYER->query_wc()
#define MY_NAME            lower_case(MY_PLAYER->query_real_name())
#define MY_NAME_CAP        capitalize(MY_PLAYER->query_real_name())
#define MY_ROOM            environment(MY_PLAYER)
#define MY_STR             MY_PLAYER->query_attrib("str")
#define MY_STA             MY_PLAYER->query_attrib("sta")
#define MY_WIL             MY_PLAYER->query_attrib("wil")
#define MY_MAG             MY_PLAYER->query_attrib("mag")
#define MY_PIE             MY_PLAYER->query_attrib("pie")
#define MY_STE             MY_PLAYER->query_attrib("ste")
#define MY_LUC             MY_PLAYER->query_attrib("luc")
#define MY_INT             MY_PLAYER->query_attrib("int")

/* him, her, it */
#define MY_OBJECTIVE       MY_PLAYER->query_objective()
/* his, hers, its */
#define MY_POSSESSIVE      MY_PLAYER->query_possessive()
/* he, she, it */
#define MY_PRONOUN         MY_PLAYER->query_pronoun()
