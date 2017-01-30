/* Based on Hurtbrain's old Traveller Pigeon.  Thanks Hurtbrain for allowing him to use his code as a solid
   template to use for this object.  Mythos' changes were left in for legality reasons.
 - Snakespear <8-15-98>
  I have added a check in the tie command to check vs if dropable, if gettable, if no weight and if auto_load...
  alos for the fly to command i have made it so the pigeon can not send to wizes
 - Mythos <2-26-96>
*/
#define MAX_WEIGTH     11 
int local_weight;

long() {
   object tied;
   write("-= A small gargoyle =-\n"+
   "You can do the follow commands:\n"+
   "tie <object> to paw\n"+
   "untie <object> from paw\n"+
   "untie all from paw\n"+
   "fly to <player>\n\n");

/* if (first_inventory(this_object()))   {
     write("It has something tied to it's paw.\n");
     tied=first_inventory(this_object());
     while(tied)   {
	write(call_other(tied,"short")+".\n");
	tied=next_inventory(tied);
	}
    }
    else
        write("You can tie something to its paw.\n"); */
}

reset(arg) {
    if (arg)
        return;
    local_weight = 0;
}

init() {
    add_action("tie","tie");
    add_action("untie","untie");
    add_action("send","fly");
}

tie(str)   {
string what;
object tied;
if(!str || !(sscanf(str,"%s to paw",what)))   {
	notify_fail("Usage: tie <object> to paw.\n");	
	return 0;
	}
tied=present(what,this_player());
if(!tied)  {
	notify_fail("What do you want to tie?\n");
	return 0;
	}
  if(tied->query_auto_load() || tied->query_weight() == 0 || !(tied->get()) || tied->drop()) {
    write("You can not tie that.\n");
    return 1;
    }
  if ((call_other(tied,"query_weight")+local_weight) > MAX_WEIGTH)  {
    notify_fail("The gargoyle is carrying too much!\n");
    return 0;
    }
   local_weight += call_other(tied,"query_weight");
   write("You tied "+what+" to the gargoyle's paw.\n");
   say(this_player()->query_name()+" tied something to the paw of "+this_player()->query_possessive()+" gargoyle.\n");
   move_object(tied,this_object());
   return 1;
   }


untie(str)   {
 string what;
 object untied;
 if(!str || !(sscanf(str,"%s from paw",what)))   {
   notify_fail("Usage: untie <object> from paw.\n");
   return 0;
   }
if(what == "all")   {
   untied=first_inventory(this_object());
   while(untied)    {
        write("You untied a "+call_other(untied,"query_name")+" from a gargoyle's paw.\n");
	say(this_player()->query_name()+" untied the "+call_other(untied,"query_name")+" from the gargoyle's paw.\n");
	move_object(untied,this_player());
	untied=first_inventory(this_object());
	}
   local_weight=0;
   return 1;
   }
untied=present(what,this_object());
if(!untied)   {
   notify_fail("What do you want to untie?\n");
   return 0;
   }
local_weight -=call_other(untied,"query_weight");
   write("You untied a "+what+" from the gargoyle's paw.\n");
   say(this_player()->query_name()+" untied something from the gargoyle's paw.\n");
   move_object(untied,this_player());
   return 1;
   }


send(str)   {
string who;
object flyed;

if(!str || !(sscanf(str,"gargoyle to %s",who)))  {
   notify_fail("Usage: fly gargoyle to <player>\n");
   return 0;
   }
flyed=find_player(who);
if(!flyed)  {
   notify_fail("A small gargoyle grunts: I can't locate "+who+" on the MUD.\n");
   return 0;
   }
if(flyed->query_invis()) {
   notify_fail("A small gargoyle whispers: I can't find "+who+" on the MUD.\n"); 
   return 0;
   }
if(environment(flyed)->realm() == "NT") {
   write("You cannot fly the gargoyle there.\n");
   return 1;
   }
if(environment(this_player())->realm() == "NT") {
   write("The gargoyle can't fly out of here.\n");
   return 1;
   }
if(flyed->query_level() > 19) {
   write("A small gargoyle whispers: No way! I won't fly to a wizard.\n");
   return 1;
   }
write("A small gargoyle spreads his wings and heads off towards "+flyed->query_name()+".\n");
tell_object(flyed,"A small gargoyle lands on your shoulder and tucks its small wings onto it's back.\n"+
                  "The small gargoyle says: "+this_player()->query_name()+" sent me.\n");
move_object(this_object(),flyed);
return 1;
}

query_weight() {
    return 3;
}

short() {
    return "A small gargoyle";
}

id(str) {
    return str == "gargoyle";
}

query_value() {
    return 200;
}

get() {
    return 1;
}

prevent_insert() {
    if (local_weight > 0) {
        write("Gargoyle whispers to you: I can't carry it with stuff inside the bag.\n");
        return 1;
    }
    return 0;
}
