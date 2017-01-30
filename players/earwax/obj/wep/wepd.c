#define WEP_DATA "players/earwax/obj/wep/wep_data"

/* Global Variables */
int    *AxeHits;
int    *AxeLevel;
string *AxeNames;

save_info() { save_object(WEP_DATA); }
load_info() { restore_object(WEP_DATA); }

void initialize_info()
{
  AxeNames = ({ });
  AxeHits = ({ });
  AxeLevel = ({ });
  load_info();
}

void add_axename(string arg) {

  if (!AxeNames) 
  {
    initialize_info();
  }

  if (member_array(arg, AxeNames) > -1)
    return;

  AxeNames += ({ arg });
  AxeHits += ({ 0 });
  AxeLevel += ({ 0 });
  save_info();
}

void set_info(string name, int hits, int level)
{
  int i;

  if (!AxeNames)
  {
    initialize_info();
  }

  i = member_array(name, AxeNames);

  if (i < 0)
  {
    AxeNames += ({ name });
    AxeHits += ({ hits });
    AxeLevel += ({ level });
    return;
  }

  AxeHits[i] = hits;
  AxeLevel[i] = level;
  save_info();
}

int *query_info(string name)
{
  int i;

  if (!AxeNames)
  {
    initialize_info();
  }

  i = member_array(name, AxeNames);

  if (i < 0)
  {
    add_axename(name);
    return 0;
  }

  return ({ AxeHits[i], AxeLevel[i] });
}

void reset(status arg) { if (!arg) initialize_info(); }
