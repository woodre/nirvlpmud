/* pet.c: slave object for logger guild pets        */
/* Whee, Nirvana: get ready for daemonized pets     */
#define MASTER "/players/wizardchild/closed/logger/masterob.c"
#define CP(s)  capitalize(s)
#define LWR(s) lower_case(s)
#define ROOT "players/wizardchild/closed/logger/"
static status follow, fight, protect, stable, loaded;
static string owner, myname, type;
inherit "obj/monster";
id(str) { return str == myname || str == "pet" || str == type;  }
short() { return CP(owner)+"'s "+CP(type)+" named "+CP(myname); }
long()  {
  short();
  cat(ROOT+type);
  if(this_player()->query_real_name() == owner)
    write("Type \"lhelp pets\" and \"lhelp pets2\" for more info.\n");
  return 1;
}
query_myname()  { return myname;  }
query_fight()   { return fight;   }
query_follow()  { return follow;  }
query_owner()   { return owner;   }
query_protect() { return protect; }
query_stable()  { return stable;  }
query_type()    { return type;    }
 
set_stable(x)  { stable = x;       }
set_owner(str) { owner = LWR(str); }
set_myname(st) { myname = LWR(st); }
set_type(str)  { type = LWR(str);  }
set_protect(x) { protect = x;      }
set_follow(x)  { follow = x;       }
set_fight(x)   { fight = x;        }
is_pet()       { return 1;         }
 
reset(arg) {
  if(arg) return 0;
  ::reset(arg);
  type = "duck";
  myname = owner = "nobody";
  follow = fight = 0;
  loaded = 0;
  call_out("delayed_reset", 3);
}
delayed_reset() {
  if(!owner && loaded)
    destruct(this_object());
  else if(!owner) {
    loaded = 1;
    call_out("delayed_reset", 3);
  } else
    MASTER->load_pet(find_player(owner));
}
init() {
  if(this_player() && this_player()->query_real_name() == owner) {
    add_action("namepet", "namepet");
    add_action("do_something", myname);
  }
  ::init();
}
namepet(str)      { return MASTER->namepet(str); }
do_something(str) { return MASTER->do_something(str); }
home() { move_object(this_object(), ROOT+"room/pet_room"); }
protect() { call_out("end_it", 12); }
status end_protect;
end_it() {
  object ob;
  if(!present(owner, environment(this_object())) || !query_attack())
    return (set_protect(0));
  if(end_protect)
    set_protect(0);
  else {
    MASTER->stop_pet_protect(this_object());
    end_protect = 1;
    call_out("end_it", 20);
  }
  return 1;
}
 
heart_on()  { set_heart_beat(1); }
heart_off() { set_heart_beat(0); }
heart_beat() {
  fight = (query_attack() ? 1 : 0);
  if(!follow && !fight)
    heart_off();
  if(!find_player(owner))
    destruct(this_object());
  call_out("restart_hb", 4);
  if(follow && !present(owner, environment(this_object())))
    follow_him();
  if(fight && illegal_fight())
    MASTER->end_pet_fight(this_object());
  else if(fight)
    attack();
  ::heart_beat();
  remove_call_out("restart_hb");
}
follow_him() {
  say(CP(myname)+" leaves, following "+CP(owner)+".\n");
  move_object(this_object(), environment(find_player(owner)));
  say(CP(myname)+" arrives following "+CP(owner)+".\n");
}
illegal_fight() {
  object ob;
  ob = query_attack();
  return (ob && (ob->query_attack() == this_object() ||
     query_attack() != find_player(owner)->query_attack()) && !protect);
}
restart_hb() {
  if(find_player(owner)->query_level() > 20)
    tell_object(find_player(owner), "Restarting pet heartbeat.\n");
  heart_on();
}
