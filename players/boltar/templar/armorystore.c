#define MAX_LIST 15

int x,asn_no_save,value;
int invdagger,invchainmail,invsword,invlongsword;
int invaxe,invbow,invarr;
int noout;
int invplatemail,invhelmet,invshield;
int invarrm,invarra;
int times_more;
int we_is_ok;
object list_no;
string save_str, name_of_item;

short() {
   return "store room for the shop";
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
   if(noout) return;
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
   if(!present(name_of_item) && new) {
     write("Sorry there is nothing listed under that number.\n");
     return 1;
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
   invdagger=0;invchainmail=0;invsword=0;invlongsword=0;
   invplatemail=0;invhelmet=0;invshield=0;
   invaxe=0;
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
fill()
{
    if (!present("dagger") && invdagger < 12) {
        object dagger;
       invdagger += 1;
        dagger = clone_object("obj/weapon");
        call_other(dagger, "set_name", "a dagger");
        call_other(dagger, "set_class", 6);
        call_other(dagger, "set_weight", 2);
        call_other(dagger, "set_value", 12);
        call_other(dagger, "set_alt_name", "knife");
        call_other(dagger, "set_alias", "dagger");
        call_other(dagger, "set_short", "a dagger");
        call_other(dagger, "set_long", "a plain dagger\n");
        move_object(dagger, this_object());
    }
    if(!present("steel arrows") && invarr < 12) {
      object ar;
      invarr += 1;
      ar=clone_object("players/boltar/templar/items/arrows");
      ar->set_num_ar(24);
      ar->set_recover(68);
      ar->set_arrow_str(14);
      ar->set_type("steel arrows");
      ar->set_value(430);
      ar->set_short("Carbon steel tiped arrows");
      ar->set_long("These arrows are of high quality.\n");
      move_object(ar,this_object());
     }
    if(!present("stone arrows") && invarra < 12) {
      object ara;
      invarra += 1;
      ara=clone_object("players/boltar/templar/items/arrows");
      ara->set_num_ar(50);
      ara->set_arrow_str(10);
      ara->set_recover(50);
      ara->set_value(500);
      ara->set_type("stone arrows");
      ara->set_short("Stone tiped arrows");
      ara->set_long("These arrows are of quality.\n");
      move_object(ara,this_object());
     }
    if(!present("magic arrows") && invarrm < 4) {
      object arm;
      invarrm += 1;
      arm=clone_object("players/boltar/templar/items/arrows");
      arm->set_num_ar(6);
      arm->set_arrow_str(16);
      arm->set_value(350);
      arm->set_recover(72);
      arm->set_short("Magic Fire Arrows");
      arm->set_long("These arrows are of a very magical quality.\n");
      arm->set_type("magic arrows");
      move_object(arm,this_object());
     }
   if(!present("bow") && invbow < 12) {
     invbow += 1;
     move_object(clone_object("players/boltar/templar/items/bow"), this_object());
   }
     if(!present("axe") && invaxe < 12) {
       object axe;
       invaxe += 1;
       axe = clone_object("obj/weapon");
       axe->set_name("axe");
       axe->set_class(16);
       axe->set_weight(3);
       axe->set_value(290);
       axe->set_alt_name("weapon");
       axe->set_alias("battle axe");
       axe->set_short("A large battle axe");
       axe->set_long("A large battle axe with a decorated blade.\n");
       move_object(axe,this_object());
    }
    if (!present("sword") && invsword < 12) {
        object sword;
        invsword += 1;
        sword = clone_object("obj/weapon");
        call_other(sword, "set_name", "sword");
        sword->set_short("A Templar Sword");
        call_other(sword, "set_class", 16);
        call_other(sword, "set_weight", 3);
        call_other(sword, "set_value", 530);
        call_other(sword, "set_alt_name", "weapon");
        call_other(sword, "set_alias", "sword");
        call_other(sword, "set_long", "A Sword decorated with the carvings of the Templars\n");
        move_object(sword, this_object());
    }
    if (!present("longsword") && invlongsword < 12) {
        object longsword;
        invlongsword += 1;
        longsword = clone_object("obj/weapon");
        call_other(longsword, "set_name", "longsword");
        call_other(longsword, "set_class", 17);
        call_other(longsword, "set_weight", 3);
        call_other(longsword, "set_value", 1432);
        call_other(longsword, "set_alt_name", "weapon");
        call_other(longsword, "set_alias", "sword");
        call_other(longsword, "set_short", "A Templar longsword");
        call_other(longsword, "set_long", "A longsword decorated in the manner of the Templars\n");
        move_object(longsword, this_object());
    }
    if (!present("chainmail") && invchainmail < 12) {
        object chainmail;
        invchainmail += 1;
        chainmail = clone_object("obj/armor");
        call_other(chainmail, "set_name", "chainmail");
        call_other(chainmail, "set_ac", 3);
        call_other(chainmail, "set_weight", 4);
        call_other(chainmail, "set_value", 500);
        call_other(chainmail, "set_alias", "armor");
        call_other(chainmail, "set_type", "armor");
        call_other(chainmail, "set_short", "a suit of white chainmail");
        call_other(chainmail, "set_long", "a suit of white Templar chainmail\n");
        move_object(chainmail, this_object());
    }
    if (!present("platemail") && invplatemail < 12) {
        object platemail;
        invplatemail += 1;
        platemail = clone_object("obj/armor");
        call_other(platemail, "set_name", "platemail");
        call_other(platemail, "set_ac", 4);
        call_other(platemail, "set_weight", 7);
        call_other(platemail, "set_value", 1809);
        call_other(platemail, "set_alias", "armor");
        call_other(platemail, "set_type", "armor");
        call_other(platemail, "set_short", "a suit of white platemail");
        call_other(platemail, "set_long", "a suit of white Templar platemail\n");
        move_object(platemail, this_object());
    }
    if (!present("shield") && invshield < 12) {
        object shield;
        invshield += 1;
        shield = clone_object("obj/armor");
        call_other(shield, "set_name", "shield");
        call_other(shield, "set_ac", 1);
        call_other(shield, "set_weight", 3);
        call_other(shield, "set_value", 300);
        call_other(shield, "set_alias", "shield");
        call_other(shield, "set_type", "shield");
        call_other(shield, "set_short", "a white shield with a red cross");
        call_other(shield, "set_long", "a white shield with the red Templar Cross\n");
        move_object(shield, this_object());
    }
    if (!present("helmet") && invhelmet < 12) {
        object helmet;
        invhelmet +=1;
        helmet = clone_object("obj/armor");
        call_other(helmet, "set_name", "metal helmet");
        call_other(helmet, "set_ac", 1);
        call_other(helmet, "set_weight", 3);
        call_other(helmet, "set_value", 300);
        call_other(helmet, "set_alias", "helmet");
        call_other(helmet, "set_type", "helmet");
        call_other(helmet, "set_short", "a white metal helmet");
        call_other(helmet, "set_long", "a white metal helmet\n");
        move_object(helmet, this_object());
    }
/*
noout = 1;
inventory();
noout = 0;
*/
}

