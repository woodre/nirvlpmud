#include <ansi.h>
inherit "obj/armor";

reset(arg){
   ::reset(arg);

set_name("bone shield");
set_short("Buckler made from human bone");
set_alias("buckler");
set_long("A large shield that Tauros himself used as a buckler with his Maul,\n"+
         "BoneCrusher, the buckler is made up of human bones lashed\n"+
         "together. A skull at the center is locked in an eternal scream\n");
set_type("shield");
set_ac(2);
set_weight(2);
set_value(1175);
}
