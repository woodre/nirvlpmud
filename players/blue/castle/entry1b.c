inherit "room/room";

init() {  
   ::init() ; 
     add_action ("lift_gate", "lift");
     }

reset(arg) {

     if(!arg) {
        set_light(1);
        short_desc = "A passage";
        long_desc =
"You are standing in a passageway that is part of the entrance to the castle.\n"
+
"To the north is a courtyard, and to the south is a gate.  You hear birds\n"+
"singing in the courtyard, but it is not as pleasent sounding as it should\n"+
"be.\n";

     dest_dir = ({
     "players/blue/castle/courtyard" , "north",
     });
    }
}

lift_gate(str) {
     if(str != "gate") { write("lift what?\n"); return 1;}
     if (this_player()->query_level() < 13) {
     write("You are not strong enough.\n");
     return 1;}
     write("You lift the gate and quickly walk under it. It crashes down"+
       " behind you.\n");
   this_player()->move_player("gate#players/blue/castle/entry1");
     return 1;}
