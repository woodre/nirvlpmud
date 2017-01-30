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
#define esc ""
#define WHITE ""
#define BLINK ""
#define REVERSE ""
#define RED ""
#define GREEN ""
#define BROWN ""
#define BLUE ""
#define PURPLE ""
#define LIGHT_BLUE ""
#define END ""
#define REV_RED ""
#define REV_GREEN ""
#define REV_BROWN ""
#define REV_BLUE ""
#define REV_PURPLE ""
#define REV_L_BLUE ""
#define OFF END
