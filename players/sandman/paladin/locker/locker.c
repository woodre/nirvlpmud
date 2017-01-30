
/*
 * MASTER WEAPONS LOCKER
 */

#define LPATH "players/sandman/paladin/locker/"
#define NAME this_player()->query_real_name()

int number_of_weapons;

store(str) {
   object weap, new_weap;
   string path, wizard, junk;

   if(!str) {
     write("Usage: store <paladin weapon>\n");
     return 1;
   }
   weap = present(str, this_player());
   if(!weap) {
     write("You do not have a "+str+".\n");
     return 1;
   }
   if (!weap->query_pro_weapon() || shadow( weap, 0)) {
      write( "That is not a true paladin weapon!\n");
      return 1;
   }
   if(weap->query_deny_save()) {
     write("You cannot save this particular weapon.\n");
     return 1;
   }
   if (weap->drop()) {
      write( "You fail to store your weapon.\n");
      return 1;
   }
   sscanf(file_name(weap), "players/%s/%s", wizard, junk);               
   if(wizard != "sandman") {
     weap->save_thing("players/"+wizard+"/pal_locker_tmp");
     destruct(weap);
     new_weap = clone_object("players/sandman/paladin/obj/weapon");
     new_weap->restore_thing("players/"+wizard+"/pal_locker_tmp");
     weap = new_weap;
     move_object(weap, this_player());
   }
   if(!restore_object(LPATH+NAME)) {
     number_of_weapons = 1;
   } else {
     number_of_weapons += 1;
   }
   if(number_of_weapons >= 4) {
     write("You cannot store anymore weapons.\n");
     return 1;
   }
   path = LPATH+NAME+number_of_weapons;
   weap->save_thing(path);
   destruct(weap);
   write("Your weapon has been stored.\n");
   save_file();
   return 1;
}

retrieve() {
   object weap;
   int i, number;
   string path;

   if(!restore_object(LPATH+NAME)) {  
     write("You have no weapons stored in the weapons locker.\n");
     return 1;
   }
   for(i=0; i < number_of_weapons; i++) {
      number = i + 1;
      path = LPATH+NAME+number;
      weap = clone_object("players/sandman/paladin/obj/weapon");
      weap->restore_thing(path);
      if (transfer( weap, this_player())) {
         write( weap->short() + ": Too heavy.\n");
         transfer( weap, previous_object());
      }
      rm("/"+path+".o");
   }   
   rm("/"+LPATH+NAME+".o");
   write("You retrieve your weapons from the locker.\n");
   return 1;
}

list() {
   object weap;
   int i, number;
   string path;

   if(!restore_object(LPATH+NAME)) {  
     write("You have no weapons stored in the weapons locker.\n");
     return 1;
   }
   write("Weapons in your locker:\n");
   weap = clone_object("players/sandman/paladin/obj/weapon");
   for(i=0; i < number_of_weapons; i++) {
      number = i + 1;
      path = LPATH+NAME+number;
      weap->restore_thing(path);
      write("     "); write(weap->short()+"\n");
   }   
   destruct(weap);
   return 1;
}

save_file() {
   save_object(LPATH+NAME);
   number_of_weapons = 0;
}

