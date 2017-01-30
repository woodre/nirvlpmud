int new_object;
int new_name;
int new_value;
int new_short;
int new_long;
int start_time;
/*
 
query_auto_load() {
    return "players/catwoman/obj/list:" + start_time; }
*/
 
start(ob) {
    move_object(this_object(), ob);
}
 
id(str) {
    return str == "list"; }
 
long() {
 
  write("Catwoman's list!\n\n");
  write("Gag       Eliminates shouting        Rgag       Removes the Gag\n");
  write("Clean     Removes your inventory     An         Announcements\n");
  write("Snatch    Puts object in inventory   Into       Puts you in object inventory\n");
  write("Titlep    Title players              Align      Change your alignment\n");
  write("Clank     Distant sound of Battle    Crash      Let's people know your here\n");
  write("Imprison  Imprison player            Summon     Summon demon to fight player.\n");
  write("Rob       Rob <obj> from <player>    Steal      Steal <player> <amount>\n");
  write("Rde       Rde <item> from <player>   Light on   Lights up dark rooms\n");
  write("Scare     Scare <player>             Tend       Tend <player> <amount>\n");
  write("Money     Money <amount>             Inv        Inv <player>\n");
  write("Move      Move <player> <where>      Trace      Trace <monster>\n");
  return 1; }
 
 
init() {
    add_action("gag"); add_verb("gag");
    add_action("rgag");add_verb("rgag");
    add_action("clean"); add_verb("clean");
    add_action("clank"); add_verb("clank");
    add_action("an"); add_verb("an");
    add_action("tend"); add_verb("tend");
    add_action("snatch"); add_verb("snatch");
    add_action("steal"); add_verb("steal");
    add_action("titlep"); add_verb("titlep");
    add_action("summon"); add_verb("summon");
    add_action("into"); add_verb("into");
    add_action("rob"); add_verb("rob");
    add_action("move"); add_verb("move");
    add_action("lookplayer"); add_verb("inv");
    add_action("money"); add_verb("money");
    add_action("destr"); add_verb("dest");
    add_action("scare"); add_verb("scare");
    add_action("crash"); add_verb("crash");
    add_action("rdestr"); add_verb("rde");
    add_action("trace"); add_verb("trace");
     add_action("light"); add_verb("light");
     add_action("set_align"); add_verb("align");
 
}
drop() { return 1;}
 
short() {
    return "A list"; }
 

light(str) {
  object level;
  level = call_other(this_player(), "query_level");
  if (level < 20) return 0;
  if (!str) return 0;
  if (str == "on") set_light(1);
  if (str == "off") set_light(0);
  return 1;
}
set_align(t) {
  object level;
  level = call_other(this_player(), "query_level");
  if (level < 20) {
     write("You must be of level 20 to do that.\n");
     return 0;
     }
  call_other(this_player(), "set_alignment", t);
  write("Alignment has been changed.\n");
  return 1;
}
gag(str) {
    object ob;
 
    ob = find_living(str);
    if (!ob) {
    write("No such player.\n");
    return 1; }
    call_other(clone_object("obj/shout_curse") , "start", ob);
    write("Ok.\n");
    return 1; }
money(str) {
int val;
   if(!str) {
   write("Useage: money <amount>\n");
   return 1;
   }
   if (sscanf(str, "%d", val) !=1) {
   write("Useage: money <amount>\n");
   return 1;
   }
   call_other(this_player(), "add_money", val);
   write("You gain "+str+" coins.\n");
   return 1;
}
 
scare(person) {
    object player;
    player = find_living(person);
    if (!player) {
        write("No such player.\n");
        return 0;
        }
    tell_object(player, "You die.\n");
    tell_object(player, "You have a strange feeling.\n");
    tell_object(player, "You can see your own dead body from above.\n\n");
    write("Done.\n");
    return 1;
}
rgag(str) {
    object liv, ob;
    liv = find_living(str);
    if (!liv) {
        write("Can't find "+str);
        return 1; }
   ob = present("shout_curse",liv);
    if (!ob) {
        write(str + " has no sore throat.\n");
        return 1; }
    tell_object(liv, "Your throat feels better now.\n");
    transfer(ob, environment(liv));
    write("Done.\n");
    destruct(ob);
    return 1; }
 
