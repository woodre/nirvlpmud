
/*
 * Sunndi include file
 *
 */

#include "/players/molasar/sunndi/include/log.h"

#define SUNNDI_MASTER "/players/molasar/sunndi/sunndi_master"

/* Alignment adjustment values */
#define ALADJ_GUARD -2
#define ALADJ_BANDIT 2

void sunndi_add_alignment(int align);
int query_sunndi_alignment();
int query_player_alignment(string player);
void sunndi_add_player_alignment(string who, int align);
int query_sunndi_debug();
void sunndi_toggle_debug();

int query_sunndi_alignment() {
   int alignment;
   alignment = (int)call_other(SUNNDI_MASTER, "query_alignment", 0);
   return alignment;

}

void sunndi_add_alignment(int align) {
	call_other(SUNNDI_MASTER, "add_alignment", align);
}

int query_player_alignment(string player) {
   int alignment;
   alignment = (int)call_other(SUNNDI_MASTER, "query_player_alignment", player);
   return alignment;

}

void sunndi_add_player_alignment(string who, int align) {
   call_other(SUNNDI_MASTER, "add_player_alignment", who, align);
}

int query_sunndi_debug() {
   int flag;
   flag = (int)call_other(SUNNDI_MASTER, "query_debug", 0);
   return flag;
}

void sunndi_toggle_debug() {
   call_other(SUNNDI_MASTER, "toggle_debug", 0);
}
    
