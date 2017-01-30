/*
        Ripped and tinkered code.. Credits to Pinkfish and George Reese
	RESET fixed by Boltar
*/
#define ANSI(s) (pad("", 1, 27) + "[" + s + "m")
#define ESC(s) (pad("", 1, 27) + s)

static mapping term_info;

void
create()
{
    term_info = ([
      "unknown":
      ([ "RESET": "", "BOLD": "", "FLASH":"",
      "BLACK":"", "RED":"", "GREEN":"",
      "ORANGE":"", "YELLOW":"", "BLUE":"",
      "MAGENTA":"", "CYAN":"", "WHITE":"",
      "B_BLACK":"", "B_RED":"", "B_GREEN":"",
      "B_ORANGE":"", "B_YELLOW":"", "B_BLUE":"",
      "B_MAGENTA":"", "B_CYAN":"","B_WHITE":"",
      "CLEARLINE":"", "STATUS":"", "WINDOW":"", "INITTERM": "","ENDTERM":""]),
      "ansi":
      ([ "RESET":ANSI(0), "BOLD":ANSI(1), "FLASH":ANSI(5),
      "BLACK":ANSI(30), "RED":ANSI(31), "GREEN":ANSI(32),
      "ORANGE":ANSI(33), "YELLOW":ANSI(1)+ANSI(33), "BLUE": ANSI(34),
      "MAGENTA":ANSI(35), "CYAN":ANSI(36), "WHITE": ANSI(37),
      "B_BLACK":ANSI(40), "B_RED":ANSI(41), "B_GREEN":ANSI(42),
      "B_ORANGE":ANSI(43), "B_YELLOW":ANSI(1)+ANSI(43), "B_BLUE":ANSI(44),
      "B_MAGENTA":ANSI(45), "B_CYAN":ANSI(46), "B_WHITE": ANSI(47),
      "CLEARLINE":ESC("[L")+ESC("[G"), "STATUS":"", "WINDOW":"", 
      "INITTERM":ESC("[H")+ESC("[2J"), "ENDTERM":"" ]),
    ]);
}

string
terminal_colour(string msg, string terminal)
{
    int i, max;
    string *words, code;
    mapping term;

    if (!(term = term_info[terminal])) term = term_info["unknown"];

    for (i = 0, max = sizeof(words = explode(msg, "%^")); i < max; i++)
        if (code = term[words[i]]) words[i] = code;
    return(implode(words, "") + term["RESET"]);
}
