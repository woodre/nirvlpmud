/*  Below are a few ANSI colors that you can put in your items.
    To use the colors all you need to do is have a:
      #include "/players/grimm/esc.h";
    at the top of the code for the item you will be using it on.
    Then to implement the color you can:
      write("Grimm says: "+BLINK+RED+"this is a test"+OFF+"\n");
    which will say "Grimm says: this is a test" with the words "this is a test"
    blinking red.
    NOTE: The OFF HAS TO BE THERE, otherwise it will leave everything thereafter
          printed as blinky-red. */

#ifndef beckesc
#define BS "\b"
#define esc ""
#define CLR esc+"[2J"
#define DBL esc+"#6"
#define BLACK esc+"[30m"
#define WHITE esc+"[1m"
#define BOLD WHITE
#define BLINK esc+"[5m"
#define REVERSE esc+"[7m"
#define RED esc+"[31m"
#define GREEN esc+"[32m"
#define BROWN esc+"[33m"
#define YELLOW BROWN+BOLD
#define BLUE esc+"[34m"
#define MAGENTA esc+"[35m"
#define CYAN esc+"[36m"
#define END esc+"[0m"
#define REV_RED esc+"[41m"
#define REV_GREEN esc+"[42m"
#define REV_BROWN esc+"[43m"
#define REV_BLUE esc+"[44m"
#define REV_MAGENTA esc+"[45m"
#define REV_CYAN esc+"[46m"
#define OFF END
#define beckesc BLAH
#endif
