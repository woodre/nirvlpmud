#include "/players/snow/dervish/def.h"

dtalk(str) {
  object ob;
  ob = "/players/snow/dervish/objects/chatob.c";
  if(!ob) {
    write("The guild line is currently down.\n"); return 1; }
  if(!str) { dervishes();  return 1; }
  ob->tell(str);
  return 1; }

demote(str) {
  object ob;
  ob = "/players/snow/dervish/objects/chatob.c";
  if(!ob) {
    write("The guild line is currently down.\n"); return 1; }
  if(!str) { write("Derve what?\n");  return 1; }
  ob->emote(str);
  return 1; }

dervishes() {
  int b, level;
  string title, place;
  object * iter;
  object ob, cob;

  write("\n");
  write(BOLD+"********************************************************"+
        "***********************\n"+OFF);
  write(BOLD+BLUE+pad("Dervish",     15)+
        pad("Level",       11)+
        pad("Title",       15)+
        pad("Location",    30)+"\n"+OFF+OFF);
  write(BOLD+"********************************************************"+
        "***********************\n\n"+OFF);

  cob = CHATOB;
  if(!cob) { write("Derv malfunction.\n"); return 1; }
  cob->resetchannel();
  iter = cob->query_members();
  if(!iter) { cob->resetchannel(); iter = cob->query_members(); }
  if(!iter) { write("Derv malfunction 2.\n"); return 1; }
  for(b=0;b<sizeof(iter);b+=1)  {
    if(!iter[b]->query_invis()) {
        ob     = iter[b];
        write(pad(ob->query_name(), 15));
        level = ob->query_level();
        write(pad(level, 11));
        if(level < 10) write(YELLOW);
        if(level >= 10 && level < 19) write(BOLD);
        if(level >= 19) write(BOLD+RED);
        title = get_title(level);
        write(pad(title, 15));
        write(OFF+OFF);
        place = environment(ob)->short();
        write(OFF+OFF);
      write(place);
        write("\n");
    }
  }

  write(BOLD+"\n********************************************************"+
        "***********************\n"+OFF);
  return 1;
}

get_title(num) {
  if(num > 19) return "Deity";
  if(num < 10) return "Initiate";
  if(num < 19) return "Mystic";
               return "Master"; }
