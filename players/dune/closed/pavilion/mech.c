/* This is the actual RoboMech */
inherit "obj/monster";

string name;
string aim, target, type, pilot;
int hits, speed, maxheat, maxcapacity;
static int blasted;

id(str) { return str == name || str == "mech" ||
                 str == "_robomech_"; }

reset(arg) {

   if(!present("_cockpit_")) {
     object pit; 
     pit = clone_object("/players/dune/closed/pavilion/cockpit.c");
     move_object(pit, this_object());
     pit->init();
   }

   ::reset(arg);
   if(arg) return;

   do_check();

   if(!name) {
      set_name("mech");
      set_short("A RoboMech");
   }
   else set_short(capitalize(name)+", the RoboMech");
   set_alias("mech");
   set_level(1);
   set_race("robot");
   if(!hits) set_hp(1);
   else set_hp(hits);
   set_wc(1);
   set_ac(1);
   set_ep(0);
   set_no_exp_value();
   enable_commands();
   set_aggressive(0);
   set_dead_ob(this_object());
   set_long(
      "     You are nestled deep in the armored interior of your mech.\n"+
      "Around you are the various gyrofiber-muscle and arsenal controls\n"+
      "that allow you to masterfully control the high-tech war machine.\n"+
      "To download the mech hyperdocument, type \"robo\".\n"+
      "To exit your mech at anytime, type \"bail\".\n");
}

do_check() {
  /* cooling system and destructor */
  if(!present("_cockpit_", this_object())) {
    destruct(this_object());
    return 1; }
  if(present("_cockpit_"))
    if(present("_cockpit_")->query_heat() > 0)
      present("_cockpit_")->add_heat(-1);
  call_out("do_check", 6);
}

set_myname(string str) {
   name = str;
   set_name(name);
}
string query_myname() { return name; }
set_hits(int num) { hits = num; }
int is_mech() { return 1; }
string query_pilot() { return pilot; }
set_pilot(string new) { pilot = new; }
string query_type() { return type; }
set_type(string new) { type = new; }
int query_maxcapacity() { return maxcapacity; }
add_maxcapacity(int num) { maxcapacity += num; }
set_maxcapacity(int num) { maxcapacity = num; }
int query_maxheat() { return maxheat; }
set_maxheat(int num) { maxheat = num; }
add_max_heat(int num) { maxheat += num; }
int query_speed() { return speed; }
set_speed(int num) { speed = num; }
string query_aim() { return aim; }
string query_target() { return target; }
set_aim(string new) { aim = new; }
set_target(string new) { target = new; }
int query_blown_away() { return blasted; }
set_blown_away(int new) { blasted = new; }
realm() { return "NT"; }

catch_tell(string str) {
  /* allows pilot to hear things in room */
  tell_room(this_object(), str);
  return 1;
}

/* mechs do not leave corpses lying around
   also, players can use corpses for other reasons so remove it
*/
monster_died(object ob)
{
  if (present("corpse", environment(this_object())))
  {
    destruct(present("corpse", environment(this_object())));
  }
}
