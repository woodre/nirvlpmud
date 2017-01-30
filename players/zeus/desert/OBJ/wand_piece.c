#include <ansi.h>
inherit "/obj/treasure.c";
int piece_num; /* 1 is bottom, 2 middle, 3 top */
object a,b,c,wand;

reset(arg){
  set_weight(1);
  set_value(1500);
}

short(){
  if(this_player()->query_level() > 20)
    return "A dusty old piece of treasure ["+piece_num+"]";
  else
    return "A dusty old piece of treasure";
}

long(){
  if(piece_num == 2)
    write(
"This is a strange little trinket.  It is a piece of a wand, a few inches\n"+
"long, and covered with mystical engravings.  The ends of the wand are\n"+
"clearly broken off, as though it was once longer than it is now.  You\n"+
"could be wrong, but it almost looks like the broken ends of the rod are\n"+
"glowing softly.  ");
  else
    write(
"This is a strange little trinket.  It is a piece of a wand, a few inches\n"+
"long, and covered with mystical engravings.  The end of the wand is\n"+
"clearly broken off, as though it was once longer than it is now.  You\n"+
"could be wrong, but it almost looks like the broken end of the rod is\n"+
"glowing softly.  ");
  if(piece_num == 1)
    write("This looks like the bottom piece of the wand.\n");
  else if(piece_num == 2)
    write("This looks like the middle piece of the wand.\n");
  else if(piece_num == 3)
    write("This looks like the top piece of the wand.\n");
  else
    write("\n");
}

void set_number(int x){ piece_num = x; }

id(a){
  if(piece_num == 1)
    return a == "treasure" || a == "wand" || a == "piece" || a == "trinket"
    || a == "zeus_inculta_rp_one";
  else if(piece_num == 2)
    return a == "treasure" || a == "wand" || a == "piece" || a == "trinket"
    || a == "zeus_inculta_rp_two";
  else if(piece_num == 3)
    return a == "treasure" || a == "wand" || a == "piece" || a == "trinket"
    || a == "zeus_inculta_rp_three";
  else
    return a == "treasure" || a == "wand" || a == "piece" || a == "trinket";
}

void init(){
  add_action("assemble", "assemble");
  add_action("wizsetnum", "wizsetnum");
}

int assemble_wand(object ths)
{
  write("\nYou place the pieces of the wand end to end.\n"+
    "Each piece begins to glow softly...\n"+
    "The pieces melt together and reform as the original wand.\n");
  say("You see a soft flash of light come from "+
    this_player()->query_name()+"'s hands.\n");
  wand = clone_object("/players/zeus/desert/OBJ/wand.c");
  move_object(wand, this_player());
  write_file("/players/zeus/log/Q", ctime(time())+" -  "+
     capitalize((string)this_player()->query_real_name())+
     " assembled the Inculta Creperum wand.\n");
  if(ths != a) destruct(a);
  if(ths != b) destruct(b);
  if(ths != c) destruct(c);
  destruct(a);
  destruct(b);
  destruct(c);
  return 1;
}

status assemble(string str)
{
  if(!present(this_object(), this_player())) return 0;
  if(str != "pieces" && str != "wand") return 0;
  if(!piece_num) return 0;
  if(piece_num == 1)
  {
    a = this_object();
    if((b = present("zeus_inculta_rp_two", this_player())) &&
     (c = present("zeus_inculta_rp_three", this_player())))
     return assemble_wand(a);
  }
  else if(piece_num == 2)
  {
    b = this_object();
    if((a = present("zeus_inculta_rp_one", this_player())) &&
     (c = present("zeus_inculta_rp_three", this_player())))
     return assemble_wand(b);
  }
  else if(piece_num == 3)
  {
    c = this_object();
    if((a = present("zeus_inculta_rp_one", this_player())) &&
     (b = present("zeus_inculta_rp_two", this_player())))
     return assemble_wand(c);
  }
  else
    return 0;
}

status wizsetnum(string b)
{
  int a;
  if(!b) return 0;
  if(this_player()->query_level() < 100) return 0;
  sscanf(b, "%d", a);
  piece_num = a;
  write("Wand Piece Assigned "+a+".\n");
  return 1;
}

