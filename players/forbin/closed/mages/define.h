#include "/players/forbin/ansi.h"

#define GUILDNAME "mages"
#define GUILD_FILE "players/forbin/closed/mages/mageobj"
#define GCL HIC
#define DIR "/players/forbin/closed/mages/"
#define CMDDIR DIR+"cmd/"
#define SAVE_PATH DIR+"member/"
#define SAVE_BAK SAVE_PATH+"/bak/"
#define MAGE environment(this_object())

#define ENV(x) environment(x)
#define TP this_player()
#define TO this_object()
#define PO previous_object()

#define QNAME(x) (string)x->query_real_name()
#define QRNAME(x) (string)x->query_real_name()
#define QPNAME(x) CAP((string)x->query_real_name())

#define CAP(x) capitalize(x)
#define LOWER(x) lower_case(x)

#define POSSES(x) (string)x->query_possessive()
#define OBJECTIVE(x) (string)x->query_objective()
#define PRONOUN(x) (string)x->query_pronoun()

/* Tell Object of Environment - tell_object(environment(), what) */
#define TOE(ob,msg) if(ob) tell_object(ob, msg);

/* Tell Room of Environment - tell_room(environment(), what, ({ environment() })) */
#define TRE(ob,msg) if(ob && ENV(ob)) tell_room(ENV(ob), msg, ({ ob }));

/* Tell All of Environment - tell_room(environment(), what) */
#define TAE(ob,msg) if(ob) tell_room(ENV(ob), msg);