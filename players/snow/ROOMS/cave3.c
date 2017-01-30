#define TRES "/players/snow/random/treasure.c"
inherit "room/room";
 
int searched;

reset(arg){
 
if(!present("cave bear"))  {
move_object(clone_object("/players/snow/MONSTERS/cave_bear.c"),this_object());                                    }

  searched = 0;  /* Rumplemintz */
 
 if(!arg){
 
 set_light(0);
  short_desc="The Lair";
 long_desc=
 "You have entered the living place of the owner of this cave. There are \n\
multitudes of bones and bits of clothing strewn about. What occupies \n\
your attention most about this room is the awful stench of decayed flesh.\n";
 
items=({
 "bones", "Chewed bits and pieces of bones, many of which look human",
 "clothing","Tattered shreds of clothing strewn about the room",
 "bits","Tattered shreds of clothing strewn about the room"
           });
 
  dest_dir=({
  "/players/snow/ROOMS/cave1.c","east"});
  }   }
 
init()  {
 ::init();
  add_action("search_room","search");
         }
 
search_room() {
  object bear, coins, sword;
  bear = present("cave bear");
  if(bear) {
    write("Your searching causes the Cave Bear to attack you!\n");
    bear->attack_object(this_player());
    return 1; }
  if(searched == 1) {
    write("You find nothing of value.\n");
    return 1; }
  write("You find some treasure buried in the refuse!\n");
  searched = 1;
  coins = clone_object("/obj/money.c");
  coins->set_money(random(2000)+500);
  move_object(coins, this_object());
  call_other(TRES, "random_item");
  call_other(TRES, "random_item");
  sword = clone_object("/players/snow/WEAPONS/glass_sword.c");
  move_object(sword, this_object());
  return 1;
}
