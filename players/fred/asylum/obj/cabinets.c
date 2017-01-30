inherit "/obj/treasure.c";
#define tpn this_player()->query_name()

reset(arg) {
 set_id("cabinet");
 set_long("A large cabinet that with several sliding drawers.\n");
 }

query_weight(){return 50000;}
can_put_and_get(){ return 1; }
