	/* The Fallen Oak Inn & Tavern*/
	/* Main tavern hall */

#include "/players/wren/ansi.h"; 
inherit "/players/vertebraker/closed/std/room.c";
int w;

reset(arg)  {   
     if(arg) return; 
 
   set_light(1);
   short_desc = "Main Hall";
   long_desc = 
"A cheery fire blazes up at the back of the hall. The air is pleasantly \n\
warm and carries the pleasant smell of roast meats mixed with ale and   \n\
pasteries. Local patrons are gathered at the front tables to relax after\n\
working in the fields and shops all day. The townies don't pay much     \n\
attention as you enter its clearly a quiet place and they aren't        \n\
expecting any sort of trouble. There are open tables further in and you \n\
can see the wait staff serving the evening meal. The bar rail is crowded\n\
with travelers eating and drinking. This looks like a very comfortable  \n\
place to escape the bad weather outside. A pair of rangers sit near the \n\
bar watching for any signs of trouble among the customers.              \n";

      items=({		/*Remember two deep on noun descriptions*/
          "","",
	  "","",
          "","",
	  "","",
	  "","",
	  "","",
	  "","",
	  "","",
          "","",
          "","",
          "","",
          "","",
          "","",
          "",""
             });

        
      dest_dir = ({
          "/players/wren/Area/tavern/tavern_hall2.c","west",
          "/players/wren/Area/tavern/tavern_front.c","east", 
                 }); 
 
set_chance(1);       
add_msg(" \n");
add_msg(" \n");
add_msg(" \n");
add_msg(" \n");
add_msg(" \n");

add_listen("main"," ");
add_listen(" "," ");
add_listen(" "," ");

add_smell("main"," ");
add_smell(" "," ");
add_smell(" "," ");

add_touch(" "," ");

add_exit_msg("dir","message to mover\n",
                    "movement seen by others\n");
}

  init() {
    ::init();
    add_action("search_room","search");
    add_action("read_menu","read");

    add_action("toss_me_bouncer","banshee");
    add_action("toss_me_bouncer","strike");
    add_action("toss_me_bouncer","kill");
    add_action("toss_me_bouncer","mi");
    add_action("toss_me_bouncer","sh");
    add_action("toss_me_bouncer","fi");
    add_action("toss_me_bouncer","so");
    add_action("toss_me_bouncer","pummel");
    add_action("toss_me_bouncer","p3");
    add_action("fire_drill","flick_lighter");
    add_action("fire_drill","burn");
    add_action("fire_drill","inferno");

         }

  search_room()  {
        write(" \n");
        say (this_player()->query_name() +" searches the area. \n");
        return 1;
                 }

  read_menu(str) {
      if(str != "menu") {
        write("Read what?\n");
        return 0;
                       }
      if(str == "menu") {
        write("\n");
        write("A serving girl brings you the slate with today's menu.              \n");
        write("\n");
        write("    Todays vitels are:          \n");
        write("        Foods:                       Expense:        \n");        
        write("         1. Todays Special              150 coins    \n");
        write("         2. Biscuits and gravy          100 coins    \n");
        write("         3. Ham and eggs                120 coins    \n");
        write("         4. Pheasant ala Meriwether     140 coins    \n");
        write("         5. Vegtable Stew               150 coins    \n");
        write("         6. Dom's pasta with pesto      180 coins    \n");
        write("         7. Trout Almandine             220 coins    \n");
        write("         8. Venison and flat bread      340 coins    \n");
        write("         9. Stir fry w/ sweet rolls     440 coins    \n"); 
        write("        10. Feast                       800 coins    \n");
        write(" \n");
        write("        Beverages:                   Expense:        \n");
        write("        11. Pure Water                   10 coins    \n");
        write("        12. Summer Beer                  30 coins    \n");
        write("        13. Hot tea and scones           50 coins    \n");
        write("        14. Mead                         70 coins    \n");
        write("        15. Ale                         100 coins    \n");
        write("        16. Black Stout                 120 coins    \n");
        write("        17. Rasberry wine               200 coins    \n");
        write("        18. Sherry                      300 coins    \n");
        write("        19. Fey wine                   1000 coins    \n");
        write("        20. Wren's Private Stock        500 coins    \n");
        write(" \n");
        write(" You may also buy a round for the bar with 'buy round of'\n");
        write(" and the menu item of choice. Be sure to check your coin \n");
        write(" purse first for this can be expensive. But the patrons  \n");
        write(" will love you for your generosity.                      \n");
        write(" \n");
        say(this_player()->query_name() +" looks at the menu.\n");
        return 1;
                    }
              }   
  
  toss_me_bouncer()  {        /*damage will be added later if trouble makers persist*/
      object person;
      
      write("The rangers sprint forward and punt you from the bar.\n");
      say("The rangers charge from the bar and throw "+ this_player()->query_name()+" out the front door.\n");

      this_player()->move_player("out the door#players/wren/Area/tavern/tavern_front.c");   
      person=this_player();

      
      switch(random(5))  {
               case 0:
                   tell_object(this_player(),"The rangers catch you under the arms and throw you out,\n");
                   tell_room(environment(person),this_player()->query_name()+" flies from the door hitting the oak tree out front.\n");
                   break;

               case 1:
                   tell_object(this_player(),"The rangers catch you under the arms and throw you out,\n");
                   tell_room(environment(person),this_player()->query_name()+" screams out the door crashing painfully in the dust.\n");
                   break;

               case 2:
                   tell_object(this_player(),"The rangers catch you under the arms and throw you out,\n");
                   tell_room(environment(person),this_player()->query_name()+" spins out of the door and lands with a "+BLU+"Spash"+NORM+" in the horse troth.\n");
                   break;

               case 3:
                   tell_object(this_player(),"The rangers catch you under the arms and throw you out,\n");
                   tell_room(environment(person),this_player()->query_name()+" thuds painfully into the doorjam and rolls off to land in the flowerbed.\n");
                   break;

               case 4:
                   tell_object(this_player(),"The rangers catch you under the arms and throw you out,\n");
                   tell_room(environment(person),this_player()->query_name()+" lands gently in the road only to get run over by and oxcart of turnips.\n");
                   break;

                             }
                     return 1;
                   }

       fire_drill()  {
              object person;
              person=this_player();

              tell_room(environment(person),"Bluish Runes scattered around the room scream to life creating a   \n");
              tell_room(environment(person),"horrible din. Small black clouds gather over the flame and thunder \n");
              tell_room(environment(person),"can be heard as the mini-rain clouds form. A brisk rain quickly    \n");
              tell_room(environment(person),"extinguishes the dangerous flame source. The alarm quiets and the  \n");
              tell_room(environment(person),"runes fade back into the wood paneling.                            \n"); 

/*add damage code for firestarter and noise */


              return 1;
                     }




  	/*      */
	/*      */
	/*      */
	/*      */
