inherit "room/room";
#include "/players/boltar/things/esc.h"
  int power,stro;
  string song;
reset(arg) {
   if(arg) return;
   short_desc = "The Hall of Thoughts";
   set_light(1);
   dest_dir =
   ({
         "/room/church", "church",
         "/room/shop", "shop",
         "/players/nooneelse/black/cult_lower_hall", "vamps",
         "/players/gorgan/closed/guild/guild_room.c","undead",
         "room/post", "post",
         "/players/trix/castle/center.c", "castle",
         "/players/bastion/room/limbo", "limbo",
         "/players/trix/closed/room/bedroom.c", "west"
    });
  song=allocate(39);
    song[1]="Sometimes I feel like I don't know";
    song[2]="Sometimes I feel like checkin' out";
    song[3]="I want to get it wrong";
    song[4]="Can't always be strong";
    song[5]="And love it won't be long...";
    song[6]="Oh sugar";
    song[7]="Don't you cry";
    song[8]="Oh child";
    song[9]="Wipe the tears from your eyes";
    song[10]="You know I need you to be strong";
    song[11]="And the day is as dark as the night is long";
    song[12]="Feel like trash";
    song[12]="You make me feel clean";
    song[13]="I'm in the black";
    song[14]="Can't see or be seen";
    song[15]="Baby Baby Baby light my way";
    song[16]="You bury your treasure";
    song[17]="When it can't be found";
    song[18]="But your love is like a secret";
    song[19]="That's been passed around";
    song[20]="There is a silence that comes to a house";
    song[21]="Where no one can sleep";
    song[22]="I guess it's the price of love";
    song[23]="I know it's not cheap";
    song[24]="Baby Baby Baby light my way";
    song[25]="I remember";
    song[26]="When we could sleep on stones";
    song[27]="Now we lie together";
    song[28]="In whispers and moans";
    song[29]="When I was all messed up";
    song[30]="And I heard opera in my head";
    song[31]="Your love was a light bulb";
    song[32]="Hanging over my bed";
    song[33]="Baby Baby Baby";
    song[34]="Baby Baby Baby";
    song[35]="Baby Baby Baby light my way";
    song[36]="Baby Baby Baby";
    song[37]="Baby Baby Baby";
    song[38]="Baby Baby Baby light my way";
    power=0;  
}
look(arg)
{ if(arg=="at stereo"||arg=="hi-fi")
   { write("A hi-fi stereo system, type <power> to toggle it or or off.\n");
     return 1;
   }
  return 0;
}
long()
{ write("You are in the Hall of Thoughts, Trix's private workroom, where he usually\n"+
        "comes to enjoy silence and quietness, trying to code fun for mortal players.\n"+
        "There are exits to: church, shop, vamps, undead, post, castle, limbo and west.\n");
  if(power)
  write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m");
  write("A hi-fi stereo system."+esc+"[0m"+"\n");
}
init(){
 ::init();
if(!find_living("trix")&&this_player()->query_real_name()!="aleena")
{ write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m You are not permitted to enter!"+esc+"[0m"+"\n");
     log_file("trix.ie",call_other(this_player(),"query_real_name")+"\ttried work at "+ctime(time())+"\n");
         move_object(this_player(),"/room/church");
         return 1;
       }
   add_action("stereo","power"); 
   add_action("look","look");
}

stereo()
{ if (!power)
   { tell_object(this_player(),"You turn the stereo system on and a soft background music fills the room.\n\n");
     say(call_other(this_player(),"query_name",)+" turns the stereo system on and a soft background music fills the room.\n\n",this_player());
     stro=1;
     power=1;
     call_out("play",1);
   }
  else
   { remove_call_out("play");
     tell_object(this_player(),"You turn the stereo system off.\n");
     say(call_other(this_player(),"query_name",)+" turns the stereo system off.\n",this_player());
     power=0;
   }
  return 1;
}

play()
{ 
  tell_room(this_object(),"*** "+song[stro]+" ***\n");
     stro++;
   if (stro<=38)
    { call_out("play",2);
    }
  else
    {tell_room(this_object(),"\nThe songs finishes and the stereo system turns off automatically.\n");
     power=0; 
}
}      
realm(){return "NT";}
