#ifndef _sys_event_h
#define _sys_event_h

#define EPRIO_MODIFY    600
#define EPRIO_MODIFY2   700
#define EPRIO_MODIFY3   800
#define EPRIO_CANCEL    300
#define EPRIO_CANCEL2   400
#define EPRIO_CANCEL3   500
#define EPRIO_HANDLE      0
#define EPRIO_HANDLE2   100
#define EPRIO_HANDLE3   200
// if you want different notice-priorities, use an offset
// like EPRIO_NOTICE+offset
#define EPRIO_NOTICE  (-300)

#define EPRIO_NOTICE2 (EPRIO_NOTICE+1) // for compatibility
#define EPRIO_NOTICE3 (EPRIO_NOTICE+2) // for compatibility

#define E_TYPE             "?"
#define E_HANDLER          "@"
#define E_HANDLER_PRIORITY "!"

#define EH_DEFAULT       0
#define EH_NORMAL       10
#define EH_OVERRIDE     20

// These fields are put into the event-mapping automatically
#define E_COMMAND       "command"     // given (event-causing) command
#define E_SENDER        "sender"
#define E_RECEIVERS     "receivers"
// The next few are to prevent too deep recursions
#define E_MODIFIERS     "modifiers"   // those who (maybe) modified
#define E_PREVENTERS    "preventers"  // those who (maybe) prevented
#define E_HANDLERS      "handlers"    // those who (maybe) handled
#define E_REACTORS      "reactors"    // those who (maybe) reacted
#define E_HANDLED       "handled"     // handled (by whom)
#define E_CANCELLED     "cancelled"   // cancelled (by whom)

#define E_TIME          "time"        // time of sending of the event
#define E_AGENT         "agent"       // The acting person causing the event
#define E_CO_AGENTS     "co_agents"   // who is acting with the agent
#define E_TARGET        "target"      // target(s) for the event
#define E_TOOL          "tool"        // tool providing the event-action
#define E_WITH          "with"        // helping thing
#define E_WEAPON        "weapon"      // weapon for combat-related events
#define E_DAMAGE        "damage"      // damage caused by the event
#define E_WOUND         "wound"       // wound caused by the event
#define E_DAMAGE_TYPE   "damage_type" // 2nd field of E_DAMAGE or E_TYPE
#define E_ACTION        "action"      // action sending the event
#define E_SUCCESS       "success"     // success of the action/event
#define E_SKILL         "skill"       // skill(s) tested by/for the event
#define E_DIFFICULTY    "difficulty"  // difficulty of the event-action
#define E_RANGE         "range"       // range of the event
#define E_MODE          "mode"        // mode of the event
#define E_PHASE         "phase"       // phase of the event

#define E_OBJECT        "object"      // an object involved in the event
#define E_LINKED        "linked"      // objects that are linked (somehow)
#define E_RECIPIENT     "recipient"   // an object receiving something
#define E_WHERE         "where"       // a location
#define E_BODY          "body"        
#define E_CONTAINER     "container"   // a container from which sth. is dropped

// For combat-related events
#define E_DEFENSE       "defense"
#define E_DEFENSE_TYPE  "defense_type"
#define E_ATTACK        "attack"
#define E_ATTACK_TYPE   "attack_type"

// if this is set with an object, it will be used instead of the standard
// death mark /room/death/death_mark, Chameloid, 09-Aug-96
#define E_DEATH_MARK "death_mark"

// added by Carador, 29-Sep-93, for /bin/soul.c
#define E_FEELING       "feeling"
#define E_PERSONS       "persons"
#define E_ADVERBS       "adverbs"
#define E_BODYPARTS     "bodyparts"
#define E_REMOTE_TARGET "remote_target"  // for the remote target(s), who also
                              // see feelings of other rooms, Coogan, 02-Jul-01

#define E_FROM          "from"
#define E_TO            "to"
#define E_DIR           "dir"
#define E_IN            "in"
#define E_OUT           "out"
#define E_CMD           "cmd"  // the command to be done after a move

// added by Ugh, 19-Oct-93, for message-event in /global/commands/comm.c
#define E_MSG_TYPE      "msgtype"
#define E_RECIPIENTS    "recipients"
#define E_MSG           "message"
#define E_MESSAGES      "messages"

#define E_ID     "id"  // inserted by Ugh for targets where the id is needed
#define E_NUMBER "number" // moved here from /global/commands/move,
                          // Chameloid, 12-Oct-97
#define E_TEXT          "text"
#define E_TONGUE        "tongue"

#define E_AGENT_MSG     "agent_msg"
#define E_ROOM_MSG      "room_msg"
#define E_NOTIFY_FAIL   "notify_fail"
#define E_KEY           "key"
#define E_PREPOSITION   "preposition"
#define E_PARTNER       "partner"

// some additions required for Magic (Mentar 19-Sep-94)
#define E_MAGIC         "magic"
#define E_ART           "art"
#define E_LORE          "lore"
#define E_REQUISITE     "requisite"
#define E_SPELL         "spell"
#define E_COMPONENT     "component"
#define E_LEVEL         "level"
#define E_COST          "cost"
#define E_DELAY         "delay"
#define E_EXTRA_DELAY   "extra_delay"

// some additions for the quest event, Chameloid, 07-Jul-96
#define E_QUEST         "quest"
#define E_REWARD        "reward"
#define E_QP_REWARD     "qp_reward"
#define E_FIRST_SOLVING "first_solving"

// some additions for the consume, eat, drink and poison event, Coogan, Jan-98
#define E_ALCOHOL_RATE       "alcohol_rate"
#define E_BODY_HEALING_RATE  "body_healing_rate"  // Coogan, 13-Jan-01
#define E_MIND_HEALING_RATE  "mind_healing_rate"  // Coogan, 13-Jan-01
#define E_AMOUNT             "amount"

#define E_POISON_RATE   "poison_rate"
#define E_POISON_SPEED  "poison_speed"

// for the modify_skill event:
#define E_MODIFICATION  "modification"

// for the quit_really event:
#define E_EQUIPMENT     "equipment"  // the equipment to be stored

// for the play [instrument] event, Coogan, 15-Jan-02
#define E_MELODY        "melody"    // 0th value: object, 1st value: string

#endif /* _sys_event_h */

