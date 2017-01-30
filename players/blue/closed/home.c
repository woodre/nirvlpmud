#include "/players/blue/closed/lib/color.h"
#include "/players/blue/closed/lib/basic.h"
#define OWNER find_player("blue")
#define CRN CAP(this_player()->query_real_name())

object *stuff;
string *people;
int people_on, stuff_on;

id(str) { return str == "bluehome"; }
short() { return CYA+" The Workroom of "+BOLD+" Blue."+
                  NOSTYLE+WHI;
}
long() { 
   if(people_on)
   people_check();
   if(ENVTP == TO)
   write("You find yourself in a beautiful room, light stone "+
      "\n");
   else write(CYA);
}

reset(arg) {
   
   if(arg) return;

   set_heart_beat(1);
   set_light(1);
   stuff = allocate(20);
   people = allocate(20);
   people = ({"blue", "hawkeye","boltar","sandman",
         "airwoman", "delilah"});
   stuff = ({});
    if(!present("board",TO)) {
      move_object( clone_object("players/grimm/closed/obj/badge_stuff/board"), 
            this_object());
   }
}

heart_beat() {
   if(people_on) people_check();
   if(stuff_on) check_stuff();
}

init() {

   add_action("leave_room","leave");
   add_action("no_drop","drop");

   if(TP->query_real_name() == "blue") {
      add_action("people_toggle", "wpeople");
      add_action("stuff_toggle","wstuff");
      add_action("stuff_ok","wokstuff");
      add_action("spill_people","wspill");
      add_action("people_add","wadd");
   }
}
      
no_drop(str) {
   write("Things that are on the ground swiftly disapear.  Not a good idea.\n");
   return 1;
}

leave_room(str) {
   if(str == "church") {
      move_player(TP,"church#room/church");
      return 1;
   }
   return;
}

static people_toggle() {
   if(people_on == 1) {
      write("Unsecuring room.\n");
      people_on = 0;
      return 1;
   }
   write("Securing room.\n");
   people_on = 1;
   return 1;
}

static stuff_toggle() {
   if(stuff_on == 1) {
      write("Unsecuring stuff in room.\n");
      stuff_on = 0;
      return 1;
   }
   write("Securing items in room.\n");
   stuff_on = 1;
   return 1;
}

stuff_ok() {
   object *temp;
   object ob;
   int n;
   n = 0;
   temp = allocate(20);
   ob = first_inventory(TO);
   while(ob && n < 20) {
      temp[n] = ob;
      n+=1;
      ob = next_inventory(ob);
   }
   tell_object(OWNER, "Items okayed.\n");
   stuff = 0;
   stuff = temp;
   return 1;
}

static people_add(str) {
   int size;
   size = sizeof(people);
   people[size] = str;
   write("Ok.\n");
   return 1;
}

spill_people() {
   int n;
   write("People okayed......\n");
   while(people[n]) {
      write(people[n]+"\n");
      n+=1;
   }
   write("Done.\n");
   return 1;
}

static people_check() {
   object ob, tmp;
   int n, ok, size;
   string name;
   n = 0;
   size = sizeof(people);
   ob = first_inventory(TO);
   while(ob) {
      if(ob->is_player()) {
         name = ob->query_real_name();
         while(n < size && !ok) {
            if(people[n] == name) ok = 1;
            n+= 1;
         }
         if(!ok) {
            write("Removing "+CAP(ob->query_real_name())+".\n");
            tmp = next_inventory(ob);
            move_object(ob, "/room/void");
            command("look", ob);
         }
      ok = 0;
      n = 0;
      }
      if(present(ob, TO)) ob = next_inventory(ob);
         else ob = tmp;
   }
   return 1;
}


static check_stuff() {
   int n, ok;
   object ob, tmp;
   ob = first_inventory(TO);
   while(ob) {
      while(stuff[n]&&!living(ob)) {
         if(ob == stuff[n]) ok = 1;
         n+=1;
      }
      tmp = next_inventory(ob);
      if(!ok) {
         move_object(ob, "/room/void");
         command("look", ob);
         return 1;
      }
      ok = 0;
      n = 0;
      ob = tmp;
   }
   return 1;
}
      
