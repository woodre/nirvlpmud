/*
 * The purpose of this object is to house basic functionality used by the smart monsters.
 * Contents personal copyright Mizan@Nirvana, 2003.
 * Exclusive rights also to Boltar@Nirvana.
 * Reproduction on other muds restricted, under penalty of personal retribution.
 *
 */

#define TACTICAL_DM_SAVEFILE    "players/mizan/mbv2/tacticalDM"
#define NEXUS_DM_SAVEFILE       "players/mizan/mbv2/nexusDM"

#define LOCKERS         "/players/mizan/mbv2/ROOMS/locker01.c"
#define LOCKERS_ROOM    "players/mizan/mbv2/ROOMS/locker01.c"
#define LISTENING_ROOM  "players/mizan/core/02h/room08.c"

#define DAEMON_HOME     "/players/mizan/core/02h/room08.c"
#define MAXIMUM_BALANCE 1000000

/* misc */
#define RADIO_ID                   "walkie-talkieV2-on"
#define GOGGLES_ID                 "gogglesV2-on"

/* Please do not mess with anything below this line. */

/* the start of the object block */
#define ORDER_OBJECT_START          1

    /* an order block that harms objects */
#define ORDER_HARM_OBJECT_START    64
    /* we basically go suicide bomber (object) player/monster */
#define ORDERS_EXPLODE_OBJECT      65
    /* to follow and harrass an object (object) */
#define ORDERS_HARRASS_OBJECT      66
    /* goto object, fight for a few rounds, leave, and repeat (object) */
#define ORDERS_HITFADE_OBJECT      67
    /* to hound a creature, and attack it when it is down hps (object) */
#define ORDERS_HOUND_OBJECT        68
    /* attack, follow, hunt down an object (object) */    
#define ORDERS_HUNT_OBJECT         69
    /* specifically attack an object once encountered by chance (object)  */
#define ORDERS_KILL_OBJECT         70
    /* steal a player's kills */
#define ORDERS_STEALKILLS_OBJECT   71
/*IMPLEMENT! */
#define ORDERS_PESTER_OBJECT       72
#define ORDER_HARM_OBJECT_END      95




/* an order block that helps objects */
#define ORDER_HELP_OBJECT_START    96
   /* follow and protect an object at all costs (object) */
#define ORDERS_PROTECT_OBJECT      97
/*IMPLEMENT! */
#define ORDERS_COVER_OBJECT        98
/*IMPLEMENT! */
#define ORDERS_HEAL_OBJECT         99

#define ORDER_HELP_OBJECT_END     127

/* end object block */
#define ORDER_OBJECT_END          127



#define ORDER_STRING_START        128
/* an order block that harms by string */
#define ORDER_HARM_STRING_START   128
    /* to harrass anything with a name matching (string) */
#define ORDERS_HARRASS_NAME       129
    /* similar to hitfade object, but operates by player name instead */
#define ORDERS_HITFADE_NAME       130
    /* attack anyone with a guild name match (string) */
#define ORDERS_KILL_BY_GUILDNAME  131
    /* attack anyone with an ip address match (string) */
#define ORDERS_KILL_BY_IPADDR     132
    /* attack ANYTHING with a matching name (string) */
#define ORDERS_KILL_BY_NAME       133
    /* we hound and steal kills from a player name */
#define ORDERS_STEALKILLS_NAME    134
/*IMPLEMENT! */
#define ORDERS_PESTER_NAME        135

#define ORDER_HARM_STRING_END     136
#define ORDER_STRING_END          223



/* orders that are neutral */
#define ORDER_NEUTRAL_START       224
    /* defend a roomfile aggressively. Nothing gets past except fellow monsters (string) */
#define ORDERS_DEFEND_SPOT        225
    /* we basically go suicide bomber (string) roomname */
#define ORDERS_EXPLODE_SPOT       226
    /* to linger around a specific location, not wandering far from it (string) */
#define ORDERS_LOITER             227
#define ORDERS_INFUSE_NEXUS       228
    /* report to a position, and hold. (string) */
