#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("man"))  {
move_object(clone_object("/players/saber/monsters/corpseman.c"),this_object()); 
        }
 if(!arg){
  set_light(1);
short_desc="Corpse Shop";
long_desc=
 "You stand in a small, dirty one room shop.  In the middle of\n"+
 "the chamber is an embalming table.  There is a sign on the wall.\n";

items=({
 "room","You are in a one room shop",
 "table","An embalming table",
 "sign","Try 'read sign'",
 });

  dest_dir=({
 "/players/saber/ryllian/slums5.c","east",
           });
  }   }
init(){
 ::init();
  add_action("read_sign","read");
  add_action("search","search");
  add_action("buy_corpse","buy");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

read_sign(str)  {
  if(str == "sign")  {
say(tp+" reads a sign.\n");
write("\nBuy a corpse - only 100 coins.\n"+
       "\nWe sell only the highest quality corpses.\n"+
       "They never decay, and they never fade away.\n");
  return 1;
        }
        }

buy_corpse(str)  {
object CORPSE;
  if(!str)  {
    write("Would you like to 'buy' a 'corpse'?\n");
  return 1;
       }
  if(!present("man"))  {
  write("There is nobody here to buy the corpse from.\n");
  return 1;
        }
/* added to keep vampires from buying corpses -Eurale 10/21 */
if(present("efangs",this_player())) {
  write("The man says, 'I don't sell corpses to vampire cheaters!'\n");
  return 1; }

  if(this_player()->query_money() < 101)  {
  write("You don't have enough money.\n");
  return 1;
        }
  if(str == "corpse")  {
  write("You pay 100 golden coins.\n"+
       "The man places a corpse in front of you.\n");
  say("The man places a corpse in front of "+tp+".\n");
  CORPSE = clone_object("/players/saber/stuff/corpse2.c");
  move_object(CORPSE,environment(this_player()));
  this_player()->add_money(-100);
  return 1;
        }
        }
