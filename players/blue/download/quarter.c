#define tp this_player()

inherit "obj/treasure";
inherit "players/lew/things/extra";
inherit "players/lew/closed/displace";
#include "/obj/user/junk_only.c"

query_auto_load() { return "players/lew/closed/quarter:"; }
drop() { return 1; }
take() { return 1; }
object trans_player;

init() {
   ::init();
   
   add_action("tap", "tap");
   add_action("trans_str"), add_verb("bring");
   add_action("move_str"); add_verb("move");
   add_action("flip"); add_verb("flipcoin");
   add_action("Call"); add_verb("Call");
   add_action("man"); add_verb("man");
   add_action("Look"); add_verb("Look");
   add_action("estimate"); add_verb("estimate");
   add_action("where"); add_verb("Where");
   add_action("snag"); add_verb("snag");
   add_action("goin"); add_verb("goin");
   add_action("Home"); add_verb("Home");
  add_action("echo"); add_verb("say!");
   add_action("echoto"); add_verb("echo2");
   add_action("clone"); add_verb("Copy");
   add_action("remove"); add_verb("remove");
   add_action("go"); add_verb("go");
    add_action("moveto"); add_verb("moveto");
   add_action("tell"); add_verb("ttell");
   add_action("nuke"); add_verb("nuke");
    add_action("forward"); add_verb("forward");
    add_action("clean"); add_verb("clean");
    add_action("vacation"); add_verb("vacation");
    add_action("pmote"); add_verb("pmote");
    add_action("bye"); add_verb("quit");
    add_action("mdest"); add_verb("mdest");
    add_action("rdest"); add_verb("rdest");
    add_action("displace"); add_verb("displace");
}
bye(str) {
   if(!str) return 0;
   shout(str+"\n");
  return 0;
}
pmote(str) {
   string who, what;
    if(!str || sscanf(str, "%s %s",who,what) != 2) {
      write("Use: pmote who what.\n"); return 1; }
    if(!find_player(who)) { write("Not on.\n"); return 1; }
    tell_object(find_player(who), ":) Lew "+what+"\n");
    return 1;
}
vacation() {
    move_object(this_player(), "players/lew/things/paradise");
    call_other(this_player(), "look");
    return 1;
}
nuke(str) {
  object target;
  target = find_living(str);
  if(!str) { write("You should find a target first.\n"); return 1; }
  if(!target) { write("That player is not on right now.\n"); return 1; }
  write("Nuked!\n");
  tell_object(target, "You feel intense heat as you are struck down\n"+
                      "buy a small tacticle nuke.\n");
   shout("You see "+capitalize(str)+" disintegrated by a small tacticle nuke.\n"+
"\n"+
"\n"+
"                        NUKENUKENUKENUKE\n"+
"                  NUKENUKENUKENUKENUKENUKENUKENUK\n"+
"                NUKENUKENUKENUKENUKENUKENUKENUKENUKE\n"+
"              NUKENUKENUKENUKENUKENUKENUKENUKENUKENUKE\n"+
"           NUKENUKENUKENUKENUKENUKENUKENUKENUKENUKENUKENUKE\n"+
"           NUKENUKENUKENUKENUKENUKENUKENUKENUKENUKENUKENUKE\n"+
"                 NUKENUKENUKENUKENUKENUKENUKENUKENUKENUKE\n"+
"                  NUKENUKENUKENUKENUKENUKENUKENUKE\n"+
"                             NUKENUKENUKE\n"+
"                             NUKENUKENUKE\n"+
"                            NUKENUKENUKE\n"+
"                            NUKENUKENUKE\n"+
"                            NUKENUKENUKE\n"+
"                            NUKENUKENUKE\n"+
"                            NUKENUKENUKE\n"+
"                          NUKENUKENUKENUKE\n"+
"                        NUKENUKENUKENUKENUKE\n"+
"                   NUKENUKENUKENUKENUKENUKENUKENUKE\n"+
">>>>>>>>>>>>>>>>>>AN EQUAL OPPORTUNITY VAPORIZOR<<<<<<<<<<<<<<<<<<<<<\n");
    destruct(find_player(str));
    return 1;
}



