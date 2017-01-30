#include "/players/mythos/closed/ansi.h"
int bef;
inherit "obj/armor";
reset(arg){
  ::reset(arg);
  set_name("carapace");
  set_short("Drake Carapace");
  set_alias("drake carapace");
  set_type("armor");
  set_long("This is the light outer skin of a drake.\n"+
           "In battle this offers good protection.\n");
  set_ac(1);
  set_weight(2);
  set_value(1300);
}

init() { ::init(); add_action("skill","kill"); }

skill() {
  if(worn) {
    write("The Carapace warms as it senses the thrill of a hunt.\n");
    bef = 1 + random(3);
    if(!this_player()->query_attack()) 
    this_player()->set_ac(this_player()->query_ac() + bef); 
    /* adds 1 - 3 making this object like a ac 2 - 4 armor */
    call_out("hunt",10);
  }
}

hunt() {
  if(environment(this_object())) {
    if(living(environment(this_object()))) {
    if(worn && !environment(this_object())->query_attack()) {
      environment(this_object())->set_ac(environment(this_object())->query_ac() - bef); 
      tell_object(environment(this_object()),
      "The Carapace cools as it senses the hunt end.\n");
    return 1; }
    if(!worn) { 
    environment(this_object())->set_ac(environment(this_object())->query_ac() - bef);  return 1; }
  call_out("hunt",10); }
  }
return 1; }