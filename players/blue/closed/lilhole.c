#define MAX_WEIGTH      35
int hole_weight;
int local_weight;
   int log;

reset(arg) {
   if(!arg) {
   
   local_weight = 0;

   }
}
long() {
    write("A Portable Hole... ");
   write("Type 'help hole' for a list of commands.\n");
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
   if(living_check()) {
      return 0;
   }
   return 50;
}

can_put_and_get() { return 1; }

get() {
   object ob;
   if(!first_inventory(this_object())) {
      return 1;
   }
   ob=first_inventory(this_object());
      while(ob) {
      if(living(ob)) {
         return 0;
      }
      ob=next_inventory(ob);
   }
   return 1;   
}

prevent_insert() {
    if (local_weight > 0) {
        write("You can't when there are things in the bag.\n");
        return 1;
    }
    return 0;
}

/*
init() {

   add_action("recheck_weight","recheck");
   add_action("enter_port_hole","step");
   add_action("leave_port_hole","leave");
   add_action("hole_inv","inhole");
   add_action("hole_help","help");
}
*/

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
   if(!log) {
   write_file("/players/blue/HOLE.LOG", this_player()->query_name() +
   " bought a hole on " + ctime(time()) + ".\n");
   log = 1;
}
   if(living_check()) {
      write("There is already someone in there.\n");
      return 1;
      }
   if(this_player()->query_attack()) {
      if(this_player()->query_spell_point() - 25 < 0) {    
   write("You are too low on energy.\n");
         return 1;
         }
     call_other(this_player(), "add_spell_point", -25);
   }
   write("You set the portable hole on the ground, carefully unfold it, and"+
         " climb in.\n");
   say((this_player()->query_name()) + " sets a black cloth on the ground,"+
       " unfolds it,\nand disappears in it's shadows.\n");
   move_object(this_object(), environment(this_player()));
   move_object(this_player(), this_object());
   call_other(this_object(), "get",0);
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
 "strange cloth lying on the ground, folds it\nup, and tucks it"+
          " away.\n");
          move_object(this_object(), this_player());
   call_other(this_object(), "get", 1);
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

hole_help(str) {
   if(!str || str != "hole") {
      return ;
   }
write("These are the commands that you may use with the hole-\n"+
"recheck- recheck how much weight is in the hole, if you think that there\n"+
"         might be an error.\n"+
"step-   Enter the portable hole. This costs 25 sp if you are fighting.\n"+
"leave-  leave the whole once you have entered it.\n"+
"inhole - check the inventory of the whole, with weights of each item.\n"+
"Any other ideas for the hole would be greatly appreciated.\n"+
"                                       -Blue.\n");
   return 1;
}

recheck_weight() {
   find_hole_weight();
   write("Weight is now: "+local_weight+".\n");
   return 1;
}

living_check() {
   object ob;
   ob = first_inventory(this_object());
     if(!ob) return 0;
   while(ob) {
      if(living(ob)) {
         return 1;
      }
   ob=next_inventory(ob);
   }
   return 0;
}
