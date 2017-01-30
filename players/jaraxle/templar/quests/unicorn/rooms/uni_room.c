#define PATH "/players/jaraxle/templar/quests/unicorn/rooms/"
#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

array *rooms;
int RELEASED;

reset(arg) {
   RELEASED = 0;
   
   if(arg) return;
   rooms = ({ "cave1","cave2","cave3","cave4" });
   
   set_light(0);
   
   short_desc = "Dark Caverns";
   long_desc =
   " The caverns open up to a large, wide area.\n"+
   "A huge cage stands at the rear of the room.\n";
   
   items = ({
         "cage","blah",
});
   
   dest_dir = ({
         "/players/jaraxle/3rd/pyramid/rooms/room.c","east",
         "/players/jaraxle/3rd/pyramid/rooms/roomw2.c","north",
         "/players/jaraxle/3rd/pyramid/rooms/room2.c","northeast",
});
   
}
realm() { return "NT"; }

init(){
   ::init();
   add_action("release","release");
}

long(arg)
{
   if(arg == "cage")
      {
      string mod;
      string uni;
      
      if(RELEASED >= 1){
         mod = "open";
         uni = "nothing";
      } else {
         mod = "closed";
         uni = "a "+HIW+"Unicorn"+NORM+"";
      }
      
      write("A large square cage about ten feet tall and wide.\n"+
         "There is a large gate which is "+HIM+"[ "+HIW+mod+HIM+" ]"+NORM+", and through\n"+
         "the bars you can see that "+HIM+"[ "+NORM+uni+NORM+" "+HIM+"]"+NORM+" is trapped inside.\n");
      
      return;
   }
   
   ::long(arg);
}

release(arg)
{
   int s, x; /* s is the counter for the inventory of each room,
   x counts the rooms in the array */
   object room, *inv;
   
   if(RELEASED >= 1){ write("There is nothing here to release.\n"); return 1; }
   if(arg == "unicorn")  /* if arg is correct */
      {
      tell_object(this_player(),"You unlock the cage and release the unicorn.\n");
      tell_room(environment(this_player()), "A Unicorn walks freely out of the cage!\n"+
         "A horde of screaming can be heard echoing through the caverns.\n");
move_object(clone_object("/players/jaraxle/templar/quests/unicorn/mon/u.c"),this_object());
      for (x = 0; x < sizeof(rooms); x++) /* for each element.. */
      {
         room = find_object(PATH + rooms[x]); /* see if the room
            is loaded */
         if(!room)  /* if not */
            { 
            (PATH + rooms[x])->load_me();
            room = find_object(PATH + rooms[x]); /* now grab it ! */
           }
         
         move_object(clone_object("/players/jaraxle/templar/quests/unicorn/mon/raider"),
            room);
         RELEASED +=1;
      }
      /* :) */
      return 1;
    }
    
    /* added for fun.. notify_fail() lets other objects evaluate
       the verb, but gives a message if no other objects
       can . */
    notify_fail("Type 'pull lever'.\n");
    return 0;
}
