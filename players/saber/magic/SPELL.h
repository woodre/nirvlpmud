#define TP this_player()
#define TO this_object()
#define tp this_player()->query_name()
#define ALI (int) TP->query_alignment()
#define LEVEL TP->query_level()
#define SPELL TP->query_sp()
#define NOT_LEVEL "You have not the power to use that ability yet.\n"
#define NOT_SP "You do not have the mana to use this ability.\n"
#define NO_PK "These spells may not be used against players.\n"
#define GENDER this_player()->query_possessive()
#define REALM call_other(environment(this_player()), "realm", 0)

int spell(int min_level, int sp_cost)  {
if(LEVEL<min_level) {notify_fail(NOT_LEVEL); return -1;}
if(SPELL<sp_cost) {notify_fail(NOT_SP); return -1;}
return 1;
        }

int attack_spell(int min_level, int sp_cost, object ob)  {
if(spell(min_level, sp_cost) == -1) return -1;
if(TP->query_ghost()) {notify_fail("You must be alive to do that.\n"); return -1;}
if(!living(ob)) {notify_fail("Target must be alive to do that.\n"); return -1;}
if(ob->is_player()) {notify_fail(NO_PK); return -1;}
return 1;
        }
