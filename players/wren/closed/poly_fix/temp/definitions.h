/*
 * definitions.h
 *
 *
 */

/* The current version of this thing, used by 'guild version' */
#define CURRENT_VERSION          "Polymorph Toaster Daemon V4R1M0"
#define CURRENT_VERSION_BUILD    "PDM4.c - Spawn #10"
#define CURRENT_VERSION_DATE     "11 August 2001"

/* The id of the guild objects */
#define GUILD_ID    "Mizan-guild-object"

/* The id of morph form objects (spheres) */
#define MORPH_ID    "Mizan-morph-object"

/* The guild name, as it is used in set_guild_name() */
#define GUILDNAME   "polymorph"

/* The root path of guild files */
#define PATHNAME    "/players/mizan/closed/poly/"

/* The location of the gob */
#define GUILDFILE   PATHNAME + "gob.c"

/* The directory for help files of the guild */
#define HELPDIR     PATHNAME + "help/"

/* Message of the day */
#define MOTD        PATHNAME + "motd.txt"

/* New developments */
#define DEVSTUFF    PATHNAME + "devstuff.txt"

/* The listing of all possible polymorph forms */
#define POLYLIST    HELPDIR + "forms"

/* credits for various people who contributed */
#define CREDITS     PATHNAME + "credits.txt"

/* The place where this daemon will sit happily. */
#define HOME        "/players/mizan/etheriel/ROOMS/linna"

/* The directory where actions are logged */
#define LOGPATH     "/players/mizan/logs/"

/* The GC level of the guild. GC's are in essence powerless. */
#define GC          20

/* The exp required before a player can do damage exceeding the damage cap */
#define BASELINE_EXP   160000

/* The legal damage cap of magic per combat round of the game. */
#define MAGIC_DAMAGE_CAP      55

/* The legal damage cap of extra limbs per combat round of the game. */
#define COMBAT_DAMAGE_CAP     40

/* The text object where news articles is stored. */
#define NEWSFILE "players/mizan/closed/poly/NEWSFILE"

/*
 * These are the divisors for damage above the damage cap

 */

/* superhard hits are 100+ the damage cap. SHOULD NOT HAPPEN! 
 * We charge them at least 150 exp per damage point. 
 */
#define SUPERHARD_DAMAGE_DIV     500

/*
 * extrahard hits are 75 - 100 over the damage cap. At least 80 exp
 * per damage point.
 */
#define EXTRAHARD_DAMAGE_DIV     500

/*
 * veryhard hits are 50 - 75 over the damage cap.
 */
#define VERYHARD_DAMAGE_DIV       180

/* hard hits are 25 - 50 over the damage cap. More common.
 */
#define HARD_DAMAGE_DIV           90

/* light over the damage cap. Most common. 1-25 over.
 */
#define LIGHT_DAMAGE_DIV          45

/* [1] */
#define POLY_SPUCKBALL                 0
#define POLY_PUFFERFISH                1
#define POLY_WOMBAT                    2

#define POLY_SPUCKBALL_COST        60
#define POLY_PUFFERFISH_COST       10
#define POLY_PUFFERFISH_FORM       "/players/mizan/closed/poly/pufferfish-form"
#define POLY_WOMBAT_COST           50

/* [2] */
#define POLY_GOLEM                     3
#define POLY_TREE                      4
#define POLY_CATAPULT                  5
#define POLY_LOAFY                     6

#define POLY_GOLEM_COST           120
#define POLY_TREE_COST            200
#define POLY_CATAPULT_COST         85
#define POLY_CATAPULT_FORM        "/players/mizan/closed/poly/catapult-form"
#define POLY_LOAFY_COST           220

/* [3] */
#define POLY_FUNGOID                   7
#define POLY_SPONGE                    8
#define POLY_SPR                       9
#define POLY_TREEHOUSE                10
#define POLY_WUMPUS                   11

#define POLY_FUNGOID_COST         250
#define POLY_SPONGE_COST          250
#define POLY_SPR_COST             330
#define POLY_TREEHOUSE_COST       200
#define POLY_TREEHOUSE_FORM       "/players/mizan/closed/poly/treehouse-form"
#define POLY_WUMPUS_COST          450

/* [4] */
#define POLY_REPLICANT                12
#define POLY_PUFFBALL                 13
#define POLY_SHOUTBOX                 14
#define POLY_JUNGLE_SLUG              15
#define POLY_OCTOPUS                  16

