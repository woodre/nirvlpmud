/*
	Color
*/
#include "/players/pain/color.h"

/*	
	Definitions
*/
#define OB "/players/pain/Legion/legion_ob"
#define BASE "/players/pain/Legion/guilddaem"
#define LEGION "players/pain/Legion/Legion/"
#define TP this_player()
#define TPN this_player()->query_name()
#define TPRN this_player()->query_real_name()
#define TPL this_player()->query_level()
#define TPXL  this_player()->query_extra_level()
#define TPAC this_player()->query_ac()
#define TPWC this_player()->query_wc()
#define TPHP this_player()->query_hp()
#define TPSP this_player()->query_spell_point()
#define TPSTR this_player()->query_attrib("str")
#define TPSTA this_player()->query_attrib("sta")
#define TPWIL this_player()->query_attrib("wil")
#define TPMAG this_player()->query_attrib("mag")
#define TPPIE this_player()->query_attrib("pie")
#define TPSTE this_player()->query_attrib("ste")
#define TPLUC this_player()->query_attrib("luc")
#define TPINT this_player()->query_attrib("int")
#define TPGEXP this_player()->query_guild_exp()
#define ETO environment(this_object())
#define TO this_object()
#define ROOM environment(this_player())

string muffs;
query_muffs() { return muffs; }
set_muffs(str) { muffs = str; }

int enrage;
query_enrage() { return enrage; }
set_enrage(str) { enrage = str; }

int multi_attack;
query_multi_attack() { return multi_attack; }
set_multi_attack(str) { multi_attack = str; }

int critical_hit;
query_critical_hit() { return critical_hit; }
set_critical_hit(str) { critical_hit = str; }

int extra_damage;
query_extra_damage() { return extra_damage; }
set_extra_damage(str) { extra_damage = str; }

int balance;
query_balance() { return balance; }
set_balance(str) { balance = str; }

int bury;
query_bury() { return bury; }
set_bury(str) { bury = str; }

int repair;
query_repair() { return repair; }
set_repair(str) { repair = str; }


