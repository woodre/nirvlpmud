/* added a random(3) == 0 and changed return to 7
   - mythos <5-15-96>
 */

inherit "obj/weapon";

int att;

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("dagger");
   set_short("The Dopple Dagger");
   set_long(
      "This is an amazingly stout little dagger.  It fits your hand\n"+
      "perfectly.  It is very heavy for such a small item, because it\n"+
      "is hand crafted from the finest steel.  It is black with age\n"+
      "and rare oils.  You see runes pressed into the grip.\n");
   set_alias( ({ "dagger", "dopple dagger" }) );
   set_value(0);
   set_class(18);
   set_weight(3);
   set_hit_func(this_object());
}
can_put_and_get() { return 1;}

weapon_hit(attacker_ob) {
  if(random(3) == 0) {
   if(attacker_ob->query_alignment() < 300) {
      write("The dagger leaps of it's own accord and smites your enemy.\n");
      say(this_player()->query_name() + "'s weapon emits an eerie\n"+
         "hum and smites " + attacker_ob->query_name() + "\n");
      return 7;
   } }
   return 0;
}

init() {
   ::init();
   add_action("read", "read");
   add_action("wield", "wield");

}

read(str) {
   if(str == "runes" || str == "writing") {
      write("The runes say: Ye who holds the dagger, dies with it...\n");
      return 1;
   }
   notify_fail("Read what?\n");
   return 0;
}
wield() {
/*
   if (!present ("badge", this_player())) {
     write("This weapon does not fit your hand.\n");
     return 1;
  }
*/
  if (this_player()->query_alignment()>200)  {
    write("You are not wicked enough to wield this weapon!\n");
    return 1;
  }
  write("You feel the dagger vibrate with power as you wield it.\n");
  ::wield();
  return 1;
}
