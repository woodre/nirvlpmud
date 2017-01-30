#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object klingon;
    if(!present("klingon")) {

        object dagger,w_hit_dag;
       klingon = clone_object("obj/monster");
       call_other(klingon, "set_id","klingon");
       call_other(klingon, "set_name", "klingon");
       call_other(klingon, "set_alt_name","klingon");
       call_other(klingon, "set_short", "a klingon is here");
       call_other(klingon, "set_ac", 1);
       call_other(klingon, "set_long", "a klingon of the lower ranks\n");
       call_other(klingon, "set_level", 3);
       call_other(klingon, "set_al",-100);
       call_other(klingon, "set_hp",75);
       call_other(klingon, "set_wc",7);
       call_other(klingon, "set_aggressive",1);
       call_other(klingon, "set_chat_chance",30);
       call_other(klingon, "load_chat","Klingon says: Die!!!You lowly human scum!!!!\n");
       move_object(klingon, this_object());
       dagger = clone_object("obj/weapon");
       w_hit_dag=clone_object("players/rich/w_hit_dag.c");
           call_other(dagger,"set_name","klingon dagger");
           call_other(dagger,"set_class",8);
           call_other(dagger,"set_weight",1);
           call_other(dagger,"set_value",30);
           call_other(dagger,"set_alt_name","nasty");
           call_other(dagger,"set_alias","dagger");
           call_other(dagger,"set_short","a klingon dagger");
         call_other(dagger,"set_long","A three pronged klingon dagger.\n");
         call_other(dagger,"set_hit_func",w_hit_dag);
       move_object(dagger,klingon);
    }
}



/*



*/


ONE_EXIT("players/rich/hall3u.c", "west",
   "Visitor`s Quarters",
            "This is the visitor`s quarters.To the east is a hallway.\n",1)
realm(){return "enterprise";}
