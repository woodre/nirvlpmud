
/*  10/08/06 - Rumplemintz: removed trailing ; in #include  */
/*  NOT FOR PLAYERS, THIS IS AN NPC ITEM */

inherit "/obj/armor";
#include "/players/jaraxle/define.h"

void
reset(status arg)
{
   if(arg) return;
   ::reset();
   call_out("kill_it",9);
   set_name("fairy bubble");
   set_id("fairy_bubble");
   set_short(HIC+"Aq"+HIW+"u"+HIB+"a B"+HIC+"ubB"+HIW+"l"+HIC+"E"+NORM);
   set_type("armor");
   set_weight(0);
   set_long("blech\n");
   set_ac(0); /* physical ac */
   set_res(25);
   set_value(0);
}

do_special(owner){
   tell_object(owner, "The bubble reflects some of the blow!\n");
   if(this_player() && this_player()!=owner)
      write(owner->query_name()+"'s bubble vibrates, reflecting your attack!\n");
   return 50;
}
drop(){ destruct(this_object()); return 1; }
get(){ destruct(this_object()); return 1; }
kill_it(){
   ::drop();
   destruct(this_object());
   return 1; }
