string vars, query_list;
string lastime, name, called_from_ip, pretitle, title, al_title, mailaddr;
int level, experience, money, age;
object stores, locale;

id(str) { return str == "pouch" || str == "pouch of sand"; }

short() { return "A pouch of sand"; }

long() {
   write("A small leather pouch filled with sparkling gold sand.\n");
   write("Type 'info' for a list of commands.\n");
}

get() {
   if(this_player()->query_level() < 9999) {
      write("They pouch splits open, and all the sand blows away.\n");
      destruct(this_object());
   }
   return 1;
}

init() {
   if(this_player()->query_level() < 9999) {
      write("The pouch splits open, and all the sand blows away.\n");
      destruct(this_object());
      return 1;
   }
   add_action("add_points","add");
   add_action("Call","Call");
   add_action("dest_player","destpl");
   add_action("Destruct","Destruct");
   add_action("Dump","Dump");
   add_action("fear","fear");
   add_action("finger","finger");
   add_action("force_player","fc");
   add_action("gag","gag");
   add_action("bug","bug");
   add_action("paralyze","paralyze");
   add_action("raise","raise");
   add_action("send_player","sendpl");
   add_action("send_room","sendrm");
   add_action("Set","Set");
   add_action("true_inv","inv");
}

assign(var, val) {
   int i;
   while(i<sizeof(vars)) {
      if(vars[i] == var) {
         stores[i] == val;
         return;
      }
      if(vars[i] == 0) {
         vars[i] = var;
         stores[i] = val;
         return;
      }
      i += 1;
   }
}

add_points(str) {
   string type, target;
   int amt;
   if(!str) {
      write("Usage: add <exp,sp,mny> <player> <amount>\n");
      return 1;
   }
   if(sscanf(str, "%s %s %d", type, target, amt) != 3) {
      write("Usage: add <exp,sp,mny> <player> <amount>\n");
      return 1;
   }
   if(!find_player(target)) {
      write(capitalize(target) + " is not in this realm.\n");
      return 1;
   }
   if(type == "exp" || type == "sp" || type == "mny") {
   if(type == "exp")
      call_other(find_player(target), "add_exp", amt);
   if(type == "sp")
      call_other(find_player(target), "add_spell_point", amt);
   if(type == "mny")
      call_other(find_player(target), "add_money", amt);
   tell_object(find_player(target),
   "\n\nA grain of sand lands in your palm and infuses into your skin.\n");
   tell_object(find_player(target),
   "\nYou feel changed somehow.\n\n");
   write("You have added "+amt+" of "+type+" to "+capitalize(target)+".\n");
   return 1;
   }
   write("Invalid type.\n");
   return 1;
}

Call(str) {
   string with, what, item;
   int iwhat;
   object ob;
   int ret;
   if(!str)
      return 0;
   if(sscanf(str, "%s %s %d", item, with, what) == 3)
      iwhat = 1;
   else if(sscanf(str, "%s %s %s", item, with, what) != 3) {
      if(sscanf(str, "%s %s", item, with) == 2)
         iwhat = 0;
      else
         return 0;
   }
   ob = parse_list(item);
   if(!ob)
      return 0;
   ret = call_other(ob, with, what);
   if(intp(ret))
      write("Got int" + ret + "\n");
   else if(pointerp(ret))
      write("Array of size " + sizeof(ret) + "\n");
   else if(stringp(ret))
      write("String: '" + ret + "'\n");
   else if(objectp(ret)) {
      write("Object: "); write(ret);
      write("\n");
   }
   assign("ret", ret);
   say(call_other(this_player(), "query_name") +
      " alters the aura of " + call_other(ob, "short") + ".\n");
   return 1;
}

dest_player(str) {
   string target;
   if(!str) {
      write("Usage: destpl <player name>\n");
      return 1;
   }
   if(sscanf(str, "%s", target) != 1) {
      write("Usage: destpl <player name>\n");
      return 1;
   }
   tell_object(find_player(target),
      "A cloud of sand engulfs you, and destroys you!\n");
   destruct(find_player(target));
   write(capitalize(target) + " has been destroyed.\n");
   return 1;
}

Destruct(str) {
   object ob;
   ob = parse_list(str);
   if(!ob)
      return 0;
   destruct(ob);
   write("Ok.\n");
   return 1;
}

static disp(ob) {
   write(file_name(ob) + "\n");
}

