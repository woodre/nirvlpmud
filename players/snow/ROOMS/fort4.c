/* A room deep inside the Fortress of Snow in which players can clone
 * a maximum of 2 huge snow demons (very, very tough)
 */

inherit "room/room";
 
int flashes;
reset(arg){
 
 
  flashes = 0;
 if(!arg){
 
 set_light(1);
  short_desc="Magica";
 long_desc=
"  You have come to a strange, spherical chamber. There is a glowing ball\n\
of what appears to be crystal floating in the center of the room.\n\
  The walls are made of some sort of metallic substance and the only exit\n\
seems to be the staircase you came down on.\n";
 
items=({
 "ball", "As you concentrate on the floating ball of crystal, a voice\n"+
         "enters your mind...\n\t** Grasp the ball for a test of skill **\n"+
         "... The voice fades away and you shiver for a second",
 "crystal", "As you concentrate on the floating ball of crystal, a voice\n"+
        "enters your mind...\n\t** Grasp the ball for a test of skill **\n"+
        "... The voice fades away and you shiver for a second",
 "walls", "The metallic substance appears impenetrable",
 "substance", "The metallic substance lining the walls appears impenetrable",
 "staircase", "This is the staircase you came down to enter this chamber",
          });
 
  dest_dir=({
  "/players/snow/ROOMS/fort3.c","up",
      });
  }   }
 
 
init()  {
 ::init();
  add_action("grasp_ball","grasp");
        }
 
grasp_ball(string str) {
  object ob, mon;
  if(!str) { notify_fail("Grasp what?\n"); return 0; }
  if(str != "ball") { notify_fail("Grasp what?\n"); return 0; }
  else write("You grasp the ball of crystal and are pierced with COLD!\n\n"+
    "\tYou cannot let go... PAIN courses through your wracked frame!\n"+
    "\nSuddenly, it stops. A light grows in the ball and it FLASHES!\n");
  say(this_player()->query_name()+" grasps the ball of crystal, grimaces \n"+
      " in pain, then lets go as a light FLASHES!\n");
  if(flashes >= 2) {
    tell_room(this_object(), "Nothing happens.\n"); return 1; }
  else
  flashes ++;
  mon = clone_object("/players/snow/MONSTERS/snow_demon");
  mon->set_short("A HUGE Snow Demon");
  mon->set_hp(1000);
  if(random(2)) {
  ob = clone_object("/players/snow/WEAPONS/balance.c");
  move_object(ob, mon);
  }
  move_object(mon, this_object());
  mon->attack_object(this_player());
  return 1; }
