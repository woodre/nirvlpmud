#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "The Crossroads at Travelers Gate";
     long_desc =
"    This appears to be a well used intersection with the main road\n\
leading north.  An archway to the west leads to a plain looking guard-\n\
house.  To the northwest is the entrance to the visitors center.  The\n\
main road heads north and a smaller access road goes east toward a big\n\
warehouse.  The entry way to the bazaar is to the northeast while the\n\
towering gate house to the south is an unmistakable landmark.\n";

     items = ({
     "archway","It is unadorned and plain looking",
     "gatehouse","An impressive black stone structure at least ten stories high",
});

dest_dir = ({
	AREA+"102-150.c","north",
        AREA+"102-149.c","northwest",
        AREA+"101-149.c","west",
        AREA+"101-151.c","east",
        AREA+"100-150.c","south",
        AREA+"102-151.c","northeast",
});

}
init(){
     ::init();
     add_action("read_board","read");
}
/*
 *   I'd credit the auther for the ascii art but it came from an archive site
 */

read_board(str){
     if(!str || str != "billboard"){
        notify_fail("Are you trying to 'read' the 'billboard' or what?\n");
        return 0;
     }
     write("\n"+
"       d@$iWWb:\n"+
"     '8$$$$#$$$k                   Come visit the"+HIR+" F"+NORM+"."+HIR+"D"+NORM+"."+HIR+"B"+NORM+". club!\n"+
"     '8$$$$$`$$M&                                 "+HIR+"i o e"+NORM+" \n"+
"     X$$$$K$$`$$XX                                "+HIR+"r w l"+NORM+" \n"+
"     $$$$$UUo$@$$$.                               "+HIR+"e n o"+NORM+" \n"+
"    9$$$$$$$$$9$$$$>                               "+HIR+"   w"+NORM+" \n"+
"   W$$$$$$$$P `#$$?B           The ONLY choice\n"+
"  '$$$$$\"#$h. d$$$X?$c         for adult relaxation featuring girls from\n"+
"   $$$$R      /\"$$$X$$\n"+
"   ?$$$R~    :/ $$R\"\"\"\\.            "+HIR+"H"+NORM+"ot\n"+
"    $$$$:   .xHx$E      !           "+HIR+"E"+NORM+"rotic\n"+
"   '$\"9$$N    d$$F       !          "+HIR+"L"+NORM+"ovely\n"+
"   '  M$$$'Ne@$$$!'      '          "+HIR+"L"+NORM+"adies\n"+
"   E  XR#$>'R P9?  k>     :\n"+
"   E   '! *f  .f'  :      9k               -~`      `\"-.\n"+
"   `  :    `    >   >     ~$:          .~                `!.\n"+
"   'L :     ~` ~    !     '$8       .~                        ~\\.\n"+
"    ?         ~   ! .      $$$.    :                             `~:\n"+
"    `!        '   %X2      R$$W% .~                                  `\\\n"+
"     !:  MM> .A      :     M5$$ ~   !                                   `.\n"+
"     !$W.   xF '#buo@$     '^$F   :$$>       .--^`\"-.  `.\n"+
"     !M$$$$*         'k    '     d$*##..-~`           `: \"4:x.\n"+
"     '!$$$$$c   !. !xx!     .!  `$$@F`                  >~\n"+
"     '\\!?$$$$$X.     `M   9 !     ~\n"+
"     '!!!> ~ `!!~!!.  f     ~ ~\n"+
"\n");
     return 1;
}



