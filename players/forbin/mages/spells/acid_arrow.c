#include "../def.h"

string s_spell_name()     { return "acid arrow"; }
string s_proper_name()    { return "Acid Arrow"; }
   int s_spell_level()    { return 2; } 
string s_spell_school()   { return "evoc"; }
string s_primary_stat()   { return "will power"; }
string s_secondary_stat() { return "power"; }
int s_spell_delay()       { return 20; }

/*
///////////////////////////////////////////////////////////////////// 
// Effect:     12+random(evoc/5) damage followed by 
//             4 rounds 2+random(evoc/20) damage 
// Cost:       
// Components: none
// Delay:      none
// Files:      ~mages/obj/spells/acid_arrow_obj.c
/////////////////////////////////////////////////////////////////////
/*

/* info() is used by guild NPC to inform player about spell */
status info(object gob, object player) 
{
  
}

/* help() is called from mhelp and is the help information about spell */
status help(object gob, object player) 
{
  
}

/* main is called from cast.c command and is the bulk of the spell */
status main(string str, object gob, object player) 
{
  
}