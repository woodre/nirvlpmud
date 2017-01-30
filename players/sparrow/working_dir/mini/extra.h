#define TP this_player()
#define tp this_player()->query_name()
#define TPQ this_player()->query_real_name()
#define TARG capitalize(target)
#define TARGET find_player(target)
#define ALI (int) TP->query_alignment()
#define LEVEL TP->query_level()
#define ENV environment(TP)
#define SPELL TP->query_sp()
#define NOT_GOOD "Your soul is not balanced towards the light.\n"
#define NOT_LEVEL "You have not the power to use that ability yet.\n"
#define NOT_SP "You do not have the mana to use this ability.\n"
#define CAP capitalize(str)
#define NO_PK "NO PLAYER KILLING\n"
#define GENDER this_player()->query_possessive()
#define INV environment(this_object())
#define REALM call_other(environment(this_player()), "realm", 0)
#define POSS this_player()->query_possessive()
#define OBJE this_player()->query_objective()
#define OOBJ ob->query_objective()
#define POS2 ob->query_possessive()
#define PRO2 ob->query_pronoun()
#define THAT if(!ob) { write(capitalize(str)+" is not here.\n"); return 1; }
#define OJN ob->query_name()

int spell(int cutoff_ali, int min_level, int sp_cost) {
if(ALI<cutoff_ali) {notify_fail(NOT_GOOD); return -1;}
if(LEVEL<min_level) {notify_fail(NOT_LEVEL); return -1;}
if(SPELL<sp_cost) {notify_fail(NOT_SP); return -1;}
return 1;
        }

int attack_spell(int cutoff_ali, int min_level, int sp_cost, object ob) {
if(spell(cutoff_ali, min_level, sp_cost) ==-1) return -1;
if(TP->query_ghost()) {notify_fail("You must be alive to do that.\n"); return -1;}
if(!ob){notify_fail("That is not here.\n"); return -1;  }
if(!living(ob)) {notify_fail("Target must be alive to do that.\n"); return -1;}
if(ob->is_player()) {notify_fail(NO_PK); return -1;}
return 1;
        }