#define POLY_REPLICANT_COST       500
#define POLY_PUFFBALL_COST        400
#define POLY_SHOUTBOX_COST        440
#define POLY_JUNGLE_SLUG_COST     250
#define POLY_OCTOPUS_COST         500

/* [5] */
#define POLY_TETRAPOD                 17
#define POLY_BOG                      18
#define POLY_SPUCKTROOPER             19
#define POLY_MIMIC                    20
#define POLY_COW                      21

#define POLY_TETRAPOD_COST        700
#define POLY_BOG_COST             550
#define POLY_SPUCKTROOPER_COST    120
#define POLY_MIMIC_COST            50
#define POLY_MIMIC_FORM           "/players/mizan/closed/poly/mimic-form"
#define POLY_COW_COST             450

/* [6] */
#define POLY_DIVYA                    22
#define POLY_JUGGERNAUT               23
#define POLY_NECROMONGER              24
#define POLY_GAMBLER                  25
#define POLY_SPUCKMOBILE              27
#define POLY_BABOON                   28

#define POLY_DIVYA_COST           960
#define POLY_JUGGERNAUT_COST      960
#define POLY_NECROMONGER_COST     500
#define POLY_GAMBLER_COST         500
#define POLY_SPUCKMOBILE_COST     250
#define POLY_SPUCKMOBILE_FORM     "/players/mizan/closed/poly/spuckmobile-form"
#define POLY_BABOON_COST          400

/* [7] */
#define POLY_PHB                      26
#define POLY_HIGH_MIMIC               29
#define POLY_DARK_TETRAPOD            30
#define POLY_WEREWOMBAT               32
#define POLY_SHAMEN                   33

#define POLY_PHB_COST             850
#define POLY_HIGH_MIMIC_COST       75
#define POLY_HIGH_MIMIC_FORM     "/players/mizan/closed/poly/high_mimic-form"
#define POLY_DARK_TETRAPOD_COST  1000
#define POLY_WEREWOMBAT_COST      500
#define POLY_SHAMEN_COST          300

/* [21] */
#define POLY_TESTFORM                31

#define POLY_TESTFORM_COST          1


/*
 * ORDER-> cmorph, sta, int, mag, str, ste, luck
 */

/* [1] */
#define POLY_SPUCKBALL_STAT       "spuckball#spuckball#2#-20#-1#1#-3#2"
#define POLY_PUFFERFISH_STAT      "pufferfish#pufferfish#-20#-20#-20#-20#-20#-20"
#define POLY_WOMBAT_STAT          "wombat#wombat#-6#-17#-6#2#-16#10"

/* [2] */
#define POLY_GOLEM_STAT           "golem#golem#4#-8#-20#4#-6#-2"
#define POLY_TREE_STAT            "tree#fruit tree#2#-20#-20#0#-20#-7"
#define POLY_CATAPULT_STAT        "catapult#catapult#0#0#0#0#0#0"
#define POLY_LOAFY_STAT           "loafy#loafy dog#0#0#0#0#0#0"

/* [3] */
#define POLY_FUNGOID_STAT         "fungoid#fungoid#2#-18#-18#2#-6#-3"
#define POLY_SPONGE_STAT          "sponge#sponge#" + (10+random(15)) + "#-18#-19#5#-19#1"
#define POLY_SPR_STAT             "blobel#blobel#-6#3#3#-10#-6#0"
#define POLY_TREEHOUSE_STAT       "treehouse#treehouse#0#0#0#0#0#0"
#define POLY_WUMPUS_STAT          "wumpus#wumpus#5#-9#-20#5#-3#4"

/* [4] */
#define POLY_REPLICANT_STAT       "replicant#replicant#4#4#4#4#4#4"
#define POLY_PUFFBALL_STAT        "puffball#puffball#-11#3#7#-13#2#2"
#define POLY_SHOUTBOX_STAT        "shoutbox#shoutbox#-6#-7#4#9#-13#-10"
#define POLY_JUNGLE_SLUG_STAT     "jungle_slug#jungle slug#0#0#0#0#0#0"
#define POLY_OCTOPUS_STAT         "octopus#octopus#1#10#2#-4#-9#-4"

