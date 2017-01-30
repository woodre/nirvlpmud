/* changed the return to str/3 and the random to 50
  - mythos <5-15-96>
*/
inherit "obj/weapon";

int att;

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("axe");
   set_short("Barbarian Axe");
   set_long(
      "This axe comes from the far eastern woodlands of Greyhawk.  It\n"+
      "is where the barbarians reside.  With the proper strength, the\n"+
      "holder of this axe can devastate his opponents.\n");
   set_alias( ({ "axe", "barbarian axe" }) );
   set_value(5000);
   set_class(17);
   set_weight(3);
   set_hit_func(this_object());
}
weapon_hit(attacker_ob) {
   if(this_player()->query_attrib("str")>random(50)) {
   write("You yell BRUUL and smash your opponent to pieces!\n");
   return(att);
   }
   return 0;
}

init() {
   ::init();
   add_action("wield", "wield");

}

wield() {
   att=this_player()->query_attrib("str");
   if(att < 15) {
     write("You cannot wield this weapon properly.\n");
     return 1;
  }
  write("A shiver of energy enters your body as you equip this axe\n");
  ::wield();
  return 1;
}
