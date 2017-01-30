inherit "obj/weapon";
int count, wait, no_hit;
init() {
   add_action("add","add");
   add_action("sonic","sonic");
   add_action("help","help");
   ::init();
}
reset(arg) {
::reset(arg);
   if(arg) return;
   count=5;
   wait=5;
   no_hit = time();
   set_name("A Ghetto Blaster");
   set_short("A Ghetto Blaster");
   set_long("This is the preferred weapon of local gang members.\n"
           +"Type HELP BLASTER for more info on it.\n");
   set_class(10);
   set_alias("blaster");
   set_weight(3);
   set_value(1000);
   set_alias("blaster");
}

sonic(str)  {
  object ob;
  if (!str && !this_player()->query_attack()) {
    write("Blast who?\n");
    return 1;
   } else
   if (!this_player()->query_attack() && !present(str,environment(this_player()))) {
      write("That is not here!\n");
      return 1;
    } else {
  if(!str) ob = this_player()->query_attack();
  else
        ob = present(str,environment(this_player()));
  if(!this_player()->valid_attack(ob)) write("cant do it man\n");
  else {
     if (count>0) {
        weapon_hit(ob);
       }
     else
       { write("The ghetto blaster has used up it's batteries.\n"); }
  }
   return 1;
 }
  }

weapon_hit(str) {
if (no_hit>=time()) {
  write("The blaster is charging.\n");
 } else {
  say(this_player()->query_name()+"'s ghetto blaster sends a sonic boom"+
  " at "+capitalize(str->query_name())+".\n");
  write("Your ghetto blaster sends a sonic boom at "+capitalize(str->query_name())+".\n");
  no_hit = wait + time();
   if(present(str,environment(this_player()))) str->hit_player(5);
  count--;
  }
  return 1;
  }

help(str) {
  if (str=="blaster" || str=="ghetto blaster" || str=="ghetto") {
    write("This is a sonic ghetto blaster.  To operate you will need to tell\n"
         +"it to SONIC <Target>.  It has a set number of charges due to the\n"
         +"batteries.  After the charges are used up you will have to buy\n"
+"new batteries that you will have to ADD.\n");
    return 1;
  }
}

battery(str) {
  object bat;
  bat = first_inventory(this_player());
  while (bat) {
    if (call_other(bat,"id",str)) return bat;
    bat = next_inventory(bat);
  }
  return 0;
}

add(str) {
  object batt;
  if (str=="battery") {
     batt = battery(str);
     if (batt) {
     if (count<5) {
       count++;
       destruct(batt);
       write("You load a new battery in the blaster.\n");
     } else {
     write("The blaster is full of batteries.\n");
    }
   } else {
     write("You don't have any batteries.\n");
   }
  } else {
    write("What do you want to add?\n");
   }
  return 1;
}
