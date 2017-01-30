if( !present("student", this_object()) )
{
  int x, y;
  y = random(4);
  for(x = 0; x < y; x++)
  {
    move_object(clone_object("/players/angel/area/school/npc/student_01.c"),
    this_object());
  }
}
