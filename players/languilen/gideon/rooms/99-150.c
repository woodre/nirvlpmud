#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define MYENTRANCE "/players/languilen/areas/inside.c"
inherit "room/room";


reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "Outside South Gate";
     long_desc =
"    A huge gatehouse and mighty city walls rise above the field of\n\
grass that separates the city from the surrounding forest.  The open\n\
city gates beckon to weary adventurers, spuring them northward to the\n\
shelter of the city.\n";  

     items = ({
     "gates","The gates to the city look very well protected",
     "gatehouse","It stands nearly ten stories high and is made of some kind of black rock",
     "grass","It's so perfectly trimed it looks more like a green carpet.  The gardener must have a magic touch",
     "field","Due to the hight of the gatehouse there seems always to be a shadow",
     "walls","The tall walls flank the gatehouse straching east and west from it",
});

dest_dir = ({
	AREA+"100-150.c","north",
});

     if( !present("doorway") ){
         move_object(clone_object("/players/languilen/areas/doorway.c"),this_object());
     }


}