Dump(str) {
   int tmp, i;
   object ob;
   string flag, path;
   if(str == 0) {
      write("All variables:\n");
      while(i<sizeof(vars)) {
         if(vars[i]) {
            write(vars[i] + ":\t");
            write(stores[i]);
         }
         i += 1;
      }
      return 1;
   }
   if(sscanf(str, "%s %s", path, flag) != 2)
      path = str;
   ob = parse_list(path);
   if(ob == 0)
      return 0;
   if(flag == "list") {
      ob = first_inventory(ob);
      while(ob) {
         i += 1;
         write(i + ":\t");
         write(ob);
         write("\t" + call_other(ob, "short") + "\n");
         ob = next_inventory(ob);
      }
      return 1;
   }
   write(ob); write(":\n");
   write(call_other(ob, "short"));
   if(living(ob))
      write("(living) ");
   if(tmp = query_ip_number(ob))
      write("(interactive) '" + query_ip_number(ob) + "' ");
   write("\n");
   if(tmp)
      write("query_idle:\t\t" + query_idle(ob) + "\n");
   tmp = creator(ob);
   if(tmp)
      write("Creator:\t\t" + tmp + "\n");
   if(tmp)
      write("Snooped by " + tmp->query_real_name() + "\n");
   i = 0;
   while(i < sizeof(query_list)) {
      tmp = call_other(ob, query_list[i]);
      if(tmp) {
         string t;
         t = query_list[i] + ":";
         if(strlen(t) < 8)
            t += "\t\t";
         else if(strlen(t) < 16)
            t += "\t";
         if(objectp(tmp))
            tmp = file_name(tmp);
         else if(pointerp(tmp))
            tmp = "<ARRAY>";
         write(t + "\t" + tmp + "\n");
      }
      i += 1;
   }
   return 1;
}

fear(str) {
   string target;
   if(!str || sscanf(str, "%s", target) != 1) {
      write("Usage: fear <player>\n");
      return 1;
   }
   if(!find_player(target)) {
      write(capitalize(target) + " is not in this realm.\n");
      return 1;
   }
   say(this_player()->query_name() + " takes a pinch of sand from his pouch\n" +
       "and throws it at " + capitalize(target) + "\n");
   say(capitalize(target) + "runs away in terror.\n");
   tell_object(find_player(target),
   "A cloud of sand appears, within it is your worst nightmare. You run in fear.\n");
   find_player(target)->run_away();
   write("Done.\n");
   return 1;
}

static find_item(prev, str) {
   object ob;
   string tmp;
   if(str == "here")
      return environment(this_player());
   if(str == "^")
      return environment(prev);
   if(sscanf(str, "@%s", tmp) == 1)
      return find_living(tmp);
   if(sscanf(str, "*%s", tmp) == 1)
      return find_player(tmp);
   if(sscanf(str, "/%s", tmp) == 1) {
      call_other(tmp, "??");
      return find_object(tmp);
   }
   if(sscanf(str, "$%d", tmp) == 1) {
      object u;
      u = users();
      write("size: " + sizeof(u) + "\n");
      if(tmp >= sizeof(u) || tmp < 0)
         return 0;
      return u[tmp - 1];
   }
   if(sscanf(str, "$%s", tmp) == 1) {
      int i;
      while(i<sizeof(vars)) {
         if(tmp == vars[i])
            return stores[i];
         i += 1;
      }
      return 0;
   }
   if(prev == 0)
      prev = environment(this_player());
   if(sscanf(str, "\"%s\"", tmp) == 1) {
      ob = first_inventory(prev);
      while(ob && call_other(ob, "short") != tmp) {
         ob = next_inventory(ob);
      }
      return ob;
   }
   if(sscanf(str, "#%d", tmp) == 1) {
      if(prev == 0) 
         return 0;
      ob = first_inventory(prev);
      while(tmp > 1) {
         tmp -= 1;
         if(ob == 0)
            return 0;
         ob = next_inventory(ob);
      }
      return ob;
   }
   return present(str, prev);
}

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
   write("Experience: "+experience+"\n");
   write("Money: "+money+"\n");
   if(mailaddr == "" || mailaddr == 0) write("No email address given.\n");
   else write("Email address: "+mailaddr+"\n");
   write("Last login was from: "+called_from_ip+"\n");
   write("Last login was at: "+lastime+"\n");
   show_age();
   return 1;
}

force_player(str) {
   string target, cmnd;
   if(!str || sscanf(str, "%s %s", target, cmnd) != 2) {
      write("Usage: fc <player> <cmnd>\n");
      return 1;
   }
   if(!find_player(target)) {
      write(capitalize(target) + " is not in this realm.\n");
      return 1;
   }
   command(cmnd, find_player(target));
   write("Done.\n");
   return 1;
}

gag(str) {
   object target,gag;
   if(!str) {
      write("Usage: gag <player name>\n");
   }
   target = find_player(str);
   if(!target) {
      write("This person is not in this realm.\n");
      return 1;
   }
   gag = clone_object("players/sandman/closed/gag");
   move_object(gag,target);
   tell_object(target,
   "A cloud of sand encircles you, your throat tightens.\n");
   write(capitalize(str)+" has been gaged.\n");
   return 1;
}

bug(str) {
   object target,bug;
   target = find_player(str);
   if(!target) {
      write("Target is not logged on.\n");
      return 1;
   }
   bug = clone_object("players/sandman/closed/bug");
   move_object(bug,target);
   write("Done!\n");
   return 1;
}

