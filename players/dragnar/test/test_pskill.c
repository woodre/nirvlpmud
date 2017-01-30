#include <ansi.h>
#define PRES_SKILL_REGHP this_player()->query_prestige_skill( "reghp" )

id(string str) {

   return str == "test" || str == "tester";
}


init() {
   add_action("test","test");
}
reset(arg){
  if(arg) return;
}

short() { 
  return "Tester";
}


long() {
write("test\n");
}


test(string item) {
  int hp,intoxicated;
  intoxicated = this_player()->query_intoxication();
  
  if( PRES_SKILL_REGHP > random( PRES_SKILL_REGHP + 9 ) ) {
    hp += intoxicated ? (3 + PRES_SKILL_REGHP / 2) : (2 + PRES_SKILL_REGHP / 10);
    write("Regenerating :"+ hp + "\n");

  }

  return 1;
}

get() { return 1; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }

