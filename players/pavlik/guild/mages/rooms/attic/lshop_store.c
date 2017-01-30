#define ME capitalize(this_player()->query_name())
#define MAX_LIST 15

int x,asn_no_save,value;
int times_more;
int we_is_ok;
object list_no;
string save_str, name_of_item;

short() {
  return "Myla's Secret Supply Room";
}

init() {
   add_action("south"); add_verb("south");
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
      if (!present("topaz ring")) {
         move_object(clone_object("players/pavlik/armor/ilstkarn_ring"),
         this_object());
      }
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
      write("["+arg+"]"+"  " + value*2 + ":\t"+ call_other(ob, "short") + ".\n");
   }
}

value(item) {
   name_of_item = present(item);
   if (!name_of_item) {
      return 0;
   }
   value = call_other(name_of_item, "query_value", 0);
  if(!value){
  write("Myla says: That ain't worth squat.\n");
  return 0;
   }
  write("Myla says:  That would cost, oh ...about "+
        value*2+" gold coins.\n"+
        "Myla smiles at you.\n");
   return 1;
}

buy(item) {
  string itname;
   int new;
   name_of_item = present(item);
   if (!name_of_item && sscanf(item, "%d", new) == 1) {
      sscanf(item, "%d", new);
      name_of_item = list_no[new];
   }
   if (!name_of_item) {
    write("Myla says: I'm not selling any "+item+"!\n");
      return;
   }
   value = call_other(name_of_item, "query_value", 0);
   if (!value) {
    write("Myla says: Honey, that ain't worth squat.\n");
      return;
   }
   value = 11*value/6;
   if (call_other(this_player(), "query_money", 0) < value) {
    write("Myla says: Sorry honey, but you don't have enough cash\n");
    write("Myla tries not to look too put out with you.\n");
      return;
   }
   if (!call_other(this_player(), "add_weight",
            call_other(name_of_item, "query_weight"))) {
     write("Myla says: Sorry child, but you couldn't carry this "+
          "if I sold it to you.\n");
     write("Myla tries to stiffle some giggles.\n");
      return;
   }
   itname = call_other(name_of_item, "query_short", 0);
   call_other(this_player(), "add_money", 0 - value);
   move_object(name_of_item, this_player());
   write("Myla asks "+6*value/5+" gold coins for the "+item+".\n");
   write("You offer "+value+" and not a penny more!\n");
   write("Myla gives in, none to graciously, and shakes on the deal.\n");
   write("You buy the "+item+" for "+value+" gold coins.\n");
   say(ME+" buys a "+item+" from Myla.\n");
}

south() {
   call_other(this_player(), "move_player", "leaves#players/pavlik/guild/mages/rooms/lil_shop");
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
