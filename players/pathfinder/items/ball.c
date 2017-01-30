#define MASTER "/players/pathfinder/items/spball-master"

 /*
   This is a object which a player will give up a certain amount of
   spell points, and will create an object for 1/2 that amount of points
   to be able to be used later on.
 */


static int sps; /* this is the amount of spell points trapped within it */

die() { destruct(this_object()); return 1; }

id(str)
{
  return str == "ball" ||
         str == "spell_point_object";
}

get() { return 1; }
query_weight() { return 1; } /* weighs 1 */
query_save_flag() { return 1; } /* not saveable */
query_total_sps() { return sps; } /* returns points that are in the object */
set_sps(amt) { sps = amt; return 1;} /* sets points in the object */
query_value() { return 0; } /* valueless */

short()
{
  string mesg;
  mesg = "A ball containing " + sps + " spell points";
  return mesg;
}

long()
{
  write("You view a magnificant ball of pure mental energy.  It looks\n");
  write("very potent, and in the right hands it could possibly be\n");
  write("'toss'ed at someone to do massive harm, 'pass'ed on to another\n");
  write("person who is not near you, or 'crush'ed to regain the mystical\n");
  write("energy trapped within it.\n");
return 1;
}

reset(arg)
{
  if(arg) return;
  sps = 0; /* set the spell points to 0 in the beginning */
}

init()
{
  add_action("crush_the_ball", "crush");
  add_action("pass_the_ball", "pass");
  add_action("toss_the_ball", "toss");
}


 /*
   lets use daemonized functions in hopes that it will save some memory
   if many of these objects are in existance at one time
 */

crush_the_ball(str) { MASTER->crush_the_ball(str); return 1; }
pass_the_ball(str) { MASTER->pass_the_ball(str); return 1; }
toss_the_ball(str) { MASTER->toss_the_ball(str); return 1; }

