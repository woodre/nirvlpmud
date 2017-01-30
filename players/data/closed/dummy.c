/*
 * A practice dummy for the Servants of Shardak
 * Can be fought, but does not fight back.
 * Gives an indication of strength of attack
 * History:
 * 96-01-28 Balowski (query_mhp bug fixed, msg for negative heal_self)
 * 2000 Verte added a bug check in hit_player if the new code fucks it up
 */

static string   *colors;
static object   Attacker;
int Total;
int i;

string 
short()
{
    return "A wooden knight";
}

status
id(string s)
{
    return s == "knight";
}

string
query_name()
{
    return "knight";
}

status
query_npc()
{
    return 1;
}

heart_beat() {

  if (this_object()->query_attack())
    i++;

  if (i == 100) {
    say("\n\n\nTOTAL DAMAGE = "+Total+"\n+AVERAGE = "+(Total/100)+"\n\n\n");
    destruct(this_object());
    return 0;
  }
}

void
reset(int arg)
{
    if (arg || root()) return;
i = 0; Total = 0;
    enable_commands();
set_heart_beat(1);
    colors = ({
/*      0..4            5..9 */
        "black",        "violet",
        "ultramarine",  "umber",
        "ochre",        "olive green",
        "viridian",     "emerald green",
        "deep yellow",  "lemon yellow",
        "white",        "scarlet",
        });
}

void
long()
{
    int i;

    write("\
The knight is carved in a dark type of wood. The knight's holy posture\n\
enrages you, and its many nicks and cuts tell you that it has often\n\
been beaten. A puzzling table has been carved in the knight's shield:\n");
    for (; i < sizeof(colors); i++)
        write(pad(i*5, -4) + " to " + pad((i + 1)*5 - 1, -2) + ": " +
                colors[i] + "\n");
    write("The knight is not alive.\n");
}

int
hit_player(int dam)
{
    int color;
    if(!intp(dam))
    {
      write("The knight reports: Bug!  Tell your guild wizard to fix me.\n");
      return 1;
    }

/* temporary shit added by earwax to do guild damage calculations */
Total += dam;
say("Round #"+i+"\tDamage: "+dam+"\tTotal Damage: "+Total+"\n");

/* end wax additions */
    color = dam/5;
    if (color >= sizeof(colors)) color = sizeof(colors) - 1;
    write("The knight turns " + colors[color] + ".\n");
    return dam;
}

void
heal_self(int amount)
{
    if (amount < 0)
        write("The knight trembles at your magical attack.\n");
}

void
attacked_by(object ob)
{
    Attacker = ob;
}

object
query_attack()
{
    return Attacker;
}

void
stop_fight()
{
    Attacker = 0;
}

int
query_mhp()
{
    return 1;   /* prevents the standard monitor from dividing by 0 */
}
