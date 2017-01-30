/*  Guilds Related Defines for easier coding  */
/*  Please use these defines when editing in  */
/*  the vampire guild directories. This will  */
/*  help maintain consistency across all the  */
/*  guild files.                              */

/*  Vampire information  */
#define MEMBER "/players/nooneelse/black/guild_members_room.c"
#define TRAITOR "/players/nooneelse/black/guild_prohibit.c"
#define TOP_FLOOR "/players/nooneelse/black/guild_office_floor_top.c"
#define COFFIN_ROOM "/players/nooneelse/black/guild_coffin_room"
#define COFFIN "/players/nooneelse/black/guild_coffin"

/*  Guild Directories  */
#define BASE            "/players/guilds/vampires/"
#define ROOMS           BASE  + "rooms/"
#define COMMAND         BASE  + "commands/"
#define VEMOTES         BASE  + "emotes/"
#define OBJ             BASE  + "obj/"
#define NPC             BASE  + "npc/"
#define DOC             BASE  + "doc/"
#define FANGS           BASE  + "vampob.c"
#define BITE            OBJ   + "vampire_bite.c"
#define SUMMONS         OBJ   + "summons.c"
#define SANCTUARY_ROOM  ROOMS + "vguild_hall.c"
#define TRIAL_ROOM      ROOMS + "trial_room.c"
#define VAMP_WOLF       NPC   + "vamp_wolf.c"
#define FORM            NPC   + "guild_form.c"
#define HELP            BASE  + "help/"
#define LOG             BASE  + "log/"
#define GUILDOBJ        BASE  + "vampob.c"
#define GUILDNAME       "Vampires"
#define DELIMITER   ","

#define PFANGS present("vampire fangs",TP)
#define TPBPTS PFANGS->query("blood_points")
#define GXP    TP->query_guild_exp()
#define GRANK  TP->query_guild_rank()

/*  Guild Ranking and Positions */
#define BLOOD_RANK  "Blood"
#define DIRE_RANK   "Dire"
#define SHADOW_RANK "Shadow"
#define SPIRIT_RANK "Spirit"
#define MASTER      "Master"
#define ASSISTANT   "Vampire Underlord"
#define LIEUTENANT  "Lieutenant"
