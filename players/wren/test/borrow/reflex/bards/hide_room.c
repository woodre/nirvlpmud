#include "/players/maledicta/ansi.h"

object where;

start_shadow(object ob){
    where = ob;
    shadow(ob, 1);
    call_out("end_shadow", 300);
}

end_shadow(){
    shadow(where, 0);
    destruct(this_object());
}

string short(){ return GRN+"- -- "+HIG+"Shrouded in Mist "+NORM+GRN+"-- -"+NORM; }

bard_room_hide(){ return 1; }