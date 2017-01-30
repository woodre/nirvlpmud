#include "defs.h"
#define POWER previous_object()->query_skill("meditate")
#define COST 10 - POWER
inherit CMDBASE;

status
main(string str) {
  object spell;
  object ob;

  if(previous_object()->query_adr_con()){
  write("You cannot meditate with such an adrenaline rush!\n");
  return 1; }	

  skill_type = "telepathy";
  if(USER->query_ghost()) return 0;
  if( skill_check( 1 ) ) return 1;

  write("You concentrate on the force and feel it around you.\n");
  say(NAME(this_player())+" kneels down on one knee and closes "+POS+" eyes.\n");
  spell = clone_object( "/players/dragnar/Jedi/obj/meditate" );
  move_object(spell, this_player());
  return 1;
}
