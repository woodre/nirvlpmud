#include "/players/eurale/closed/ansi.h"
#define TP this_player()
#define TPRN this_player()->query_real_name()
inherit "obj/monster";

reset(arg) {
object buyer;
  ::reset(arg);
  if(arg) return;
set_name("librarian");
set_alias("caped librarian");
set_race("vampire");
set_short(GRY+"caped librarian"+NORM);
set_long(
  "A slight woman with very pale skin, she is one of the vampire\n"+
  "workers.  Her blazing green eyes glow from underneath her cape\n"+
  "and she glides across the floor noiselessly as she straightens\n"+
  "and puts away the old books.\n");

set_level(14);
set_hp(300);
set_al(0);
set_wc(48);
set_ac(11);
set_heal(5,2);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(2);
load_chat("The caped librarian whispers, 'If there's something I can\n"+
          "do for you, just 'ask'.\n");

}

init() {
add_action("Ask","ask");
add_action("Tour","tour");
}

Tour(str) {
if(!str) {
  write("The vampire librarian hisses, 'Who did you give a tour to?'\n");
  return 1; }
write(
  "The vampire librarian picks up a quill and quickly jots down your\n"+
  "information.  She hisses, 'Eurale will be pleased with you' and then\n"+
  "goes back about her business.\n");
write_file("/players/eurale/VAMPIRES/BITERS", ctime(time())+"  "+
  capitalize(TPRN)+" gave the GUILD TOUR to "+capitalize(str)+".\n");
return 1; }

Ask(str) {
if( (!str) || str == "librarian" || str == "vampire" ) {
  write(
   "The caped librarian looks you in the eye and whispers, 'I am the keeper\n"+
   "of the vampire history books.  I keep track of who joins our family and\n"+
   "which family members bite them.  I also keep track of who gives the new\n"+
   "members their guild tour.  All you need do here is type 'tour <name>' and\n"+
   "I will record your efforts.  If you but 'ask history', I will show you\n"+
   "the most recent of family additions.'  And with that, she goes back to\n"+
   "the business of putting her books in order.\n");
  return 1; }
if(str == "history") {
  write("The librarian takes down a book of vampire history and quickly\n"+
        "thumbs through the pages.  She stops and looks up at you and\n"+
        "then she says, 'Ahhhh, here it is.'  She turns the book and\n"+
        "shows you the page with this writing on it...\n\n");
  tail("/players/eurale/VAMPIRES/BITERS");
  return 1; }
}

