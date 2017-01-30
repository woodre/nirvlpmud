
/*
 * Horse.
 * Players can rid horse and have it carry items.
 * Cannot be used to attack!
 * Follow uses a call_out 
 */

#define VERSION "1.5"
#define UPDATE "05/24/94"
query_version() { return VERSION; }
query_update() { return UPDATE; }

/* Valid directions a player ride horse */
#define VALID_DIR ({ "n","north","s","south","e","east","w","west",\
                     "ne","northeast","nw","northwest","se","southeast",\
                     "sw","southwest","in","out","up","u","down","d","enter",\
                     "enter portal","enter castle","leave","lay on bed" })\

#define ALIAS_CMD ({ "n","s","e","w","ne","nw","se","sw","u","d" })
#define REAL_CMD ({ "north","south","east","west","northeast","northwest",\
                    "southeast","southwest","up","down" })

#define notify_fail(A) { write(A+"\n"); return 1; }

#include "/obj/living.h"

#define USER this_player()->query_real_name()
#define OWNER find_player(owner)
#define MAX_WEIGHT 20

/* Interval between follow call_outs */
#define F_INTV 5

/* Make things look nice */
justify(str, len) { return extract(str+"                       ",0,len-1); }

object me, dest, dest2, dead_ob, init_ob, kill_ob;
int mounted;   /* is the horse mounted? */
int led;      
status healing;
string owner, dir;

set_owner(ow) { owner = ow; }

reset(arg) {
   /* set monster's stats */
   name = "horse";
   level = 5;
   weapon_class = 12;
   armor_class = 3;
   set_living_name(name);
   cap_name = capitalize(name);
   alignment = 100;
   enable_commands();
   me = this_object();
   is_npc = 1;
}

id(str) { return str == name || str == "horse"; }

short() {
   if(mounted) 
     return "A black horse ridden by "+capitalize(owner);
   return "A black horse";
}

long() {
   write("A jet black horse owned by "+capitalize(owner)+".\n");
   if(USER == owner)
     write("Type 'horse' for help.\n");
   if(hit_point < max_hp/10) {
     write(cap_name+" is in very bad shape.\n");
     return;
   }
   if(hit_point < max_hp/5) {
     write(cap_name+" is in bad shape.\n");
     return;
   }
   if(hit_point < max_hp/2) {
     write(cap_name+" is not in good shape.\n");
     return;
   }
   if(hit_point < max_hp - 10) {
     write(cap_name+" is slightly hurt.\n");
     return;
   }
   write(cap_name+" is in good shape.\n");
   write("Version: "+query_version()+"  Last Update: "+query_update()+"\n");
}

follow() {
   /* If no owner destruct this object */
   if(!OWNER) {
     move_object(this_object(), "/room/void");
     destruct(this_object());
     return 1;
   }
   if(!led) {
     remove_call_out("follow");
     return 1;
   }
   if(!present(this_object(), environment(OWNER))) {
     move_object(this_object(), environment(OWNER));
     tell_room(environment(OWNER),"A black horse arrives.\n");
   }
   call_out("follow",F_INTV);
   return 1;
}

heart_beat() {
   age += 1;
   already_fight = 0;
   
/* If no owner destruct this object */
   if(!OWNER) {
     move_object(this_object(), "/room/void");
     destruct(this_object());
     return 1;
   }
   if(!test_if_any_here()) {
     if(!healing)
       heal_slowly();
     return;
   }
   if(kill_ob && present(kill_ob, environment(this_object()))) {
     if(random(2) == 1)
       return;
     attack_object(kill_ob);
     kill_ob = 0;
     return;
   }
   attack();
}

heal_slowly() {
   hit_point += 120/(INTERVAL_BETWEEN_HEALING * 2);
   if(hit_point > max_hp)
     hit_point = max_hp;
   healing = 1;
   if(healing < max_hp)
     call_out("heal_slowly", 80);
   else
     healing = 0;
}

can_put_and_get(str) {
   if(!str)
     return 0;
   return 1;
}

init() {
   if(!OWNER) {
     move_object(this_object(), "/room/void");
     destruct(this_object());
     return 1;
   }
   if(this_player() == me)
     return;
   if(this_player() && (USER != owner)) return;
   add_action("jumpstart","jumpstart");
   add_action("setname","setname");
   add_action("mount","mount");
   add_action("dismount","dismount");
   add_action("lead","lead");
   add_action("tie","tie");
   add_action("pack","pack");
   add_action("unpack","unpack");
   add_action("horse","horse");
   add_action("dismiss","dismiss");
   add_action("horsedir","horsedir");
   if(!mounted) return;
   add_action("get","get");
   add_action("speak","say");
   add_action("speak");  add_xverb("'");
   add_action("look","look");
   add_action("look","l");
   add_action("drop","drop");
   add_action("ride"); add_xverb("");
}

