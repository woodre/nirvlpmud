/*
Black diamond, possessed by /pl/s/MONSTERS/cleop.c
Transforms to /pl/s/WEAPONS/temblor.c for saber quest
*/

inherit "/obj/treasure.c";

reset(arg) {
    if(!arg) {

set_id("black diamond");
set_alias("diamond");
set_short("A shimmering black diamond");
set_long(
  "This incredibly beautiful diamond looks extremely valuable...\n"+
  "\n"+"Or maybe not! The flawless surface has some vague scratches.\n"+
  "It should still be worth quite a bit though.\n");
set_weight(1);
set_value(2000);
set_read("Though sharp as a stone,\n"+
         "A brawny warrior's dream\n"+
         "Lies in my bright shards.\n"+
"\n"+    "Seek the great dragon.\n"+
         "On his fearsome hide you may-\n"+
         "'Crush' my shimmering.\n");
  }
}

init() {
  ::init();
add_action("diamond_crush","crush");
}

diamond_crush(arg) {
  object ham;
ham = clone_object("/players/snow/WEAPONS/temblor.c");
  if(arg == "diamond" || arg == "black diamond") {
  if(call_other(this_player(),"query_attrib","str") < 19) {
    write("You do not possess the strength necessary to crush the diamond!\n");
  return 1;
  }
  if(this_player()->query_level() < 15) {
    write("You are not experienced enough to crush the diamond!\n");
  return 1;
  }
  if(!present("icingdeath",environment(this_player()))) {
    if(present("dragon",environment(this_player()))) {
      write("The scales on this dragon are not hard enough!\n");
    return 1;
    }
    write("There is no dragon here.\n");
    return 1;
  }
else
  tell_room(environment(this_player()),capitalize(this_player()->query_name())+
           " crushes a black diamond on the flanks of Icingdeath!\n");
  tell_room(environment(this_player()),
        "\n"+"A black cloud forms around the shimmering shards!\n");
  tell_room(environment(this_player()),
        "\n"+"The dragon ****ROARS**** in anger!\n");
  tell_room(environment(this_player()),
        "\n"+"A hammer forms from cloud!\n");
move_object(ham,environment(this_player()));
  tell_room(environment(this_player()),
        "\n"+"Icingdeath's eyes glow red as he grows furiously aggressive!\n");
present("icingdeath",environment(this_player()))->set_aggressive(1);
  write("You better take the hammer and get out of here!\n");
destruct(this_object());
return 1;
 }
}

quest_ob() { return 1; }
