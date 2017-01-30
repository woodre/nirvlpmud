#define DATA_FILE "/players/blue/closed/store/storage_file"
#define TR(x) tell_room(environment(this_object()), x);
#define ERROR_FILE "/players/blue/closed/store/errors"
#define TP this_player()
#define DEST "/players/blue/workroom.c"

int busy;

id(str) { return str == "storage" || str == "desk" || str == "desk-ob"; }
short() { 
   object clerk;
   clerk = present("clerk_ob", environment(this_object()));
   if(!clerk || clerk->query_attack()) return "An empty desk";
    return "Dread Clerk, sitting in his desk";
}

long() { 
   write("This is where you can store your items.\n");
}

reset(arg) {
   if(arg) return;
   
   busy = 0;

}

init() {
   add_action("start_restore_object","restore");
   add_action("start_storage","store");
}

get_size(file_name) {
   int size;
   if(!file_name) file_name = DATA_FILE;
   size = sizeof(explode(read_file(file_name), "\n"));
   return size;
}

is_my_line(name, line) {
   string tmp1, tmp2;
    if(sscanf(line, "%s@%s", tmp1, tmp2) == 2 && tmp1 == name)
      return 1;
   return 0;
}

log_error(error) {
   write_file(ERROR_FILE, ctime(time())+" "+error+"\n");
}

current_items_stored(name) {
   string line;
   int current_line, n, size;
   size = get_size(0);
   if(size < 1) {
      log_error("File size < 1");
      return -1;
   }
   current_line = 1;
   n = 0;
   while(current_line <= size) {
      line = read_file(DATA_FILE, current_line);
      if(is_my_line(name, line))
         n+=1;
      current_line += 1;
   }
   return n;
}

get_line_number(name) {
   string line;
   int current_line, size;
   size = get_size(0);
   if(size < 1) {
      log_error("File size < 1");
      return -1;
   }
   current_line = 1;
   while(current_line <= size) {
      line = read_file(DATA_FILE, current_line);
      if(is_my_line(name, line))
        return current_line;
      current_line += 1;
   }
   return 0;
}

remove_line(num) {
   int size;
   string prechunk, postchunk;
   size = get_size(0);
   if(num != 1 && num != size) {

      prechunk = read_file(DATA_FILE, 1, num - 1);
      postchunk = read_file(DATA_FILE, num +1, size);
      size -= sizeof(explode(prechunk, "\n"));
      size -= sizeof(explode(postchunk, "\n"));
      if(size != 1) {
         log_error("Error in removing line");
         return 0;
      }
      rm(DATA_FILE);
      write_file(DATA_FILE, prechunk);
      write_file(DATA_FILE, postchunk);
      return 1;
   }
   if(num == 1) {
      postchunk = read_file(DATA_FILE, 2, size);
      size -= sizeof(explode(postchunk, "\n"));
       if(size != 1) {
         log_error("Error in removing line");
         return 0;
      }
      rm(DATA_FILE);
      write_file(DATA_FILE, postchunk);
      return 1;
   }
   if(num == size) {
      prechunk = read_file(DATA_FILE, 1, size - 1);
      size -= sizeof(explode(prechunk, "\n"));
       if(size != 1) {
         log_error("Error in removing line");
         return 0;
      }
      rm(DATA_FILE);
      write_file(DATA_FILE, prechunk);
      return 1;
   }
   return 0;                    /*## should not get here  ##*/
}

verify_file(filename) {
   if(file_size(filename) < 0)
      return 0;
   return 1;
}

valid_object(ob) {
   if(ob->query_save_flag())
      return 0;
   return 1;
}

make_object(file) {
   object ob;
 /*
   if(verify_file(file) == 0) {
      return -1;
   }
   */
   ob = clone_object(file);
   if(!valid_object(ob)) {
      destruct(ob);
      return 0;
   }
   move_object(ob, TP);
   write("Dread Clerk gives you: "+ob->short()+"\n");
   say("Dread Clerk gives "+capitalize(TP->query_name())+": "+ob->short()+"\n");
   return 1;
}

