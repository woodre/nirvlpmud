#ifndef ROBES
#include "/obj/ansi.h"
#define TP this_player()
#define TPN TP->query_name()
#define TPRN TP->query_real_name()
#define TR tell_room
#define TE tell_object
#define TO this_object() 
#define MO move_object
#define CO clone_object
#define ENV environment
#define USER ENV(TO)
#define ATT USER->query_attack()
#define ATTN ATT->query_name()
#define LVL USER->query_level()
#define XLVL USER->query_extra_level()
#define STR USER->query_attrib("str")
#define STA USER->query_attrib("sta")
#define MAGIC USER->query_attrib("mag")
#define LUC USER->query_attrib("luc")
#define WIL USER->query_attrib("wil")
#define DEX USER->query_attrib("dex")
#define INT USER->query_attrib("int")
#define CHA USER->query_attrib("cha")
#define PIE USER->query_attrib("pie")
#define STE USER->query_attrib("ste")
#define POS USER->query_possessive()
#define OBJ USER->query_objective()
#define PRO USER->query_pronoun()
#define RANK USER->query_guild_rank()
#define TOU TE(USER,
#define TRU TR(ENV(USER),
#define SAVE_PATH "players/fred/mages/member/"
#define SAVE_PATH2 "players/fred/mages/member/backup/"
#define ROBES "mage_armor"
#endif
