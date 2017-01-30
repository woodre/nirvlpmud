#define ME capitalize(this_player()->query_name())
#define Me capitalize(OB->query_name())
inherit "room/room";

int VALUE, BUSY;
object OB, myla;

reset(arg){
  if(!arg){
set_light(1);
short_desc="Hougton's Little Shop";
long_desc=
"You are in a dainty shop owned and run by little Miss Myla Hougton.\n"+
"Myla keeps her shop in wonderful repair.  There are little blue\n"+
"curtains at the small window in the back, and the counter and floor\n"+
"are so clean you can just about see your reflection in them.  Myla\n"+
"keeps herself well occupied during the day by maintaining this quaint\n"+
"little store.  There is a sign on the wall here.\n";

items=({
"stone",
"There is a loose stone in this wall.\n"+
"Maybe you can push it",
"wall",
"You notice a loose stone in this wall",
"window",
"You peer through the window and see the tower's courtyard",
});

dest_dir=({
 "/players/pavlik/guild/mages/rooms/main", "east",
});

if(!present("myla", this_object())){
  myla = clone_object("players/pavlik/guild/mages/rooms/npc/myla");
  move_object(myla, this_object());
  }

  call_out("random_message", 10);
     }
}

init(){
 ::init();
 add_action("push_stone","push");
 add_action("sell","sell");
 add_action("buy","buy");
 add_action("list","list");
 add_action("read","read");
 add_action("read","look");
 add_action("north","north");
 add_action("east","east");
}


push_stone(str){
  if(str == "stone"){
    if((this_player() == OB) && (BUSY == 1)){
      write("You can't do that right now.\n");
      return 1;
      }
    write(
    "You push the loose stone in and there is a quiet 'click'.\n"+
    "Next there is a loud 'Whoosh' sound and you wonder what\n"+
    "the hell just happened!\n");
    say(
    "There is a quiet 'click' and "+ME+" has disappeared!\n");
    move_object(this_player(), "players/pavlik/guild/mages/rooms/bank_stairs");
    return 1;
    }
}

east(){
  if((this_player() == OB) && (BUSY == 1)){
    write("Your in the middle of a deal, you can't back out now!\n");
    return 1;
    }
  write("You leave the shop.\n");
  say(ME+" leaves the shop.\n");
  move_object(this_player(), "players/pavlik/guild/mages/rooms/main");
  command("look", this_player());
  return 1;
}

sell(item) {
    object ob;

 if(!item){
   write("Myla says: What would you like to sell?\n");
   return 1;
   }

  if(item == "all"){
    object next;

    if(BUSY == 1){
    write("Myla says:  Sorry, I'll be with you in just a moment.\n");
    return 1;
     }

    ob = first_inventory(this_player());
    BUSY = 99;
    while(ob){
      next = next_inventory(ob);
      if(!ob->drop() && ob->query_value()){
         write(ob->short()+":\t");
         do_sell(ob);
       }
        ob = next;
    }
    BUSY = 0;
    write("Ok.\n");         /* sell all */
    return 1;
  }

  ob = present(item, this_player());
  if(!ob)
  ob = present(item, this_object());

  if(!ob){
    write("Myla says: Sorry honey, but you dont seem to have one of "+
     "those.\n");
    return 1;
   }
  if(BUSY == 1){
    write("Myla says: Just a moment deary, I'm already helping "+
    Me+".\n");
  return 1;
  }

  do_sell(ob);
  return 1;
}

do_sell(ob) {
  int value, do_destroy;

  value = ob->query_value();

  if(BUSY == 1){
    write("Myla says: Just a moment dear, I'm already helping "+
    capitalize(OB->query_name())+".\n");
     return 1;
     }
  if(!value){
    write("Myla says: Sorry sweety, but that ain't worth squat!\n");
    return 1;
    }
  if(environment(ob) == this_player()){
    int weight;
    if(call_other(ob, "drop", 0)){
      write("Myla says: I wouldn't dream of taking that from you!\n");
      return 1;
      }
    weight = call_other(ob, "query_weight", 0);
    call_other(this_player(), "add_weight", -weight);
    }

  if(value > 8000)
    do_destroy = 1;
  /* was originally 1500 + rnd(400) ... - mythos <2-8-96> */
  if(value > 1000)
    if(value < 1232) value = 1000 + random(550);
    else value = 1232 + random(90);

  if(BUSY != 99)
    haggle(value);

  this_player()->add_money(value);
  say(ME+" begins to haggle with Myla over some merchandise.\n");
  if(do_destroy)
    destruct(ob);
  else
    call_other("players/pavlik/guild/mages/rooms/lshop_store", "store", ob);
  return 1;
}

haggle(price){
  VALUE = price;
  OB = this_player();
  BUSY = 1;
  write("You begin to haggle with Myla for a reasonable price...\n");
  write("Myla offers "+VALUE/2+" for the item, ");
  write("You demand "+15*VALUE/6+".\n");
  say("Myla offers "+VALUE/2+", but "+ME+" demands ");
  say(15*VALUE/6+" coins.\n");
  call_out("haggle2", 3);
  return 1;
}

haggle2(){
  tell_object(OB,
  "Myla is willing to pay "+3*VALUE/4+" gold coins.\n"+
  "You won't settle for any less than "+2*VALUE+".\n");
  tell_room(environment(OB),
  "Myla will pay "+3*VALUE/4+", but "+Me+" won't settle for less "+
  "than "+2*VALUE+".\n");
  call_out("haggle3", 3);
  return 1;
}

