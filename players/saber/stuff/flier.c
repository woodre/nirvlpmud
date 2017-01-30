inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("scroll");
   set_short("A scroll");
   set_long(
  "Welcome to the land of the Shadow of the Sun.\n"+
  "\n"+
   "                                    Mountains\n"+
   "                                      |\n"+
   "                                      |\n"+
   "  Green   --  Dark   --  Green  --  Portals -- Cave\n"+
   "  Valley      Tower      Valley      End\n"+
   "                                      |\n"+
   "              Shrine     Arena  --  Ryllian -- Orins     Gym\n"+
   "                 |                    |        Inn         |\n"+
   "                 |                    |                    |\n"+
   " Church   --    **   --    **   --   **     --  **   --   **   --  **\n"+
   " of Larn      -  |                    |                    |        |\n"+
   "            -    |                    |                    |        |\n"+
   " Embassy  -     **         Gen  --   Fine   --  Misc    Library   Hero\n"+
   "  House          |         Shop      Cloth      Shop             Tower\n"+
   "                 |          |         |          |\n"+
   "              Slums        **   --   Food & --  Magic\n"+
   "                 |          |        Spirits    Shop\n"+
   "                 |          |         |          |\n"+
   "                **         Gem  --   The    --  **\n"+
   "                 |         Shop      Armory\n"+
   "                 |                    |\n"+
   "                **   --    Slums -   **\n"+
 "\n"+
   "A rift leading to the city of Ryllian can be found in Sun Alley.\n"+
   "  (From church s, 5e, 3n, 1w, step rift)                  -- Saber\n");
   set_weight(0);
   set_value(0);
}
