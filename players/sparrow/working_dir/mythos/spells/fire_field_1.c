#include "/players/mythos/closed/guild/def.h"
#define eep environment(ep)

object targ;
id(str) {return str == "fire_field_1";}

get() { return 0;}
drop() { return 1;}

extra_look() {
  return "A Crackling Field of "+HIB+"COLD FIRE"+NORM+" surrounds "+
           capitalize(epn);
}

reset(arg) {
  if(arg) return;
  call_out("flash",3);
}

flash() {
if(!ep) return 1;
  if(ep->query_ghost()) { 
    tell_object(ep,"Your fire field vanishes!\n"); 
    destruct(this_object());
  return 1;}
  if(ep->query_attack()) {
    targ = ep->query_attack();
    if(targ->is_player() && !(targ->id("masakado")) && !(targ->id("amoril")) &&
       !(targ->id("jinro")) && !epp) {
         tell_object(ep,"Your fire field flashes briefly, however it dims because\n"+
               "this spell may not harm players at this time.\n");
          destruct(this_object());
    return 1;}
    if(present("fielded",targ)) {
      tell_object(ep,"A Fire Field may only work on a target once.\n");
      destruct(this_object());
    return 1;}
    tell_room(eep,CLR+HOME);
    tell_room(eep,"\n\n\n\n\n\n\n");
    tell_room(eep,"\n"+HIB+
          "                                        *     *    *\n"+
          "                                 *        *          *    *\n"+
          "                                       *             *        *\n"+NORM);   
  tell_room(eep,HIB+"                        *        *               *               *\n"+
          "                      *       *        *                  *         *\n"+
          "                             *                    *               *        \n"+NORM);
  tell_room(eep,HIB+"                  *           *             *              *            *\n"+
          "                *        *     *         *       *            *           *\n"+
          "                            *      *                  *               *     *\n"+NORM);
  tell_room(eep,HIB+"              *         *               *                  *        *        *\n"+
          "                     *                       *         *       *         *\n"+NORM);
  tell_room(eep,HIB+"             *          *      *                *           *           *      *\n"+
          "            *         "+NORM+HIG+"^^^^^     ^        ^^^^       ^^^^^       ^^^^^"+HIB+
          "          *\n"+NORM);
  tell_room(eep,HIB+"            *         "+NORM+HIG+"^         ^       ^    ^      ^   ^       ^"+HIB+
  "               *\n"+NORM);
  tell_room(eep,HIB+"                      "+NORM+HIG+"^^^^^     ^       ^^^^^^      ^^^^^       ^^^^^"+HIB+
  "          *\n"+
          "             *        "+NORM+HIG+"^         ^       ^    ^      ^    ^      ^"+HIB+
          "         *\n"+NORM);
  tell_room(eep,HIB+"           *     *    "+NORM+HIG+"^         ^^^^^   ^    ^      ^     ^     ^^^^^"+HIB+
  "         *\n"+
          "             *     *            *         *                  *                   *\n"+NORM);
  tell_room(eep,HIB+"            *          *                        *                  *          *\n"+NORM);
  tell_room(eep,HIB+"                     *        *        *                 *                   *\n"+
          "              *       *                              *                        *\n"+NORM);
  tell_room(eep,HIB+"                   *        *              *                  *         *    *\n"+
          "                     *             *                               *       *\n"+NORM);
  tell_room(eep,HIB+"                         *            *         **          *         *\n"+
          "                              *           *          *            *\n"+
          "                                   *       *            *      *\n"+NORM);
  tell_room(eep,HIB+"                                         *       *         *\n\n"+NORM);
    tell_object(targ,HIB+"\nCOLD FIRE BURNS THROUGH YOU!\n\n"+NORM);
    targ->heal_self(-((targ->query_hp())/2));
    tell_object(ep,HIB+"\nPower runs through you as the flash fire burns!\n\n"+NORM);
    ep->add_hit_point(-((ep->query_hp())/2));
    if(targ) { move_object(clone_object("/players/mythos/closed/guild/spells/fielded.c"),
              targ); }
    destruct(this_object());
  return 1;}
call_out("flash",3);
return 1;}
