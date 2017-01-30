/* ************************************************
 * Command Base
 *
 * - Earwax 1/14/04
 *
 * Just a small inherit for commands.
 *
 * ************************************************
*/

#pragma weak_types

#include "../defs.h"

/* Command Requirements */
int glevel() { return 1; }
int grank() { return 1; }
int hp_cost() { return 0; }
int sp_cost() { return 0; }
int req_pk() { return 0; }
int sac_cost() { return 0; }
int exp_cost() { return 0; }
string req_task() { return ""; }
int arg() { return 0; }
string *components() { return ({ }); }

/* Collect the requirements and send them to command daemon
 * as one nice little package.
*/
mixed *query_reqs(string path) { return ({ path, glevel(), grank(), req_pk(), hp_cost(), sp_cost(), sac_cost(), exp_cost(), req_task(), arg(), sizeof(components()) }); }

/* Make it easy to use custom failure messages */
status failure_msg(string arg) { COMMANDSD->set_msg(arg); return 0; }

/* Have this as a blank function, for use with catch() */
void reset(status arg) { return; }