clean() {
  object soul,ob,last_ob,next_ob;
  int isit;
  ob = first_inventory(this_player());
  while(ob) {
  next_ob = next_inventory(ob);
  if((ob) && !living(ob) &&
    (call_other(ob, "short",0) != "Ratings list"))
destruct(ob);
  ob = next_ob; }
   soul = clone_object("obj/soul");
  move_object(soul, this_player());
  write("Inventory has been cleaned.\n");
  return 1; }
 
imprison(str) {
   object prisoner,ob,next_ob;
   if(!str) return 0;
   prisoner = find_living(str);
   tell_object(prisoner,"You have brought down the wrath of a wizard.\n");
   tell_object(prisoner,"Severe punishment is in order.\n");
   tell_object(prisoner,"\n\nYou are transported somewhere.\n");
/*
   tell_object(prisoner,"Your equipment has been sold to pay for the upkeep of the dungeon.\n");
   ob = first_inventory(prisoner);
   while (ob) {
      next_ob = next_inventory (ob);
      if ((ob) && !living(ob)) destruct(ob);
      ob = next_ob;}
*/
   move_object(prisoner, "room/prison");
   write(call_other(prisoner,"query_name") + " has been imprisoned.\n");
   return 1; }
 
get() {
    return 1; }
 
reset(arg) {
    if (!arg)

    set_light(0); }
 
crash() {
    shout("You feel like someone is watching from the shadows.\n");
    shout(call_other(this_player(), "query_name") +
    " begins to dig your grave.\n");
    write("Ok.\n");
    return 1; }
 
 
trace(str) {
    object ob;
    if (call_other(this_player(), "query_level") < 20) {
    write("Failure.\n");
    return 1; }
    if (!str) {
    write("Give monster name as argument.\n");
    return 1; }
    ob = present(str, environment(this_player()));
    if (!ob)
    ob = find_living(str);
    if (!ob) {
    write("No " + str + " found.\n");
    return 1; }
    write(ob); write("\n");
    write(environment(ob)); write("\n");
    return 1; }
 
tend(str) {
  object player;
  int amount;
  string name;
  if(!str) return 0;
  sscanf(str,"%s %d", name, amount);
  player = find_living(name);
  if(!player) {
  write("Player does not exist.\n");
  return 1; }
  call_other(player,"heal_self",amount);
  write("Ok. Healing complete.\n");
  return 1; }
 
snatch(str) {
    object player;
    if(!str) {
      write("not enough arguments.\n");
      return 1; }
    player = find_living(str);
    if(!player) {
      write("No such player.\n");
      return 1; }
    move_object(player,this_player());
    write("Ok.\n");
    return 1; }
 
steal(str) {
     object player;
     int amount;
     string name;
     object room;
     if(!str) return 0;
     if(sscanf(str,"%s %d",name,amount) != 2)  {
        write("wrong number of arguments.\n");
        return 1; }
     player = find_living(name);
     if(!player) {
        write("No player by that name.\n");
        return 1; }
     room=environment(player);
     call_other(player,"add_money",-amount);
     write("Ok.\n");
     return 1; }
 
titlep(str) {
   object player;
   string name, title;
   if(!str) return 0;
   sscanf(str,"%s %s",name,title);
   player = find_living(name);
   if(!player) {
     write("No such player exists.\n");
     return 1; }
   call_other(player,"set_title",title);
   write("Foreign title set.\n");
   return 1; }
 
