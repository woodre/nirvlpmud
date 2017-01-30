	/* The Fallen Oak Inn & Tavern*/
	/* Main tavern hall */

#include "/players/wren/ansi.h"; 
inherit "/players/vertebraker/closed/std/room.c";
int w,b;

reset(arg)  {   
     if(arg) return; 
 
   set_light(1);
   short_desc = "Main Hall";
   long_desc = 
"A cheery fire blazes up at the back of the hall. The air is pleasantly     \n\
warm and carries the pleasant smell of roast meats mixed with ale and       \n\
pasteries. Local patrons are gathered at the front tables to relax after    \n\
working in the fields and shops all day. The townies don't pay much         \n\
attention as you enter its clearly a quiet place and they aren't expecting  \n\
any sort of trouble. There are open tables further in and you can see       \n\
the wait staff serving the evening meal. The bar rail is crowded with       \n\
travelers eating and drinking. This looks like a very comfortable place     \n\
to escape the bad weather outside. A pair of rangers sit near the bar      \n\
watching for any signs of trouble among the customers.                       \n";

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
        write("           This will be a service menu.                              \n");
        say(this_player()->query_name() +" looks at the menu.\n");
        return 1;
                    }
              }   
  
  toss_me_bouncer()  {
      object person;
      
      write("The rangers sprint forward and punt you from the bar.\n");
      say("The rangers charge from the bar and throw "+ this_player()->query_name()+" out the front door.\n");

      this_player()->move_player("out the door#players/wren/Area/tavern/tavern_front.c");   
      person=this_player();

      b==random(5);
      switch(b)  {
               case 0:
                   tell_object(this_player(),"The rangers catch you under the arms and throw you out,\n");
                   tell_room(environment(person),this_player()->query_name()+" flys from the door hitting the tree out front.\n");
                   break;

               case 1:
                   tell_object(this_player(),"The rangers catch you under the arms and throw you out, you crash into the tree out front.\n");
                   tell_room(environment(person),this_player()->query_name()+" flys from the door hitting the tree out front.\n");
                   break;

               case 2:
                   tell_object(this_player(),"The rangers catch you under the arms and throw you out, you crash into the tree out front.\n");
                   tell_room(environment(person),this_player()->query_name()+" flys from the door hitting the tree out front.\n");
                   break;

               case 3:
                   tell_object(this_player(),"The rangers catch you under the arms and throw you out, you crash into the tree out front.\n");
                   tell_room(environment(person),this_player()->query_name()+" flys from the door hitting the tree out front.\n");
                   break;

               case 4:
                   tell_object(this_player(),"The rangers catch you under the arms and throw you out, you crash into the tree out front.\n");
                   tell_room(environment(person),this_player()->query_name()+" flys from the door hitting the tree out front.\n");
                   break;

                             }
   
return 1;
}


  	/*      */
	/*      */
	/*      */
	/*      */
