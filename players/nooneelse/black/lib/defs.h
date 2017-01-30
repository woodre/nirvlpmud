/*
  defs.h - vampire guild objects definitions
*/

#include "/players/nooneelse/ansi.h"

#define PAGESIZE  18
#define SHOP_DESTROY_VALUE 6000

#define LOGINMSG "enters the game and sends 'Hi Vamps!'"
#define LOGOUTMSG "has left the game after sending 'Bye Vamps'!"

/* tell my room, but not me */
#define  GUILD_MASTER          "Master"
#define  GUILD_ASSISTANT       "Vampire Underlord"
#define  GUILD_LIEUTENANT      "Lieutenant"

#define  VAMPIRE_BITE          "/players/nooneelse/black/vampire_bite"
#define  VAMPIRE_FANGS         "/players/nooneelse/black/vampire_fangs"
#define  VAMPIRE_FANGS_BASE    "/players/nooneelse/black/vampire_fangs_base"
#define VAMPIRE_DENTURES_BASE "/players/nooneelse/black/vampire_dentures_base"
#define  GUILD_NEWS            "/players/nooneelse/black/guild_news"
#define GUILD_SECONDS "players/nooneelse/black/guild_seconds"
#define  GUILD_TASKS           "/players/nooneelse/black/vampire_tasks.help"
#define  GUILD_HELP            "/players/nooneelse/black/hlp/"


/* guild rooms */
#define  MASTER_WORKROOM       "/players/nooneelse/workroom"

#define  GUILD_HALL            "/players/eurale/Vamp/RMS/vguild_hall"
#define  GUILD_LOWER_HALL      "/players/eurale/Vamp/RMS/vguild_hall"
#define  GUILD_MEMBER      "/players/nooneelse/black/guild_members_room.c"
/* /players/eurale/Vamp/RMS/vguild_hall */
#define  GUILD_SANCTUARY_ROOM  "/players/eurale/VAMPIRES/RMS/vguild_hall"
#define  GUILD_PROHIBIT        "/players/nooneelse/black/guild_prohibit"
#define GUILD_CHARITY "/players/eurale/VAMPIRES/RMS/donation"
#define  GUILD_COFFIN_ROOM     "/players/nooneelse/black/guild_coffin_room"
#define  GUILD_COFFIN          "/players/nooneelse/black/guild_coffin"
#define  GUILD_TRAINING        "/players/nooneelse/black/guild_training"
#define  GUILD_EQUIP           "/players/nooneelse/black/guild_equip"
#define  GUILD_SHOP            "/players/nooneelse/black/guild_shop"
#define  GUILD_SHOP_STOREROOM  "/players/nooneelse/black/guild_storeroom"

#define GUILD_OFFICE_FLOOR_TOP "/players/nooneelse/black/guild_office_floor_top"
#define  GUILD_OFFICE_TN       "/players/nooneelse/black/guild_office_tn"
#define  GUILD_OFFICE_TS       "/players/nooneelse/black/guild_office_ts"
#define  GUILD_OFFICE_TE       "/players/nooneelse/black/guild_office_te"
#define  GUILD_OFFICE_TW       "/players/nooneelse/black/guild_office_tw"
#define  GUILD_OFFICE_FLOOR_2  "/players/nooneelse/black/guild_office_floor_2"
#define  GUILD_OFFICE_2N       "/players/nooneelse/black/guild_office_2n"
#define  GUILD_OFFICE_2E       "/players/nooneelse/black/guild_office_2e"
#define  GUILD_OFFICE_2S       "/players/nooneelse/black/guild_office_2s"
#define  GUILD_OFFICE_2W       "/players/nooneelse/black/guild_office_2w"
#define  GUILD_OFFICE_FLOOR_1  "/players/nooneelse/black/guild_office_floor_1"
#define  GUILD_OFFICE_1N       "/players/nooneelse/black/guild_office_1n"
#define  GUILD_OFFICE_1E       "/players/nooneelse/black/guild_office_1e"
#define  GUILD_OFFICE_1S       "/players/nooneelse/black/guild_office_1s"
#define  GUILD_OFFICE_1W       "/players/nooneelse/black/guild_office_1w"

