string direction;
object partner_door;
string key_code;
string key_type;
string door_long;
string door_room;
int can_lock, is_locked, is_closed;
/* Added for existing compatibility */
int is_pickable;

query_dir() { return direction;}
query_locked() { return is_locked; }
query_closed() { return is_closed; }

set_dir(str) { direction = str;}
set_code(str) { key_code = str;}
set_type(str) { key_type = str;}
set_door(obj) { partner_door = obj;}
/* Added to stay compatible with existing door.c */
set_pickable(arg) { if(intp(arg)) is_pickable=arg; }
set_door_room(str) { door_room = str; }

set_closed(val) {
   if (is_closed != val && environment()) {
      tell_room(environment(this_object()), "The " + direction + " door ");
   if (val)
      tell_room(environment(this_object()), "closes.\n");
   else
      tell_room(environment(this_object()), "opens.\n");
   }
   is_closed = val;
}

set_locked( val) {
   if (is_locked != val)
      door_sound("Click!");
   is_locked = val;
}

set_can_lock(val) { can_lock = val; }

set_both_status() {
   if (!partner_door)
      return;
   partner_door->set_closed(is_closed);
   partner_door->set_locked(is_locked);
   partner_door->set_can_lock(can_lock);
   partner_door->set_type(key_type);
   partner_door->set_code(key_code);
   partner_door->set_door_long(door_long);
   /* Added for existing door compatibility */
   partner_door->set_pickable(is_pickable);
}

set_door_long(str) {
   door_long = str;
}

set_all(str) {
   if (!str)
      return 0;
   if (sscanf(str, "%s %s %s %s %d %d %d", door_room, direction, key_type,
            key_code, is_closed, is_locked, can_lock) == 7 ) {
      if(key_type == "0")
         key_type = 0;
      move_object(this_object(), door_room);
      return 1;
   }
   return 0;
}

query_room() {
   return door_room;
}

player_enters(str) {
   tell_room(environment(this_object()), str + " enters through the " +
      direction + " door.\n");
}

door_sound(str) {
   if (environment())
      tell_room(environment(this_object()),
      str + " is heard from the " + direction + " door.\n");
}

both_door_sound(str) {
   door_sound(str);
   if (partner_door)
      partner_door->door_sound(str);
}

short() {
   string str;
   if (is_closed)
      str = " ( closed )";
   else
      str = " ( open )";
   return "A door to the " + direction + str;
}

long() {
   string str;
   int rnd;
   write(door_long);
   if (key_type)
      write("On the door there is a " + key_type + " lock.\n");
   if (is_closed)
      str = "closed.\n";
   else
      str = "open.\n";
   write("The door is " + str);
}

id(str) {
   return str == "door"
   || str == direction + " door"
   || str == "H_door";
}

init() {
   if (direction) {
      add_action("go_door", direction);
   }
   add_action("go", "go");
   add_action("close", "close");
   add_action("open", "open");
   if (can_lock) {
      add_action("lock", "lock");
      add_action("unlock", "unlock");
   }
}

go(str) {
   int tmp;
   if (!str)
      return 0;
   tmp = this_door(str);
   if (tmp==2) {
      go_door();
      return 1;
   }
   return tmp == 1;
}

open(str) {
   int tmp;
   if (!str)
      return 0;
   tmp = this_door(str);
   if (tmp==2) {
      open_door();
      return 1;
   }
   return tmp == 1;
}

close(str) {
   int tmp;
   if (!str)
      return 0;
   tmp = this_door(str);
   if (tmp==2) {
      close_door();
      return 1;
   }
   return tmp == 1;
}

unlock(str) {
   object ob;
   int tmp;
   string type, door;
   
   if (!str)
      return 0;
   if (str == "door") {
      write("Unlock the door with what?\n");
      return 1;
   }
   if (sscanf(str, "%s with %s", door, type) == 2) {
      tmp = this_door(door);
      if (tmp != 2)
         return tmp;
      if (this_key(type)==2)
         unlock_door(get_lock(type));
      return 1;
   }
}

lock(str) {
   object ob;
   int tmp;
   string type, door;
   
   if (!str)
   return 0;
   if (str == "door") {
      write("Lock the door with what?\n");
      return 1;
   }
   if (sscanf(str, "%s with %s", door, type) == 2) {
      tmp = this_door(door);
      if (tmp !=2)
         return tmp;
      if (this_key(type)==2)
         lock_door(get_lock(type));
      return 1;
   }
}

/* this_door(str) tests if the argument str refers to this door.
   Return values: 0 => str not referring to a door
1 => refers to a door, but there is more than one
2 => this door
*/

