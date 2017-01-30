#define MMSGOUT "fades from view"
#define MMSGIN "fades into view"
#define PREFIX ">> "
#define MASTER_R "mizan"
 
object owner;
object pet;
static object it;
static int power_tl;
int brief_tl;
 
id(str) { return str == "playersoul"; }
 
long() {
  write("It is transparent.\n");
}
 
query_real_name() { return "MASTER_R"; }
query_version() { return "Version 1.1"; }
 
get() { return 1; }
drop() { return 1; }
 
reset() {
  owner=find_player(MASTER_R);
  if(!owner) {
    write("This does not belong to you.\n");
    destruct(this_object());
    return 1;
  }
  pet=find_living("summerhead");
  if(!pet) {
    write("Error... Summerhead not located.\n");
    move_object(this_object(), pet);
    destruct(this_object());
    return 1;
  }
}
 
init() {
  add_action("kill","kill");
  add_action("teleport","goto");
  add_action("communicate","say");
  add_action("emote","emote");
  add_action("look","look");
  add_action("look","l");
  add_action("put_object","put");
  add_action("give_object","give");
  add_action("get_object","get");
  add_action("inventory","i");
  add_action("drop_object","drop");
  add_action("pick_object","take");
  add_action("tell","tell");
  add_action("score","sc");
  add_action("score","score");
  add_action("command_prompt","q");
  add_action("brief_tl","bf");
}
 
spooga(str) {
  string test1, test2;
  string test3,test4;
  sscanf(str, "%s#%s", test1, test2);
  test3=test1 + ".c";
  test2 = file_size(test3);
  return test2;
}
 
/* Called on by object. */
 
tell_owner(str) {
  if(!str || !owner || !interactive(owner)) return 0;
  tell_object(owner, "[SR]" + str);
  return 1;
}
 
sum_echo(str) {
  tell_room(environment(pet), str);
  return 1;
}
 
find_it(str) {
  object oc;
  oc=find_player(str);
  if(!oc) {
    oc=find_living(str);
    if(!oc) {
      oc=find_object(str);
      if(!oc) return 0;
    }
  }
  return oc;
}
 
find_local(str) {
  object oc;
  oc=present(str, pet);
  if(!oc) {
    oc=present(str, environment(pet));
    if(!oc) return 0;
  }
  return oc;
}
 
brief_tl() {
  if(!brief_tl) {
    brief_tl=1;
    tell_owner(" Brief mode.\n");
  } else {
  brief_tl=0;
  tell_owner(" Verbose mode.\n");
  }
  return 1;
}
 
score() {
  object room;
  room=environment(pet);
  write((pet->short()) + "\n\n");
  write("[" + (pet->query_mhp()) + " / " + (pet->query_hp()) + "]HP\n");
  write("[" + (pet->query_money()) + "]AU\n");
  write("[" + object_name(room) + ", " + spooga(object_name(room)) + " bytes] CR\n");
  return 1;
}
 
command_prompt() {
  object ob;
  int v,l_wz,eld_wz,g_wz;
  ob=users();
  for(v=0; v<sizeof(ob); v++) {
    int oc;
    if(ob[v]->query_level() > 9999) {
      g_wz = g_wz + 1;
      } else if(ob[v]->query_level() > 59) {
        eld_wz = eld_wz + 1;
        } else if(ob[v]->query_level() > 19) {
          l_wz = l_wz + 1;
        }
  }
  write("[" + object_name(environment(pet)) + ", " + spooga(object_name(environment(pet))) + "B] [" + sizeof(ob) + "]UT");
  if(l_wz) write(" [" + l_wz + "]wz");
  if(eld_wz) write(" [" + eld_wz + "]ew");
  if(g_wz) write(" [" + g_wz + "]gw");
  write(">>");
  return 1;
}
 
inventory() {
   if(brief_tl) {
     list_basic();
   } else {
     list_complex();
   }
  return 1;
}
 
