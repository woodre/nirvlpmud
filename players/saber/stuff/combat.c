inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("list");
   set_short("A list");
   set_long(
   "  THE 20 RULES OF COMBAT\n"+
   "\n"+
   "1)  If the ememyis in range, so are you.\n"+
   "2)  If it's stupid, but works, it ain't stupid.\n"+
   "3)  You are not Superman.\n"+
   "4)  Never draw fire; it irritates everyone around you.\n"+
   "5)  When in doubt, empty the magazine.\n"+
   "6)  Never share a foxhole with someone braver than you.\n"+
   "7)  Your weapon was made by the lowest bidder.\n"+
   "8)  If you can't remember, the Claymore is pointed toward you.\n"+
   "9)  All five-second grenade fuses are three seconds.\n"+
   "10) The enemy diversion you are ignoring is the main attack.\n"+
   "11) If you're short on everything except enemy, you're in combat.\n"+
   "12) Incoming has right of way.\n"+
   "13) No combat-ready unit ever passed inspection.\n"+
   "14) No inspection-ready unit ever passed combat.\n"+
   "15) Teamwork is essential.  It gives them more people to shoot at.\n"+
   "16) Tracers work both ways.\n"+
   "17) The only thing more accurate than incoming enemy fire\n"+
            "            is incoming friendly fire.\n"+
   "18) Try to look unimportant, they may be low on ammo.\n"+
   "19) Radios will fail as soon as you need fire support.\n"+
   "20) Close only counts in horseshoes, grenades and nukes.\n"+
   "					Courtery of the L-4 GrasshopperWing\n");
   set_weight(0);
   set_value(0);
}
