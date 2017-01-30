#define NEW_SPELLS "/players/guilds/bards/spells/"
#define EMO "/players/guilds/bards/emotions/"
#define TP this_player()
#define TO this_object()
#define tp this_player()->query_name()
#define TPQ this_player()->query_real_name()
#define TARG capitalize(target)
#define TARGET find_player(target)
#define ROOT "/players/saber/closed/bards/spell"
#define ADDCOLOR(x) (string)call_other("/players/guilds/bards/lib/addcolor","addcolor",x)
#define ALI (int) TP->query_alignment()
#define LEVEL TP->query_level()
#define ENV environment(TP)
#define SPELL TP->query_sp()
#define USER environment()
#define NOT_GOOD "Your soul is not balanced towards the light.\n"
#define NOT_LEVEL "You have not the power to use that ability yet.\n"
#define NOT_SP "You do not have the mana to use this ability.\n"
#define NO_PK "Bards do not have player killing spells.\n"
#define BARD_ON "You tune your instrument so as to hear your kin speak.\n"
#define BARD_OFF "You tune your instrument so that you will no longer hear your kin.\n"
#define CHANNEL "/players/guilds/bards/obj/channel_object.c"
#define NO_INSTRUMENT "WARNING: You have no guild object!  Tell Saber!\n"
#define CAP capitalize(str)
#define INST this_object()->query_instrument()
#define GENDER this_player()->query_possessive()
#define INV environment(this_object())
#define BLVL TO->query_bard_level()
#define REALM call_other(environment(this_player()), "realm", 0)
#define MASTER "/players/guilds/bards/obj/master"

int spell(int cutoff_ali, int min_level, int sp_cost) {
if(locked){ notify_fail("Your powers are frozen.\n"); return -1; }
if(TP->query_ghost()){notify_fail("You must be alive to do that.\n"); return -1;}
if(ALI<cutoff_ali) {notify_fail(NOT_GOOD); return -1;}
if(BLVL<min_level) {notify_fail(NOT_LEVEL); return -1;}
if(SPELL<sp_cost) {notify_fail(NOT_SP); return -1;}
if((string)environment(TP)->realm() == "NM"){ notify_fail("Your power is gone here.\n"); return -1; }
return 1;
        }

int attack_spell(int cutoff_ali, int min_level, int sp_cost, object ob) {
if(locked){ notify_fail("Your powers are frozen.\n"); return -1; }
if(spell(cutoff_ali, min_level, sp_cost) ==-1) return -1;
if(TP->query_ghost()) {notify_fail("You must be alive to do that.\n"); return -1;}
if(!ob){notify_fail("That is not here.\n"); return -1;  }
if(!living(ob)) {notify_fail("Target must be alive to do that.\n"); return -1;}
if(ob->is_player()) {notify_fail(NO_PK); return -1;}
if((string)environment(TP)->realm() == "NM"){ notify_fail("Your power is gone here.\n"); return -1; }
return 1;
        }
