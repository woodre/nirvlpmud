bard_title(str)
{
	int a, b, c, CLVL;
	string titl;

	if (!str || sscanf(str, "%d", CLVL) != 1) {
		write("You must enter a number.  See bard_title_list.\n");
		return 1;
	}
	b = str;
	a = CLVL;
	c = BLVL;
	if (a > c) {
		write("You have not yet achieved that title.\n");
		return 1;
	}
	switch (b) {
	case "0":
		write("That is not a valid choice\n");
		break;
	case "1":
		titl = "the "+BOLD+"Apprentice"+NORM;
		break;
	case "2":
		titl = "the "+HIR+"Lyrist"+NORM;
		break;
	case "3":
		titl = "the "+HIG+"Journeyman"+NORM;
		break;
	case "4":
		titl = "the "+HIY+"Minstrel"+NORM;
		break;
	case "5":
		titl = "the "+HIB+"Troubadour"+NORM;
		break;
	case "6":
		titl = "the "+HIM+"Bard"+NORM;
		break;
	case "7":
		titl = "the "+HIR+"Guardian"+NORM+" of "+HIB+"Secrets"+NORM;
		break;
	case "8":
		titl = "the "+HIY+"Master"+NORM+" of "+HIG+"Riddles"+NORM;
		break;
	case "9":
		titl = "the "+HIC+"Master Bard"+NORM;
		break;
	case "10":
		titl = "the "+HIB+"Keeper"+NORM+" of "+HIM+"Lore"+NORM;
		break;
	case "11":
		titl = "the Song Master";
		break;
	default:
		notify_fail("You must enter a number.  See bard_title_list.\n");
	}
	call_other(TP, "set_title", titl);
	write("Your title has been changed.\n");
	return 1;
}

bard_title_list() {
        write(BOLD+"\n"+
        "  Bard Level       Actual Level     Guild Title        \n"+MAG+
	"_______________________________________________________\n"+NORM+
	"      1                 1           Apprentice         \n"+
	"      2                 3           Lyrist             \n"+
	"      3                 5           Journeyman         \n"+
	"      4                 8           Minstrel           \n"+
	"      5                 10          Troubadour         \n"+
	"      6                 12          Bard               \n"+
	"      7                 14          Guardian of Secrets\n"+
	"      8                 16          Master of Riddles  \n"+
	"      9                 18          Master Bard        \n"+
	"      10                GC          Keeper of Lore     \n"+HIM+
        "_______________________________________________________\n"+NORM+BOLD+
	"Type bard_title <level #> to change your title.\n"+NORM);
    return 1;
}

bard_instrument_list()
{
        write(
        "  "+HIM+"1"+NORM+BOLD+")"+NORM+"     Harp\n" +
	"  "+HIM+"2"+NORM+BOLD+")"+NORM+"     Flute\n" +
	"  "+HIM+"3"+NORM+BOLD+")"+NORM+"     Fiddle\n" +
	"  "+HIM+"4"+NORM+BOLD+")"+NORM+"     Lyre\n" +
	"  "+HIM+"5"+NORM+BOLD+")"+NORM+"     Horn\n" +
	"  "+HIM+"6"+NORM+BOLD+")"+NORM+"     Mandolin\n" +
	"  "+HIM+"7"+NORM+BOLD+")"+NORM+"     Lute\n" +
	"  "+HIM+"8"+NORM+BOLD+")"+NORM+"     Violin\n" +
	"  "+HIM+"9"+NORM+BOLD+")"+NORM+"     Bagpipes\n" +
	"  "+HIM+"10"+NORM+BOLD+")"+NORM+"    Recorder\n" +
	"  "+HIM+"11"+NORM+BOLD+")"+NORM+"    Guitar\n" +
	"  "+HIM+"12"+NORM+BOLD+")"+NORM+"    Drum\n" +
	"  "+HIM+"13"+NORM+BOLD+")"+NORM+"    Pan Pipes\n" +
	"  "+HIM+"14"+NORM+BOLD+")"+NORM+"    Trumpet\n" +
	"  "+HIM+"15"+NORM+BOLD+")"+NORM+"    Harpsicord\n" +
	"  "+HIM+"16"+NORM+BOLD+")"+NORM+"    Saxophone\n" +BOLD+
	"\nType instrument_name <#> to switch instruments.\n"+NORM);
	return 1;
}
string old_get_colored_instrument_name(string instr) {
      switch(lower_case(instr)) {
	case "harp": default:
		return HIR+"Harp"+NORM;
		break;
	case "flute":
		return HIG+"Flute"+NORM;
		break;
	case "fiddle":
		return HIY+"Fiddle"+NORM;
		break;
	case "lyre":
		return HIB+"Lyre"+NORM;
		break;
	case "horn":
		return HIM+"Horn"+NORM;
		break;
	case "mandolin":
		return HIC+"Mandolin"+NORM;
		break;
	case "lute":
		return HIW+"Lute"+NORM;
		break;
	case "violin":
		return HIR+"Violin"+NORM;
		break;
	case "bagpipes":
		return HIG+"Bagpipes"+NORM;
		break;
	case "recorder":
		return HIY+"Recorder"+NORM;
		break;
	case "guitar":
		return HIB+"Guitar"+NORM;
		break;
	case "drum":
		return HIM+"Drum"+NORM;
		break;
	case "pan pipes":
		return HIC+"Pan Pipes"+NORM;
		break;
	case "trumpet":
		return HIW+"Trumpet"+NORM;
		break;
	case "harpsicord":
		return HIR+"Harpsicord"+NORM;
		break;
	case "saxophone":
		return HIG+"Saxophone"+NORM;
		break;
	}
}
            
bard_instrument_name(str)
{
	int a, b, c, CLVL;
	string instr;

	if (!str || sscanf(str, "%d", CLVL) != 1) {
		write("You must enter a number.  See instrument_list.\n");
		return 1;
	}
	a = str;
	c = BLVL;
	b = CLVL;
	switch (a) {
	case "0":
		write("That is not a valid choice.\n");
		break;
	case "1":
		instr = "Harp";
		break;
	case "2":
		instr = "Flute";
		break;
	case "3":
		instr = "Fiddle";
		break;
	case "4":
		instr = "Lyre";
		break;
	case "5":
		instr = "Horn";
		break;
	case "6":
		instr = "Mandolin";
		break;
	case "7":
		instr = "Lute";
		break;
	case "8":
		instr = "Violin";
		break;
	case "9":
		instr = "Bagpipes";
		break;
	case "10":
		instr = "Recorder";
		break;
	case "11":
		instr = "Guitar";
		break;
	case "12":
		instr = "Drum";
		break;
	case "13":
		instr = "Pan Pipes";
		break;
	case "14":
		instr = "Trumpet";
		break;
	case "15":
		instr = "Harpsicord";
		break;
	case "16":
		instr = "Saxophone";
		break;
	default:
		notify_fail("You must enter a number.  See instrument_list.\n");
	}
	set_instrument_string(instr);
	write("You switch instruments.\n");
	return 1;
}
