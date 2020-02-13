/*
 * main.c
 *
 *  Created on: Nov 6, 2011
 *      Author: student
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "resource_detector.h"
#include "stegano.h"
#include "bmp.h"

#define    MAX_STRLEN    80

static bool WithMenu = true;

static int
GetInt (const char* Message)
{
    char Line[MAX_STRLEN];
    char* Result = NULL;
    int  Value = -1;

    if (WithMenu)
    {
        printf ("%s", Message);
    }
    Result = fgets (Line, sizeof(Line), stdin);
    if (Result != NULL)
    {
        sscanf (Result, "%d", &Value);
    }

    return Value;
}

static void
GetStr (const char* Message, char* Str)
{
    char Line[MAX_STRLEN];
    char* Result = NULL;

    if (WithMenu)
    {
        printf ("%s", Message);
    }
    Result = fgets (Line, sizeof(Line), stdin);
    if (Result != NULL)
    {
        sscanf (Result, "%s", Str);
    }
}


extern int
main (int argc, char * argv[])
{
    char File0 [MAX_STRLEN];
    char File1 [MAX_STRLEN];
    char File2 [MAX_STRLEN];
    int  Choice;
    bool Quit = false;

    printf ("PRC assignment 'SteganoC' (version 2)\n"
            "-------------------------------------\n");

    if (argc != 1)
    {
        fprintf (stderr, "%s: argc=%d\n", argv[0], argc);
    }

    while (!Quit)
    {
        if (WithMenu)
        {
            printf ("\n\nMENU\n"
                "===================\n"
                "[1] multiplex\n"
                "[2] multiplex text\n"
                "[3] demultiplex\n"
                "[4] demultiplex text\n"
                "[8] show/hide menu\n"
                "[9] Quit\n");
        }
        Choice = GetInt ("Choice: ");

        switch (Choice)
        {
            case 1:
                GetStr ("enter input file (visible): ", File0);
                GetStr ("enter input file (hidden): ", File1);
                SteganoMultiplex (File0, File1);
                break;
            case 2:
                GetStr ("enter input file (visible): ", File0);
                GetStr ("enter input file (text): ", File1);
                SteganoMultiplexText (File0, File1);
                break;
            case 3:
                GetStr ("enter input file: ", File0);
                GetStr ("enter output file (visible): ", File1);
                GetStr ("enter output file (hidden): ", File2);
                SteganoDemultiplex (File0, File1, File2);
                break;
            case 4:
                GetStr ("enter input file: ", File0);
                GetStr ("enter output file (visible): ", File1);
                GetStr ("enter output file (text): ", File2);
                SteganoDemultiplexText (File0, File1, File2);
                break;
            case 8:
                if (WithMenu)
                {
                    printf ("printing of MENU is disabled\n");
                }
                WithMenu = !WithMenu;
                break;
            case 9:
                Quit = true;
                break;
            default:
                printf ("ERROR: invalid Choice: %d\n", Choice);
                break;
        }
    }
    return (0);
}

