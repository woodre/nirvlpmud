inherit "obj/armor";
object player;

#include "/players/saber/closed/ansi.h"

reset(arg){
   ::reset(arg);
   set_name("tee shirt");
   set_short("A "+BOLD+"_NO FEAR_"+NORM+" tee shirt");
   set_alias("shirt");
   set_long("A tee shirt with the words "+BOLD+"NO FEAR"+NORM+" boldly"+
            " written acorss it.\n");
   set_type("misc");
   set_ac(1);
   set_weight(1);
   set_value(10);
}