/* [5] */
#define POLY_TETRAPOD_STAT        "tetrapod#tetrapod#6#-20#-20#5#-7#-4"
#define POLY_BOG_STAT             "bogglemancer#bogglemancer#-3#-2#6#-1#-1#8"
#define POLY_SPUCKTROOPER_STAT    "spucktrooper#Spucktrooper#4#-5#-3#6#-7#2"
#define POLY_MIMIC_STAT           "mimic#mimic#0#0#0#0#0#0"
#define POLY_COW_STAT             "cow#cow#0#0#0#0#0#0"

/* [6] */
#define POLY_DIVYA_STAT           "divya#divya#-3#5#9#-5#-5#9"
#define POLY_JUGGERNAUT_STAT      "juggernaut#juggernaut#10#-10#10#15#-20#-5"
#define POLY_NECROMONGER_STAT     "necromonger#necromonger#-18#20#20#-20#-20#20"
/* note that POLY_GAMBLER_STAT is not defined here. Generated randomly. */
#define POLY_SPUCKMOBILE_STAT     "spuckmobile#spuckmobile#0#0#0#0#0#0"
#define POLY_BABOON_STAT          "baboon#baboon#2#-3#-2#4#4#0"

/* [7] */
#define POLY_PHB_STAT             "phb#pointy haired boss#5#-20#20#4#-6#20"
#define POLY_HIGH_MIMIC_STAT      "high_mimic#High mimic#0#0#0#0#0#0"
#define POLY_DARK_TETRAPOD_STAT   "dark_tetrapod#dark tetrapod#10#-13#-12#9#-4#10"
#define POLY_WEREWOMBAT_STAT      "werewombat#werewombat#0#0#0#0#0#0"
#define POLY_SHAMEN_STAT          "shamen#shamen#0#0#0#0#0#0"

/* [8] */


/* [21] */
#define POLY_TESTFORM_STAT        "testform#testform#0#0#0#0#0#0"


/* ---- Spell costs --- */

#define ESCAPE_COST      20
#define ETHER_COST       20
#define SURVEY_COST      10

#define ATOMIZE_COST     15
#define REGAIN_COST       3
#define HELPME_COST       7


#define SPUCKBALL_SQUIT_COST      10

#define WOMBAT_BURROW_COST         5
#define WOMBAT_BURROW                "players/mizan/closed/poly/wombat_burrow"
#define WOMBAT_BURROW_ENTRANCE       "players/mizan/closed/poly/wombat_burrow_e"
#define LOOSEN_OBJECT                "/players/mizan/closed/poly/wombat_drag.c"
#define LOOSEN_ID                    "drag_device"
#define WOMBAT_FORAGE_COST        16
#define WOMBAT_CHOMP_COST          8

#define FUNGOID_GRIBBLE_COST      12
#define FUNGOID_PUFF_COST         15
#define FUNGOID_SPOG_COST         18

#define BLOBEL_CONFUSION_COST     25
#define BLOBEL_UNFROG_COST        85
#define BLOBEL_DEEPSURVEY_COST     5
#define BLOBEL_TUCK_COST          40

#define SPONGE_EVALUATE_COST       5

#define SHOUTBOX_SUPERBLINK_COST  15
#define SHOUTBOX_SHRILL_COST      25
#define SHOUTBOX_HOLLER_COST      18
#define SHOUTBOX_CURSE_COST       15
#define SHOUTBOX_CALM_COST        55
#define SHOUTBOX_REVERB_COST      60

#define OCTOPUS_INKJET_COST       60

#define PUFFBALL_FRY_COST         40
#define PUFFBALL_VAPORIZE_COST    45

#define BOG_SPEEDBALL_COST        42
#define BOG_ZOKWAVE_COST          45
#define BOG_CHARBROIL_COST        40
#define BOG_SANDBAG_COST          30
#define BOG_TREE_COST             36
#define BOG_LINT_COST             25
#define BOG_PIANO_COST            40
#define BOG_ANVIL_COST            32

#define TETRAPOD_BLITZ_COST       60

#define SPUCKTROOPER_SQUIT_COST   45

#define DARK_TETRAPOD_CLOAK_COST  60
#define DARK_TETRAPOD_CLOAK_FORM    "/players/mizan/closed/poly/dark_tetrapod-cloak.c"

#define NECRO_COLDSUCK_COST       90

