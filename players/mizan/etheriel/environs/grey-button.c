#include "/players/bastion/closed/color.h"

int beano_count;

#define MAX_BEANOS 36

id(str) { return str == "button"; }
short() { return "A dull grey button (lick it)"; }
long() { 
write("This is a dull grey button suspended in the air. If you are under or\n"+
"at level 3, and there is not a Beano present, you can " + GREEN + "'lick'" + OFF + " the button to\n"+
"summon another one.\n");
}
reset()
{
  beano_count = 0;
}
init() {
  add_action("lickme","lick");
}
lickme(str) {
  if(!str) return 0;
  if(str != "button") return 0;
  if((this_player()->query_level()) > 3) {
    write("You have to be level 3 or less to be able to summon a Beano.\n");
    say(capitalize(this_player()->query_name())+" licks the button but nothing happens.\n");
    return 1;
  }
  if(!this_player()->is_player())
  {
    say(this_player()->query_name() + " is blown to bits.\n");
    call_other(this_player(), "hit_player", 400000);
/*
    this_player()->hit_player(400000);
*/
    return 1;
  }
  if(present("beano", environment(this_object()))) {
    write("There is already a Beano present.\n");
    return 1;
  }
  beano_count ++;
  if(beano_count > MAX_BEANOS)
{
      write("The Beano population has been decimated!\n");
    write("Come back later when more of them have bred.\n");
    return 1;
  }
  write("You lick the button and a Beano appears.\n");
  say(capitalize(this_player()->query_name())+" licks the button and a Beano appears.\n");
  move_object(clone_object("players/mizan/etheriel/beasties/beano.c"), environment(this_object()));
  return 1;
}
