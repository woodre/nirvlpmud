/* 
 * Floor core code, by Dune at Nirvana (6/18/97)
 * std_floor.c is copied and modified upon hotel generation
 * Change std_floor.c is a change in hotel floors is desired
 */


#include "../def.h"
inherit "room/room";

int floor;
string *exits;

init() {
  if(!floor) {
    write("\n\nThe hotel doors are not open yet.\n"+
          "The clerk can assist you on this.\n\n");
    move_object(this_player(), PATH+"office.c");
    return 1; }
  add_action("enter","enter");
  ::init();
}


int query_floor() { return floor; }

reset(arg) {
  int i;
  if(!arg) {
    set_light(1);

    short_desc= HOTELNAME+", floor "+floor;
    long_desc = 
"    You are on floor "+floor+" of "+HOTELNAME+".\n"+
"Carved wooden archways line the entrance of each\n"+
"guest room. Along the hallway, soft glowing globes\n"+
"of yellow-orange emit a pleasant light.\n"+
"To inquire about room exits, type 'enter'.\n";
     }
  }


setup_floor(int floornum) {
  /* set room variables and generate room exits */
  int i, floors, count, level;
  string room;

  floor = floornum;
  count = 0;
  floors = ROOMS / ROOMSPERFLOOR;

  /* exits will not only be to rooms, but to other floors
   * and also the hotel office */
  if(floor == 1)                       count++;
  if((floors > 1) && (floor < floors)) count++;
  if((floors > 1) && (floor > 1))      count++;

  /* level is the current story of this floor */
  level = (floor - 1) * ROOMSPERFLOOR;

  /* allocate enough for rooms and other exits */
  exits = allocate(ROOMSPERFLOOR + count);

  /* iterate and make an exit for each room */
  for(i = 0; i < ROOMSPERFLOOR; i++) {
    exits[i] = ("room" + (level+i+1));
    }

  /* now add exits other than to rooms */
  if(floor == 1) {
    exits[i] = "office";
    i+=1; }
  if((floors > 1) && (floor < floors)) {
    exits[i] = "up";
    i+=1; }
  if((floors > 1) && (floor > 1)) exits[i] = "down";

  /* make sure room description is properly updated */
  reset();
  return 1;
  }


enter(string place) {
  /* instead of dest_dir, an 'enter' command is used
   * this facilitates the generation of room exit commands */
  int i;
  string roomfile;
  status correct;
  if(!place) {
    write("To move into another room,\n"+
          "use the corresponding command...\n");
    write("--------------------------------\n");
    for(i = 0; i < sizeof(exits); i++) {
      write("  enter "+exits[i]+"\n");
      }
    write("--------------------------------\n");
    return 1; }
  place = lower_case(place);
  correct = 0;
  for(i = 0; i < sizeof(exits); i++) {
    /* has guest specified correct exit?
     * easy to tell, because exits stores locations */
    if(exits[i] == place) correct = 1;
    }
  if(!correct) {
    write("Enter where?\n");
    return 1; }
  if(place == "up")     place = "floor"+(floor+1);
  if(place == "down")   place = "floor"+(floor-1);

  roomfile = ROOMPATH+place;
  if(place == "office") roomfile = PATH+place;
  roomfile = extract(roomfile, 1, strlen(roomfile));

  call_other(this_player(), "move_player", 
    place+"#"+roomfile);
  return 1;
}
