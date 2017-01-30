#include "../DEFS.h"
#define LEVEL   9
#define DRAIN 200

status main(string str) {
  object here, there, ninto;
  string here_realm, there_realm, where;
  string a,b;
  status can_trans;

  if(!gotrank(TP, LEVEL)) return 0;
  if(!gotsp(TP,   DRAIN)) return 1;
  here       = environment(TP);
  here_realm = (string)here->realm();
  if(!str) {
    write("Usage: transto <ninja> or transto <on/off>\n");
    return 1; }
  if(str == "on") {
    IPTP->set_trans(0);
    write("Your transto is set: "+BOLD+"ON\n"+OFF); return 1; }
  if(str == "off") {
    IPTP->set_trans(1);
    write("Your transto is set: "+BOLD+"OFF\n"+OFF); return 1; }
  ninto = find_player(str);
  if(!ninto || (int)ninto->query_level() > 19) {
    write("<~>"+capitalize(str)+" cannot be found.\n");
    return 1; }
  if(!present(GUILD_ID, ninto)) {
    write("That player is not a CyberNinja!\n"); return 1; }
  there       = environment(ninto);
  there_realm = (string)there->realm();
  if(here_realm == "NT") {
    write("You cannot trans from your location.\n");
    return 1; }
  if(sscanf(file_name(there),"%sdune/closed/guild%s",a,b)==2) {
    write("That player is not in the guild hall.\n");
    write("You may only transport to those in the guild hall.\n");
    return 1;
  }
  if(there_realm == "NT") {
    write("You cannot trans to that location.\n");
    return 1; }
  can_trans = (status)present(GUILD_ID, find_player(str))->query_trans();
  if(can_trans) {
    write(capitalize(str)+" has transto turned off.\n");
    return 1; }
  if(!TP->query_pl_k()) {
    write("You are not PK!\n"); return 1; }

  /* chance for teleport error */
  if(where = (string)call_other("obj/base_tele", "teleport")) {
    write("You hear the sound of a fly buzzing near your ear.\n");
    say(TPN+"s body vaporizes into nothing.\n");
    write("Your body disintegrates into invisible matter particles.\n");
    write("Something went wrong!\n");
    TP->move_player("with an astonished look#"+where);
  call_other(TP, "add_spell_point", -40);
    return 1;
  }

  say(TPN+"s body vaporizes into nothing.\n");
  tell_room(there, TPN+" transfers in.\n");
  move_object(this_player(), there);
  write("Your body disintegrates into invisible matter particles.\n");
  write("You trans yourself to "+capitalize(str)+"...\n\n");
  call_other(TP, "glance");
  call_other(TP, "add_spell_point", -DRAIN);
  return 1;
}
