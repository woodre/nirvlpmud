/*
Level 3 Control Spell: Graft - Will allow the symb to
graft pieces of armor to their body, giving them the
ac, but not the specials. ungrafting will destroy
the armor. Cost: 30 mp
*/

#include "/players/chip/venom2/sdefine.h"

main(string str, object gob, object player)
{
	object ob;
	if(USER->query_ghost()) return 0;
	if(CON < 3) return 0;
	if(!str){ tell_object(USER, "graft <armor>\n"); return 1; }
	ob = present(str, USER);
   if(!ob){ tell_object(USER, "You do not see that.\n"); return 1; }
	if(!ob->armor_class()){
     tell_object(USER, "You do not believe it would do any good to graft that.\n");
     return 1;
     }
   if(!ob->is_armor()){ tell_object(USER, "That is not something you can graft!\n"); return 1; }
   if(GOB->query_mp() < 30){
     tell_object(USER, "You lack the matter to graft.\n");
     return 1;
     }
   if(GOB->check_armors(ob->query_type())){
     tell_object(USER, "You already have "+ob->query_type()+" type armor worn!\n");
     return 1;
     }
	tell_object(USER,
	"You concentrate and extend "+HIK+"Dark Matter"+NORM+" tentacles out toward the\n"+
   ob->short()+". They burrow into the piece of armor and extend\n"+
   "throughout its internal structure. The armor is pulled to your\n"+
   "body and grafted to your skin.\n");
   tell_room(environment(USER),
	USER->query_name()+" grafts "+ob->short()+" to "+UP+" skin.\n", ({ USER }));
   GOB->add_mp(-30);
   GOB->add_gr_armors(ob->query_type(), ob->short(), ob->armor_class());
   destruct(ob);
	return 1;
}