setname(str) {
   if(!str) 
     notify_fail("What would you like to name your horse?");
   name = str;
   cap_name = capitalize(name);
   write("You changed your horse's name to: "+capitalize(str)+"\n");
   return 1;
}

jumpstart() {
   write("Your horse seems to liven up a bit.\n");
   set_heart_beat(1); 
   return 1;
}

horse() {
   cat("/players/molasar/rowan/helpdir/H_HELP");
   return 1;
}

/* Allow players to drop items into horse's environment when mounted */
drop(str) {
   object dest, itemob;
   int weight;
   string me, short_str;

   if(!str) 
     notify_fail("Drop what?");
   dest = environment(this_object());
   me = this_player()->query_name();
   if(str == "all") {
     drop_all(this_player());
     return 1;
   }
   itemob = present(str, this_player());
   if(!itemob) 
     notify_fail("You do not have a "+str+".");
   if(itemob->drop()) 
     notify_fail("You can't drop that.");
   weight = itemob->query_weight();
   move_object(itemob, dest);
   this_player()->add_weight(-weight);
   short_str = itemob->short();
   tell_room(dest, me+" drops "+short_str+"\n");
   return 1;
}

/* Allow players to get items from horse's environment when mounted */
get(str) {
   object itemob, dest;
   int weight;
   string me, short_str;

   if(!str) return 0;
   dest = environment(this_object());
   if(str == "all") {
     get_all(dest);
     return 1;
   }
   itemob = present(str, dest);
   if(!itemob) 
     notify_fail("That is not here!");
   if(!itemob->get()) 
     notify_fail("You cannot take that!");
   weight = itemob->query_weight();
   if(!this_player()->add_weight(weight)) 
      notify_fail("That is too heavy!\n");
   me = this_player()->query_name();
   short_str = itemob->short();
   move_object(itemob, this_player());
   this_player()->add_weight(weight);
   tell_room(dest, me+" takes "+short_str+"\n");
   return 1;
}

/* To pack and unpack items */
pack(str) {
   object itemob, pack;
   int weight, space;

   pack = present("horse_pack", this_object());
   if(!pack) {
     pack = clone_object("/players/sandman/paladin/obj/pack");
     move_object(pack, this_object());
   }
   if(!str) {
     object ob;
     ob = first_inventory(pack);
     if(!ob) 
       notify_fail("The horse pack is empty.");
     write("The horse pack contains:\n");
     while(ob) {
       string sh;
       sh = ob->short();
       if(sh)
         write("    "+sh+"\n");
       ob = next_inventory(ob);
     }
     return 1;
   }
   itemob = present(str, this_player());
   if(!itemob) 
     notify_fail("You do not have a "+str+".");
   if(itemob->drop()) 
     notify_fail("You cannot do that.");
   weight = itemob->query_weight();
   space = pack->query_weight();
   if(space + weight > MAX_WEIGHT) 
     notify_fail("There is not enough room.");
   move_object(itemob, pack);
   pack->add_weight(weight);
   this_player()->add_weight(-weight);
   write("Ok.\n");
   return 1;
}

unpack(str) {
   object pack, itemob;
   int weight;

   pack = present("horse_pack", this_object());
   if(!pack) {
     pack = clone_object("/players/sandman/paladin/obj/pack");
     move_object(pack, this_object());
   }
   if(!str)
     notify_fail("What would you like to unpack?");
   itemob = present(str, pack);
   if(!itemob) 
     notify_fail("There is not a "+str+" in the pack.");
   weight = itemob->query_weight();
   if(!this_player()->add_weight(weight)) 
     notify_fail("You cannot carry anymore.");
   this_player()->add_weight(weight);
   pack->add_weight(-weight);
   move_object(itemob, this_player());
   write("You take "+str+" from pack.\n");
   return 1;
}

/* To have the horse follow the owner */
lead(str) {
   if(str && (str != "horse"))
     return;
   if(mounted) 
     notify_fail("You must dismount your horse first.");
   if(led) 
     notify_fail("Your horse is already following you.");
   led = 1;
   write("Your horse will now follow you.\n");
   call_out("follow", F_INTV);
   return 1;
}

/* Get horse to stop following */
tie(str) {
   if(!led) 
     notify_fail("Your horse is already tied off.");
   if(str == "off" || str == "off horse") {
     led = 0;
     write("Your horse is now tied off.\n");
     remove_call_out("follow");
     return 1;
   }
}

