#include "../definitions.h"
string *my_narci_first_names;
string *my_narci_last_names;
string *my_narci_facts;
string *my_narci_insults;
string *my_otakuese_prefixes;
string *my_otakuese_suffixes;
string *my_otakuese_origins;
string *my_temper;

get() {
    return 0;
}
short() {
    return "A server named (narcissist)";
}
id(str) {
    return str == "narcissist" || str == "server";
}


string get_first_name() {
    return my_narci_first_names[random(sizeof(my_narci_first_names))];
}

string get_last_name() {
    return my_narci_last_names[random(sizeof(my_narci_last_names))];
}

string get_fact() {
    return my_narci_facts[random(sizeof(my_narci_facts))];
}

string get_insult() {
    return my_narci_insults[random(sizeof(my_narci_insults))];
}

string get_temper() {
    return my_temper[random(sizeof(my_temper))];
}
string get_otakuese_prefix() {
    return my_otakuese_prefixes[random(sizeof(my_otakuese_prefixes))];
}

string get_otakuese_suffix() {
    return my_otakuese_suffixes[random(sizeof(my_otakuese_suffixes))];
}

string get_otakuese_origin() {
    return my_otakuese_origins[random(sizeof(my_otakuese_origins))];
}


void reset(int arg)
{
    /* move ourselves home. */
    move_object(this_object(), DAEMON_HOME);

    if (!arg)
    {
        my_narci_first_names = ( {
            "Auguste",
            "Monsieur",
            "Henri",
            "Rivale",
            "Jean Claude",
	    "Emile",
	    "Jean",
	    "Marcel",
	    "Guy",
	    "Bouchard",
            "Jacques",
	    "Fenix",
	    "Victor",
	    "Marcel",
	    "Thierry",
        });

	my_narci_last_names = ({
	    "Le Tueur",
	    "Dupont",
	    "Verdoux",
	    "Landru",
	    "L'ogre",
	    "Fourniret",
	    "Diable",
	    "Cousteau",
	    "Louis",
	    "La Pierre",
	    "Marteau",
	    "Le Violeur",
	    "L'ane",
	    "Poisson",
	    "La Souris",
	    "Cheval",
	    "Vacher",
	    "L'eventreur du Lyon",
	    "Paulin",
	});

        my_narci_insults = ( {
            "You look like you need to hit the gym more. A LOT MORE!",
            "If it jiggles, it's fat... and it looks like all of you is jiggling!",
            "Prada... Louis Vuitton... Gucci... I love them all!",
            "My... you look terrible. So out of shape, and so out of style!",
            "Aww, don't cry, you look fat when you cry.",
        });

        /* CREDITS: a bunch of these come from the following sources:
         * http://facts.randomhistory.com/2009/06/27_fast-food.html
         */
        my_narci_facts = ( {
            "Americans spend $33 billion per year to lose weight. It's obviously not doing ANYTHING.",
            "Every month, approximately nine out of ten American children visit a McDonald's 'restaurant'.",
            "In 1970, Americans spent about $6 billion on fast food. In 2006, the spending rose to nearly $142 billion.",
            "During the early 1900s, the hamburger was thought to be polluted, unsafe to eat, and food for the poor. Street carts, not restaurants, typically served them. How quaint.",
            "Proportionally, hash browns have more fat and calories than a cheeseburger or Big Mac.",
            "At some fast food chains, both in U.S. and in other countries, managers are rewarded bonuses when they reduce employee wages to save money.",
            "To keep salaries low, McDonald's and other fast food chains have intentionally engaged in anti-union activities.",
            "Today, Coca-Cola and PepsiCo products are sold in every country in the world, except North Korea.",
            "Late comedian and talk-show host Johnny Carson labeled the hamburger the 'McClog the Artery'.",
            "There are more than 300,000 fast food restaurants in the U.S. alone. That translates into 300,000 opportunities to get fat and lazy!",
            "McDonald's is Brazil's largest employer. HA HA HA HA!",
            "When McDonald's opened an outlet in Kuwait shortly after the end of the Gulf War, the line of cars waiting to eat there was seven miles long. SEVEN MILES OF STUPIDITY!",
            "Children and teenagers consume more than 64 gallons of soft drinks per year.",
            "Caffeine is the most commonly used drug in the world, and high doses can have serious health effects, including muscle weakness, heart irregularities, and infertility.",
            "High-fructose corn syrup (which tricks your body into wanting to eat more and to store more fat) first appeared in 1967, and the average American now consumes 63 pounds of it a year.",
            "McDonald's is the largest purchaser of beef, pork, and potatoes and the second largest purchaser of chicken in the world.",
            "Mcdonald's annual orders for french fries constitute 7.5% of America's entire potato crop.",
            "By the end of the twentieth century, one out of eight American workers had at some time been employed by McDonald's and 96% of Americans had visited McDonald's at least once.",
            "In-N-Out Burger is one of the few fast food restaurants that actually slice each potato by hand shortly before it is placed in the deep fryer.",
            "A McDonald's. corn muffin has more calories than a glazed donut. A small packet of Wendy.s honey mustard dressing has 280 calories.",
            "Americans consume approximately 70 million tater tots a year. They were created to utilize potato shreds left over from french fry production.",


        });


        my_otakuese_prefixes = ( {
            "ichi",
            "ni",
            "san",
            "shi",
            "jun",
            "go",
            "roku",
            "shichi",
            "hachi",
            "kyu",
            "juu",
            "nana-ju",
            "hyaku",
            "hidari",
            "migi",
            "mae",
            "ushiro",
            "ato",
            "jun",
            "gyaku",

        });

        my_otakuese_suffixes = ( {
            "hiraki-gamae",
            "tai-gamae",
            "tan-en",
            "so-tai",
            "uwa",
            "juji",
            "jo-dan",
            "chu-dan",
            "ge-dan",
            "uchi",
            "soto",
            "yoko",
            "sokuto",
            "gassho",
            "gamae",
            "goho",
            "juho",
            "umpoho",
            "ukemi",
            "tai sabake",
            "kata",
            "gakka",
            "hokei",
            "kihon",
            "atemi",
            "zuki",
            "geri",
            "kiri",
            "uke",
            "kagite",
            "nuki",
            "gote",
            "maki",
            "nage",
            "omote",
            "embu",
            "randori",
            "gaeshi",
            "chinkon",
            "kenshi",
            "sensei",
            "kaiso",
            "kancho",
            "dojo",
            "hombu",
            "te",
            "ashi",
            "ken",
            "kote",
            "jo-haku",
            "hiji",
            "hiza",
            "kinteki",
            "yubi",
            "kubi",
            "gi",
            "sode",
            "obi",
            "onegai-shimasu",
            "arigato-gozaimasu",
            "kudesai",
            "gomen nasai",
            "Yoi",
            "hajime",
            "seiza",
            "chakuza",
            "kiai",
            "itai",
            "samu",
            "mizu",
            "keimyaku",
            "owarimasu",

        });

        my_otakuese_origins = ( {
            "Iga",
            "Ise",
            "Shima",
            "Owari",
            "Mikawa",
            "Totomi",
            "Suruga",
            "Izu",
            "Kai",
            "Sagami",
            "Musashi",
            "Awa",
            "Kazusa",
            "Shimousa",
            "Hitachi",
            "Omi",
            "Mino",
            "Hida",
            "Shinano",
            "Suwa",
            "Kozuke",
            "Shimotsuke",
            "Dewa",
            "Uzen",
            "Ugo",
            "Mutsu",
            "Iwaki",
            "Iwase",
            "Iwashiro",
            "Iwaki",
            "Rikuchu",
            "Rikuzen",
            "Mutsu",
            "Wakasa",
            "Echizen",
            "Kaga",
            "Noto",
            "Etchu",
            "Echigo",
            "Sado",
            "Tamba",
            "Tango",
            "Tajima",
            "Inaba",
            "Hoki",
            "Izumo",
            "Iwami",
            "Oki",
            "Harima",
            "Mimasaka",
            "Bizen",
            "Aki",
            "Suo",
            "Nagato",
            "Nankaido",
            "Kii",
            "Awaji",
            "Awa",
            "Sanuki",
            "Iyo",
            "Tosa",
            "Saikaido",
            "Buzen",
            "Bungo",
            "Chikuzen",
            "Chikugo",
            "Hizen",
            "Higo",
            "Hyuga",
            "Osumi",
            "Satsuma",
            "Iki",
            "Tsushima",
            "Oshima",
            "Shiribeshi",
            "Iburi",
            "Ishikari",
            "Teshio",
            "Kitami",
            "Hidaki",
            "Tokachi",
            "Kushiro",
            "Nemuro",
            "Chishima",
        });

	my_temper = ({
	"the souls of the damned",
	"the Sony Corporation execs",
	"suicidal Toshiba employees",
	"a Canon 1Ds Mk. III DSLR camera",
	"hundreds of aborted fetuses",
	"legions of dead puppy dogs",
	"corpses of many bunny rabbits",
	"the honor of 72 dead virgins",
	"very small rocks of Onigiri-ito",
	"collarbones of schoolgirls",
	"used socks of schoolgirls",
	"blood of pancake-wearing rabbits",
	"zombie Super Mario spinoffs",
	"the bile of tentacle rapists",
	"the remnants of Neo Geo",
	"Sensei Fujitsu Enix himself",
	"the Toyota Corporation",
	"a Honda Type-R Civic",
	"a fistful of Mabuchi motors",
	});

    }
}

