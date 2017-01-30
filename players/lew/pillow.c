 

inherit "obj/weapon";
#define TP this_player()->query_real_name()

reset(arg) {

::reset(arg);

if(arg) return;

set_name("pillow");

set_short("A big pillow");

set_long("A well-used pillow.  It looks dangerous.\n");

set_class(16);

set_weight(1);

set_value(800);

 

}
