#include "/players/grimm/closed/mall/truck/truck.h"
#define CN capitalize(owner->query_real_name())
inherit "/obj/treasure";
object truck, owner, dead_truck;
int timer, coolant;
 
reset(arg) {
  if(arg) return;
  set_value(0);
  set_weight(0);
  set_short("Monster Truck Remote Control");
  set_long("This is a monster truck remote control.  Type \"help truck\"\n"+
           "for a list of its commands.\n");
  set_alias("remote");
  timer=time()+1;
  coolant=time()+300;
  set_heart_beat(1);
}
 
heart_beat() {
  if(coolant<time()) {
    coolant=time();
    truck->add_hits(-10);
    if(truck->query_hits()<1) {
      tell_object(owner,"Your truck blows up from overheating!\n");
      tell_room(truck,CN+"'s truck explodes from overheating!\n");
      tell_room(owner,CN+"'s truck explodes from overheating!\n");
      tell_object(owner,"GAME OVER.\n");
      dead_truck=clone_object("/players/grimm/closed/mall/truck/dead_truck");
      dead_truck->set_nme("The remains of "+CN+"'s truck");
      move_object(dead_truck,truck);
      destruct(truck);
      destruct(this_object());
      return 1;
    } else {
      tell_object(owner,"Your truck is out of coolant!  It is overheating.\n");
    }
  }
  if(!environment(owner)->im_daemons()) {
    tell_object(owner,"You are not allowed to leave the room with the"+
                " remote.\nDaemons comes and takes it away from you.\n");
    destruct(truck);
    destruct(this_object());
    return 1;
  }
  move_object(this_object(),owner);
  if(timer<time()) {
    tell_room(truck,CN+"'s truck explodes.\n");
    tell_object(owner,"Your time runs up for the race.  "+
                "Daemon comes and takes away the remote.\n");
    tell_room(owner,CN+"'s time runs up for the race.\n");
    destruct(truck);
    destruct(this_object());
    return 1;
  }
  if(timer<(time()+31)) {
    tell_object(owner,"WARNING! You only have "+(timer-time())+
                " seconds left in the race!\n");
  }
}
 
set_owner(ob) { owner=ob; }
 
set_truck(ob) { truck=ob; }
 
set_timeout(x) { timer+=x; }
 
add_coolant(x) { coolant+=x; }
 
init() {
  add_action("hts","hts");
  add_action("info","info");
  add_action("tsay","tsay");
  add_action("honk","honk");
  add_action("rev","rev");
  add_action("stats","stats");
  add_action("shoot","shoot");
  add_action("nuke","nuke");
  add_action("leave","leave");
  add_action("west","west",1);
  add_action("east","east",1);
  add_action("north","north",1);
  add_action("south","south",1);
  add_action("nw","northwest");
  add_action("nw","nw");
  add_action("ne","ne");
  add_action("ne","northeast");
  add_action("sw","southwest");
  add_action("sw","sw");
  add_action("se","southeast");
  add_action("se","se");
  add_action("help","help");
  add_action("buy","buy");
  add_action("look","Look");
  add_action("look","L",1);
  add_action("list","list");
  add_action("check","check");
}
 
north() { truck->north(); return 1; }
south() { truck->south(); return 1; }
east()  { truck->east();  return 1; }
west()  { truck->west();  return 1; }
nw()    { truck->nw();    return 1; }
ne()    { truck->ne();    return 1; }
sw()    { truck->sw();    return 1; }
se()    { truck->se();    return 1; }
 
look()  { truck->Look();  return 1; }
 
check() {
  int i,j,k;
  i=timer-time();
  j=i/60;
  k=i%60;
  if(k>9)
  write("You have "+j+":"+k+" left in the race.\n");
  else
  write("You have "+j+":0"+k+" left in the race.\n");
  return 1;
}
 
hts() {
  help("truckshort");
  return 1;
}
 
help(str) {
  if(!str) return;
  if(str=="truck") {
  write("The following is a list of the commands you can do with the truck.\n");
  write("   info <ITEM> ..... Get some information on an item in the\n");
  write("                       trucks.  (\"info trucks\" for an overview)\n");
  write("   check ........... Checks the amount of time left\n");
  write("   Look or L ....... Take a look at what is in the room\n");
  write("                       with the truck\n");
  write("   stats ........... Get the current stats of your truck\n");
  write("   shoot <item> .... Shoot at <item>\n");
  write("   nuke <item> ..... Nuke <item>\n");
  write("   help truck ...... This menu\n");
  write("   help truckshort . A condensed version of this menu\n");
  write("     or hts ........\n");
  write("   buy # ........... Buy an item for the truck (the items\n");
  write("                       are described in \"list\"\n");
  write("   list ............ Get a list of items you can get for the truck\n");
  write("   honk ............ Honk the truck's horn\n");
  write("   rev ............. Rev the truck's engine\n");
  write("   tsay <str> ...... Let the truck \"talk\"\n");
  return 1;
  }
  if(str=="truckshort") {
    write("Condensed truck commands:\n");
    write("info, check, Look, stats, shoot, nuke, buy,"+
          " list, honk, rev, tsay\n");
    return 1;
  }
  return 0;
}
 
