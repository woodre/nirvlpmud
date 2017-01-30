/*
 * This is the Bardic ability to shape reality, to bring
 *  order from chaos.
 */

shape(str)  {
object ob;
string name, stuff, detail;
string OBJ, AA, BB, CC;

if(sscanf(str, "%s %s %s", name, stuff, detail) !=3)  {
    write("S <object to be named> <type of shaping> <detail>\n"+
    "Example - S ring inscribe To remember me always.\n");
    return 1;
        }

if(!present(name,environment(this_object())))  {
    write("You must hold the object to shape it.\n");
    return 1;
        }

ob = present(name,environment(this_object()));
OBJ = ob->query_name();

if(!ob->query_bardic_mark())  {
    write("This object is anchored too well in reality to shape.\n");
    return 1;
        }

if(stuff == "shine")  {
    if(spell(-156,7,10) ==-1)  return 0;
    call_other(ob, "set_light", 1);
    write("You shape the "+OBJ+" so that it shines like a torch.\n");
    say(tp+" causes the "+OBJ+" to shine like a torch.\n");
    call_other(TP,"add_spell_point",-10);
    return 1;
        }

if(stuff == "inscribe")  {
    if(spell(-199,7,5) ==-1) return 0;
    detail = detail+"\n";
    call_other(ob, "set_read", detail);
    write("You inscribe the "+OBJ+" with runes which read:\n"+
       "* "+detail+"\n");
    say(tp+" inscribes some runes upon the "+OBJ+"\n");
    call_other(TP,"add_spell_point",-5);
    return 1;
        }

if(stuff == "detail")  {
    if(spell(-111,7,5) ==-1) return 0;
    detail = detail+"\n";
    call_other(ob, "set_long", detail);
    say(tp+" separates the "+OBJ+" from the primal forces of chaos.\n");
    write("The "+OBJ+" is now seperate from the primal forces of chaos.\n");
    call_other(TP,"add_spell_point",-5);
    return 1;
        }

if(stuff == "xname")  {
    if(spell(-158,7,5) ==-1) return 0;
    call_other(ob, "set_alt_name", detail);
    write("You have given "+OBJ+" the additional name of "+detail+".\n");
    say(tp+" whispers a single word to the "+OBJ+".\n");
    call_other(TP,"add_spell_point",-5);
    return 1;
        }

if(stuff == "mass")  {
    if(spell(-194,7,10) ==-1) return 0;
    call_other(ob, "set_weight", 0);
    say(tp+" reduces the mass of the "+OBJ+".\n");
    write("You reduce the mass of the "+OBJ+".\n");
    call_other(TP,"add_spell_point",-10);
    return 1;
        }

if(stuff == "name")  {
  if(sscanf(str, "%s %s %s | %s | %s", name, stuff, AA, BB, CC) !=5)  {
    write("Name - S strand name <name> | <appearance> | <common name>\n"+
       "Example: S strand name rose | A rose | flower\n");
    return 1;
        }
    if(spell(-195,7,20) ==-1) return 0;
    call_other(ob, "set_short", BB);
    call_other(ob, "set_alias", CC);
    call_other(ob, "set_name", AA);
    write("You have NAMED the object, bringing pattern to chaos.\n");
    say(tp+" NAMES an element of chaos.\n"+
     "A "+OBJ+" is formed.\n");
    call_other(TP,"add_spell_point",-20);
    return 1;
        }

  write("S <object name> <type of shaping> <detail>.\n");
  return 1;
        }
