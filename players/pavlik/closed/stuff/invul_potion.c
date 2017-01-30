#define EN environment()
int eaten,num;
  object ob;

id(str) { if (!eaten) 
   return str == "potion" || str == "invuln";
   return 0;
}
short() { if (!eaten)
  return "A potion of Invulnrability";
   return 0;
}
long() {  
  write("A small flask filled with a strange blue liquid.  This is\n"+
  "a potion of Invulnrability.  This fluid will make you invincible\n"+
  "for a short amount of time.\n");
   return 1;
}
get() { return 1; }

drop() { if (!eaten) return 0;
   return 1;
}

reset(arg) {
   if (!arg) 
   {
      eaten = 0;
      num = 0;
   }
}
init() {
 add_action("drink","drink");
}

drink(str) {
   if (eaten)
   return 0;
   if (!str)
   return 0;
   str = lower_case(str);
   if (str == "potion" || str == "potion of invulnrability") {
      eaten = 1;
 write("You uncork the flask and quaff its conents.  Suddenly\n"+
  "you feel very confident and secure.  Your ego is roughly the\n"+
  "size of Montana.  You think someone could drop a house on you\n"+
  "and it wouldn't even tickle!  ...well maybe a little bit...\n");
     ob = clone_object("players/pavlik/closed/stuff/invuln.c");
       ob->shadow_target(this_player());
         call_out("ridit", 40);
      return 1;
   }
   return 0;
}

ridit() {
   write("You feel the potion's effects wear off and you suddenly\n"+
    "realize that you are once again nothing but a mere mortal.\n");
     ob->remove_target();
    destruct(this_object());
   move_object(ob, "/players/pavlik/rooms/dungeon.c");
  return 1;
}
query_value() { return 10; }
