/* The ammunition for our spuck based weapons. */

int balls;
int price;

id(str) { return str == "spuckballs" || str == "tube"; }

reset(arg)
{
  if(arg) return;
  
  /* when we start off, we have 36 balls. */
  balls=36;

  /* Spuckballs are generally not worth very much to shops. */
  price = balls * 1;
}

short() { return "A tube of Spuckballs [" + balls + "]"; }

long() 
{
  write("You hold a large, soft, squishy cylinder filled with equally\n"+
        "squishy but very dense colored balls. You are not quite sure\n"+
        "what you could do with them.\n");
  write("There are [" + balls + "] spuckballs left.\n");
}

/* This is called by a spuck weapon, when firing (deducting ammo) */
lose_ammo(i) 
{
  if(i) balls = balls - i;
  else balls = balls - 1;
  return balls;
}

/* a query of how many balls we have left. */
query_ammo() 
{
  return balls;
}

/* not saveable. It must be this way, or else the ball count will
 * autospawn with lockers and hotel rooms... */
query_save_flag() {return 1;}

query_value() { return price; }

init()
{
  add_action("use"); add_verb("eat");
}

/* Sort of an optional, humorous thing... that spuckballs can be eaten. */

use(arg)
{
  object tp;
  tp = this_player();

/* i put some loops within a loop here. Not very elegant on my part. */
/* But this was one of the first things i coded so cut me some slack :) */
    if(!arg || arg != "spuckball")
    {
      return 0;
    }
    else
    {
      if(!tp->eat_food(3))
      {
        /* the player was not able to eat_food, so we just return neatly. */
        /* at this point they get a "You are too full" error message */
        return 1;
      }
      else
      {
        if(arg == "spuckball")
        {
          balls -= 1;
          write("You gobble up a Spuckball. You feel like you just ate a water balloon.\n"+
                "There are [" + balls + "] spuckballs left.\n");
          say(capitalize(tp->query_name()) + " eats a Spuckball.\n");

          if(balls == 0)
          {
            destruct(this_object());
            write("You finish off the tube and chuck it away.\n");
            tp->add_weight(-1);
          }
          return 1;
        }
     }
  }
}

get() { return 1; }

query_weight() { return 1; }

