#define MAX_LIST 15

int x,asn_no_save,value;
int times_more;
int we_is_ok;
object list_no;
string save_str, name_of_item;

short() {
   return "store room for the shop";
}

init() {
   add_action("south","south");
}

inventory(str)
{
   object ob;
   object inv_arr;
   int how_full;
   int asn_no,max;
   if (str !="cont") {
   list_no = allocate(500);
   inv_arr = allocate(500);
   }
   if (!str)
      str = "all";
   asn_no = 1;
   we_is_ok = 1;
   inv_arr = all_inventory(this_object());
   how_full=sizeof(inv_arr)-1;
   if (how_full > 495)
      {
      stop_overflow();
      inv_arr = all_inventory(this_object());
      how_full = size_of(inv_arr) -1;
   }
   if(str == "cont"){
      how_full = times_more;
      str = save_str;
      asn_no = asn_no_save;
   }
   save_str = str;
   times_more = how_full;
   while (times_more >=0) {
      max = MAX_LIST;
      while(how_full >= 0 && max > 0) {
         list_no[asn_no] = inv_arr[how_full];
         ob = inv_arr[how_full];
         if (str == "all") {
            list(ob,asn_no);
            max-=1;
            }
         if (str == "weapons" && call_other(ob, "weapon_class", 0)) {
            list(ob,asn_no);
            max-=1;
            }
         if (str == "armors" && call_other(ob, "armor_class", 0)) {
            list(ob,asn_no);
            max-=1;
            }
         asn_no += 1;
         how_full -=1;
         }
      times_more = how_full;
      if (max > 0)
         times_more=-1;
      if (times_more >=0)
         {
         asn_no_save = asn_no;
         write("Continue listing? [y]: ");
         input_to("list_more");
         return;
         }
   }
}

list(ob,arg)
{
   int value;
   value = call_other(ob, "query_value", 0);
   if (value) {
      write("["+arg+"]"+"  " + value*11/5 + ":\t"+ call_other(ob, "short") + ".\n");
      /*
      write(list_no[arg]);
      write("\n");
      */
   }
}

value(item) {
   name_of_item = present(item);
   if (!name_of_item) {
      return 0;
   }
   value = call_other(name_of_item, "query_value", 0);
   if (!value) {
      return 0;
   }
   write("The "); write(item); write(" would cost you ");
   write(value*11/5); write(" gold coins.\n");
   return 1;
}

buy(item) {
   int new;
   name_of_item = present(item);
   if (!name_of_item && sscanf(item, "%d", new) == 1) {
      sscanf(item, "%d", new);
      name_of_item = list_no[new];
   }
   if (!name_of_item) {
      write("No such item in the store.\n");
      return;
   }
   value = call_other(name_of_item, "query_value", 0);
   if (!value) {
      write("Item has no value.\n");
      return;
   }
   value = 11*value/5;
   if (call_other(this_player(), "query_money", 0) < value) {
      write("It would cost you ");
      write(value); write(" gold coins, which you don't have.\n");
      return;
   }
   if (!call_other(this_player(), "add_weight",
            call_other(name_of_item, "query_weight"))) {
      write("You can't carry that much.\n");
      return;
   }
   call_other(this_player(), "add_money", 0 - value);
   move_object(name_of_item, this_player());
   write("Ok.\n");
   say(call_other(this_player(), "query_name") + " buys " + call_other(name_of_item, "short", 0) + ".\n");
}

south() {
   call_other(this_player(), "move_player", "leaves#room/shop");
   return 1;
}

heart_beat()
{
   object ob, next_ob;
   ob = first_inventory(this_object());
   while(ob) {
      next_ob = next_inventory(ob);
      destruct(ob);
      ob = next_ob;
   }
}

reset(arg) {
   if (!arg)
      set_light(1);
   if (!present("torch")) {
      object torch;
      torch = clone_object("obj/torch");
      call_other(torch, "set_name", "torch");
      call_other(torch, "set_fuel", 2000);
      call_other(torch, "set_weight", 1);
      move_object(torch, this_object());
   }
   if(!we_is_ok)
      inventory("all");
}

long()
{
   write("All things from the shop are stored here.\n");
}

store(item)
{
   string short_desc;
   object ob;
   
   short_desc = call_other(item, "short");
   ob = first_inventory(this_object());
   while(ob) {
      if (call_other(ob, "short") == short_desc) {
         /* Move it before destruct, because the weight
         has already been compensated for. */
         move_object(item, this_object());
         destruct(item);
         return;
         }
      ob = next_inventory(ob);
   }
   move_object(item, this_object());
}
static list_more(str) {
   write("\n");
   if(str =="n")
      times_more = -1;
   if (str == "y" || str == "");
   call_other(this_object(), "inventory", "cont");
   return;
}
stop_overflow(){
   int t;
   t=1;
   while(t < 50){
      destruct(list_no[t]);
      t += 1;
   }
   return;
}
/*
many mods done by boltar (petebre@elof.iit.edu)
improved store room version #1.1
*/
check_yyy(){
    int yyy;
   while (yyy < 20) {
    write (list_no[yyy]);
    write ("\n");
    yyy += 1;
  }
return 1;
}
