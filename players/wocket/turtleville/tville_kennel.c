#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/tvroom.c";
mixed *pets;
mixed *died;
reset(arg){
if(!present("ralphio")){
move_object("/players/wocket/turtleville/NPC/kkeeper.c",this_object());
}
  if(arg) return;
set_no_clean(1);
set_light(1);
dest_dir = ({
  "/players/wocket/turtleville/twpath1.c","south",
});
short_desc = HIG+"The Turtleville Kennel"+NORM;
long_desc = "  "+
            "A fairly small room.  Light filters in from the door illuminating\n"+
            "the space.  The walls are covered with cages filled with animals. There\n"+
            "is a small counter to the north and behind that a doorway to the backroom.\n"+
            "Through that many kennels can be seen.  There is a small sign behind the\n"+
            "counter.\n";
items = ({
  "door","A wooden door, which leads outside",
  "walls","They are painted pink and have cages filling the majority of their space",
  "cages","Big, small, wide and tall wire mesh cages fill the wallspace",
  "counter","It is an old wooden counter with a shell top",
  "kennels","Huge wire cages with many animals inside",
  "light","It glows but remains untangable",
  "doorway","An opening to the north that leads into the back room",
  "animals","Many animals like dogs, cats, and snakes.  You even think you see a\nperson way in the back",
  "sign","It reads:\n\n\t"+HIG+"Welcome to the Turtleville Pet Store/Kennel"+OFF+"\n\n"+
         "\tYou may buy a pet here to keep as long as you care for it.\n"+
         "\tThey will start out very young and inexperienced so you must\n"+
         "\ttrain them.  They can be kept here when you are not using them.\n"+
         "\tYou only need to 'bringout' or 'putaway' them.  Remember if you\n"+
         "\ttake care of your pet it will take care of you",
});

smells = ({
  "default","It smells like a farm",
});

listens = ({
  "default","You hear barking, chirping, meowing, and hissing from all the cages",
});
pets = ({ });

died = ({ });
}

init(){
  ::init();
  add_action("putaway","putaway");
  add_action("bringout","bringout");
}

putaway(str){
object ob;

  if(!str){
    notify_fail("What would you like to putaway?\n");
    return 0; 
  }
  ob = present(str,this_object()); 
  if(!ob){
    notify_fail("That is not here to putaway?\n");
    return 0;
  }
  if(!ob->is_neopet()){
    notify_fail("There is not a pet here to putaway?\n");
    return 0;
  }
  if(ob->query_masterob() != this_player()){
    notify_fail("That is not your pet.\n");
    return 0;
  }
  ob->save_me();
   pets -= ({ this_player()->query_real_name() });
  write("You lead "+ob->query_name()+" in his kennel.\n");
  say(this_player()->query_name()+" leads "+ob->query_name()+" into his kennel.\n");
  destruct(ob);
  return 1;
}

bringout(str){
int i, b, c, cost;
object ob;
string file;
cost = 8000;
c = 0;
  file = "/players/wocket/turtleville/PETS/saves/"+this_player()->query_real_name()+".o";  
  if(file_size(file) > 1)
  {
    b = member_array(this_player()->query_real_name(),died);
    if(b == 0)
    {
      c = 1;
      if(this_player()->query_money() < cost)
      {
        write("You do need "+cost+" coins to bring out your pet again.\n");
        return 1;
      }
    }             
    i = member_array(this_player()->query_real_name(),pets);
    if(i == -1){
      pets += ({ this_player()->query_real_name() });
    }
    else
      { 
        notify_fail("You already have your pet out.\n");
        return 0;
      }
    ob = clone_object("/players/wocket/turtleville/PETS/neopet.c");
    ob->set_master(this_player()->query_real_name());
    move_object(ob,this_object());
    write("You take your pet out of the kennel.\n");
    say(this_player()->query_name()+" takes "+this_player()->query_possessive()+" pet out of the kennel.\n");
    if(c > 0)
      this_player()->add_money(-cost);
    return 1;
    }
  notify_fail("You do not have a pet in this kennel.\n");
  return 0;
}

query_pets(){
int i,a; 
  for(i=0, a= sizeof(pets); i<a ; i++){
    write(pets[i]+"\n");
  }
  return 1;
}

add_pets(str){
 pets += ({ str });
}

remove_pets(str){
  pets -= ({ str });
}

add_died(str){
  died += ({ str });
}
