/*
 Shadow Shadow, a blantent copy of  Vampire Shadow
 blantent copy of cyber hide-in-shadows
 */

#include "/players/eurale/defs.h"
#define NO_SHORT 17
object player,shgob;

Stest() {
  return "Shadow Shadow working..."; }

start_shadow_stuff(who) {
  player = who;
  shgob = present("shadow-mark", player);
  shadow(player, 1);
  return 1; }

test_dark() { return 0; }

stop_shadow_stuff() {
  shadow(player, 0);
  destruct(TO);
  return 1; }

quit() {
  object gob;
  gob = shgob;
  if (gob) gob->end_game();
  shadow(player,0);
  player->quit();
  return 1;
}

look(str) {
  object shadob;
  shadob = shgob;
  if(shadob) {
    shadob->light_up(3);
    player->look(str);
    shadob->light_up(-3); }
  else { player->look(str); }
return 1;
}

move_player(str) {
  object shadob;
  shadob = shgob;
  if(shadob) {
    shadob->light_up(3);
    if(!player->move_player(str)) { shadob->light_up(-3); }
    else shadob->light_up(-3); }
  else { player->move_player(str); }
}
check_shadows()
{
  object gob;
  gob = shgob;
  if (!gob) return 0;
  return gob->query_shadows();
}


short()
{
  int clvl,cste,cint,mylvl,myste,myint;
  if (check_shadows())
  {
    if(TP){
      clvl = TP->query_total_level(); mylvl=player->query_total_level();
      cste = TP->query_attrib("ste"); myste=player->query_attrib("ste");
      cint = TP->query_attrib("int"); myint=player->query_attrib("int");
    if (TP && TP->query_level() > 19)
       return player->short()+" (hiding in shadows)";
    else
    if ((clvl > mylvl && random(cint+cste) > 2*random(myint+myste)/3) ||
       (random(cint+cste) < random(myint+myste)))
       return player->short()+" (hiding in shadows)";
    else
      if(player->query_invis(TP->query_level(),TP->query_extra_level()) <
         NO_SHORT) return player->short()+" (hiding in shadows)";
    else
      return;
    }
  /* must be visiable to more powerful players! -Bp */
  }
  return player->short();
}
long()
{
  if (!TP ||
      (TP && !present("shadow-mark",TP) && check_shadows())) shadows_spotted();
  player->long();
}


shadows_spotted()
{
  object gob;
  tell_object(player,"You are no longer hidden.\n");
  if (TP) tell_object(TP, "You spot "+player->query_name()+" in the shadows.\n");
  gob = shgob;
  if (gob)
  {
    gob->set_shadows(0);
    gob->save_me();
  }
  return 1;
}

#include "shadow_move.h"
