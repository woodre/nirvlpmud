
/*
 * FAMILIAR STONE (3/25/94)
 * Device for controlling familiars. (obj/familiar.c)
 */

#define MAX_LIST 15

string owner, fam_name, cap_fam_name;

reset(arg) {
   if(arg) 
     return;
}

id(str) { return str == "familiar stone" || str == "stone"; }

query_value() { return 100; }

short() { return "A familiar stone"; }

long() {
   write("A small black stone.\n");
   write("This is a familiar stone for controlling your familiar.\n"+
         "Type 'fc' for a list of possible commands.\n");
}

get() { return 1; }

set_fam_name(fn) { fam_name = fn; }
set_owner(o) { owner = o; }

init() {
   add_action("summon","summon");
   add_action("fam_cmds","fc");
}

summon(str) {
   if(!str)
     return;
   if(str == "familiar") {
     if(fam_name && find_living(fam_name)) {
       write("There is already a familiar in existence for this device.\n");
       return 1;
     }
     write("What name would you like to give your familiar? ");
     input_to("get_familiar");
     return 1;
   }
}

get_familiar(str) {
   object familiar;
   string fam_name, name, fam_short;
   int fam_lvl;

   if(!str || str == "") {
     write("You cannot use that name!\n");
     write("Give name again: ");
     input_to("get_familiar");
     return 1;
   }
   if(restore_object("players/"+str)) {
     write("You cannot use existing player names.\n");
     write("Give name again: ");
     input_to("get_familiar");
     return 1;
   }
   if(find_living(str)) {
     write("There is already a monster using that name.\n");
     write("Give name again: ");
     input_to("get_familiar");
     return 1;
   }
   name = this_player()->query_real_name();
   fam_name = str;
   fam_short = capitalize(fam_name)+", a small grey wombat";
   fam_lvl = this_player()->query_level()/2;
   if(fam_lvl < 1) fam_lvl = 1;
   familiar = clone_object("players/molasar/rowan/magic/obj/familiar");
   familiar->set_name(fam_name);
   familiar->set_owner(name);
   familiar->set_tmp_short(fam_short);
   familiar->set_level(fam_lvl);
   transfer(familiar, environment(this_player()));
   this_object()->set_owner(name);
   this_object()->set_fam_name(fam_name);
   return 1;
}

fam_cmds(str) {
   string short_str, it, who, msg, item, extra_str, emote;
   object fam, dest, new_dest, ob, ob_tmp, special;
   int max;

   if(!str) {
     cat("/players/molasar/rowan/magic/obj/FAM_HELP");
     return 1;
   }
   if(!fam_name) {
     write("You must summon a familiar before you can command it.\n");
     return 1;
   }
   if(this_player()->query_real_name() != owner) return 0;
   fam = find_living(fam_name);
   cap_fam_name = capitalize(fam_name);
   if(str && !fam) {
     write("Could not find "+cap_fam_name+".\n");
     return 1;
   }
   dest = environment(fam);
   if(str == "dismiss") {
     destruct(fam);
     write("You dismiss your familiar.\n");
     return 1;
   }
   if(sscanf(str, ":%s", emote) == 1) {
     tell_room(dest, cap_fam_name+" "+emote+"\n");
     write("Your familiar emotes: "+emote+"\n");
     return 1;
   }
   if(str == "look" || str == "l") {
     write("%");
     dest->long();
     ob = first_inventory(dest);
     max = MAX_LIST;
     while(ob && max > 0) {
       if(ob != fam) {
         short_str = call_other(ob, "short", 0);
         if(short_str) {
           max -= 1;
           write("%"+short_str+".\n");
           it = short_str;
         }
       }
       ob = next_inventory(ob);
     }
     return 1;
   }
   if(sscanf(str,"look at %s",item) == 1 || sscanf(str,"l at %s",item) == 1 ||
      sscanf(str,"look in %s",item) == 1 || sscanf(str,"l in %s",item) == 1) {
     item = lower_case(item);
     ob = present(item, fam);
     if(!ob && call_other(dest, "id", item))
       ob = dest;
     if(!ob) 
       ob = present(item, dest);
     if(!ob) {
       write("There is no "+item+" here.\n");
       return 1;
     }
     it = item;
     write("%");
     call_other(ob, "long", item);
     if(!call_other(ob, "can_put_and_get", item))
       return 1;
     if(living(ob)) {
       special = first_inventory(ob);
       while(special) {
         extra_str = call_other(special, "extra_look");
         if(extra_str)
           write("%"+extra_str+".\n");
         special = next_inventory(special);
       }
     }
     ob_tmp = first_inventory(ob);
     while(ob_tmp && call_other(ob_tmp, "short") == 0)
       ob_tmp = next_inventory(ob_tmp);
     if(ob_tmp) {
       if(living(ob)) {
         write("\t%"+capitalize(item)+" is carrying:\n");
       } else
         write("\t%"+capitalize(item)+" contains:\n");
     }
     max = MAX_LIST;
     ob = first_inventory(ob);
     while(ob && max > 0) {
       short_str = call_other(ob, "short", 0);
       if(short_str)
         write("%"+short_str+".\n");
       ob = next_inventory(ob);
       max -= 1;
     }
     return 1;
   }
   if(str == "north" || str == "n" || str == "south" || str == "s" ||
      str == "east" || str == "e" || str == "west" || str == "w" ||
      str == "northeast" || str == "ne" || str == "northwest" || str == "nw" ||
      str == "southeast" || str == "se" || str == "southwest" || str == "sw" ||
      str == "up" || str == "u" || str == "down" || str == "d") {
     command(str, fam);
     new_dest = environment(fam);
     short_str = new_dest->short();
     write("%"+short_str+".\n");
     ob = first_inventory(new_dest);
     max = MAX_LIST;
     while(ob && max > 0) {
       if(ob != fam) {
         short_str = ob->short();
         if(short_str) {
           max -= 1;
           write("%"+short_str+".\n");
           it = short_str;
         }
       }
       ob = next_inventory(ob);
     }
     return 1;
   }
   if(sscanf(str, "tell %s %s", who, msg)) {
     if(!find_player(who) || find_player(who)->query_invis() > 0) {
       write("Could not find "+capitalize(who)+".\n");
       return 1;
     }
     tell_object(find_player(who), cap_fam_name+" tells you: "+msg+"\n");
     write("Your familiar tells "+capitalize(who)+": "+msg+"\n");
     return 1;
   }
   if(sscanf(str, "say %s", msg) || sscanf(str, "' %s", msg)) {
     tell_room(dest, cap_fam_name+" says: "+msg+"\n");
     return 1;
   }
   if(sscanf(str, "get %s", item)) {
     ob = present(item, dest);
     if(!ob) {
       write("That is not here!\n");
       return 1;
     }
     if(call_other(ob, "get", 0) == 0) {
       write("You cannot take that!\n");
       return 1;
     }
     transfer(ob, fam);
     tell_room(dest, cap_fam_name+" takes "+item+".\n");
     return 1;
   }
   if(sscanf(str, "drop %s", item)) {
     ob = present(lower_case(item), fam);
     if(!ob) {
       write("You do not have a "+item+"!\n");
       return 1;
     }
     if(call_other(ob, "drop", 0) == 1) {
       write("You cannot drop that!\n");
       return 1;
     }
     transfer(ob, dest);
     tell_room(dest, cap_fam_name+" drops a "+item+".\n");
     return 1;
   }
}


