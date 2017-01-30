#define MAX_WEIGTH      50
int hole_weight;
int local_weight;
int monster_present;
int monster_name;


reset(arg) {
   if(!arg) {
   
   local_weight = 0;
   monster_present = 0;
   monster_name = 0;

   }
}
long() {
    write("A Portable Hole... ");
    if (first_inventory(this_object()))
        write("There is something in it.\n");
    else
        write("You can put things in it.\n");
}

query_weight() {
    return 1;
}

add_weight(w) {
    if (local_weight + w > MAX_WEIGTH)
        return 0;
    local_weight += w;
    return 1;
}

short() {
    return "A portable hole";
}

id(str) {
    return str == "hole";
}

query_value() {
    return 0;
}

can_put_and_get() { return 1; }

get() {
    return 1;
}

prevent_insert() {
    if (local_weight > 0) {
        write("You can't when there are things in the bag.\n");
        return 1;
    }
    return 0;
}

init() {
   add_action("recheck_weight","recheck");
   add_action("enter_port_hole","step");
   add_action("leave_port_hole","leave");
   add_action("hole_inv","inhole");
   add_action("hole_get","get");
   add_action("hole_put","put");
   add_action("capture_monster","capture");
   add_action("release_monster","release");
   add_action("hole_help","help");
}

hole_get(str) {
   string what;
   if(sscanf(str, "%s from hole", what)) {
      if(monster_present == 1) {
         if(!monster_release_check()) {
            write("You may not get something from the hole while a monster is"+
                  "in the hole, and you\nmay not release the monster here.\n");
            return 1;
            }
         monster_release();
         return 1;
   }
   }
}

hole_put(str) {
   string what;
   if(sscanf(str, "%s in hole", what)) {
   if(monster_present == 1) {
      if(!monster_release_check()) {
         write("You may not get something from the hole while a monster is"+
               "in the bag, and you\nmay not release the monster here.\n");
         return 1;
      }
   monster_release();
   return 1;
   }
   }
}

hole_inv() {
   object ob;
   if(!present(this_object(),this_player())) {
      write("You must pick it up first.\n");
      return 1;
   }
  ob=first_inventory(this_object());
     if(!ob) {
      write("The portable hole is empty.\n");
      return 1;
      }
   while(ob) {
   write( ob->query_weight() + "    "+ob->short()+"\n");
      ob=next_inventory(ob);
   }
   write(
"----------------------------------------------------------------------------"+
"---\n");
   write("Total weight- "+ local_weight + ".\n");
   return 1;
}

enter_port_hole(str) {
   if(str) return;
   if(monster_present == 1) {
      write("You may not enter the hole while there is a monster in it\n");
      return 1;
      }
   if(this_player()->query_attack()) {
      write("You cannot enter the hole during battle.\n");
      return 1;
   }
   write("You set the portable hole on the ground, carefully unfold it, and"+
         "climb in.\n");
   say((this_player()->query_name()) + " sets a black cloth on the ground,"+
       "unfolds\nit, and disappears in it's shadows.\n");
   move_object(this_object(), environment(this_player()));
   move_object(this_player(), this_object());
   call_other(this_object(), "get()",1);
   command("look",this_player());
   return 1;
}

leave_port_hole() {
   if(environment(this_player())!=this_object()) {
      return;
   }
   move_object(this_player(), environment(this_object()));
   write("You leave the portable hole, fold it up, and put it back in your"+
            "pocket.\n");
   say(capitalize(this_player()->query_name()) + " appears to rise from a "+
 "strange cloth lying on the ground, folds/nit up, and tucks it"+
          " away.\n");
          move_object(this_object(), this_player());
   call_other(this_object(), "get()", 0);
   command("look",this_player());
   return 1;
}

find_hole_weight() {
   object ob;
   local_weight=0;
   ob=first_inventory(this_object());
      while(ob) {
      local_weight += ob->query_weight();
      ob=next_inventory(ob);
      }
   return local_weight;
}

capture_monster(str) {
   int cost;
   object monster;
   if(monster_present == 1) {
      write("You already have a monster in the hole.\n");
      return 1;
   }
   if(this_player()->query_attack()) cost = 100;
   if(!this_player()->query_attack()) cost = 50;
   if(this_player()->query_spell_point() - cost < 0) {
      write("You do not have enough spell points to do that.\n");
      return 1;
   }
   monster=present(str, environment(this_player()));
   if(!monster) {
      write("There is no " + str + " here.\n");
      return 1;
   }
   if(!living(monster)) {
      write("That is not a living thing.\n");
      return 1;
   }
   if(!monster->query_npc()) {
      write("You cannot take that.\n");
      return 1;
   }
   if(!monster_get_check(monster)) {
     write("You cannot take that monster.\n");
   return 1;
   }
   call_other(this_player(), "add_spell_point()",-cost);
   move_object( monster, this_object());
   write("You quickly open the hole and make the monster disappear!!!\n");
   say(capitalize(this_player()->query_name()) + " unfolds a black cloth"+
" and in one quick gesture makes the " + capitalize(monster->query_name()) +
    "\ndisappear!!!\n");
   monster_present = 1;
   monster_name = monster->query_name();
   return 1;
}

monster_get_check(monster) {
   string whatever;
   string here;
   if(monster->query_level() > 9) {
      return 0;
   }
   if(call_other(monster, "aggressive",0) == 1) {
      return 0;
   }
   here=file_name(environment(this_object()));
   if(sscanf(here,"/room/s%", whatever)) {
      return 0;
   }
   return 1;
}

monster_release() {
   string whatever;
   object ob;
   if(monster_present !=1) {
      monster_present = 0;
      return 1;
   }
   ob=first_inventory(this_object());
   if(!ob) {
      return 1;
   }
   while(ob) {
      if(living(ob)) {
   if(sscanf(file_name(environment(this_player())),"/room/%s",whatever)) {
      write("You cannot release the monster here.\n");
      return 1;
   }
         move_object(ob, environment(this_player()));
   write("A "+capitalize(ob->query_name()) + " suddenly leaps out of the "+
         "hole!!!\n");
   say(capitalize(this_player()->query_name()) + "reaches into a black cloth"+
      " and suddenly a " + ob->query_short() + " leaps out!\n");
      monster_present = 0;
   return 1;
   }
   ob=next_inventory(ob);
      return 1;
   }
}

monster_release_check() {
   return 1;
}

release_monster() {
   monster_release();
   return 1;
   }
hole_help(str) {
   if(!str || str != "hole") {
      return 0;
   }
write("These are the commands that you may use with the hole-\n"+
"recheck- recheck how much weight is in the hole, if you think that there\n"+
"         might be an error.\n"+
"step-   Enter the portable hole.  You may not do this if there is a\n"+
"        monster in the hole.  It costs 25 spell points.\n"+
"leave-  leave the whole once you have entered it.\n"+
"inhole - check the inventory of the whole, with weights of each item.\n"+
"capture <monster> - Capture a non-aggressive monster, level 9 or lower.\n"+
"        If you are fighting it costs 75 spell points, 50 otherwise.\n"+
"release - release the monster trapped in the hole.\n"+
"\nNote- You may only keep one monster in the hole at once, and cannot "+
"release it in public places ( i.e. the church).  While the is a monster in"+
"the hole, you cannot get or put things in it until the monster is releas"+
"ed.\n"+

"Any other ideas for the hole would be greatly appreciated.\n"+
"                                       -Blue.\n");
   return 1;
}

recheck_weight() {
   find_hole_weight();
   write("Weight is now: "+local_weight+".\n");
   return 1;
}
