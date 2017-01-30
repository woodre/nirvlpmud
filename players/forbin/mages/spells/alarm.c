#include "../def.h"

string s_spell_name()     { return "alarm"; }
string s_proper_name()    { return "Alarm"; }
   int s_spell_level()    { return 2; } 
string s_spell_school()   { return "abju"; }
string s_primary_stat()   { return "intelligence"; }
string s_secondary_stat() { return "will power"; }

/*
///////////////////////////////////////////////////////////////////// 
// Effect:     notifies player when someone enters the room
// Components: none
// Delay:      none (player can only have 2 active at any time)
// Files:      ~mages/obj/spells/alarm_obj.c
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