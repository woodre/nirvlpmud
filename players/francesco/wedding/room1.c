#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int blah;
reset(arg) {
  if(arg) return;
 if (!present("monster")) {
  move_object(clone_object("/players/francesco/wedding/monster1.c"),this_object());  
  move_object(clone_object("/players/francesco/wedding/monster2.c"),this_object());   
  move_object(clone_object("/players/francesco/wedding/monster3.c"),this_object());   
  move_object(clone_object("/players/francesco/wedding/monster4.c"),this_object());  } 
set_light(1);

short_desc = ""+HIR+"An"+NORM+YEL+" o"+HIY+"pe"+HIG+"n "+HIB+"sp"+HIM+"ac"+HIC+"e"+NORM+"" ;
long_desc =
     "   This wide open area is characterized by seven oaks which raise\n"+
     "highly and stately above the well maintained green grass.  The oaks\n"+
     "are positioned one after the other to form an almost perfect circle.\n"+
     "Under those huge trees some tables are layed for several people to \n"+
     "sit.  A small waterfall coming from nowhere forms a small lake from\n"+
     "which a tiny brook emerges and passes through the whole area, with \n"+
     "ample meanders and small bridges crossing itself.  High in the sky,\n"+
     "the sun is shining.\n",

items = ({
   "oaks","The oaks have large "+YEL+"trunks "+NORM+"and "+GRN+"wide foliage"+NORM+"",
   "trunk",""+YEL+"The trunk of the oaks must be at least 10 feet in diameter"+NORM+"",
   "trunks",""+YEL+"The trunks of the oaks must be at least 10 feet in diameter"+NORM+"",
   "foliage",""+GRN+"The thick foliage of the oaks covers a wide portion of the grass."+NORM+"\n"+
             "Some birds must be hiding there, according to what you can 'listen'",
   "grass",""+HIG+"The lawn is meticulously manicured"+NORM+"",
   "green grass",""+HIG+"The lawn is meticulously manicured"+NORM+"",
   "circle","The geometric shape formed by the oaks",
   "trees","The oaks have large "+YEL+"trunks "+NORM+"and wide "+GRN+"foliage"+NORM+"",
   "table","The tables are covered by white "+HIW+"tablecoaths"+NORM+" and each is surrounded by eight chairs",
   "tablecoaths",""+HIW+"At a closer look they appear to be all hand made with lace"+NORM+"",
   "chairs","Small armchairs, rather than plain chairs",
   "waterfall","The soft sound of the "+HIC+"water "+NORM+"falling down is very relaxing",
   "lake",""+HIC+"The lake is heart-shaped, "+NORM+"is it a natural one?",
   "brook",""+HIB+"Small and slowly flowing along"+NORM+"",
   "area","In the far distance a fence encircles the area",
   "fence","The fence is made by small flowering plants",
   "plants","The flowering plants are lilacs",
   "flowering plants","The flowering plants are lilacs",
   "meanders","The meanders of the brook had been formed by the slow flowing of the water",
   "bridges","The bridges are made by the assembly of small bars of wrought iron, painted in "+HIW+"white"+NORM+"",
   "small bridges","The bridges are made by the assembly of small bars of wrought iron, painted in "+HIW+"white"+NORM+"",
   "sky","The color of the sky is a perfect "+HIC+"sky-blue"+NORM+"",
   "sun","A brilliantly blazing ball of "+HIY+"yellow"+NORM+"",
   "flowers",""+HIW+"White"+NORM+" and "+HIM+"purple"+NORM+" lilacs", 
   "birds","They happily fly around, singing, landing and hiding eventually in the foliage of the oaks",
   "lilacs","They are colored in "+HIW+"white"+NORM+" and "+HIM+"purple"+NORM+" and send a sweet 'smell' around",
});


dest_dir = ({
  "/room/church.c","nirvana"
});}

init() {
    ::init();
    add_action("listen","listen");
    add_action("smell","smell");
}

listen(){write("You hear the melody of singing birds.\n");return 1;}

smell(){write("You smell the scent of the flowers......hmmmmmm......sweet......\n"); return 1;}
