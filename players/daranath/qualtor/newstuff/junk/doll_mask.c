#include <ansi.h>
#define tp this_player()
#define tpn tp->query_name()

inherit "obj/armor";
reset(arg){
   ::reset(arg);

   set_name("doll mask");
   set_short("White porcelin "+WHT+"china doll"+NORM+" mask");
   set_alias("mask");
   set_long("This white mask is popular among the gothic types. The eyes and mouth\n"+
            "are often accentuated with bright red and blue hues.\n");
   set_type("helmet");
   set_ac(1);
   set_weight(1);
   set_value(200);
}

extra_look() {
if(worn)
  write("The china doll mask give "+environment(this_object())->query_name()+" a look of pure innocence.\n"); 
}

