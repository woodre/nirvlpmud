	/* This is Starbug from BBC TV series RedDwarf			*/
        /* Funny funny stuff, first area to be implimented		*/
	/* Current count 10ish rooms, 22 monsters, 7 weapons, 22items   */
        /* file is     players/wren/Area/starbug/rooms/bridge.c         */

inherit "room/room";
int searched;

reset(arg)  {
    if(arg) 
       return ;

    if(!present("holly")) {
        move_object(clone_object("/players/wren/Area/starbug/posse/holly.c"),this_object()); }      

    set_light(1);
    short_desc = "Bridge of Starbug";
    long_desc = 
"This is the main bridge of the Jupiter Mining Corp vessel Starbug 2. \n\
The Red Dwarf crew spends a lot of time here while exploring the universe\n\
in search of their lost ship and a really good curry. A large windshield\n\
dominates the front view with lots of toggles everywhere. There are four\n\
operation stations here pilot, copilot, communication, and tactical. A \n\
large monitor beside you displays the image of Holly the ships computer. \n";               

    items=({
   "windshield","A relatively sturdy screen to keep the Dwarfers and the vacuum seperate",
   "space","Stars and swirly spacial thingys outside the ship",
   "vacuum","The void of space, you think this oxygen rich environment is better",
   "toggles","Toggles to control all sorts of ships functions, they aren't labeled well though",
   "stations","The four seats for the command crew",
   "pilot","This is the Cat's usual post, the chair doesn't squeak and the headset is stuck on country western",
   "copilot","Lister's seat. He shares control of the ship with Cat's superior olfactory skills",
   "communication","With his vast library of alien language and protocols this is Kryton's chair naturally",
   "tactical","First Rimmer with his danger aversion skills then later Kachanski with real ability used this seat",
   "monitor","This monitor is one of the interactive points to the ships AI Holly",
   "image","You see Holly the ships computer",
   "holly","Holly the second incarnation. A blond dimwitted female. Not sure exactly how she became the AI's persona",
   "seats","Synthetic leather chairs with seat belts. They don't adjust very well",
   "headset","The headset got stuck on Country Western after a gelf fire fight"
          });
   dest_dir = ({
       "/players/wren/Area/starbug/rooms/deck","deck"
              }); 
searched = 0;

}
      init() {
        ::init();
           add_action("search_room","search");
              }

      search_room() {
         if(searched == 0) {
           write("You dig around the stations and find some objects.\n");
           say (this_player()->query_name() +" searches the area. \n");
           move_object(clone_object("/players/wren/Area/starbug/items/redbulb.c"),this_object()); 
           move_object(clone_object("/players/wren/Area/starbug/items/fuzzy_dice.c"),this_object()); 
           searched = 1;
           return 1;
                   }

         else   {
           write("You search around and find nothing but dust and peanut shells.\n");
           say(this_player()->query_name() +" searches the area.\n");
           return 1;
                }
           }

	/* Senile Holly on cart, Female Holly on screen. */
 	/* Search: reveal fuzzy dice, red bulb, 	 */
