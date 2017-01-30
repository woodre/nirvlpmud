/* Scrolls of Nar-Tuith.. Dervish quest for reincarnation */
#include "/players/snow/color.h"
id(str) { return str == "scrolls" || str == "scroll" ||
                 str == "scrolls of nar-tuith"; }
drop() { return 0; }
short() { return "Scrolls of Nar-Tuith"; }
long() {
  write("You peruse the scrolls of Nar-Tuith...\n");
  find_quest(this_player());
  write(BOLD+RED+"The Scrolls of Nar-Tuith burst into flame!\n"+OFF);
  call_out("destruct_me", 1);
  return 1; }
find_quest(object ob) {
  string qstr;
  if(!ob) return;
  if(ob->query_guild_name() != "dervish") {
    write("You are unable to decipher the mystical writings.\n");
    return 1; }
  if(this_player()->query_extra_level() < 21) {
    write("You are not one with the "+BOLD+RED+"SandStorm"+
          OFF+" yet.\n");
    return 1; }
  write(BOLD);
  write("\n\tMystical writings burst into life before your eyes!\n\n");
  write(BLUE);
  write("\tMortal yet more than mortal, the SandStorm is your soul.\n\n\
\tBut what price, to be reincarnated as your master?\n\n\
\tTen items of extreme power.\n\n\
\tOffer these, as well as your entire life...\n\n\n\n\
\t\t"+OFF+RED+"REBIRTH!"+OFF+"\n\n\n\n");
  write_file("/players/snow/dervish/task",ctime(time())+" "+
    this_player()->query_real_name()+" learned of Nar-Tuith.\n");
  return 1; }

destruct_me() { destruct(this_object()); return 1; }