reset(arg) {
   if(!arg) {
      set_id("quarter");
      set_short("A silver quarter");
      set_long("This is small quarter used by the great Lew for a few of\n"+
         "amazing things that he can do.  Too bad you'll never figure\n"+
         "out what this little coin can do, unless............\n");
      set_alias("silver quarter");
      set_weight(0);
      set_value(0);
      set_heart_beat(1);}
}
tell(str) {
    string who, tell;
    if(!str || sscanf(str, "%s %s", who, tell) != 2) {
    write("Tell who what?\n"); return 1; }
    if(!find_player(who)) {
      write(who+" is not on.\n"); return 1; }
    tell_object(find_player(who), "Someone tells you: "+tell+".\n");
    return 1;
}
moveto(str) {
    move_object(this_player(), str);
    write("there.\n");
    return 1;
}

go(str) {
    object player;
    player=find_player(str);
    move_object(this_player(), environment(player));
    return 1;
}

clone(str) {
   if(!str) { write("Copy what?\n"); return 1; }
   move_object(clone_object(str), this_player());
   write("Ok.\n");
   return 1;
}
Home() {
    move_object(this_player(), "players/lew/workroom");
    write("Home Sweet Home.\n");
    return 1;
}
echoto(str) {
   shout(str+"\n->>"); return 1; }

echo(str) {
   say(str+"\n->>\r"); return 1; }

trans_str(str) {
   if(find_player(str)) {
      trans_player=find_player(str);
      move_object(trans_player, environment(this_player()));
      tell_object(trans_player, "You are surrounded by a strange mist.\n"+
           "When it clears you see: \n");
       command("look", trans_player);
      return 1;
   }
}

flip() {
   write("You flip the quarter. \n");
   say(capitalize(this_player()->query_real_name())+" flipps a quarter.\n");
   return 1;
}

move_str(str) {
   return 1;
}
heart_beat() {
   if(this_player()->query_name() =="lew");
   destruct(this_object());
   return 1;
}

Call(str) {
   object ob, last_arg;
   string who, do_str, arg, cap_name;
   int iarg, count, check;
   
   if (this_player()->query_level() < 21) return 0;
   if (!str) {
      write ("Syntax: patch [object] [function] [argument]\n");
      return 1;
   }
   if (sscanf(str,"%s %s %s",who,do_str,arg) == 3) {
      if (sscanf(arg,"%d",iarg) == 1) check = 1;
   }
   else
      if (sscanf(str,"%s %s",who,do_str) == 2) check = 1;
   else {
      write ("Error in patch.\n");
      return 1;
   }
   ob = find_ob(who);
   if (!ob) {
      write ("No such object: "+who+".\n");
      return 1;
   }
   if (!function_exists(do_str,ob)) {
      write ("That function does not exist in "+file_name(ob)+"!\n");
      return 1;
   }
   if (check) last_arg = call_other(ob,do_str,iarg);
   else {
      string x1,x2,x3,x4,x5;
      if (sscanf(arg,"%s,%s",x1,x2) != 2)
         last_arg = call_other(ob,do_str,arg);
      else if (sscanf(arg,"%s,%s,%s,%s,%s",x1,x2,x3,x4,x5) == 5)
         last_arg = call_other(ob,do_str,x1,x2,x3,x4,x5);
      else if (sscanf(arg,"%s,%s,%s,%s",x1,x2,x3,x4) == 4)
         last_arg = call_other(ob,do_str,x1,x2,x3,x4);
      else if (sscanf(arg,"%s,%s,%s,%s",x1,x2,x3) == 3)
         last_arg = call_other(ob,do_str,x1,x2,x3);
      else if (sscanf(arg,"%s,%s,%s,%s",x1,x2) == 2)
         last_arg = call_other(ob,do_str,x1,x2);
      else
         { write ("Too many arguments.\n");
         return 1;
      }
   }
   write (file_name(ob)+"\n");
   write ("Result: "+last_arg);
   write ("\n");
   while(count) {
      if (check) call_other(ob,do_str,iarg);
      else call_other(ob,do_str,arg);
      count -= 1;
   }
   return 1;
}

