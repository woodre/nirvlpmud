inherit "obj/armor";

#define tp this_player()->query_name()

int power_on;

reset(arg){
   ::reset(arg);
   power_on = 1;
   set_name("hardsuit");
   set_short("A light blue Hardsuit");
   set_alias("suit");
   set_long("A lightweight combat hardsuit.\n"+
     "There are jump jets built into the back, and\n"+
     "armor plating which will cover your body.\n"+
         "Hardsuits were designed to protect the Knight Sabers\n"+
         "from laser guns and blades.\n"+
     "Type <hardsuit> for more information.\n");
   set_ac(4);
   /* added laser defense - illarion dec 2004*/
   set_params("other|laser",0,35,"laser_emote");
   set_weight(3);
   set_value(1000);
}

init()  {
  ::init();
  add_action("hardsuit_info","hardsuit");
  add_action("jump_jets","jump");
  add_action("suit_on","suit");
       }

hardsuit_info()  {
  write(
  "This hardsuit will let you:\n"+
  "\n"+
  "    <jump>\n    <suit on>\n\n"+
  "    More commands will be added later.\n\n");
  return 1;
        }

jump_jets()  {
  if(power_on == 1)  {
    write("You need to power up your suit before you can\n"+
    "use the jump jets.\n");
  return 1;
        }

  write("You trigger your jump jets and soar up into the air.\n\n"+
   "After hanging suspended in the air for a brief moment, you descend\n"+
   "gracefully back to the ground.\n");
  say(tp+" triggers the jump jets on "+this_player()->query_possessive()+" hardsuit and soars\n"+
   "high up into the air.\n\n"+
   tp+" hangs suspended in the air for a brief moment, and then\n"+
   "descends gracefully back to the ground.\n");
  return 1;
        }

suit_on(str)  {
  if(!str || str != "on")  {
    write("Try turning the suit 'on'\n");
    return 1;
        }

  if(power_on == 0)  {
  write("The faint hum of the suit disengages as you power it down.\n");
  say(tp+"'s hardsuit stopsits hum as "+this_player()->query_pronoun()+" power it down.\n");
  power_on = 1 - power_on;
  return 1;
        }

  write("You feel a low hum as the suit powers up around you.\n");
  say("You hear a low hum as "+tp+"'s suit powers up.\n");
  power_on = 1 - power_on;
  return 1;
        }
laser_emote() {
  if(environment()) tell_object(environment(),
"Your hardsuit deflects some of the futuristic damage!\n");
}