list_basic(str) {
  object ob,ob2;
  if(!str) {
   ob=first_inventory(pet);
   write(PREFIX + "You are currently carrying:\n");
  }
  if(str) {
    if(str == "ROOM") {
      call_other(environment(pet), "long");
      ob=environment(pet);
    } else {
      ob=find_local(str);
      if(!ob) {
        ob=find_it(str);
        if(!ob) {
          write(PREFIX + "No '" + str + "' found.\n");
          return 1;
        }
      }
    }
    if(str == "ROOM") {
      write(PREFIX+ "Room [" + object_name(ob) + "] contains:\n");
    } else {
      if(ob->short()) {
        write(PREFIX+ "'" + (ob->short()) + "' contains:\n");
      } else {
        write(PREFIX+ "[" + object_name(ob) + "] contains:\n");
      }
    }
  }
  ob2=first_inventory(ob);
  while(ob2) {
    object oc;
    oc=ob2;
    ob2=next_inventory(ob2);
    if(living(oc)) {
      if(oc->query_npc()) {
        write((oc->short()) + ". [NPC] [" + creator(oc) +
        "]Cr [" + (oc->query_wc()) + "]wc [" +
        (oc->query_ac()) + "]ac [" +
        (oc->query_level()) + "]lvl" +
        "\n");
        }
        if(oc->query_npc() == 1) {
          if(!oc->short()) {
            write("[IV] ");
          }
          write(capitalize(oc->query_real_name()) + ". [PLYR!]\n"+
          "    [" + (oc->query_wc()) + "]wc [" +
          (oc->query_ac()) + "]ac [" +
          (oc->query_level()) + "]lvl [" +
          (oc->query_money()) + "]$ [" +
          (oc->query_guild_name()) + "]gn" +
          "\n");
        }
      } else {
      write((oc->short()) + ". [" + creator(oc) + "]Cr [" +
      (oc->query_weight()) + "]kg [" +
      (oc->query_value()) + "]$" +
      "\n");
    }
  }
  return 1;
}
 
list_complex(str) {
  object ob,ob2;
  if(!str) {
   ob=first_inventory(pet);
   write(PREFIX + "You are currently carrying:\n");
  }
  if(str) {
    if(str == "ROOM") {
      call_other(environment(pet), "long");
      ob=environment(pet);
    } else {
      ob=find_local(str);
      if(!ob) {
        ob=find_it(str);
        if(!ob) {
          write(PREFIX + "No '" + str + "' found.\n");
          return 1;
        }
      }
    }
    if(str == "ROOM") {
      write(PREFIX+ "Room [" + object_name(ob) + "] contains:\n");
    } else {
      if(ob->short()) {
        write(PREFIX+ "'" + (ob->short()) + "' contains:\n");
      } else {
        write(PREFIX+ "[" + object_name(ob) + "] contains:\n");
      }
    }
  }
  ob2=first_inventory(ob);
  while(ob2) {
    object oc;
    oc=ob2;
    ob2=next_inventory(ob2);
    if(living(oc)) {
      if(oc->query_npc()) {
        write((oc->short()) + ". [LIVING!] Creator: " + creator(oc) + "\n" +
        "  Filename: [" + object_name(oc) + "] [" + (oc->query_wc()) + "]wc [" +
        (oc->query_ac()) + "]ac [" +
        (oc->query_level()) + "]lvl" +
        "\n");
        }
        if(oc->query_npc() != 1) {
          write(capitalize(oc->query_name()) + ". [LIVING!]\n"+
          "    [" + (oc->query_wc()) + "]wc [" +
          (oc->query_ac()) + "]ac [" +
          (oc->query_level()) + "]lvl [" +
          (oc->query_money()) + "]$ [" +
          (oc->query_guild_name()) + "]gn" + " [" +
          (oc->query_guild_rank()) + "]gr" +
          "\n" + "  [" +
          (oc->query_experience()) + "]EXP [" +
          (oc->query_idle()) + "]I [" +
          (query_ip_name(oc)) + ": " +
          (query_ip_number(oc)) + "]IP" +
          "\n");
        }
      } else {
      write((oc->short()) + ". Creator: " + creator(oc) + "\n" +
      "    Filename: [" + object_name(oc) + ", " + spooga(object_name(oc)) + " bytes]\n" +
      "  [" +
      (oc->query_weight()) + "]kg [" +
      (oc->query_value()) + "]$" +
      " [" + (oc->query_save_flag()) + "]SF [" + (oc->query_auto_load()) + "]AL " +
      "\n");
    }
  }
  return 1;
}
 
teleport(str) {
  object ob;
  string tempr;
  if(!str) {
    write(PREFIX + "Goto where ?\n");
    return 1;
  }
  tempr = str;
  ob = find_player(str);
  if(!ob) {
    ob = find_living(str);
  }
  if(ob) {
    ob = environment(ob);
    if(!pet->query_invis()) {
      sum_echo((pet->query_name()) + " " + MMSGOUT + ".\n");
    }
    move_object(pet, ob);
    if(!pet->query_invis()) {
      sum_echo((pet->query_name()) + " " + MMSGIN + ".\n");
    }
    call_other(ob, "long", 0);
    ob = first_inventory(ob);
        while(ob) {
        if (ob != this_object()) {
        string short_str;
        short_str = call_other(ob, "short");
        if (short_str)
        write(PREFIX + short_str + ".\n");
      }
    ob = next_inventory(ob);
    }
  return 1;
  } else {
  pet->move_player("X#" + str);
  return 1;
  }
}
 
