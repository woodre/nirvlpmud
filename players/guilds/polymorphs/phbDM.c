/*
 * ADAPTED FROM:
 *
 * Flounder's Mission Statement Generator
 * Written 4/26/2000
 * by Scott Fitzenrider
 * flounder@giantflounderpenisDONTSPAM.com
 *
 * resume =>  http://www.giantflounderpenis.com/myresume.html
 *
 */

id(str) { return str == "generator"; }
short() { return "The Corporate Bullshit Generator [1.0]"; }

string ms_openers;
string ms_adverbs;
string ms_verbs;
string ms_adjectives;
string ms_nouns;
string ms_conjunctions;
string ms_closers;

string bs_verbs;
string bs_adjectives;
string bs_nouns;


reset()
{
   load_text();
   move_object(this_object(), "/players/mizan/core/02h/room04.c");
}

init()
{
  add_action("get_bs","get_bs");
}

get_bs()
{
   string result;
   string result02;

   result = get_mission_statement();
   result02 = get_bullshit();
   
   write("You push a button on the machine.\n");
   write("The Bullshit Generator says: MISSION STATEMENT: " + result + ".\n");
   write("The Bullshit Generator says: BULLSHIT: " + result02 + ".\n");
   say(this_player()->query_name() + " pushes a button the Corporate Bullshit Generator.\n");
   say("The Bullshit Generator says: MISSION STATEMENT: " + result + ".\n");
   say("The Bullshit Generator says: BULLSHIT: " + result02 + ".\n");
   return 1;
   
}

get_bullshit()
{
    string result;

    result = bs_verbs[random(sizeof(bs_verbs))] + " ";
    result += bs_adjectives[random(sizeof(bs_adjectives))] + " ";
    result += bs_nouns[random(sizeof(bs_nouns))];

    return result;
}

get_mission_statement()
{
    string result;

    result = ms_openers[random(sizeof(ms_openers))] + " ";
    result += ms_adverbs[random(sizeof(ms_adverbs))] + " ";
    result += ms_verbs[random(sizeof(ms_verbs))] + " ";
    result += ms_adjectives[random(sizeof(ms_adjectives))] + " ";
    result += ms_nouns[random(sizeof(ms_nouns))] + " ";
    result += ms_conjunctions[random(sizeof(ms_conjunctions))] + " ";
    result += ms_closers[random(sizeof(ms_closers))];

    /* don't forget the period. */
    result = result + ".";

    return result;
}


