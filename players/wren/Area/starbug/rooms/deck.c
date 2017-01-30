	/* MainDeck of Starbug. Have the guys as the normally appear through series */
	/* Midsized monsters, should be a challenge, spouting quotes and nifty toys */


inherit "room/room";
int searched;

reset(arg)  {
   if(arg) 
      return ;

   if(!present("kryten")) {
      move_object(clone_object("/players/wren/Area/starbug/posse/kryten.c"),this_object()); }
   if(!present("rimmer")) {
      move_object(clone_object("/players/wren/Area/starbug/posse/rimmer.c"),this_object()); }
   if(!present("cat")) {
      move_object(clone_object("/players/wren/Area/starbug/posse/cat.c"),this_object()); }
   if(!present("lister")) {
      move_object(clone_object("/players/wren/Area/starbug/posse/lister.c"),this_object()); }


   set_light(1);
   short_desc = "Main Deck";
   long_desc = 
"Starbug's Main Deck is the center of life on ship. Here they \n\
plan the events of the day and dine. A large table fills the\n\
center of the room. Dishes, wires, and dirty clothing are \n\
strewn across its surface. Several monitors flicker on the \n\
back wall. Crates are stacked around the perimeter. \n";

      items=({
          "table","A large table that contains everything the guys are using with room for eight seats",
	  "dishes","Dirty dishes that Kryten hasn't had a chance to clear. One plate looks really gross",
	  "wires","Well you know there are always bits left over in 'do it yourself' jobs",
	  "clothing","Dirty socks that Lister must have shed recently or else everyone would have fled",
	  "monitors","Screens displaying ships statistics, crew data or showing Holly",
	  "holly","Holly winks at you and asks if you want to play charades using just your nose",
	  "crates","These have been gathered from derilicts that were entered for supplies, it wasn't looting though",
          "seats","These are pretty standard looking plastic and metal chairs",
          "plate","This plate has the remains of a roasted space weevil, gross"
             });

        
      dest_dir = ({
          "/players/wren/Area/starbug/rooms/bridge","bridge",
          "/players/wren/Area/starbug/rooms/quarters","quarters", 
          "/players/wren/Area/starbug/rooms/airlock","airlock",
	  "/players/wren/Area/starbug/rooms/engine","engine",
          "/players/wren/Area/starbug/rooms/galley","galley" 
                 }); 
 
searched = 0;   
}

  init() {
    ::init();
    add_action("search_room","search");
          }


  search_room()  {
      if(searched == 0) {
        write("You search through the clutter and a couple things hold your attention\n");
        say (this_player()->query_name() +" searches the area. \n");
        move_object(clone_object("/players/wren/Area/starbug/items/lager.c"),this_object());
        move_object(clone_object("/players/wren/Area/starbug/items/poppadom.c"),this_object());
        searched = 1;
        return 1;
                        }
      else {
        write("You search the clutter but find nothing clean enough to keep.\n");
        say(this_player()->query_name() +" searches the area. \n");
        return 1;            
           }
     }

	/* Lister -dreds+hat,curries,leather jacket, guitar(jam attack WC16)    */
	/* Cat -fish,red sequin jacket(miscAC2),comb, mirror, fashion attack    */
	/* Rimmer -light bee, Nuerosis or Arrogance(WC18), Charisma(shieldAC-1) */
	/* Kryten -Lister's dirty laundry, groinal attachment,spare head3(WC18) */
        /* search reveals:pompadoms, flat lager w/cigar dibs(drink-mild poison) */

