/*
 *  room.h
 *  Nirvana Development
 *
 *  Created by Vital on Sat Nov 30 2002.
 *  Copyright (c) 2002 by VitalCode.
 *  All rights reserved.
 */

void set_short(string str)
{
    short_desc = str;
}

void set_long(string str)
{
    long_desc = str;
}

void set_info(string str)
{
    info = str;
}

set_items(string *itemlist) /* this is to set up items outside of the 'reset' function for a cleaner look */
{
    items = itemlist;
}

set_directions(string *directionarray) /* this is to set up directions outside of the 'reset' function for a cleaner look */
{
    dest_dir = directionarray;
}

string get_search_adverb()
{
    string *adverb;
    adverb = ({
        "furiously",
        "frantically",
        "quickly",
        "passionately",
        "anxiously",
        "quickly",
        "swiftly",
        "rapidly",
        "hastily",
        "briefly",
        "rapidly",
        "deliberately",
        "slowly",
        "moronically",
        "feeblemindedly",
        "stupidly",
        "thickly",
        "sluggishly",
        "heavily",
        "lethargically",
        "ponderously",
        "clumsily",
        "ponderously",
        "roughly",
        "laboriously",
        "lethargically",
        "secretly",
        "deeply",
        "gravely",
        "expectantly",
        "intently",
        "ambitiously",
        "enthusiasticly",
        "covetously",
        "longingly",
        "wishfully",
        "restlessly",
        "impatiently",
        "apatheticly",
        "stolidly",
        "actively",
        "briskly",
        "keenly",
        "fleetingly",
        "rapidly",
        "hastily",
        "expeditiously",
        "firmly",
        "tenaciously",
        "lightly",
        "carelessly",
        "heedlessly",
        "steadily",
        "resolutely",
        "wildly",
        "raffishly",
        "carelessly",
        "heedlessly",
        "thoughtlessly",
        "soberly",
        "firmly",
        "solidly",
        "steadfastly",
        "easily",
        "effortlessly",
        "freely",
        "lightly",
        "readily",
        "efficiently",
        "smoothly",
        "competently",
        "handily",
        "awkwardly",
        "wearily",
        "clumsily",
        "ineptly",
        "stiffly",
        "arduously",
        "laboriously"
    });
    
    return adverb[random(sizeof(adverb)+1)];
}