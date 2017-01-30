#include "/players/catt/things/avatar.c"
destmessage = "Macros calls upon his demon host to protect him.";
frymessage = "A hole in the fabric of space opens up and swallows Macros.";
movemessage = "walks";
teleportmessage = "disappears in a flash of demonic light.";
followmessage = "leaves with a flash of light.";
followmessage2 = "Screaming demons carry Macros to you in a made rush.";
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("macros");
   set_short("Macros the master black sorceror (black knight)");
   set_long("Macros the master black sorceror (black knight)\n"+
      "Macros makes you wonder if you should have ever been born.\n"+
      "Macros is carrying:\n"+
      "Macros' quicktyper.\n"+
      "Amulet of the Sky (worn)\n"+
      "Silver ring (worn)\n"+
      "Spider Woven Cowl (worn)\n"+
      "Ancient cloak (worn)\n"+
      "Sightblinders Staff (wielded)\n");
   set_level(18);
   set_hp(10000);
   set_wc(1);
}
finger_macros() {
   tell_object(this_player(),
      "Macros the master black sorceror (black knight)\n"+
      "Level:           18\n"+
      "Guild name: demon summoners\n"+
      "Player Killer:   Yess\n"+
      "Last called at: Not logged off.\n"+
      "Age: 2 months 5 days 16 hours 22 minutes 53 seconds\n");
   return 1;
}