haggle3(){
  tell_object(OB,
  "She scratches her chin for a moment.\n"+
  "Myla says: I will give ye "+7*VALUE/8+" coins for the item and not\n"+
  "a damn penny more!\n"+
  "You tell Myla where she can shove it if you don't get "+15*VALUE/9+
  "\nfor this marvelous item!\n");
  tell_room(environment(OB),
  "Myla and "+Me+" begin to argue more pointedly over the price.\n");
  call_out("haggle4", 3);
  return 1;
}

haggle4(){
  tell_object(OB,
  "Myla says: Ok, It's a deal then!  "+VALUE+" coins for this item.\n"+
  "She spits into her palm and clasps your hand, takes the object and\n"+
  "puts it away under the counter, and hands you "+VALUE+" gold coins.\n"+
  "Myla pinches you cheek and smiles sweetly.\n");
  tell_room(environment(OB),
  "Myla and "+Me+" shake on a deal and the transaction takes place.\n"+
  Me+" stumbles away from the counter in a daze.\n");
  BUSY = 0;
  return 1;
}

value(item) {
  int value;
  string name_of_item;

  if(BUSY == 1){
  write("Myla says: Just a minute deary, I'm busy helping another\n"+
        "           Customer.\n");
  return 1;
  }

 if(!item){
   write("Myla says: What would you like to see?\n");
   return 1;
   }

 name_of_item = present(item);
 if(!name_of_item)
   name_of_item = find_item_in_player(item);
 if(!name_of_item){
  if(call_other("players/pavlik/guild/mages/rooms/lshop_store", "value", item))
     return 1;
 write("Myla says: Sorry, but there isn't a "+item+" 'round here.\n");
 return 1;
    }
  value = call_other(name_of_item, "query_value", 0);
  if(!value){
    write("Myla says: Honey, "+item+" ain't worth squat!\n");
    return 1;
    }
 write("Myla says: I would say that's worth about "+
    7*value/8+" gold coins.\n");
  return 1;
}

buy(item) {
  if(BUSY == 1){
    write("Myla says: Just a moment deary, I'm already helping\n"+
    "      another customer.\n");
    return 1;
    }

  if(!item){
    write("Myla says: Buy what, dear?\n");
    return 1;
    }
    call_other("players/pavlik/guild/mages/rooms/lshop_store", "buy", item);
    return 1;
}

list(obj){
  call_other("players/pavlik/guild/mages/rooms/lshop_store", "inventory", obj);
  return 1;
}

find_item_in_player(i){
  object ob;
  ob = first_inventory(this_player());
  while(ob){
    if(call_other(ob, "id", i))
      return ob;
    ob = next_inventory(ob);
   }
  return 0;
}

read(str){
if(str =="sign" || str == "at sign"){
write(
"\n"+
"  +--------------------------------------------+\n"+
"  +  Hougton's Shop                            +\n"+
"  +     Make a great deal at Hougton's Shop!   +\n"+
"  +     You can:  buy , sell , list            +\n"+
"  +--------------------------------------------+\n"+
"\n"+
"While examining the sign, you notice a loose stone in the wall.\n"+
"\n");
return 1;
     }
}

random_message(){
  int what;

what = random(10);
if(what == 0)
  tell_room(this_object(),
  "Haji strolls into the shop.  Haji stops and glances at his watch.\n"+
  "Haji says: Oh my!  Rush Limbaugh is on!  See Ya Later.\n"+
  "Haji turns around and hurries out of the shop.\n");
else if(what == 1)
  tell_room(this_object(),
  "Myla sighs and drums her fingers on the countertop.\n");
else if(what == 2)
  tell_room(this_object(),
  "A Man enters the Shop and buys a Long Sword from Myla.\n");
else if(what == 3)
  tell_room(this_object(),
  "Hawkeye enters the shop.\n"+
  "Hawkeye wanders over to Myla and flirts with her.\n"+
  "Myla slaps Hawkeye.\n");
else if(what == 4)
  tell_room(this_object(),
  "An old man enters the shop to sell his walking stick.\n"+
  "Myla haggles over the walking stick with Old Man.\n"+
  "Old Man gets ripped off.\n");
else if(what == 5)
  tell_room(this_object(),
  "A bunch of small children enter the shop.\n"+
  "Myla gives them each a piece of candy and sends them out.\n"+
  "Myla says: Keeps them out of trouble ...\n"+
  "Myla shrugs.\n");
else if(what == 6)
  tell_room(this_object(),
  "Myla winks at you.\n");
else if(what == 7)
  tell_room(this_object(),
  "Some water leaks through the ceiling.\n"+
  "Drip.\nDrip.\nDrip.\n");
else if(what == 8)
  tell_room(this_object(),
  "A Member of the Mages Guild enters the shop to do business with Myla.\n"+
  "Mage sells a bunch of gooey stuff to Myla.\n"+
  "Myla hides gooey stuff under the counter.\n");
else if(what == 9)
  tell_room(this_object(),
  "Teop enters the shop and wanders over to Myla.\n"+
  "You hear a voice from the street yell:\n"+
  "  'SHUT THE DOOR PETE!'\n");

call_out("random_message", 40);
return 1;
}
