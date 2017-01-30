inherit "obj/armor";
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("flannel shirt"+NORM+"");
   set_alias("shirt");
   set_short("A flannel shirt"+NORM+"");
   set_long(
      "This is a red and black striped flannel shirt.  It is well worn,\n"+
      "with the material getting very thin.  It looks as so it offers\n"+
      "some protection, but not very much.\n"
   );
   set_ac(3);
   set_type("armor"); 
   set_weight(3);
   set_value(500);

}
