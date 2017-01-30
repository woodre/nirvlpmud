#include "/players/fred/mages/defs.h"

cmd_revert(){
 if(USER->liched()){
   USER->quit_lich();
   return 1; }
 if(USER->dknighted()){
   USER->quit_dk();
   return 1; }
 else{
  write("You are in your original form already.\n");
  return 1; }
}
