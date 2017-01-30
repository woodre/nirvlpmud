object speed, quick;
object apouch, dbadge, crobes, sdark, bmedal, cseal, mshadow, slife, mkskar;
object braxe, vrblade, draura;
object kthing, kdread;
object popc;

void reset(status arg) {
  if (!arg) {
    set_light(1);
  }
}

void init() {
  add_action("south", "south");
  add_action("buy", "buy");
  add_action("list", "list");
  add_action("info", "info");
}

int south() {
  int x;
  x = random(4);
  switch(x) {
    case 3:
      write("Macklemore tells you: I wear your granddad's clothes!\n");
    case 2:
      write("Macklemore tells you: I look incredible!\n");
    case 1:
      write("Macklemore tells you: I'm in this big ass coat, from that thrift shop down the road!\n");
    default:
      write("Macklemore tells you: Is that your grandma's coat?\n");
  }
  this_player()->move_player("south#/room/alley");
  return 1;
}

int list() {
  write("The Thrift Shop Down the Road has these items for sale:\n");
  write("\n"+
     "1|| A Speedster                      40 gold pieces\n"+
     "2|| A Quicktyper                     40 gold pieces\n"+
     "3|| Alchemist Pouch                 100 gold pieces\n"+
     "4|| Doppleganger Badge              100 gold pieces\n"+
     "5|| Cleric Robes                    100 gold pieces\n"+
     "6|| Shroud of Darkness              100 gold pieces\n"+
     "7|| A bronze medallion              100 gold pieces\n"+
     "8|| A Consistory Seal               100 gold pieces\n"+
     "9|| A Mark of the Shadows           100 gold pieces\n"+
     "10| Someone's life                  100 gold pieces\n"+
     "11| Blood scar of Mortal Kombat     100 gold pieces\n"+
     "12| Symbol of Shardak                      1000 gold pieces\n"+
     "13| The Legendary Battleaxe of Bresine     1000 gold pieces\n"+
     "14| Vampiric Blade of Regeneration         1000 gold pieces\n"+
     "15| A thing.                               1500 gold pieces\n"+
     "16| A dreadnought                          1500 gold pieces\n"+
     "17| A torpedo room key                     1500 gold pieces\n"+
     "\n"+
     "For information regarding the items, type info <number>.\n");
  return 1;
}

int info(int num) {
  switch(num) {
  case 17:
    write("These keys used to be used to gain access to the torpedo room\n"+
          "aboard the starship Enterprise. They could also be used to launch\n"+
          "a torpedo at a player for a sneaky pk attack!\n");
  case 16:
    write("The dreadnought was a tank like vehicle that could be purchased\n"+
          "at KMART for a steal.  Players could travel anywhere in safety\n"+
          "as aggressive monsters would not attack!\n");
  case 15:
    write("A thing. Oh how many good times were had with this item, which\n"+
          "was purchasable at KMART.  You could rename your 'thing' to \n"+
          "whatever you wanted, and then try to pass it off as the real\n"+
          "thing, including players!\n");
  case 14:
    write("The Vampiric Blade of Regeneration.  In the early days of\n"+
          "Nirvana, the vamp blade was one of the most sought after weapons\n"+
          "in the game. It allowed hp to regenerate while the player was in\n"+
          "combat.\n");
  case 13:
    write("The Legendary Battleaxe of Bresnine.  This hefty battleaxe was\n"+
          "quite the weapon.  It would cut pieces of your enemies off and\n"+
          "leave them in the room.  As an added bonus (ew), you could eat\n"+
          "the parts that were chopped off!\n");
  case 12:
    write("Symbol of Shardak.  The identifying object of the Shardak Guild.\n");
  case 11:
    write("Blood scar of Mortal Kombat.  This scar was visible on PK players\n"+
          "while participating in Mortal Kombat.  A points based system to \n"+
          "keep track of player kills based on a video game.\n");
  case 10:
    write("Someone's life.  Not sure who's life, but some undead guild\n"+
          "member must have left their life lying around!\n");
  case 9:
    write("A Mark of the Shadows.  The shadow guild mark.\n");
  case 8:
    write("A Consistory Seal.  An ancient guild seal from the Mason's guild\n"+
          "obviously from long ago.\n");
  case 7:
    write("A bronze medallion, eerily similar to the medallions worn in\n"+
          "ages past by the Paladins guild.\n");
  case 6:
    write("The Dark Mages were often seen wandering around with this type\n"+
          "of shroud.\n");
  case 5:
    write("The Robes of the Cleric guild.  These were commonly worn by\n"+
          "Clerics on Nirvana from days gone by.\n");
  case 4:
    write("A Doppleganger Badge!  These have been extinct from our realm\n"+
          "for quite some time!\n");
  case 3:
    write("Alchemists on Nirvana often carried a pouch around that contained\n"+
          "the various ingredients that they used.\n");
  case 2:
    write("A Quicktyper.  Before the days of build in aliases, players were\n"+
          "forced to carry around an object that would keep track of all of\n"+
          "the commands and abbreviations that they would come up with.\n");
  case 1:
    write("A Speedster.  A command speed-er-up-er. The Speedster allowed\n"+
          "you to type in many commands in a sequence, and then execute \n"+
          "them all at once.  These were outlawed long ago due to abuse.\n");
  default:
    write("Macklemore says: Please use the syntax 'info <number>'\n");
  return 1;
}

int buy(int num) {
  object ob;
  int cost;
  switch(num) {
  case 17:
    ob = clone_object(TPATH + "obj/tkey");
    cost = 1500;
  case 16:
    ob = clone_object(TPATH + "obj/dread");
    cost = 1500;
