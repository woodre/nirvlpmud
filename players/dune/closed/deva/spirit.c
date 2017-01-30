/*
 * Ascension, by Dune and Snow
 * Code shell by Dragnar, Balowski
 */
#include "def.h"

#define BEAT     5
#define DISALLOW ({"mi","missile","fireball","fi","shock","sh",\
                   "so","sonic","marry"})

static status   legion_flag;    /* does player haave spirit legion */
int*            settings;       /* array of guild cmd settings */
static mapping  cmds, nocmds;   /* [command : file] - list */

id(str) { return str == GUILDID || str == "notarmor"; }

long() { write("\
  Your immortal spirit is of pure goodness.\
  Type 'holy' for your divine graces.\n"); }

extra_look() {
    if (this_player() == environment())
	return "Your shining spirit radiates heavenly light";
    else
	return environment()->query_name() +
	"'s shining spirit radiates heavenly light"; }

query_auto_load() { return AUTOLOAD; }
init_arg(x) { cat(NEWS); }

reset(arg) {
  if(!arg) {
    remove_call_out("fake_beat");
    call_out("fake_beat", BEAT);
    }
  return 1; }

init() {
    object shad;
    if (environment() == this_player()) {
	restore_object(SAVEDIR + this_player()->query_real_name());
        prepare_settings();
        TP->set_title("the "+LEVELD->get_title(settings[CLASS]));
	TP->set_guild_name(GUILDNAME);

	if (cmds = ACTIOND->query_cmds(settings[DISGRACE])) {
	    string *ks; int i;
	    i = sizeof(ks = keys(cmds));
	    while (i--) add_action("cmd_hook", ks[i]);
	    }
        set_light(settings[CLASS] + 3);
        shad = clone_object("/players/dune/closed/deva/deva_shadow.c");
        shad->start_deva_shadow(TP);

        /* code for disallowed cmds here */
        i = sizeof(ks = DISALLOW);
        nocmds = allocate_mapping(i);
        while (i--) add_action("not_allowed", ks[i]);
        }
}

drop()          { return 1; }
get()           { return 1; }
status query_legion() { return legion_flag; }
set_legion(status lg) { legion_flag = lg; }

cmd_hook(string str) {
    string cmd;
    if (cmd = cmds[query_verb()]) return (status) cmd->main(str); }

not_allowed(string str) {
    tell_object(TP, "This action is forbidden.\n");
    return 1; }

prepare_settings() { 
    int i, size;
    int* tmp_settings;
    tmp_settings = allocate(SETSIZE);
    size = sizeof(settings);
    if(size > SETSIZE) size = SETSIZE;
    for(i = 0; i < size; i++) tmp_settings[i] = settings[i];
    settings = allocate(SETSIZE);
    for(i = 0; i < size; i++) settings[i] = tmp_settings[i]; }

int query_setting(int index)      { return settings[index]; }
set_setting(int index, int value) { settings[index] = value; }

save_me() {
    string name;
    save_object(SAVEDIR + 
    environment()->query_real_name()); }

restore_me() {
    int x;
    x = restore_object(SAVEDIR +
        environment()->query_real_name());
    return x; }

fake_beat() {
    BEATD->fake_beat(ME);
    call_out("fake_beat", BEAT, ME);
    return 1; }
