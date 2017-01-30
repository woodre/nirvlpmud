id(str) { return str == "brick"; }
short() { return "Snorri's Trick Brick"; }
long() {
  write("This appears to be an ordinary red brick. However, it feels\n"+
	"somewhat dense and heavy, and reeks of happy magic. Perhaps if\n"+
	"you were to 'rub' the brick, something would happen.\n");
}
/*
 * Remember Bard's Tale RPG? *grin*
 *
 *   20 Dec 93 Mizan
 */

get() { return 1; }
query_weight() { return 2; }
query_value() { return 10500; }
query_save_flag() { return 1; }

init() {
  add_action("do_something_cool","rub");
}

static do_something_cool(str) {
  string tpn;
  if(!str || str !="brick") return;
  tpn=this_player()->query_name();
  if(1==random(6)) {
    write("You rub the brick and it turns into a jar of pickles!\n");
    say(tpn+" rubs the Trick Brick and it turns into a jar of pickles!\n");
    move_object(clone_object("players/mizan/etheriel/heals/pickles.c"), this_player());
    this_player()->add_weight(-2);
    destruct(this_object());
    return 1;
  }
  if(1==random(6)) {
    write("You rub the brick and it turns into a sword!\n");
    say(tpn+" rus the Trick Brick and it turns into a sword!\n");
    move_object(clone_object("players/mizan/etheriel/items/bigsword.c"), this_player());
    this_player()->add_weight(-2);
    destruct(this_object());
    return 1;
  }
  if(1==random(6)) {
    write("You rub the brick and it turns into a bag of dirt!\n");
    say(tpn+" rubs the Trick Brick and it turns into a bag of dirt!\n");
    move_object(clone_object("players/mizan/etheriel/heals/dirtbag.c"), this_player());
    this_player()->add_weight(-2);
    destruct(this_object());
    return 1;
  }
  if(1==random(6)) {
    write("You rub the brick and it turns into a plastic bag!\n");
    say(tpn+" rubs the Trick Brick and it turns into a plastic bag!\n");
    move_object(clone_object("players/mizan/etheriel/items/plastic-bag.c"), this_player());
    this_player()->add_weight(-2);
    destruct(this_object());
    return 1;
  }
  if(1==random(6)) {
  write("You rub the brick and it EXPLODES!! LOOK OUT!!\n");
  say(tpn+" rubs a Trick Brick and it explodes! Run for your lives!\n");
    area_attack();
    this_player()->add_weight(-2);
    destruct(this_object());
    return 1;
  }
  if(1==random(6)) {
    write("You rub the brick and it turns to dust! :(\n");
    say(tpn+" rubs a Trick Brick and it turns to dust.\n");
    this_player()->add_weight(-2);
    destruct(this_object());
    return 1;
  }
}

static area_attack() {
  object room,ob2,oc2;
  object ob;
  room=environment(this_object());
  ob=first_inventory(room);
  say("\tBBBBBBB    OOOOOO    OOOOOO   MM     MM  !!  !!\n"+
      "\tBB    BB  OO    OO  OO    OO  MMM   MMM  !!  !!\n"+
      "\tBBBBBBB   OO    OO  OO    OO  MM MMM MM  !!  !!\n"+
      "\tBB    BB  OO    OO  OO    OO  MM  M  MM  \n"+
      "\tBBBBBBB    OOOOOO    OOOOOO   MM     MM  !!  !!\n\n");
    while(ob) {
      object oc;
      oc=ob;
      ob=next_inventory(ob);
        if(living(oc)) {
          if(oc->query_npc() !=1) {
            if((oc->query_name()) == "Mizan") {
              say("Mizan is unaffected by the blast.\n");
            } else {
              say((oc->query_name())+" is thrown across the room by the explosion.\n");
              oc->run_away();
            }
          }
        if(oc->query_npc() == 1) {
          if((oc->query_name()) == "Summerhead") {
            say("Summerhead is unaffected by the blast.\n");
          } else {
            say((oc->query_name())+" is caught in a barrage of red-hot shrapnel!\n");
            oc->hit_player(15+random(10));
          }
        }
      }
    }
  return 1;
}