#define ORDERS_HOLD_POSITION      229
    /* to harrass anything with a name matching (string) */
#define ORDERS_HARRASS_IP         230
    /* orders the monster to wander exclusively inside a castle and kill all monsters on sight (string) creator */
#define ORDERS_PILLAGECASTLE      231
    /* orders the monster to loiter from a spot and pillage anything within its loiter radius (string) roomfile */
#define ORDERS_PILLAGELOITER      232
    /* to tell ourselves to get lost! */
#define ORDERS_DISMISS            254

#define ORDER_NEUTRAL_END         255



    /* think of a 'force' kind of command */
#define TASK_EXEC_CMD             10
#define TASK_INFUSE_NEXUS         11
    /* Earwax gets the credit for this idea. The monster sees if it has a 'bag' id object in its
       inventory and gives it to a player while in combat. This has the effect of disorienting script lusers
       who keep all their heals in bag */
#define TASK_BAGFLOOD             12
#define TASK_BE_INVISIBLE         13
#define TASK_BE_VISIBLE           14



/* event codes */
#define EVENT_ARRIVAL              1
#define EVENT_DEPARTURE            2
#define EVENT_STATUS_REPORT        3


/* our counters - these correspond to places in the array arr_counts. */

    /* how much time is elapsed on our orders */
#define COUNT_ORDERS_TIME          1
    /* when this reaches a threshold, we begin to actively hunt the player. */
#define COUNT_HUNTING_ROUNDS       2    
    /* if we have randomly given some cash to a newbie */
#define COUNT_HELPED_NEWBIES       3
    /* if we have jumped into a brawl lately */
#define COUNT_ASSISTED_ALLY        4
    /* how many times we may be bouncing off a room */
#define COUNT_TRAVEL_FUTILITY      5
    /* how many HP of healing we have drawn already from the nexus */
#define COUNT_HEAL_QUOTA           6
    /* a counter used to track how many junks we issue when tracking players */
#define COUNT_JUNK_FLAP            8
    /* a count of how many times we have used a command() to leave a room */
#define COUNT_MOTION               9
    /* a count of time before we infuse ourselves to the nexus */
#define COUNT_INFUSE_NEXUS        10
    /* how many corpses we have looted */
#define COUNT_CORPSES_LOOTED      11
    /* a running total of how many coins we have kicked back to the nexus. */
#define COUNT_COINS_INFUSED       12
    /* a running count of how many rounds we have been fighting the same creature. */
#define COUNT_COMBAT_ROUNDS       13
    /* a temp of how angry we are */
#define COUNT_EMOTIONAL_TEMP_ANGER  14
    /* a temp of how happy we are */
#define COUNT_EMOTIONAL_TEMP_HAPPY  15

#define COUNT_HEALQUOTA_CUTOFF    16


/* our toggles */
    /* if we communicate only basic messages on channels */
#define MODE_BRIEF                  1
    /* if we have been instructed to not use the radio */
#define MODE_RADIO_SILENCED         2
    /* if a monster is on orders, they cannot be bothered until the orders are finished, */
#define MODE_ON_ORDERS              3
    /* INTERNAL: a flag of whether or not we have accomplished our goal */
#define MODE_ORDERS_ACHIEVED        4
    /* INTERNAL: we are told to stop wandering for whatever reason (i.e. following others) */
#define MODE_STOP_MOVING            5
    /* if we pick fights with other players who are PK flag set */
#define MODE_PK_INSTIGATOR          6
    /* if this monster is able to call for backup */
#define MODE_CALLS_FOR_BACKUP       7
    /* INTERNAL: a setting that keeps us from spamming up and calling backup all the time */
#define MODE_HAS_CALLED_FOR_BACKUP  8
    /* note that we ate trying to SPARE the newbies not SPAR against them */
#define MODE_SPARING_NEWBIES        9
    /* INTERNAL: A state. If we are pillaging, we won't be bothered with anything unless a player attacks us */
