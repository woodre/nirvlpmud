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
		instr = HIR+"Harp"+NORM;
		break;
	case "2":
		instr = HIG+"Flute"+NORM;
		break;
	case "3":
		instr = HIY+"Fiddle"+NORM;
		break;
	case "4":
		instr = HIB+"Lyre"+NORM;
		break;
	case "5":
		instr = HIM+"Horn"+NORM;
		break;
	case "6":
		instr = HIC+"Mandolin"+NORM;
		break;
	case "7":
		instr = HIW+"Lute"+NORM;
		break;
	case "8":
		instr = HIR+"Violin"+NORM;
		break;
	case "9":
		instr = HIG+"Bagpipes"+NORM;
		break;
	case "10":
		instr = HIY+"Recorder"+NORM;
		break;
	case "11":
		instr = HIB+"Guitar"+NORM;
		break;
	case "12":
		instr = HIM+"Drum"+NORM;
		break;
	case "13":
		instr = HIC+"Pan Pipes"+NORM;
		break;
	case "14":
		instr = HIW+"Trumpet"+NORM;
		break;
	case "15":
		instr = HIR+"Harpsicord"+NORM;
		break;
	case "16":
		instr = HIG+"Saxophone"+NORM;
		break;
	default:
		notify_fail("You must enter a number.  See instrument_list.\n");
	}
	set_instrument_string(instr);
	write("You switch instruments.\n");
	return 1;
}
