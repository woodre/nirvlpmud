#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_alias("statue");
   set_short("Statue");
   set_long("A large, dirty statue of about seven feet in height.\n"+
            "The statue is dark brown in color from the dust and\n"+
            "sand that has covered the statue over time.  A large\n"+
            "scythe sits in the statue's huge hands, resting against\n"+
            "its chest.  A suit of plated armor made from leathers\n"+
            "and gold plate cover its body.  A helmet, which looks\n"+
            "like a dog's head covers the statues head.\n");

}
id(str){ return str == "pyramid_statue" || str == "statue"; }

get(){ return 0; }
