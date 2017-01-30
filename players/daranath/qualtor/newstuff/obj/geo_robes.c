#include <ansi.h>
inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("geomancer robes");
set_short(YEL+"Robes of the Earth"+NORM);
set_alias("robes");
set_long("Dark sand colored robes that match the sand from the area around\n"+
         "Gundar's wastes itself, these robes were worn long ago by the\n"+
         "ancient Geomancer guild. Although the guild hasn't been seen,\n"+
         "for decades. These robes have survived the test of time.\n");
set_type("armor");
set_ac(4);
set_weight(1);
set_value(5750);
set_params("other|earth",3,5,"earth_special");
}

int earth_special(object ob) {
  if(!random(3))
  tell_object(ob, YEL+"Your robes absorb some of the earth damage.\n"+NORM);
}