/* Get rid of horse */
dismiss(str) {
   if(!str || !id(str))
     return;
   if(mounted) 
     notify_fail("You must dismount first.");
   tell_room(environment(this_object()), capitalize(owner)+" dismisses "+
       find_player(owner)->query_possessive()+" horse.\n");
   write("You dismiss your horse.\n");
   move_object(this_object(), "/room/void");
   destruct(this_object());
   return 1;
}

ride(direction) {
   int i;
   if(member_array(direction, VALID_DIR) != -1) {
     if(member_array(direction, ALIAS_CMD) != -1) {
       for(i=0; i < sizeof(ALIAS_CMD); i++)
          if(direction == ALIAS_CMD[i])
            break;
       direction = REAL_CMD[i];
     }
     command(direction, this_object());
     look();
     return 1;
   }
}

speak(str) {
   dest = environment(this_object());
   tell_room(dest, capitalize(owner)+" says: "+str+"\n");
   write("You say: "+str+"\n");
   return 1;
}

mount(str) {
   if(str && str != id(str)) 
     return 0;
   if(led) 
     notify_fail("You must tie off your horse before you can mount it.");
   if(mounted) 
     notify_fail("You are already mounted on your horse.");
   if(this_player()->query_attack()) 
     notify_fail("You cannot mount your horse while fighting.");
  if(present("efangs",this_player()))
    notify_fail("The horse twists away from you in fear...\n");
   mounted = 1;
   say(capitalize(owner)+" mounts the horse.\n");
   move_object(this_player(), this_object());
   return 1;
}

dismount(str) {
   if(str && str != id(str))
     return 0;
   if(!mounted) 
     notify_fail("You are not mounted on your horse.");
   mounted = 0;
   say(capitalize(owner)+" dismounts from the horse.\n");
   write("You dismount from your horse.\n");
   move_object(this_player(), environment(this_object()));
   return 1;
}

horsedir() {
   int i, cnt;   
   string *tmp_arr;

   tmp_arr = VALID_DIR;
   write("Valid Horse Directions:\n");
   write("[=============================================================]\n");
   cnt = 0;
   for(i=0; i < sizeof(tmp_arr); i++) {   
      write(justify(tmp_arr[i],15));
      cnt += 1;
      if(cnt >= 3) {
        cnt = 0;
        write("\n");
      } else
        write(justify(" ",5));
   }
   if(cnt)
     write("\n");
   write("[=============================================================]\n");   
   return 1;
}


/* Allow player to hear stuff in horse's environment when mounted */
catch_tell(str) {
   if(mounted && OWNER) {
     tell_object(OWNER, str);
     return 1;
   }
}

/* Let's player see whats in the horse's room */
look(str) {
   string item;
   dest = environment(this_object());
   dest2 = environment(this_player());
   if(!str) {
     move_object(this_player(), dest);
     this_player()->look();
     move_object(this_player(), dest2);
     return 1;
   }
   if(sscanf(str, "at %s", item)) {
     move_object(this_player(), dest);
     this_player()->look("at "+item);
     move_object(this_player(), dest2);
     return 1;
   }
   if(sscanf(str, "in %s", item)) {
     move_object(this_player(), dest);
     this_player()->look("in "+item);
     move_object(this_player(), dest2);
     return 1;
   }
}

/* Extra stuff to make things nice */
get_all(from) {
   object ob, next_ob;

   ob = first_inventory(from);
   while(ob) {
     string sh_str;
     next_ob = next_inventory(ob);
     sh_str = ob->short();
       if(sh_str && ob->get()) {
         int weight;
         if(!living(from) || !ob->drop()) {
           if(!call_other(ob, "id", "soul")) {
             weight = ob->query_weight();
             if(find_player(owner)->add_weight(weight)) {
               write(sh_str+": Ok.\n");
               from->add_weight(-weight);
               move_object(ob, find_player(owner));
               tell_room(environment(this_object()), 
                  capitalize(this_player()->query_name())+
                  " takes: "+sh_str+".\n");
               } else {
                  write(sh_str+": Too heavy.\n");
               }
             }
           }
        }
        ob = next_ob;
     }
}

drop_all(from) {
   object ob, next_ob;

   ob = first_inventory(from);
   while(ob) {
     string sh_str;
     next_ob = next_inventory(ob);
     sh_str = ob->short();
     if(sh_str && !ob->drop()) {
       int weight;
       weight = ob->query_weight();
       write(sh_str+": Ok.\n");
       from->add_weight(-weight);
       move_object(ob, environment(this_object()));
       tell_room(environment(this_object()),
           capitalize(this_player()->query_name())+" drops: "+sh_str+".\n");
     }
     ob = next_ob;
   }
}