this_door(str) {
   if (!str)
      return 0;
   
   if (str == "door") {
      if (!present("H_door 2", environment()))
         return 2;
      which_door();
      return 1;
   }
   if (direction && str == direction+" door")
      return 2;
   return 0;
}

this_key(str) {
   string type;
   
   if (!str)
      return 0;
   
   if (str=="key") {
      if (present("key", this_player()))
         if (present("key 2", this_player()))
         which_key();
      else
         return 2;
      else
         write("You haven't got a key!\n");
      return 1;
   }
   if (sscanf(str, "%s key", type) == 1) {
      if (present(type+" key", this_player()))
         return 2;
      write("You haven't got such a key!\n");
      return 1;
   }
   return 0;
}

open_door() {
   string str;
   int tmp;
   
   if (! is_closed) {
      write("But why? It's already open!\n");
      return;
   }
   
   if (is_locked)
      write("You can't open the " + direction + " door, it's locked!\n");
   else  {
      write("You open the " + direction + " door.\n");
      set_closed( 0);
      if (partner_door)
         partner_door->set_closed(is_closed);
   }
}

close_door() {
   string str;
   int tmp;
   
   if (is_closed) {
      write("But why? It's already closed!\n");
      return;
   }
   if (is_locked)
      write("You can't close the " + direction + " door, it's locked!\n");
   else {
      write("You close the " + direction + " door.\n");
      set_closed(1);
      if (partner_door)
         partner_door->set_closed(is_closed);
   }
}

lock_door(key) {
   string str;
   int tmp;
   
   if (is_locked) {
      write("But why? It's already locked!\n");
      return;
   }
   if (key)
      str = key->query_code();
   
/* Added is_pickable for compatibility */
   if ((str == key_code) || (str == "zap" && is_pickable)) {
      write("\nYou lock the " + direction + " door.\n");
      set_locked(1);
      if (partner_door)
         partner_door->set_locked(is_locked);
   }
   else
      write("The key doesn't fit!\n");
}

unlock_door(key) {
   string str;
   
   if (!is_locked) {
      write("But why? It's already unlocked!\n");
      return;
   }
   
   if (key)
      str = key->query_code();
   
   if ((str == key_code) || (str == "zap")) {
      write("You unlock the " + direction + " door.\n");
      set_locked(0);
      if (partner_door)
         partner_door->set_locked(is_locked);
   }
   else
      write("The key doesn't fit!\n");
}

go_door() {
   string str;
   
   if (is_closed) {
      write("You can't do that, the door is closed.\n");
      return 1;
   }
   if (partner_door) {
      str = this_player()->query_name();
      partner_door->player_enters(str);
      write("You go through the " + direction + " door.\n");
      this_player()->move_player(direction+"#"+partner_door->query_room());
   }
   else
      return 0;
   return 1;
}

which_door() {
   object ob;
   int i;
   string str, tmp;
   
   /* Note: this function is called only if present("H_door 2") */
      
   str="Which door do you nean";
   tmp=direction;
   
   for(i=2; ; i++) {
      ob = present("H_door "+i);
      if (!ob)
         break;
      str += ", the " + tmp + " door";
      tmp = ob->query_dir();
   }
   write(str + " or the " + tmp + " door.\n");
}

number_of_keys() {
   object ob;
   int num_key;
   
   num_key = 0;
   
   ob = first_inventory(this_player());
   while(ob) {
      if (call_other(ob, "id", "key"))
         num_key++;
      ob = next_inventory(ob);
   }
   return num_key;
}

which_key() {
   object ob;
   int i;
   string str, tmp;
   
   str = "Which key do you mean";
   tmp = 0;
   
   for(i=1; ; i++) {
      ob = present("key "+i, this_player());
      if (!ob)
         break;
      if (tmp)
         str += ", the " + tmp + " key";
      tmp = ob->query_type();
      if (!tmp)
         tmp="";
   }
   write(str+ " or the " + tmp + " key.\n");
}

get_lock(type) {
   object ob;
   int num_key;
   int tmp_num;
   string str;
   string k_type;
   
   if (sscanf(type, "%s key", k_type) != 1)
      k_type = 0;
   
   tmp_num = 0;
   
   ob = first_inventory(this_player());
   while(ob) {
      if (ob->id("key")) {
         str = ob->query_type();
         
         if ((str==k_type) || (! k_type))
            return ob;
         }
      ob = next_inventory(ob);
   }
}

clean_up(arg) {
   if (arg || environment())
      return;
   destruct(this_object());
}
