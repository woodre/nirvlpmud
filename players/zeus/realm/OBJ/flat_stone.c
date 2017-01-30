

#include "/players/zeus/closed/all.h"
int sword, timah;
static object *x, misty, theroom;

reset(arg){
 if(arg) return;

  x =({  "players/zeus/realm/taus/circle1",
         "players/zeus/realm/taus/circle2",
         "players/zeus/realm/taus/circle3",
         "players/zeus/realm/taus/circle4",
         "players/zeus/realm/taus/circle5",
         "players/zeus/realm/taus/circle6",
         "players/zeus/realm/taus/circle7",
         "players/zeus/realm/taus/circle8",
         "players/zeus/realm/taus/circle9",  });

  if(!restore_object("players/zeus/realm/taus/circle_log"))
    sword = 1; /* there is a sword */
  else if(timah < time())
  {
    sword = 1;
    save_object("players/zeus/realm/taus/circle_log");
  }

}

short(){ 
  if(sword)
    return "A flat stone with a sword protruding from it";
  else if(0 == sword)
    return "A flat stone";
}

get(){ return 0; }
id(str){ return str == "stone" || str == "flat stone"; }

long(){
  if(sword)
  {
    write(
      "This is a solid block of grey stone resting upon the forest\n"+
      "floor.  On the surface there are some simple carvings.  A\n"+
      "very old sword is protruding from the stone.  The handle is\n"+
      "pointing right at you, as though you should pull it out.  Mist\n"+
      "is drifting all around the stone.\n");
  }
  else if(0 == sword)
  {
    write(
      "This is a solid block of grey stone resting upon the forest\n"+
      "floor.  On the surface there are some simple carvings.  There\n"+
      "is a small slit in the top of the stone where it looks like\n"+
      "something used to be stuck into it.\n");
  }
}

void init(){
  add_action("pull_cmd", "pull");
  add_action("pull_cmd", "get");
  add_action("pull_cmd", "take");
  add_action("look_cmd", "look");
  add_action("look_cmd", "l");
  add_action("read_cmd", "read");
  add_action("wiz_reset_cmd", "reset_stone");
}

wiz_reset_cmd(){
  if((string)this_player()->query_real_name() != "zeus") return 0;
  write("Flat stone reset.\n");
  sword = 1;
  timah = 0;
  save_object("players/zeus/realm/taus/circle_log");
  return 1;
}

look_cmd(str)
{
  if(!str) return 0;
  if(str == "at carvings")
  {
    write("The carvings on the stone depict a large creature towering\n"+
      "high above the trees.  There is some writing beneath it which\n"+
      "makes no sense to you.\n");
    return 1;
  }
  if(str == "at sword")
  {
    if(sword)
    {
      write("The sword protruding from the stone looks brand new.  Its\n"+
        "shiny metalic blade seems to glint in the darkness.\n");
      return 1;
    }
  }
}

read_cmd(str)
{
  if(!str) return 0;
  if(str == "carvings")
  {
    write("The carvings on the stone depict a large creature towering\n"+
      "high above the trees.  There is some writing beneath it which\n"+
      "makes no sense to you.\n");
    return 1;
  }
  else return 0;
}

pull_cmd(str)
{
  int i, j, *c, total_meat;
  total_meat = 0;
  if(!str) return 0;
  if(str == "sword" || str == "sword from stone")
  {
    if(sword)
    {
      if((int)this_player()->query_attrib("str") < 19 ||
        this_player()->query_level() < 12 ||
        this_player()->query_level() > 20) /* hehe */
      {
        write("You pull hard on the sword but it is stuck fast.\n"+
          "You are not strong enough to pull the sword from the stone.\n");
        say(this_player()->query_name()+" pulls on the sword.\n");
        return 1;
      }
      else if(random(3))
      {
        write("You pull on the sword but it is stuck.\n");
        say(this_player()->query_name()+" pulls on the sword.\n");
        return 1;
      }
      write("You smoothly pull the sword from the stone.\n");
      say(this_player()->query_name()+" pulls the sword from the stone.\n");
      MO(CO("/players/zeus/realm/OBJ/fallen_blade.c"), TP);
      write_file("/players/zeus/log/circle", ctime(time())+" - ");
      for(i = 0; i < sizeof(x); i++)
      {
        c = all_inventory(x[i]);
        for(j = 0; j < sizeof(c); j++) /* count up opponents */
        {
          if(c[j]->is_player())
          {
            total_meat++;
            if(c[j] == this_player())
              write_file("/players/zeus/log/circle", "*");
            write_file("/players/zeus/log/circle", 
              capitalize((string)c[j]->query_real_name())+" ");
          }
        }
        x[i]->set_nt(1);  /*  set all 9 rooms to NT */
        if(x[i] != environment())
          tell_room(x[i], "\nMist slowly drifts by you...\n");
      }
      misty = "/players/zeus/realm/NPC/mist_creature.c";
      misty->set_meats(total_meat);
      write_file("/players/zeus/log/circle", "\n");
      x[3]->set_wall(1); /* block exit */
      theroom = environment();
      "/players/zeus/realm/taus/guth16.c"->set_max(total_meat); /* max in */
      sword = 0;
      timah = time() + 324000 + random(324000);  /* 3.75 - 7.5 days */
      save_object("players/zeus/realm/taus/circle_log");
      call_out("msg1", 5);
      call_out("msg2", 12);
      call_out("msg3", 20);
      call_out("msg4", 24);
    } /* end if sword */
    else return 0;
  } /* end if str */
  else return 0;
  return 1;
}


msg1(){
  int y;
  for(y = 0; y < sizeof(x); y++)
    tell_room(x[y], "\nMist drifts around the trees...\n");
}

msg2(){
  int y;
  for(y = 0; y < sizeof(x); y++)
    tell_room(x[y], "\nThe mists begin to twist and writhe upwards...\n");
}

msg3(){
  int y;
  for(y = 0; y < sizeof(x); y++)
    tell_room(x[y], "\nA gigantic creature takes shape from the mists...\n");
  move_object(misty, theroom);
}

msg4(){
  int y;
  for(y = 0; y < sizeof(x); y++)
    tell_room(x[y], "\nA demonic scream rips across the forest.\n");
}

