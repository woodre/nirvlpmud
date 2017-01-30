inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("darkstone");
    set_alias("gem");
    set_short("A Darkstone");
    set_long("There is something shining deep within the stone.\n"+
             "You may wish to 'peer' into it.\n");
    set_weight(1);
    set_value(10);
}

query_gsave() { return 1; }

init() {
  ::init();
  add_action("peer","peer");
  add_action("word","intone");
}

peer() {
  write("You peer into the gem and notice that deep inside there is\n"+
        "a flame.  The flame seems to dance around and you feel calm\n"+
        "and safe.\n");
  write("\nSuddenly you realize the flame is spelling out the word:\n\n"+
         "\t\t\tKinen\n\n"+"Perhaps you may wish to 'intone'.\n");
   return 1;}
   
word() {
string realm;
string wheree;
realm=call_other(environment(this_player()),"realm",0);
  if(realm == "NT") {
  write("Nothing happens...\n"); return 1;}
  if(wheree = call_other("obj/base_tele","teleport")) {
     this_player()->move_player("with an astonished look#"+wheree); }
  else {
  tell_room(environment(this_player()),capitalize(this_player()->query_name())+ 
           " intones quietly and vanishes!\n");
  write("You intone the word:   Kinen.\n\nYou are somewhere else.\n");
  move_object(this_player(),"/players/mythos/aroom/shrinear5.c");
}
  call_other(this_player(),"add_spell_point",-30-random(20));
return 1;}