load_text()
{
   ms_openers = ({
    "It is our business to",
    "It is our job to",
    "It is our mission to",
    "It's our responsibility to",
    "Our challenge is to",
    "Our first priority is to",
    "Our goal is to",
    "Our mission is to",
    "Our mission is to continue to",
    "The customer can count on us to",
    "We",
    "We build trust and teamwork to",
    "We envision to",
    "We exist to",
    "We have committed to",
    "We strive to",
    "We will",
   });

   ms_adverbs = ({
    "appropriately",
    "assertively",
    "authoritatively",
    "collaboratively",
    "competently",
    "completely",
    "continually",
    "conveniently",
    "credibly",
    "distinctively",
    "dramatically",
    "dynamically",
    "efficiently",
    "enthusiastically",
    "globally",
    "holisticly",
    "interactively",
    "intrinsicly",
    "objectively",
    "proactively",
    "professionally",
    "progressively",
    "quickly",
    "seamlessly",
    "synergistically",
   });

   ms_verbs = ({
    "actualize",
    "administrate",
    "build",
    "communicate",
    "conceptualize",
    "coordinate",
    "create",
    "customize",
    "develop",
    "disseminate",
    "empower",
    "engineer",
    "enhance",
    "facilitate",
    "fashion",
    "foster",
    "impact",
    "initiate",
    "integrate",
    "leverage existing",
    "leverage other's",
    "maintain",
    "negotiate",
    "network",
    "parallel task",
    "promote",
    "provide access to",
    "pursue",
    "re-engineer",
    "re-invent",
    "restore",
    "revolutionize",
    "simplify",
    "streamline",
    "supply",
    "utilize"
   });
   
   ms_adjectives = ({
    "accurate",
    "adaptive",
    "alternative",
    "an expanded array of",
    "backward-compatible",
    "best of breed",
    "business",
    "client-based",
    "client-centered",
    "client-centric",
    "client-focused",
    "collaborative",
    "competitive",
    "cooperative",
    "corporate",
    "cost effective",
    "cross functional",
    "cross-unit",
    "customer directed",
    "cutting edge",
    "distinctive",
    "diverse",
    "economically sound",
    "effective",
    "emerging",
    "empowered",
    "enabled",
    "enterprise-wide",
    "equity invested",
    "error-free",
    "ethical",
    "excellent",
    "exceptional",
    "flexible",
    "fully researched",
    "fully tested",
    "functional",
    "functionalized",
    "future-proof",
    "global",
    "go forward",
    "goal-oriented",
    "high standards in",
    "high-payoff",
    "high-quality",
    "highly efficient",
    "inexpensive",
    "innovative",
    "installed base",
    "integrated",
    "interactive",
    "interdependent",
    "interoperable",
    "just in time",
    "leading-edge",
    "leveraged",
    "long-term high-impact",
    "low-risk high-yield",
    "maintainable",
    "market positioning",
    "market-driven",
    "mission-critical",
    "multidisciplinary",
    "multifunctional",
    "multimedia based",
    "optimal",
    "orthogonal",
    "parallel",
    "performance based",
    "premier",
    "premium",
    "principle-centered",
    "proactive",
    "process-centric",
    "professional",
    "progressive",
    "prospective",
    "quality",
    "reliable",
    "resource maximizing",
    "resource-leveling",
    "scalable",
    "stand-alone",
    "standards compliant",
    "state of the art",
    "strategic",
    "superior",
    "sustainable",
    "tactical",
    "team building",
    "team driven",
    "technically sound",
    "timely",
    "top-line",
    "turn-key",
    "unique",
    "user friendly",
    "value-added",
    "virtual",
    "world-class",
    "worldwide"
   });

   ms_nouns = ({
    "outside the box thinking",
    "action items",
    "alignments",
    "benefits",
    "best practices",
    "catalysts for change",
    "collaboration and idea-sharing",
    "content",
    "core competencies",
    "customer service",
    "data",
    "deliverables",
    "e-business",
    "expertise",
    "growth strategies",
    "human capital",
    "ideas",
    "imperatives",
    "information",
    "infrastructures",
    "initiatives",
    "innovation",
    "intellectual capital",
    "internal or 'organic' sources",
    "leadership",
    "leadership skills",
    "manufactured products",
    "materials",
    "meta-services",
    "methods of empowerment",
    "metrics",
    "niche markets",
    "opportunities",
    "paradigms",
    "potentialities",
    "process improvements",
    "processes",
    "products",
    "quality vectors",
    "resources",
    "results",
    "scenarios",
    "services",
    "solutions",
    "sources",
    "strategic theme areas",
    "supply chains",
    "synergy",
    "technology",
    "testing procedures",
    "total linkage",
    "value",
   });
   
   ms_conjunctions = ({
    "and",
    "and also",
    "and continue to",
    "as well as to",
    "in order that we may",
    "in order to",
    "so that we may",
    "so that we may endeavor to",
    "such that we may continue to",
    "to allow us to",
    "while continuing to",
   });
   
   ms_closers = ({
    "and approach our jobs with passion an commitment",
    "because that is what the customer expects",
    "for 100% customer satisfaction",
    "in order to solve business problems",
    "so that we can deliver the kind of results on the bottom line that our investors expect and deserve",
    "through continuous improvement",
    "to be the best in the world",
    "to delight the customer",
    "to exceed customer expectations",
    "to meet our customer's needs",
    "to satisfy our internal and external customers",
    "to set us apart from the competition",
    "to stay competitive in tomorrow's world",
    "while maintaining the highest standards",
    "while promoting personal employee growth",
    "while striving for technical leadership",
    "with 100% on-time delivery",
    "with zero defects"
   });

   bs_verbs = ({
    "aggregate",
    "architect",
    "benchmark",
    "brand",
    "cultivate",
    "deliver",
    "deploy",
    "disintermediate",
    "drive",
    "e-enable",
    "embrace",
    "empower",
    "enable",
    "engage",
    "engineer",
    "enhance",
    "envisioneer",
    "evolve",
    "expedite",
    "exploit",
    "extend",
    "facilitate",
    "generate",
    "grow",
    "harness",
    "implement",
    "incentivize",
    "incubate",
    "innovate",
    "integrate",
    "iterate",
    "leverage",
    "matrix",
    "maximize",
    "mesh",
    "monetize",
    "morph",
    "optimize",
    "orchestrate",
    "productize",
    "recontextualize",
    "redefine",
    "reintermediate",
    "reinvent",
    "repurpose",
    "revolutionize",
    "scale",
    "seize",
    "strategize",
    "streamline",
    "syndicate",
    "synergize",
    "synthesize",
    "target",
    "transform",
    "transition",
    "unleash",
    "utilize",
    "visualize",
    "whiteboard",
   });


   bs_adjectives = ({
    "24/365",
    "24/7",
    "B2B",
    "B2C",
    "back-end",
    "best-of-breed",
    "bleeding-edge",
    "bricks-and-clicks",
    "clicks-and-mortar",
    "collaborative",
    "compelling",
    "cross-platform",
    "cross-media",
    "customized",
    "cutting-edge",
    "distributed",
    "dot-com",
    "dynamic",
    "e-business",
    "efficient",
    "end-to-end",
    "enterprise",
    "extensible",
    "frictionless",
    "front-end",
    "global",
    "granular",
    "holistic",
    "impactful",
    "innovative",
    "integrated",
    "interactive",
    "intuitive",
    "killer",
    "leading-edge",
    "magnetic",
    "mission-critical",
    "next-generation",
    "one-to-one",
    "open-source",
    "out-of-the-box",
    "plug-and-play",
    "proactive",
    "real-time",
    "revolutionary",
    "robust",
    "scalable",
    "seamless",
    "sexy",
    "sticky",
    "strategic",
    "synergistic",
    "transparent",
    "turn-key",
    "ubiquitous",
    "user-centric",
    "value-added",
    "vertical",
    "viral",
    "virtual",
    "visionary",
    "web-enabled",
    "wireless",
    "world-class",
   });

   bs_nouns = ({
    "action-items",
    "applications",
    "architectures",
    "bandwidth",
    "channels",
    "communities",
    "content",
    "convergence",
    "deliverables",
    "e-business",
    "e-commerce",
    "e-markets",
    "e-services",
    "e-tailers",
    "experiences",
    "eyeballs",
    "functionalities",
    "infomediaries",
    "infrastructures",
    "initiatives",
    "interfaces",
    "markets",
    "methodologies",
    "metrics",
    "mindshare",
    "models",
    "networks",
    "niches",
    "paradigms",
    "partnerships",
    "platforms",
    "portals",
    "relationships",
    "ROI",
    "synergies",
    "web-readiness",
    "schemas",
    "solutions",
    "supply-chains",
    "systems",
    "technologies",
    "users",
    "vortals",
    "web services",
   });

}

