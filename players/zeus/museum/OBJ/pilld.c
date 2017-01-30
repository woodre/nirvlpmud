/*  inspired by Snow's mystic pricing system  ;) 
*   When reset occurs, if the heal hasn't been bought 
*   in at least 30 min, price drops by 5+random(10)
*   Prices increase 50+random(61) every 10 purchases.
*/

#include "/players/zeus/closed/all.h"
int *x, *y, *c;

reset(arg){
 if(arg) return;
 
  if(!restore_object("players/zeus/museum/heals"))
  {
    x = allocate(2);
    x = ({ 1100, 1100, });
    y = allocate(2);
    y = ({ time(),time(), });
    c = allocate(2);
    c = ({ 0,0 });
  }
  else 
  {
    int z;
    for(z = 0; z < 2; z++)
    {
      if(y[z] <= time())  /*  price drop */
        x[z] -= 5+random(15);
      if(x[z] < 500)   /*  the 'minimum' cost */
      {                /* lowered from 700 to 500 on 12.12.99 */
        x[z] = 500;
      }
    }
    write_file("/players/zeus/log/pills", ctime(time())+" -  ");
    for(z=0; z < 2; z++)
    {
      write_file("/players/zeus/log/pills", ",  "+x[z]); 
    }
    write_file("/players/zeus/log/pills", "  [");
    for(z=0; z < 2; z++)
    {
      write_file("/players/zeus/log/pills", c[z]+","); 
    }
    write_file("/players/zeus/log/pills", "]\n");
  }

  save_object("players/zeus/museum/heals");

}

short(){ return "A pill dispenser"; }
id(str){ return str == "dispenser"; }
get(){ return 0; }

long()
{  
  write(
    "This is a tall, mechanical dispenser.  There is a small display\n"+
    "screen showing what items are for sale within the dispenser.  Type\n"+
    "'read display' to see the items, and 'buy <item>' to purchase one.\n");
}

void init()
{
  add_action("read_lazy", "rd");
  add_action("read_cmd", "read");
  add_action("buy_cmd", "buy");
}

read_lazy()
{
  write("The display screen shows the following:\n\n"+
    "  1) zp1 pills are "+x[0]+" each.  There are "+c[0]+
    " left at this price.\n"+
    "  2) zp2 pills are "+x[1]+" each.  There are "+c[1]+
    " left at this price.\n"+
    "\n");
  return 1;
}

read_cmd(str)
{
  if(str != "display") return 0;
  write("The display screen shows the following:\n\n"+
    "  1) zp1 pills are "+x[0]+" each.  There are "+c[0]+
    " left at this price.\n"+
    "  2) zp2 pills are "+x[1]+" each.  There are "+c[1]+
    " left at this price.\n"+
    "\n");
  return 1;
}

price_hike(int b){  x[b] += 50+random(61); }

brain(int b)
{
  if((int)TP->query_money() < x[b])
  {
    TR(environment(), "You realize you can't afford it.\n");
    return 0;
  }
  else if(!TP->add_weight(1))
  {
    TR(environment(), "You realize you can't carry it.\n");
    return 0;
  }
  else 
  {
    TR(environment(), TP->QN+" buys a pill.\n", ({TP}));
    tell_object(TP, "You buy a pill.\n");
    y[b] = time() + 900;
    TP->add_money(-x[b]);
    TO->add_money(x[b]);
    c[b]--;
    if(c[b] <= 0)
    { 
      price_hike(b);
      TR(environment(), 
        "The dispenser restocks and recalculates its prices.\n");
      if(b == 0)
        c[b] = 20;
      else if(b == 1)
        c[b] = 10;
    }
    save_object("players/zeus/museum/heals");
  }
  return 1;
}

buy_cmd(str)
{
  object it;
  if(!str) return 0;
  if(this_player()->query_level() > 19 &&
    this_player()->query_real_name() != "zeus") return 0;
  if(str == "zp1" || str == "1")
  {
    if(!brain(0)) return 1;
    it = clone_object("/players/zeus/heals/zp1.c");
    it -> set_val(x[0]);
    move_object(it, this_player());
    return 1;
  }
  else if(str == "zp2" || str == "2")
  {
    if(!brain(1)) return 1;
    it = clone_object("/players/zeus/heals/zp2.c");
    it -> set_val(x[1]);
    move_object(it, this_player());
    return 1;
  }
  else return 0;
}
