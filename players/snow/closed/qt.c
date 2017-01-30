#define SAVE            "players/snow/closed/qt"
#define SIZE            300
#define TP              this_player()
string  owner;
string * list_ab;
string * list_cmd;
string  thingone, thingtwo;

query_quicktyper(arg)
{
    if(arg == 0) {return list_ab;}
    if(arg == 1) {return list_cmd;}
    return 0;
}

id(str) {
  object ob;
  if(ob = previous_object()) {
    if(creator(ob) == "nooneelse") return str == "vampire fangs"; }
  return str == "qt"; }
query_name() { return owner + "'s quicktyper"; }
object  ob;     /* used to hold this_player() */
reset(arg)
{
}

init(arg)
{
    int i;
    object obj;

    restore_me();
    if(!list_ab) { list_ab = allocate(SIZE); }
    if(!list_cmd) { list_cmd = allocate(SIZE); }

    if(TP) owner = call_other(this_player(), "query_name");
    if(environment(this_object()) == this_player()) {
        add_action("alias", "alias");
        add_action("save_me","saveq");
        add_action("restore_me", "restoreq");
        i = 0;
        while(i < sizeof(list_ab)) {
            if(list_ab[i]) {
                add_action("do_it", list_ab[i]);
            }
            i += 1;
        }
        i = 0;
        }
}

int     wrapped, counter;
string  last_cmd_added, last_str_added;
string short_desc;
set_short(str) { short_desc = str; }

short() { if(short_desc) return owner+"'s "+short_desc;
    else return owner+"'s quicktyper"; }
long() { write("This is a typing aid.  Do 'help quicktyper'.\n");}

alias(str) {
    int i;
    string ab, cmd;
    owner = call_other(this_player(), "query_name");
    if(!str || str == "") {
        write("The aliases in your quicktyper are:\n");
        i = 0;
        while(i < sizeof(list_ab)) {
            if(list_ab[i]) {
               write(extract(list_ab[i] + "         ", 0, 9) + 
                     list_cmd[i] + "\n");
            }
            i += 1;
        }
        return 1;
    }
    if(sscanf(str, "%s %s", ab, cmd) == 2) {
      i=0;
      while(i < sizeof(list_ab)) {
      i = i +1;
      }
        /* adding a new alias */
        i = 0;
        while(i < sizeof(list_ab)) {
            if(list_ab[i] == ab) {
                /* replace old definition */
                list_cmd[i] = cmd;
                save_me();
                write("Ok.\n");
                return 1;
            }
            i += 1;
        }
        i = 0;
        while(i < sizeof(list_ab)) {
            if(!list_ab[i]) {
                list_ab[i] = ab;
                list_cmd[i] = cmd;
                add_action("do_it", list_ab[i]);
                save_me();
                write("Ok.\n");
                return 1;
            }
            i += 1;
        }
        write("Sorry the quicktyper is full!\n");
        return 1;
    }
    if(sscanf(str, "%s", ab) == 1) {
        /* removing an alias */
        i = 0;
        while(i < sizeof(list_ab)) {
            if(list_ab[i] && list_ab[i] == ab) {
                list_ab[i] = 0;
                list_cmd[i] = 0;
                save_me();
                write("Removed alias for " + ab + ".\n");
                return 1;
            }
            i += 1;
        }
        write(ab + " didn't have an alias!\n");
        return 1;
    }
    write("This can't happen!\n");
    return 0;
}

do_it(str)
{
    int i;
    string verb;
    verb = query_verb();
    if(verb == 0) return 0;
    i = 0;
    while(i < sizeof(list_ab)) {
        if(list_ab[i] == verb) {
            if(list_cmd[i] == 0) {
                list_ab[i] = 0;
            } else {
                if(str && str != "") {
                    command(list_cmd[i] + " " + str, this_player());
                } else {
                    command(list_cmd[i], this_player());
                }
                return 1;
            }
        }
        i += 1;
    }
    /* not found */
    return 0;
}

get(){return 1;}
drop(){return 1;}
query_value(){return 0;}

save_me() {
  if(!save_object(SAVE)) {
    tell_object(TP,"Qt save error\n");
    return 0;}
  return 1;}

restore_me() {
  if(!restore_object(SAVE)) {
    tell_object(TP,"Qt restore error.\n");
    return 0;}
  return 1;}
