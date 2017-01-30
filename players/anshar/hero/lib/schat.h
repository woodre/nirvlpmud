#include "/players/anshar/hero/def.h"

stalk(str) {
  object ob;
  ob = "/players/anshar/hero/objects/chatob.c";
  if(!ob) {
    write("The guild line is currently down.\n"); return 1; }
  if(!str) { heros();  return 1; }
  ob->tell(str);
  return 1; }

semote(str) {
  object ob;
  ob = "/players/anshar/hero/objects/chatob.c";
  if(!ob) {
    write("The guild line is currently down.\n"); return 1; }
  if(!str) { write("Heroe what?\n");  return 1; }
  ob->emote(str);
  return 1; }

heros() {
  int b, level;
  string title, place;
  object * iter;
  object ob, cob;

  write("\n");
  write(BOLD+"********************************************************"+
        "***********************\n"+NORM);
  write(HIG+pad("hero",     15)+
        pad("Level",       11)+
        pad("Title",       15)+
        pad("Location",    30)+"\n"+NORM);
  write(BOLD+"********************************************************"+
        "***********************\n\n"+NORM);

  cob = CHATOB;
  if(!cob) { write("Hero malfunction.\n"); return 1; }
  cob->resetchannel();
  iter = cob->query_members();
  if(!iter) { cob->resetchannel(); iter = cob->query_members(); }
  if(!iter) { write("Hero malfunction 2.\n"); return 1; }
  for(b=0;b<sizeof(iter);b+=1)  {
    if(!iter[b]->query_invis()) {
        ob     = iter[b];
        write(pad(ob->query_name(), 15));
        level = ob->query_level();
        write(pad(level, 11));
        if(level < 10) write(HIG);
        if(level >= 10 && level < 19) write(BOLD);
        if(level >= 19) write(BOLD+RED);
        title = get_title(level);
        write(pad(title, 15));
        write(NORM+NORM);
        place = environment(ob)->short();
        write(NORM+NORM);
        write(pad(place, 30));
        write("\n");
    }
  }

  write(BOLD+"\n********************************************************"+
        "***********************\n"+NORM);
  return 1;
}

get_title(num) {
  if(num > 19) return "Deity";
  if(num < 10) return "Hero";
  if(num < 19) return "GreatHero";
               return "SuperHero"; }