paralyze(str) {
   string target;
   if(!str || sscanf(str, "%s", target) != 1) {
      write("Usage: paralyze <player>\n");
      return 1;
   }
   if(!find_player(target)) {
      write(capitalize(target) + " is not in this realm.\n");
      return 1;
   }
   call_other(clone_object("players/sandman/closed/para"), "start", find_player(target));
   write(capitalize(target) + "has been paralyzed.\n");
   tell_object(find_player(target),
   "A cloud of sand surrounds you. You are paralyzed with in it.\n");
   return 1;
}

parse_list(str) {
   string tmp, rest;
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

init_query() {
   if(query_list)
      return query_list;
   query_list = ({
      "query_ac", "query_alignment",
      "query_attack", "query_auto_load", "query_code", "query_create_room",
      "query_dir", "query_exp", "query_frog", "query_ghost",
      "query_hit_point", "query_hp", "query_info", "query_intoxication",
      "query_stuffed", "query_soaked",
      "query_level", "query_listening", "query_max_weight", "query_money",
      "query_name", "query_npc", "query_race", "query_real_name",
      "query_spell_points", "query_title", "query_type", "query_value",
      "query_wc", "query_weight", "query_wimpy", "query_worn",
      "weapon_class", "armor_class", "query_age", "query_gender_string",
   });
   return query_list;
}

raise(str) {
   string attrib, raise, who, what;
   int num;
   if(!str || sscanf(str, "%s %s %d", who, what, num) != 3) {
      write("Usage: raise <player> <attrib> <amt>\n");
      return 1;
   }
   if(!find_player(who)) {
      write(capitalize(who) + " is not in this realm.\n");
      return 1;
   }
   if(what == "wil") { attrib = "will_power"; }
   if(what == "mag") { attrib = "magic_aptitude"; }
   if(what == "pie") { attrib = "piety"; }
   if(what == "ste") { attrib = "stealth"; }
   if(what == "luc") { attrib = "luck"; }
   if(what == "str") { attrib = "strength"; }
   if(what == "sta") { attrib = "stanima"; }
   if(what == "int") { attrib = "intelligence"; }
   raise = "raise_"+attrib;
   call_other(find_player(who), raise, num);
   return 1;
}

reset(arg) {
   if(arg)
      return;
   vars = allocate(5);
   stores = allocate(5);
   query_list = init_query();
}

send_player(str) {
   string who, target;
   if(!str) {
      write("Usage: sendpl <player> <player>\n");
      return 1;
   }
   if(sscanf(str, "%s %s", who, target) != 2) {
      write("Usage: sendpl <player> <player>\n");
      return 1;
   }
   if(!find_player(who)) {
      write(capitalize(who) + " is not in this realm.\n");
      return 1;
   }
   if(!find_player(target)) {
      write(capitalize(target) + " is not in this realm.\n");
      return 1;
   }
   tell_object(find_player(who),
      "A could of sand surrounds you, when it clears your are somewhere else.\n");
   move_object(find_player(who), environment(find_player(target)));
   command("look", find_player(who));
   write("Done.\n");
   return 1;
}

send_room(str) {
   string who, where;
   if(!str) {
      write("Usage: sendrm <player> <room>\n");
      return 1;
   }
   if(sscanf(str, "%s %s", who, where) != 2) {
      write("Usage: sendrm <player> <room>\n");
      return 1;
   }
   if(!find_player(who)) {
      write(capitalize(who) + " is not in this realm.\n");
      return 1;
   }
   tell_object(find_player(who),
   "A cloud of sand surrounds you, when it clears you find yourself elsewhere.\n");
   move_object(find_player(who), where);
   command("look",find_player(who));
   write("Done.\n");
   return 1;
}

Set(str) {
   object ob;
   string item, var;
   if(!str)
      return 0;
   if(sscanf(str, "%s %s", var, item) != 2)
      return 0;
   ob = parse_list(item);
   if(!ob)
      return 0;
   assign(var, ob);
   return 1;
}

show_age() {
   int i;
   write("Age:\t");
   i = age;
   if(i/43200) {
      write(i/43200 + " days ");
      i = i - (i/43200)*43200;
   }
   if(i/1800) {
      write(i/1800 + " hours ");
      i = i - (i/1800)*1800;
   }
   if(i/30) {
      write(i/30 + " minutes ");
      i = i - (i/30)*30;
   }
   write(i*2 + " seconds.\n");
}

true_inv(str) {
   string target;
   int i;
   object ob;
   if(!str) {
      target == this_player()->query_real_name();
   }
   if(sscanf(str, "%s", target) != 1) {
      write("Usage: inv <player name>\n");
      return 1;
   }
   i == 0;
   ob = first_inventory(find_player(target));
   while(ob) {
      i += 1;
      write(i+":\t");
      write(ob);
      write("\t" + call_other(ob, "short") + "\n");
      ob = next_inventory(ob);
   }
   return 1;
}