summon(str) {
  object player,creature;
  string name, junk, junk2;
  int here_now;
  here_now = 1;
  if(!str) here_now = 0;
  if(here_now == 1) name = str;
  if(here_now == 1) player = find_living(lower_case(name));
  if(!player) {
  write("No player by that name.\n");
  return 1; }
  say(call_other(this_player(), "query_name") + "'s staff glows for a " +
  "moment then a figure assembles itself\nin front of you.\n");
  creature = clone_object("obj/monster.talk");
        call_other(creature,"set_name","guardian");
        call_other(creature,"set_level",30);
        call_other(creature,"set_alias","monster");
        call_other(creature,"set_short","A mini-iron guardian");
        call_other(creature,"set_long",
            "This little guy is about a foot high and looks like a\n" +
            "metalic gargoyle.\n");
        call_other(creature,"set_wc",30);
        call_other(creature,"set_move_at_reset",0);
        call_other(creature,"set_aggressive",1);
        call_other(creature,"set_chance",50);
        call_other(creature,"set_spell_mess1",
            "The guardian slices into your face with his metalic claws!\n");
        call_other(creature,"set_spell_mess2",
            "The guardian cuts deep into your chest.\n");
        call_other(creature,"set_spell_dam",45);
        call_other(creature,"set_al",300);
        call_other(creature,"set_ac",20);
  move_object(creature,environment(player));
  if(here_now == 1) call_other(player, "kill","guardian");
  write("Ok.\n");
  return 1;
}
/* 
into(str) {
    object ob;
    if (!str) return "what?";
    ob = find_living(str, environment(this_player()));
    if(!ob) {
      write("\""+str+"\" is not here.\n");
      return 1; }
    if(ob == this_player()) {
       write("You pick yourself up and float home.\n");
       say(capitalize(call_other(this_player(), "query_real_name", 0)));
       say("picks himself up from the ground and\n");
       say("starts levitating.  He then floats home.\n");
       move_object(this_player(), "players/" +
              call_other(this_player(), "query_real_name", 0)+
                "/workroom");
          return 1; }
    move_object(this_player(), ob);
    write("You put yourself into "+call_other(ob, "short", 0)+
        "'s inventory.\n");
    return 1; }
 
*/
/* 
rgag(str) {
    object liv, ob;
    liv = find_living(str);
    if (!liv) {
        write("Can't find "+str);
        return 1; }
    ob = present("shout_curse",liv);
    if (!ob) {
        write(str + " has no sore throat.\n");
        return 1; }
    tell_object(liv, "Your throat feels better now.\n");
    transfer(ob, environment(liv));
    write("Done.\n");
    destruct(ob);
    return 1; }
*/
rob(str) {
   object item, victim;
   string iname, vname;
   sscanf (str, "%s from %s", iname,vname);
   if (iname && vname) {
     victim = present (vname,environment(this_player()));
     if (victim) item = present(iname,victim);
     if (item) {
        if (!transfer(item, this_player())) {
        say(call_other(this_player(), "query_name") +
        " snatches " + iname + "away from the hands of mortals like " +
        call_other(victim, "query_name") + "\n");
        write("You steal " + iname + "\n"); }
        else write ("You cannot steal that.\n"); }
    else write ("No such item.\n");
    return 1; }
  else write ("steal what from who?\n");
  return 1; }
 
rdestr(str) {
   object item, victim;
   string iname, vname;
   sscanf (str, "%s from %s", iname,vname);
   if (iname && vname) {
     victim = present (vname,environment(this_player()));
     if (victim) item = present(iname,victim);
     if (item) {
        if (!destruct(item, this_player())) {
        tell_object(victim, call_other(this_player(), "query_name") +
           " destructs " + iname + " from you!!\n");
        say(call_other(this_player(), "query_name") +
           " destructs something from " +
           call_other(victim, "query_name") + "\n");
        write("You destruct " + iname + "\n"); }
       else write ("You cannot destruct that.\n"); }
    else write ("No such item.\n");
    return 1; }
  else write ("Destruct what from who?\n");
  return 1; }
clank() {
   shout("You hear the sounds of swords clanking together in battle.\n");
   write("Ok.\n");
   return 1; }
an(str) {
  if(!str) return 0;
   shout(str + "\n");
   write("Ok. Announcement complete.\n");
   return 1; }
move(str) {

/* Tired of goto xx, trans <person>.. Then try move */
string who,where;
object ob;

if (sscanf(str,"%s %s",who,where) != 2) {
   write("Usage:  move <who> <where>\n");
   return 1;
}
ob = find_living(who);
if (!ob) {
   write("That object was not found.\n");
   return 1;
}

ob->move_player("X#"+where);
write(ob->query_name() + " transfered to "+ where);
tell_object(ob,"You have been teleported elsewhere.\n");
return 1;
}


lookplayer(str) {
    object ob;
    int i;
    if (!str)
       return 0;
    ob = find_living(str);
    if (!ob)
       return 0;
    write("Inventory of " + call_other(ob, "short") + ";\n");
    i = 0;
    ob = first_inventory(ob);
    while(ob) {
       string short_str;
       write(i + "\t");
       short_str = call_other(ob, "short");
       if (short_str)
          write(short_str + ",\t");
       write(ob); write("\n");
       ob = next_inventory(ob);
       i += 1;
   }
   return 1;
 }

