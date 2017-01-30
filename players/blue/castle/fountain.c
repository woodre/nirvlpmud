inherit "room/room";

reset(arg) {
 
  if(!arg){
   set_light(1);
     short_desc = "A fountain";
     long_desc = 
"Ahead of you is a beautiful circular fountain about 20 feet across.  Altho"+
"ugh\nit is ancient, time and the elements haven't been able to destroy its"+
"lovely\nluster.  This castle once have once been a very gloriuos thing inde"+
"ed.\n"+
"   You think you can see something in the fountain that looks shiny, but yo"+
"u\ncan't be sure without looking closer...\n";

dest_dir = ({
   "players/blue/castle/courtne","north",
   "players/blue/castle/courtyard","west"
   });
   }
}


init() {
 ::init();
   add_action("check_out", "examine");
   add_action("check_out","search");
   add_action("look_at","look");
}

check_out(str) {
   object room;
  if(str != "fountain") {
   return 0;
   }
   if(!str) return 0;
   call_other("players/blue/castle/infount","??");
   room = find_object("players/blue/castle/infount");
   if(present("spirit", room)) {
   write("The water comes alive and grabs you!  You are pulled into the foun"+
         "tain!!\n");
say(capitalize(this_player()->query_name()) +" gets pulled into the fountai"+
      "n!\n");
   this_player()->move_player("fountain#players/blue/castle/infount.c");
   return 1;
}
   write("Now that you look closer you find there is nothing.\n");
   return 1;
}

look_at(str) {
   object room;
   object obj;
   if(!str) return;
   sscanf(str, "at %s", obj);
   if(!obj) return 0;
   if(obj != "fountain") return 0;
   call_other("players/blue/castle/infount", "??");
   room = find_object("players/blue/castle/infount");
   if(present("spirit", room)) {
   write("The water comes alive and grabs you!  You are pulled into the foun"+
         "tain!!\n");
say(capitalize(this_player()->query_name()) +" gets pulled into the fountai"+
       "n!\n");
   this_player()->move_player("fountain#players/blue/castle/infount.c");
   return 1;
}
   write("Now that you look closer you find there is nothing.\n");
   return 1;
}
search(str) {
   object room;
   object obj;
   if(!str) return 0;
   if(str !="fountain") return 0;
   call_other("players/blue/castle/infount", "??");
   room = find_object("players/blue/castle/infount");
   if(present("spirit", room)) {
   write("The water comes alive and grabs you!  You are pulled into the foun"+
         "tain!!\n");
say(capitalize(this_player()->query_name()) +" gets pulled into the fountai"+
       "n!\n");
   this_player()->move_player("fountain#players/blue/castle/infount.c");
   return 1;
}
   write("Now that you look closer you find there is nothing.\n");
   return 1;
}
