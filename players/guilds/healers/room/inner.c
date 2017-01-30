#include "../def.h"
int lev;

id(str) { return str == "chamber" || str == "inner" || str == "healerchamber"; }

short() { return "Inner Chambers"; }

long() {
 write("You enter a small circular chamber.  The walls are white marble, the ceiling\n"+
       "a crystal dome, and the floor is coverd in mist.  At the center suspended\n"+
       "a few feet above the floor, is a softly glowing orb.  The orb is roughly the\n"+
       "3 feet in radius and the color of the light changes every so gradually, like\n"+
       "the light of the dawn as the sun rises above the horizon.\n"+
       "The only obvious exit is: hall\n");
}

reset(arg) {
object inv;
int h,i;
  if(arg) {
    inv = all_inventory(TO);
    h = 1;
    while(h && i < sizeof(inv)) {
      if(query_ip_name(inv[i])) h = 0;
      i++;
    }
    if(h) destruct(TO);
   return;
  }    set_light(2);  lev = 5;
}

init() {
  add_action("hall","hall");
  add_action("bow","touch");
  if(tp) call_out("serve",10);
}

hall() {
  tp->move_player("hall#"+root+"room/hall.c");
return 1; }

serve() {
  tell_room(TO,"The acolyte bows before the orb.\n"+
               "As he turns to leave he whispers:\n"+
               "  This once, touch the Orb, so that\n"+
               "   it may know you and love you.\n"+
               "The acolyte then leaves quietly.\n");
return 1; }

drop() { return 1; }
get() { return 0; }

realm() { return "NT"; }

query_no_fight() { return 1; }

bow(str) {
  if(str) {
    if(str == "orb" || str == "the orb") {
        write("You touch the orb and find it surprisingly cool.\n"+
             "Suddenly, it flares with a blaze of white light- \n"+
              "blinding you.\n\n"+
              "A voice from within the Orb speaks:\n\n"+
              "    Will you bind yourself to the service of All, to Heal\n"+
              "      those who need it and want it, and to bring MY light\n"+
              "      to the eyes of this World?     <y/n>  :  ");
       input_to("awo");
    return 1;}
  }
}

awo(str) {
object rom;
   if(!str) { write("<y/n>  :  "); input_to("awo"); return 1; }
   if(str != "Y" && str != "y" && str != "N" && str != "n") {
         write("<y/n>  :  "); input_to("awo"); return 1; }
   if(str == "n" || str == "N") {
      write("The Orb's light dims and you feel at a loss.\n"+
            "You experience a queasy feeling and then it passes.\n");
      move_object(tp,root+"room/hall.c");
      command("look",tp);
   return 1; }
   write("As you utter the words of acceptance, a great warmth surronds you.\n"+
         "The world seems to be a swirl of light and heat.\n\n"+
         "The Orb speaks:\n\n"+
         "       Now go forth my child and do as your oath has stated.\n\n");
   save_object(MEM+tpn);
   rom = clone_object("/"+root+"room/study.c");
   rom->set_ownn(tpn);
   move_object(tp,rom);
   tp->set_guild_file("/players/guilds/healers/guildob.c");
  write_file("/players/guilds/healers/START.TXT",ctime(time())+" "+tpn+"   "+tp->query_exp()+"\n");
   write("You feel a gentle hand lead you away......\n");
   command("look",tp);
   destruct(TO);
return 1; }
