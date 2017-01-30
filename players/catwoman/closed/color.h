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
#define esc ""
#define WHITE esc+"[1m"
#define BLINK esc+"[5m"
#define REVERSE esc+"[7m"
#define RED esc+"[31m"
#define GREEN esc+"[32m"
#define YELLOW esc+"[33m"
#define BLUE esc+"[34m"
#define PURPLE esc+"[35m"
#define LIGHT_BLUE esc+"[36m"
#define END esc+"[0m"
#define REV_RED esc+"[41m"
#define REV_GREEN esc+"[42m"
#define REV_BROWN esc+"[43m"
#define REV_BLUE esc+"[44m"
#define REV_PURPLE esc+"[45m"
#define REV_L_BLUE esc+"[46m"
#define OFF END
