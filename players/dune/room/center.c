inherit "room/room";


reset(arg)
{

  if(!arg)
  {
    set_light(1);
    short_desc="Center of Elemental Tower";
    long_desc=
"                             .....                   \n"+
"    f                        {,,,,},, ```            \n"+
"   f                        .. {,,,,,} ``     ___    \n"+
"  ff                         ...  ..``       /***<   \n"+
" fff       ________________  { }  ...  `    /*****<  \n"+
"  ffff     ~  ~~// ~~~  ~~    ``,,,,,,,    |*******| \n"+
"  fffff   ~~~~ // ~ ~~~ ~ ~    {       }   |*******| \n"+
" fffffff   ~~ // ~~~~   ~~~     ```````     -------/ \n"+
"  FIRE         WATER              AIR        EARTH   \n"+
"     You are on the roof of the monolithic\n"+
"tower. You are surrounded by a dazzling display\n"+
"of elemental chaos! To the north, columns of\n"+
"eternal flame shoot in the sky. East, you see\n"+
"clouds and raging winds. To the west, a walkway\n"+
"travels over churning waters. And to the south,\n"+
"a tunnel leads into the tower itself. Dirt and\n"+
"clay are scattered around the tunnel enterance.\n"+
"The spiral stairs continue going upward.\n";

    items=({
 "flame", "Columns of swirling flame reach at the heavens",
 "columns","The columns surround a fiery walkway",
 "clouds","The clouds churn violently",
 "winds","The winds blast a walkway that leads into it",
 "walkway","Four walkways exist, all lead in the four directions",
 "waters","What sort of horrible creature could swim in those depths",
 "tunnel","The tunnel descends in black depths",
 "dirt","The dirt is black and moist",
 "clay","The clay is red and soft",
    });

    dest_dir=({
 "/players/dune/room/fire1.c","north",
 "/players/dune/room/water1.c","west",
 "/players/dune/room/air1.c","east",
 "/players/dune/room/earth1.c","south",
 "/players/dune/closed/castle/rooms/pinnacle.c","up",
 "/players/dune/room/floor3.c","down",
    });
  }
}


realm() { return "NT"; }