#define MODE_PILLAGING             10
    /* if we throw shit at people on a regular basis */
#define MODE_SHIT_THROWER          11
    /* if we throw balloons at people on a regular basis. */
#define MODE_BALLOON_THROWER       12
    /* INTERNAL: a state issued by a mission, where we are instructed to not wimpy */
#define MODE_TO_THE_DEATH          13
    /* if we randomly attack kids */
#define MODE_KID_KILLER            14
    /* if we randomly attack kids */
#define MODE_PET_KILLER            15
    /* if we will cover for allies present that might be under attack */
#define MODE_COVERS_PRESENT_ALLIES 16
    /* if we make a lot of noise when arriving that other rooms know we are here */
#define MODE_NOISY_ARRIVE          17
    /* INTERNAL: turn on the snoop for the object */
#define MODE_SNOOP_ACTIVE          18
    /* If a monster is enabled to this flag, it will navigate away from the village center */
#define MODE_USE_REMOTE_WAYPOINTS  19
    /* if we chug down corpses we find instead of just carrying them. Use in conjunction with corpse looting percentage */
#define MODE_CORPSE_EATER          20
    /* INTERNAL: By default this is zero, meaning we are invis. */
#define MODE_IS_VISIBLE            21
    /* used if we want the monster to run slower hitfades- i.e. sticking around more and tporting less */
#define MODE_SLOW_HITFADES         22
    /* used if throw fireworks at our attackers */
#define MODE_FIREWORKS_THROWER     23
    /* INTERNAL: If we are pissed off. */
#define MODE_IS_PISSED_OFF         24

/* our attributes */
/* note that if the order of this is changed, it needs to be updated in monsterDM as well
 * for the variable my_attribnames;
 */
#define ATTRIB_VINDICTIVENESS       0
#define ATTRIB_FEARLESSNESS         1
#define ATTRIB_PERCEPTION           2
#define ATTRIB_CRUELTY              3
#define ATTRIB_INSANITY             4
#define ATTRIB_GENEROUSITY          5


/* our chance items */
#define CHANCE_CORPSE_LOOTING       0
#define CHANCE_TAKE_ALL_LOOT        1
#define CHANCE_EMOTE_ATTACKED       2
#define CHANCE_EMOTE_PANICKED       3
#define CHANCE_EMOTE_TAUNTING       4
#define CHANCE_EMOTE_TRIUMPH        5
#define CHANCE_EMOTE_CASUAL         6
#define CHANCE_EMOTE_SCARED         7
#define CHANCE_PELTING_THINGS       8



/* int settings */
    /* after X combat rounds, this monster begins to hunt the player attacking it */
#define VAL_HUNTING_THRESHOLD       2
    /* this is the point in gold coins that we have collected where we infuse... */
#define VAL_INFUSE_POINT            3
    /* the maximum amount in hitpoints of heals that we are allowed to draw */
#define VAL_MAX_HEAL_QUOTA          4
    /* how often we jet around from room to room */
#define VAL_RANDOM_MOVE_FREQUENCY   5



/* string settings */
    /* the name of our monster team. Avoid spaces and ANSI. */
#define STR_TEAM_NAME               1
    /* the name of our monster 'sub team'. It's an organizational thing, like '1st_division' of the 'usarmy' 
     * Avoid spaces and ANSI to be useful. */
#define STR_CABAL_NAME              2
    /* used internally, don't goof with this :) The previous roomname of where we were. Used to see
     * if we have been banging our heads on an exit for too long. */
#define STR_TRAVEL_PREVIOUS_ROOMNAME   3



/* object settings */
#define OBJ_TRAVEL_ATTACKER         2
    /* the player who is snooping us */
#define OBJ_SNOOP_VIEW              3
    /* something we throw at players */
#define OBJ_BALLOON                 4
    /* something we throw at PKers and people we don't like */
#define OBJ_SHITPILE                5
    /* the room we were in previously */
#define OBJ_TRAVEL_ROOM             6
    /* something we throw at players */
#define OBJ_FIREWORKS               7





/* eof */