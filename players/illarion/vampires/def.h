#include <ansi.h>

#define ROOT "/players/illarion/vampires/"
#define ARM "/players/illarion/vampires/arm/"
#define LIB "/players/illarion/vampires/lib/"
#define LIBBASE "/players/illarion/vampires/lib/base"
#define OBJ "/players/illarion/vampires/obj/"
#define ROOM "/players/illarion/vampires/room/"
#define SOUL "/players/illarion/vampires/soul/"
#define WEP "/players/illarion/vampires/wep/"
#define SAVE "players/illarion/vampires/save/"
#define INC "/players/illarion/vampires/inc/"
#define GOB "/players/illarion/vampires/gob.c"
#define DAEM "/players/illarion/vampires/daem/daemon.c"
#define SKDAEM "/players/illarion/vampires/daem/skill_daem.c"
#define HEALDAEM "/players/illarion/vampires/daem/heal_daem.c"
#define COMDAEM "/players/illarion/vampires/daem/com_daem.c"
#define DOC "/players/illarion/vampires/doc/"

#define GID "illarion_vampire_fangs"
#define BUFF     OBJ+"buff_obj.c"
#define BUFFID   "vampire_buff_ob"
#define DEBUFF   OBJ+"debuff_obj.c"
#define DEBUFFID "vampire_debuff_ob"

#define FAIL(x) { if(x) notify_fail(x); return 0; }
#define TP this_player()
#define TO this_object()
#define ETO environment()
#define ENV(x) environment(x)
