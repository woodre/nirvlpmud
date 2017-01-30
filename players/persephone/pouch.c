id(str) { return str == "pouch"; }

short() {
   return "Pouch of Sand";
}

long() {
   write("A small leather pouch filled with sparkling sand.\n");
}

get() {
   if(this_player()->query_real_name() != "sandman") {
      write("The pouch is too heavy for you to lift.\n");
      return 0;
   }
   return 1;
}

init() {
   add_action("give_exp","exp");
   add_action("give_sp","sp");
   add_action("new_title","settitle");
   add_action("trans_room","sendpl");
   add_action("trans_person","sendto");
   add_action("true_inv","inv");
   add_action("give_money","mny");
   add_action("finger","finger");
   add_action("Destruct","Destruct");
}

give_exp(str) {
   string who;
   int amt;
   if(!str || sscanf(str, "%s %d", who, amt) != 2) {
      write("Usage: exp <player name> <amt exp>\n");
      return 1;
   }
   if(!find_player(who)) {
      write(capitalize(who)+" is not in this dimension now.\n");
      return 1;
   }
   find_player(who)->add_exp(amt);
   write("You give "+capitalize(who)+" "+amt+" experience points.\n");
   tell_object(find_player(who), "Sandman has given you "+amt+" experience pts.\n");
   return 1;
}

give_sp(str) {
   string who;
   int amt;
   if(!str || sscanf(str, "%s %d", who, amt) != 2) {
      write("Usage: sp <player name> <amount sp>\n");
      return 1;
   }
   if(!find_player(who)) {
      write(capitalize(who)+" is not in this dimension now.\n");
      return 1;
   }
   call_other(find_player(who), "add_spell_point", amt);
   write("You give "+capitalize(who)+" "+amt+" spell points.\n");
   tell_object(find_player(who), "Sandman gives you "+amt+" spell points.\n");
   return 1;
}

new_title(str) {
   string who,strgn;
   if(!str || sscanf(str, "%s %s", who, strgn) != 2) {
      write("Usage: settitle <player name> <title string>\n");
      return 1;
   }
   if(!find_player(who)) {
      write(capitalize(who)+" is not in this dimension now.\n");
      return 1;
   }
   call_other(find_player(who), "set_title", strgn);
   write("You change "+capitalize(who)+"'s title to '"+strgn+"'\n");
   return 1;
}

trans_room(str) {
   string who,destin;
   if(!str || sscanf(str, "%s %s", who, destin) != 2) {
      write("Usage: sendpl <player name> <room path>\n");
      return 1;
   }
   if(!find_player(who)) {
      (capitalize(who)+" is not in this dimension now.\n");
      return 1;
   }
   move_object(find_player(who), destin);
   write("You pull out a pinch of sand, and sprinkle it into the air.\n");
   tell_object(find_player(who), "A cloud of sand surrounds you, when it clears you find yourself elsewhere.\n\n");
   command("look", find_player(who));
   return 1;
}

trans_person(str) {
   string who,target;
   if(!str || sscanf(str, "%s %s", who, target) != 2) {
      write("Usage: sendto <name of player> <name of target>\n");
      return 1;
   }
   if(!find_player(who)) {
      write(capitalize(who)+" is not in this dimension.\n");
      return 1;
   }
   if(!find_player(target)) {
      write(capitalize(target)+" is not in this dimension.\n");
      return 1;
   }
   move_object(find_player(who), environment(find_player(target)));
   write("You take out a pinch of sand and sprinkle it into the air.\n");
   tell_object(find_player(who), "A cloud of sand surrounds you, when it clears you find yourself elsewhere.\n\n");
   command("look", find_player(who));
   return 1;
}

true_inv(str) {
   string who;
   int i;
   object ob;
   if(!str || sscanf(str, "%s", who) != 1) {
      write("Usage: inv <player name>\n");
      return 1;
   }
   if(!find_player(who)) {
      write(capitalize(who)+" is not in this dimension now.\n");
      return 1;
   }
   i == 0;
   ob = first_inventory(find_player(who));
   while(ob) {
      i += 1;
      write(i+":\t");
      write(ob);
      write("\t"+call_other(ob,"short")+"\n");
      ob = next_inventory(ob);
   }
   return 1;
}

give_money(str) {
   string who;
   int amt;
   if(!str || sscanf(str, "%s %d", who, amt) != 2) {
      write("Usage: mny <player name> <amount coins>\n");
      return 1;
   }
   if(!find_player(who)) {
      write(capitalize(who)+" is not in this dimension now.\n");
      return 1;
   }
   call_other(find_player(who), "add_money", amt);
   write("You take a pinch of sand from the pouch and sprinkle it in the air.\n");
   tell_object(find_player(who), "Sandman gives you "+amt+" gold coins.\n");
   return 1;
}
string lastime, name, called_from_ip, pretitle, title, al_title, mailaddr;
int level, experience, money, age;

finger(str) {
   int days, hours, minutes, seconds;
   mailaddr = 0; name = 0; title = 0; level = 0; al_title = 0; age = 0;
   pretitle = 0; money = 0; experience = 0; lastime = 0; called_from_ip = 0;
   if(!str) {
      write("Usage: finger <player name>\n");
      return 1;
   }
   restore_object("players/"+str);
   if(!name) {
      write("That player does not exist.\n");
      return 1;
   }
   write(pretitle+" "+capitalize(name)+" "+title+" ("+al_title+")\n");
   write("Level: "+level+"\n");
   write("Money: "+money+"\n");
   if (mailaddr == "" || mailaddr == 0) write("No Email address given.\n");
   else write("Mail Address: "+mailaddr+"\n");
   write("Last called from: "+called_from_ip+"\n");
   write("Last on: "+lastime+"\n");
   show_age();
   return 1;
}

show_age() {
   int i;
   write("Age:\t");
   i = age;
   if(i/43200) {
      write(i/43200+" days ");
      i = i - (i/43200)*43200;
   }
   if(i/1800) {
      write(i/1800+" hours ");
      i = i - (i/1800)*1800;
   }
   if(i/30) {
      write(i/30+" minutes ");
      i = i - (i/30)*30;
   }
   write(i*2+" seconds.\n");
}

Destruct(str) {
   object ob;
   if(!str) {
      write("Usage: Destruct <item path>\n");
      return 1;
   }
   ob = parse_list(str);
   if(!ob)
      return 0;
   destruct(ob);
   write("Ok.\n");
   return 1;
}

parse_list(str) {
   string tmp,rest;
   object prev;
   prev = environment(this_player());
   while(prev && str) {
      if(sscanf(str, "%s:%s", tmp, rest) == 2) {
         prev = find_item(prev, tmp);
         str = rest;
         continue;
      }
      prev = find_item(prev, str);
      break;
   }
   assign("$", prev);
   if(objectp(prev))
      disp(prev);
   return prev;
}

static disp(ob) {
   write(file_name(ob)+"\n");
}

assign(var, val) {
   int i;
   while(i<sizeof(vars)) {
      if(vars[i] == var) {
         stores[i] = val;
         return;
      }
      if(vars[i] == 0) {
         vars[i] = var;
         return;
      }
      i += 1;
   }
}
