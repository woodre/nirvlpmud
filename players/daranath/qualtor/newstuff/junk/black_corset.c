#include <ansi.h>
#define tp this_player()
#define tpn tp->query_name()

inherit "obj/armor";
reset(arg){
   ::reset(arg);

   set_name("black corset");
   set_short("Tight black corset");
   set_alias("corset");
   set_long("The black leather of the corset is drawn tightly across the body\n"+
            "by numerous leather laces. The corset itself lifts and pushes the\n"+
            "breasts together, creating a massive amount of cleavage.\n");
   set_type("armor");
   set_ac(3);
   set_weight(1);
   set_value(450);
}

extra_look() {
if(worn)
  write(environment(this_object())->query_name()+"'s naked breasts are displayed for all to see by the black corset.\n");
}


