#define robe present("mrobe", environment(this_player()))
#define member this_player()
#define tpl this_player()->query_level()
#define tps robe->query_spirit_points()
#define tpn this_player()->query_name()
#define poss this_player()->query_possessive()
#define c_mod robe->query_cure_modifier()
#define train_fail "You do not have the training to cure your wounds.\n"
#define spirit_fail "You do not have the spirit points for this.\n"
#define init_chant "You begin to chant quietly, concentrating on your wounds\n"
#define cure "You ask for God's help in healing your "+how+" wounds.\n"
#define ucure "You ask for God's help in healing "+target+"'s "+how+" wounds.\n"
#define p_cure tpn+" prays for your "+how+" wounds.\n"
#define g_msg "God envelops you in His love, healing your wounds.\n";
#define a_mod robe->query_a_spell_modifier()



int cure_modifier;	/*The druid cure skill*/
int a_spell_modifier;	/*The druid attack spell skill*/
int weap_modifier;	/*The druid weapon skill*/
int def_modifier;	/*The druid deflection modifier*/
int muffs;		/*The muffles for the guild channel*/
int color;		/*Color on or off?*/

query_cure_modifier() { return cure_modifier; }
query_a_spell_modifier() { return a_spell_modifier; }
query_weap_modifier() { return weap_modifier; }
query_def_modifier() { return def_modifier; }
query_muffs() { return muffs; }
query_color() { return color; }

set_cure_modifier(str) { cure_modifier = str; }
set_a_spell_modifier(str) { a_spell_modifier = str; }
set_weap_modifier(str) { weap_modifier = str; }
set_def_modifier(str) { def_modifier = str; }
set_muffs(str) { muffs = str; }
set_color(str) { color = str; }

