/* Daemon that maintains the weather */
/* fails miserably */
/* weather goes from 0-36 = hot and sunny to big storm */
/* the statistical distribution is 1/f noise which should 
   match real weather, sort of. */
/* values:
   0 very hot and humid
   1 very hot and sunny
   2 hot and humid
   3 hot and sunny
   4 very warm and sunny
   5 warm and sunny
   6 warm and humid
   7 warm and sunny
   8 sunny
   9 pleasantly cool and sunny
  10 pleasantly cool, but sunny
  11 cool, but sunny
  12 pleasantly cool
  13 cool
  14 chilly
  15 very chilly
  16 cold
  17 ice cold
  18 frigid
  19 misty
  20 foggy
  21 drizzling
  22 sprinkling
  23 raining
  24 rainy
  25 a downpour
  26 raining very hard
  27 sleeting
  28 raining extremely hard
  29 stormy
  30 very stormy
  31 extremely stormy
  32 hailing
  33 hailing hard
  34 hailing very hard
  35 hurricane
  36 large hurricane
*/

int c1, c2, c3, c4, c5, w1, w2, w3, w4, oldweather, currentweather;

reset(arg)
{
    if (arg)
        return;
    set_heart_beat(1);
    shout("We now have weather!\n");
    c1=random(8);
    c2=random(8);
    c3=random(8);
    c4=random(8);
    c5=random(8);
    w1=random(10);
    w2=random(10);
    w3=random(10);
    w4=random(10);
    oldweather=w1+w2+w3+w4;
    currentweather=w1+w2+w3+w4;
   move_object(this_object(), "room/test");
}

short() {
    return "A weather daemon";
}

long() {
    return ("A very strange daemon.\n" +
    "It just sits here, controlling the weather.\n");
}

id(str) { return str == "daemon"; }

heart_beat()
{
    if (random (5)) return;
    if (c1 == 0) {
        c1=20;
        oldweather=w1+w2+w3+w4;
        if (c2 == 0) {
            c2=8;
            if (c3 == 0) {
                c3=8;
                if (c4 == 0) {
                    c4=8;
                    if (c5 == 0) {
                        c5=8;
                        w4=random(10);
		    }
                    c5=c5-1;
		    w3=random(10);
		}
                c4=c4-1;
                w2=random(10);
	    }
            c3=c3-1;
            w1=random(10);
	}
        c2=c2-1;
        currentweather=w1+w2+w3+w4;
        if (oldweather == currentweather) {
            shout("It is ");
        } else {
            shout("It is now ");
        }
        if (currentweather ==  0) { shout("very hot and humid"); } else
        if (currentweather ==  1) { shout("very hot and sunny"); } else
        if (currentweather ==  2) { shout("hot and humid"); } else
        if (currentweather ==  3) { shout("hot and sunny"); } else
        if (currentweather ==  4) { shout("very warm and sunny"); } else
        if (currentweather ==  5) { shout("warm and very humid"); } else
        if (currentweather ==  6) { shout("warm and humid"); } else
        if (currentweather ==  7) { shout("warm and sunny"); } else
        if (currentweather ==  8) { shout("sunny"); } else
        if (currentweather ==  9) { shout("pleasantly cool and sunny"); } else
        if (currentweather == 10) { shout("pleasantly cool, but sunny"); } else
        if (currentweather == 11) { shout("cool, but sunny");  } else
        if (currentweather == 12) { shout("pleasantly cool"); } else
        if (currentweather == 13) { shout("cool"); } else
        if (currentweather == 14) { shout("chilly"); } else
        if (currentweather == 15) { shout("very chilly"); } else
        if (currentweather == 16) { shout("cold");  } else
        if (currentweather == 17) { shout("ice cold"); } else
        if (currentweather == 18) { shout("frigid"); } else
        if (currentweather == 19) { shout("misty"); } else
        if (currentweather == 20) { shout("foggy"); } else
        if (currentweather == 21) { shout("drizzling"); } else
        if (currentweather == 22) { shout("sprinkling"); } else
        if (currentweather == 23) { shout("raining"); } else
        if (currentweather == 24) { shout("rainy"); } else
        if (currentweather == 25) { shout("a downpour"); } else
        if (currentweather == 26) { shout("raining very hard"); } else
        if (currentweather == 27) { shout("sleeting"); } else
        if (currentweather == 28) { shout("raining extremely hard"); } else
        if (currentweather == 29) { shout("stormy"); } else
        if (currentweather == 30) { shout("very stormy"); } else
        if (currentweather == 31) { shout("extremely stormy"); } else
        if (currentweather == 32) { shout("hailing"); } else
        if (currentweather == 33) { shout("hailing hard"); } else
        if (currentweather == 34) { shout("hailing very hard"); } else
        if (currentweather == 35) { shout("hurricane"); } else
        if (currentweather == 36) { shout("large hurricane"); }
        shout(".\n");
    }
    c1=c1-1;
}

query_weather() {
    return currentweather;
}
