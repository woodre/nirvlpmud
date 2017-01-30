#include "/players/pavlik/closed/colors.h"

/*
 * A player can fight this object and get an idea of how much
 * damage his attack is doing.  Original design by Balowski.
 * I probably coulda whipped up something like this without
 * borrowing Bal's code, but I just like the way he does things!
 */

/* different returns for amts of damage */
static string *colors;

/* who's trying to kill me */
static object Attacker;

string short() {
    return "A Stone Golem";
}

status id(string s) {
    return s == "golem" || s == "stone golem";
}

string query_name() {
    return "Stone Golem";
}

status query_npc() {
    return 1;
}

void reset(int arg) {
    if (arg || root()) return;
    enable_commands();
    colors = ({
/*      0..4            5..9     */
        HIW+"pure white"+NORM,    WHT+"off-white"+NORM,
        RED+"blood scarlet"+NORM,  HIR+"flush red"+NORM,
        YEL+"whacky orange"+NORM,   HIY+"eye-gouging yellow"+NORM,
        GRN+"puke green"+NORM,    HIG+"emerald"+NORM,
        CYN+"sea ocre"+NORM,  HIC+"brilliant cyan"+NORM,
        BLU+"deep azure"+NORM, HIB+"cobalt"+NORM,
        MAG+"indigo"+NORM,    HIM+"lush violet"+NORM,
    });
}


void long() {
    int i;

 write(
"The Stone Golem is an enchanted manifest of the Mages.  This huge Golem's\n"+
"only purpose is to suffer the might of your spells.  Several chunks of\n"+
"rock are missing from its nicked and battered body.  There is some sort\n"+
"of inscription on the back of its right hand.\n");
  return;
}

init() {
  add_action("read","read");
}

int read(string arg) {
  int i;
  if(arg == "inscription" || arg == "golem" || arg == "hand") {
    write("You read this table from the Golem's hand:\n");
    for (; i < sizeof(colors); i++)
        write(pad(i*5, -4) + " to " + pad((i + 1)*5 - 1, -2) + ": " +
                colors[i] + "\n");
    return 1;
  }
}

#define VALID_TYPES ({"dark","fire","light","water","fire","wind","earth",\
                      "ice","electric","laser","evil","good","poison",\
                      "sonic","mental"})

int do_damage(int *d, string *meth) {
    int color;
    int i, dam;
    string type;
    for(i=0;i<sizeof(d);i++)
    {
      if(!meth || sizeof(meth) < i-1)
      {
        type="physical";
      }
      else
      {
        type=meth[i];
        if(!type) type="physical";
        if(sscanf(type,"other|%s",type))
        {
          if(member_array(type, VALID_TYPES) == -1)
          {
            type="otherworldly";
          }
        }
        else if(type != "physical" && type != "magical")
        {
          type="otherworldly";
        }
      }
      dam=d[i];
      color = dam/5;
      if (color >= sizeof(colors))
        color = sizeof(colors) - 1;
      tell_room(environment(),
        "> The Golem's stone body flashes " + colors[color] + ".\n");
      tell_room(environment(),
        "> The Golem reels from the "+BOLD+type+NORM+" attack!\n");
    }
    return dam;
}

int heal_self(int amount) {
    if (amount < 0)
      return do_damage(({-amount}), ({"otherworldly"}));
}

varargs int hit_player(int d1, string t1, int d2, string t2)
{
  return do_damage(({d1,d2}),({t1,t2}));
}

void attacked_by(object ob) {
    Attacker = ob;
}

object query_attack() {
    return Attacker;
}

void stop_fight() {
    Attacker = 0;
}

int query_mhp() {
    return 1;   /* prevents the standard monitor from dividing by 0 */
}
