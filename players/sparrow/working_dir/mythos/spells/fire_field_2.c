#include "/players/mythos/closed/guild/def.h"
#define eep environment(ep)
object targ;
int j,kk, ddam;
id(str) {return str == "fire_field_2";}

get() { return 0;}
drop() { return 1;}

extra_look() {
  return "A Dark Field surrounds "+
           capitalize(epn);
}

reset(arg) {
  if(arg) return;
  call_out("flash",3);
}

flash() {
if(!ep) return 1;
  if(ep->query_ghost()) { 
    tell_object(ep,"Your flow field vanishes!\n"); 
    destruct(this_object());
  return 1;}
  if(ep->query_attack()) {
  kk = 0;
    targ = deep_inventory(environment(ep));
    for(j=0;j<sizeof(targ);j++) {
      if(living(targ[j])) {
        if(!targ[j]->is_player() || (targ[j]->is_player() && epp) ||
           targ[j]->id("masakado") || targ[j]->id("jinro") ||
           targ[j]->id("amoril") && targ[j] != ep && !targ[j]->id("messenger")) {
             kk = kk + 1;
        }
      }
    }
    ddam = 3;
    if(kk > 3) ddam = 4;
    if(kk > 5) ddam = 5;
    if(kk > 7) ddam = 6;
    if(kk > 10) ddam = 10;
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
    for(j=0;j<sizeof(targ);j++) {
      if(living(targ[j])) {
        if(!(targ[j]->is_player()) || (targ[j]->is_player() && epp) ||
           targ[j]->id("masakado") || targ[j]->id("jinro") ||
           targ[j]->id("amoril") && targ[j] != ep && !targ[j]->id("messenger")) {
             if(!present("fielded",targ[j])) 
                targ[j]->heal_self(-((targ[j]->query_hp()) / ddam));
             if(targ[j]) tell_object(targ[j],HIB+"\nCOLD FIRE BURNS THROUGH YOU!\n\n"+NORM);
             if(targ[j]) targ[j]->attack_object(ep);
  if(targ[j]) move_object(clone_object("/players/mythos/closed/guild/spells/fielded.c"),
              targ[j]); 
        }
      }
    }
    tell_object(ep,HIB+"\nPower runs through you as the flash fire burns!\n\n"+NORM);
    ep->add_hit_point(-((ep->query_hp())*5/8));
    destruct(this_object());
  return 1;}
call_out("flash",3);
return 1;}