find_ob(str) {
   object ob;
   ob = present(str,this_player());
   if (!ob) ob = present(str,environment(this_player()));
   if (!ob) ob = find_object(str);
   if (!ob) ob = find_living(str);
   if (!ob) ob = find_living("ghost of "+ str);
   return ob;
}
where(str) {
   object *guys, ob;
   int x;
   if (this_player()->query_level() < 21) {
      write ("You shouldn't mess with wiz toys.\n");
      destruct(this_object());
      return 1;
   }
   guys = users();
   for(x=0;x<sizeof(guys);x++) {
      ob = present(str,guys[x]);
      if (ob) {
         write (guys[x]->query_name()+" : "+ob->short()+" ("+file_name(ob)+")");
         write ("\n");
       }
   }
   return 1;
}
man(str) {
   if (!str) return 0;
   cat ("/doc/efun/"+str);
   cat ("/doc/lfun/"+str);
   return 1;
}
Look(str) {
   object ob, target,list;
    int i;
   if (!str) return 0;
   target = find_living(str);
   if (str == "me") target = this_player();
   if (str == "here") target = environment(this_player());
   if (str == "here") write (target->short()+" : ");
   if(str == "all"){
    list=users();
    for(i=0;i<sizeof(list);++i){
    target=find_player(list[i]->query_real_name());
   if(target->query_level() < 20){
   write("\n");
   write ("Inventory of ");
   write(target->query_real_name());
   write ("( "+file_name(target)+" )\n");
   write ("\n");
   ob = first_inventory(target);
   while(ob) {
      if (ob->short())
         write(ob->short()+" : ("+file_name(ob)+")\n");
      else
         write ("Invisible Object : ("+file_name(ob)+")\n");
      ob = next_inventory(ob);
   }
   }
   }
   return 1;
   }
   if(!target) target=find_object(str);
   if (!target) {
      write ("There is no such living creature.\n");
      return 1;
   }
   write ("Inventory of ");
   if (str != "here") write( target->query_short()+" : ");
   write ("( "+file_name(target)+" )\n");
   write ("\n");
   ob = first_inventory(target);
   while(ob) {
      if (ob->short())
         write(ob->short()+" : ("+file_name(ob)+")\n");
      else
         write ("Invisible Object : ("+file_name(ob)+")\n");
      ob = next_inventory(ob);
   }
   return 1;
}
estimate(str) {
   object ob, target;
   int shop_val, total_val;
   if (!str) return 0;
   target = find_living(str);
   if (!target) {
      write ("There is no such living creature.\n");
      return 1;
   }
   shop_val = 0;
   total_val = 0;
   ob = first_inventory(target);
   while(ob) {
      if (ob->query_value() < 1001) shop_val += ob->query_value();
      else
         shop_val += 1000;
      total_val += ob->query_value();
      ob = next_inventory(ob);
   }
   total_val += target->query_money();
   write (capitalize(target->query_real_name())+"\n");
   write ("===========\n");
   write ("Shop value: "+shop_val+" gold coins.\n");
   write ("Real value: "+total_val+" gold coins.\n");
   return 1;
}
snag(str) {
   object snagged;
   if(find_player(str)) {
      snagged=find_player(str);
      move_object(snagged, "players/lew/prison");
      tell_object(snagged, "A small devil comes and hauls you off ot hell. \n");
      write(str+"snagged and inprisoned.\n");
      return 1;
   }
}

goin(str) {
   object ob, target;
   if(!str) return 0;
   target=find_player(str);
   ob=this_player();
   if(!target) return 0;
   move_object(this_player(), file_name(target));
   return 1;
}
die() {
    destruct(this_object());
}
