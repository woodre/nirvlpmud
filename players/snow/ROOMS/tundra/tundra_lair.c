/* Room with Polar Bear and random searching treasure */

#define TRES "/players/snow/random/treasure.c"
inherit "room/room";

int searched;
 
reset(arg){
 
if(!present("polar bear"))  {
move_object(clone_object("/players/snow/MONSTERS/polar_bear.c"),this_object());  }
 
 if(!arg){
 
 set_light(1);
  short_desc="A cave lair";
 long_desc=
 "Feeling brave, you have ventured deep into the snow cave. It has finally\n\
opened up into a large circular area, about 30 meters in diameter. This\n\
seems to be the lair of some great beast. Tatters of hide and bone lie all\n\
about you and and the scent of old meat is somewhat nauseating.\n";
 
items=({
 "tatters", "Shreds of hide and bone",
 "hide","Small ripped pieces of animal skin. You think you recognize a " +
           "human scalp but you can't be sure...",
 "bone","Splinters of chewed bone",
           });
 
  dest_dir=({
  "/players/snow/ROOMS/tundra/tundra6.c","leave",
      });
  }   }
 
 
init()  {
 ::init();
  add_action("search_room","search");
         }
 
search_room() {
  object bear, coins, gem;
  bear = present("polar bear");
  if(bear) {
    write("Your searching causes the Polar Bear to attack you!\n");
    bear->attack_object(this_player());
    return 1; }
  if(searched == 1) {
    write("You find nothing of value.\n");
    return 1; }
  write("You find some treasure buried in the refuse!\n");
  searched = 1;
  coins = clone_object("/obj/money.c");
  coins->set_money(random(2000)+1000);
  move_object(coins, this_object());
  call_other(TRES, "random_item");
  call_other(TRES, "gem");
  return 1;
}
