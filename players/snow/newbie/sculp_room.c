inherit "room/room";
 
reset(arg){

if(!present("sculpture")) {
move_object(clone_object("/players/snow/newbie/sculpture.c"),this_object());
   }
 
 if(!arg){
 
 set_light(1);
  short_desc="The Sculpture";
 long_desc=
"You are floating in limbo with one object to focus your attention on.\n"+
"A huge ice sculpture dominates this otherwise empty space. A feeling\n"+
"of peace radiates about you and you feel strangely happy!\n";
 
 
  dest_dir=({
"/players/snow/gate.c","nexus"
      });
  }   }
 
 