get_file(mess) {
   string tmp1, tmp2, file;
   if(sscanf(mess, "%s@%s:%s$", tmp1, tmp2, file)  != 3) return 0;
   return file;
}
   
start_restore_object(how) {
   int num, tmp, line_number;
   string line, name, file;
   if(busy) return 1;
   busy = 1;
   if(!present("clerk", environment(TP))) {
      busy = 0;
      return 0;
   }
   name = this_player()->query_real_name();
   num = current_items_stored(name);
   if(num == -1) {
      busy = 0;
      return 1;
   }
   if(num== 0) {
     TR("Dread Clerk says: 'Hmmm...I don't have anything of yours in here.'\n");
      busy = 0;
     return 1;
   }
   tell_object(TP, "Dread Clerk tells you: 'Ok...you have "+num+" items "+
      "stored here.'\n");
   while(num > 0) { 
       line_number = get_line_number(name);
      line = read_file(DATA_FILE, line_number);
      if(!line) {
         log_error("No line found in start_restore_object");
         TR("Dread Clerk gets confused.\n");
         busy = 0;
         return 1;
      }
      if(!remove_line(line_number)) {
         log_error("Couldn't remove line "+line_number+".\n");
         TR("Dread Clerk gets confused.\n");
         busy = 0;
         return 1;
      }
      file = get_file(line);
      if(file == "0") {
         log_error("No file found in "+line+".\n");
         TR("Dread Clerk gets confused.\n");
         busy = 0;
         return 1;
      }
      tmp = make_object(file);
      if(tmp == -1 ) {
         TR("Dread Clerk says: 'Hmmm...thats not here anymore.'\n");
         busy = 0;
         return 1;
      }
      if(tmp == 0) {
        TR("Dread Clerk says: 'That object can no longer be saved.'\n");
         busy = 0;
         return 1;
      }
      num -= 1;
   }
   write("Done.\n");
   busy = 0;
   return 1; 
}

start_storage(item) {
   object ob;
   string name, dummy;
   int number, max;
   if(busy) return 1;
   if(!item) {
      tell_object(TP, "Dread Clerk tells you: Dah?!?! Store what?\n");
      return 1;
   }
   busy = 1;
   name = this_player()->query_real_name();
   number = current_items_stored(name);
   max = get_max_storage(TP);
   if(number >= max) {
      TR("Dread Clerk says: 'You can't store that many items.'\n");
      busy = 0;
      return 1;
   }
   ob = present(item, TP);
   if(!ob) {
      TR("Dread Clerk examines you carefully.\n");
      TR("Dread Clerk says: 'You don't have one of those.\n");
      busy = 0;
      return 1;
   }
   if(ob->query_save_flag() || !ob->get() || ob->drop()) {
     TR("Dread Clerk says: 'That can't be stored.'\n");
     busy = 0;
      return 1;
   }
   if(sscanf(file_name(ob), "obj/%s", dummy)) {
      TR("Dread Clerk says: That cannot be stored.\n");
      busy = 0;
      return 1;
   }
   if(!store_object(ob, name)) {
      TR("Dread Clerk gets confused.\n");
      busy = 0;
      return 1;
   }
   TR("Dread Clerk says: 'Okie Dokie!'\n");
   busy = 0;
   return 1;
}

store_object(ob, name) {
   string file;
   int dummy;
   if(sscanf(file_name(ob), "%s#%d", file, dummy) !=2) return 0;
   write_file(DATA_FILE, name+"@"+time()+":/"+file+".c$\n");
   TP->add_weight(-1 * (ob->query_weight()));
   TR(capitalize(TP->query_name())+ " gives Dread Clerk: "+ob->short()+"\n");
   TR("Dread Clerk quickly stuffs "+ob->short()+" into his desk.\n");
   destruct(ob);
   return 1;
}

int get_max_storage(object player) {
   return 6;
}


no_busy() {
   busy = 0;
   return 1;
}
