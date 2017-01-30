inherit "obj/armor";
int jumps_left;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("jumpboots");
  set_alias("boots");
  set_value(8000);
  set_ac(1);
  set_weight(2);
  jumps_left=8;
}

init() {
  ::init();
  add_action("jumpto","jumpto");
}

short() {
  if(worn) return "A pair of Jumpboots ["+jumps_left+"] (wielded)";
  else return "A pair of Jumpboots ["+jumps_left+"]";
}

long() {
  write("These boots are constructed of a durable, plastic-like material.\n"+
	"On the soles, you notice a series of orifices that jet hot gas when\n"+
	"the button labeled 'test' is pushed. Most of the symbols are\n"+
	"alien to you, but a sticker on one boot reads:\n"+
	"'USAGE: jumpto <plyr>'.\n");
  write("There appear to be ["+jumps_left+"] charges remaining.\n");
}

jumpto(arg) {
  object people;
  object victim;
  int index;
  if(!arg) return 0;
  victim=find_player(arg);
  if(!worn) {
    write("[Jumpboots] ERROR: Wear the boots first!\n");
    return 1;
  }
  if(!jumps_left) {
    write("[Jumpboots] ERROR: No more fuel.\n");
    return 1;
  }
  if(!victim) {
    write("[Jumpboots] ERROR: No such player logged in.\n");
    return 1;
  }
  if((victim->query_level()) > 20) {
    write("[Jumpboots] ERROR: Cannot jump to a wizard.\n");
    return 1;
  }
  if(victim == this_player()) {
    write("[Jumpboots] ERROR: Jump to yourself? Duh!\n");
    return 1;
  }
  if(present(victim, environment(this_player()))) {
    write("[Jumpboots] ERROR: Jump to someone in the same room? Duh!\n");
    return 1;
  }
  jumps_left=jumps_left-1;
  say((this_player()->query_name())+" fires up a pair of jumpboots and rockets off into the sky.\n");
  move_object(this_player(), environment(victim));
  people = users();
  for(index = 0; index < sizeof(people); index++) {
    if(people[index]->on_channel("junk")) {
      tell_object(people[index], "You see "+(this_player()->query_name())+
      " rocket across the MUD and come crashing down near "+(victim->query_name())+"!\n");
    }
  }
  say((this_player()->query_name())+" drops from the sky.\n");
  return 1;
}