/* guild cloned items */
#define  VAMPIRE_PENANCE_MARK  "/players/nooneelse/black/guild_penance"
#define  VAMPIRE_SPEED         "/players/nooneelse/black/vampire_speed"
#define  VAMPIRE_SERVANT       "/players/nooneelse/black/vamp_servant"
#define  VAMPIRE_WOLF          "/players/nooneelse/black/vamp_guild_wolf"
#define  SNOOPER_BAT           "/players/nooneelse/black/snooper_bat"
#define  ALARM_BAT             "/players/nooneelse/black/alarm_bat"
#define  MAPPER_BAT            "/players/nooneelse/black/mapper_bat"
#define  VAMPIRE_FORM          "/players/nooneelse/closed/guild_form"
#define  VAMPIRE_CURSE         "/players/nooneelse/black/guild_damn_curse"
#define  GUILD_HOLE            "/players/nooneelse/black/guild_hole"
#define  ROOM_SEALER           "/players/nooneelse/black/guild_room_sealer"
#define  VAMPIRE_ILLUSION      "/players/nooneelse/black/illusion"
#define  VAMPIRE_PARLYZE_CURSE "/players/nooneelse/black/guild_paralyze_curse"
#define  VAMPIRE_GUILD_SUMMONS "/players/nooneelse/black/guild_summons"
#define  AMULET                "/players/nooneelse/obj/amulet"
#define  GUILD_NANNY_CURSE     "/players/nooneelse/black/guild_nanny_curse"
#define  PEEKER                "/players/nooneelse/obj/peeker"
#define  REGENERATE_SILENCE_OBJ "/players/nooneelse/black/regenerate_silence"
#define  REGENERATE_ROOM        "/players/nooneelse/black/regenerate_room"
#define  VAMPIRE_MIST          "/players/nooneelse/black/vampire_mist"
#define  VAMPIRE_DART          "/players/nooneelse/black/magic_dart"

/* items from processed & sewn skins */
#define  VAMPIRE_SKIN          "/players/nooneelse/black/skin"
#define  VAMPIRE_WOVEN_SKIN    "/players/nooneelse/black/woven_skin"
#define  VAMPIRE_TUXEDO        "/players/nooneelse/obj/tuxedo2"
#define  VAMPIRE_SILK_SHIRT    "/players/nooneelse/obj/silk_shirt"
#define  VAMPIRE_TOP_HAT       "/players/nooneelse/obj/top_hat"
#define  VAMPIRE_BOOTS         "/players/nooneelse/obj/boots"
#define  VAMPIRE_LINEN_GLOVES  "/players/nooneelse/obj/linen_gloves"
#define  VAMPIRE_SILK_TIE      "/players/nooneelse/obj/silk_tie"
#define  VAMPIRE_RUBY_RING     "/players/nooneelse/obj/ruby_ring"

/* guild definitions to check various stats in the player */
#define MY_FANGS           previous_object()
#define MY_PLAYER          environment(MY_FANGS)
#define MY_GUILD_EXP       MY_PLAYER->query_guild_exp()
#define MY_LEVEL           MY_PLAYER->query_level()
#define MY_SPELL_POINTS    MY_PLAYER->query_spell_point()
#define MY_HIT_POINTS      MY_PLAYER->query_hp()
#define MY_INTOXICATION    MY_PLAYER->query_intoxination()
#define MY_STUFFED         MY_PLAYER->query_stuffed()
#define MY_ALIGNMENT       MY_PLAYER->query_alignment()
#define MY_AC              MY_PLAYER->query_ac()
#define MY_WC              MY_PLAYER->query_wc()
#define MY_NAME                     MY_PLAYER->query_real_name()
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
