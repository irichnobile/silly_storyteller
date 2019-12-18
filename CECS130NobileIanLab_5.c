//******************************************************************************
//  CECS130NobileIanLab_5.c     Author: Ian Nobile
//  
//  Program_description: this program generates interactive stories. It begins by
//  asking the user a number of personal questions. After obtaining a sufficient 
//  amount of information, this program outputs a short story of at least one 
//  paragraph that incorporates the user’s personal information obtained via the 
//  initial questioning. The generated story is different every time the program 
//  is run (randomly generating alternative endings, randomly selecting different 
//  descriptions of objects (blue car, green car, red car), etc. This program 
//  makes use of pointers and arrays to deal with strings.
//  
//  Lab section: 01
//  Due Date: 28 September 2018
//******************************************************************************

#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>


//------------------------------------------------------------------------------
//  Main Function
//------------------------------------------------------------------------------
main() {

    //seeds the random number generator with the current time:
    srand(time(NULL));

    char* aCityName[] = { "Bird-in-Hand", "Hackensack", "Magicians' Heights",
        "Tenderloin", "Shoofly" };

    char* aLandName[] = { "East Tickle", "The Monkey's Eyebrow", "Tubbercurry",
        "Wagga Wagga", "Tamale" };

    char* aAdjective[] = { "pedestrian", "bearded", "unholy", "user input",
        "user input" };

    char* aVerbs[] = { "stands", "points", "flexes", "poses", "yawns" };

    char* aVerb[] = { "debug", "boogie about", "slobber", "cajole", "impinge" };

    char* aObject[] = { "factory reset button", "washing machine",
        "friendly neighborhood koala", "user input", "user input" };

    char* sSillyPlace[] = {
        "the local art museum",
        "a temple deep in the jungle",
        "a luxury casino on the nice side of town",
        "a fort deep in a northern forest",
        "the auditorium where CECS 130 is currently in session" };

    char* sSillyAction[] = {
        "book a flight there using Kayak",
        "finish their grocery shopping",
        "buy flowers for their SO",
        "finish their CECS lab assignment",
        "finish solving that crossword puzzle from two Sundays ago" };

    char* aNumber[] = { "seven", "like, a million",
        "three and a half gallons o'", "fourteen", "a house of" };

    char* aColour[] = { "aquamarine", "fuchsia", "silver", "hot pink",
        "ultra indigo" };

    char* aOpening[] = { "doors", "gates", "keyholes", "portals",
        "warp gates" };

    char* aAnimal[] = { "beach chickens", "velocirabbits", "dragon shrimps",
        "trash pandas", "user input" };

    char* aRoom[] = { "warshroom", "trophy closet", "wine cellar",
        "basement garage", "ballroom" };

    char* aBodyP[] = { "a single eyelash", "their ear lobe", "their big toe",
        "the very tip of their tongue", "user input" };

    char* sSillyGoal[] = {
        "reach deep into the gaping maw of a chimera and withdraw nine teeth!",

        "scribble a long, detailed beard on the last portrait of former mayor "
        "of Riga!",
        
        "examine the bottom of a Ming dynasty vase for the final answer to an "
        "ancient crossword puzzle!",
        
        "pretend to conduct an orchestra while holding their nose,\nall the "
        "while jumping in smaller and smaller circles.",
        
        "proceed to suck all of the air out of the room." };

    char* sSillyConclusion[] = {
        "retire, absorbing into the comfortable leather of a favourite "
        "armchair\nnext to the fireplace in their study back at home.",
        
        "spend the good part of a fortnight perendinating studying for\nthe "
        "first CECS exam.",
        
        "get around to calling Mother, who's been pestering them the good part "
        "of\na fortnight now for some much needed reconnection.",
        
        "crawl back into bed and get caught up on all this sleep debt\nthey've "
        "accumulated going on silly adventures.",
        
        "stop by that Latvian place (the one with those amazing piragi?) on "
        "the way back to\nthe apartment where they shall binge the last "
        "episodes of that Netflix show they've totally become addicted to." };

    char* sSillyHint[] = {
        "The answers you give me can be real or made up!",
        
        "Give me answers that are close to your heart to give a personal touch "
        "to your story.",
        
        "It's okay to be a little silly with your answers. That makes the "
        "story more fun!",
        
        "If you keep running this program, the stories will be slightly "
        "different every time!",
        
        "If you weren't such a big fan of my story, that's just life. I'm a "
        "program with a limited set of parameters!"};
    /*Variable initialisations end.*/


    /*Now comes the intro and the requests for user information:*/
    printf("Hi, there. I'm a storytelling program and I tell silly stories.\n");
    Sleep(2 * 1000);
    printf("I'm going to ask you a few questions, and you're going to provide "
        "me with the answers!\n");
    Sleep(2 * 1000);
    printf("Then I'm going to tell you a story. About you!\n\n");
    Sleep(2 * 1000);
    printf("All right, first question. What's your name? ");
    char sUserName[255] = { '\0' };
    scanf("%s", sUserName);

    printf("Hi, %s. Would you please give me the names of two of your "
        "favourite objects separated by a space?: ", sUserName);
    char sObject1[255] = { '\0' };
    char sObject2[255] = { '\0' };
    scanf("%s %s", sObject1, sObject2);
    aObject[3] = sObject1;
    aObject[4] = sObject2;

    printf("All right. Now I need some adjectives. Two separated by a space "
        "should do it: ", sUserName);
    char sAdjective1[255] = { '\0' };
    char sAdjective2[255] = { '\0' };
    scanf("%s %s", sAdjective1, sAdjective2);
    aAdjective[3] = sAdjective1;
    aAdjective[4] = sAdjective2;

    printf("Got it. How about the name of your favorite animal? ");
    char sAnimal[255] = { '\0' };
    scanf("%s", sAnimal);
    aAnimal[4] = sAnimal;

    printf("Thanks, just one more. The name of a part of the body: ");
    char sBodyP[255] = { '\0' };
    scanf("%s", sBodyP);
    aBodyP[4] = sBodyP;
    system("cls");

    /*Here is where the actual story is told:*/
    
    printf("All right. Here we go!\n\n");
    printf("*Ahem* In the city of %s in the land of %s, the %s hero named %s %s."
        "\n", aCityName[(rand() % 5)], aLandName[(rand() % 5)], 
        aAdjective[(rand() % 5)], sUserName, aVerbs[(rand() % 5)]);
        //(rand() % 5) sets a random number between 0 and 4
    printf("Their quest? To %s the %s %s from %s!", aVerb[(rand() % 5)], 
        aAdjective[(rand() % 5)], aObject[(rand() % 5)], 
        sSillyPlace[(rand() % 5)]);
    printf("\nBefore they can do that, %s must %s quick, fast and in a "
        "hurry.\n", sUserName, sSillyAction[(rand() % 5)]);
    printf("With that out of the way, their real work can begin!\n");
    Sleep(5 * 1000);
    printf("\nHaving slipped past %s guards in shimmery %s ", 
        aNumber[(rand() % 5)], aColour[(rand() % 5)], aColour[(rand() % 5)]);
    printf("and white uniforms who patrol the\nexterior boundary, the ");
    printf("locks of %s %s %s have to be picked in order to\ngain access. ", 
        aNumber[(rand() % 5)], aColour[(rand() % 5)], aOpening[(rand() % 5)]);
    printf("Once inside, %s must sneakily %s the passageways, all the while"
        " avoiding the many, many\n%s %s lurking throughout. ", 
        sUserName, aVerb[(rand() % 5)], aAdjective[(rand() % 5)], 
        aAnimal[(rand() % 5)]);
    printf("Finally, once they have made their way to the %s,\n%s, using only "
        "their %s, must %s\n", aRoom[(rand() % 5)], sUserName, 
        aBodyP[(rand() % 5)], sSillyGoal[(rand() % 5)]);
    Sleep(5 * 1000);
    printf("\nOnce complete, %s can then finally %s\n\n", sUserName, 
        sSillyConclusion[(rand() % 5)]);
    Sleep(5 * 1000);

    printf("\nWhat did you think of my story? I certainly hope you enjoyed it. "
        "Please, enter your comments below:\n");
    char sResponse[25] = { '\0' };
    //This doesn't go anywhere (yet!), but makes the user feel heard:
    scanf("%s", &sResponse);
    printf("\nThanks for the feedback! Now here's a secret that will make my "
        "stories more interesting:\n%s\nNot everybody knows that!\n\n", 
        sSillyHint[(rand() % 5)]);
    system("pause");
    system("cls");
    printf("Thanks for listening!\n");

}

