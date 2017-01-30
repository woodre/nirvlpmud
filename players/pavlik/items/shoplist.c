
long() {
 write("A list and brief description of the items for sale\n"+
  "at Pavlik's Specialty Shop.\n");
}
short() {
  write("A list of items\n");
}
id(str) {
  return str == "list";
}

get() {
  return 0;
}
init() {
 add_action("read","read");
}
read(str) {
  if(str == "list") {
write("Items for sale (for low low prices!) at Pavlik's\n"+
      "        Specialty Shop!\n"+
 "\n");
write("(1) Cool Shades.  Jammin, cool shades the serve as helmet AC.\n"+
      "(2) ESP Ring.  This ring allows you to see through another\n"+
      "  players eyes.  It also allows you to 'tell' without\n"+
      "  any spell point charge.\n"+
      "(3) TMNJ Bookbag.  Gnarly carrying item.  You would like\n"+
      "  a totally awesome dude with one of these.\n"+
      "(4) Telegem.  Small Gem that allows you to teleport to several\n"+
      "  locations mud wide.  (destinations include: hotel, shop, church.)\n"+
      "(5) Slayer Recharger.  Magical recharge ointment for the Slayer.\n"+
      "(6) Easter Egg.  Even when out of season, this item is a great\n"+
      "  little thing to have.  Put items in the Egg and toss mud-wide.\n"+
      "(7) Bop Axe.  Oh, You have to try one of these! Not a reliable\n"+
      "  weapon, but just fun to have.\n"+
      "(8) Foxhole.  This is a portable foxhole that you dive into when\n"+
      "  a battle starts getting to rough.\n"+
      "(9) Align Potion.  Be bad, be good...its up to you.\n"+
      "(10) Color Monitor.  A color coded hit point monitor.  This item\n"+
      "  color coordinates your Hp/Sp status. (DO NOT use if your screen\n"+
      "  cannot handle color)\n"+
      "(11) A Juggler.  A magical pin that allows you to juggle your Hit\n"+
      "  points into Spell points and visa versa.\n"+
      "(12) Power Potion.  Enhance the power of your weapon.\n"+
      "(13) Spyglass.  This little item allows you to see into an adjacent\n"+
      "  room without ever having to enter it.\n"+
      "(14) Footlocker.  A locker you can place in one spot and get/put\n"+
      "  items into.  Only you will be able to use the locker.\n"+
     "(15) Healing Stone.  This stone will heal you three times.  Once\n"+
     "  activated the stone will heal you three times periodically until\n"+
     "  the items powers have been used up.\n"+
      "\n"+
      "Write more items avialable by reasonable request.\n\n");
                    return 1;
        }
}





