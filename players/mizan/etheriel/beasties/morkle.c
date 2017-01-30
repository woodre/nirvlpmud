inherit "/players/mizan/core/monster.c";
int hps;

reset(arg)
{
   object treasure;
   object heal;
   ::reset(arg);
   if(arg) return;
   set_name("morkle");
   set_race("fungus");
   set_alias("morkle");
   set_short("Morkle the wandering fungus");
   set_level(20);
   set_hp(320);
   set_al(740);
   set_wc(24);
   set_ac(22);
   set_aggressive(0);
   load_chat("Morkle drifts around.\n");
   load_chat("Morkle blurbles: Hi there!\n");
   load_chat("Morkle blurbles: I'm kind of lost...\n");
   heal=clone_object("players/mizan/etheriel/items/rawtoast.c");
   move_object(heal,this_object());
  move_object(clone_object("players/mizan/etheriel/items/moo-toaster.c"), this_object());
   enable_commands();
}

long() {
  write("Morkle is a happy fungus, drifting about the area in an utterly\n"+
	"random fashion. Unable to speak (obviously), Morkle communicates\n"+
	"telepathically, but most of its thoughtforms remain an cluttered,\n"+
	"jumbled, mess of random emotions.\n");
  ::long();
}

heart_beat(){
   object attacker,room;
   string attacker_name;
   string munchie;
   ::heart_beat();
   hps=this_object()->query_hp();
   room=environment(this_object());
   attacker=this_object()->query_attack();
   if(attacker){
      attacker_name=attacker->query_real_name();
      if(present(attacker_name,environment(this_object()))){
        if(attacker->query_level() < 5) {
          munchie=call_other("/players/mizan/closed/RandomRoomDM", "one_random", 0);
          say("Morkle ponders mogfully.\n");
          this_object()->move_player("X#players/mizan/etheriel/ROOMS/" + munchie);
        }
        if(1 == random(21)) {
          tell_room(room, "Morkle heals itself.\n");
          this_object()->heal_self(random(100));
        }
        if(1 == random(25)) {
          tell_room(room, "Morkle sprays a poisonous jet of glop at "+capitalize(attacker_name)+"!\n");
          attacker->run_away();
        }
        if(hps < 100) {
          munchie=call_other("/players/mizan/closed/RandomRoomDM", "one_random", 0);
          command(munchie, this_object());
        }
      }
   }
}
