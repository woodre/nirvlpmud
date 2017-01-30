#include "../def.h"

mapping abjuspells, conjspells, enchspells, evocspells;
mapping divispells, illuspells, necrspells, transpells;
string *saved_abjuspells, *saved_conjspells;
string *saved_enchspells, *saved_evocspells;
string *saved_divispells, *saved_illuspells;
string *saved_necrspells, *saved_transpells;

/* Prototype Declaration */
void load_spells(string arg);

void save_mapping()
{
  saved_abjuspells = deconstruct_mapping(abjuspells);
  saved_conjspells = deconstruct_mapping(conjspells);
  saved_enchspells = deconstruct_mapping(enchspells);
  saved_evocspells = deconstruct_mapping(evocspells);
  saved_divispells = deconstruct_mapping(divispells);
  saved_illuspells = deconstruct_mapping(illuspells);
  saved_necrspells = deconstruct_mapping(necrspells);
  saved_transpells = deconstruct_mapping(transpells);
  save_object("players/forbin/mages/log/msd_save");
}

int restore_mapping()
{
  int a;
  a = restore_object("players/forbin/mages/log/msd_save");
  abjuspells = reconstruct_mapping(saved_abjuspells);
  conjspells = reconstruct_mapping(saved_conjspells);
  enchspells = reconstruct_mapping(saved_enchspells);
  evocspells = reconstruct_mapping(saved_evocspells);
  divispells = reconstruct_mapping(saved_divispells);
  illuspells = reconstruct_mapping(saved_illuspells);
  necrspells = reconstruct_mapping(saved_necrspells);
  transpells = reconstruct_mapping(saved_transpells);
  return a;
}

void reset(mixed arg) {
  if(arg) return;

  abjuspells = conjspells = enchspells = evocspells = ([ ]);
  divispells = illuspells = necrspells = transpells = ([ ]);

  if(!restore_mapping())
  {
    load_spells("abju");
    load_spells("conj");
    load_spells("ench");
    load_spells("evoc");
    load_spells("divi");
    load_spells("illu");
    load_spells("necr");
    load_spells("tran");
    save_mapping();
  }
  else
    restore_mapping();
}


void load_spells(string arg)
{
	string *temparray;
	string sname;
	int x;
	int slevel;
	
  if(!arg)
	  return;
	
	switch(arg)
	{
		case "abju" : abjuspells = ([ ]); break;
	  case "conj" : conjspells = ([ ]); break;
    case "ench" : enchspells = ([ ]); break;
	  case "evoc" : evocspells = ([ ]); break;
		case "divi" : divispells = ([ ]); break;
		case "illu" : illuspells = ([ ]);	break;
		case "necr" : necrspells = ([ ]); break;
		case "tran" : transpells = ([ ]); break;
	}

	temparray = get_dir("players/forbin/mages/spells/");

	for(x = 0; x < sizeof(temparray); x++)
	{
		if("players/forbin/mages/spells/"+temparray[x]->s_spell_school() == arg)
		{
			slevel = "players/forbin/mages/spells/"+temparray[x]->s_spell_level(); 			
			sname = "players/forbin/mages/spells/"+temparray[x]->s_spell_name(); 
			switch(arg)
			{
				case "abju" : abjuspells += ([ temparray[x] : ({ slevel, sname }) }); break; 
				case "conj" : conjspells += ([ temparray[x] : ({ slevel, sname }) }); break; 
				case "ench" : enchspells += ([ temparray[x] : ({ slevel, sname }) }); break; 
				case "evoc" : evocspells += ([ temparray[x] : ({ slevel, sname }) }); break; 
				case "divi" : divispells += ([ temparray[x] : ({ slevel, sname }) }); break; 
				case "illu" : illuspells += ([ temparray[x] : ({ slevel, sname }) }); break; 
				case "necr" : necrspells += ([ temparray[x] : ({ slevel, sname }) }); break; 
				case "tran" : transpells += ([ temparray[x] : ({ slevel, sname }) }); break; 																																			
			}
		}
	}
	save_mapping();
}