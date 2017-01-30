set_plevel(str){ powerlevel = DAEMON->set_power(str); return 1; }
set_type(str){ major_type = str; return 1; }
set_location(str){ location = str; return 1; }
query_plevel() { return powerlevel; }
query_type() { return major_type; }
query_location() { return location; }
query_major_info(str) { return major_map[str]; }
add_spell(str) { spelllist += ({ str }); }
remove_spell(str) { spelllist -= ({ str }); }

static invoke_spell(str) { return DAEMON->invoke_spell(str); }
static cone_att() { return DAEMON->cone_att(); }
disperse() { return DAEMON->disperse(); }

ghelp_cmd(str){ return DAEMON->ghelp_cmd(str); }
gwho_cmd(){ return DAEMON->gwho_cmd(); }
channel_cmd(str){ return DAEMON->channel_cmd(str); }
new_sc(){ return DAEMON->new_sc(); }