kill(str) {
  object ob;
  if (!str) {
    write(PREFIX + "Kill what?\n");
    return 1;
  }
  ob = present(lower_case(str), environment(pet));
  if (!ob) {
  write(PREFIX + "No " + str + " here!\n");
  return 1;
  }
  if(!living(ob)) {
    write(PREFIX + " " + str + " is not a living thing !\n");
    return 1;
  }
  if(ob == pet) {
    write(PREFIX + "What ? Attack yourself ?\n");
    return 1;
    }
    if(pet->query_attack() == ob) {
      write(PREFIX + "Yes, yes.\n");
      return 1;
    }
    pet->attack_object(ob);
    return 1;
}
 
communicate(str) {
  string verb;
  write(PREFIX + "You say: " + str + "\n");
  sum_echo((pet->query_name()) + " says: " + str + "\n");
    return 1;
}
 
look(str) {
  object ob, ob_tmp;
  string item;
  if(!str) {
   if(brief_tl) {
     list_basic("ROOM");
   } else {
     list_complex("ROOM");
   }
   return 1;
  }
  if(sscanf(str, "at %s", item) == 1 || sscanf(str, "in %s", item) == 1) {
   if(!find_local(item)) {
     write(PREFIX + "There is no " + str + " here.\n");
     return 1;
   }
   if(brief_tl) {
     call_other(find_local(item), "long");
     list_basic(find_local(item));
   } else {
     call_other(find_local(item), "long");
     list_complex(find_local(item));
   }
   return 1;
   }
    write(PREFIX + "Look AT something, or what?\n");
    return 1;
}
 
put(str) {
  int i;
  string item;
  string container;
  object item_o;
  object container_o;
  if(!str) return 0;
  if(sscanf(str, "%s in %s", item, container) != 2) {
    write(PREFIX + "Put what ?\n");
    return 1;
  }
  container = lower_case(container);
  container_o = present(container, pet);
  if(!container_o)
  container_o = present(container, environment(pet));
  if (!container_o) {
    write(PREFIX + "There are no " + container + "s here!\n");
    return 1;
  }
  if (!call_other(container_o, "can_put_and_get", 0)) {
     write(PREFIX + "You can't do that (can_put_and_get returned 0).\n");
     return 1;
  }
  item = lower_case(item);
  item_o = present(item, pet);
  if (!item_o) {
     write(PREFIX + "You have no " + item + "!\n");
     return 0;
  }
  if (call_other(item_o, "prevent_insert")) return 1;
  if (call_other(item_o, "drop")) return 1;
  i = call_other(item_o, "query_weight");
  if (call_other(container_o, "add_weight", i)) {
    call_other(environment(item_o), "add_weight", -i);
    move_object(item_o, container_o);
    sum_echo((pet->query_name()) + " puts the " + item + " in the " + container + ".\n");
    write(PREFIX + "Ok.\n");
    it = item;
    return 1;
  }
  write(PREFIX + "There is not room for more.\n");
  return 1;
}
 
take_object(str) {
  string item;
  string container;
  object item_o;
  object container_o;
  int weight;
  if(!str) {
    write(PREFIX + "What ?\n");
    return 1;
  }
  if(str == "all") {
    get_all(environment(pet));
    return 1;
  }
  if (sscanf(str, "%s from %s", item, container) != 2) {
    pick_item(str);
    return 1;
  }
  container_o = present(lower_case(container));
  if(!container_o) {
    write(PREFIX + "There is no " + container + " here.\n");
    return 1;
  }
  if (!call_other(container_o, "can_put_and_get", 0)) {
    write(PREFIX + "You can't do that!\n");
    return 1;
  }
  item_o = present(item, container_o);
  if(!item_o){
    write(PREFIX + "There is no " + item + " in the " + container + ".\n");
    return 1;
  }
  call_other(container_o, "add_weight", -weight);
  move_object(item_o, pet);
  write(PREFIX + "Ok.\n");
  sum_echo((pet->query_name()) + " takes " + item + " from " + container + ".\n");
  return 1;
}
 
get_object(obj) {
  object ob;
  int i;
  obj = lower_case(obj);
  if(environment(pet)->id(obj)) {
  write(PREFIX + "You can't take that.\n");
  return 1;
  }
  ob = present(obj, environment(pet));
  if(!ob) {
    write(PREFIX + "That is not here.\n");
    return 1;
  }
  if(environment(ob) == pet) {
    write(PREFIX + "You already have it!\n");
    return 1;
  }
 
  if(call_other(ob, "get") != 1) {
    write("You wrench at " + (ob->short()) + " violently!\n");
    if(living(ob)) {
      sum_echo((pet->query_name()) + " grabs " + (ob->query_name()) + " by the neck!\n");
    } else {
      sum_echo((pet->query_name()) + " tears " + (ob->short()) + " out of the ground!\n");
    }
  }
  i = call_other(ob, "query_weight", 0);
  move_object(ob, pet);
  sum_echo((pet->query_name()) + " takes " + obj + ".\n");
  it = obj;
  write(PREFIX + "Ok.\n");
  return 1;
}
 
