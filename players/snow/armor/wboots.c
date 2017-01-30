/* Boots of the Wanderer */
 
#define BOOTMASTER "/players/snow/closed/bootmaster.c"
 
inherit "obj/armor";
 
int monon;
set_mon(m) { monon = m; }
query_mon() { return monon; }
 
init() {
  ::init();
    add_action("pub_commands","pubb");
    add_action("wander_commands","wan");
}
 
reset(arg){
   ::reset(arg);
   set_name("boots of the wanderer");
   set_short("Boots of the Wanderer");
   set_alias("boots");
   set_long(
"These are the Boots of the Wanderer. As you peer more closely,\n"+
"you notice two words scratched on the leather: 'pubb' and 'wan'.\n");
   set_type("boots");
   set_ac(1);
   set_weight(1);
   set_value(500);
}
 
pub_commands(arg) { BOOTMASTER->pub_commands(arg); return 1; }
wander_commands(arg) { BOOTMASTER->wander_commands(arg); return 1; }
 
fake_beat() {
  if(monon) {
    BOOTMASTER->wander_mon(environment(this_object()));
    call_out("fake_beat",10);
    return 1;
  }
  return 0;
}
