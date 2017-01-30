#include "std.h"




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_reset(){
    object q;
    if(!present("q")) {

        object money;
       q = clone_object("obj/monster");
       call_other(q, "set_id","q");
	call_other(q,"set_name","Q, the omnipotent one");
       call_other(q, "set_alt_name","q");
       call_other(q, "set_short", "Q the omnipotent one");
	call_other(q,"set_long","Q, the omnipotent one.\n");
       call_other(q, "set_ac", 16);
       call_other(q,"set_wc",25);
       call_other(q, "set_level", 20);
       call_other(q, "set_al",-100);
       call_other(q, "set_hp",750);
       call_other(q, "set_chance",80);
       call_other(q, "set_spell_mess2","Q waves his hand and hits you with a fireball\n");
       call_other(q, "set_spell_dam",30);
       call_other(q, "set_aggressive",0);
       call_other(q, "set_chat_chance",40);
       call_other(q, "load_chat","Q says: pathetic human scum.\n");
       call_other(q, "load_chat","Q says: you`re lower than denebian slime\n");
move_object(q,this_object());
       call_other(q, "load_chat","Q says: civilized hah!!!\n");
       money = clone_object("obj/money");
       call_other(money, "set_money",(3000+random(1000)));
       move_object(money,q);
    }
}



/*



*/


ONE_EXIT("players/rich/hall5.c", "west",
	   "a room",
  "This is another of the non-descript rooms of\n"+
  "the Enterprize.  To the east is a hole through\n"+
  "the bulkhead that leads to another room.\n",
           1)
realm(){return "enterprise";}

extra_init() {
  add_action("east","east");
}

east() {
if(present("q")) {
  write("Q steps between you and the opening.\n"); return 1; }
else {
  this_player()->move_player("east#players/rich/lower/guard.c");
  return 1; }
}
