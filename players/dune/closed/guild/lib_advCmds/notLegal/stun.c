#include "../DEFS.h"
#define LEVEL  8

status main(string str) {
  object targ, stunob;
  int mysp, mylev, oplev;
  int artlev;

  write("Guild stun command: not yet approved -Snow\n");
  return 1;
  if(!gotrank(TP, LEVEL)) return 0;
  if(!str) { 
    write("Usage: stun <player>.\n"); 
    return 1; }
  artlev = (int)IPTP->query_art_level();
  stunob = clone_object(OBJDIR+"/stun_blow.c");
  mysp   = (int)TP->query_sp();
  mylev  = (int)TP->query_level();
  targ   = present(str,environment(TP));
  oplev  = (int)targ->query_level();
  if(!targ) { 
    write(capitalize(str)+" is not here.\n"); 
    return 1; }
  if(!living(targ)) { 
    write(capitalize(str)+" is not alive!\n"); 
    return 1; }
  if(targ != (object)TP->query_attack()) {
    write("You must be fighting what you want to stun.\n"); 
    return 1; }
  if(present("stun_blow",targ)) {
    write(capitalize(str)+" is already stunned!\n"); 
    return 1; }
  if(!gotsp(TP, artlev)) return 1;
  if(targ->is_player() && mylev < oplev) {
    write(capitalize(str)+" is too strong for your stunning blow.\n");
    return 1; }
  write("You smash your fingers into "+capitalize(str)+"'s neck!\n");
  tell_object(targ, "You feel a brief blinding pain!\n");
  tell_room(environment(TP), capitalize(str)+" goes limp and is stunned!\n");
  move_object(stunob, targ);
  stunob->destruct_stun(artlev * 2);
  TP->add_spell_point(-artlev);
  return 1;
}
