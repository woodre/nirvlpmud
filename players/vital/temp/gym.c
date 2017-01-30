#include <ansi.h>

inherit "room/room";
int x;

reset(arg)
{
  ::reset(arg);
  if( !present("teacher", this_object()) )
    move_object(clone_object("/players/angel/area/school/npc/gym_teacher_01.c"), this_object());
  if( !present("student", this_object()) )
  {
    for(x=0; x<5; x++)
    {
      move_object(clone_object("/players/angel/area/school/npc/gym_student_01.c"), this_object());
    }
  }
  if(arg) return;
  set_light(1);
  short_desc = "gym";
  long_desc =
    "   Students play sports for PE such as hockey, basketball, volleyball\n\
and handball. Students also perform plays on the stage in the gym. They\n\
have Friday Night Lives where people have sleep-over's in the gym. The\n\
gym also servers as a cafeteria.\n";

  items =
  ({
    "basketball goals",
    "They features a 44 inch fan shaped backboard made of durable eco composite\n\
material, telescoping lift system that adjusts the height of your rim\n\
and more",
    "floor",
    "You see a hard wood floor, it is very shiny",
    "gym",
    "The gym has shiny hardwood floors. The lunch tables pop up and are along\n\
the wall. There is a stage at the front and a storage room for the equipment",
    "friday night lives",
    "When the students sleep over and play games. Help to keep them off the streets",
    "tables",
    "They are stored along the wall till lunch time",
    "stage",
    "A typical school stage",
    "storage room",
    "A dark room where the equipment is keep",
    "equipment",
    "Balls, bats, gloves, racquet's, and the like",
  });
  dest_dir =
  ({

  });
}


init()
{
  ::init();
  add_action("open","open");
  add_action("search","search");
  opened = 0; is_here = 0;
}


open(str)
{
  if(present("teacher"))
  {
    write("The gym Teacher puts his boot along your lower back and\n\
  boots your ass to the floor...\n");
    return 1;
  }
  if(!str) { write("Open what?\n"); return 1; }
  if(str == "closet")
  {
    write("Open ");
    return 0;
  }
}


search(str)
{
  int is_here
    object broom;
  if(!opened)
  {
    write("You must open the door first.\n"); return 1;
    if(present("teacher"))
    {
      write("Teacher says, 'Drop and give me 20 pushup!\n");
      return 1;
    }
    if(!str)
    {
      write("Search what?\n");
      return 1;
    }
    if(str == "closet" && is_here)
    {
      write("You find a broom lying on the floor.\n");
      broom=clone_object("/players/angel/broom.c");
      move_object(broom,this_player());
      is_here=1;
      return 1;
    }
    write("You find nothing.\n");
    return 1;
  }
