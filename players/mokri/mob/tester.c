inherit "obj/monster";
#include "/players/mokri/define.h"

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("tester");
   set_alias("mob");
   set_level(1);
   set_wc(0);
   set_ac(20);
   set_al(350);
   set_short("a tester mob");
   set_long("a guy for testing.\n");
}
init() {
::init();
add_action("function1","test");
add_action("function1","test2");
}
int function1() {
write(query_verb()+"\n");
return 1;
}

hit_player(dam1, type1, dam2, type2){
   return do_damage(({dam1,dam2}),({type1,type2}));
}