drop_object(obj) {
  string tmp;
  string tmp2;
  int i;
  if (!obj) {
    write(PREFIX + "What ?\n");
    return 1;
  }
  if (obj == "all") {
  drop_all(1);
  return 1;
  }
  if(sscanf(obj, "%s in %s", tmp, tmp2) == 2) {
  put(obj);
  return 1;
  }
  tmp = obj;
  obj = present(lower_case(obj), pet);
  if(!obj) {
    write(PREFIX + "That is not here.\n");
    return 1;
  }
  if(drop_one_item(obj)) {
    it = tmp;
    write(PREFIX + "Ok.\n");
    sum_echo((pet->query_name()) + " drops the " + tmp + ".\n");
  }
  return 1;
}
 
emote(str) {
  if(!str) {
    write(PREFIX + "Emote what ?\n");
    return 1;
  }
  sum_echo((pet->query_name()) + " " + str + "\n");
  write(PREFIX + "You " + str + "\n");
  return 1;
}
 
tell(str) {
  object ob;
  string who;
  string msg;
   if(!str || sscanf(str, "%s %s", who, msg) != 2) {
    write(PREFIX + "Tell what ?\n");
    return 1;
  }
  it = lower_case(who);
  ob = find_living(it);
  if(!ob) {
    write(PREFIX + "No player with that name.\n");
    return 1;
  }
  tell_object(ob, (pet->query_name()) + " tells you: " + msg + "\n");
  write(PREFIX + "Ok.\n");
  return 1;
}
 
drop_one_item(ob) {
  int weight;
  if(call_other(ob, "drop", 0)) return 0;
  move_object(ob, environment(pet));
  write(PREFIX + "Ok.\n");
  return 1;
}
 
drop_all(verbose) {
  object ob;
  object next_ob;
  if (!pet || !living(pet)) return;
    ob = first_inventory(pet);
    while(ob) {
      string out;
      next_ob = next_inventory(ob);
      it = call_other(ob, "short", 0);
      if(drop_one_item(ob) && verbose) {
        out = it + ".\n";
        sum_echo((pet->query_name()) + " drops " + out);
        tell_object(PREFIX + pet, "drop: " + out);
      }
      ob = next_ob;
   }
}
 
give_object(str) {
  string item, dest;
  object item_ob, dest_ob;
  int weight;
  int coins;
  if (!str) return 0;
  if (sscanf(str, "%s to %s", item, dest) != 2) {
    write(PREFIX + "Give what to whom ?\n");
    return 1;
  }
  dest = lower_case(dest);
  if (item) {
    item = lower_case(item);
    item_ob = present(item, pet);
      if (!item_ob) {
        write(PREFIX + "There are no " + item + " here.\n");
        return 1;
      }
    it = item;
    if (environment(item_ob) == this_object() &&
      call_other(item_ob, "drop", 0) == 1) {
      return 1;
    } else {
    if (!call_other(item_ob, "get")) {
        write(PREFIX + "You can't get that !\n");
        return 1;
    }
   }
  }
  dest_ob = present(dest, environment(pet));
  if(!dest_ob) {
    write(PREFIX + "There is no " + capitalize(dest) + " here.\n");
    return 1;
  }
  if(!living(dest_ob)) {
    write(PREFIX + "You can't do that.\n");
    return 1;
  }
  weight = call_other(item_ob, "query_weight", 0);
  if (!call_other(dest_ob, "add_weight", weight)) {
    write(PREFIX + capitalize(dest) + " can't carry any more.\n");
    return 1;
  }
  move_object(item_ob, dest_ob);
  sum_echo((pet->query_name()) + " gives " + item + " to " + capitalize(dest) + ".\n");
  write(PREFIX + "Ok.\n");
  return 1;
}
 
get_all(from) {
  object ob, next_ob;
  ob = first_inventory(from);
  while(ob) {
    string item;
    next_ob = next_inventory(ob);
    item = call_other(ob, "short", 0);
      if(item && call_other(ob, "get", 0)) {
        write(PREFIX + item + ": Ok.\n");
        move_object(ob, pet);
        sum_echo((pet->query_name()) + " takes: " + item + ".\n");
        it = item;
        }
        ob = next_ob;
    }
}