#include "/obj/ansi.h"
#define IBUG(x) if(find_player("illarion")) tell_object(find_player("illarion"),x)
#define ROOT "/players/guilds/bards/"
#define LIB ROOT+"lib/"
#define SPELLS ROOT+"spells/"
#define OBJ ROOT+"obj/"
#define EMO ROOT+"emotions/"
#define TP this_player()
#define TO this_object()
#define tp this_player()->query_name()
#define OBJE(x) (string)x->query_objective()
#define PRON(x) (string)x->query_pronoun()
#define POSS(x) (string)x->query_possessive()
#define NAME(x) (string)x->query_name()
#define ADDCOLOR(x) (string)call_other(LIB+"addcolor","addcolor",x)
#define TPQ this_player()->query_real_name()
#define TARG capitalize(target)
#define TARGET find_player(target)
#define ALI (int)TP->query_alignment()
#define LEVEL TP->query_level()
#define ENV environment(TP)
#define SPELL TP->query_sp()
#define USER environment()
#define GOB present("bard_obj",TP) 
#define NOT_GOOD "Your soul is not balanced towards the light.\n"
#define NOT_LEVEL "You have not the power to use that ability yet.\n"
#define NOT_SP "You do not have the mana to use this ability.\n"
#define NO_PK "Bards do not have player killing spells.\n"
#define BARD_ON "You tune your instrument so as to hear your kin speak.\n"
#define BARD_OFF "You tune your instrument so that you will no longer hear your kin.\n"
#define CHANNEL "/players/guilds/bards/obj/channel_object.c"
#define PET "/players/guilds/bards/obj/pet_master.c"
#define SCALE "/players/guilds/bards/lib/scale.c"
#define NO_INSTRUMENT "WARNING: You have no guild object!  Tell Saber!\n"
#define FAIL(x) { notify_fail(x); return 0; }
#define CAP capitalize(str)
#define INST (string)GOB->query_instrument()
#define GENDER this_player()->query_possessive()
#define INV environment(this_object())
#define BLVL (int)(GOB->query_bard_level())
#define REALM call_other(environment(this_player()), "realm", 0)
#define MASTER "/players/guilds/bards/obj/master"
#define spell(a,b,c) (int)MASTER->check_spell(a,b,c)
#define attack_spell(a,b,c,d) (int)MASTER->check_attack_spell(a,b,c,d)
