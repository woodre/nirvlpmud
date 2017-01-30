/*  Forbin | Create date:  may2002.31 | Last mod:  may2002.31  */

#include "/players/forbin/define.h"
inherit "obj/treasure";

id(str) { return (::id(str) || str == "nfo_maker"); }

reset(arg) {
  if(arg) return;
  set_short("Forbin's Nfo Maker");
}

init() {
  add_action("make_nfo","make_info");
}

make_nfo() {
  write(""+HIW+""+BLINK+"NFO FILE MADE!"+NORM+"\n");
  write_file("/open/info/forbin.nfo","\n"+GRN+"-"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"-"+NORM+"\n"+  
                                     "                   "+GRN+"Up Since:  "+NORM+"June 11, 2004 "+HIW+"("+NORM+GRN+"re-coded"+HIW+")"+NORM+"                       \n"+     
                                     ""+GRN+"-"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"-"+NORM+"\n"+  
                                     "\n"+
                                     "                     "+HIW+"The Realms of the Wizard Forbin"+NORM+"                         \n"+                                                    
                                     "       A new trail has opened up in the south forest of Nirvana.             \n"+  
                                     "     Learn the workings of the crystals, and you may find many               \n"+
                                     "     exciting things.  Search well, for much is hidden in my                 \n"+
                                     "     realms - remember to look, listen, touch, smell, and search,            \n"+
                                     "     because you never know what you might find.                             \n"+
                                     ""+GRN+"-"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"-"+NORM+"\n"+
                                     "  "+GRN+"TO REACH MY AREA:  "+HIW+"6w,3s,4w,4s,follow the trail "+NORM+GRN+"OR "+HIW+"10e,pass,forbin"+NORM+"         \n"+ 
                                     ""+GRN+"-"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"---"+HIG+"=\\="+NORM+GRN+"---"+HIG+"=/="+NORM+GRN+"-"+NORM+"\n");
    return 1;
}
           

