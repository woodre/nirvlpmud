#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
extra_reset();
extra_reset()
{
       object moon;
if(!present("moon")){
       tree = clone_object("players/ultramagnus/moon.c");
       move_object(moon, this_object());
}
}
ONE_EXIT("players/ultramagnus/hall.c", "up",
        "High Place",
        "You are at the Top of the Earth's Highest Point....\n" +
        "The View is Breath-taking as you look around...\n" +
        "The Sky is all Aglow with a Deep Sea Blue...\n" +
        "Billions upon Billions of Stars are Flickering in the Heavens as\n" +
        "A gentle Breeze Blows from the West...\n" +
        "The Moon is All its Beauty is Setting in the West as Beams\n" +
        "from the New Days Dawning emerges from the East...\n" +
        "To the North is an Ever Burning Star...High in The Sky..\n" +
        "That Shines its light Throughout the Very Universe...\n" +
        "Majestic is this Star to all those Who Casts there Eyes\n" +
        "Skywards to Behold it...\n" +
        "Truly Does it Give an Ease to The Soul and the Mind...\n" +
        "To the South is a Beautiful Lake That Reflects the...\n" +
        "The Light of the Moon and the Stars and The Greater Star...\n" +
        "And Peace Trancends the Waters as should Peace be in\n" +
        "The Hearts of All People...\n" +
        "The Heavens and the Earth meet at the Waters edge...\n" +
        "And within the Waters...If one looks Deep enough...\n" +
        "Is the Key to The Universe itself...\n" +
        "This Is Truly a High Place...\n", 1)