list() {
  write("The following are items you can buy for your truck:\n");
  write("    1.  Bullets                (10 for 20 coins)\n");
  write("    2.  Shields                (1 for 500 coins)\n");
  write("    3.  Hits                   (10 for 100 coins)\n");
  write("    4.  Bullet Strength        (1 for 50 coins)\n");
  write("    5.  Straif Amount          (1 for 50 coins)\n");
  write("    6.  Time                   (5 mins for 100 coins)\n");
  write("    7.  Coolant for guns       (1 container for 50 coins)\n");
  write("    8.  Nuke!                  (1 bomb for 5000 coins)\n");
  write("Just type \"buy #\" to get one. (separate multiple with a , \n"+
        "i.e.   \"buy 1,3,2,1,4,5,5\")\n");
  return 1;
}
 
stats() {
  write("Your truck stats:\n");
  write(truck->short()+"\n");
  write("           Kills: "+truck->query_kills());
  write("     Hits left: "+truck->query_hits()+"\n");
  write("    Bullets Left: "+truck->query_bullets());
  write("    Shields: "+truck->query_armor()+"\n");
  write(" Bullet Strength: "+truck->query_bulstrength());
  write("        Straif: "+truck->query_straif()+"\n");
  write("           Nukes: "+truck->query_nuke());
  write("  Coolant Left: "+(coolant-time())+" seconds.\n");
  check();
  return 1;
}
 
nuke(str) {
  truck->nuke(str);
  return 1;
}
 
shoot(str) {
  truck->shoot(str);
  return 1;
}
 
buy(str) {
  string it, rest, all;
  if(!str) {
    write("Buy what?\n");
    return 1;
  }
  all=str+",%%,%%";
  while(all) {
    sscanf(all,"%s,%s",it,rest);
    if(!it) {
      write("What do you want to buy?\n");
      all=rest;
    } else {
    if(it!="%%") {
      purchase_it(it);
      all=rest;
      } else { all=0; }
    }
  }
  return 1;
}
 
ok(x) {
  if(this_player()->query_money()<x) {
    write("You do not have enough for that.\n");
    return 0;
  }
  this_player()->add_money(-x);
  write("Ok.\n");
  return 1;
}
 
purchase_it(it) {
  int x;
  string dummy, dummy2;
  if(!sscanf(it,"%d",x)) {
          write("Buy what?\n");
          return 1;
        }
  if(x<1 || x>8) {
    write("Buy something from 1 to 8.\n");
    return 1;
  }
  switch(x) {
    case 1: checkme(1,truck->query_bullets(),MAX_bullets,10,20); break;
    case 2: checkme(2,truck->query_armor(),MAX_armor,1,500); break;
    case 3: checkme(3,truck->query_hits(),MAX_hits,10,100); break;
    case 4: checkme(4,truck->query_bulstrength(),MAX_bulstrength,1,50); break;
    case 5: checkme(5,truck->query_straif(),MAX_straif,1,50); break;
    case 6: if(ok(100)) { timer+=300; } break;
    case 7: checkme(7,(coolant-time()),MAX_coolant,180,50); break;
    case 8: checkme(8,truck->query_nuke(),MAX_nukes,1,5000);
  }
  return 1;
}
 
checkme(num,act,max,amt,cost) {
  int aa, sc;
  if(act==max) {
    write("That is already maxed out.\n");
    return 1;
  }
  else if(act+amt>max) {
    write("You have reached the max!\n");
    aa=max-act;
  } else aa=amt;
  if(!ok(cost)) { return; }
  switch(num) {
    case 1: truck->add_bullets(aa); break;
    case 2: truck->add_armor(aa); break;
    case 3: truck->add_hits(aa); break;
    case 4: truck->add_bulstrength(aa); break;
    case 5: truck->add_straif(aa); break;
    case 6: write("ERROR!\n"); return 0; break;
    case 7: truck->add_coolant(aa); break;
    case 8: truck->add_nuke(aa);
  }
  return 1;
}
 
id(str) { return str=="remote" || str=="monstertruckremote"; }
 
leave() {
  write("Your truck explodes as you leave the race.\n");
  tell_room(truck,CN+" leaves the race and "+owner->query_possessive()+
            " truck explodes.\n");
  tell_room(owner,CN+" leaves the race.\n");
  destruct(truck);
  destruct(this_object());
  return 1;
}
 
honk() {
  truck->honk();
  return 1; }
 
rev() {
  truck->rev();
  return 1;
}
 
tsay(str) {
  truck->tsay(str);
  return 1;
}
 
info(str) {
  if(!str) return;
  if(file_size("/players/grimm/closed/mall/truck/help/"+str)<1) {
    return;
  }
  cat("/players/grimm/closed/mall/truck/help/"+str);
  return 1;
}
 
save_me(fn) {
  save_object(fn+"r");
  truck->save_me(fn);
  return 1;
}
restore_me(fn) {
  restore_object(fn);
  return 1;
}
