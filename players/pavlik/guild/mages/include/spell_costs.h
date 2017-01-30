/*
 *--------------------------------
 *    Level 1 Spells
 *--------------------------------
 */

#define WERELITE_COST		15

#define SDAGGER_COST		25
#define SDAGGER_DAMAGE		5 + random(guild->query_total_guild_stat("illusion")) / 2
#define SDAGGER_COMPONENT_ID	"silver_needle"
#define SDAGGER_COMPONENT_COST	200

#define SAC_COST		0
#define SAC_HEAL		7 / 4
#define SAC_COMPONENT_ID	"corpse"

/* note: cost and damage are per missile */
#define MSSLE_COST		5
#define MSSLE_DAMAGE		random(guild->query_total_guild_stat("evocation") / 6)

#define MARK_COST		40

#define KNOWAL_COST		15

#define FFIRE_COST		10 + guild->query_spell_rank() / 2
#define FFIRE_AC_REDUCTION	1 + random(present("mageobj", owner)->query_total_conjuration() / 20)
#define FFIRE_MAX_REDUCTION	6

#define CTOUCH_COST		5 + (guild->query_spell_rank() / 4)
#define CTOUCH_DAMAGE		random(guild->query_total_guild_stat("necromancy") / 2)

/*
 *--------------------------------
 *    Level 2 Spells
 *--------------------------------
 */

#define WIZEYE_COST		30

#define QUERY_COST		20

#define PACIFY_COST		50

#define MBAG_COST		20

/* note: damage builds up over several rounds */
#define FSP_COST		25
#define FSP_DAMAGE		present("mageobj", owner)->query_total_guild_stat("conjuration") / 5
#define FSP_MAX_DAMAGE		50

#define CURE_COST		30
#define CURE_AMOUNT		20 + random(guild->query_total_guild_stat("necromancy") / 5);

#define BLIND_COST		35
#define BLIND_WC_REDUCTION	random(guild->query_total_guild_stat("illusion") / 12) + 1
#define BLIND_MAX_REDUCTION	6

/*
 *--------------------------------
 *    Level 3 Spells
 *--------------------------------
 */

#define USERV_COST		30

#define REVEAL_COST		30

#define KHIRSTEL_COST		50

#define ESHIELD_COST		60
#define ESHIELD_SHIELD_AMOUNT	guild->query_total_guild_stat("evocation") / 25
#define ESHIELD_MAX_HITS	60 + random(guild->query_total_guild_stat("intelligence"))
#define ESHIELD_COMPONENT_ID	"onyx_powder"
#define ESHIELD_COMPONENT_COST	900

#define CRUSH_COST		guild->query_total_guild_stat("necromancy") / 2

#define ALARM_COST		35

/*
 *--------------------------------
 *    Level 4 Spells
 *--------------------------------
 */

#define SUMMON_COST		100
#define SUMMON_COMPONENT_ID	"heartstone"
#define SUMMON_COMPONENT_COST	1500

#define LIFESTEAL_COST		40

#define FOOD_COST		15
#define FOOD_COMPONENT_ID	"corpse"

#define EDAGGER_COST		65
#define EDAGGER_MAX_WC		19

#define DETOX_COST		40

#define ACID_COST		50
#define ACID_DAMAGE		10 + random(guild->query_total_guild_stat("conjuration")) / 10
#define ACID_COMPONENT_ID	"sulfur_powder"
#define ACID_COMPONENT_COST	350

/*
 *--------------------------------
 *    Level 5 Spells
 *--------------------------------
 */

#define FBALL_COST		80
#define FBALL_TOTAL_DAMAGE	(guild->query_total_guild_stat("conjuration") + guild->query_total_guild_stat("intelligence"))

#define STONESKIN_COST			80
#define STONESKIN_COMPONENT_ID		"granite_powder"
#define STONESKIN_COMPONENT_COST	650

#define SOULTRAP_COST		0
#define SOULTRAP_COMPONENT_ID	"corpse"

#define AUGURY_COST		0

#define ABSORB_COST		50
#define ABSORB_AMOUNT		2 + random(guild->query_total_guild_stat("evocation")/5)
#define ABSORB_MAX_AMOUNT	15

/*
 *--------------------------------
 *    Level 6 Spells
 *--------------------------------
 */

#define TLP_COST		75

#define INVULN_COST		50

#define GSTR_COST		70
#define GSTR_AMOUNT		guild->query_total_guild_stat("enchantment") / 8
#define GSTR_MAX_AMOUNT		10
#define GSTR_EXPIRE		(guild->query_total_guild_stat("power") * 4) / 3

/*
 *--------------------------------
 *    Level 7 Spells
 *--------------------------------
 */

#define ANDEAD_COST		65
#define ANDEAD_COMPONENT_ID	"corpse"

/* note: cost is per image (max 4) */
#define MIMAGE_COST		40
#define MIMAGE_IMAGE_COST	20
#define MIMAGE_MAX_IMAGES      3
#define MIMAGE_COMPONENT_ID	"platinum_mirror"
#define MIMAGE_COMPONENT_COST	8000

#define ENCHANT_COST		160
#define ENCHANT_AMOUNT		1 + random(guild->query_total_guild_stat("enchantment")/10)
#define ENCHANT_MAX_AMOUNT	10

#define CLOUDKILL_COST		200
#define CLOUDKILL_MAX_DAMAGE	300
#define CLOUDKILL_MAX_TARGETS	5
#define CLOUDKILL_MAX_HBS	5

