# 1 "players/rich/quest/trek.c"
# 1 "room/std.h"





























# 72 "room/std.h"


# 123 "room/std.h"



# 182 "room/std.h"

# 246 "room/std.h"

# 317 "room/std.h"

# 388 "room/std.h"
# 1 "players/rich/quest/trek.c"





 







extra_reset(){
    object trekkie;
    if(!present("trekkie")) {

        object money;
       trekkie = clone_object("obj/monster");
       call_other(trekkie, "set_id","trekkie");
       call_other(trekkie, "set_name", "trekkie");
       call_other(trekkie, "set_alt_name","trekkie");
       call_other(trekkie, "set_short", "a new generation trekkie");
       call_other(trekkie, "set_ac", 1);
       call_other(trekkie, "set_long", "a new generation trekkie\n");
       call_other(trekkie, "set_level", 3);
       call_other(trekkie, "set_al",100);
       call_other(trekkie, "set_hp",75);
       call_other(trekkie, "set_wc",5);
       call_other(trekkie, "set_aggressive",1);
       move_object(trekkie, this_object());
       money = clone_object("obj/money");
       call_other(money, "set_money",50);
       move_object(money,trekkie);
    }
}



 






reset(arg) { extra_reset();  if (arg) return; set_light(1); }short() { if (set_light(0)) return 
   "a room"; return "It is too dark to see here"; }init() { add_action("move1"); add_verb( "east"); add_action("move2"); add_verb( "north");   }move1() {   call_other(this_player(), "move_player",  "east"+"#"+"players/rich/quest/room.c"); return 1; }move2() {   call_other(this_player(), "move_player",  "north"+"#"+
         "players/rich/quest/room.c"); return 1; }long(str) { if (set_light(0) == 0){ write("It really is dark you know.\n"); return; }   write(
            "This is a room.\n"); write("There are two obvious exits:\n "+ "east"+" and "+ "north"+".\n"); } 
