#define THIS_FILE "/players/feldegast/junk/loader.c"
#define LOG_FILE "feldegast.autoload"

string autostore;

string extra_look() {
  return environment()->query_name()+" can autoload stuff";
}
int id(string str) {
  return str=="autoloader";
}
string query_auto_load() {
  return THIS_FILE+":"+autostore;
}

void restore_items() {
  object ob;
  string item;
  string item_arg;
  int hits, misses;

  while(sscanf(autostore,"%s\n%s",item,autostore)==2) {
    if(sscanf(item,"%s*%s$%d$%d",item,item_arg,hits,misses)==4) {
      if( catch(ob=clone_object(item)) ) {
        write("Item failed to load.\n");
        log_file(LOG_FILE,ctime(time())+" "+this_player()->query_name()+" "+item+" failed to load.\n");
      }
      else {
        ob->locker_init(item_arg); 
        ob->set_hits(hits); 
        ob->set_misses(misses);
        if(!ob->short()) {
          write("Generic item failed to load.\n");
          destruct(ob);  /* Get rid of generic objects */
        }
        else move_object(ob,this_player());
      }
    }
  }
  this_player()->recalc_carry();
  command("ready",this_player());
}

void reset(int arg) {
  if(arg) return;
}

void init() {
  add_action("cmd_quit","quit");
}

int cmd_quit(string str) {
  object ob;
  object next;
  string file;
  string init_arg;
  int hits, misses;

  autostore="";

  if(this_player()->query_attack()) {
    write("You abandon all of your equipment and flee combat.\n");
    return 0;
  }

  write("Storing inventory...\n");
  ob=first_inventory(this_player());
  while(ob) {
    init_arg=0;
    next=next_inventory(ob);
    if(!ob->query_save_flag() &&
       !ob->generic_object() &&
       ob->get() &&
/*       !ob->drop() && */
       !ob->query_auto_load() &&
       (ob->query_wielded() || ob->query_worn())
    ) {
      init_arg=(string)ob->locker_arg();
      file=file_name(ob);
      sscanf(file,"%s#",file);
      file+="*"+init_arg;
      file+="$"+ob->query_hits()+"$"+ob->query_misses();
      autostore+=file+"\n";
      write(ob->short()+" [stored]\n");
      destruct(ob);
    }
    ob=next;
  }
  write("Items saved.\n");
  return 0;
}

void init_arg(string arg) {
  if(arg && this_player()) {
    autostore=arg;
    restore_items();
  }
}
       
drop() { return 1; }
