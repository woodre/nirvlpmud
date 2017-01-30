#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
short_desc="Bard Shield Room";
long_desc=
 "This small chamber is filled with a deep, heavy blue light.  In the center of\n"+
 "the chamber is a large blue gem surrounded by some sort of a dark blue force\n"+
 "shield.  Bardic tradition has it that the magical shield which shelters the\n"+
 "Bardic Guild receives its power from the mana stored here.  If you like, you\n"+
 "may <donate> some <#> mana to help maintain the magical shield.\n";

items=({
 "floor","The floor is made from a beautiful mahogany wood",
 "chamber","You are in the shield chamber",
 "light","A heavy blue light fills the chamber.\n"+
    "It appears to be emanating from the gem",
 "gem","A large star sapphire which pulses in rythum with your heart.\n"+
    "You feel a strange power emanating from it",
 "shield","You cannot see the shield.  It's invisible",
 });

  dest_dir=({
 "/players/guilds/bards/bardrooms/teleport.c","west",
           });
  }   }
init(){
 ::init();
if(!present("instrument",this_player()))  {
  write("You get the brief image of a blue circle before\n"+
     "\n"+
    " * * * * *  B O O M  * * * * *\n"+
    "\nYour body flies through space.\nYou find yourself somewhere new.\n");
  say(tp+" bounces off the Circle of Warding.\n");
  move_object(this_player(),"/room/church");
  tell_room(environment(this_player()), tp+" falls screaming from the sky.\n"+
      "THUD.\n");
  return 1;
        }
  add_action("search","search");
   add_action("donate","donate");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

donate(str)  {
int temp, temp2;
int temp3;
object ob;
  if(sscanf(str,"%d",temp) !=1)  {
  write("Donate <# of mana pts>\n");
  return 1;
        }
  ob = this_player();
  temp3 = ob->query_sp();
  temp2 = (temp*5);
  if(temp > temp3)  {
  write("You do not have that much mana.\n");
  return 1;
        }
  this_player()->add_money(temp2);
  this_player()->add_spell_point(-temp);
  write("You donate "+str+" mana towards shield upkeep.\n"+
    "You feel richer.\n");
  say(tp+" donates mana towards shield upkeep.\n");
  return 1;
        }


realm()  { return "NT"; }
