id(str) { return str == "book" || str == "newbie book"; }
reset() {}

long() { write(
  "  A beautiful leather bound book filled with useful Newbie inform-\n"+
  "ation.  Maybe you should 'read' it.  Author:  Eurale\n");
}

short() { return "A leather Newbie help book"; }

init() {
  add_action("read","read");
  add_action("drop_book","drop");
}

read(arg) {
if(!arg) { write("Read what?\n"); return 1; }
if(arg == "book" || arg == "newbie book") {
  write(
  "   Welcome to the exciting world of Nirvana.  There is lots to learn\n"+
  "and this book should help you get started.  There are quite a few\n"+
  "help files that you can see by typing 'help'.  To read each file\n"+
  "just type 'help <topic>'.  Also included in this book is a list of\n"+
  "newbie areas that you can visit to fight without great fear of be-\n"+
  "ing killed right off.  In order to read through the topics in this\n"+
  "book, simply type 'read index' to see them.  Good luck!\n");
  return 1;
}

if(arg == "index") { write(
  "  This is the index of the Newbie book.  The basic topics are\n"+
  "covered on the individual pages.  To read the information con-\n"+
  "tained on any given page, simply type 'read page #' where # is\n"+
  "the page number you want to read.\n\n"+
  "                      INDEX \n"+
  "TITLE                                        PAGE\n"+
  "-------------------------------------------------\n"+
  "Helpful hints...................................1\n"+
  "More helpful hints..............................2\n"+
  "Guilds..........................................3\n"+
  "Guilds..........................................4\n"+
  "Newbie areas....................................5\n"+
  "Portable heal locations.........................6\n"+
  "-------------------------------------------------\n"+
  "\n");
  return 1; }

if(arg == "page 1") { write(
  "(1) First, it is only normal to get going as fast as possible but\n"+
  "    you should spend some time and read all the help files so as\n"+
  "    to familiarize yourself with the basic set-up and rules of\n"+
  "    this game.  Nothing is more annoying to other players than to\n"+
  "    hear a new player asking simple questions that are all answered\n"+
  "    in the help files.\n\n"+
  "(2) You should spend some time exploring town and mapping it out.\n"+
  "    There are various establishments located throughout town that \n"+
  "    can be of assistance to you.  You will log into the church\n"+
  "    and you should explore the areas south and east all the way\n"+
  "    to Pizza Hut.  At the very least you should be able to find\n"+
  "    the Adventurer Guild, the pub, the shop, the weaponsmith and\n"+
  "    the armorer.\n\n"+
  "(3) There are various items that can be purchased or gotten from\n"+
  "    other players which will make your life easier.  These items\n"+
  "    will automatically disappear if you log off before you're at\n"+
  "    least an hour old.\n\n"+
  "(4) Equipment can either be gotten from the Newbie dispenser or\n"+
  "    purchased from a shop, weaponsmith or armorer.  You can also\n"+
  "    get it by killing one of the monsters and taking it from their\n"+
  "    corpse.  Money is obtained by killing monsters or players and\n"+
  "    looting their corpses and/or selling things you get from them.\n"+
  "\n");
  return 1; }

if(arg == "page 2") { write(
  "(5) Look at everything and read, read, read.  Most of the coders\n"+
  "    give you plenty of hints as to how to use an object.  Room\n"+
  "    descriptions often have items that can be looked at as well\n"+
  "    and your examination may lead to other discoveries.\n\n"+
  "(6) PK (Player Kill)  Nirvana is not considered a PK mud.  There\n"+
  "    are areas, however, where players can kill each other.  It is\n"+
  "    up to you to learn where these areas are and avoid them if you\n"+
  "    are not interested in PKing or being PKed.  Not all players\n"+
  "    who offer help intend to help you so BEWARE!\n\n"+
  "(7) There are multiple channels where you may talk to other players\n"+
  "    here at Nirvana.  The 'gossip' channel is the general channel\n"+
  "    and as such is to remain 'G' rated.  Misuse of channels or\n"+
  "    harrassing other players with 'spamming' or inappropriate\n"+
  "    remarks may earn you a trip to the famous Nirvana jail.\n\n"+
  "(8) There are mini guilds that you can join that each have special\n"+
  "    abilities.  You must be 6 hours old to join the first and 2 days\n"+
  "    old to join the second.  Each mini guild costs 5000 coins to\n"+
  "    join.  Ask someone for a scroll to learn more.\n");
  return 1; }

if(arg == "page 5") { write(
  "  The following list is by no means all the areas where players of\n"+
  "different fighting abilities can find monsters to fight.  Those\n"+
  "that are proficient fighters may find some too easy while others\n"+
  "of the same level may find them too tough.  So, proceed with\n"+
  "caution, be sure your wimpy is set and if possible, take along some\n"+
  "kind of portable heals that can be purchased at various places lo-\n"+
  "cated thoughout Nirvana.  The directions will all start from the\n"+
  "'green' located south of the church.\n\n"+
  "   Missionaries/zombies:  e,n\n"+
  "   Evergloom Forest:  7w, walk path\n"+
  "   MASH:  5e,s,enter portal,e....\n"+
  "   Dopple grounds:  9e,s,d,s\n"+
  "   Bandits:  5e,3n,w,step rift,in,2w,enter,e,u,s...\n"+
  "   Santa:  6w,n....\n"+
  "   South Park:  6w,3s,4w,4s,10w,enter hole\n"+
  "   Trixtown Daycare:  6w,2s,e,enter realm,3w,2n,2e\n"+
  "   Toys:  5e,4n,enter store\n"+
  "   Assorted:  10e,pass,ancient,e,s,hut\n"+
  "   Assorted:  2e,s,d,lay on bed,s,2e\n"+
  "   Icy stuff:  10e,pass,snow,newbie\n"+
  "   Castle Mael:  4w,2n,enter castle\n"+
  "   Funhouse:  4w,3n,e,enter doorway\n"+
  "   Rats:  4w,n,4nw,n,slide cover,crawl down,descend\n"+
 "   Jungle:  4w,5n,w,enter shrine,island\n"+
  "   Whispering Woods: 5e,2n,touch well,touch woods\n");
return 1; }

if(arg == "page 3") { write(
  "  There are quite a few guilds here.  Guilds have personalities\n"+
  "just like the players do.  You should research the different guilds\n"+
  "by talking to the members who belong to them.  When you're sure\n"+
  "you understand each guild's purpose and their strengths and weak-\n"+
  "nesses, choose the one that closest fits the personality of the\n"+
  "character you intend to play.  There is a hefty experience penalty\n"+
  "for leaving a guild so it pays to make a wise choice...\n\n"+

  "Vampires - Decent fighters, interesting spells, pets, unique guild\n"+
  "   hall, close family atmosphere, need support of at least 3 level\n"+
  "   17 or higher vamps to be admitted, slow to get in.\n\n"+
  "Power Rangers - Very good fighters at high level, team concept\n"+
  "   throughout the whole guild, guild weapon and special abilities,\n"+
  "   guild spells, alignment restrictions.\n\n"+
  "Polymorphs - Excellent fighters at high level, interesting morphs,\n"+
  "   NO PKing, 'strange' area of existence, few spells.\n\n"+
  "Cyberninjas - Good fighters, guild bionics and weapon, guild mechs\n"+
  "   that replace guild pets, honor system, guild heirarchy, PK.\n");
  return 1; }

if(arg == "page 4") { write(
   "Healers - Poor fighters even at high level, but with a wide range of\n"+

 "   healing oriented spells.\n\n"+
  "Knights Templar - Excellent fighters at high level, limited spells,\n"+
  "   alignment restriction, protectors of good.\n\n"+
  "Fallen - Difficult, spell-based guild requiring a comprehensive know-\n"+
  "   ledge of Nirvana.  Open character theme, solitary, armor and weapon\n"+
  "   restrictions.\n\n"+
  "Symbiotes - excellent fighters, purely physical attacks.  No guild\n"+
  "  loyalties to one another.  Based on Marvel Comic character Venom.\n"+
  "  Reduced to level 5 upon joining.  High power at high level.\n\n"+
  "Dervish - Ascetic fighting guild, limited healing spells,\n"+
  "   armor and stat restrictions, dual wielding at high levels.\n\n"+
  "  Remember, no guild is 'perfect'.  Each has strengths and weak-\n"+
  "nesses.  Also, every guild has some kind of leadership either as a\n"+
  "guild wizard or some kind of guild command.  It is up to you to do\n"+
  "the checking and see which one best fits you and your style of play.\n");
  return 1; }
                                                                     
if(arg == "page 6") { write(
  "Portable heals can be purchased throughout Nirvana.  You will find\n"+
  "a pretty wide range of prices and varieties of them.  This list is\n"+
  "by no means complete, just a couple of places to get you started.\n\n"+
  "  green: 10e,pass,newbie\n"+
  "  lockers:  west is a shop\n"+
  "  green: 6w,3s,w,warp,gulch,2e,2s,e,enter\n"+
  "  green: 5e,3n,w,step rift,in,4s\n");
return 1; }

}
get() { return 1; }
query_weight() { return 1; }
query_value() { return 0; }
drop_book(str) {
    if (str == "all") {
        destruct(this_object());
        return 1;
    }
    if (!str || !id(str))
        return 0;
write("As the Newbie book falls, there is a FLASH and it disappears!\n");
   say(capitalize(this_player()->query_real_name())+" drops a newbie book!\n");
   destruct(this_object());
   return 1;
}
