/*
Daemonsraad
Final puzzle for the Jal-Hab quest.
*/
#include "defs.h"

inherit ROOM;


int solved;

string *stones;
int *weight;
int *x;
int *y;

int calc_x()
{
  int i,a;
  for(i=0; i < sizeof(stones); i++)
    a+=x[i]*weight[i];
  return a;
}
int calc_y()
{
  int i,b;
  for(i=0; i < sizeof(stones); i++)
    b+=y[i]*weight[i];
  return b;
}

void reset(int arg)
{
  if(arg) return;
  short_desc=HIR+"Daemonsraad"+NORM;
  long_desc=
"  Shadows linger in the corners of this vaulted chamber, lending\n\
sustenance to your every fears.  Images of gargoyles and demons are\n\
carved in bas-relief upon the thirteen obsidian columns that support\n\
the ceiling.  In the center of the chamber is a grid with a black\n\
altar on it.\n";
  dest_dir=({
    "blah","out"
  });
  items=({
    "grid","blah",
    "altar","A black looking altar with ancient blood still encrusting its foul surface.\n"+
            "You guess it weighs about 10 stones",
  });


  stones=({ "altar" });
  weight=({ 10 });
  x=({ -4 });
  y=({ -6 });

}

void init()
{
  ::init();
  add_action("cmd_place","place");
  add_action("cmd_remove","remove");
  add_action("cmd_remove","get");
  add_action("cmd_remove","take");
  add_action("cmd_out","out");
  add_action("cmd_move","move");
  add_action("cmd_move","push");
  add_action("cmd_move","pull");
  add_action("cmd_move","shove");
}

int cmd_out(string str)
{
  say(TPN+" leaves.\n");
  move_object(this_player(),(object)MAP->query_location(9,8));
  command("look",this_player());
  return 1;
}
int cmd_move(string str)
{
  if(str && str=="altar")
  {
    write("The altar is attached to the floor.  It cannot be moved at all.\n");
    return 1;
  }
  if(str && str=="grid")
  {
    write("The grid cannot be manipulated by brute force.  It appears that it can only be\n"+
          "be manipulated through magical means.\n");
    return 1;
  }
}
void long(string str)
{
  int i,j;
  int a,b;
  int n;
  string dir;

  if(!str || str!="grid") { ::long(str); return; }

  a=calc_x();
  b=calc_y();

  if(!a && !b) dir="The grid is flat";
  else
    dir="The grid is tilted down to the ";
  if(b > 0) dir+="north";
  if(b < 0) dir+="south";
  if(a > 0) dir+="east";
  if(a < 0) dir+="west";
  dir+=".\n";
  write(dir);
  write("\t 987654321Y123456789\n");
  for(i=10; i >= -10; i--) 
  {
    if(i!=0) write(i+"\t");
    else write("X\t");
    for(j=-10; j <= 10; j++)
    {

      n=member_array("air",stones);

      if(n!=-1 && x[n]==j && y[n]==i)
        write(CYN+"A"+NORM);
      else {
        n=member_array("water",stones);
        if(n!=-1 && x[n]==j && y[n]==i)
          write(BLU+"W"+NORM);
        else {
          n=member_array("earth",stones);
          if(n!=-1 && x[n]==j && y[n]==i)
            write(RED+"E"+NORM);
          else {
            n=member_array("fire",stones);
            if(n!=-1 && x[n]==j && y[n]==i)
              write(HIR+"F"+NORM);
            else {
              n=member_array("altar",stones);
              if(n!=-1 && x[n]==j && y[n]==i)
                write(BOLD+BLK+"A"+NORM);              
              else
                if(j==0 && i==0)
                  write("+");
                else
                  write(".");
            }
          }
        }
      }
    }
    write("\n");
  }
}

int cmd_place(string str)
{
  object key;
  string elem;
  string k, location;
  int a,b,w;
  int i;

  notify_fail("Place <what> at <x,y>\n");
  if(!str) return 0;
  if(sscanf(str,"%s at %s",k,location)!=2) return 0;
  key=present(k,this_player());
  if(!key) {
    notify_fail("You don't have that.\n");
    return 0;
  }

  elem=(string)key->query_element();
  w=(int)key->query_weight();

  if(!elem) {
    notify_fail("That is not the right key!\n");
    return 0;
  }
  if(sscanf(location,"%d,%d",a,b)!=2) return 0;

  if(a > 10 || b > 10 || a < -10 || b < -10)
  {
    notify_fail("The coordinates must be between -10 and 10.\n");
    return 0;
  }

/* Check to see if that spot is taken */
  for(i=0; i < sizeof(stones); i++)
  {
    if(a==x[i] && b==y[i])
    {
      write("There is already a key there.\n");
      return 1;
    }
  }

  stones+=({ elem });
  weight+=({ w });
  x+=({ a });
  y+=({ b });
  destruct(key);
  TP->recalc_carry();
  write("You place the key at <"+a+","+b+"> on the grid.\n");
  call_out("check_solution",3);
  return 1;
}
int cmd_remove(string str)
{
  object key;
  string name;
  int n;
  notify_fail("Remove what?\n");
  if(!str) return 0;

  if(str=="fire" || str=="fire key" && (n=member_array("fire",stones)) != -1)
    name="key-fire";
  else if(str=="air" || str=="air key" && (n=member_array("air",stones)) != -1)
    name="key-air";
  else if(str=="water" || str=="water key" && (n=member_array("water",stones)) != -1)
    name="key-water";
  else if(str=="earth" || str=="earth key" && (n=member_array("earth",stones)) != -1)
    name="key-earth";
  if(name)
  {
    x-=({ x[n] });
    y-=({ y[n] });
    stones-=({ stones[n] });
    weight-=({ weight[n] });

    key=clone_object(OBJ_PATH+name);
    write("You pick up the "+(string)key->short()+".\n");
    move_object(key,TP);
    TP->recalc_carry();
    return 1;
  }    
  return 0;
}

void check_solution()
{
  int a,b;
  if(sizeof(stones) < 5)
  {
    tell_room(this_object(),"The floor shifts.\n");
    return;
  }
    
  if(!calc_x() && !calc_y() && !solved) 
  {
    tell_room(this_object(),"You've solved the puzzle!  \n<Insert quest completion here>\n");
    solved=1;
    return;
  }

  if(sizeof(stones) == 5)
  {
    tell_room(this_object(),"The floor shifts, but nothing happens.\n");
    return;
  }
}
