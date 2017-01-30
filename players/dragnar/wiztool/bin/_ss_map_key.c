#include <ansi.h>
#include <regexp.h>

mapping map_key;
mixed *map_key_a;
string *exit_rooms;
string delimiter;

status cmd_ss_map_key(string str) {
  write("Str is : "+str+"\n");
   if( str == "players/dragnar/SevenSpires/rooms/citadel/s1" ) {
     delimiter = "";

	 map_key = ([ "_": ({ HIK, "Spire" })
              , "/": ({ HIK, "Spire" })
              , "\\": ({ HIK, "Spire" }) 
              , "(": ({ HIK, "Spire" })
              , ")": ({ HIK, "Spire" })
              , "@": ({ YEL, "Path" })
              , "#": ({ HIK, "Path" })
              , "#": ({ HIW, "Path" })
	      , "X": ({ BLINK, "Current Location" })
	      , ".": ({ BLK, "?" })
              ]);
/*
	 map_key = ([ "_": ({ HIK, "Spire" })
	      , "X": ({ BLINK, "Current Location" })
              ]);
*/
#ifndef __LDMUD__
     map_key_a = deconstruct_mapping( map_key );
#endif
     exit_rooms = ({ "@", "#", "X", "O", });
   }
   else if( str == "players/dragnar/SevenSpires/rooms/forest/f1" ) {
     delimiter = " ";
     
	 map_key = ([ "@": ({ HIG, "Forest" })
              , "-": ({ HIR, "Path" })
              , "+": ({ HIR, "Path Junction" })
              , "|": ({ HIR, "Path" })
              , "%": ({ GRN, "Plains" })
              , "^": ({ HIB, "Body of Water" })
              , "#": ({ YEL, "Hills" })
              , ".": ({ HIBLK, "Impassable" })
	      , "X": ({ BLINK, "Current Location" })
              ]);
#ifndef __LDMUD__
     map_key_a = deconstruct_mapping( map_key );
#endif
     exit_rooms = ({ "@", "+", "-", "|",  "X", "#", "%", });
   }
   else {
     write("Invalid directory.\n");
     return 1;
   }
   save_object( str+"/map_key" );
   write("Saving... "+str+"/map_key\n" );
   return 1; 
}
